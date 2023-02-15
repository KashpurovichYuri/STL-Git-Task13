#include <iostream>
#include "timer.hpp"

void Timer::initialize()
{
	try
	{
		m_stream << "Timer \"" << m_name << "\" launched ... " << std::endl << std::endl;
	}
	catch (const std::exception & exception)
	{
		uninitialize();
	}
}

void Timer::uninitialize()
{
	try
	{
		elapsed();
	}
	catch (const std::exception & exception)
	{
		//
	}
}

void Timer::elapsed()
{
	try
	{
		auto end = clock_t::now();
		m_time += std::chrono::duration_cast < std::chrono::microseconds > (end - m_begin);
				
		m_stream << "Timer \"" << m_name << "\" elapsed " << std::setprecision(6) << std::fixed <<
			static_cast < double > (m_time.count()) / 1'000'000.0 << " (seconds)" << std::endl << std::endl;
	}
	catch (const std::exception & exception)
	{
		//
	}
}

void Timer::stop() noexcept
{			
	auto stop = clock_t::now();
	m_time += std::chrono::duration_cast < std::chrono::microseconds > (stop - m_begin);
}

void Timer::resume() noexcept
{
	m_begin = clock_t::now();
}


int main()
{
	Timer time {"timer.cpp", std::cout};
	double a, b;
	a = 2023;
	b = a * a;
	time.stop();
	a = 0;
	b = 0;
	time.resume();
	a = 2023;
	b = a * a;
	double c = b * b;
}