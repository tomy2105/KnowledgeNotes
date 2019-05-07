# CPP 14

## New language features

### Function return type deduction

In order to induce return type deduction, the function must be declared with auto as the return type, but without the trailing return type specifier in C++11. 

- If multiple returns, they must be same type
- If recursion, at least one return before recursion call

```cpp
auto Correct(int i)
{
  if (i == 1)
    return i;             // return type deduced as int

  return Correct(i-1)+i;  // ok to call it now
}
```

### Alternate type deduction on declaration

The decltype(auto) syntax allows auto declarations to use the decltype rules on the given expression. 

The decltype(auto) syntax can also be used with return type deduction, by using decltype(auto) syntax instead of auto for the function's return type deduction.


### Relaxed constexpr restrictions


Constexpr functions may now contain the following:
- Any declarations except: 
  - static or thread_local variables.
  - Variable declarations without initializers.
- The conditional branching statements if and switch.
- Any looping statement, including range-based for.
- Expressions which change the value of an object if the lifetime of that object began within the constant expression function. 
- goto statements are forbidden in C++14 relaxed constexpr-declared functions. 


### Variable templates

C++14 now allows the creation of variables that are templated. 

```cpp
template<typename T>
constexpr T pi = T(3.141592653589793238462643383);

// Usual specialization rules apply:
template<>
constexpr const char* pi<const char*> = "pi";

	std::cout << pi<int> << std::endl; // outputs 3
	std::cout << pi<double> << std::endl; // outputs 3.14159
	std::cout << pi<const char*> << std::endl; // outputs pi
```


### Binary literals

Numeric literals  be specified in binary form, syntax uses the prefixes 0b or 0B. 

### Digit separators

Single-quote character may be used arbitrarily as a digit separator in numeric literals, both integer literals and floating point literals.

### Generic lambdas

Lambda function parameters to be declared with the `auto` type specifier.

```cpp
#include <iostream>
#include <string>

int main() {
	auto lambda = [](auto x, auto y) { return x + y; };
	std::cout << lambda(1, 2)									<< std::endl;	// outputs 3
	std::cout << lambda(1.1, 2.2)								<< std::endl;	// outputs 3.3
	std::cout << lambda(std::string("foo"), std::string("bar")) << std::endl;	// outputs foobar
}
```


### Lambda capture expressions

Captured members to be initialized with arbitrary expressions allowing capture by value-move and declaring arbitrary members of the lambda
(can even add arbitrary new state to the lambda object).

```cpp
std::unique_ptr<int> ptr(new int(10));
auto lambda = [value = std::move(ptr)] {return *value;};
```

```cpp
auto incrementer = [value = 1]() mutable { return value++; };
auto incrementer2 = [value = 11]() mutable { return value++; };
std::cout << incrementer() << std::endl;    // outputs 1
std::cout << incrementer2() << std::endl;   // outputs 11
std::cout << incrementer() << std::endl;    // outputs 2
std::cout << incrementer2() << std::endl;   // outputs 12
```

###  The attribute [[deprecated]]

The deprecated attribute (with optional description) puts  on notice that use is discouraged and may cause a warning message to be printed during compilation.

```cpp
[[deprecated]] int f() {}

[[deprecated("g() is thread-unsafe. Use h() instead")]]
void g( int& x ) {}

void h( int& x ) {}

void test()
{
  int a = f(); // warning: 'f' is deprecated
  g(a); // warning: 'g' is deprecated: g() is thread-unsafe. Use h() instead
}
```

**MS compiler emits error instead of warning if SDL is enabled!**

## New standard library features

### Shared mutexes and locking

Shared timed (non timed version in C++17) mutex and a companion shared lock type is added.

In contrast to other mutex types which facilitate exclusive access, a shared_timed_mutex has two levels of access:
- shared - several threads can share ownership of the same mutex (*read access*) - obtained via `shared_lock`
- exclusive - only one thread can own the mutex (*write access*) - obtained via `unique_lock`

More info with examples [here](https://en.cppreference.com/w/cpp/thread).

### Heterogeneous lookup in associative containers

For ordered associative containers (`map`, `multimap`, `set` and `multiset`) you are no longer required to pass the exact same object type as the key or element in member functions such as `find()` and `lower_bound()`, you can pass any type for which an overloaded `operator<` is defined.

**Note**: Feature us is enabled on an opt-in basis when you specify the std::less<> or std::greater<> "diamond functor" comparator when declaring the container variable, if you use the default comparator, then the container behaves as it did in earlier specification.


### Standard user-defined literals

Following standard literals are added: 
- "s", for creating the various std::basic_string types.
- "h", "min", "s", "ms", "us", "ns", for creating the corresponding std::chrono::duration time intervals.
- "if", "i", "il", for creating the corresponding std::complex<float>, std::complex<double> and std::complex<long double> imaginary numbers.

**Note**: Literals are added inside namespace so using namespace is required!

```cpp
using namespace std::string_literals;
auto str = "hello world"s; // auto deduces string

using namespace std::chrono_literals;
auto dur = 60s;            // auto deduces chrono::seconds

using namespace std::complex_literals;
auto z = 1.0 + 1i;             // auto deduces complex<double>
```


### Tuple addressing via type

Allow fetching from a tuple by type instead of by index, if the tuple has more than one element of the type, a compile-time error results.

```cpp
tuple<string, string, int> t("foo", "bar", 7);
int i = get<int>(t);        // i == 7
int j = get<2>(t);          // Same as before: j == 7
string s = get<string>(t);  // Compile-time error due to ambiguity
```

### Smaller library features

`std::make_unique` can be used like `std::make_shared` for `std::unique_ptr` objects.

The class template `std::integer_sequence` and related alias templates were added for representing compile-time integer sequences, such as the indices of elements in a parameter pack (see [example](https://en.cppreference.com/w/cpp/utility/integer_sequence)).

In addition to `std::begin`/`std::end`, following were added for constant/reverse functionality: `std::cbegin`/`std::cend`, `std::rbegin`/`std::rend` and `std::crbegin`/`std::crend`. 

`std::quoted` for inserting and extracting strings with embedded spaces, by placing delimiters output and stripping them on input, and escaping any embedded delimiters. 

`std::exchange` algorithm has been added to set new value and return old.



## Some of the references

- [C++ 14 Wiki](https://en.wikipedia.org/wiki/C%2B%2B14)
- [C++ 14 Language Extensions] (https://isocpp.org/wiki/faq/cpp14-language)
- [C++ 14 Library Extensions] (https://isocpp.org/wiki/faq/cpp14-library)
- [Modern C++ features] (https://github.com/AnthonyCalandra/modern-cpp-features)

