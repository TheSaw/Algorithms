#ifndef ALGORITHMS_TIMER_H_
#define ALGORITHMS_TIMER_H_

#include <chrono>
#include <iostream>
#include <string>

class Timer
{
public:
	void start();
	void stop(const std::string &text);

private:
	std::chrono::time_point<std::chrono::steady_clock> stamp;
};

void Timer::start()
{
	stamp = std::chrono::steady_clock::now();
}

void Timer::stop(const std::string &text)
{
	auto end = std::chrono::steady_clock::now();
	auto diff = end - stamp;
	std::chrono::duration<int, std::milli> diff_sec = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
	
	if (!text.empty())
	{
		std::cout << text << diff_sec.count() << " ms" << std::endl;
	}
	
}

#endif ALGORITHMS_TIMER_H_