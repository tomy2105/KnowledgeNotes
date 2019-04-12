#include <iostream>
#include <thread>
#include <mutex>
#include <array>
#include <atomic>
#include <map>
#include <sstream>
#include <condition_variable>

class osyncstream : public std::stringstream
{
public:
	osyncstream() = default;
	~osyncstream()
	{
		std::cout << std::stringstream::str();
	}
};

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
	Philosopher(Fork<Philosopher>& fork1_, Fork<Philosopher>& fork2_) :fork1(fork1_), fork2(fork2_), philospherId(++cnt) {};

	void eat(unsigned numBites, unsigned biteDuration) 
	{
		{
			std::lock_guard lck(staticMtx);
			threadToIdMap[std::this_thread::get_id()] = philospherId;
		}

		osyncstream() << "Philosopher " << philospherId << " waiting for start" << std::endl;

		{
			std::unique_lock lck(staticMtx);
			start.wait(lck);
		}

		for (unsigned biteNum = 1; biteNum <= numBites; biteNum++) {
			{
				// scoped_lock worries about deadlocking so we don't have to :) :) :)
				std::scoped_lock lockForks(fork1, fork2);
				osyncstream() << "Philosopher " << philospherId << " starts eating bite " << biteNum << " with fork " << fork1.getId() << " and fork " << fork2.getId() << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(biteDuration));
				osyncstream() << "Philosopher " << philospherId << " finishes eating" << std::endl;
			}
		}

		{
			std::lock_guard lck(staticMtx);
			threadToIdMap.erase(threadToIdMap.find(std::this_thread::get_id()));
		}
	}

	unsigned getId() const
	{
		return philospherId;
	}

	static unsigned getIdFromThread()
	{
		std::lock_guard lck(staticMtx);
		return threadToIdMap.at(std::this_thread::get_id());
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
	static std::map<std::thread::id, unsigned> threadToIdMap;
	static std::mutex staticMtx;
	static std::condition_variable start;
};

std::atomic<unsigned> Fork<Philosopher>::cnt = 0;
std::atomic<unsigned> Philosopher::cnt = 0;
std::map<std::thread::id, unsigned> Philosopher::threadToIdMap;
std::mutex Philosopher::staticMtx;
std::condition_variable Philosopher::start;


int main()
{
	const unsigned NUM_PHILOSOPHERS = 10;
	const unsigned NUM_BITES = 10;
	const unsigned BITE_DURATION = 1;
	std::vector<Philosopher> philosophers;
	std::vector<std::thread> philosopherThreadObjects;
	std::array<Fork<Philosopher>, NUM_PHILOSOPHERS> forks;

	for (auto i = 0; i < NUM_PHILOSOPHERS; i++) {
		philosophers.emplace_back(forks[i % NUM_PHILOSOPHERS], forks[(i + 1) % NUM_PHILOSOPHERS]);
		philosopherThreadObjects.emplace_back(&Philosopher::eat, philosophers[i], NUM_BITES, BITE_DURATION);
	}
	std::this_thread::sleep_for(std::chrono::seconds(BITE_DURATION));
	Philosopher::signalStart();

	for (auto& th : philosopherThreadObjects) {
		th.join();
	}
}