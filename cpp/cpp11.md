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

Concept is bound to [`std::initializer_list`](https://en.cppreference.com/w/cpp/utility/initializer_list) which can be parameter for constructors/functions.

```cpp
class SequenceClass
{
public:
    SequenceClass(std::initializer_list<int> list);
};

SequenceClass some_var = {1, 4, 5, 6};

function_name({1.0f, -3.45f, -0.4f});
```
Constructor with such parameter is treated specially during uniform initialization.

Class `std::initializer_list<>` can be constructed statically by the compiler using `{}`  and it's copying is cheap.

### Uniform initialization
Uniform type initialization works on any object (not just aggregates and PODs as before). Now it can be used to initialize simple types, invoke constructors, initialize (public) data members, etc...


```cpp
struct BasicStruct
{
    int x;
    std::string s;
};

class BasicClass
{
public:
    BasicClass(int x, const std::string& as)
        : x_{ x }
        , s_{ as }
    {}
private:
    int x_;
    std::string s_;
};

class InitializerClass
{
public:
    InitializerClass(std::initializer_list<std::any> list)
    {
        assert(list.size() > 1);
        auto it = list.begin();
        x_ = std::any_cast<int>(*it++);
        s_ = std::any_cast<const char *>(*it++);
    }
private:
    int x_;
    std::string s_;
};

BasicClass GetBasicClass() {
    return { 5, "foobar" }; // no explicit type needed here
}

int a = { 1 };
int aa[] = { 1, 2, 3, 4 };
BasicStruct var1{ 5, "foobar" }; // initialize public members
BasicClass var2{ 2, "foobar" }; // call constructor
BasicClass var3 = GetBasicClass();
InitializerClass var4{ 5, "foobar" }; // call initializer list constructor
```

If a class has an initializer list constructor, then it takes priority over other forms of construction


```cpp
std::vector<int> the_vec{4}; // vector with one integer { 4 }
std::vector<int> the_vec2(4); // vector with four integers { 0, 0, 0, 0 }
```

### Type inference

The definition of a variable with an explicit initialization can use the `auto` keyword. This creates a variable of the specific type of the initializer.

Keyword `decltype` can be used to determine the type of expression at compile-time.

The type denoted by `decltype` can be different from the type deduced by `auto`.

```cpp
#include <vector>
int main()
{
    const std::vector<int> v(1);
    auto a = v[0];        // a has type int
    decltype(v[0]) b = 1; // b has type const int&, the return type of
                          //   std::vector<int>::operator[](size_type) const
    auto c = 0;           // c has type int
    auto d = c;           // d has type int
    decltype(c) e;        // e has type int, the type of the entity named by c
    decltype((c)) f = c;  // f has type int&, because (c) is an lvalue
    decltype(0) g;        // g has type int, because 0 is an rvalue
}
```

**Auto with initializer list**: `auto z = { 42 };` type of `z` is `std::initializer_list<int>` and not just `int`!!!

### Range-based for loop

Syntax of the `for` statement is extended to allow easy iteration over a range of elements:


```cpp
int my_array[5] = {1, 2, 3, 4, 5};
// double the value of each element in my_array:
for (int& x : my_array)
    x *= 2;
```

“Range-based for” will work for C-style arrays, initializer lists, and any type that has `begin()` and `end()` functions.

### Alternative function syntax
"Traditional" function syntax doesn't allow "guessing" of function return type based function parameters.

```cpp
template<class Lhs, class Rhs>
  decltype(lhs+rhs) adding_func(const Lhs &lhs, const Rhs &rhs) {return lhs + rhs;} //Not valid C++11
```
This is not valid C++ because `lhs` and `rhs` have not yet been defined when used in `decltype`.

New function declaration syntax, with a _trailing-return-type_ can be used to achive desired:

```cpp
template<class Lhs, class Rhs>
  auto adding_func(const Lhs &lhs, const Rhs &rhs) -> decltype(lhs+rhs) {return lhs + rhs;}
```

Keyword `auto` is part of the syntax and does not perform automatic type deduction.

### Lambda functions and expressions

_Lambda expressions_ are anonymous functions of the form:

`[capture](parameters) -> return_type { function_body }`

Return type and/or parameters can be omitted: `[capture] { function_body }`

Example:
```cpp
std::vector<int> some_list{ 1, 2, 3, 4, 5 };
int total = 0;
int value = 5;
std::for_each(begin(some_list), end(some_list), [&, value, this](int x) {
	total += x * value * this->some_func();
});
```

_capture_ specifies which **variables** outside of the lambda can be used inside it's body and can be:

- `[]` - no variables captured.
- `[x, &y]` - x is captured by value, y is captured by reference
- `[&]` - any external variable is implicitly captured by reference if used
- `[=]` - any external variable is implicitly captured by value if used
- `[&, x]` - x is explicitly captured by value, other variables will be captured by reference
- `[=, &z]` - z is explicitly captured by reference, other variables will be captured by value

Variables captured by value are constant by default, `mutable` after the parameter list makes them non-constant.

The capture of `this` is special. It can only be captured by value, not by reference. The lambda will have the same access as the member that created it, in terms of protected/private members. 

Class members cannot be captured explicitly by a capture (only **variables**), using them requires explicit or implicit capture of _this_. 

**Caution** when a lambda captures a member using implicit by-copy capture, it does not make a copy of that member variable (it captures _this_ and access memeber by reference using _this_).

For example see [Lambda.cpp](Lambda.cpp), lines 31 through 47.

If a nested lambda `m2` captures something that is also captured by the immediately enclosing lambda `m1`, then `m2`'s capture is transformed as follows:
-   if the enclosing lambda `m1` captures by copy, `m2` is capturing the non-static member of `m1`'s closure type, not the original variable or `this`.
-   if the enclosing lambda `m1` captures by reference, `m2` is capturing the original variable or `this`.

For example see [Lambda.cpp](Lambda.cpp), lines 88 and below.

If a closure object containing references to local variables is invoked after the innermost block scope of its creation, the behavior is undefined. 

The special case is a reference parameter that is captured by reference, it is using the object referred-to by the original reference, not the captured reference itself.

Lambda functions can be stored in [`std::function`](https://en.cppreference.com/w/cpp/utility/functional/function)  or `auto` variable (their exact type is implementation specific).

A lambda expression with an empty capture specification (`[]`) can be implicitly converted into a function pointer with the same type as the lambda was declared with. 

```cpp
auto a_lambda_func = [](int x) { /*...*/ };
void (* func_ptr)(int) = a_lambda_func;
func_ptr(4); //calls the lambda.
```

More info can be found [here](https://en.cppreference.com/w/cpp/language/lambda).

Sample code with lambda can be found in [Lambda.cpp](Lambda.cpp)

### Object construction improvement

Constructors are allowed to call other peer constructors:
```cpp
class SomeType
{
    int number;
public:
    SomeType(int new_number) : number(new_number) {}
    SomeType() : SomeType(42) {}
};
```

**Warning**:  An object is constructed once _any_ constructor finishes execution. This means that delegating constructor will be executing on a fully constructed object. 

A class is allowed to specify that base class constructors will be inherited. Compiler will automatically generate code needed. This is an all-or-nothing feature: either all base class's constructors are forwarded or none.


```cpp
class BaseClass
{
public:
    BaseClass(int value);
};

class DerivedClass : public BaseClass
{
public:
    using BaseClass::BaseClass;
};

```

Members can be initialized (not only static const):
```cpp
class SomeClass
{
public:
    SomeClass() {}
    explicit SomeClass(int new_value) : value(new_value) {}

private:
    int value = 5;
};
```

### Explicit overrides and final

The `override` identifier forces compiler check if the base class have a virtual function with this exact signature. 

The `final` identifier prevents inheriting from classes or  overriding methods in derived classes. 

```cpp
struct Base
{
	virtual void some_func(float f) {
		std::cout << "Base::some_func(float) " << f << std::endl;
	};
 
	virtual void some_other(float f) {};
	virtual void some_final(float f) final {};
};
 
struct Derived : Base
{
	virtual void some_func(double i) {  // error while overriding, wrong parameter type/signature so actually creating new function
		std::cout << "Derived::some_func(int) " << i << std::endl;
	};
 	virtual void some_other(double f) override {}; // error while compiling because override looks for base class function
 	virtual void some_final(float f)  {}; // error while compiling because base class function is final
};

struct FinalBase final { };
 
struct DerivedFromFinal : FinalBase { }; // ill-formed because the class FinalBase has been marked final
```

### Null pointer constant

New keyword to serve as a distinguished null pointer constant: `nullptr` so it can be distinguished from `0` integer constant.
It is of type `nullptr_t`, which is implicitly convertible and comparable to any pointer type or pointer-to-member type. It is not implicitly convertible or comparable to integral types, except for `bool`.

### Strongly typed enumerations

Enumeration that are type-safe, are not introduced into enclosing scope and cannot be implicitly converted to integers are defined as:

```cpp
enum class Gender : unsigned short {
	Male,
	Female,
	Neutral
};
```
Type can be omitted and defaults to `int`.


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
- [Lambda expressions](https://en.cppreference.com/w/cpp/language/lambda)
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTE3MDM0NTM2NzQsLTEwNjA5MjcyMzIsNj
Y2OTUwMDMxLC04OTQ5MDY0MjYsOTcwMTc4NTgsLTE3NjcxNDEw
NSwtMTk1NDE2MTgsLTE1NDU0NDgzNzYsLTYwMjU5MzUxNyw0MT
M2MzQzNDUsLTMyOTgxMTM1OCwxNjg2MjM0NDQ4LDE5NjA3Mjcx
MCwxNjY5MzQ2OTE0LDMwNTA3ODkxOSwtMTY4NTY5NDA0OSwxMD
k5ODEyNzQ1LDU4OTMwMzE3NywxMjA4MjE3MDc5LDk5MTg3OTAw
NF19
-->