"""
Task Manager Application
Python implementation with SQLite, JSON, and dataclasses
"""

import sqlite3
import json
from dataclasses import dataclass, asdict, field
from datetime import datetime
from typing import List, Optional
from enum import Enum


# DTO (Data Transfer Object) using dataclass
@dataclass
class TaskDTO:
    """Task Data Transfer Object"""
    id: Optional[int] = None
    title: str = ""
    description: str = ""
    completed: bool = False
    created_at: datetime = field(default_factory=datetime.now)
    completed_at: Optional[datetime] = None
    
    def to_dict(self) -> dict:
        """Convert to dictionary with ISO format dates"""
        data = asdict(self)
        data['created_at'] = self.created_at.isoformat()
        data['completed_at'] = self.completed_at.isoformat() if self.completed_at else None
        return data
    
    @classmethod
    def from_dict(cls, data: dict) -> 'TaskDTO':
        """Create TaskDTO from dictionary"""
        if isinstance(data['created_at'], str):
            data['created_at'] = datetime.fromisoformat(data['created_at'])
        if data.get('completed_at'):
            data['completed_at'] = datetime.fromisoformat(data['completed_at'])
        return cls(**data)
    
    def __str__(self) -> str:
        status = "✓" if self.completed else "○"
        return f"{status} [{self.id}] {self.title}"


# Repository Layer (Database Operations)
class TaskRepository:
    """Handles database operations for tasks"""
    
    def __init__(self, db_name: str = ":memory:"):
        """Initialize repository with SQLite database"""
        self.db_name = db_name
        self.conn = sqlite3.connect(db_name)
        self.conn.row_factory = sqlite3.Row
        self._create_table()
    
    def _create_table(self):
        """Create tasks table if it doesn't exist"""
        cursor = self.conn.cursor()
        cursor.execute("""
            CREATE TABLE IF NOT EXISTS tasks (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                title TEXT NOT NULL,
                description TEXT,
                completed BOOLEAN DEFAULT 0,
                created_at TEXT NOT NULL,
                completed_at TEXT
            )
        """)
        self.conn.commit()
    
    def save(self, task: TaskDTO) -> TaskDTO:
        """Save or update a task"""
        if task.id is None:
            return self._insert(task)
        else:
            return self._update(task)
    
    def _insert(self, task: TaskDTO) -> TaskDTO:
        """Insert a new task"""
        cursor = self.conn.cursor()
        cursor.execute("""
            INSERT INTO tasks (title, description, completed, created_at, completed_at)
            VALUES (?, ?, ?, ?, ?)
        """, (
            task.title,
            task.description,
            task.completed,
            task.created_at.isoformat(),
            task.completed_at.isoformat() if task.completed_at else None
        ))
        self.conn.commit()
        task.id = cursor.lastrowid
        return task
    
    def _update(self, task: TaskDTO) -> TaskDTO:
        """Update an existing task"""
        cursor = self.conn.cursor()
        cursor.execute("""
            UPDATE tasks
            SET title = ?, description = ?, completed = ?, completed_at = ?
            WHERE id = ?
        """, (
            task.title,
            task.description,
            task.completed,
            task.completed_at.isoformat() if task.completed_at else None,
            task.id
        ))
        self.conn.commit()
        return task
    
    def find_by_id(self, task_id: int) -> Optional[TaskDTO]:
        """Find a task by ID"""
        cursor = self.conn.cursor()
        cursor.execute("SELECT * FROM tasks WHERE id = ?", (task_id,))
        row = cursor.fetchone()
        return self._row_to_task(row) if row else None
    
    def find_all(self) -> List[TaskDTO]:
        """Get all tasks"""
        cursor = self.conn.cursor()
        cursor.execute("SELECT * FROM tasks ORDER BY created_at DESC")
        return [self._row_to_task(row) for row in cursor.fetchall()]
    
    def delete_by_id(self, task_id: int) -> bool:
        """Delete a task by ID"""
        cursor = self.conn.cursor()
        cursor.execute("DELETE FROM tasks WHERE id = ?", (task_id,))
        self.conn.commit()
        return cursor.rowcount > 0
    
    def _row_to_task(self, row) -> TaskDTO:
        """Convert database row to TaskDTO"""
        return TaskDTO(
            id=row['id'],
            title=row['title'],
            description=row['description'],
            completed=bool(row['completed']),
            created_at=datetime.fromisoformat(row['created_at']),
            completed_at=datetime.fromisoformat(row['completed_at']) if row['completed_at'] else None
        )
    
    def close(self):
        """Close database connection"""
        self.conn.close()


# Service Layer (Business Logic)
class TaskService:
    """Business logic for task management"""
    
    def __init__(self, db_name: str = ":memory:"):
        """Initialize service with repository"""
        self.repository = TaskRepository(db_name)
    
    def create_task(self, title: str, description: str = "") -> TaskDTO:
        """Create a new task"""
        task = TaskDTO(title=title, description=description)
        return self.repository.save(task)
    
    def get_task_by_id(self, task_id: int) -> Optional[TaskDTO]:
        """Get a task by ID"""
        return self.repository.find_by_id(task_id)
    
    def get_all_tasks(self) -> List[TaskDTO]:
        """Get all tasks"""
        return self.repository.find_all()
    
    def get_completed_tasks(self) -> List[TaskDTO]:
        """Get only completed tasks using filter (similar to Java Streams)"""
        return list(filter(lambda task: task.completed, self.repository.find_all()))
    
    def get_pending_tasks(self) -> List[TaskDTO]:
        """Get only pending tasks"""
        return list(filter(lambda task: not task.completed, self.repository.find_all()))
    
    def get_tasks_sorted_by_title(self) -> List[TaskDTO]:
        """Get tasks sorted by title"""
        return sorted(self.repository.find_all(), key=lambda task: task.title.lower())
    
    def complete_task(self, task_id: int) -> TaskDTO:
        """Mark a task as completed"""
        task = self.repository.find_by_id(task_id)
        if not task:
            raise ValueError(f"Task not found with id: {task_id}")
        
        task.completed = True
        if not task.completed_at:
            task.completed_at = datetime.now()
        
        return self.repository.save(task)
    
    def update_task(self, task_id: int, title: str, description: str) -> TaskDTO:
        """Update a task's title and description"""
        task = self.repository.find_by_id(task_id)
        if not task:
            raise ValueError(f"Task not found with id: {task_id}")
        
        task.title = title
        task.description = description
        return self.repository.save(task)
    
    def delete_task(self, task_id: int) -> bool:
        """Delete a task"""
        return self.repository.delete_by_id(task_id)
    
    def count_tasks(self) -> int:
        """Count total tasks"""
        return len(self.repository.find_all())
    
    def count_completed_tasks(self) -> int:
        """Count completed tasks"""
        return len(self.get_completed_tasks())
    
    def export_to_json(self) -> str:
        """Export all tasks to JSON"""
        tasks = self.repository.find_all()
        tasks_dict = [task.to_dict() for task in tasks]
        return json.dumps(tasks_dict, indent=2)
    
    def import_from_json(self, json_str: str):
        """Import tasks from JSON"""
        tasks_data = json.loads(json_str)
        for task_data in tasks_data:
            task_data['id'] = None  # Reset ID for new inserts
            task = TaskDTO.from_dict(task_data)
            self.repository.save(task)
    
    def close(self):
        """Close service and repository"""
        self.repository.close()


# CLI Application
class TaskManagerApp:
    """Command-line interface for Task Manager"""
    
    def __init__(self):
        """Initialize the application"""
        # Use file-based database for persistence, or ":memory:" for in-memory
        self.service = TaskService("tasks.db")
    
    def run(self):
        """Run the application"""
        print("=== Task Manager Application ===\n")
        
        while True:
            self.print_menu()
            choice = self.get_input("Enter your choice: ")
            
            try:
                if choice == "1":
                    self.add_task()
                elif choice == "2":
                    self.view_all_tasks()
                elif choice == "3":
                    self.view_pending_tasks()
                elif choice == "4":
                    self.view_completed_tasks()
                elif choice == "5":
                    self.complete_task()
                elif choice == "6":
                    self.update_task()
                elif choice == "7":
                    self.delete_task()
                elif choice == "8":
                    self.show_statistics()
                elif choice == "9":
                    self.export_tasks()
                elif choice == "10":
                    self.import_tasks()
                elif choice == "0":
                    break
                else:
                    print("Invalid choice. Try again.")
            except ValueError as e:
                print(f"✗ Error: {e}")
            except Exception as e:
                print(f"✗ Unexpected error: {e}")
            
            print()
        
        self.service.close()
        print("Goodbye!")
    
    def print_menu(self):
        """Print the main menu"""
        print("1. Add Task")
        print("2. View All Tasks")
        print("3. View Pending Tasks")
        print("4. View Completed Tasks")
        print("5. Complete Task")
        print("6. Update Task")
        print("7. Delete Task")
        print("8. Show Statistics")
        print("9. Export to JSON")
        print("10. Import from JSON")
        print("0. Exit")
    
    def add_task(self):
        """Add a new task"""
        print("\n--- Add New Task ---")
        title = self.get_input("Enter task title: ")
        description = self.get_input("Enter task description: ")
        
        task = self.service.create_task(title, description)
        print(f"✓ Task created successfully! ID: {task.id}")
    
    def view_all_tasks(self):
        """View all tasks"""
        print("\n--- All Tasks ---")
        tasks = self.service.get_all_tasks()
        self.display_tasks(tasks)
    
    def view_pending_tasks(self):
        """View pending tasks"""
        print("\n--- Pending Tasks ---")
        tasks = self.service.get_pending_tasks()
        self.display_tasks(tasks)
    
    def view_completed_tasks(self):
        """View completed tasks"""
        print("\n--- Completed Tasks ---")
        tasks = self.service.get_completed_tasks()
        self.display_tasks(tasks)
    
    def complete_task(self):
        """Mark a task as completed"""
        task_id = int(self.get_input("Enter task ID to complete: "))
        task = self.service.complete_task(task_id)
        print(f"✓ Task completed: {task.title}")
    
    def update_task(self):
        """Update a task"""
        task_id = int(self.get_input("Enter task ID to update: "))
        title = self.get_input("Enter new title: ")
        description = self.get_input("Enter new description: ")
        
        task = self.service.update_task(task_id, title, description)
        print("✓ Task updated successfully!")
    
    def delete_task(self):
        """Delete a task"""
        task_id = int(self.get_input("Enter task ID to delete: "))
        deleted = self.service.delete_task(task_id)
        
        if deleted:
            print("✓ Task deleted successfully!")
        else:
            print(f"✗ Task not found with ID: {task_id}")
    
    def show_statistics(self):
        """Show task statistics"""
        print("\n--- Task Statistics ---")
        total = self.service.count_tasks()
        completed = self.service.count_completed_tasks()
        pending = total - completed
        
        print(f"Total Tasks: {total}")
        print(f"Completed: {completed}")
        print(f"Pending: {pending}")
        if total > 0:
            print(f"Completion Rate: {(completed * 100.0 / total):.1f}%")
    
    def export_tasks(self):
        """Export tasks to JSON"""
        json_data = self.service.export_to_json()
        print("\n--- Exported Tasks (JSON) ---")
        print(json_data)
        
        # Optionally save to file
        save = self.get_input("\nSave to file? (y/n): ").lower()
        if save == 'y':
            filename = self.get_input("Enter filename: ")
            with open(filename, 'w') as f:
                f.write(json_data)
            print(f"✓ Saved to {filename}")
    
    def import_tasks(self):
        """Import tasks from JSON"""
        filename = self.get_input("Enter filename to import: ")
        try:
            with open(filename, 'r') as f:
                json_data = f.read()
            self.service.import_from_json(json_data)
            print("✓ Tasks imported successfully!")
        except FileNotFoundError:
            print(f"✗ File not found: {filename}")
        except json.JSONDecodeError:
            print("✗ Invalid JSON format")
    
    def display_tasks(self, tasks: List[TaskDTO]):
        """Display a list of tasks"""
        if not tasks:
            print("No tasks found.")
            return
        
        for task in tasks:
            print(str(task))
            print(f"   {task.description}")
            print(f"   Created: {task.created_at.strftime('%Y-%m-%d %H:%M:%S')}")
            if task.completed:
                print(f"   Completed: {task.completed_at.strftime('%Y-%m-%d %H:%M:%S')}")
            print()
    
    def get_input(self, prompt: str) -> str:
        """Get user input"""
        return input(prompt).strip()


# Main entry point
if __name__ == "__main__":
    app = TaskManagerApp()
    app.run()