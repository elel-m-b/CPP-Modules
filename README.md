# ⚔️ 42 C++ Modules

<div align="center">

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)
![Status](https://img.shields.io/badge/Status-In%20Progress-yellow?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

*A comprehensive collection of exercises designed to master the fundamentals of **C++ programming***

[Getting Started](#-getting-started) •
[Modules](#-modules-overview) •
[Requirements](#-requirements) •
[Contributing](#-contributing)

</div>

---

## 📚 About

The **42 C++ Modules** represent a carefully curated learning path through the intricacies of C++ programming. Following the renowned **42 School curriculum**, this project takes you on a journey from basic syntax to advanced programming paradigms.

> 🎯 **Goal**: Not just to learn C++ syntax, but to truly understand the *why* and *how* behind Object-Oriented Programming, memory management, and modern C++ practices.

---

## 🗺️ Modules Overview

<table>
<tr>
<td width="50%">

### 🏗️ **Foundation Modules**
- **📦 Module 00** - *C++ Basics*
  - Namespaces & I/O streams
  - Classes & member functions
  - First steps into OOP

- **🧠 Module 01** - *Memory & References*
  - Dynamic memory allocation
  - Pointers vs references
  - Switch statements

- **⚡ Module 02** - *Polymorphism Intro*
  - Ad-hoc polymorphism
  - Operator overloading
  - Orthodox canonical classes

</td>
<td width="50%">

### 🚀 **Advanced Modules**
- **🔗 Module 03** - *Inheritance*
  - Class hierarchies
  - Protected members
  - Virtual functions

- **🎭 Module 04** - *Abstract Classes*
  - Subtype polymorphism
  - Pure virtual functions
  - Interface design

- **⚠️ Module 05** - *Exception Handling*
  - Try-catch blocks
  - Custom exceptions
  - RAII principles

</td>
</tr>
</table>

<table>
<tr>
<td width="33%">

### 🔧 **Module 06**
**C++ Casts**
- Static cast
- Dynamic cast
- Reinterpret cast
- Const cast

</td>
<td width="33%">

### 🧬 **Module 07**
**Templates**
- Function templates
- Class templates
- Template specialization
- Generic programming

</td>
<td width="33%">

### 📊 **Module 08**
**STL Foundations**
- Templated containers
- Iterators
- Algorithm basics
- Custom containers

</td>
</tr>
</table>

<div align="center">

### 🏆 **Module 09** - *STL Mastery*
**Standard Template Library deep dive**  
*Containers • Algorithms • Best Practices*

</div>

---

## 🛠 Requirements

<details>
<summary><b>📋 System Requirements</b></summary>

### Minimum Requirements
- **Compiler**: C++98 compatible compiler
  - `clang++` (recommended)
  - `g++` 
- **OS**: Linux, macOS, or Windows (with WSL)
- **Make**: GNU Make utility

### Recommended Setup
```bash
# Install on macOS
brew install llvm

# Install on Ubuntu/Debian
sudo apt-get update
sudo apt-get install clang++ make

# Verify installation
clang++ --version
```

</details>

<details>
<summary><b>📚 Prerequisites</b></summary>

- Solid understanding of **C programming**
- Familiarity with basic programming concepts:
  - Variables and data types
  - Control structures (loops, conditionals)
  - Functions and scope
- Knowledge of **42 Norm** coding standards
- Basic terminal/command line usage

</details>

---

## 🚀 Getting Started

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/yourusername/42-cpp-modules.git
cd 42-cpp-modules
```

### 2️⃣ Navigate to a Module
```bash
cd module_00/ex00
```

### 3️⃣ Compile and Run
```bash
make
./program_name
```

### 4️⃣ Clean Up
```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile everything
```

---

## 📂 Repository Structure

```
42-cpp-modules/
├── 📁 module_00/           # C++ Basics
│   ├── ex00_megaphone/
│   ├── ex01_phonebook/
│   └── ex02_account/
├── 📁 module_01/           # Memory & References
│   ├── ex00_zombie/
│   ├── ex01_zombie_horde/
│   ├── ex02_brain/
│   ├── ex03_violence/
│   ├── ex04_sed/
│   ├── ex05_harl/
│   └── ex06_harl_filter/
├── 📁 module_02/           # Operator Overloading
├── 📁 module_03/           # Inheritance
├── 📁 module_04/           # Polymorphism
├── 📁 module_05/           # Exceptions
├── 📁 module_06/           # Casts
├── 📁 module_07/           # Templates
├── 📁 module_08/           # STL Containers
├── 📁 module_09/           # STL Algorithms
├── 📄 README.md
└── 📄 .gitignore
```

---

## 🎯 Learning Objectives

<div align="center">

| **Concept** | **Module** | **Key Learnings** |
|------------|------------|-------------------|
| 🏗️ **OOP Fundamentals** | 00-01 | Classes, Objects, Encapsulation |
| ⚡ **Polymorphism** | 02, 04 | Operator Overloading, Virtual Functions |
| 🔗 **Inheritance** | 03-04 | Class Hierarchies, Abstract Classes |
| ⚠️ **Error Handling** | 05 | Exceptions, RAII |
| 🔧 **Type Safety** | 06 | C++ Cast Operators |
| 🧬 **Generic Programming** | 07-08 | Templates, STL |
| 🏆 **Advanced STL** | 09 | Algorithms, Best Practices |

</div>

---

## 🤝 Contributing

We welcome contributions! Here's how you can help:

1. **🍴 Fork** the repository
2. **🌿 Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **✅ Commit** your changes (`git commit -m 'Add some amazing feature'`)
4. **📤 Push** to the branch (`git push origin feature/amazing-feature`)
5. **🔀 Open** a Pull Request

### 📝 Contribution Guidelines

- Follow the **42 Norm** coding standards
- Add comments explaining complex logic
- Test your solutions thoroughly
- Update documentation when necessary

---

## 📖 Additional Resources

<div align="center">

| **Resource** | **Link** |
|--------------|----------|
| 📚 **42 Intranet** | [intra.42.fr](https://intra.42.fr) |
| 📖 **C++ Reference** | [cppreference.com](https://cppreference.com) |
| 🎓 **Learn C++** | [learncpp.com](https://learncpp.com) |
| 📝 **42 Norm** | [42 Coding Standard](https://github.com/42School/norminette) |

</div>

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

<div align="center">

**Made with ❤️ by the 42 Community**

*"The best way to learn C++ is to code C++"*

[![GitHub stars](https://img.shields.io/github/stars/yourusername/42-cpp-modules?style=social)](https://github.com/yourusername/42-cpp-modules/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/yourusername/42-cpp-modules?style=social)](https://github.com/yourusername/42-cpp-modules/network/members)

</div>
