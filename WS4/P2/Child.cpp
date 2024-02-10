#define _CRT_SECURE_NO_WARNINGS
#include "Child.h"
#include <iostream>
#include <iomanip>
#include <string>
namespace seneca {
	void Child::reset() {
		m_name = "";
		m_age = 0;
		m_totalToys = 0;
		delete[] m_toys;
		m_toys = nullptr;
	}
	Child::Child() {
		reset();
	}
	Child::Child(const Child& src) {
		*this = src;
	}
	Child& Child::operator=(const Child& src) {
		if (this != &src)
		{
			m_totalToys = src.m_totalToys;
			m_name = src.m_name;
			m_age = src.m_age;
			delete[] m_toys;
			m_toys = new Toy[src.m_totalToys];
			for (size_t i = 0;i < src.m_totalToys;i++)
			{
				m_toys[i] = src.m_toys[i];
			}
		}
		return *this;
	}
	Child::Child(Child&& src) {
		*this = std::move(src);
	}
	Child& Child::operator=(Child&& src) {
		if (this != &src)
		{
			m_totalToys = src.m_totalToys;
			m_name = src.m_name;
			m_age = src.m_age;
			delete[] m_toys;
			m_toys = src.m_toys;
			src.m_toys = nullptr;
			src.m_totalToys = 0;
			src.m_name = "";
			src.m_age = 0;
		}
		return *this;
	}
	Child::Child(std::string name, int age, const Toy* toys[], size_t count) {
		m_toys = new  Toy[count];
		m_name = name;
		m_age = age;
		m_totalToys = count;
		for (size_t i = 0;i < count;i++)
		{
			m_toys[i] = *toys[i];
		}

	}
	Child::~Child() {
		delete[] m_toys;
		m_toys = nullptr;
	}
	size_t Child::size() const {
		return m_totalToys;
	}

	std::ostream& operator<<(std::ostream& ostr, const Child& rhs) {
		static int toyCounter=0;
		++toyCounter;
		ostr << "--------------------------\n" <<
			"Child " << toyCounter << ": " << rhs.m_name << " " << rhs.m_age << " years old:" << std::endl;
		ostr << "--------------------------\n";
		if (rhs.m_totalToys == 0) 
		{
			ostr << "This child has no toys!" << std::endl;
		}
		else 
		{
			for (size_t i = 0; i < rhs.m_totalToys; i++)
			{
				ostr << rhs.m_toys[i];
			}
		}
		ostr << "--------------------------\n";
		return ostr;
	}
}