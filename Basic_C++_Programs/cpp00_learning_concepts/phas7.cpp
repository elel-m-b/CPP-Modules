#include <iostream>

// 1. Stream Hierarchy and Basic Concepts

/*
                    ios_base
                       |
                       ios
                      /  \
                 istream  ostream
                 /    \   /    \
           ifstream   iostream  ofstream
                       |
                  fstream
*/

#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    // Output stream
    std::cout << "Hello world!" << std::endl;
    
    // Input stream  
    int number;
    std::cin >> number;

    // file stream
    std::ofstream file("test.txt");
    file << "Writing to file" << std::endl;
    file.close();

    // string stream

    std::stringstream ss;
    ss << "Number: " << number;
    std::string result = ss.str();
}

/*
+----------------+      +-----------------+      +---------------+
|   std::cout    |----->| std::streambuf  |----->|   stdout      |
|   (ostream)    |      |   (buffer)      |      | (console)     |
+----------------+      +-----------------+      +---------------+
         ↑                      ↑                       ↑
      User Code           Buffer Management        Destination
     
+----------------+      +-----------------+      +---------------+
|  std::ifstream |----->| filebuf         |----->|   File        |
|                |      | (derived)       |      |   on Disk     |
+----------------+      +-----------------+      +---------------+
*/

// Step-by-step std::cout << "Hello"


/*
-    What actually happens:
                1. std::cout.operator<<("Hello") is called
                2. ostream::operator<< checks stream state
                3. Delegates to streambuf::sputn("Hello", 5)
                4. streambuf checks if buffer has space
                - If buffer full: calls overflow()
                - If buffer empty: may buffer or write immediately
                5. Buffer manages the actual writing to stdout
                6. Returns ostream& for chaining
*/

/*
User Code: std::cout << "Hello" << " " << "World!";

Execution Flow:
+---------+     +----------+     +-------------+     +----------+
|  User   | --> | ostream  | --> | streambuf   | --> | Platform |
|  Code   |     | operator |     |   buffer    |     |  stdout  |
+---------+     +----------+     +-------------+     +----------+
     |               |                 |                  |
     | operator<<    | sputn()         | write()          |
     | ("Hello")     | → "Hello"       | → stdout         |
     |               |                 |                  |
     | operator<<    | sputn()         | write()          |
     | (" ")         | → " "           | → stdout         |
     |               |                 |                  |
     | operator<<    | sputn()         | write()          |
     | ("World!")    | → "World!"      | → stdout         |
     |               |                 |                  |
     | flush()       | sync()          | flush stdout     |
     | (if needed)   | → flush         | → complete       |
     +---------------+-----------------+------------------+
*/