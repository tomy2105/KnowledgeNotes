# CPP 17

## Core language features

### Fold expressions

Can directly reduce a variadic templates parameter pack with a binary operator.

```cpp
#include <iostream>

template<typename ...Args>
auto sum(const Args&&... args) {
	return (args + ... + 0);
}

int main() {
	std::cout << "sum(0): " << sum() << std::endl;
	std::cout << "sum(1): " << sum(1) << std::endl;
	std::cout << "sum(1, 2, 3, 4): " << sum(1, 2, 3, 4) << std::endl;
	std::cout << "sum(1.1, 2.2, 3.3): " << sum(1.1, 2.2, 3.3) << std::endl;
}
```

There are four variations base if default value is present and if evaluated from left or from right:

| Expression   | Description  |
|---|---|
| ... op pack  | unary fold from left with operator op  |
| pack op ...  | unary fold from right with operator op   |
| init ... op pack  | binary fold from left with operator op and initial value init |
| pack op ... init | binary fold from right with operator op and initial value init |

Unary fold with empty parameter pack can be used only with operators that have default value specified and those are *&&*, *||* and *,*.

### constexpr if

Enables to conditionally compile source code.

```cpp
template <typename T>
auto get_value(T t) {
    if constexpr (std::is_pointer_v<T>)
        return *t; 
    else
        return t;
}
```

### Initializers in if and switch statements

Similar as you can for *for* statement, directly initialize variables inside the *if* and *switch* statements. Variables are scoped to if/else/switch statement and destroyed immediately after them.

```cpp
#include <iostream>

class Temp {
public:
	Temp(bool b_) : b(b_) { std::cout << "Temp()" << std::endl; }
	~Temp() { std::cout << "~Temp()" << std::endl; }
	bool isTrue() { return b; }
private:
	bool b;
};


int main() 
{
	std::cout << "Before if" << std::endl;
	if (Temp t = Temp(true); t.isTrue()) {
		std::cout << "Inside if" << std::endl;
	}
	else {
		std::cout << "Inside else" << std::endl;
	}
	std::cout << "After if" << std::endl;
}
```

### Structured binding declarations

Allows binding std::tuple, std::pair, array or a non-static data member directly to variables. 

```cpp
#include <set>
#include <string>
#include <iostream>

int main() {
	std::set<std::string> myset;
	if (auto[iter, success] = myset.insert("Hello"); success)
		std::cout << "insert is successful. The value is " << *iter << '\n';
	else
		std::cout << "The value " << *iter << " already exists in the set\n";

	if (auto[iter, success] = myset.insert("Hello"); success)
		std::cout << "insert is successful. The value is " << *iter << '\n';
	else
		std::cout << "The value " << *iter << " already exists in the set\n";
}
```

Similar functionality was available prior to C++17 with `std::tie`.

More info and verbose explanation can be found [here](https://en.cppreference.com/w/cpp/language/structured_binding).

### Template deduction of constructors

A constructor of a class template can deduce its type parameters from is constructor arguments.

```cpp
#include <iostream>

template <typename T>
struct ShowMe {
	ShowMe(const T& t) {
		std::cout << t << std::endl;
	}
};

int main() {
	ShowMe(5.5);  // only with C++17, before it had to be: ShowMe<double>(5.5) ;
	ShowMe(5);    // only with C++17, before it had to be: ShowMe<int>(5);
}
```

### Copy elision

Optional before C++17, now gauranteed.

Applies to return values, (named) return value optimization, passing temporary by value and throwing and catching exceptions by value.

More info [here](https://jonasdevlieghere.com/guaranteed-copy-elision/).

### Inline variables

You can declare global variables and static variables inline. 
The same rules that are applied to inline functions are applied to inline variables.

- There can be more than one definitions of an inline variable.
-  The definition of an inline variable must be present in the translation unit, in which it is used.
-  A global inline variable (non-static inline variable) must be declared inline in every translation unit and has the same address in every translation unit.

### Automatic type deduction of non-type template parameters

```cpp
template <auto N>
class MyClass{
  ...
};

template <int N> 
class MyClass<N> {
  ...
};


MyClass<'x'> myClass2;     // Primary template for char
MyClass<2017>  myClass1;   // Partial specialisation for int
```

### auto in combination with an {}-Initialisation

Type is no longer always `std::initializer_list`.

```cpp
auto initA{1};          // int
auto initB= {2};        // std::initializer_list<int>
auto initC{1, 2};       // error, no single element
auto initD= {1, 2};     // std::initializer_list<int>
```

Assigning with a {} returns a std::initializer_list. Copy construction only works for a single value.
  
### Nested namespaces

```cpp
namespace A::B::C {
  ...
}
```

### New attributesfallthrough, nodiscard, and maybe_unused

- `[[fallthrough]]` can be used in a switch statement. It has to be on its own line, immediately before a case label and indicates that a fall through is intentional and should therefore not diagnose a compiler warning.
- `[[nodiscard]]` can be used in a function declaration, enumeration declaration, or class declaration. If you discard the return value from a function declared as nodiscard, the compiler should issue a warning. 
- `[[maybe_unused]]` can be used in the declaration of a class, a typedef­, a variable, a non­-static data member, a function, an enumeration, or an enumerator. Thanks to maybe_unused, the compiler suppresses a warning on an unused entity. 

### Compile time if

Discard branches of an if statement at compile-time based on a constant expression condition

```cpp
template<int N>
constexpr int fibonacci()
{
    if constexpr (N>=2)
        return fibonacci<N-1>() + fibonacci<N-2>();
    else
        return N;
}
```

### Lambda capture of this by value(copy)

`*this` in caputre list denotes capturing enclosing object by value.

```cpp
#include <string>
#include <iostream>

struct Struct {
	double ohseven = .007;
	auto f() { 
		return[*this]{ // capture the enclosing Struct by copy (C++17)
			return ohseven;
		};
	}
	auto g() {
		return[this]{ // capture the enclosing Struct by pointer/reference (C++11)
			return ohseven;
		};
	}
};

int main()
{
	Struct s;
	auto f = s.f();
	auto g = s.g();
	std::cout << f() << " " << g() << " " << s.ohseven << std::endl;
	s.ohseven = .008;
	std::cout << f() << " " << g() << " " << s.ohseven << std::endl;
}
```

### Other smaller enhancements

- text message for static_assert optional
- typename (as an alternative to class) in a template template parameter
- UTF-8 (u8) character literals
- Hexadecimal floating-point literals
- `__has_include`, allowing availability of a header to be checked by preprocessor directives
- keyword register is now reserved and unused (formerly deprecated)
- removal of auto_ptr and trigraphs
- removal of ++ operator on bool
- dynamic exception specification has been removed, `throw()` remains as alias for `noexcept()`
- end expression for ranged foor loop no longer needs to be an iterator (of same type as begin), now only comparison is required
- evaluation order rules changed a bit "the function arguments must be fully evaluated before all other arguments" so chaining works as expected
- some additional memory allocation functions that uses align parameter
- exception specification is part of the type system
- attributes on namespaces and enumerators, omitting unknown attributes

## Standard Library enhancements

### basic_string_view

A **non-owning** reference to a sequence of characters (std::string, or C-string).
Cheap to copy, mainly readonly with two, fast, modfiy methods: `remove_prefix` and `remove_suffix`.

```cpp
#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <vector>


std::string_view remove_space(std::string_view strView) {
	strView.remove_prefix(std::min(strView.find_first_not_of(' '), strView.size()));
	auto pos = strView.find_last_not_of(' ');
	if (pos != std::string_view::npos)
		strView.remove_suffix(strView.size() - pos - 1);
	return strView;
}

int main() {
	std::string str = "   A lot of space    ";
	std::string_view strView = remove_space(str);
	std::cout << "str      :" << str << ":" << std::endl
		<< "strView  :" << strView << ":" << std::endl;

	std::cout << std::endl;

	char arr[] = { ' ', ' ', ' ', ' ', ' ', ' ', 'A',' ','l','o','t',' ','o','f',' ','s','p','a','c','e',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};
	std::string_view strView2 = remove_space(arr);
	std::cout << "arr      :" << arr << ":" << std::endl
		<< "strView2 :" << strView2 << ":" << std::endl;
}
```

Template specialization for all underlaying character types exist (`string_view`, `wstring_view`, `u16string_view`, `u32string_view`).

### Parallel algorithms

Algorithms of the STL available in a sequential, parallel and parallel and vectorized (Single Instruction, Multiple Data, SIMD, extensions used) versions.

Version is determined by first argument to the algorithm specifying [execution policy](https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t).

```cpp
#include <vector>
#include <algorithm>

int main()
{
	std::vector<unsigned long> v(10000000);
	..... fill vector .....
	// standard sequential sort
	std::vector v1 = v;
	std::sort(v1.begin(), v1.end());

	// sequential execution
	std::vector v2 = v;
	std::sort(std::execution::seq, v2.begin(), v2.end());

	// permitting parallel execution
	std::vector v3 = v;
	std::sort(std::execution::par, v3.begin(), v3.end());

	// permitting parallel and vectorized execution
	std::vector v4 = v;
	std::sort(std::execution::par_unseq, v4.begin(), v4.end());
}
```

More complete example with timings can be found in [Sort.cpp](Sort.cpp).

Operating system support SIMD instructions and/or compiler glags and the optimisation level determined whether an algorithm runs in a parallel and vectorised way.

**There is no automatic prevention of data races and deadlock, it is programmers responsibility!!!**

### New algortihms and functions

Several new algorithms have been introduced:

- `std::for_each_n` - for each for first n elements
- `std::exclusive_scan` - an exclusive prefix sum operation on a range using binary operator
- `std::inclusive_scan` - an inclusive prefix sum operation on a range  using binary operator
- `std::transform_exclusive_scan` - combination of transform and exclusive_scan
- `std::transform_inclusive_scan` - combination of transform and inclusive_scan
- `std::reduce` - reduces range using binary operator (similar to accumulate)
- `std::transform_reduce` - combination of transform and reduce
- `std::clamp` - value between two boundaries
- `std::gcd`, `std::lcm` - common denominator and multiplier
- `std::not_fn` -  returns the negation of the callable object it holds

### The filesystem library

Based on boost::filesystem. based on the three concepts file, file name and path. Files can be directories, hard links, symbolic links or regular files. Paths can be absolute or relative.

More info [here](https://en.cppreference.com/w/cpp/filesystem) and [here](https://www.bfilipek.com/2017/08/cpp17-details-filesystem.html).


### Any
A type-safe container for single values of any type (must be copyable). 
Number of `any_cast` functions provide type-safe access to the contained object and throws `bad_any_cast` if access is not allowed.

```cpp
#include <any>
#include <iostream>

struct Foo {
	int a;
	int b;
};

int main()
{
	std::cout << std::boolalpha;
	std::any a = 1;
	std::cout << a.type().name() << ": " << std::any_cast<int>(a) << '\n';
	a = 3.14;
	std::cout << a.type().name() << ": " << std::any_cast<double>(a) << '\n';
	a = true;
	std::cout << a.type().name() << ": " << std::any_cast<bool>(a) << '\n';
	a = Foo{ 1,2 };
	std::cout << a.type().name() << ": " << std::any_cast<Foo>(a).a << " " << std::any_cast<PeFooro>(a).b << '\n';
}
```

More info [here](https://en.cppreference.com/w/cpp/utility/any).

### Optional
Can have a value or no value (), common use case a return value of a function that can fail.

Can be converted to bool, indicating if value is present. Contained value is accessed via `value` or `value_or` methods or `->` or `*` operators.

```cpp
#include <string>
#include <functional>
#include <iostream>
#include <optional>

// optional can be used as the return type of a factory that may fail
std::optional<std::string> create(bool b) {
	if (b)
		return "Godzilla";
	return {};
}

// std::nullopt can be used to create any (empty) std::optional
auto create2(bool b) {
	return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
}

// std::reference_wrapper may be used to return a reference
auto create_ref(bool b) {
	static std::string value = "Godzilla";
	return b ? std::optional<std::reference_wrapper<std::string>>{value}
	: std::nullopt;
}

int main()
{
	std::cout << "create(false) returned " << create(false).value_or("empty") << '\n';

	// optional-returning factory functions are usable as conditions of while and if
	if (auto str = create2(true)) {
		std::cout << "create2(true) returned " << *str << '\n';
	}

	if (auto str = create_ref(true)) {
		// using get() to access the reference_wrapper's value
		std::cout << "create_ref(true) returned " << str->get() << '\n';
		str->get() = "Mothra";
		std::cout << "modifying it changed it to " << str->get() << '\n';
	}

	std::cout << std::endl;
	// C string literal
	std::optional<std::string> opt1(std::in_place, "C++17");                        // 1
	// 5 characters 'C'
	std::optional<std::string> opt2(std::in_place,5, 'C');                          // 2
	// initializer list
	std::optional<std::string> opt3(std::in_place, {'C', '+', '+', '1', '7'});      // 3
	// Copy constructor
	std::optional<std::string> opt4(opt3);                                          // 4
	
	std::cout << *opt1 << std::endl;
	std::cout << *opt2 << std::endl;
	std::cout << *opt3 << std::endl;
	std::cout << *opt4 << std::endl;
	
	std::cout << std::endl;}
```


More info [here](https://en.cppreference.com/w/cpp/utility/optional).

### Variant
Represents a type-safe union. 

An instance of std::variant at any given time either holds a value of one of its alternative types, or in the case of error - no value.

Not permitted to hold references, arrays, or the type void. 

`std::get` or `get_if` used to access values, compile time error or throws `bad_variant_access` in case of wrong value type.

```cpp
#include <variant>
#include <string>
#include <cassert>
#include <vector>
#include <iostream>

// helper type for the visitor
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...)->overloaded<Ts...>; 

int main()
{
	std::variant<int, float> v, w;
	v = 12; // v contains int
	int i = std::get<int>(v);
	w = std::get<int>(v);
	w = std::get<0>(v); // same effect as the previous line
	w = v; // same effect as the previous line

//  std::get<double>(v); // compile time error: no double in [int, float]
//  std::get<3>(v);      // compile time error: valid index values are 0 and 1

	try {
		std::get<float>(w); // w contains int, not float: will throw
	}
	catch (const std::bad_variant_access&) {}

	using var_t = std::variant<int, long, double, std::string>;
	std::vector<var_t> vec = { 10, 15l, 1.5, "hello" };
	for (auto& v : vec) {
		std::visit([](auto&& arg) {std::cout << arg << " "; }, v);
	}

	std::cout << std::endl;

	for (auto& v : vec) {
		std::visit(overloaded{
			[](auto arg) { std::cout << "Auto: " << arg << ' '; },
			[](double arg) { std::cout << "Double: " << std::fixed << arg << ' '; },
			[](const std::string& arg) { std::cout << "String: " << arg << ' '; },
		}, v);
	}
}
```

`std::visit` can be used to write "type" independant actions on variant. More [here](https://en.cppreference.com/w/cpp/utility/variant/visit).

More info [here](https://en.cppreference.com/w/cpp/utility/variant).

### Byte

A byte is only a collection of bits, and the only operators defined for it are the bitwise ones. 

More info [here](https://en.cppreference.com/w/cpp/types/byte).

### Invoke and apply

Invoke callable object with arguments
- std::invoke - with direct arguments specified
- std::apply - with array, tuple, pair used to specify arguments

```cpp
#include <functional>
#include <iostream>
#include <array>

struct Foo {
	Foo(int num) : num_(num) {}
	void print_add(int i) const { std::cout << num_ + i << '\n'; }
	int num_;
};

void print_num(int i)
{
	std::cout << i << '\n';
}

struct PrintNum {
	void operator()(int i) const
	{
		std::cout << i << '\n';
	}
};

int add(int first, int second) { return first + second; }

template<typename T>
T add_generic(T first, T second) { return first + second; }

auto add_lambda = [](auto first, auto second) { return first + second; };

int add_all(int first, int second, int third) { return first + second + third; }

int main()
{
	// invoke a free function
	std::invoke(print_num, -9);

	// invoke a lambda
	std::invoke([]() { print_num(42); });

	// invoke a member function
	const Foo foo(314159);
	std::invoke(&Foo::print_add, foo, 1);

	// invoke (access) a data member
	std::cout << "num_: " << std::invoke(&Foo::num_, foo) << '\n';

	// invoke a function object
	std::invoke(PrintNum(), 18);

	// OK
	std::array<int, 3> arr = { 4, 5, 6 };
	std::cout << std::apply(add, std::make_pair(1, 2)) << '\n';
	std::cout << std::apply(add_all, std::make_tuple(1, 2, 3)) << '\n';
	std::cout << std::apply(add_all, arr) << '\n';

	// Error: can't deduce the function type
	// std::cout << std::apply(add_generic, std::make_pair(2.0f, 3.0f)) << '\n'; 

	// OK
	std::cout << std::apply(add_lambda, std::make_pair(2.0f, 3.0f)) << '\n';
}

```

More info [here](https://en.cppreference.com/w/cpp/utility/functional/invoke).

### Shared mutex

Mutex with  two levels of access:
- shared - several threads can share ownership of the same mutex, obtained by `std::shared_lock`
- exclusive - only one thread can own the mutex, obtained by `std::unique_lock`

```cpp
#include <iostream>
#include <mutex>  // For std::unique_lock
#include <shared_mutex>
#include <thread>
#include <sstream>

class osyncstream : public std::stringstream
{
public:
	osyncstream() = default;
	~osyncstream()
	{
		std::cout << std::stringstream::str();
	}
};

class ThreadSafeCounter {
public:
	ThreadSafeCounter() = default;

	// Multiple threads/readers can read the counter's value at the same time.
	unsigned int get() const {
		std::shared_lock lock(mutex_);
		return value_;
	}

	// Only one thread/writer can increment/write the counter's value.
	void increment() {
		std::unique_lock lock(mutex_);
		value_++;
	}

	// Only one thread/writer can reset/write the counter's value.
	void reset() {
		std::unique_lock lock(mutex_);
		value_ = 0;
	}

private:
	mutable std::shared_mutex mutex_;
	unsigned int value_ = 0;
};

int main() {
	ThreadSafeCounter counter;

	auto increment_and_print = [&counter]() {
		for (int i = 0; i < 10; i++) {
			counter.increment();
			osyncstream() << std::this_thread::get_id() << ' ' << counter.get() << '\n';
		}
	};

	std::thread thread1(increment_and_print);
	std::thread thread2(increment_and_print);

	thread1.join();
	thread2.join();
}
```

More info [here](https://en.cppreference.com/w/cpp/thread/shared_mutex).

### Scoped lock

RAII-style mechanism for owning one or more mutexes for the duration of a scoped block. If several mutexes are given, deadlock avoidance algorithm is used as if by `std::lock`.

More info [here](https://en.cppreference.com/w/cpp/thread/scoped_lock).

One more code example is in [Philosophers.cpp](Philosophers.cpp).

### Memory allocation and polymorphic allocator

A **lot** of classes for easier writing of custom allocators.

- `polymorphic_allocator` - an allocator that supports run-time polymorphism based on the std::memory_resource it is constructed with
- `memory_resource` - an abstract interface for classes that encapsulate memory resources
- `new_delete_resource` - returns a static program-wide std::pmr::memory_resource that uses the global operator new and operator delete to allocate and deallocate memory
- `null_memory_resource` - returns a static std::pmr::memory_resource that performs no allocation
- `get_default_resource` - gets the default std::pmr::memory_resource
- `set_default_resource` - sets the default std::pmr::memory_resource
- `pool_options` - a set of constructor options for pool resources
- `synchronized_pool_resource` - a thread-safe std::pmr::memory_resource for managing allocations in pools of different block sizes
- `unsynchronized_pool_resource` - a thread-unsafe std::pmr::memory_resource for managing allocations in pools of different block sizes
- `monotonic_buffer_resource` - 	a special-purpose std::pmr::memory_resource that releases the allocated memory only when the resource is destroyed


```cpp
#include <iostream>
#include <memory_resource>
#include <vector>

int main() {
    char buffer[64] = {};
    std::fill_n(std::begin(buffer), std::size(buffer)-1, '_');
    std::cout << buffer << '\n';

    std::pmr::monotonic_buffer_resource pool{
        std::data(buffer), std::size(buffer)
    };

    std::pmr::vector<char> vec{&pool};    
    for (char ch='a'; ch <= 'z'; ++ch)
        vec.push_back(ch);

    std::cout << buffer << '\n';
}
```

More info [here](https://en.cppreference.com/w/cpp/memory).

### Other smaller enhancements

- `std::uncaught_exceptions`, as a replacement of `std::uncaught_exception` in exception handling
- new insertion functions `try_emplace` and `insert_or_assign` for `std::map` and `std::unordered_map`
- uniform container access: `std::size`, `std::empty` and `std::data`
- logical operator traits: `std::conjunction`, `std::disjunction` and `std::negation`
- improved `std::search` with searchers
- `std::void_t` - metafunction that maps a sequence of any types to the type void, more [here](https://en.cppreference.com/w/cpp/types/void_t)
- bunch of special mathematical functions, more [here](https://en.cppreference.com/w/cpp/numeric/special_math)
- `std::is_aggregate` - type traits checking if aggregate type
- `std::to_chars` and `std::from_chars` - for simple integer/float to char sequence conversions
- `std::as_const`

## Some of the references

- [Modernes C++](https://www.modernescpp.com/)
- [Changes between C++14 and C++17](https://isocpp.org/files/papers/p0636r0.html)
- [C++17 Features all in one](https://github.com/tvaneerd/cpp17_in_TTs/blob/master/ALL_IN_ONE.md)
- [C++ compiler support](https://en.cppreference.com/w/cpp/compiler_support)
