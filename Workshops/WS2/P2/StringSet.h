/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date - 28 / 01 / 2024

We have completed this assignment ourselves respecting academic integrity.

*/

#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H
#include <iostream>
#include <string>
namespace seneca {
	class StringSet {
		std::string* m_string;
		size_t m_currentString;
	public:
		StringSet();
		StringSet(const char* fileName);

		// Copy constructor and Copy Assignment operator
		StringSet(const StringSet& src);
		StringSet& operator=(const StringSet& src);
		~StringSet();

		// Move constructor and Move Assignment operator
		StringSet(StringSet&& src);
		StringSet& operator=(StringSet&& src);

		size_t size() const;
		std::string operator[](size_t) const;
	};
}
#endif