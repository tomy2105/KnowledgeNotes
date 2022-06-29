#include <iostream>
#include <thread>
#include <mutex>
#include <array>
#include <atomic>
#include <map>
#include <sstream>
#include <condition_variable>
#include <vector>

#ifdef __cpp_lib_syncbuf
#include <syncstream>
class osyncstream : public std::osyncstream
{
public:
	osyncstream() : std::osyncstream(std::cout) {}
};
#else
class osyncstream : public std::stringstream
{
public:
	osyncstream() = default;
	~osyncstream()
	{
		std::cout << std::stringstream::str();
	}
};
#endif

template <class User>
class Fork : public std::mutex {
public:
	Fork() : forkId(++cnt) {};

	void lock() {
		osyncstream() << "Philosopher " << User::getIdFromThread() << " taking fork " << forkId << std::endl;
		std::mutex::lock();
		osyncstream() << "Philosopher " << User::getIdFromThread() << " took fork " << forkId << std::endl;
	}

	void unlock() {
		osyncstream() << "Philosopher " << User::getIdFromThread() << " leaving fork " << forkId << std::endl;
		std::mutex::unlock();
	}

	bool try_lock() {
		osyncstream() << "Philosopher " << User::getIdFromThread() << " tries taking fork " << forkId << std::endl;
		bool res = std::mutex::try_lock();
		osyncstream() << "Philosopher " << User::getIdFromThread() << " " << (res ? "took" : "did not take") << " fork " << forkId << std::endl;
		return res;
	}

	unsigned getId() const
	{
		return forkId;
	}

private:
	unsigned forkId;

	static std::atomic<unsigned> cnt;
};


class Philosopher {
public:
	Philosopher(Fork<Philosopher>& fork1_, Fork<Philosopher>& fork2_) : philospherId(++cnt), fork1(fork1_), fork2(fork2_) {};

	void eat(unsigned numBites, unsigned biteDuration)
	{
		threadPhilosopherId = philospherId;

		osyncstream() << "Philosopher " << philospherId << " waiting for start" << std::endl;

		{
			std::unique_lock<std::mutex> lck(staticMtx);
			start.wait(lck);
		}

		osyncstream() << "Philosopher " << philospherId << " starting to eat" << std::endl;
		auto t0 = std::chrono::high_resolution_clock::now();

		for (unsigned biteNum = 1; biteNum <= numBites; biteNum++) {
			{
				// scoped_lock worries about deadlocking so we don't have to :) :) :)
				// on the other hand there will be a some number of try_lock and locks obtained and then released (because other lock has not been obtained) when used
				// check here for extremely nice article about that: https://howardhinnant.github.io/dining_philosophers.html
				// scoped lock is introduced in C++17
				std::scoped_lock lockForks(fork1, fork2);
				osyncstream() << "Philosopher " << philospherId << " starts eating bite " << biteNum << " with fork " << fork1.getId() << " and fork " << fork2.getId() << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(biteDuration));
				osyncstream() << "Philosopher " << philospherId << " finishes eating bite " << biteNum << std::endl;
			}
		}

		auto t1 = std::chrono::high_resolution_clock::now();
		osyncstream() << "Philosopher " << philospherId << " finished eating in " << std::chrono::duration<float>(t1 - t0).count() << " seconds" << std::endl;
	}

	void eat_ordered(unsigned numBites, unsigned biteDuration)
	{
		threadPhilosopherId = philospherId;

		osyncstream() << "Philosopher " << philospherId << " waiting for start" << std::endl;

		{
			std::unique_lock<std::mutex> lck(staticMtx);
			start.wait(lck);
		}

		osyncstream() << "Philosopher " << philospherId << " starting to eat" << std::endl;
		auto t0 = std::chrono::high_resolution_clock::now();

		for (unsigned biteNum = 1; biteNum <= numBites; biteNum++) {
			{
				// making sure lock acquire is ordered
				if (fork1.native_handle() < fork2.native_handle()) {
					fork1.lock();
					fork2.lock();
				}
				else {
					fork2.lock();
					fork1.lock();
				}
				// making sure already owned locks are released at the end of the scope
				std::lock_guard<Fork<Philosopher>> lock1(fork1, std::adopt_lock);
				std::lock_guard<Fork<Philosopher>> lock2(fork2, std::adopt_lock);

				osyncstream() << "Philosopher " << philospherId << " starts eating bite " << biteNum << " with fork " << fork1.getId() << " and fork " << fork2.getId() << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(biteDuration));
				osyncstream() << "Philosopher " << philospherId << " finishes eating bite " << biteNum << std::endl;
			}
		}

		auto t1 = std::chrono::high_resolution_clock::now();
		osyncstream() << "Philosopher " << philospherId << " finished eating in " << std::chrono::duration<float>(t1 - t0).count() << " seconds" << std::endl;
	}

	static unsigned getIdFromThread()
	{
		return threadPhilosopherId;
	}

	static void signalStart()
	{
		osyncstream() << "Starting all philosophers" << std::endl;
		start.notify_all();
	}
private:
	unsigned philospherId;
	Fork<Philosopher>& fork1;
	Fork<Philosopher>& fork2;

	static std::atomic<unsigned> cnt;
	static thread_local unsigned threadPhilosopherId;
	static std::mutex staticMtx;
	static std::condition_variable start;
};

template<class User> std::atomic<unsigned> Fork<User>::cnt;
std::atomic<unsigned> Philosopher::cnt;

thread_local unsigned Philosopher::threadPhilosopherId = -1;

std::mutex Philosopher::staticMtx;
std::condition_variable Philosopher::start;


int main()
{
	const unsigned NUM_PHILOSOPHERS = 10;
	const unsigned NUM_BITES = 10;
	const unsigned BITE_DURATION = 1;
	std::vector<Philosopher> philosophers;
#ifdef __cpp_lib_jthread
	std::vector<std::jthread> philosopherThreadObjects;
#else
	std::vector<std::thread> philosopherThreadObjects;
#endif
	std::array<Fork<Philosopher>, NUM_PHILOSOPHERS> forks;

	for (unsigned i = 0; i < NUM_PHILOSOPHERS; i++) {
		philosophers.emplace_back(forks[i % NUM_PHILOSOPHERS], forks[(i + 1) % NUM_PHILOSOPHERS]);
		philosopherThreadObjects.emplace_back(&Philosopher::eat, philosophers[i], NUM_BITES, BITE_DURATION);
	}
	std::this_thread::sleep_for(std::chrono::seconds(BITE_DURATION));
	Philosopher::signalStart();

#ifndef __cpp_lib_jthread
	for (auto& th : philosopherThreadObjects) {
		th.join();
	}
#endif
	// jthread automatically joins when jthread object is destroyed during clearing of the vector
	philosopherThreadObjects.clear();
	philosophers.clear();

	for (unsigned i = 0; i < NUM_PHILOSOPHERS; i++) {
		philosophers.emplace_back(forks[i % NUM_PHILOSOPHERS], forks[(i + 1) % NUM_PHILOSOPHERS]);
		philosopherThreadObjects.emplace_back(&Philosopher::eat_ordered, philosophers[i], NUM_BITES, BITE_DURATION);
	}
	std::this_thread::sleep_for(std::chrono::seconds(BITE_DURATION));
	Philosopher::signalStart();

#ifndef __cpp_lib_jthread
	for (auto& th : philosopherThreadObjects) {
		th.join();
	}
#endif
	// jthread automatically joins when jthread object is destroyed during destroying of the vector
}
