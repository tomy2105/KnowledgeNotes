#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

#ifndef __PRETTY_FUNCTION__
	#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

// recursion stopper
void print() {}

// The recursive case: we take one parameter, alongside
// some other parameters, and print one and then recursively rest.
template <typename T, typename... Rest>
void print(T&& t, Rest&&... rest) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "void print(" << typeid(T).name() << ", " << sizeof...(Rest) <<")" << std::endl;
	std::cout << t << std::endl;
	print(rest...);
}


template <typename T>
int printWithReturn(T t) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	std::cout << "void printWithReturn(" << typeid(T).name() << ")" << std::endl;
	std::cout << t << std::endl;

	return 0;
}

template<typename... Args> inline void dummy(Args&&...) {}
template<typename... Args> inline void expand(Args&&... args)
{
	dummy(printWithReturn(args)...); // requires non void return, order of evaluation not guaranteed
}

struct dummyStruct
{
	template<typename ...T> dummyStruct(T...) {}
};
template<typename... Args> inline void expandStruct(Args&&... args)
{
	dummyStruct{ printWithReturn(args)... }; // requires non void return, order of evaluation guaranteed
}
template<typename... Args> inline void expandStruct2(Args&&... args)
{
	dummyStruct{ (print(args), 1)... }; // non void return done via comma operator, order of evaluation guaranteed
}
template<typename... Args> inline void expandStruct3(Args&&... args)
{
	dummyStruct{ ([&]() { std::cout << args << std::endl; }(), 1)... }; // lamda used instead of separate function
}
template<typename... Args> inline void expandStruct4(Args&&... args)
{
	dummyStruct{ (std::cout << args << std::endl, 1)... }; // expression used instead of separate function
}


// recursion for tuple definition
template <class... Ts> struct tuple {};

template <class T, class... Ts>
struct tuple<T, Ts...> : tuple<Ts...> {
	tuple(T t, Ts... ts) : tuple<Ts...>(ts...), tail(t) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	T tail;
};


// recursion for tuple type definition
template <size_t, class> struct elem_type_holder;

template <class T, class... Ts>
struct elem_type_holder<0, tuple<T, Ts...>> {
	typedef T type;
};

template <size_t k, class T, class... Ts>
struct elem_type_holder<k, tuple<T, Ts...>> {
	typedef typename elem_type_holder<k - 1, tuple<Ts...>>::type type;
};


// recursion for tuple get definition
template <size_t k, class... Ts>
typename std::enable_if<
	k == 0, typename elem_type_holder<0, tuple<Ts...>>::type&>::type
	get(tuple<Ts...>& t) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return t.tail;
}

template <size_t k, class T, class... Ts>
typename std::enable_if<
	k != 0, typename elem_type_holder<k, tuple<T, Ts...>>::type&>::type
	get(tuple<T, Ts...>& t) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	tuple<Ts...>& base = t;
	return get<k - 1>(base);
}

int main()
{
	print(1, 2.1f, 3.2, 4l, "555");

	expand(42, "answer", true);
	expandStruct(43, "no answer", false);
	expandStruct2(44, "with answer", true);
	expandStruct3(45, "wrong answer", false);
	expandStruct4(46, "right answer", true);

	tuple<double, uint64_t, const char*> t1(12.2, 42, "big");

	std::cout << typeid(elem_type_holder <1, tuple<double, uint64_t, const char*>>::type).name() << std::endl;

	std::cout << get<0>(t1) << std::endl;
	std::cout << get<1>(t1) << std::endl;
	std::cout << get<2>(t1) << std::endl;

	get<1>(t1) = 103;
	std::cout << get<1>(t1) << std::endl;
}

