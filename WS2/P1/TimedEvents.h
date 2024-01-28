#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H
#include <chrono>
#include <iostream>
#include <string>
namespace seneca {
	class TimedEvents {

		static const int maxRecords = 10;
		int m_currentRecords;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		
		struct Event {
			std::string name;
			std::string unit;
			std::chrono::steady_clock::duration duration;
			Event() :name(""), unit("") {};
		};
		Event event[maxRecords];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* eventName);
		friend std::ostream& operator<<(std::ostream& ostr, const TimedEvents& rhs);
	};

}
#endif