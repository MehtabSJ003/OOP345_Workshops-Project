#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iomanip>
using namespace std;
namespace seneca {
	int Event::m_count = 0;
	Event::Event() {
		m_description[0] = '\0';
		m_startTime = 0;
	}
	void Event::display() {
		cout<< setw(1)<< ++m_count << ". ";
		if (m_description[0] == '\0')
		{
			cout << "| No Event |";
		}
		else
		{
			size_t hours, minutes, seconds;
			hours = m_startTime / 3600;
			minutes = (m_startTime % 3600) / 60;
			seconds = m_startTime % 60;

			cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << " => " << m_description;
		}
		cout << setfill(' ') << endl;
	}

	void Event::set(const char* description) {
		if (description == nullptr || description[0] == '\0')
		{
			m_description[0] = '\0';
			m_startTime = 0;
		}
		else
		{
			strncpy(m_description, description, 128);
			m_startTime = g_sysClock;
		}
	}
    size_t g_sysClock = 0;
}