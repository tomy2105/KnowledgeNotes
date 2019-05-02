# Not so obvious C++

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

<!--stackedit_data:
eyJoaXN0b3J5IjpbLTcyODU2MjcwNiwtNTQwMzE5MzM0LDE5Mz
g3NDk0NjgsNjI0MTI5NDY5LDE0OTczOTU5MzgsLTE3NTAxMTcx
NjMsLTE4MjA3NDkwMjgsLTEzMjc5MDgwOCwtMTM1NzI2Njk2NS
wtMTYxMzU3MjAyNl19
-->