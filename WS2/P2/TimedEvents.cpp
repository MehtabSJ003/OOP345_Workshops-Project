/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date - 28 / 01 / 2024

We have completed this assignment ourselves respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "TimedEvents.h"
#include <iostream>
#include <iomanip>
namespace seneca {
	TimedEvents::TimedEvents() {
		m_currentRecords = 0;
	}
	void TimedEvents::startClock() {
		m_startTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock() {
		m_endTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::addEvent(const char* eventName) {
		event[m_currentRecords].name = eventName;
		event[m_currentRecords].unit = "nanoseconds";
		event[m_currentRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		++m_currentRecords;
	}
	std::ostream& operator<<(std::ostream& ostr, const TimedEvents& rhs) {
		ostr << "--------------------------" << std::endl;
		ostr << "Execution Times:" << std::endl;
		ostr << "--------------------------" << std::endl;
		for (int i = 0;i < rhs.m_currentRecords;i++)
		{
			ostr << std::left << std::setw(21) << rhs.event[i].name;
			ostr << std::right << std::setw(13) << rhs.event[i].duration.count();
			ostr << " ";
			ostr << rhs.event[i].unit << std::endl;
		}
		ostr << "--------------------------" << std::endl;
		return ostr;
	}
}