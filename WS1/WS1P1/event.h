#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <iostream>

namespace seneca {
	extern size_t g_sysClock;
	class Event {
		char m_description[128];
		size_t m_startTime;
	    static int m_count;
	public:
		Event();
	    void display();
		void set(const char* description = nullptr);
	};
	
}
#endif