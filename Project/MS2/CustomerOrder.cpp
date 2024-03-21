#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

namespace seneca {
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const std::string& str) {
		Utilities temp;
		bool more = false;
		size_t pos = 0u;
		//If the string str is empty ---> set to empty state
		if (str.empty()) 
		{
			m_name = "";
			m_product = "";
			m_cntItem = 0;
			m_lstItem = nullptr;
		}
		else 
		{
			//Otherwise, the m_name is extracted from the string str
			m_name = temp.extractToken(str, pos, more);
			if (more) 
			{
				m_product = temp.extractToken(str, pos, more);
			}
			std::string newItems = str.substr(pos, str.length() - pos);
			m_cntItem = (count(newItems.begin(), newItems.end(), temp.getDelimiter())) + 1;
			//DMA for the list of Items
			m_lstItem = new Item * [m_cntItem];
			for (size_t i = 0u; i < m_cntItem && more; i++)
				m_lstItem[i] = new Item(temp.extractToken(str, pos, more));  //DMA
			if (m_widthField < temp.getFieldWidth())
				m_widthField = temp.getFieldWidth();
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder& src) {
		throw "Error!";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src)noexcept {
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src)noexcept {
		if (this != &src) 
		{
			for (auto i = 0u; i < m_cntItem; i++) 
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			//shallow copy
			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;
			//set to empty state
			src.m_name = "";
			src.m_product = "";
			src.m_cntItem = 0;
			src.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		for (auto i = 0u; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	bool CustomerOrder::isOrderFilled() const {
		bool check = true;
		for (unsigned i = 0; i < m_cntItem; i++) 
		{
			if (!m_lstItem[i]->m_isFilled) 
			{
				check = false;
			}
		}
		return check;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const 
	{
		bool check = true;
		for (unsigned int i = 0; i < m_cntItem; i++) 
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				return m_lstItem[i]->m_isFilled;
			}
		}
		return check;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		bool filled = false;
		for (size_t i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_isFilled == filled && m_lstItem[i]->m_itemName == station.getItemName()) {

				if (station.getQuantity() >= 1) {
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << std::setw(11) << std::right;
					os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "] " << std::endl;
					filled = true;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << std::endl;
		for (unsigned int i = 0; i < m_cntItem; i++) 
		{
			os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled) os << "FILLED" << std::endl;
			else os << "TO BE FILLED" << std::endl;
		}
	}
}