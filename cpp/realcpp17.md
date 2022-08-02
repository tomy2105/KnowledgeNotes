# Moving real world product to C++17 in Visual Studio 2022

A small number of changes that were needed to compile "smallish" real world product (approx 1M lines of code, some relatively new, some 20+ years old) on C\++17 in Visual Studio 2022 (previously C++11 and Visual Studio 2017 used).

Since it is rather old code base, Visual Studio **Conformance Mode** is set to default (meaning **No** = `/permissive`, no `-` here!!!).

<!-- toc -->

- [auto_ptr](#auto_ptr)
- [ptr_fun, unary_function and binary_function](#ptr_fun-unary_function-and-binary_function)
- [bind1st and bind2nd](#bind1st-and-bind2nd)
- [strstream](#strstream)
- [std::allocator's destroy, allocate and construct](#stdallocators-destroy-allocate-and-construct)
- [std::iterator](#stditerator)
- [std::uncaught_exception](#stduncaught_exception)
- [nodiscard attribute](#nodiscard-attribute)
- [done?](#done)

<!-- tocstop -->

## auto_ptr

First step here was to change all usage of `auto_ptr` to `unique_ptr`. This covered 80% of the cases.

If greeted with error message about using deleted functions then change it to `shared_ptr`.

**In all cases try to understand the pointer ownership behind usage of `auto_ptr`, do not just change blindly!**

In small number of cases was able to completely remove `auto_ptr` usage with some other idiom. My, not so, favorite example was singleton patter written by some outsourced developer 10+ years ago (code is approximate and was split between header and implementation cpp file).

```cpp
class singleton
{
private:
	typedef std::auto_ptr<singleton> singletonPtr;

	static singletonPtr& GetInstance();
		static singletonPtr theSink(new singleton);
		return theSink;
	}

	// appropriate default and deleted constructors and copy operators here
public:
	static singleton& Instance() { return *GetInstance(); }
	static const singleton& constInstance() { return Instance(); }
};
```

Needless to say this usage of `auto_ptr` has been completely removed with standard singleton idiom.

```cpp
class singleton
{
private:
	// appropriate default and deleted constructors and copy operators here
public:
	static singleton& Instance() { 
		static singleton instance;
		return instance;
	}
	static const singleton& constInstance() { return Instance(); }
};
```

If you are forced to remain with `auto_ptr` (for example you have some 3rd party library that has not upgraded yet) you can use `_HAS_AUTO_PTR_ETC=1` define in project properties.

## ptr_fun, unary_function and binary_function

This is the easiest one to deal with. `ptr_fun`, `unary_function`, `binary_function` are no longer needed so just remove them.

If you are forced to remain with those functions (for example you have some 3rd party library that has not upgraded yet) you can use empty template instead.

## bind1st and bind2nd

`bind1st` and `bind2nd` are completely removed from the standard but are luckily easy to rewrites using `bind`

For example:

- `bind1st(memberObject::CompareName, strBaseName.c_str())` is rewritten as `bind(memberObject::CompareName, strBaseName.c_str(), std::placeholders::_1 )`

-  and `bind2nd(Session::AddMemberToObject, &m_rootObject))` as `bind(Session::AddMemberToObject, std::placeholders::_1, &m_rootObject))`

## strstream

`strstream` is completely removed but easily replaced with `stringstream`.
Just `include <sstream>` instead of `include <strstream>` and replace `strstream` type/class with `stringstream`.

## std::allocator's destroy, allocate and construct

Methods `destroy`, `allocate` and `construct` of `std::allocator` have been deprecated in C\++17 (and I think will be removed in C++20 turning this warning into error). Easily replaced with `std::allocator_traits` counterparts.

## std::iterator 

Usage of `std::iterator` as a base class has been deprecated in C\++17 (and I think will be removed in C++20 turning this warning into error). Easily fixed by adding stuff that is inside of `std::iterator` inside your won class.

```cpp

struct iterator : public std::iterator<std::forward_iterator_tag, T>
{
//....
}

```

change to

```cpp
struct iterator
{
    using iterator_category = std::forward_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;
//....
}

```

## std::uncaught_exception

`std::uncaught_exception()` has been deprecated in C\++17 (and I think will be removed in C++20 turning this warning into error). t is superseded by `std::uncaught_exceptions()`, **plural**.

## nodiscard attribute

Usage of `nodiscard` attribute in standard library code produces warnings which revelaed some interesting, probably well known, errors while using standard library.

Most numerous was usage of collection `empty()` method instead of `clear()` method.

Second was usage of `remove_if` and `unique` algorithms without calling `erase` after them.

## done?

The code compiles under Visual Studio 2022 but with **Conformance Mode** set to default (meaning **No**).

Setting language standard to C\++20 implicitly sets this to **Yes** (although you can set it back to **No** if absolutely needed).

So, setting **Conformance Mode** to **Yes** is my next step, wish me luck :smile: (I'll need it because a lot of old code is not `const` correct so when string constants in code become `const char*` and not `char *` it will be fun time for me :()
