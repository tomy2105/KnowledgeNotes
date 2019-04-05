#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

class enclosing 
{
	auto some_func()
	{
		return 5;
	}

public:
	void process()
	{
		std::vector<int> some_list{ 1, 2, 3, 4, 5 };
		int total = 0;
		int value = 5;
		std::for_each(begin(some_list), end(some_list), [&, value, this](int x) {
			total += x * value * this->some_func();
		});
		std::cout << total << std::endl;
	}
};

void use (int i, int x) 
{
	std::cout << i << " " << x << std::endl;
}

struct ClassMember {
	int x = 0;
	void f() {
		int i = 0;
		auto l1 = [=] { use(i, x); }; // captures a copy of i and a copy of the this pointer
		i = 1; x = 1; l1(); // calls use(0,1), as if i by copy and x by reference

		auto l2 = [i, this] { use(i, x); }; // same as above, made explicit
		i = 2; x = 2; l2(); // calls use(1,2), as if i by copy and x by reference

		auto l3 = [&] { use(i, x); }; // captures i by reference and a copy of the this pointer
		i = 3; x = 3; l3(); // calls use(3,3), as if i and x are both by reference

		auto l4 = [i, *this]{ use(i, x); }; // makes a copy of *this, including a copy of x
		i = 4; x = 4; l4(); // calls use(3,3), as if i and x are both by copy
	}
};

double eval(std::function <double(double)> f, double x = 2.0)
{
	return f(x);
}

int main()
{
	std::cout << "Ordinary lambda " << std::endl;

	std::vector<int> vc = { 1, 2, 3, 4, 5, 6, 7 };
	int x = 5;
	vc.erase(std::remove_if(vc.begin(), vc.end(), [x](int n) { return n < x; }), vc.end());

	std::for_each(vc.begin(), vc.end(), [](int i) { std::cout << i << ' '; });
	std::cout << std::endl;


	std::cout << std::endl << "Ordinary lambda with this capture" << std::endl;
	enclosing().process();

	std::cout << std::endl << "Class member implicit capture" << std::endl;
	ClassMember().f();

	std::cout << std::endl << "Storing lambdas and invoking later" << std::endl;
	std::function<double(double)> f0 = [](double x) {return 1; }; // when storing into function unnecessary overhead may incur 
	auto                          f1 = [](double x) {return x; };
	decltype(f0)                  fa[3] = { f0,f1,[](double x) {return x * x; } };
	std::vector<decltype(f0)>     fv = { f0,f1, [](double x) {return x * x; } };

	for (auto &f : fv)
		std::cout << f(2.0) << std::endl;

	for (auto &f : fa)
		std::cout << f(2.0) << std::endl;

	std::cout << eval(f0) << std::endl;
	std::cout << eval(f1) << std::endl;
	std::cout << eval([](double x) {return x * x; }) << std::endl;

	std::cout << std::endl << "Nested lambdas and capturing" << std::endl;
	int a = 1, b = 1, c = 1;

	auto m1 = [a, &b, &c]() mutable {
		auto m2 = [a, b, &c]() mutable {
			std::cout << a << b << c << '\n';
			a = 4; b = 4; c = 4;
		};
		a = 3; b = 3; c = 3;
		m2();
	};

	a = 2; b = 2; c = 2;

	m1();                             // calls m2() and prints 123
	std::cout << a << b << c << '\n'; // prints 234

	return 0;
}
