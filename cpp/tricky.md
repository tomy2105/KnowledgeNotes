# Not so obvious C++

<!-- toc -->

- [Type of int[] function parameter](#type-of-int-function-parameter)
- [Reference collapsing rule](#reference-collapsing-rule)
- [Type deduction rules for rvalue references](#type-deduction-rules-for-rvalue-references)
- [Mandatory virtual destructor](#mandatory-virtual-destructor)
- [Explicit single argument constructors](#explicit-single-argument-constructors)
- [Use iosfwd](#use-iosfwd)
- [Include order](#include-order)
- [Empty character](#empty-character)
- [Exception objects must be nothrow copy constructible](#exception-objects-must-be-nothrow-copy-constructible)
- [Invoking virtual functions from base class constructor/destructor](#invoking-virtual-functions-from-base-class-constructordestructor)
- [Creation of default special functions](#creation-of-default-special-functions)

<!-- tocstop -->

## Type of int[] function parameter

Having `int a[100]`, with or without size specified, as a function parameter is identical to having `int* a` due to ancient history C compatibility.

Meaning that you cannot `for (int i: a) {}` on such parameter, you will get _no callable 'begin' function found for type 'int []'_ error (and one for _'end'_ too).

In order to have really array as function parameter you need some template magic.

```cpp
#include <iostream>
 
void f(int a[100]) 
{
	std::cout << typeid(a).name() << std::endl;
//	for (int i: a) {} // does not work here
}
 
template <typename T, size_t N>
void ff(T (&arr)[N])
{
	std::cout << typeid(arr).name() << std::endl;
	for (auto i: arr) {} // works here
}
 
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	std::cout << typeid(a).name() << std::endl;  // output int [6]
	f(a); // outputs int *
	ff(a); // outputs int [6]
 
	return 0;
}
```

## Reference collapsing rule

What is the type ok `k`? What does `int & &` colapse to?
```cpp
template <typename T>
void baz(T t) {
  T& k = t;
}
int ii = 4;
baz<int&>(ii);
baz<int&&>(ii);
```

The _reference collapsing_ rule. `&` always wins. So `& &` is `&`, and so are `&& &` and `& &&`. The only case where `&&` emerges from collapsing is `&& &&`.

## Type deduction rules for rvalue references

```cpp
template <class T>
void func(T&& t) {
}

func(4);            // 4 is an rvalue: T deduced to int

double d = 3.14;
func(d);            // d is an lvalue; T deduced to double&

float f() {...}
func(f());          // f() is an rvalue; T deduced to float

int bar(int i) {
  func(i);          // i is an lvalue; T deduced to int&
}
```
`T&&` t is not an rvalue reference here. When it appears in a type-deducing context, T&& acquires a special meaning. When func is instantiated, T depends on whether the argument passed to func is an lvalue or an rvalue. If it's an lvalue of type U, T is deduced to U&. If it's an rvalue, T is deduced to U.


## Mandatory virtual destructor
Any class that has any virtual methods, or is any other mean meant for polymorhic inheritance, **must** have virtual destructor. Otherwise it won't get cleaned up properly if destructed from base class pointer (only a base class destructor will be invoked since it is not virtual).

```cpp
class Base {
public:
	~Base() {
		std::cout << this << " ~Base()\r\n";
	}
};
 
class Child: public Base {
public:
	~Child() {
		std::cout << this << " ~Child()\r\n";
	}
};
 
int main() {
	Base* pBase = new Child();
	delete pBase; // only ~Base invoked here, no ~Child
}
```

## Explicit single argument constructors

Single arguments constructor are used in implicit conversions. Hence one should mark them **explicit** unless implicit conversion usage is intended.

```cpp
struct Foo {
	Foo(int i) {};
		static void doSomething(const Foo& foo) {};
};

int main() {
	Foo::doSomething(1); // implicit conversion here (is it intended or side-effect)?
}
```

Same, explicit, applies to conversion operator (C++11).

## Use iosfwd

Use `<iosfwd>` instead of the traditional stream headers ( `<iostream>` and friends ) so that you can avoid including the definition of the whole streaming stuff. With `<iosfwd>` you are only making a forward declaration of all the streaming stuff.

## Include order

Your headers should not be dependent upon other headers being included first. One way to insure this is to include your headers before any other headers (so any errors are detected by compiler and not hidden by what has been done in other headers).

Include in the following order:

1.  The prototype/interface header for this implementation (ie, the .h/.hh file that corresponds to this .cpp/.cc file).
2.  Other headers from the same project, as needed.
3.  Headers from other non-standard, non-system libraries (for example, Qt, Eigen, etc).
4.  Headers from other "almost-standard" libraries (for example, Boost)
5.  Standard C++ headers (for example, iostream, functional, etc.)
6.  Standard C headers (for example, cstdint, dirent.h, etc.)

## Empty character

There is **no** such thing!!! Although might be tempted to write `'\0'` this is not **empty** character, this is *nul* character (one character with 0 as value).

Hence if you output `'\0'` to file you will get one byte file with 0 value in it, whereas if you output `"\0"` to file you will get empty file (`"\0"` same as `"\0"` because `"something"` represents zero terminated character array so zero terminating it explicitly makes no visible difference).


## Exception objects must be nothrow copy constructible

When an exception is thrown, the exception object operand of the throw expression is **copied** into a temporary object that is used to initialize the handler. 
If the copy constructor for the exception object type throws during the copy initialization, std::terminate() is called, which can result in undefined behavior.

## Invoking virtual functions from base class constructor/destructor

Base type must be constructed previous to the Derived type. Problem is what does it mean to call a virtual method from the constructor of the Base type. 
C++ calls a method at the Base level, unlike Java which calls method on Derived level while Derived object is still not fully constructed.

Same issue is with destructors. To avoid calling virtual method on partially destructed object (Derived destructor is executed before Base one) C++ calls a method at the Base level.

_In other words, during the base classes constructor/destructor execution, the object is not of the derived type and thus the base type's implementation of the virtual function is invoked._

## Creation of default special functions

- **Default constructor** - generated if class has no other constructors and has base class and/or members (calls base class constructor, member default constructors, ...)
- **Destructor** - generated if have base class and/or members (calls base class destructor, member destructors, ...), virtual if base class destructor is virtual
- **Copy constructor** - generated if class lacks user defined copy constructor, deleted if move operation is declared, deprecated automatic generation if there is user copy assigment or user destructor 
- **Copy assignment operator** - generated if class lacks user defined copy assignment, deleted if move operation is declared, deprecated automatic generation if there is user copy constructor or user destructor 
- **Move constructor or move assignment operator** - generated only if no user copy and/or move operations and/or destructor

Although more verbose, it is sometimes better to explicitly create default versions (`= default`) so they stay defined even when class is changed in a way that would prevent implicit creation of those (e.g. adding user defined destructor is added for logging purposes).
