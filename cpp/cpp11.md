# CPP 11

## Extensions to the C++ core language

### Rvalue references and move constructors
A new non-const reference type called an rvalue reference, identified by `T&&` is added. This refers to temporaries that are permitted to be modified after they are initialized, for the purpose of allowing "move semantics".

a performance problem with C++03 is the costly and unneeded [deep copies](https://en.wikipedia.org/wiki/Deep_copy "Deep copy") that can happen implicitly when objects are passed by value. To illustrate the issue, consider that an `std::vector<T>` is, internally, a wrapper around a C-style array with a defined size. If an `std::vector<T>` temporary is created or returned from a function, it can be stored only by creating a new `std::vector<T>` and copying all the rvalue's data into it. Then the temporary and all its memory is destroyed. (For simplicity, this discussion neglects the [return value optimization](https://en.wikipedia.org/wiki/Return_value_optimization "Return value optimization").)

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
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTIzMzAyMDgxOSwxMDcyNjY0MzQ4XX0=
-->