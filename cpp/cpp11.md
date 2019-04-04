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
- may contain only declarations, null statements and a single return statement
- return statement produces a constant expression (after argument substitution)

In addition constant expressions need not be of integral or enumeration type anymore.

`constexpr double earth_gravitational_acceleration = 9.8;`
`constexpr double moon_gravitational_acceleration = earth_gravitational_acceleration / 6.0;`

### Modification to the definition of plain old data

POD concept devided into two separate concepts: _trivial_ (statically initializiable and `memcpy`able) and _standard-layout_ (compatible with C, member ordering and packing).

A _trivial_ class or struct is defined as one that has trivial constructors (default, copy and move), trivial copy and move assignment operator and trivial and non virtual destructor. 

A class or struct is _standard-layout_ if it has no virtual functions or base classes, all members have same acess, and some other rules that can be seen [here](https://en.wikipedia.org/wiki/C%2B%2B11#Modification_to_the_definition_of_plain_old_data).

### Extern template

`extern template class std::vector<MyClass>;`

Compiler _will not_ instantiate the template in current translation unit (build time reduced).

### Initializer lists

Initializer-lists are extended to be used for all classes (before they were for PODs, structs and arrays only).

Concept is bound to [`std::initializer_list`](https://en.cppreference.com/w/cpp/utility/initializer_list) which can be parameter for concstructors/functions.

```cpp
class SequenceClass
{
public:
    SequenceClass(std::initializer_list<int> list);
};
SequenceClass some_var = {1, 4, 5, 6};
```

This constructor is a special kind of constructor, called an initializer-list-constructor. Classes with such a constructor are treated specially during uniform initialization (see [below](https://en.wikipedia.org/wiki/C%2B%2B11#Uniform_initialization))

The template class `std::initializer_list<>` is a [first-class](https://en.wikipedia.org/wiki/First-class_citizen "First-class citizen") C++11 standard library type. They can be constructed statically by the C++11 compiler via use of the `{}` syntax without a type name in contexts where such braces will deduce to an `std::initializer_list`, or by explicitly specifying the type like `std::initializer_list<SomeType>{args}` (and so on for other varieties of construction syntax).

The list can be copied once constructed, which is cheap and will act as a copy-by-reference (the class is typically implemented as a pair of begin/end pointers). An `std::initializer_list` is constant: its members cannot be changed once it is created, and nor can the data in those members be changed (which rules out moving from them, requiring copies into class members, etc.).

Although its construction is specially treated by the compiler, an `std::initializer_list` is a real type, and so it can be used in other places besides class constructors. Regular functions can take typed `std::initializer_list`s as arguments. For example:

void function_name(std::initializer_list<float> list); // Copying is cheap; see above

function_name({1.0f, -3.45f, -0.4f});

Examples of this in the standard library include the `std::min()` and `std::max()` templates taking `std::initializer_list`s of numeric type.

Standard containers can also be initialized in these ways:

std::vector<std::string> v = { "xyzzy", "plugh", "abracadabra" };
std::vector<std::string> v({ "xyzzy", "plugh", "abracadabra" });
std::vector<std::string> v{ "xyzzy", "plugh", "abracadabra" }; // see "Uniform initialization" below
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
eyJoaXN0b3J5IjpbMTA0ODczNjExNiwxODc2OTI4MDIwLDE0Mj
M0NzM4NDAsMTU5NjcwNDY2MiwtNjY5NjYwODk0LDQ3MDUzMzIy
OCw3NDM5MDExNDQsMTQ5ODU2OTE5NSw3NTg5NzYyNDgsMjA0Nz
M3NDcwOCwxNjA1OTc5ODkyLDYxMjMzNTc0MSwxMDcyNjY0MzQ4
XX0=
-->