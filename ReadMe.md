# 42 C++ Modules (CPP00 → CPP09)

## Overview

This repository contains the 10 C++ modules from the 42 curriculum. The goal is to progressively learn C++ fundamentals (close to C++98 constraints) through practical exercises.
Each module introduces key concepts, with increasing abstraction and complexity.


## Global Skills Acquired
**OOP**: Encapsulation, inheritance, polymorphism, abstraction.
**Memory Management**: Stack vs heap, avoiding leaks, RAII.
**C++ Idioms**: Canonical form, operator overloading, exception safety.
**Generic Programming**: Templates, reusability.
**STL Mastery**: Containers, iterators, algorithms.


## Notes
All projects follow C++98 standard (42 requirement).
No external libraries.
Focus on understanding fundamentals rather than modern shortcuts.
Documented learning process and solved challenges with explanations.


## Links
42 C++ Curriculum: https://42.fr/en/the-program/innovative-learning/


## Modules:

### CPP00 — Basics of C++
Concepts: Namespaces (std), I/O streams, classes, member functions, this pointer, static members.
Takeaway: Transition from C to C++, object-oriented thinking.

### CPP01 — Memory & References
Concepts: Stack vs heap, new/delete, pointers vs references, file I/O.
Takeaway: Memory management and avoiding leaks.

### CPP02 — Orthodox Canonical Form
Concepts: Constructors/destructors, copy constructor, copy assignment operator, operator overloading.
Takeaway: Rule of 3 and object copying semantics.

### CPP03 — Inheritance
Concepts: Base/derived classes, method overriding, access specifiers, constructor/destructor chaining.
Takeaway: Code reuse and hierarchical design.

### CPP04 — Polymorphism
Concepts: Virtual functions, dynamic binding, abstract classes, deep vs shallow copy.
Takeaway: Runtime polymorphism and interface-based design.

### CPP05 — Exceptions
Concepts: try/catch/throw, custom exception classes, RAII.
Takeaway: Robust error handling.

### CPP06 — Casting
Concepts: static_cast, dynamic_cast, reinterpret_cast, const_cast.
Takeaway: Explicit and safe type conversions.

### CPP07 — Templates
Concepts: Function templates, class templates, generic programming.
Takeaway: Reusable, type-independent code.

### CPP08 — STL Containers & Algorithms
Concepts: vector, list, iterators, std::find, std::sort.
Takeaway: Efficient use of STL.

### CPP09 — Advanced STL
Concepts: map, set, data processing algorithms.
Takeaway: Combining STL tools for problem solving.


## Structure & Build
Clone this repository
Navigate to the desired module/exercise directory:
<cd CPP00/ex00>
Compile and run your program:
Build with <make> in each module folder.
<make
./PROGRAM_EXECUTABLE_NAME> (depends on the exercise)