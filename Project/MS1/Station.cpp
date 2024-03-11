#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"
namespace seneca {
	int Station::id_generator = 1;
	size_t Station::m_widthField = 0;
    Station::Station(const std::string& src) {
        std::string subString = "";
        Utilities utilities = Utilities();
        bool check = false;
        size_t position = 0;
        try 
        {
            m_itemName = utilities.extractToken(src, position, check);
            if (m_itemName.size() > m_widthField) 
            {
                m_widthField = m_itemName.size();
            }
            utilities.setFieldWidth(m_widthField);
            if (check == true)
            {
                subString = utilities.extractToken(src, position, check);
                m_nextSerialNumber= std::stoi(subString);
                subString = utilities.extractToken(src, position, check);
                m_quantity = std::stoi(subString);
                m_description = utilities.extractToken(src, position, check);
                m_id = id_generator;
                id_generator++;
            }
        }
        catch (const char* msg) 
        {
            std::cout << "Error: " << msg << std::endl;
        }
    }
    const std::string& Station::getItemName() const {
        return m_itemName;
    }
    size_t Station::getNextSerialNumber() {
        m_nextSerialNumber++;
        return m_nextSerialNumber - 1;
    }
    size_t Station::getQuantity() const {
        return m_quantity;
    }
    void Station::updateQuantity() {
        m_quantity--;
    }
    void Station::display(std::ostream& os, bool full) const {
        os << std::right << std::setw(3) << std::setfill('0') << m_id 
        << " | " << std::left << std::setw(m_widthField + 1) << std::setfill(' ')
        << m_itemName << "| " << std::right << std::setfill('0') << std::setw(6) 
        << m_nextSerialNumber << std::setfill(' ') << " | ";
        if (!full) 
        {
            os << std::endl;
        }
        else
        {
            os << std::setw(4) << m_quantity << " | " << std::left << m_description << std::endl;
        }
    }
}