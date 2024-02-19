/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date - 18 / 02 / 2024

We have completed this assignment ourselves respecting academic integrity.

*/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include <string>
#include <iomanip>
namespace seneca
{
	class Book
	{
		std::string m_author{};
		std::string m_title{};
		std::string m_country{};
		size_t m_year{ 0 };
		double m_price{ 0 };
		std::string m_description{};
	public:
		Book() = default;
		Book(const Book& book) = default;
		Book& operator=(const Book& book) = default;
		Book(const std::string& strBook);
		virtual ~Book() = default;
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		friend std::ostream& operator<<(std::ostream& ostr, const Book& rhs);
		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_description);
		}
	};
}
#endif