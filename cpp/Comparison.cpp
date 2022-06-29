// cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct WrapperTwo
{
	int y;
};

struct WrapperOne
{
	int x;
};

bool operator==(const WrapperOne& w1, const WrapperTwo& w2)
{
	return w1.x == w2.y;
}

#ifdef __cpp_lib_three_way_comparison
std::strong_ordering operator<=>(const WrapperOne& w1, const WrapperTwo& w2)
{
	return w1.x <=> w2.y;
}
#endif

#ifndef __cpp_lib_three_way_comparison
// for C++17 and earlier in addition to == we need !=, <, <=, >, >= and asymmetric versions of each

bool operator==(const WrapperTwo& w2, const WrapperOne& w1)
{
	return w1 == w2;
}

bool operator!=(const WrapperOne& w1, const WrapperTwo& w2)
{
	return w1.x != w2.y;
}

bool operator!=(const WrapperTwo& w2, const WrapperOne& w1)
{
	return w1 != w2;
}

bool operator<(const WrapperOne& w1, const WrapperTwo& w2)
{
	return w1.x < w2.y;
}

bool operator<=(const WrapperOne& w1, const WrapperTwo& w2)
{
	return w1 < w2 || w1 == w2;
}

bool operator>(const WrapperOne& w1, const WrapperTwo& w2)
{
	return !(w1 < w2) && w1 != w2;
}

bool operator>=(const WrapperOne& w1, const WrapperTwo& w2)
{
	return !(w1 < w2);
}

bool operator<(const WrapperTwo& w2, const WrapperOne& w1)
{
	return w1 >= w2;
}

bool operator<=(const WrapperTwo& w2, const WrapperOne& w1)
{
	return w1 > w2;
}

bool operator>(const WrapperTwo& w2, const WrapperOne& w1)
{
	return w1 <= w2;
}

bool operator>=(const WrapperTwo& w2, const WrapperOne& w1)
{
	return w1 < w2;
}
#endif

int main()
{
	WrapperOne w1{ 1 };
	WrapperTwo w2{ 2 };

	std::cout << (w1 < w2) << std::endl;
	std::cout << (w1 <= w2) << std::endl;
	std::cout << (w1 > w2) << std::endl;
	std::cout << (w1 >= w2) << std::endl;
	std::cout << (w1 == w2) << std::endl;
	std::cout << (w1 != w2) << std::endl;

	std::cout << (w2 < w1) << std::endl;
	std::cout << (w2 <= w1) << std::endl;
	std::cout << (w2 > w1) << std::endl;
	std::cout << (w2 >= w1) << std::endl;
	std::cout << (w2 == w1) << std::endl;
	std::cout << (w2 != w1) << std::endl;
}

