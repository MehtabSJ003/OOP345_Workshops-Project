#define _CRT_SECURE_NO_WARNINGS
#include "StringSet.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "utility"
using namespace seneca;
StringSet::StringSet() {
	m_string = nullptr;
	m_currentString = 0;
}
StringSet::StringSet(const char* fileName) :m_string(nullptr), m_currentString(0) {
	if (fileName)
	{
		std::ifstream readFile(fileName);
		std::string temp;
		if (readFile)
		{
			while (getline(readFile, temp, ' '))
			{
				++m_currentString;
			}
			m_string = new std::string[m_currentString];
			readFile.clear();
			readFile.seekg(0, std::ios::beg);

			int i = 0;
			while (getline(readFile, m_string[i], ' '))
			{
				++i;
			}
		}
	}
}

// Copy constructor and Copy Assignment operator
StringSet::StringSet(const StringSet& src):m_string(nullptr),m_currentString(0) {
	*this = src;
}
StringSet& StringSet::operator=(const StringSet& src) {
	if (this != &src)
	{
		delete[] m_string;
		m_currentString = src.m_currentString;
		m_string = new std::string[m_currentString];
		for (size_t i = 0;i < m_currentString;i++)
		{
			m_string[i] = src.m_string[i];
		}
	}
	return *this;
}
StringSet::~StringSet() {
	if (m_string)
	{
		delete[] m_string;
	}
}

// Move constructor and Move Assignment operator
StringSet::StringSet(StringSet&& src) {
	*this = std::move(src);
}
StringSet& StringSet::operator=(StringSet&& src) {
	if (this != &src)
	{
		delete[] m_string;
		m_currentString = src.m_currentString;
		m_string = src.m_string;

		src.m_currentString = 0;
		src.m_string = nullptr;
	}
	return *this;
}

size_t StringSet::size() const {
	return m_currentString;
}
std::string StringSet::operator[](size_t src) const {
	std::string temp = "";
	if (src < m_currentString)
	{
		temp = m_string[src];
	}
	return temp;
}