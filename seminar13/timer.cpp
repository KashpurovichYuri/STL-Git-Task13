#include "timer.hpp"

namespace solution
{
	namespace shared
	{
		void Timer::initialize()
		{
			RUN_LOGGER(logger);

			time = 0;

			try
			{
				m_stream << "Timer \"" << m_name << "\" launched ... " << std::endl << std::endl;
			}
			catch (const std::exception & exception)
			{
				uninitialize();

				shared::catch_handler < timer_exception > (logger, exception);
			}
		}

		void Timer::uninitialize()
		{
			RUN_LOGGER(logger);

			try
			{
				elapsed();
			}
			catch (const std::exception & exception)
			{
				shared::catch_handler < timer_exception > (logger, exception);
			}
		}

		void Timer::elapsed() const
		{
			RUN_LOGGER(logger);

			try
			{
				auto end = clock_t::now();

				time += stop - m_begin;
				
				m_stream << "Timer \"" << m_name << "\" elapsed " << std::setprecision(6) << std::fixed <<
					static_cast < double > (std::chrono::duration_cast < std::chrono::microseconds > 
						time.count()) / 1'000'000.0 << " (seconds)" << std::endl << std::endl;
			}
			catch (const std::exception & exception)
			{
				shared::catch_handler < timer_exception > (logger, exception);
			}
		}

		void Timer::stop() noexcept
		{			
			auto stop = clock_t::now();
			time += stop - m_begin;
		}

		void Timer::resume() noexcept
		{
			m_begin = clock_t::now();
		}

	} // namespace shared

} // namespace solution 