/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date - 18 / 02 / 2024

We have completed this assignment ourselves respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
namespace seneca
{
	Book::Book(const std::string& strBook)
	{
		size_t startIndex{ 0 };
		size_t endIndex = strBook.find(',');
		m_author = strBook.substr(startIndex, (endIndex - startIndex));
		startIndex = endIndex + 1;
		endIndex = strBook.find(',', startIndex);
		m_author.erase(0, m_author.find_first_not_of(" \t\r\n"));
		m_author.erase(m_author.find_last_not_of(" \t\r\n") + 1);
		m_title = strBook.substr(startIndex, (endIndex - startIndex));
		startIndex = endIndex + 1;
		endIndex = strBook.find(',', startIndex);
		m_title.erase(0, m_title.find_first_not_of(" \t\r\n"));
		m_title.erase(m_title.find_last_not_of(" \t\r\n") + 1);
		m_country = strBook.substr(startIndex, (endIndex - startIndex));
		startIndex = endIndex + 1;
		endIndex = strBook.find(',', startIndex);
		m_country.erase(0, m_country.find_first_not_of(" \t\r\n"));
		m_country.erase(m_country.find_last_not_of(" \t\r\n") + 1);
		m_price = std::stod(strBook.substr(startIndex, (endIndex - startIndex)));
		startIndex = endIndex + 1;
		endIndex = strBook.find(',', startIndex);
		m_year = std::stoi(strBook.substr(startIndex, (endIndex - startIndex)));
		startIndex = endIndex + 1;
		endIndex = strBook.find('\n', startIndex);
		m_description = strBook.substr(startIndex, endIndex);
		m_description.erase(0, m_description.find_first_not_of(" \t\r\n"));
		m_description.erase(m_description.find_last_not_of(" \t\r\n") + 1);
	}
	const std::string& Book::title() const { 
		return m_title; 
	}
	const std::string& Book::country() const { 
		return m_country; 
	}
	const size_t& Book::year() const { 
		return m_year;
	}
	double& Book::price() {
		return m_price;
	}
	std::ostream& operator<<(std::ostream& ostr, const Book& rhs){
		ostr << std::setw(20) << std::right << rhs.m_author << " | "
			<< std::setw(22) << std::right << rhs.m_title << " | "
			<< std::setw(5) << std::right << rhs.m_country << " | "
			<< std::setw(4) << std::right << rhs.m_year << " | "
			<< std::setw(6) << std::setiosflags(std::ios::fixed) << std::setprecision(2) << std::right << rhs.m_price << " | "
			<< std::left << rhs.m_description << std::endl;

		return ostr;
	}
}