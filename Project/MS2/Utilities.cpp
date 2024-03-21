
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Utilities.h"
namespace seneca {
	char Utilities::m_delimiter;
	std::string trim(std::string& src) {
		bool valid = false;
		while (!valid)
		{
			if (src[0] == ' ')
			{
				src.erase(0, src.find_first_not_of(' '));
			}
			else if (src[src.length() - 1] == ' ')
			{
				src.erase(src.find_last_not_of(' ') + 1);
			}
			else
			{
				valid = true;
			}
		}
		return src;
	}
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string string = "";
		static size_t newWidth = 0; //stores the biggest number for tempStr length.
		size_t index = 0;
		more = false;

		//if delimiter is found at next_pos, throw an error.
		if (str.find(m_delimiter, next_pos) == next_pos)
		{
			more = false;
			newWidth = 0;
			throw "   ERROR: No token.";
		}
		else
		{
			//error handling for std::string find method in case there is nothing found.
			if (str.find(m_delimiter, next_pos) >= str.length())
			{
				index = str.length();
			}
			else
			{
				index = str.find(m_delimiter, next_pos);
			}
			string = str.substr(next_pos, index - next_pos + 1);
			//adding current size of string to next_pos
			next_pos += string.length();
			//if next_pos >= initial string's length, it sets more to false to avoid reading from the string.
			if (next_pos >= str.length())
			{
				more = false;
			}
			else
			{
				string.erase(string.find(m_delimiter));
				more = true;
			}
			string = trim(string);
			//updating the width to max value of tempStr's size.
			if (newWidth < string.size())
			{
				newWidth = string.size();
				m_widthField = newWidth;
			}
			//sets newWidth back to zero once all values are read.
			if (more == false)
			{
				newWidth = 0;
			}
		}
		return string;
	}
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}