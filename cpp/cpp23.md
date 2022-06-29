# CPP 23

<!-- toc -->

- [New language features](#new-language-features)
  * [if with consteval](#if-with-consteval)
  * [Misc improvements](#misc-improvements)
- [New library features](#new-library-features)
  * [Other improvements](#other-improvements)
- [Some of the references](#some-of-the-references)

<!-- tocstop -->

## New language features

### if with consteval

If statememnt can be written with `consteval` keyword to executed different code depending whether if function is executed during compile time or during run-time.

```cpp
constexpr bool is_constant_evaluated() noexcept {
    if consteval { return true; }
    else { return false; }
}

constexpr bool is_runtime_evaluated() noexcept {
    if not consteval { return true; }
    else { return false; }
}
```

### Misc improvements

- Init statement in range based for loop can be alias declaration

## New library features

### Other improvements
- access currently executing [stack trace](https://en.cppreference.com/w/cpp/utility/basic_stacktrace) has been added
- `bind_back` added for wrapping a function with last parameters specified 
- compatibility macro _Atomic provided such that `_Atomic(T)` is identical to `atomic<T>`
- more functions (`erase`, `extract`, `insert`, `insert_or_assign`, `operator[]`, `bucket`) aware of transparent/heterogenous searching
- garabage collector related basics introduced in [C++11](cpp11.md#allow-garbage-collected-implementations) are removed


## Some of the references
- [CPP Reference](https://en.cppreference.com/)
- [C++ Stories](https://www.cppstories.com/tags/cpp20/)
