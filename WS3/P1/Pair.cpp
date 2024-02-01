#define _CRT_SECURE_NO_WARNINGS
#include "Pair.h"
#include <iostream>
#include <string>
#include <iomanip>
namespace seneca {
	Pair::Pair() {
		m_key = "No Key";
		m_value = "No Value";
	}
	bool Pair::operator==(const Pair& src) {
		return this->getKey() == src.m_key;
	}
	std::ostream& Pair::display(std::ostream& ostr)const {
		ostr << std::right << std::setw(20) << m_key << ": " << std::left << m_value;
		return ostr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Pair& rhs) {
		return rhs.display(ostr);
	}
}