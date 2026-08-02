# 42 C++ Modules

<div align="center">
  <img
    src="https://github.com/user-attachments/assets/a8cd8ff3-ed9a-4213-83bc-ad856276e9a2"
    alt="42 C++ Modules"
    width="100%"
  />
</div>

A collection of solutions and notes for the C++ Modules from the 42 School curriculum.

---

## About

This repository follows the official 42 C++ curriculum, covering the language from the basics of object-oriented programming to templates, the STL, and generic programming.

The goal of these modules is to build a solid understanding of C++ by writing code rather than relying on external libraries or modern language features. All projects follow the C++98 standard, encouraging a deeper understanding of memory management, inheritance, polymorphism, exceptions, and templates.

---
## C++ Modules Roadmap

```mermaid
flowchart TB

    START([🚀 Begin C++])

    START --> CPP00
    CPP00 --> CPP01
    CPP01 --> CPP02
    CPP02 --> CPP03
    CPP03 --> CPP04
    CPP04 --> CPP05
    CPP05 --> CPP06
    CPP06 --> CPP07
    CPP07 --> CPP08
    CPP08 --> CPP09
    CPP09 --> END([🏆 Complete])

    CPP00["CPP00<br/>Namespaces • Classes • Member Functions"]
    CPP01["CPP01<br/>Memory • Pointers • References"]
    CPP02["CPP02<br/>Canonical Form • Operator Overloading"]
    CPP03["CPP03<br/>Inheritance • Virtual Functions"]
    CPP04["CPP04<br/>Polymorphism • Abstract Classes"]
    CPP05["CPP05<br/>Exceptions • Try/Catch • Throw"]
    CPP06["CPP06<br/>Casts • RTTI • Scalar Conversion"]
    CPP07["CPP07<br/>Function & Class Templates"]
    CPP08["CPP08<br/>STL Containers • Iterators • Algorithms"]
    CPP09["CPP09<br/>STL Practice • RPN • Bitcoin • Merge-Insertion"]
```

---

## Repository Structure

```mermaid
flowchart TB

    ROOT["📦 Cpp-Modules"]

    ROOT --> CPP00["cpp00/"]
    ROOT --> CPP01["cpp01/"]
    ROOT --> CPP02["cpp02/"]
    ROOT --> CPP03["cpp03/"]
    ROOT --> CPP04["cpp04/"]
    ROOT --> CPP05["cpp05/"]
    ROOT --> CPP06["cpp06/"]
    ROOT --> CPP07["cpp07/"]
    ROOT --> CPP08["cpp08/"]
    ROOT --> CPP09["cpp09/"]
    ROOT --> README["README.md"]
```

Each module contains the exercises required by the subject along with a Makefile and the necessary source files.

---

## Requirements

- C++98 compatible compiler
- GNU Make
- Linux or macOS

Example:

```bash
cd cpp00/ex00
make
./ex00
```

---

## References

- 42 Intranet — https://intra.42.fr
- cppreference — https://cppreference.com
- Learn C++ — https://www.learncpp.com

---

## License

This repository is released under the MIT License. See the [LICENSE](LICENSE) file for more information.
