# CPP 20

<!-- toc -->

- [New language features](#new-language-features)
  * [Feature test macros](#feature-test-macros)
  * [Constraints and concepts](#constraints-and-concepts)
  * [Coroutines](#coroutines)
  * [Modules](#modules)
  * [3-way comparison operator and operator==() = default](#3-way-comparison-operator--and-operator--default)
  * [Designated initializers](#designated-initializers)
  * [Aggregates initialized using parenthesis](#aggregates-initialized-using-parenthesis)
  * [New and changed standard attributes](#new-and-changed-standard-attributes)
  * [Initializer in range based for loop](#initializer-in-range-based-for-loop)
  * [Pack expansion in lambda init-capture](#pack-expansion-in-lambda-init-capture)
  * [Abbreviated function template](#abbreviated-function-template)
  * [consteval, constinit](#consteval-constinit)
  * [Compile time allocations in constexpr](#compile-time-allocations-in-constexpr)
  * [Other improvements](#other-improvements)
- [New library features](#new-library-features)
  * [Concepts](#concepts)
  * [Span](#span)
  * [Ranges](#ranges)
  * [Threading facilities](#threading-facilities)
    + [Auto joinable thread and thread stopping classes](#auto-joinable-thread-and-thread-stopping-classes)
    + [Latch](#latch)
    + [Barrier](#barrier)
    + [Semaphore](#semaphore)
  * [Formatting library](#formatting-library)
  * [Calendar and Time Zone additions to library](#calendar-and-time-zone-additions-to--library)
  * [Heterogeneous lookup in unordered associative containers](#heterogeneous-lookup-in-unordered-associative-containers)
  * [Other improvements](#other-improvements-1)
- [Some of the references](#some-of-the-references)

<!-- tocstop -->

## New language features

### Feature test macros

A set of macros to test for the language and librarz features (C++11 and newer) supported has been introduced.

```cpp
void f(int n) {
    switch (n) {
    case 1:
    case 2:
        printf("Here we are");
#if __cpp_attributes && __has_cpp_attribute( fallthrough )
        [[fallthrough]];
#endif
    case 3: // no warning on fallthrough
        printf("Here we go");
    }
}
```

For the complete list of available macros see: [Feature testing](https://en.cppreference.com/w/cpp/feature_test).


### Constraints and concepts

Concepts are named compile-time predicates, evaluate to boolean, which constrain types, they can either "reference"
other concepts like:
```cpp
template <typename T>
concept signed_integral = integral<T> && std::is_signed_v<T>;
```
or can have their own `requires` expression>
```cpp
template <typename T>
concept callable = requires (T f) { f(); };
```

Concepts are enforced using number of syntatic forms, either directly on template type, auto type or directily using `requires` clause:
```cpp
template <my_concept T> 
void f(T v);

template <typename T> requires my_concept<T>
void f(T v);

template <typename T>
void f(T v) requires my_concept<T>;

void f(my_concept auto v);

template <my_concept auto v>
void g();

my_concept auto foo = ...;

auto f = []<my_concept T> (T v) {};

auto f = []<typename T> requires my_concept<T> (T v) {};

auto f = []<typename T> (T v) requires my_concept<T> {};

auto f = [](my_concept auto v) {};

auto g = []<my_concept auto v> () {};
```

Requirement expresssion can be one of:

- Simple requirements that asserts that the given expression is valid
```cpp
template <typename T>
concept callable = requires (T f) { f(); };
```
- Type requirements - asserts that the given type name is valid
```cpp
template <typename T>
concept C = requires { typename T::value; }; // T must have T::value
```
- Compound requirements - an expression in braces followed by a trailing return type or constraint
```cpp
template <typename T>
concept C = requires(T x) { {x + 1} -> std::same_as<int> };
```
- Nested requirements - specify additional constraints
```cpp
template <typename T>
concept C = requires(T x) { requires std::same_as<sizeof(x), size_t>;};
```
**Note:** parameter list in a requires expression is optional.

**Note:** `requires` clause and expression can be on the same line leading to "Eko Eko" effect :)
```cpp
template <typename T> requires requires (T x) { x + x; }
    T add(T a, T b) {
        return a + b;
    }
```


### Coroutines

TODO


### Modules

TODO

### 3-way comparison operator <=> and operator==() = default

Three-way comparison operator is '<=>'.
It returns **an object** which can compared with 0.
- `(a <=> b) < 0` if `a < b`
- `(a <=> b) > 0` if `a > b`
- `(a <=> b) == 0` if `a` and `b` are equal/equivalent. 

The signature for defining comparison operator is:
- `R T::operator <=>(const T2 &b) const;` - for member function or 
- `R operator <=>(const T &a, const T2 &b);` for free function. 

R is one of the following:
- [std::strong_ordering](https://en.cppreference.com/w/cpp/utility/compare/strong_ordering) - e.g. to compare integral types
- [std::partial_ordering](https://en.cppreference.com/w/cpp/utility/compare/partial_ordering) - e.g. to compare floatin point types
- [std::weak_ordering](https://en.cppreference.com/w/cpp/utility/compare/wak_ordering) - e.g. to case insensitive compare strings 

See [here](https://en.cppreference.com/w/cpp/language/default_comparisons) for defaulted behavior of comparison operator!
It compares bases (left-to-right depth-first) and then non-static members (in declaration order). In addition `operator<=>()` also implies defaulted `operator==()` if there was none, so you can writing `auto operator<=>(const T&) const = default;` gives you all six comparison operations with member-wise semantics.

In addition rules say that:
- three-way comparison is called whenever values are compared using `<`, `>`, `<=`, `>=`, or `<=>`
- equality comparison is called whenever values are compared using `==` or `!=`

Which means for full set of comparison now you need to define two functions instead of 6 previously (2 with logic and 4 usually with boilerplate calling these 2)!

New lookup rules they can handle asymmetric cases wich means that single `T1::operator==(const T2&)` handles both `T1 == T2` and `T2 == T1` as well as `T1 != T2` and `T2 != T1`. Same asymmetry applies to `<=>`.

When writing generic comparison [std::compare_3way](https://doc.bccnsoft.com/docs/cppreference2018/en/cpp/algorithm/compare_3way.html) is usefull because it fallbacks to `==` and `<` if `<=>` is not defined.

See [Comparison.cpp](Comparison.cpp) for simple comparioson operator implementation in C++20 and prior to it.


### Designated initializers

Designated initialization allows initialization of members by their name using "dot syntax".

Initialization must be done in same order as members are declared, missing members are default initialized.

```cpp
    struct MyStructBase {
        double firstDouble = 10.5;
        double secondDouble = -5.5;
    };
    struct MyStruct {
        string str;
        int firstInteger = 21;
        int secondInteger = -1;
        MyStructBase base;
    };
    MyStruct myVar{ .secondInteger = 5, .base = { .secondDouble = -200.2 } };
    cout << myVar.str << std::endl; // empty string
    cout << myVar.firstInteger << std::endl; // 21
    cout << myVar.secondInteger << std::endl; // 5
    cout << myVar.base.firstDouble << std::endl; // 10.5
    cout << myVar.base.secondDouble << std::endl; // -200.2
```

**Note**: designated and non-designated initialization **cannot** be mixed.

For more info and differences compared to C programming language see [here](https://en.cppreference.com/w/cpp/language/aggregate_initialization#Designated_initializers).

### Aggregates initialized using parenthesis

Works the same as braced initialization except:
- narrowing conversions permitted
- designated initializers not allowed
- no lifetime extension for temporaries 
- no brace elision

This improvement allows usage aggregates with factory functions like `std::make_unique<>()/emplace()`.

```cpp
    struct MyStructBase {
        double firstDouble = 10.5;
        double secondDouble = -5.5;
    };
    struct MyStruct {
        string str;
        int firstInteger = 21;
        int secondInteger = -1;
        MyStructBase base;
    };

    auto structPtr = std::make_unique<MyStruct>("Tu sam", 42, -3, MyStructBase( 5.5, -10.4 ));
    cout << structPtr->str << std::endl; // empty string
    cout << structPtr->firstInteger << std::endl; // 21
    cout << structPtr->secondInteger << std::endl; // 5
    cout << structPtr->base.firstDouble << std::endl; // 10.5
    cout << structPtr->base.secondDouble << std::endl; // -200.2

```

**Note**: Arrays can also be initialized this way like `int arr1[](1, 2, 3);`.

### New and changed standard attributes

`[[no_unique_address]]` indicates that this data member does not have an distinct address, meaning compiler can optimize it away to occupy no space if member has empty type.

`[[nodiscard]]` can have a message associated like `[[nodiscard("Forget me not")]]` and is allowed to be applied to constructors.

`[[likely]]` and `[[unlikely]]` hint compiler which execution path can be better optimized. Can be applied to if/else statement as well as switch labels and/or loop (e.g. while).

```cpp
long factorial(long num) {
    if (num > 1) [[likely]]
        return num * fact(num - 1);
    else [[unlikely]]
        return 1;
}
```
### Initializer in range based for loop

Initialization statement is placed before range declaration and is separated by `;` and can be:
- expression statement
- a simple declaration (variable with initializer) with possibly many variables
- structured binding declaration 

**Note**: this feature should be used to prevent usage of dangling reference that can be created if range expressions contains temporaries.


```cpp
#include <iostream>
#include <vector>

using namespace std;

class Holder {
private:
	std::vector<int> items { 1, 2, 3, 4, 5 };
public:
	std::vector<int>& GetItems() { return items; }
	Holder() { cout << "Created" << std::endl; }
	~Holder() { cout << "Destroyed" << std::endl; items.clear(); }

};

Holder GetHolder() { return Holder(); }

int main()
{
	// doesn't work as expected because GetHolder() temporary is destroyed and dangling reference is used
	for (auto i : GetHolder().GetItems()) {
		cout << i << std::endl;
	}

	// works ok
	for (auto holder = GetHolder(); auto i : holder.GetItems()) {
		cout << i << std::endl;
	}
}
```

### Pack expansion in lambda init-capture

Capturing and moving the pack is made easier in C\++20, had to use tricks before.

```cpp
void g(int i, int j) {
	std::cout << i << " " << j << std::endl;
}

// C++17
template<class F, class... Args>
auto delay_apply(F&& f, Args&&... args) {
	return[f = std::forward<F>(f), tup = std::make_tuple(std::forward<Args>(args)...)]() -> decltype(auto) {
		return std::apply(f, tup);
	};
}

// C++20
template<typename F, typename... Args>
auto delay_call(F&& f, Args&&... args) {
	return[f = std::forward<F>(f), ...f_args = std::forward<Args>(args)]() -> decltype(auto) {
		return f(f_args...);
	};
}

int main()
{
	delay_call(g, 1, 2)();
	delay_apply(g, 4, 5)();
}
```

### Abbreviated function template

Placeholder type (`auto`) can be used in parameter list of function declaration. When used as such it actually declares function template (which can be specialized)!

```cpp
void printMe(auto a) // same as template<class T> void printMe(T)
{
	std::cout << a << std::endl;
}

template<>
void printMe<int>(int a) // specialization of template<class T> void printMe(T)
{
	std::cout << "int " << a << std::endl;
}

int main()
{
	printMe("abc"); // prints abc
	printMe(1); // prints int 1 - calls specialization
}
```

### consteval, constinit

Keyword `consteval` declares a function whose every call must (directly or indirectly) produce a compile time constant expression. This means that compile time evaluation of such function is guaranteed, unlike `constexpr` one which will be compile time if the arguments are compile time, otherwise will be run time. Calling `consteval` function with non-constant parameters results in an error!

Keyword `constinit` declares a static or `thread_local` variable that has static initialization (otherwise error). Unlike `constexpr`, `constinit`allows non-trivial destructors!

**Note**: Usage of `constinit` with `thread_local` tells the compiler that the variable is already initialized so it can be used without implicit code to check and initialize that is usuallz required on each usage!

```cpp
// Evaluated at compile-time if the input is known at compile-time, evaluated in run-time otherwise
constexpr unsigned constExprFactorial(unsigned n) {
    return n < 2 ? 1 : n * constExprFactorial(n - 1);
}

// Guaranteed to be evaluated at compile-time.
consteval unsigned constEvalFactorial(unsigned n) {
    return constExprFactorial(n); // can call constexpr here since n is guaranteed to be compile-time then constexpr fuction with that parameter is compile-time
}

static_assert(constExprFactorial(6) == 720);
static_assert(constEvalFactorial(6) == 720);

constinit thread_local unsigned y{ constEvalFactorial(5) }; 

int main(int argc, const char* []) 
{
    unsigned a = constExprFactorial(argc); // OK, evaluated at run time
    constexpr unsigned x{ constExprFactorial(4) }; // evaluated at compile time
    //  unsigned b = constEvalFactorial(argc); // argument is not a constant expression, error

    std::cout << a << std::endl;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}
```

### Compile time allocations in constexpr

Steps have been made to allow usage of containers in `constexpr`:
- `constexpr` and even `virtual constexpr` destructors for literal types
- calls to `std::allocator<T>::allocate()` and new expressions which results in a call to global new operator(s) new
- in other words, memory can be allocated at compile-time but it must be deallocated at compile-time!

If you need to use such data at run time you must store it in some non-allocating container (e.g. `std::array`)

```cpp
#include <iostream>
#include <array>

constexpr auto get_str()
{
    std::string s1{ "hello " };
    std::string s2{ "world" };
    std::string s3 = s1 + s2;
    return s3;
}

constexpr auto get_array()
{
    // we need size and data for std::array but
    // we cannot store get_str() into a variable here so
    // need to call it twice
    constexpr auto N = get_str().size();
    std::array<char, N> arr{};
    std::copy_n(get_str().data(), N, std::begin(arr));
    return arr;
}

static_assert(!get_str().empty());

// error because it holds data allocated at compile-time 
// constexpr auto str = get_str();

// OK, string is stored in std::array<char>
constexpr auto result = get_array();

int main(int argc, const char* []) 
{
    std::cout << result.data() << std::endl;
}
```


### Other improvements

- Array size deduction in new-expressions - `int* p2 = new int[]{1, 2, 3}` - prior to C++20 array size was mandatory in such expressions
- Bit-fields can now be default member initialized - `struct S{ int a : 1 {0} };` - prior to C++20 default constructor was needed
- `typename` can be omitted in more places
- `inline` is allowed to appear in nested namespace definitions
- 'using enum' can be used to introduce enum values into scope
- Class template argument deduction works now for alias templates
- signed integers are now guaranteed to be two's complement which makes some of the actions with left and right shifting now properly defined (previously undefined or implementation-defined behavior)
- char8_t type introduced to represent UTF-8 characters - same as as unsigned char but a **distinct ** type (so overloading can be done for this distinct type)
- some stronger unicode requirements
- some further relaxing/expanding regarding `constexpr`
- aggregate types cannot have user-declared constructors (previously allowed deleted or defaulted ones)
- it is no more necessary to use explicit deduction guides when using aggregates with class template argument deduction 
- improving range-based for-loop customization point rules - member `begin/end` are used only if both exist otherwise free ones are used (previously if one member was found compiler tried to use member ones even if other did not exist)
- lambdas can be used in unevaluated contexts, e.g `decltype()` or `typeid()` 
- stateless lambdas are default constructible and assignable which allows to use a type of a lambda to construct or assign it later which is important for some usages with standard library, e.g map comparator.
- template parameter list can be used to type names directly instead of `auto` in generic lambdas like `[]<typename T>(std::vector<T> vector){};`
- deprecated implicit lambda caputure of this using `[=]` and introduced explicit `[=, this]`
- virtual functions can now be `constexpr`, override function can have different `constexpr` specifier
- try-catch blocks are allowed inside `constexpr` functions but `throw` is not, hence, the catch block is simply ignored when evaluated at compile time
- one can change active member of `union` in `constexpr`, but cannot read inactive members
- `constexpr` constructor doesn't need to initialize all non-static data members anymore, but one can�t read values from such uninitialized members in `constexpr` context (you can set values to them though)
- `asm`-declaration can appear inside `constexpr` function provided that they are not evaluated at compile-time
- non-type template parameters are generalized to so-called structural types, one of:
    - scalar type(arithmetic, pointer, pointer-to-member, enumeration, std::nullptr_t)
    - lvalue reference
    - literal class type (types that can be used as a constexpr variable) with the following properties: all base classes and non-static data members are public and non-mutable
- structured bindings can have `[[maybe_unused]]` attribute as well as `static` and `thread_local` specifiers
- it�s possible to capture structured bindings in lambdas (bit-fields by value only). 
- improved structured bindings customization point finding rules so they don't capture `get` members that are not meant for this purpose (captured only if it�s a template and its first template parameter is a non-type template parameter)
- allow structured bindings to accessible (previously public) members
- new `__VA_OPT__` for variadic macros expands to nothing if `__VA_ARGS__` is empty and to its content otherwise, usefull to avoid situations where having "empty" in place of `__VA_ARGS__` would result in invalid syntax (e.g. call to function without parameters, or trailing comma after which there is nothing/empty...)
- explicitly defaulted functions can have different exception specifications
- class-specific `operator delete()` can take special `std::destroying_delete_t` tag - then compiler **will not ** call the object�s destructor before calling `operator delete()`, **it must be called manually** - usefull if value stored in object data is needed to free memory
- `explicit` can now take boolean argument making constructor/conversion conditionally explicit, similar to `noexcept(bool)`
- cconversion from array of known size to the reference to array of unknown size is allowed, overload resolution rules say matching size is better than overload with unknown or non-matching size
- rules allowing compiler to implicitly move instead of copy allow more use cases (like `return` and `throw`)
- conversion from pinter to `bool` is narrowing - produces error when used in scenarios where narrowing conversions are not allowed
- deprecate some uses of volatile
- deprecate comma operator in subscripts to be used in future versions in different manner
- copy constructor is preferred to list constructor when initializing from a **single element** having specialization of the class under construction
- lambdas within default member initializers can have capture list, their enclosing scope is the class scope


## New library features

### Concepts

Standard library provides some common concepts, complete list can be seen [here](https://en.cppreference.com/w/cpp/concepts).

### Span

Span is a lightweigt, non-owning abstraction (behaves like reference) of a pointer to continuous memory and a lenght. See it as generic replacement for pointer + lenght idiom that can also accept standard vector and array. Since lightweight you can pass it around by value....

It is analogous to `std::string_view` but span can mutate the referenced sequence, in addition it has some usefull methods on it like first, last, subspan, for complete list see [here](https://en.cppreference.com/w/cpp/container/span).

```cpp
void print(std::span<int> data)
{
    for (auto p : data)
        std::cout << p << std::endl;
}


int main(int argc, const char* []) 
{
    std::vector<int> v = { 1, 2, 3, 4 };
    std::array<int, 4> a = { 11, 12, 13, 14};
    int ra[4] = { 21, 22, 23, 24 };

    print(v);
    print(a);
    print(ra);

    auto sv = std::span{ v };

    std::cout << sv.empty() << std::endl;
    std::cout << sv.size() << std::endl;
    std::cout << sv.size_bytes() << std::endl;
    std::cout << sv.back() << std::endl;
    std::cout << sv.front() << std::endl;
    print(sv.first(2));
    print(sv.last(2));
    print(sv.subspan(1,2));
}
```

### Ranges

TODO

### Threading facilities

#### Auto joinable thread and thread stopping classes

`jthread` has the same general behavior as `thread`, except that it automatically rejoins on destruction and can be 
cancelled/stopped (which is also done in destructor). Its constructor accepts a function that can **optionaly** take 
`stop_token` as its first argument which allows the function to check if stop has been requested during its execution. 

- [stop_token](https://en.cppreference.com/w/cpp/thread/stop_token), [stop_source](https://en.cppreference.com/w/cpp/thread/stop_source) - used to signal that thread (or something else in future) needs to be stopped
- [stop_callback](https://en.cppreference.com/w/cpp/thread/stop_callback) - invoked when associated `stop_token` is requested to stop 

**Note**: `stop_callback`s that went out of scope are no longer invoked when their target is stopped (so we don't need to worry about dangling references, etc.....).

```cpp
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std::literals::chrono_literals;

// prints and sleeps until stopped
void crazyPrinter(std::stop_token stop) {
    std::cout << "crazyPrinter starting" << std::endl;
    while (!stop.stop_requested()) {
        std::cout << '*' << std::endl;
        std::this_thread::sleep_for(1s);
    }
    std::cout << "crazyPrinter ending" << std::endl;
}

// prints only when stopped
void lazyPrinter(std::stop_token stop, int start, int end) {
    std::cout << "lazyPrinter starting" << std::endl;

    std::mutex mutex;
    std::unique_lock lock(mutex);
    std::condition_variable_any().wait(lock, stop, [&stop] { return stop.stop_requested(); });

    for (int i = start; i < end; ++i)
        std::cout << i << std::endl;
    std::cout << "lazyPrinter ending" << std::endl;
}

int main(int argc, const char* [])
{
    std::jthread printer2(lazyPrinter, 1, 10);
    std::stop_callback callback2(printer2.get_stop_token(), [] {
        std::cout << "lazyPrinter callback" << std::endl;
    });

    std::this_thread::sleep_for(3s);

    printer2.request_stop();
    printer2.join();

    std::jthread printer1(crazyPrinter);
    std::stop_callback callback1(printer1.get_stop_token(), [] {
        std::cout << "crazyPrinter callback" << std::endl;
    });

    std::this_thread::sleep_for(3s);
    // destructor of printer1 will call join and request_stop for printer1
    // however callback1 will not be called because it is destroyed before printer1 destructor is called
}

```

#### Latch

Latch is a counter that blocks threads until it reaches 0. It is single use only (cannot be increased or reset) and can be decremented multiple times by same thread (unlike barrier).

Methods are:
- `wait` - wait for latch count to become 0
- `try_wait` - test if latch count is 0
- `count_down` - decrease count for some value (1 by default)
- `arrive_and_wait` - decrease count for some value (1 by default) and wait to become 0


```cpp
inline std::string get_current_time()
{
	return std::format("{:%X}", std::chrono::current_zone()->to_local(std::chrono::system_clock::now()));
}

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution distrib(1, 1000);

	array work_items = { "take out garbage", "do the laundry", "vacuume the room", "wash the dishes" };
	vector<jthread> workers{ std::size(work_items) };

	barrier sync_work{ 
		std::size(work_items), 
		[]() noexcept {
			osyncstream(cout) << get_current_time() << " Phase completed " << this_thread::get_id() << endl;
		} 
	};

	for (auto item : work_items) {
		workers.emplace_back([item, &sync_work, &distrib, &gen]() {
			for (auto i = 0; i < 10; ++i) {
				auto delay = distrib(gen);
				osyncstream(cout) << get_current_time() << " " << i << " Working on " << item << " " << delay << " " << this_thread::get_id() << endl;
				this_thread::sleep_for(chrono::milliseconds(delay*10));
				if (delay > 900) {
					osyncstream(cout) << get_current_time() << " " << i << " Giving up working on " << item << " " << this_thread::get_id() << endl;
					sync_work.arrive_and_drop();
					return;
				}
				else {
					osyncstream(cout) << get_current_time() << " " << i << " Waiting on " << item << " " << this_thread::get_id() << endl;
				}
				sync_work.arrive_and_wait();
			}
			osyncstream(cout) << get_current_time() << " Done working on " << item << " " << this_thread::get_id() << endl;
		});
	}
	return 0;
}
```

#### Barrier

Barriers block predefined number of threads and then unblocks them when expected number is reached. Unlike latch it can be reused again. In addition it invokes a completion function (must be `noexcept`) each time it unblocks threads.

Methods are:
- `arrive` - decrement expected count by some value (1 by default)
- `wait` - wait for expected count to reach 0
- `arrive_and_wait` - decrement expected count by 1 and wait for expected count to reach 0
- `arrive_and_drop` - decrement expected count by 1 and decrement expected number of thread in next run

```cpp
inline std::string get_current_time()
{
	return std::format("{:%X}", chrono::current_zone()->to_local(chrono::system_clock::now()));
}

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution distrib(1, 1000);

	array work_items = { "take out garbage", "do the laundry", "vacuume the room", "wash the dishes" };
	vector<jthread> workers{ std::size(work_items) };

	barrier completed_work{ 
		std::size(work_items), 
		[]() noexcept {
			osyncstream(cout) << get_current_time() << " Phase completed " << this_thread::get_id() << endl;
		} 
	};

	for (auto item : work_items) {
		workers.emplace_back([item, &completed_work, &distrib, &gen]() {
			for (auto i = 0; i < 10; ++i) {
				auto delay = distrib(gen);
				osyncstream(cout) << get_current_time() << " " << i << " Working on " << item << " " << delay << " " << this_thread::get_id() << endl;
				this_thread::sleep_for(chrono::milliseconds(delay*10));
				if (delay > 900) {
					osyncstream(cout) << get_current_time() << " " << i << " Giving up working on " << item << " " << this_thread::get_id() << endl;
					completed_work.arrive_and_drop();
					return;
				}
				else {
					osyncstream(cout) << get_current_time() << " " << i << " Waiting on " << item << " " << this_thread::get_id() << endl;
				}
				completed_work.arrive_and_wait();
			}
			osyncstream(cout) << get_current_time() << " Done working on " << item << " " << this_thread::get_id() << endl;
		});
	}
	return 0;
}
```

#### Semaphore

Semaphore is counting structure that blocks threads that do `acquire` if counter is 0. Least maximum value is provided 
as template parameter. Unlike mutex it allows more than one concurrent access to the same resource. In addition 
acquiring a semaphore can occur on a different thread than releasing the semaphore.

Semaphores can be used signalling/notifying rather than exclusion, the receiver(s) do `acquire` and the notifier(s) do `release`.

Methods are:
- constructor - specifies initial counter value
- `release` - increments the internal counter and unblocks acquirers
- `acquire` - decrements the internal counter or blocks until it can
- `try_acquire` - tries to decrement the internal counter without blocking
- `try_acquire_for` - tries to decrement the internal counter, blocking for up to a duration time
- `try_acquire_until` -	tries to decrement the internal counter, blocking until a point in time

**Note**: `binary_semaphore = std::counting_semaphore<1>`

```cpp
inline std::string get_current_time()
{
	return std::format("{:%X}", std::chrono::current_zone()->to_local(std::chrono::system_clock::now()));
}

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution distrib(1, 1000);

	array work_items = { "take out garbage", "do the laundry", "vacuume the room", "wash the dishes" };
	vector<jthread> workers{ std::size(work_items) };

	counting_semaphore<2> twoOnly{ 2 };

	for (auto item : work_items) {
		workers.emplace_back([item, &twoOnly, &distrib, &gen]() {
			for (auto i = 0; i < 10; ++i) {
				auto delay = distrib(gen); 
				twoOnly.acquire();
				osyncstream(cout) << get_current_time() << " " << i << " Start working on " << item << " " << delay << " " << this_thread::get_id() << endl;
				this_thread::sleep_for(chrono::milliseconds(delay * 10));
				osyncstream(cout) << get_current_time() << " " << i << " End working on " << item << " " << delay << " " << this_thread::get_id() << endl;
				twoOnly.release();
				// without this thread exhaustion seems to appear often (not always) in VS2022 (two threads finish work before two more even start)
				//this_thread::sleep_for(chrono::milliseconds(10));
			}
		});
	}
	return 0;
}
```

### Formatting library

This is an safe and extensible alternative to various printf functions. The basic function is [format](https://en.cppreference.com/w/cpp/utility/format/format) which just returns a formated string. Format specifiers are inside curly braces in format string.

```cpp
// C++ is cool
std::cout << std::format("{} is {}", "C++", "cool") << std::endl; 

// cool is C++
std::cout << std::format("{1} is {0}", "C++", "cool") << std::endl; 

// all ids must be present or none, mixing not allowed
// std::cout << std::format("{} is {1}", "C++", "cool") << std::endl; 
```

There are also:
- [format_to](https://en.cppreference.com/w/cpp/utility/format/format) - which writes directly to output iterator
- [format_to_n](https://en.cppreference.com/w/cpp/utility/format/format) - which writes directly to output iterator up to n characters
- [formatted_size](https://en.cppreference.com/w/cpp/utility/format/formatted_size) - which determines how many characters is needed

**Format string must be convertible to string view and be constant expression!** If not one must use [vformat](https://en.cppreference.com/w/cpp/utility/format/vformat) or [vformat_to](https://en.cppreference.com/w/cpp/utility/format/vformat_to) along with 

```cpp
template <typename... Args>
std::string dyna_print(std::string_view rt_fmt_str, Args&&... args) {
    // actually VS 2022 would allow std::format here too :)
	return std::vformat(rt_fmt_str, std::make_format_args(args...));
}

int main()
{
	std::cout << dyna_print("{} is {}", "C++", "cool") << std::endl;
	return 0;
}
```

Apart from index, curly braces can contain various format specifiers describing:
- type
- width, fill and alignment
- sign and precision

For detailed info see [Standard format specification](https://en.cppreference.com/w/cpp/utility/format/formatter).

Standard library provides formatting for "basic" types, string view and types from chrono. For other types you need to write custom [formatter](https://en.cppreference.com/w/cpp/utility/format/formatter) which must contain two methods `parse` and `format`.

```cpp
// cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <format>


template<class K, class T, class CharT>
struct std::formatter<std::pair<K, T>, CharT> {
    // parse context is iterator whose begin iterator points to the first character of the format specification (after 
    // the colon, or the first character after the opening brace if no colon)
    // it also contains closing brace and inner braces if any!!!
	auto parse(basic_format_parse_context<CharT>& _Parse_ctx) {
		_first_format = '{';
		_first_format += ':';
		auto it = begin(_Parse_ctx);
		for (; it != end(_Parse_ctx); ++it) {
			if (*it == ':') {
				_first_format += '}';
				break;
			}
			_first_format += *it;
            // we disregard possible inner braces here
			if (*it == '}')
				break;
		}

		if (*it == '}') {
			_second_format = _first_format;
		}
		else {
			_second_format = '{';
			_second_format += *it++; // add :
			for (; it != end(_Parse_ctx); ++it) {
				_second_format += *it;
                // we disregard possible inner braces here
				if (*it == '}')
					break;
			}
		}

		if (*it != '}')
			throw format_error("Missing '}' in format string.");

		return it;
	}

	template<class FormatContext>
	auto format(const std::pair<K, T>& t, FormatContext& fc) const {
		std::basic_string<CharT> format = static_cast<CharT>('(') + _first_format + static_cast<CharT>(',') + static_cast<CharT>(' ') + _second_format + static_cast<CharT>(')');
		return format_to(fc.out(), format, t.first, t.second);
	}

	std::basic_string<CharT> _first_format;
	std::basic_string<CharT> _second_format;
};

int main()
{
	std::pair<int, int> a_pair = std::make_pair(1, 2);
	std::pair<std::string, int> b_pair = std::make_pair("foo", 42);

	std::cout << std::format("{:+06d:+03d}", a_pair) << std::endl;
	std::wcout << std::format(L"{:>+6d:<-3d}", a_pair) << std::endl;
	std::cout << std::format("{:>6s:<+6d}", b_pair) << std::endl;
	return 0;
}
```

**Note**: All formatting methods will throw `format_error` in case invalid format strings or arguments, as well as any exception thrown by the formatters. It can also throw `bad_alloc`.

### Calendar and Time Zone additions to <chrono> library

Chrono library has many additions related to calendar and time zones as well as several new clocks, for full list see [reference](https://en.cppreference.com/w/cpp/chrono).

Short example demonstrates a tiny bit of this powerful library, for more see [examples](https://github.com/HowardHinnant/date/wiki/Examples-and-Recipes).

```cpp
using std::cout;
using std::format;
using namespace std::chrono;

cout << "TZDB version: " << get_tzdb().version << std::endl;

auto current_time = system_clock::now();
auto local_zoned_time = zoned_time{ current_zone(), current_time };
auto local_time = current_zone()->to_local(current_time); // or local_time = local_zoned_time.get_local_time();
auto ny_zoned_time = zoned_time{ "America/New_York", current_time };
auto phoenix_time = locate_zone("America/Phoenix")->to_local(current_time);
cout << "Current local time with zone: " << local_zoned_time << std::endl;
cout << "Current local time without zone: " << local_time << std::endl;
cout << "Current NY time with zone: " << ny_zoned_time << std::endl;
cout << "Current Phoenix time without zone: " << phoenix_time << std::endl;

cout << "Time difference to NY: " << local_zoned_time.get_local_time() - ny_zoned_time.get_local_time() << std::endl;
cout << "Time difference to NY formated: " << format("{:%H:%M}", local_zoned_time.get_local_time() - ny_zoned_time.get_local_time()) << std::endl;

zoned_time bd_zg_zoned{ "Europe/Zagreb", local_days{May / 21 / 1976} + 2h + 15min + 10s + 25ms };
zoned_time bd_ny_zoned{ "America/New_York", bd_zg_zoned };
cout << "BDay Zagreb: " << bd_zg_zoned << std::endl;
cout << "BDay NY: " << bd_ny_zoned << std::endl;

cout << "MS since midnight: " << round<seconds>(local_time - floor<days>(local_time)) << std::endl;
```


### Heterogeneous lookup in unordered associative containers

Similar feature to [heterogeneous lookup in ordered associative containers](cpp14.md#heterogeneous-lookup-in-ordered-associative-containers). 

For unordered associative containers (`unordered_map`, `unordered_multimap`, `unordered_set` and `unordered_multiset`) you are no longer required to pass the exact same object type as the key or element in member functions such as `find()` and `lower_bound()`, you can pass any type for which an overloaded `operator<` is defined.

**Note**: Feature is enabled on an opt-in basis when you specify the custom hash function and/or std::equal_to<> "diamond functor" comparator when declaring the container variable, if you use the default comparator, then the container behaves as it did in earlier specification.

```cpp
    struct string_hash {
        using is_transparent = void; // enables heterogenous lookup

        std::size_t operator()(const char* ch) const {
            return std::hash<std::string_view>{}(ch);
        }
        std::size_t operator()(std::string_view sv) const {
            return std::hash<std::string_view>{}(sv);
        }
        std::size_t operator()(const std::string& s) const {
            return std::hash<std::string>{}(s);
        }
    };
    std::string s = "This is my long string";

    std::unordered_map<std::string, int> ordinaryMap{};
    std::unordered_map<std::string, int, string_hash, std::equal_to<>> transparentMap{};

    std::cout << "Lookup in intMap with by const char*:\n";
    // temporary string is created and allocated here 
    std::cout << ordinaryMap.contains("This is my long string") << '\n';

    std::cout << "Lookup in trIntMap by const char*: \n";
    // no temporary string is created and allocated here 
    std::cout << transparentMap.contains("This is my long string") << '\n';

    std::cout << "Lookup in trIntMap by string: \n";
    // no temporary string is created and allocated here 
    std::cout << transparentMap.contains(s) << '\n';
```

### Other improvements
- `std::is_constant_evaluated()` you can check whether current invocation occurs within a constant-evaluated context, see [here](https://oleksandrkvl.github.io/2021/04/02/cpp-20-overview.html#is-const-eval) for some caveats
- Some bit oriented operations added including endian detection [in bit header](https://en.cppreference.com/w/cpp/header/bit)
- Some mathematical constants added [in numbers header](https://en.cppreference.com/w/cpp/numeric/constants)
- associative containers (set and map) now have `contains` member function to be used instead of finding and checking for end of iterator
- structured access to [source_location](https://en.cppreference.com/w/cpp/utility/source_location) has been added to replace `__FILE__`, `__LINE__`, ... usages (stack access comes in [C++ 23](cpp23.md#other-improvements)
- `make_shared` and `allocate_shared` now work for arrays
- `make_shared_overwrite`, `make_unique_for_overwrite` and `allocate_shared_overwrite` introduced to bypass extra initialization for non-object types
- string and string view have `starts_with` and `ends_with` method
- `basic_osyncstream` and various specializations like `osyncstream` can be used for synchronized output without interleaving, for small example see [Philosophers example](Philosophers.cpp)
- `bit_cast` added as a safe way to reinterpret types (less verbose and more efficient than memcpy() and compiler can optimize)
- `to_array` added to converts the array/"array-like" object to a `array`
- `to_address` added to obtain raw pointer from "fancy pointers"
- `to_midpoint` added to calculate mid point between numeric types or pointers without overflow
- `lerp` added to calculate linear interpolation/extrapolation (a + t(b-a)) with exactness and without overflow
- free standing `erase` and `erase_if` added to simplify uniform element erasure for most standard containers
- `is_bounded_array` and `is_unbounded_array` added for checks against the type of array
- `bind_front` added for wrapping a function with first parameters specified (`bind_back` comes in [C++ 23](cpp23.md#other-improvements)
- floating point types as well as `shared_ptr` and `weak_ptr` can be used with `atomic` as well as `atomic_ref` added
- `atomic` has added several `wait` and `notify` like methods (possible replacement for `atomic_flag`)
- `std::u8string` and `char8_t` added
- `c8rtomb` and `mbrtoc8` added (conversion from and to utf8)
- `make_obj_using_allocator` added
- `assume_aligned` added
- `ssize` added as signed counterpart of `size` for various containers and stuff
- `remove_cvref` added
- `polymorphic_allocator` added



## Some of the references
- [Modernes C++](https://www.modernescpp.com/)
- [C++ compiler support](https://en.cppreference.com/w/cpp/compiler_support)
- [C++ Stories](https://www.cppstories.com/tags/cpp20/)
- [Anthony Calandra - Modern CPP Features](https://github.com/AnthonyCalandra/modern-cpp-features)
- [Oleksandr Koval's blog](https://oleksandrkvl.github.io/2021/04/02/cpp-20-overview.html)
- [CPP Reference](https://en.cppreference.com/w/cpp/20)
