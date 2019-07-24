#include <vector>
#include <algorithm>
#include <execution>
#include <iostream>
#include <iterator>
#include <chrono>
#include <random>
#include <limits>

int main()
{
	std::random_device rnd_device;
	std::mt19937 mersenne_engine{ rnd_device() }; 
	
	unsigned long l = 0;
	auto gen = [&l]() {
		return l++;
	};

	std::vector<unsigned long> v(10000000);
	std::generate(std::begin(v), std::end(v), gen);
	std::shuffle(std::begin(v), std::end(v), mersenne_engine);

	// standard sequential sort
	std::vector v1 = v;
	auto start = std::chrono::high_resolution_clock::now();
	std::sort(v1.begin(), v1.end());
	std::cout << (std::chrono::high_resolution_clock::now() - start).count() / 1000000000.0 << std::endl;

	// sequential execution
	std::vector v2 = v;
	start = std::chrono::high_resolution_clock::now();
	std::sort(std::execution::seq, v2.begin(), v2.end());
	std::cout << (std::chrono::high_resolution_clock::now() - start).count() / 1000000000.0 << std::endl;

	// permitting parallel execution
	std::vector v3 = v;
	start = std::chrono::high_resolution_clock::now();
	std::sort(std::execution::par, v3.begin(), v3.end());
	std::cout << (std::chrono::high_resolution_clock::now() - start).count() / 1000000000.0 << std::endl;

	// permitting parallel and vectorized execution
	std::vector v4 = v;
	start = std::chrono::high_resolution_clock::now();
	std::sort(std::execution::par_unseq, v4.begin(), v4.end());
	std::cout << (std::chrono::high_resolution_clock::now() - start).count() / 1000000000.0 << std::endl;
}