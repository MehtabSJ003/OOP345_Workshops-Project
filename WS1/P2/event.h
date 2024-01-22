/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date - 21 / 01 / 2024

We have completed this assignment ourselves respecting academic integrity.

*/
#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H
#include <iostream>

namespace seneca {
	extern size_t g_sysClock;
	class Event {
		char* m_description;
		size_t m_startTime;
	    static int m_count;
	public:
		Event();
		Event(const Event& src);
		Event& operator=(const Event& src);
	    void display();
		void set(const char* description = nullptr);
		~Event();
	};
	
}
#endif