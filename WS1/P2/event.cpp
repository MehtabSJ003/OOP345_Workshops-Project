/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date - 21 / 01 / 2024

We have completed this assignment ourselves respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <iomanip>
#include <cstring>
using namespace std;
namespace seneca {
    int Event::m_count = 0;
    Event::Event() {
        m_description = nullptr;
        m_startTime = 0;
    }
    Event::Event(const Event& src) {
        *this = src;
    }
    Event& Event::operator=(const Event& src) {
        if (this != &src) {
            m_startTime = src.m_startTime;
            if (src.m_description != nullptr) {
                delete[] m_description;
                m_description = new char[strlen(src.m_description) + 1];
                strcpy(m_description, src.m_description);
            }
            else
            {
                m_description = nullptr;
                m_startTime = 0;
            }
        }
        return *this;
    }
    void Event::display() {
        cout << setw(2) << ++m_count << ". ";
        if (m_description == nullptr || m_description[0]=='\0') {
            cout << "| No Event |";
        }
        else {
            size_t hours, minutes, seconds;
            hours = m_startTime / 3600;
            minutes = (m_startTime % 3600) / 60;
            seconds = m_startTime % 60;

            cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << " => " << m_description;
        }
        cout << setfill(' ') << endl;
    }

    void Event::set(const char* description) {
        if (description != nullptr && description[0] != '\0')
        {
            delete[] m_description;
            m_description = nullptr;
            m_description = new char[strlen(description) + 1];
            strcpy(m_description, description);
            m_startTime = g_sysClock;
        }
        else
        {
            delete[] m_description;
            m_description = nullptr;
        }
    }
    size_t g_sysClock = 0;

    Event::~Event() {
        delete[] m_description;
        m_description = nullptr;
    }
}
