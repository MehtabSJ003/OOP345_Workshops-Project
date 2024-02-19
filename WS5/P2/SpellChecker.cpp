/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date - 18 / 02 / 2024

We have completed this assignment ourselves respecting academic integrity.

*/
#define _CRT_SECURE_NO_WARNINGS
#include "SpellChecker.h"
namespace seneca
{
	SpellChecker::SpellChecker(const char* filename){
		std::ifstream file(filename);
		if (!file)
		{
			throw "Bad file name!";
		}
		std::string badWord;
		std::string goodWord;
		int count = 0;
		while (file >> badWord >> goodWord)
		{
			m_badWords[count] = badWord;
			m_goodWords[count] = goodWord;
			count++;
		}

		file.close();
	}
	void SpellChecker::operator()(std::string& text){

		size_t start{};
		for (size_t i = 0; i < ARR_SIZE; i++)
		{
			start = 0;
			while ((start = text.find(m_badWords[i], start)) != std::string::npos)
			{
				text.replace(start, m_badWords[i].length(), m_goodWords[i]);
				start += m_goodWords[i].length();
				m_replacements[i]++;
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const{
		size_t index = 0;
		out << "Spellchecker Statistics"
			<< "\n";
		for (auto& badWord : m_badWords)
		{
			out << std::right << std::setw(15) << badWord << ": " << m_replacements[index] << " replacements"
				<< "\n";
			index++;
		}
	}
}