# CPP 11

<!-- toc -->

- [Extensions to the C++ core language](#extensions-to-the-c-core-language)
  * [Rvalue references](#rvalue-references)
  * [Reference qualifier](#reference-qualifier)
  * [Move constructors](#move-constructors)
  * [Move assignment](#move-assignment)
  * [std::move](#stdmove)
  * [std::forward](#stdforward)
  * [Generalized constant expressions](#generalized-constant-expressions)
  * [Modification to the definition of plain old data](#modification-to-the-definition-of-plain-old-data)
  * [Extern template](#extern-template)
  * [Initializer lists](#initializer-lists)
  * [Uniform initialization](#uniform-initialization)
  * [Type inference](#type-inference)
  * [Range-based for loop](#range-based-for-loop)
  * [Alternative function syntax](#alternative-function-syntax)
  * [Lambda functions and expressions](#lambda-functions-and-expressions)
  * [Object construction improvement](#object-construction-improvement)
  * [Explicit overrides and final](#explicit-overrides-and-final)
  * [Null pointer constant](#null-pointer-constant)
  * [Strongly typed enumerations](#strongly-typed-enumerations)
  * [Right angle bracket](#right-angle-bracket)
  * [Explicit conversion operators](#explicit-conversion-operators)
  * [Template aliases](#template-aliases)
  * [Unrestricted unions](#unrestricted-unions)
  * [Variadic templates](#variadic-templates)
  * [New string literals](#new-string-literals)
  * [User-defined literals](#user-defined-literals)
  * [Multithreading memory model](#multithreading-memory-model)
  * [Thread-local storage](#thread-local-storage)
  * [Explicitly defaulted and deleted special member functions](#explicitly-defaulted-and-deleted-special-member-functions)
  * [Type long long int](#type-long-long-int)
  * [Static assertions](#static-assertions)
  * [Allow sizeof to work on members of classes without an explicit object](#allow-sizeof-to-work-on-members-of-classes-without-an-explicit-object)
  * [Control and query object alignment](#control-and-query-object-alignment)
  * [Allow garbage collected implementations](#allow-garbage-collected-implementations)
  * [Attributes](#attributes)
- [C++ standard library changes](#c-standard-library-changes)
  * [Threading facilities](#threading-facilities)
    + [Thread class](#thread-class)
    + [Mutexes, locks and condition variables](#mutexes-locks-and-condition-variables)
    + [Futures and promises](#futures-and-promises)
    + [Atomic variables](#atomic-variables)
    + [Memory orders/barriers](#memory-ordersbarriers)
  * [Tuple types](#tuple-types)
  * [Containers](#containers)
  * [Regular expressions](#regular-expressions)
  * [General-purpose smart pointers](#general-purpose-smart-pointers)
  * [Extensible random number facility](#extensible-random-number-facility)
  * [Time manipulation](#time-manipulation)
  * [Rational arithmetics](#rational-arithmetics)
  * [Wrapper reference](#wrapper-reference)
  * [Polymorphic wrappers for function objects](#polymorphic-wrappers-for-function-objects)
  * [Type traits for metaprogramming](#type-traits-for-metaprogramming)
  * [Uniform method for computing the return type of function objects](#uniform-method-for-computing-the-return-type-of-function-objects)
  * [New C++ Algorithms](#new-c-algorithms)
  * [std::string conversion enhancements](#stdstring-conversion-enhancements)
  * [Copying and rethrowing exceptions](#copying-and-rethrowing-exceptions)
- [Features removed or deprecated](#features-removed-or-deprecated)
- [Some of the references](#some-of-the-references)

<!-- tocstop -->

## Extensions to the C++ core language

### Rvalue references
A new non-const reference type called an rvalue reference, identified by `T&&` is added. This refers to temporaries that are permitted to be modified after they are initialized, for the purpose of allowing "move semantics" (solving a performance problem with costly and unneeded deep copies if an temporary is created or returned from a function, neglecting [return value optimization](https://en.wikipedia.org/wiki/Return_value_optimization "Return value optimization")).

For safety reasons, some restrictions are imposed. A named variable will never be considered to be an rvalue even if it is declared as such. To get an rvalue, the function template [`std::move()`](https://en.cppreference.com/w/cpp/utility/move) should be used. Rvalue references can also be modified only under certain circumstances, being intended to be used primarily with move constructors.

More info about various value categories (including newer C++ standard ones) can be found [here](https://en.cppreference.com/w/cpp/language/value_category) and [here](https://docs.microsoft.com/en-us/cpp/cpp/rvalue-reference-declarator-amp-amp?view=vs-2019).

There is a special meaning when rvalue reference is used in template type deduction, for more info see [Type deduction rules for rvalue references](tricky.md#type-deduction-rules-for-rvalue-references) and
[Template type deduction](tricky.md#template-type-deduction).


### Reference qualifier 

Reference qualifier in method signature plays part in resolution which method gets invoked.

```cpp
class A {
public:
	void method() & { // invoked only when *this is an lvalue
		std::cout << "lvalue" << std::endl;
	}
	void method() && { // invoked only when *this is an rvalue
		std::cout << "rvalue" << std::endl;
	}
};

int main()
{
	A a;
	a.method(); // lvalue version invoked
	A().method(); // rvalue version invoked
}
```


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

**Note:** If possible make move constructor `noexcept` because it allows optimizations as well as some STL code behaves more optimal (`std::vector` for example).

### Move assignment

``class_name& class_name::operator= ( [const and/or volatile] class_name&& other)``

Identical in usage and restrictions to move constructor (apart from need to protect from self-assignment).

More info can be found [here](https://en.cppreference.com/w/cpp/language/move_assignment).

Sample code with move assignment and move constructor can be found in [Move.cpp](Move.cpp)


### std::move

Called move because it is usually used in move operations.

Simple cast to rvalue reference (no code generated). The actually "work" is done by argument overload resolution (which chooses between copy and move operations, assignment and/or constructor or other). 
std::move does a simple cast which tells compiler to choose move operation programmer wants instead of one that would be chosen by default, copy.

**Note:** if called on const it won't actually move (call move constructor/assignment) but copy (construct/assignment). 

Why, `std::move(const T)` will produce `const T&&` which argument resolution cannot bind to `T&&` (argument for move operations). However it can bind it to `const T&` (argument for copy operations).

```cpp
#include <iostream>

struct A {
	A() { std::cout << "Default constructor" << std::endl;  }
	A(const A&) { std::cout << "Copy constructor" << std::endl; }
	A(A&&) { std::cout << "Move constructor" << std::endl; }
};

A myMove(const A& a) {
	return std::move(a); // actually makes a copy
}

A myOtherMove(A& a) {
	return std::move(a); // actually moves
}

int main() {
	A a;
	A b = myMove(a);
	A c = myOtherMove(a);
}
```

This is good for backward compatibility because objects without move constructor will simply copy and continue to work.

**Note:** `std::move_if_noexcept` also exists (which does move even if not noexcpet in cases where there is no copy constructor :)).


### std::forward

Conditional cast to rvalue reference, return rvalue only if original value of param (which might be lvalue because it has a name) is rvalue, otherwise it returns lvalue.

### Generalized constant expressions

Keyword `constexpr` is introduced specifying that a function or object constructor is a compile-time constant.

`constexpr int get_five() {return 5;}`

`int some_value[get_five() + 7]; // Create an array of 12 integers. Invalid without constexpr above.`

- function must have a non-void return type
- cannot declare variables or define new types
- may contain only declarations, null statements and a single return statement
- return statement produces a constant expression (after argument substitution)

**Note**: [Relaxed constexpr restrictions in C++14](cpp14.md#relaxed-constexpr-restrictions).

In addition constant expressions need not be of integral or enumeration type anymore.

`constexpr double earth_gravitational_acceleration = 9.8;`

`constexpr double moon_gravitational_acceleration = earth_gravitational_acceleration / 6.0;`

**Note:** constexpr functions will be evaluated at compile time when all its arguments are constant expressions and 
the result is used in a constant expression as well, otherwise it can be executed at run time.

```cpp
#include <iostream>

constexpr int justReturn(int value) {
	return value;
}

int main() {
	int a[justReturn(10)]; // compile time execution

	int i;
	std::cout << "Please enter a number" << std::endl;
	std::cin >> i;
	std::cout << std::endl << "You entered " << justReturn(i) << std::endl; // run time execution
}
```

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

**NOTE**: Initializer list assignment and construction does not automatically narrow! Widening is performed!

```cpp
int x = 7.3; // ok, standard C narrowing
int x0{ 7.3 };	// error: narrowing
int x1 = { 7.3 };	// error: narrowing
double y = 7; // ok
double y0{ 7 };	// ok: widening
double y1 = { 7 };	// ok: widening
```

### Uniform initialization
Uniform type initialization works on any object (not just aggregates and PODs as before). Now it can be used to initialize simple types, invoke constructors, initialize (public) data members, etc...

Also sometimes called **braced initialization**.


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

**If a class has an initializer list constructor, then it takes priority over other forms of construction, care needed when adding such constructor to a class!**

```cpp
std::vector<int> the_vec{4}; // vector with one integer { 4 }
std::vector<int> the_vec2(4); // vector with four integers { 0, 0, 0, 0 }
std::vector<int> the_vec{4, 4}; // vector with two integers { 4, 4}
std::vector<int> the_vec2(4, 4); // vector with four integers having value of 4 { 4, 4, 4, 4 }
```

**Empty braces, `{}`, mean default constructor, not empty initializer list.**


**Uniform initialization with empty parameter list, `{}`, avoids "most vexing parse" rule.**

Rule says anything that could be a declaration must be treated as declaration, meaning you could not call default constructor without parameters using `MyClass a()` 
syntax because it could be and will be treated as function declaration.

```cpp
#include <iostream>

struct MyStruct
{
	MyStruct(int a = 0) : b(a) {};
	int b;
};

MyStruct a1;
MyStruct a2();     // function declaration
MyStruct a3(10);
MyStruct a4{};
MyStruct a5{10};

int main() {
	std::cout << a1.b << std::endl;
	std::cout << a2.b << std::endl;  // error here, because a2 is treated as a2 function 
	std::cout << a3.b << std::endl;
	std::cout << a4.b << std::endl;
	std::cout << a5.b << std::endl;
}
```

### Type inference

The definition of a variable with an explicit initialization can use the `auto` keyword. This creates a variable of the specific type of the initializer.
For more info about type deduction see [auto type deduction](tricky.md#auto-type-deduction).

**auto cannot be used to qualify arrays, functions arguments (except lambdas in C++14) or struct/class instance variables, or used as a cast type.**

**Auto with initializer list**: `auto z = { 42 };` type of `z` is `std::initializer_list<int>` and not just `int`!!! (**C++ 17 makes some changes!**)


Keyword `decltype` can be used to determine the type of expression at compile-time.

The type denoted by `decltype` can be different from the type deduced by `auto`. `auto` always deduces a non-reference type while `auto&&` always deduces a reference type. 
However, `decltype` can deduce a reference or non-reference type, based on the value category of the expression and the nature of the expression.
For more info see [decltype type](tricky.md#decltype-type).

**Note:** to combine automatic type deduction and decltype rules you can use `decltype(auto)` (C++14).

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
	auto* e = new auto(2105) // e has type int*
    decltype(c) e;        // e has type int, the type of the entity named by c
    decltype((c)) f = c;  // f has type int&, because (c) is an lvalue
    decltype(0) g;        // g has type int, because 0 is an rvalue
	
	int i = 1;
	const int& ri = i;
	auto ai = ri;                    // type of ai is int
	decltype(auto) dai = ri;         // type of dai is int&
}
```


```cpp
int   i;
int&& f();
auto          x3a = i;     // decltype(x3a) is int
decltype(i)   x3d = i;     // decltype(x3d) is int
auto          x4a = (i);   // decltype(x4a) is int
decltype((i)) x4d = (i);   // decltype(x4d) is int&
auto          x5a = f();   // decltype(x5a) is int
decltype(f()) x5d = f();   // decltype(x5d) is int&&
```


**Some say using auto is nice way of not forgetting to initialize variable since compiler errors on auto without initialization.**

**As well as avoid unintentional implicit conversions when programmer explicitly uses wrong type.**

```cpp
std::vector v = {1, 2, 3};
unsigned size = v.size();    // on 64 bit system this would lead to narrowing implicit conversion from 64bit unsigned int to 32bit unsigned int
auto size2 = v.size(); // no implicit conversion

std::map<std::string, std::string> m = { {"foo", "bar"}, {"jane", "doe"} };

for (const std::pair<std::string, std::string>& p : m) // conversion from std::pair<const std::string, std::string> to std::pair<std::string, std::string>, p is a temporary
{
	std::cout << &p << std::endl;
}
for (const auto& p : m) // no conversion, p is "directly" from map 
{
	std::cout << &p << std::endl;
}

auto* n = new auto(2105) // deduces int*
```


**auto does not play well with "invisible proxy" classes!**

```cpp
std::vector<int> vi = { 1, 2, 3, 4 };
std::vector<bool> vb = { true, false, true, false };

auto second_int = vi[2]; // type is int
std::cout << typeid(second_int).name() << std::endl;

auto second_bool = vb[2]; // type is std::vector<bool>::reference!!!!!!
std::cout << typeid(second_bool).name() << std::endl;

auto second_bool_true = static_cast<bool>(vb[2]); // type is bool
std::cout << typeid(second_bool_true).name() << std::endl;
```



### Range-based for loop

Syntax of the `for` statement is extended to allow easy iteration over a range of elements:


```cpp
int my_array[5] = {1, 2, 3, 4, 5};
// double the value of each element in my_array:
for (int& x : my_array)
    x *= 2;
```

“Range-based for” will work for C-style arrays, initializer lists, and any type that has `begin()` and `end()` functions.

If range object is non-const with copy-on-write semantics, the range-based for loop may trigger changes to it by (implicitly) calling the non-const begin().
To avoid that , if loop is not actually modifying the object, `std::as_const` can be used.

**Note**: Beware of temporaries in range expression, see [here](https://en.cppreference.com/w/cpp/language/range-for) or [C++20 improvement with initializers](cpp20.md#initializer-in-range-based-for-loop).


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

**Caution** when a lambda captures a member using implicit by-copy capture, it does not make a copy of that member variable (it captures _this_ and access memeber by reference using _this_). Capture by value has been added in later standard.

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

Constructors are allowed to call other peer constructors (constructor delegation):
```cpp
class SomeType
{
    int number;
public:
    SomeType(int new_number) : number(new_number) {}
    SomeType() : SomeType(42) {}
};
```

**Warning**:  An object is constructed once _any_ constructor finishes execution. This means that:
- when other constructor is invoked one cannot initialize other members anymore (since they were already initialized by other constructor)
- delegating constructor will be executing on a fully constructed object. 

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

Enumeration that are **type-safe**, **are not** introduced into enclosing scope and **cannot** be implicitly converted to integers are defined as:

```cpp
enum class Gender : unsigned short {
	Male,
	Female,
	Neutral
};
```
Type can be omitted and defaults to `int`. Old style enums can also specify underlying type.

**Note:** since type of enum is known in advance they can be used in forward declarations (unlike "ordinary" enums prior to C++11, now they can be if their type is specified in forward declaration).

**Note:** due to difference in scope rules between new and old enums, old are often called **unscoped enum** and new **scoped enum** or **enum class**.

### Right angle bracket

Multiple right angle brackets will be interpreted as closing the template argument list where it is reasonable. This can be overridden by using parentheses around parameter expressions using the “`>`”, “`>=`” or “`>>`” binary operators.

### Explicit conversion operators

The `explicit` keyword can now be applied to conversion operators. It prevents using those conversion functions in implicit conversions. 
**Note**: Language contexts that specifically need a boolean value (the conditions of if-statements and loops, and operands to the logical operators) count as explicit conversions!

```cpp
struct Testable
{
    operator bool() const {
        return false;
    }
};
 
struct ExplicitTestable
{
    explicit operator bool() const {
        return false;
    }
};
    
int main()
{
    {
        Testable a, b;
        if (a) { /*do something*/ }
        if (a == b) { /*do something*/ }  // might not be really intended usage but works
        if (a < b) { /*do something*/ }  // might not be  intended usage but works
    }
 
 
    {
        ExplicitTestable a, b;
        if (a) { /*do something*/ }  // this is correct
        if (a == b) { /*do something*/ }  // compiler error
        if (a == b) { /*do something*/ }  // compiler error
        if (a < b) { /*do something*/ }  // compiler error
    }
}
```

### Template aliases

It is now possible to create a `typedef` with template parameters as well as use `using` as type aliasing, like:

```cpp
template <typename First, typename Second, int Third> class SomeType;
template <typename Second> using TypedefName = SomeType<OtherType, Second, 5>;

typedef void(*FunctionType)(double); // Old style 
using FunctionType = void(*)(double); // New introduced syntax
```

### Unrestricted unions

If a `union` member has a non trivial (copy/move) constructor, destructor and/or copy/move assignment operator, the compiler will not generate the equivalent member function for the `union` and it must be manually defined.

```cpp
#include <new> // Needed for placement 'new'.

struct Point
{
    Point() {}
    Point(int x, int y): x_(x), y_(y) {} 
    int x_, y_;
};

union U
{
    int z;
    double w;
    Point p; // Invalid in C++03; valid in C++11.
    U() {} // Due to the Point member, a constructor definition is now needed.
    U(const Point& pt) : p(pt) {} // Construct Point object using initializer list.
    U& operator=(const Point& pt) { new(&p) Point(pt); return *this; } // Assign Point object using placement 'new'.
};
```

### Variadic templates

Allows template definitions to take an arbitrary number of arguments of any type.

```cpp
template<typename... Values> class tuple               // takes zero or more arguments
{
	tuple(Values... values);
}
```

Variadic templates may also apply to functions.

The ellipsis (...) operator has two roles. 
- to the left of the name of a parameter, it declares a parameter pack, user can bind zero or more arguments to the variadic template parameters.
- to the right of a template or function call argument, it unpacks the parameter packs into separate arguments (usage is restricted to certain [contexts](https://en.cppreference.com/w/cpp/language/parameter_pack)!!!). 

In other words example above reads:

```cpp
template<typename Value1, typename Value2, ..., typename Valuen> class tuple               // takes zero or more arguments
{
	tuple(Value1 v1, Value2 v2, ..., Valuen vn);
}
```

The variadic parameters themselves are not readily available to the implementation of a function or class. To make use of them either recursion or a dummy function/struct must be used.

Recursive case:

```cpp
func() {} // recursion termination

template<typename Arg1, typename... Args>
void func(const Arg1& arg1, const Args&&... args)
{
    process(arg1); //do something with arg1
    func(args...); // note: arg1 does not appear here!
}
```

Dummy function/struct used:

```cpp

template<typename... Args> inline void dummy(Args&&...) {}
template<typename... Args> inline void expand(Args&&... args)
{  pass(doSomethingWithReturn(args)...); // requires non void return, order of evaluation not guaranteed
}
 
struct  dummyStruct
{
  	template<typename ...T> dummyStruct(T...) {}  };
template<typename... Args> inline void expandStruct(Args&&... args)
{
	dummyStruct{ doSomethingWithReturn(args)... }; // requires non void return, order of evaluation guaranteed
}
template<typename... Args> inline void expandStruct2(Args&&... args)
{
	dummyStruct{ (doSomething(args), 1)... }; // non void return done via comma operator, order of evaluation guaranteed
}
template<typename... Args> inline void expandStruct3(Args&&... args)
{
	dummyStruct{ ([&]() { std::cout << args << std::endl; }(), 1)... }; // lamda used instead of separate function
}
template<typename... Args> inline void expandStruct4(Args&&... args)
{
	dummyStruct{ (std::cout << args << std::endl, 1)... }; // expression used instead of separate function
}
```

Creating `std::initializer_list` can be used instead of dummy struct, found [here](https://florianjw.de/en/variadic_templates.html).

Variadic templates can also be used in an exception specification, a base class list, or the initialization list of a constructor. For example, a class can specify the following:

```cpp
template <typename... BaseClasses>
class ClassName : public BaseClasses...
{
public:
    ClassName (BaseClasses&&... base_classes)
        : BaseClasses(base_classes)...
    {}
};
```

When combined with universal references we get perfect forwarding:

```cpp
template<typename TypeToConstruct>
struct SharedPtrAllocator
{
    template<typename ...Args>
    std::shared_ptr<TypeToConstruct> construct_with_shared_ptr(Args&&... params)
    {
        return std::shared_ptr<TypeToConstruct>(new TypeToConstruct(std::forward<Args>(params)...));
    }
};
```

Additionally, the number of arguments in a template parameter pack can be determined as follows:

```cpp
template<typename ...Args>
struct SomeStruct
{
    static const int size = sizeof...(Args);
};
```

The expression `SomeStruct<Type1, Type2>::size` will yield 2, while `SomeStruct<>::size` will give 0.

Some examples of usages of variadic template can be found [here](https://eli.thegreenplace.net/2014/variadic-templates-in-c/) and in [Variadic.cpp](Variadic.cpp) example.

### New string literals

Type `char` is at least eight-bit , two new character types: `char16_t` and `char32_t` are added (16 and 32 bit). 

All user-defined literals are suffixes. All user-defined literals must have suffixes starting with an underscore (`_`).

News string literals added:

```cpp
u8"This is a Unicode Character: \u2018."; // const char[]
u"This is a bigger Unicode Character: \u2018."; // const char16_t[]
U"This is a Unicode Character: \U00002018."; // const char32_t[]
```

To to avoid escaping strings there is raw string literal:


```cpp
R"(The String Data \ Stuff " )";
R"delimiter(The String Data ()\ Stuff " )delimiter";
```

Everything between the `"(` and the `)"` is part of the string. No need to escape anything.

Raw string literals can be combined with the wide literal or any of the Unicode literal prefixes:


```cpp
u8R"XXX(I'm a "raw UTF-8" string.)XXX"
uR"*(This is a "raw UTF-16" string.)*"
UR"(This is a "raw UTF-32" string.)"
```

### User-defined literals

Enables defining new kinds of literal modifiers that will construct objects based on the string of characters that the literal modifies.

For integer and float literals we have:

```cpp
OutputType operator "" _mysuffix(const char * literal_string);

OutputType some_variable = 1234_mysuffix;

template<char...> OutputType operator "" _tuffix();

OutputType some_variable = 1234_tuffix;
OutputType another_variable = 2.17_tuffix;


OutputType  operator  ""  _suffix(unsigned  long  long);  
OutputType  operator  ""  _suffix(long  double);

OutputType  some_variable  =  1234_suffix;  // Uses the 'unsigned long long' overload.  
OutputType  another_variable  =  3.1416_suffix;  // Uses the 'long double' overload.
```

For string literals we have following operators:

```cpp
OutputType  operator  ""  _ssuffix(const  char  *  string_values,  size_t  num_chars);  
OutputType  operator  ""  _ssuffix(const  wchar_t  *  string_values,  size_t  num_chars);
OutputType  operator  ""  _ssuffix(const  char16_t  *  string_values,  size_t  num_chars);  
OutputType  operator  ""  _ssuffix(const  char32_t  *  string_values,  size_t  num_chars);  
OutputType  some_variable  =  "1234"_ssuffix;  // Uses the 'const char *' overload.  
OutputType  some_variable  =  u8"1234"_ssuffix;  // Uses the 'const char *' overload.  
OutputType  some_variable  =  L"1234"_ssuffix;  // Uses the 'const wchar_t *' overload.  
OutputType  some_variable  =  u"1234"_ssuffix;  // Uses the 'const char16_t *' overload.  
OutputType  some_variable  =  U"1234"_ssuffix;  // Uses the 'const char32_t *' overload.
```

```cpp
#include <iostream>
#include <algorithm>
#include <string>

unsigned long long operator "" _x4(unsigned long long value) {
	return value * 4;
};

std::string operator "" _upper(const char* value, size_t) {
	std::string str = value;
	for (auto& c : str) c = toupper(c);
	return str;
}

int main() {
	std::cout << 10_x4 << std::endl; // outputs 40
	std::cout << "Hello World"_upper << std::endl; // outputs HELLO WORLD
}
```

More verbose explanation of user-defined literals can be found [here](https://akrzemi1.wordpress.com/2012/08/12/user-defined-literals-part-i/),  [here](https://akrzemi1.wordpress.com/2012/10/23/user-defined-literals-part-ii/) and  [here](https://akrzemi1.wordpress.com/2012/10/29/user-defined-literals-part-iii/).

One nice example of user defined roman number literals can be found (here)[https://github.com/tcbrindle/numeris_romanis].

### Multithreading memory model

Read more [here](https://en.cppreference.com/w/cpp/language/memory_model) and [here](http://www.modernescpp.com/index.php/c-memory-model).

### Thread-local storage

A new Thread-Local Storage storage duration (in addition to the existing _static_, _dynamic_ and _automatic_) is indicated by the storage specifier `thread_local`.

```cpp
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
 
thread_local unsigned int rage = 1;
std::mutex cout_mutex;
 
void increase_rage(const std::string& thread_name)
{
	++rage; // modifying outside a lock is okay; this is a thread-local variable
	std::lock_guard<std::mutex> lock(cout_mutex);
	std::cout << "Rage counter for " << thread_name << ": " << rage << '\n';
}
 
int main()
{
	std::thread a(increase_rage, "a"), b(increase_rage, "b");
 
	{
		std::lock_guard<std::mutex> lock(cout_mutex);
		std::cout << "Rage counter for main: " << rage << '\n';
	}
 
	a.join();
	b.join();
}
```

### Explicitly defaulted and deleted special member functions

Explicit defaulting and deleting of special member functions, for example, this type is non-copyable:

```cpp
struct NonCopyable
{
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};
```

The `= delete` specifier can be used to prohibit calling any function (**Non member functions can also be deleted!**). For example:

```cpp

#include <iostream>

struct NoInt
{
	void f(double i) {};
	void f(int) = delete;
};

struct OnlyInt
{
	void ff(int d) {};
	template<class T> void ff(T) = delete;
};

int main() {
	NoInt noInt;
	noInt.f(1.0);
	noInt.f(1); // error here, would not be if f(int) wasn't deleted due to implicit conversion to double

	OnlyInt onlyInt;
	onlyInt.ff(1);
	onlyInt.ff(1.0); // error here, would not be if ff(T) wasn't deleted due to implicit conversion to int (with warning)
}
```

**Usually best to make deleted functions public because it will make compiler emit better error message.** If private compiler would error because inaccessible method is invoked and not mention it is actually deleted.

**Deleted functions are taken into account during overload resoultion.**

###  Type long long int

It is guaranteed to be at least as large as a `long int`, and have no fewer than 64 bits.

### Static assertions

A new way to test assertions at compile-time, using the new keyword `static_assert`. The declaration assumes this form:

`static_assert (_constant-expression_, _error-message_);`

Here are some examples of how `static_assert` can be used:

`static_assert((GREEKPI > 3.14) && (GREEKPI < 3.15), "GREEKPI is inaccurate!");`

```cpp
template<class T>
struct Check
{
    static_assert(sizeof(int) <= sizeof(T), "T is not big enough!");
};

template<class Integral>
Integral foo(Integral x, Integral y)
{
    static_assert(std::is_integral<Integral>::value, "foo() parameter must be an integral type.");
}
```

### Allow sizeof to work on members of classes without an explicit object

```cpp
struct  SomeType  {  OtherType  member;  };  
sizeof(SomeType::member);  // Does not work with C++03. Okay with C++11
```

### Control and query object alignment

Variable alignment can be queried and controlled with `alignof` and `alignas`.

### Allow garbage collected implementations

Defines conditions under which pointer values are "safely derived" from other values. An implementation may specify that it operates under _strict pointer safety_, in which case pointers that are not derived according to these rules can become invalid.

More [here](http://www.cplusplus.com/reference/memory/pointer_safety/) and [here](http://www.cplusplus.com/reference/memory/).

### Attributes

Standardized syntax for compiler/tool extensions to the language, added information can be specified in a form of an attribute enclosed in double square brackets.

More, including standard attributes can be found [here](https://en.cppreference.com/w/cpp/language/attributes).

## C++ standard library changes

### Threading facilities

A lot of info with examples [here](https://en.cppreference.com/w/cpp/thread).

#### Thread class

A thread class `std::thread` is provided, which takes a function object (with optional arguments) to run in the new thread. 

**Note:** `std::thread` must be joined or detached before the destructor, otherwise `std::terminate` is invoked. ()

```cpp
#include <iostream>
#include <thread>
#include <chrono>

void f1()
{
	std::cout << "Thread\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
}

int main() {
	std::thread t1(f1);  // starts a new thread on f1 function
	std::cout << "Main\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
	t1.join();   // without this call, thread destructor will std::terminate
	std::cout << "All done\n";
}
```

#### Mutexes, locks and condition variables

For synchronization between threads there are `std::mutex`, `std::recursive_mutex`, `std::shared_mutex` (along with "timed" versions which try locking for specified amount of time). 

In addition condition variables `std::condition_variable` and `std::condition_variable_any` are available. Although possible **don't** wait without a condition, explanation [here](http://www.modernescpp.com/index.php/c-core-guidelines-be-aware-of-the-traps-of-condition-variables).

Usable either directly or via RAII locks `std::lock_guard`, `std::scoped_lock` (C++17), `std::unique_lock` and `std::shared_lock` (C++14). In addition `std::lock` and `std::try_lock` are available for locking multiple objects.

There is also `std::call_once` helper for invoking function only once.

One code example is in [Philosophers.cpp](Philosophers.cpp).

#### Futures and promises

Future (`std::future`, `std::shared_future`) and promise (`std::promis`) for passing asynchronous results between threads, and `std::packaged_task` for wrapping up a function call that can generate such an asynchronous result is also introduced. 

`std::async` facility provides a convenient method of running tasks and tying them to a `std::future`. Some info and problems about `std::async` [here](https://eli.thegreenplace.net/2016/the-promises-and-challenges-of-stdasync-task-based-parallelism-in-c11/).

```cpp
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int main() {
	// future from a packaged_task
	std::packaged_task<int(int)> task([] (int arg) { 
		std::this_thread::sleep_for(std::chrono::seconds(10));
		return arg;
	}); // wrap the function
	std::future<int> f1 = task.get_future();  // get a future
	std::thread t(std::move(task), 10); // launch on a thread

	std::cout << "Waiting..." << std::flush;
	f1.wait(); // if we skip waiting here f1.get() will wait
	std::cout << "Done!\nResult is: " << f1.get() << '\n';

	t.join();

	// future from an async()
	std::future<int> f2 = std::async(std::launch::async, [] (int arg) { 
		std::this_thread::sleep_for(std::chrono::seconds(5));
		return arg;
	}, 20);
	std::cout << "Waiting..." << std::flush;
	f2.wait();// if we skip waiting here f2.get() will wait
	std::cout << "Done!\nResult is: " << f2.get() << '\n';

	// future from a promise
	std::promise<int> p;
	std::future<int> f3 = p.get_future();
	std::thread([&p] { 
		std::this_thread::sleep_for(std::chrono::seconds(7));
		p.set_value_at_thread_exit(30);
	}).detach(); // no need for join here

	std::cout << "Waiting..." << std::flush;
	f3.wait();// if we skip waiting here f3.get() will wait
	std::cout << "Done!\nResults is: " << f3.get() << '\n';
}

```

#### Atomic variables

For programming without locks one can use `std::atomic` variables. 

Any trivally copiable type can be used as `std::atomic` and provides following:
- Assignment and copy (read and write) for all types (built-in and user-defined)
- Increment and decrement for raw pointers
- Addition, subtraction, and bitwise logic operations for integers (++, +=, –, -=, |=, &=, ^=), **no multiplication**
  - `std::atomic<bool>` is valid, no special operations!!!
  - `std::atomic<double>` is valid, no special operations!!! **No atomic increment for floating-point numbers!!!!**
- `atomic_store` and `atomic_store_explicit` provide atomic store, latter with memory order specified
- `atomic_load` and `atomic_load_explicit` provide atomic load, latter with memory order specified
- `atomic_fetch_*` operations (add, sub, and, or, xor) (e.g `atomic_fetch_add`) provide operation on an atomic object (with non atomic argument) 
and return previous value, explicit variations (e.g `atomic_fetch_add_explicit`) with memory order specified
- `atomic_exchange`  and `atomic_exchange_explicit`  operation on an atomic object (with non atomic argument) and return previous value, explicit 
variations (e.g `atomic_fetch_add_explicit`) with memory order specified
- `atomic_compare_exchange_strong` and `atomic_compare_exchange_weak` atomically compares the object with expected value and if equal sets it 
to desired value, if not equal loads current value into desired, explicit variations with memory order specified (2 of them one for store, other for load!!!), weak forms is allowed to fail 
spuriously (act as if desired and expected are not equal even when they are equal)

**Note:** C++20 adds `std::atomic_ref` for atomic operations on non atomic types.

```cpp
// atomic multiply with compare_and_exchange, atomic increment for floats could be done in similar fashion
std::atomic<int> x{0};
int x0 = x;
while ( !x.compare_exchange_strong(x0, x0*2) ) {}
```

See more examples of lock free operations using atomic variables [here](https://en.cppreference.com/w/cpp/atomic).

**Note:** Expressions with atomics are not computed atomically, `x = x + 1` is not atomic, on the level of the whole operation, although x is atomic! `x++` is same as `x += 1` but not the same as `x = x + 1` when x is atomic!

```cpp
	std::atomic<int> x(0);
	{
		auto inc = [&x]() {
			for (int i = 0; i < 1000000; ++i)
				x = x + 1;  // atomic read followed by atomic write, no atomicity of whole operation!!!!
		};
		std::thread thr1(inc);
		std::thread thr2(inc);
		thr1.join();
		thr2.join();
		std::cout << x << std::endl; // probably outputs something less than 2000000
	}

	x = 0;

	{
		auto inc = [&x]() {
			for (int i = 0; i < 1000000; ++i) {
				x += 1; // true atomic increment
			}
		};
		std::thread thr1(inc);
		std::thread thr2(inc);
		thr1.join();
		thr2.join();
		std::cout << x << std::endl; // outputs 2000000
	}
```

**Note:** to avoid such errors that can happen with usage of overloaded operators, and make atomic operations more explicit,it is advised to use atomic member functions directly (a bit more verbose)

**Note:** using `std::atomic` isn't always lock free, use `std::atomic::is_lock_free()` to check. Lock free can also depend on alignment and padding :(!!!

**Note:** atomic operations might wait on each other due to need to wait for memory cache, in high performance system need to carefully align data accessed!!!

#### Memory orders/barriers

Control how changes to variables/memory done in one thread become visible to other threads (control what can processor reorder in order to optimize code). 
Implemented by hardware and closely related to memory order (they ensure memory order).

`std::memory_order`:
- `memory_order_relaxed` - no synchronization or ordering constraints, only atomicity guaranteed
- `memory_order_consume` - reads and writes of same variable cannot be reordered in any direction
- `memory_order_acquire` - all reads and writes cannot be reordered from after to before the barrier
- `memory_order_release` - all reads and writes cannot be reordered from before to after the barrier
- `memory_order_acq_rel` - combination of `memory_order_acquire` and `memory_order_release`, no reordering in any direction
- `memory_order_seq_cst` - all of above plus a single total order exists in which **all threads** observe all modifications in the same order (default!!!)

**Note:** `memory_order_acquire` and `memory_order_release` are usually used together. Thread that sets(prepares) data uses `memory_order_release` and thread that reads(uses) data uses `memory_order_acquire`.

```cpp
class AtomicLock {
public:
	void lock() {
		while (true) {
			bool expected = UNLOCKED; // we exchange only if unlocked
			if (atomicLock.compare_exchange_weak(expected, LOCKED, lockOrder))
				break;
		}
	}

	void unlock() {
		atomicLock.store(0, std::memory_order_release);
	}

	bool try_lock() {
		bool expected = UNLOCKED; // we exchange only if unlocked
		return atomicLock.compare_exchange_strong(expected, LOCKED, lockOrder);
	}
private:
	const static bool UNLOCKED = false;
	const static bool LOCKED = true;

	std::atomic<bool> atomicLock = UNLOCKED;
};
```
 

### Tuple types

Tuples are collections composed of heterogeneous objects of pre-arranged dimensions. 

```cpp
typedef std::tuple <int, double, long &, const char *> test_tuple;
long lengthy = 12;
test_tuple proof (18, 6.5, lengthy, "Ciao!");

lengthy = std::get<0>(proof);  // Assign to 'lengthy' the value 18.
std::get<3>(proof) = " Beautiful!";  // Modify the tuple’s fourth element.
```

`std::make_tuple` automatically creates `std::tuple`s using type deduction. `std::tie` creates tuples of lvalue references to help unpack tuples. `std::ignore` also helps here. 

```cpp
auto record = std::make_tuple("Hari Ram", "New Delhi", 3.5, 'A');
std::string name ; float gpa ; char grade ;
std::tie(name, std::ignore, gpa, grade) = record ; // std::ignore helps drop the place name
std::cout << name << ' ' << gpa << ' ' << grade << std::endl ;
```

Expressions are available to check a tuple’s characteristics (only during compilation):

-   `std::tuple_size<T>::value` returns the number of elements in the tuple `T`,
-   `std::tuple_element<I, T>::type` returns the type of the object number `I` of the tuple `T`.

Relation operations as well as assignment between tuples is possible provided they have same number of elements and corresponding element types can be assigned/compared.

### Containers

`std::unordered_set`, `std::unordered_multiset`, `std::unordered_map` and `std::unordered_multimap` are introduced as counterparts for existing ordered containers.

`std::array` is a safe counterpart of C-style array.

`std::forward_list` is single linked list (unlike `std::list` which is double linked).

See more [here](https://en.cppreference.com/w/cpp/container).

### Regular expressions

Regular expression support is based on template class `std::basic_regex`, template class `std::match_results`, functions `std::regex_search`, and `std::regex_match` and  function `std::regex_replace`.

See more [here](https://en.cppreference.com/w/cpp/regex).

```cpp
std::string s = "Some people, when confronted with a problem, think "
	"\"I know, I'll use regular expressions.\" "
	"Now they have two problems.";
 
std::regex self_regex("REGULAR EXPRESSIONS",
	std::regex_constants::ECMAScript | std::regex_constants::icase);
if (std::regex_search(s, self_regex)) {
	std::cout << "Text contains the phrase 'regular expressions'\n";
}
 
std::regex word_regex("(\\S+)");
auto words_begin =
	std::sregex_iterator(s.begin(), s.end(), word_regex);
auto words_end = std::sregex_iterator();
 
std::cout << "Found "
	<< std::distance(words_begin, words_end)
	<< " words\n";
 
const int N = 6;
std::cout << "Words longer than " << N << " characters:\n";
for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
	std::smatch match = *i;
	std::string match_str = match.str();
	if (match_str.size() > N) {
		std::cout << "  " << match_str << '\n';
	}
}
 
std::regex long_word_regex("(\\w{7,})");
std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
std::cout << new_s << '\n';
```

### General-purpose smart pointers

Provides `std::unique_ptr`,  `std::shared_ptr` and `std::weak_ptr`. `std::auto_ptr` is deprecated.

A `unique_ptr` is a container for a raw pointer, which the `unique_ptr` is said to own. A `unique_ptr` cannot be copied because its copy constructor and 
assignment operators are explicitly deleted. Hence it is used in cases of "exclusive ownership". Unless complex deleter functions are used its size is equal to size of raw pointer.

**Note:** there is `unique_ptr<T[]>` for arrays (doesn't have `*` and `->` operators but has `[]`), however should not be used, use `std::array` or `std::vector` instead.

A `shared_ptr` is a container for a raw pointer. It maintains reference counting ownership of its contained pointer in cooperation with all copies of the `shared_ptr`. 
An object referenced by the contained raw pointer will be destroyed when and only when all copies of the `shared_ptr` have been destroyed. Hence it is used in cases of "shared ownership".

**Note:** Due to functionality they provide (and reference counting they use) shared pointers have both space (use more memory than raw pointers) and 
performance (atomic counter increase/decrease) impact! Since moving doesn't change reference count, moving shared pointer does not incur performance impact copying does!

**Note:** `unique_ptr` can be converted to `shared_ptr`, so if you don't know how others will use the pointer you return, feel free to return unique ones and caller can convert to shared if needed!

**Note:** to avoid possibility of having single memory "handled" by two or more shared pointers, avoid creating shared pointer from raw pointer variable!

A `weak_ptr` is a container for a raw pointer. It is created as a copy of a `shared_ptr`. The existence or destruction of `weak_ptr` copies of a 
`shared_ptr` have no effect on the `shared_ptr` or its other copies. After all copies of a `shared_ptr` have been destroyed, all `weak_ptr` copies become empty.
It is like a `shared_ptr` that can dangle (safely).

`std::make_shared` (C++17) and `std::make_unique` (C++14) can be used to create smart pointers and should be preferred to using new directly as argument to smart pointer constructor 
(exception safety, more efficient code (single memory allocation instead of two), .....). 
Some edge cases exist when using them is not preferred or possible (custom memory management, large objects, weak pointers that outlive shared ones), refer to numerous 
internet resources for more info, including Item 21 of Effective Modern C++.

**Note:** `std::make_shared` and `std::make_unique` use direct-initializing but not direct-list-initializing, 
meaning constructor is invoked using parenths and not braces (for difference see [Uniform initialization](cpp11.md#uniform-initialization)).

In addition `std::enable_shared_from_this` must be used if trying to create shared pointer from *this*. **Note:** in order for this to work there must be existing shared pointer, so usually done
by making constructors private and having factory function returning shared pointer(s)!

```cpp
	std::shared_ptr<int> p1 = std::make_shared<int>(5);
	std::weak_ptr<int> wp1{ p1 }; //p1 owns the memory.
 
	{
		std::shared_ptr<int> p2 = wp1.lock(); //Now p1 and p2 own the memory.
											  // p2 is initialized from a weak pointer, so 
											  // you have to check if the memory still exists!
		if (p2) {
			do_something_with(p2);
		}
	}
	//p2 is destroyed. Memory is owned by p1.
 
	p1.reset(); // Delete the memory.
 
	std::shared_ptr<int> p3 = wp1.lock();
	//Memory is gone, so we get an empty shared_ptr.
	if (p3) { // code will not execute
		action_that_needs_a_live_pointer(p3);
	}
```
See more [here](https://en.cppreference.com/w/cpp/memory).

And [here](https://www.modernescpp.com/index.php/atomic-smart-pointers) if you are concerned about thread safety.

**Note:** by default `delete` (or `delete[]`) is used to free memory pointed to by smart pointers but for advanced usages this can be overriden by custom deleter (lambda) functions.

### Extensible random number facility

Random number functionality is split into two parts: a generator engine that contains the random number generator's state and produces the pseudorandom numbers; and a distribution, which determines the range and mathematical distribution of the outcome. 

See more [here](https://en.cppreference.com/w/cpp/numeric/random).

### Time manipulation

Clocks (time providers), time points (how much time has passed since the start of the clock) and duration. Type safe manipulation of time.

Some added in C++11, more in C++14 and C++20. See more [here](https://en.cppreference.com/w/cpp/chrono).

### Rational arithmetics 

`std::ratio` template and various methods that provide compile-time rational arithmetic support.

```cpp
    typedef std::ratio<2, 3> two_third;
    typedef std::ratio<1, 6> one_sixth;
 
    typedef std::ratio_add<two_third, one_sixth> sum;
    std::cout << "2/3 + 1/6 = " << sum::num << '/' << sum::den << '\n';
```

More can be found [here](https://en.cppreference.com/w/cpp/numeric/ratio).

### Wrapper reference

To obtain a wrapper reference from any object the function template `ref` is used (for a constant reference `cref` is used). Useful for function templates, where references to parameters rather than copies are needed:

```cpp
// This function will obtain a reference to the parameter 'r' and increment it.
void func (int &r)  { r++; }

// Template function.
template<class F, class P> void g (F f, P t)  { f(t); }

int main()
{
    int i = 0;
    g (func, i); // 'g<void (int &r), int>' is instantiated
                 // then 'i' will not be modified.
    std::cout << i << std::endl; // Output -> 0

    g (func, std::ref(i)); // 'g<void(int &r),reference_wrapper<int>>' is instantiated
                           // then 'i' will be modified.
    std::cout << i << std::endl; // Output -> 1
}
```

### Polymorphic wrappers for function objects

The template class `std::function` is defined as a wrapper holder for function pointers, member function pointers, or functors. `std::mem_fn` wrapper for pointers to members. `std::bind` can be used to bind one or more arguments.

See more [here](https://en.cppreference.com/w/cpp/utility/functional).

### Type traits for metaprogramming

_Type traits_ can identify the category of an object and all the characteristics of a class (or of a struct). They are defined in the new header `<type_traits>`. 

For example determining, at compile time, if type is and array, class or if it is scalar, or object.

See more [here](https://en.cppreference.com/w/cpp/header/type_traits).



### Uniform method for computing the return type of function objects

Template class `std::result_of` that allows one to determine and use the return type of a function object for every declaration.

### New C++ Algorithms

New algorithms that mimic the set theory operations `all_of()`, `any_of()` and `none_of()`. More [here](https://en.cppreference.com/w/cpp/algorithm/all_any_none_of).

`find_if_not()` counterpart of `find_if()` has been added.


A new category of `copy_n` and `copy_if` algorithms is also available.

A new category of `move` and `move_backward` algorithms is also available for moving from/to containers.

Partitioning operations `is_partitioned`, `partition_copy` and `partition_point` are added.

Sorting operations `is_sorted` and  `is_sorted_until` are added as well as heap ones `is_heap` and  `is_heap_until`, in addition to `is_permutation`.

`minmax` and `minmax_element` are introduced.

The algorithm `iota()` creates a range of sequentially increasing values, as if by assigning an initial value to `*first`, then incrementing that value using prefix ++.

More can be found [here](https://en.cppreference.com/w/cpp/algorithm).

### std::string conversion enhancements

- `std::stoi` - convert string to integer
- `std::stol` - convert string to long int
- `std::stoul` - convert string to unsigned integer 
- `std::stoll` - convert string to long long
- `std::stoull` - convert string to unsigned long long
- `std::stof` - convert string to float 
- `std::stod` - convert string to double 
- `std::stold` - convert string to long double
- `std::to_string` - convert numerical value to string
- `std::to_wstring` - convert numerical value to wide string

### Copying and rethrowing exceptions

`exception_ptr current_exception();` and `void rethrow_exception(exception_ptr p);` can be used to copy exception and rethrow it at some other place.

More [here] (https://en.cppreference.com/w/cpp/error).

## Features removed or deprecated

Dynamic exception specifications are deprecated (removed in C++17). Compile-time specification of non-exception-throwing functions is available with the [`noexcept`](https://en.cppreference.com/w/cpp/language/noexcept_spec) keyword (useful for optimization).

**A destructor shouldn't throw**, [reason here](https://www.acodersjourney.com/top-15-c-exception-handling-mistakes-avoid/) , and compilers make destructors by default `noexcept(true)`!!! That means it will std::terminate if some code invoked inside destructor throws.

Compiler will make destructors implicitely `noexcept(false)` only if:
- destructor code directly invokes another function that is noexcept(false)
- directly invokes `throw`
- has member that has `noexcept(false)` destructor

In all other cases (throw hidden somewhere deep inside function without noexcept specification) programmer needs to explicitly 
make destructor `noexcept(false)` (or handle the exception and not let it propagate).

```cpp
#include <iostream>

class A {
public:
	~A() {
		justThrow();
	};
private:
	void justThrow() {
		throw 1;
	};
};

int main() {
	try {
		A a; // following crashes using std::terminate due to exception in destructor
	}
	catch (...) {
		std::cout << "Exception caught" << std::endl;
	}
}
```
**This behavior is backward incompatible**, for more see [here](https://akrzemi1.wordpress.com/2013/08/20/noexcept-destructors/).

It is typically a bad idea to have a move operation throw, so declare those **noexcept** wherever possible. A generated copy or move operation 
is implicitly **noexcept** if all of the copy or move operations it uses on members of its class have **noexcept** destructors.

Various STL algorithms behave better (more optimized) if your class has **noexcept** move constructor.

**Note:** always use **noexcept** if it makes sense because it allows compiler to kick in more optimizations.

## Some of the references

- [C++ 11 Wiki](https://en.wikipedia.org/wiki/C%2B%2B11)
- [C++ 11 Language extensions](https://isocpp.org/wiki/faq/cpp11-language)
- [C++ 11 Library extensions](https://isocpp.org/wiki/faq/cpp11-library)
- [Move constructor](https://en.cppreference.com/w/cpp/language/move_constructor)
- [Move assignment](https://en.cppreference.com/w/cpp/language/move_assignment)
- [Value categories](https://en.cppreference.com/w/cpp/language/value_category)
- [RValue references](https://docs.microsoft.com/en-us/cpp/cpp/rvalue-reference-declarator-amp-amp?view=vs-2019).
- [Lambda expressions](https://en.cppreference.com/w/cpp/language/lambda)
- [User-defined literals](https://en.cppreference.com/w/cpp/language/user_literal)
- [Compiler explorer](https://godbolt.org/)
- [Interactive C/C++ memory model](http://svr-pes20-cppmem.cl.cam.ac.uk/cppmem/)
- [Modernes C++](http://www.modernescpp.com/index.php)
- [Modern C++ features](https://github.com/AnthonyCalandra/modern-cpp-features)
- [IDE One](http://www.ideone.com/)
- [C++ Atomics, From Basic to Advanced by Fedor Pikus](https://github.com/CppCon/CppCon2017/tree/master/Presentations/C%2B%2B%20Atomics%2C%20From%20Basic%20to%20Advanced)
- [Effective Modern C++](https://www.oreilly.com/library/view/effective-modern-c/9781491908419/)
