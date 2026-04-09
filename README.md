# 🚀 C++ Modules - 42 School Journey

Welcome to my C++ learning repository! This project documents my progression through the 42 school C++ curriculum, from fundamental concepts to advanced object-oriented programming. Here, I explore the core pillars of C++: **OOP principles**, **memory management**, **design patterns**, and **modern C++ practices**.

---

## 📚 Modules Overview

### ✅ CPP00 - Namespaces, Classes & I/O
Introduction to C++ fundamentals and object-oriented programming basics.

**Concepts:**
- Namespaces and scope management
- Classes and objects
- Member variables and methods
- Basic encapsulation principles
- Standard input/output (std::cin, std::cout)
- Introduction to Orthodox Canonical Form

---

### ✅ CPP01 - Memory Allocation & References
Deep dive into memory management and pointer/reference semantics.

**Concepts:**
- Stack vs. Heap allocation
- Pointers and references
- new and delete operators
- Memory leaks and proper deallocation
- String manipulation
- File I/O operations

---

### ✅ CPP02 - Ad-hoc Polymorphism & Operator Overloading
Learning how to customize operator behavior through overloading.

**Concepts:**
- Operator overloading (arithmetic, comparison, assignment)
- Member vs. non-member operators
- Orthodox Canonical Form implementation
- Const correctness
- Copy semantics (copy constructor, copy assignment operator)
- Destructors

---

### ✅ CPP03 - Inheritance & Polymorphism
Exploring class hierarchies and runtime polymorphism.

**Concepts:**
- Inheritance (public, protected, private)
- Virtual functions and vtables
- Polymorphic behavior
- Method overriding
- Virtual destructors
- Multiple inheritance challenges

---

### ✅ CPP04 - Subtype Polymorphism & Abstract Classes
Advanced polymorphism with interfaces and pure virtual functions.

**Concepts:**
- Abstract base classes
- Pure virtual functions (interface pattern)
- Virtual inheritance
- Dynamic casting (dynamic_cast)
- Type identification (RTTI)
- Polymorphic design patterns

---

### ✅ CPP05 - Exceptions & Bureaucracy
Exception handling combined with classes, inheritance, and polymorphism.

**Concepts:**
- `try`, `throw`, `catch` — C++ exception mechanism
- Custom exception classes nested inside other classes (`std::exception` subclasses)
- Constructors that throw instead of returning an error
- Abstract base classes (`AForm`) with pure virtual functions
- Polymorphic `execute()` per concrete form type
- File I/O with `std::ofstream`
- Factory pattern with a dispatch table (pointer-to-function array)
- `protected` access for shared validation helpers

---

### ✅ CPP06 - C++ Casts
Understanding and applying the four C++ casting operators correctly.

**Concepts:**
- `static_cast` — safe compile-time conversions between compatible types
- `dynamic_cast` — safe runtime downcast for polymorphic types (returns `nullptr` on failure)
- `reinterpret_cast` — low-level bit reinterpretation (e.g. pointer ↔ `uintptr_t`)
- `const_cast` — adding/removing `const` qualifier
- Scalar type detection and conversion (char, int, float, double, pseudo-literals `nan`/`inf`)
- IEEE 754 special values: `nan`, `+inf`, `-inf` and their float variants
- Pointer serialisation with `uintptr_t` and `reinterpret_cast`
- Type identification without `typeid` using `dynamic_cast`

---

### ⏳ CPP07 - C++ Templates
*Coming Soon* - Generic programming with templates.

---

### ⏳ CPP08 - Templated Containers & Iterators
*Coming Soon* - STL containers and template specialization.

---

## 📁 Project Structure

<pre>
Cpps/
├── <a href="./cpp00">cpp00</a>
│   ├── <a href="./cpp00/ex00">ex00</a>
│   └── <a href="./cpp00/ex01">ex01</a>
├── <a href="./cpp01">cpp01</a>
│   ├── <a href="./cpp01/ex00">ex00</a>
│   ├── <a href="./cpp01/ex01">ex01</a>
│   ├── <a href="./cpp01/ex02">ex02</a>
│   ├── <a href="./cpp01/ex03">ex03</a>
│   ├── <a href="./cpp01/ex04">ex04</a>
│   ├── <a href="./cpp01/ex05">ex05</a>
│   └── <a href="./cpp01/ex06">ex06</a>
├── <a href="./cpp02">cpp02</a>
│   ├── <a href="./cpp02/ex00">ex00</a>
│   ├── <a href="./cpp02/ex01">ex01</a>
│   └── <a href="./cpp02/ex02">ex02</a>
├── <a href="./cpp03">cpp03</a>
│   ├── <a href="./cpp03/ex00">ex00</a>
│   ├── <a href="./cpp03/ex01">ex01</a>
│   ├── <a href="./cpp03/ex02">ex02</a>
│   └── <a href="./cpp03/ex03">ex03</a>
├── <a href="./cpp04">cpp04</a>
│   ├── <a href="./cpp04/ex00">ex00</a>
│   ├── <a href="./cpp04/ex01">ex01</a>
│   └── <a href="./cpp04/ex02">ex02</a>
├── <a href="./cpp05">cpp05</a>
│   ├── <a href="./cpp05/ex00">ex00</a>
│   ├── <a href="./cpp05/ex01">ex01</a>
│   ├── <a href="./cpp05/ex02">ex02</a>
│   └── <a href="./cpp05/ex03">ex03</a>
├── <a href="./cpp06">cpp06</a>
│   ├── <a href="./cpp06/ex00">ex00</a>
│   ├── <a href="./cpp06/ex01">ex01</a>
│   └── <a href="./cpp06/ex02">ex02</a>
├── cpp07 (coming soon)
└── cpp08 (coming soon)
</pre>
---

## 🧩 Key Learning Goals

- ✨ Master Object-Oriented Programming principles
- 💾 Understand memory management and resource allocation
- 🔄 Implement proper construction/destruction patterns
- 🎭 Leverage polymorphism for flexible designs
- 📖 Write clean, maintainable C++ code
- 🛡️ Apply const-correctness and best practices

---

## 💡 Motivation

This journey through C++ is more than just learning syntax—it's about understanding the philosophy behind one of the most powerful programming languages. Each module builds upon the previous, gradually unlocking the ability to write robust, efficient, and elegant C++ applications. The path to mastery is paved with repetition, practice, and persistence. Keep pushing! 🎯

---

**<pre>This project has been created as part of the 42 curriculum by tmarcos.</pre>**
