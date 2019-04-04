# CPP 11

## Extensions to the C++ core language

### Rvalue references
A new non-const reference type called an rvalue reference, identified by `T&&` is added. This refers to temporaries that are permitted to be modified after they are initialized, for the purpose of allowing "move semantics" (solving a performance problem with costly and unneeded deep copies if an temporary is created or returned from a function, neglecting [return value optimization](https://en.wikipedia.org/wiki/Return_value_optimization "Return value optimization")).

For safety reasons, some restrictions are imposed. A named variable will never be considered to be an rvalue even if it is declared as such. To get an rvalue, the function template [`std::move()`](https://en.cppreference.com/w/cpp/utility/move) should be used. Rvalue references can also be modified only under certain circumstances, being intended to be used primarily with move constructors.

More info about various value categories (including newer C++ standard ones) can be found [here](https://en.cppreference.com/w/cpp/language/value_category) and [here](https://docs.microsoft.com/en-us/cpp/cpp/rvalue-reference-declarator-amp-amp?view=vs-2019).

### Move constructors

A move constructor of class `T` is a non-template constructor whose first parameter is T&& (can be const and/or volatile) and the rest of the parameters, if present, have default values.

``class_name ( [const and/or volatile] class_name&& other)``

Although argument can be const per specification it is seldom so, because it "interferes" with "stealing" the resource from it.

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

Sample code with move assignment and move constructor can be found in [Move.cpp](Move.cpp)

### Generalized constant expressions

Keyword `constexpr` is introduced specifying that a function or object constructor is a compile-time constant.

`constexpr int get_five() {return 5;}`

`int some_value[get_five() + 7]; // Create an array of 12 integers. Invalid without constexpr above.`

- function must have a non-void return type
- cannot declare variables or define new types
- . Third, the body may contain only declarations, null statements and a single return statement. There must exist argument values such that, after argument substitution, the expression in the return statement produces a constant expression.

Before C++11, the values of variables could be used in constant expressions only if the variables are declared const, have an initializer which is a constant expression, and are of integral or enumeration type. C++11 removes the restriction that the variables must be of integral or enumeration type if they are defined with the `constexpr` keyword:

constexpr double earth_gravitational_acceleration = 9.8;
constexpr double moon_gravitational_acceleration = earth_gravitational_acceleration / 6.0;

Such data variables are implicitly const, and must have an initializer which must be a constant expression.

To construct constant expression data values from user-defined types, constructors can also be declared with `constexpr`. A `constexpr` constructor's function body can contain only declarations and null statements, and cannot declare variables or define types, as with a `constexpr` function. There must exist argument values such that, after argument substitution, it initializes the class's members with constant expressions. The destructors for such types must be trivial.

The copy constructor for a type with any `constexpr` constructors should usually also be defined as a `constexpr` constructor, to allow objects of the type to be returned by value from a constexpr function. Any member function of a class, such as copy constructors, operator overloads, etc., can be declared as `constexpr`, so long as they meet the requirements for constexpr functions. This allows the compiler to copy objects at compile time, perform operations on them, etc.

If a constexpr function or constructor is called with arguments which aren't constant expressions, the call behaves as if the function were not constexpr, and the resulting value is not a constant expression. Likewise, if the expression in the return statement of a constexpr function does not evaluate to a constant expression for a given invocation, the result is not a constant expression.
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
- [Value categories](https://en.cppreference.com/w/cpp/language/value_category)
- [RValue references](https://docs.microsoft.com/en-us/cpp/cpp/rvalue-reference-declarator-amp-amp?view=vs-2019).
<!--stackedit_data:
eyJoaXN0b3J5IjpbMTI1NDUyNzI2OCwxNTk2NzA0NjYyLC02Nj
k2NjA4OTQsNDcwNTMzMjI4LDc0MzkwMTE0NCwxNDk4NTY5MTk1
LDc1ODk3NjI0OCwyMDQ3Mzc0NzA4LDE2MDU5Nzk4OTIsNjEyMz
M1NzQxLDEwNzI2NjQzNDhdfQ==
-->