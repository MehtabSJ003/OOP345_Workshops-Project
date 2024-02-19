/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date - 18 / 02 / 2024

We have completed this assignment ourselves respecting academic integrity.

*/
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H
#include <iostream>
#include <string>
#include <iomanip>
namespace seneca
{
	class Movie
	{
		std::string m_title{};
		size_t m_yearOfRelease{};
		std::string m_description{};

	public:
		Movie() = default;
		Movie(const std::string& strMovie);
		const std::string& title() const;
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}
	};
}
#endif