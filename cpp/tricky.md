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
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTgwNzU0NjMxNiwtMTYxMzU3MjAyNl19
-->