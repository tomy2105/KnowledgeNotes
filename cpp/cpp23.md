# CPP 23

<!-- toc -->

- [New language features](#new-language-features)
  * [if with consteval](#if-with-consteval)
  * [Misc improvements](#misc-improvements)
- [New library features](#new-library-features)
  * [monadic optional](#monadic-optional)
  * [expected](#expected)
  * [Ranges improvements](#ranges-improvements)
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

### monadic optional

Optional has 3 methods add to enable functional style programming:

- and_then
- or_else
- transform

### expected

Error handling type similar to optional.


### Ranges improvements

- `std::ranges::starts_with` and `std::ranges::ends_with` is added
- `std::ranges::shift_left` and `std::ranges::shift_right` is added
- `std::ranges::fold_left` and `std::ranges::fold_right` is added
- `std::ranges::iota` is added
- `std::ranges::to` is added
- `std::ranges::views::zip` is added
- `std::ranges::views::zip_transform` is added
- `std::ranges::views::adjacent` is added
- `std::ranges::views::adjacent_transform` is added
- `std::ranges::views::join_with` is added
- `std::ranges::views::slide` is added
- `std::ranges::views::chunk` is added
- `std::ranges::views::chunk_by` is added
- `std::ranges::views::repeat` is added
- `std::ranges::views::cartesian_product` is added
- `std::ranges::views::as_const` is added
- `std::ranges::views::as_rvalue` is added
- `std::ranges::views::stride` is added


### Other improvements
- access currently executing [stack trace](https://en.cppreference.com/w/cpp/utility/basic_stacktrace) has been added
- `bind_back` added for wrapping a function with last parameters specified 
- compatibility macro _Atomic provided such that `_Atomic(T)` is identical to `atomic<T>`
- more functions (`erase`, `extract`, `insert`, `insert_or_assign`, `operator[]`, `bucket`) aware of transparent/heterogenous searching
- garabage collector related basics introduced in [C++11](cpp11.md#allow-garbage-collected-implementations) are removed
- `string` and `string_view` have `contains` method added
- 


## Some of the references
- [CPP Reference](https://en.cppreference.com/)
