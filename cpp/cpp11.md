# CPP 11

## Extensions to the C++ core language

### Rvalue references
A new non-const reference type called an rvalue reference, identified by `T&&` is added. This refers to temporaries that are permitted to be modified after they are initialized, for the purpose of allowing "move semantics" (solving a performance problem with costly and unneeded deep copies if an temporary is created or returned from a function, neglecting [return value optimization](https://en.wikipedia.org/wiki/Return_value_optimization "Return value optimization")).

For safety reasons, some restrictions are imposed. A named variable will never be considered to be an rvalue even if it is declared as such. To get an rvalue, the function template `std::move()` should be used. Rvalue references can also be modified only under certain circumstances, being intended to be used primarily with move constructors.

### Move constructors

A move constructor of class `T` is a non-template constructor whose first parameter is T&& (can be const and/or volatile) and the rest of the parameters, if present, have default values.

``class_name ( [const and/or volatile] class_name&& other)``

Typically called when an object is initialized temporary of the same type, including:

-   initialization: 
``T b; T a = std::move(b); T a(std::move(b));
``
-   function argument passing: 
``f(T arg) {}; T a; f(std::move(a));
``
-   function return: 
``T a; return a; 
``

It is is often optimized out or never made, see [copy elision](https://en.cppreference.com/w/cpp/language/copy_elision).

Typically "steals" the resources held by the argument rather than make copies of them, and leave the argument in some valid but otherwise indeterminate state (which can be specified by specific implementation). 

More info can be found [here](https://en.cppreference.com/w/cpp/language/move_constructor).

### Move assignment

``class_name& class_name::operator= ( [const and/or volatile] class_name&& other)``

Identical in usage and restrictions to move constructor (apart from need to protect from self-assignment).

More info can be found [here](https://en.cppreference.com/w/cpp/language/move_assignment).

### Generalized constant expressions

### Modification to the definition of plain old data

### Extern template

### Initializer lists

### Uniform initialization

### Type inference

### Range-based for loop

### Lambda functions and expressions

### Alternative function syntax

### Object construction improvement

### Explicit overrides and final

### Null pointer constant

### Strongly typed enumerations

### Right angle bracket

### Explicit conversion operators

### Template aliases

### Unrestricted unions

### Variadic templates

### New string literals

### User-defined literals

### Multithreading memory model

### Thread-local storage

### Explicitly defaulted and deleted special member functions

###  Type long long int]

### Static assertions

### Allow sizeof to work on members of classes without an explicit object

### Control and query object alignment

### Allow garbage collected implementations

### Attributes

## C++ standard library changes

### Upgrades to standard library components

### Threading facilities

### Tuple types

### Hash tables

### Regular expressions

### General-purpose smart pointers

### Extensible random number facility

### Wrapper reference

### Polymorphic wrappers for function objects

### Type traits for metaprogramming

### Uniform method for computing the return type of function objects

## Improved C compatibility

## Features removed or deprecated

## C11 changes

## References

-   [C++ 11 Wiki](https://en.wikipedia.org/wiki/C%2B%2B11#External_links)
-  [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor)
-  [Move assignment](https://en.cppreference.com/w/cpp/language/move_assignment)
<!--stackedit_data:
eyJoaXN0b3J5IjpbNzU4OTc2MjQ4LDIwNDczNzQ3MDgsMTYwNT
k3OTg5Miw2MTIzMzU3NDEsMTA3MjY2NDM0OF19
-->