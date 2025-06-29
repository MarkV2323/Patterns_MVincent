# Design Patterns in Software Engineering

Welcome to the **Design Patterns** repository! This repo provides concise, practical examples of common design patterns in software engineering, implemented in python3. 

## What are Design Patterns?

**Design patterns** are typical solutions to commonly occurring problems in software design. They're like templates that can be applied to real-world programming situations to improve code flexibility, scalability, and maintainability.

Design patterns are generally categorized into three main types:

### 1. **Creational Patterns**

These patterns deal with object creation mechanisms.

* [] Singleton
* [] Factory Method
* [] Abstract Factory
* [] Builder
* [] Prototype

### 2. **Structural Patterns**

These patterns deal with the composition of classes and objects.

* [] Adapter
* [] Bridge
* [] Composite
* [] Decorator
* [] Facade
* [] Flyweight
* [] Proxy

### 3. **Behavioral Patterns**

These focus on communication between objects.

* [] Chain of Responsibility
* [] Command
* [] Interpreter
* [] Iterator
* [] Mediator
* [] Memento
* [] Observer
* [] State
* [] Strategy
* [] Template Method
* [] Visitor

## 🗂️ Repository Structure

```bash
Patterns_MVincent/
│
├── creational/
│   ├── singleton.py
│   └── factory-method.py
│
├── structural/
│   ├── adapter.py
│   └── decorator.py
│
├── behavioral/
│   ├── observer.py
│   └── strategy.py
│
├── shared/                # Utility classes / Resources
└── README.md              # You're here!
```

Each pattern folder contains:

* A simple code example
* Code comments explaining each part
* A short `README.md` explaining the pattern, when to use it, pros/cons, and real-world examples

## 📚 PEP 8 Naming Summary
| Type           | Style                                       | Example                        |
| -------------- | ------------------------------------------- | ------------------------------ |
| Directory name | `lowercase` or `lowercase_with_underscores` | `my_app/`, `data_processing/`  |
| Module name    | `snake_case` (all lowercase)                | `config.py`, `api_client.py`   |
| Class name     | `PascalCase`                                | `DataParser`, `MyService`      |
| Function name  | `snake_case`                                | `parse_file()`, `connect_db()` |
| Constant name  | `UPPER_CASE`                                | `MAX_RETRIES = 3`              |

## 🛠️ Getting Started

1. Clone the repo.

2. Browse the folders by pattern category.

3. Run the examples in your preferred language.

## ⭐️ License

This project is licensed under the MIT License.
