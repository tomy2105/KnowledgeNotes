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

Allows binding std::tuple, array or a non-static data member directly to variables. 

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

### Removal of auto_ptr and trigraphs

Both features totaly removed from the standard.

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

## Some of the references

- [Modernes C++](https://www.modernescpp.com/)




