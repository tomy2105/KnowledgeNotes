# Not so obvious C++

<!-- toc -->

- [Type of int[] function parameter](#type-of-int-function-parameter)
- [Mandatory virtual destructor](#mandatory-virtual-destructor)
- [Explicit single argument constructors](#explicit-single-argument-constructors)
- [Use iosfwd](#use-iosfwd)
- [Include order](#include-order)
- [Empty character](#empty-character)
- [Exception objects must be nothrow copy constructible](#exception-objects-must-be-nothrow-copy-constructible)
- [Invoking virtual functions from base class constructor/destructor](#invoking-virtual-functions-from-base-class-constructordestructor)
- [Creation of default special functions](#creation-of-default-special-functions)
- [Reference collapsing rule](#reference-collapsing-rule)
- [Type deduction rules for rvalue references](#type-deduction-rules-for-rvalue-references)
- [Template type deduction](#template-type-deduction)
  * [`ParamType` is a pointer or reference type, but not a forwarding/universal reference](#paramtype-is-a-pointer-or-reference-type-but-not-a-forwardinguniversal-reference)
  * [`ParamType` is a forwarding/universal reference](#paramtype-is-a-forwardinguniversal-reference)
  * [`ParamType` is neither a pointer nor a reference](#paramtype-is-neither-a-pointer-nor-a-reference)
- [auto type deduction](#auto-type-deduction)
- [decltype type](#decltype-type)
- [type diagnostics](#type-diagnostics)
- [When is dectructor not invoked?](#when-is-dectructor-not-invoked)
- [public deleted functions](#public-deleted-functions)
- [Invoking base class method if base class is template](#invoking-base-class-method-if-base-class-is-template)
- [Some of the references](#some-of-the-references)

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

## Reference collapsing rule

What is the type of `k`? What does `int & &` colapse to?
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

`T&&` t is not an rvalue reference here. When it appears in a type-deducing context (T must be function template type, not class template type), T&& acquires a special meaning. 
When `func` is instantiated, T depends on whether the argument passed to func is an lvalue or an rvalue. 
If it's an lvalue of type U, T is deduced to U&. If it's an rvalue, T is deduced to U. This is often called forwarding and/or universal reference.

## Template type deduction

Short story, during template type deduction:

- arguments that are references are treated as non-references
- lvalue arguments get special treatment when deducing type of forwarding/universal reference parameters
- for by-value parameters, const and/or volatile arguments are treated as non-const and non-volatile
- arguments that are array or function names decay to pointers, unless they’re used to initialize references

```cpp
template<typename T>
void f(ParamType param);

f(expr);
```

How actuall type of `ParamType` and `T` are determined falls into three cathegories:
- `ParamType` is a pointer or reference type, but not a forwarding/universal reference (not `T&&`).
- `ParamType` is a forwarding/universal reference (`T&&`)
- `ParamType` is neither a pointer nor a reference


### `ParamType` is a pointer or reference type, but not a forwarding/universal reference

If expr’s type is a reference, ignore the reference part. Then pattern-match expr’s type against ParamType to determine type of T and of parameter.

**Note:** that in case when `ParamType` contains const then T is not deduced to be const! (having const const T& param is kind of avoided!)

**Note:** that array decay to pointers as expected but when ParamType is T& some surprises happen!!! There is a similar, obscure, thing with function types decaying to function pointers.


```cpp
#include <iostream>

template<typename T> struct Error;

template<typename T>
void ordinaryRef(T& param) // param is a reference
{
	Error<T> error1;
	Error<decltype(param)> error2;
}

template<typename T>
void constOrdinaryRef(const T& param) // param is a reference
{
	Error<T> error3;
	Error<decltype(param)> error4;
}

template<typename T>
void ordinaryPointer(T* param) // param is a reference
{
	Error<T> error5;
	Error<decltype(param)> error6;
}

template<typename T>
void constOrdinaryPointer(const T* param) // param is a reference
{
	Error<T> error7;
	Error<decltype(param)> error8;
}

int main()
{
	int x = 27; // x is an int
	const int cx = x; // cx is a const int
	const int& rx = x; // rx is a reference to x as a const int

	ordinaryRef(x); // T is int, param's type is int&
	ordinaryRef(cx); // T is const int, param's type is const int&
	ordinaryRef(rx); // T is const int, param's type is const int&

	constOrdinaryRef(x); // T is int, param's type is const int&
	constOrdinaryRef(cx); // T is int, param's type is const int&
	constOrdinaryRef(rx); // T is int, param's type is const int&

	int* px = &x;
	const int* cpx = &x;
	ordinaryPointer(px); // T is int, param's type is int*
	ordinaryPointer(cpx); // T is const int, param's type is const int*

	constOrdinaryPointer(px); // T is int, param's type is const int*
	constOrdinaryPointer(cpx); // T is int, param's type is const int*


	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	ordinaryPointer(arr); // T is int, param's type is int*, as expected array "decays" to pointer
	ordinaryRef(arr); // T is int[7], param's type is int (&)[7] (a reference to an array)!!!!

	const char carr[] = "C++ type deduction pitfalls";
	ordinaryPointer(carr); // T is const char, param's type is const char*, as expected array "decays" to pointer
	ordinaryRef(carr); // T is const char[28], param's type is const char(&)[28]!!!!!!
}
```

### `ParamType` is a forwarding/universal reference

If expr is an lvalue, both T and ParamType are deduced to be lvalue references. If expr is an rvalue, the rules (above) from the case for "normal" reference apply.

```cpp
#include <iostream>

template<typename T> struct Error;

template<typename T>
void forwardingRef(T&& param) // param is a reference
{
	Error<T> error1;
	Error<decltype(param)> error2;
}

int main()
{
	int x = 27; // x is an int
	const int cx = x; // cx is a const int
	const int& rx = x; // rx is a reference to x as a const int

	forwardingRef(x); // x is lvalue, so T is int&, param's type is also int&
	forwardingRef(cx); // cx is lvalue, so T is const int&, param's type is also const int&
	forwardingRef(rx); // rx is lvalue, so T is const int&, param's type is also const int&
	forwardingRef(27); // 27 is rvalue, so T is int, param's type is int&&
	forwardingRef(std::move(cx)); // move of const int is rvalue, so T is const int, param's type is const int&&
	forwardingRef(std::move(rx)); // move of const int& is rvalue, so T is const int, param's type is const int&&
}
```

### `ParamType` is neither a pointer nor a reference

Case where pass by value (copy) happens.

If expr’s type is a reference, ignore the reference part. If, after reference-ness, expr is const or volatile, ignore that, too.

```cpp
#include <iostream>

template<typename T> struct Error; 

template<typename T>
void copyValue(T param) // param is a reference
{
	Error<T> error1;
	Error<decltype(param)> error2;
}

int main()
{
	int x = 27; // x is an int
	const int cx = x; // cx is a const int
	const int& rx = x; // rx is a reference to x as a const int

	copyValue(x); // T is int, param's type is also int
	copyValue(cx); // T is int, param's type is also int
	copyValue(rx); // T is int, param's type is also int

	const char* const ptr = "Fun with pointers"; // ptr is const pointer to const object const char* const
	copyValue(ptr); // T is const char*, param's type is also const char *, modifiable pointer to const object
}
```

## auto type deduction
With one exception (initializer list handling), auto type deduction is identical to template type deduction.

Conceptually speaking:

`auto x = 27` uses same rules as
```cpp
template<typename T> 
void func_for_x(T param); 

func_for_x(27);
```

`auto& x = a` uses same rules as
```cpp
template<typename T> 
void func_for_x(T& param); 

func_for_x(a);
```

`const auto x = y` uses same rules as
```cpp
template<typename T> 
void func_for_x(const T param); 

func_for_x(y);
```

`const auto& x = z` uses same rules as
```cpp
template<typename T> 
void func_for_x(const T& param); 

func_for_x(z);
```

`auto&& x = g` uses same rules as
```cpp
template<typename T> 
void func_for_x(T&& param); 

func_for_x(g);
```

Identical rules and "caveats" regarding arrays and function pointers apply for `auto` too.

*The only difference is `std::initializer_list` handling!!!*

*However*, `auto` as return type or lambda argument type does "strict" template type deduction (no special handling for initializer list)!

```
#include <iostream>

template<typename T> struct Error;

int main()
{
	auto x = 27;  // not pointer, not reference, so x is int
	auto& rx = x; // reference but not forwarding/universal, so x is int&
	const auto cx = x;//  not pointer, not reference, so x is const int
	const auto& crx = x;  // reference but not forwarding/universal, so x is const int&
	auto&& uref1 = x; // x is int and lvalue so uref1 is int&
	auto&& uref2 = cx; // cx is const int and lvalue so uref2 is const int&
	auto&& uref3 = rx; // rx is int& and lvalue so uref3 is int&
	auto&& uref4 = crx; // crx is const int& and lvalue so uref4 is const int&
	auto&& uref5 = 27; // 27 is int and rvalue so uref5 is int&&
	auto&& uref6 = std::move(cx); // move of cx const int and rvalue so uref6 is const int&&

	const char carr[] = "Fun with pointers";
	auto carr1 = carr; // carr1 is const char * since array decays to pointer
	auto& carr2 = carr; // carr2 is const char (&)[18] due to reference to array being created

	auto x1 = 27; // int
	auto x2(27); // int
	auto x3 = { 27 }; // initializer list!!!!
	auto x4{ 27 }; // int (initializer list!!!! before C++17)
	auto x5{ 27, 30 }; // error (no auto with more than one item in direct init list)
	auto x6 = { 27, 30 }; // initializer list!!!!

	Error<decltype(x)> ex;
	Error<decltype(rx)> erx;
	Error<decltype(cx)> ecx;
	Error<decltype(crx)> ecrx;
	Error<decltype(uref1)> euref1;
	Error<decltype(uref2)> euref2;
	Error<decltype(uref3)> euref3;
	Error<decltype(uref4)> euref4;
	Error<decltype(uref5)> euref5;
	Error<decltype(uref6)> euref6;
	Error<decltype(carr1)> ecarr1;
	Error<decltype(carr2)> ecarr2;
	Error<decltype(x1)> ex1;
	Error<decltype(x2)> ex2;
	Error<decltype(x3)> ex3;
	Error<decltype(x4)> ex4;
	Error<decltype(x6)> ex6;
}
```

## decltype type

Applying decltype to a name yields the declared type for that name. However, if an lvalue expression other than a name has type T, decltype reports that type as T&.

**Note:** when using `decltype(auto)` for automatic deduction of return value be careful how you write return statements!!!

```cpp
int x = 0;

decltype(x) a;         // a is int
decltype((x)) b;       // b is int& because (x) is an expression


decltype(auto) simple_x() 
{
    int x = 0;
	return x;          // returns int
}

decltype(auto) x_with_parentheses() 
{
    int x = 0;
	return (x);          // returns int& !!!!!!! reference to local!!!!!!
}
```

## type diagnostics

One cannot rely on typeid or std::type_index to find out type (removes constness and referenceness, output might not be human readable).

Can force compiler to output exact type in error log using simple template trick.

```cpp
#include <iostream>

template<typename T> // declaration only for "Type Displayer"
class TD;

int main() {
	const int theAnswer = 42;
	auto x = theAnswer;
	auto y = &theAnswer;

	TD<decltype(x)> xType; // elicit errors containing
	TD<decltype(y)> yType; // x's and y's types}
}
```

Or use Boost.TypeIndex library.


## When is dectructor not invoked?

Automatic cleanup, often, relies on the fact that (local) object dectructor will be invoked at the end of the scope irrespective of how scope ends (exception, return statement, break statement, etc....).

However there are few exceptions which happen during "abnormal" termination. In those cases local variables might not be destroyed:

- exception propagated out of program's initial thread (main)
- violation of `noexcept`
- any exit function is invoked like `std::exit` or `std::abort`

  
## public deleted functions

As mentioned in Effective Modern C++ making deleted functions public produces better error messages because **some** compilers tend to report accessibility related errors before deleted status.


```cpp
class privateSingleton
{
private:
	privateSingleton() = default;
	privateSingleton(privateSingleton const&) = delete;
	void operator=(privateSingleton const&) = delete;
public:
	static privateSingleton& Instance() {
		static privateSingleton instance;
		return instance;
	}
};

class singleton
{
private:
	singleton() = default;
public:
	singleton(singleton const&) = delete;
	void operator=(singleton const&) = delete;
public:
	static singleton& Instance() {
		static singleton instance;
		return instance;
	}
};

int main()
{
	privateSingleton s1 = privateSingleton::Instance(); // compiler error: is inaccessible
	singleton s2 = singleton::Instance(); // compiler error: attempting to reference a deleted function
}
```

## Invoking base class method if base class is template

Invoking base class method might not work as expected if base class is template. See example below.

The "problem" is in [Two Phase Lookup](https://stackoverflow.com/questions/7767626/two-phase-lookup-explanation-needed), more [info here](http://blog.llvm.org/2009/12/dreaded-two-phase-name-lookup.html), where non-dependant names are resolved in phase one and dependant in phase two.

```cpp
template <typename T>
class Base {
public:
    void baseFunction() {}
};

template <typename T> 
class Derived : public Base<T> {
public:
    // without this just invoking baseFunction() results in compiler error
    using Base<T>::baseFunction;             
    void derivedFunction() {
        // following line results in compiler error identifier not found
        // unless using above is used
        baseFunction();                      

        // other ways to invoke without using above
        this->baseFunction();
        Base<T>::baseFunction();
    }
};
```


## function level try/catch block

Function level try/catch block introduces handler around the whole body of a function (including memeber constructors and destructors in case of a constructor or destructor!).

This construct is mainly to be used on constructors and destructors (although destructors should not throw!!!) and there are two special rules that apply to constructors/destructors:

- if the function level catch handler for constructor/destructor reaches the end, the current exception is automatically rethrown
- function level catch handler for constructor cannot return (must implicitly or explicitly (re)throw), destructor can return


```cpp
#include <iostream>
#include <stdexcept>

struct Member {
    Member(int a) : num(a) { if (a == 1) throw std::runtime_error("Member Constructor Error"); }
    ~Member() noexcept(false) { throw std::runtime_error("Member Destructor Error"); }
    int num;
};
class Class {
    Member member;
public:
    Class(int a)
    try    // A constructor try block.
        : member(a) // Can throw std::exception
    {
        // ... constructor body ...
    }
    catch (std::exception const& e)
    {
        std::cout << "Member threw: " << e.what() << std::endl;
        //throw; // rethrown implicitly here!!! cannot just return
    }

    ~Class() noexcept(false)
    try    // A destructor try block.
    {
        // ... destructor body ...
    }
    catch (std::exception const& e)
    {
        std::cout << "Member threw: " << e.what() << std::endl;
        if (member.num != 2)
            return;
        //throw; // rethrown implicitly here unless there is a return before
    }
};

int main(void)
{
    try {
        Class a(1);
    }
    catch (std::exception const& e) {
        // here because constructor throws
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try {
        Class a(2);
    }
    catch (std::exception const& e) {
        // here because destructor throws
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try {
        Class a(3);
    }
    catch (std::exception const& e) {
        // not here because destructor's catch returns
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
```


## Some of the references

- [Effective Modern C++](https://www.oreilly.com/library/view/effective-modern-c/9781491908419/)
- [Universal reference](https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers)
