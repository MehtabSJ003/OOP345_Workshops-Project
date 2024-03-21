#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ConfirmOrder.h"
#include <string>
namespace seneca {
	ConfirmOrder::ConfirmOrder() {
		m_toy = nullptr;
		m_maxToys = 0;
	}
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& src) :m_toy(nullptr), m_maxToys(0) {
		*this = src;
	}
	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& src){
		if (this != &src)
		{
			m_maxToys = src.m_maxToys;
			delete[] m_toy;
			m_toy = new const Toy * [src.m_maxToys];
			for (size_t i = 0;i < m_maxToys;i++)
			{
				m_toy[i] = src.m_toy[i];
			}
		}
		return *this;
	}
	ConfirmOrder::~ConfirmOrder() {
		delete[] m_toy;
		m_toy = nullptr;
	}
	ConfirmOrder::ConfirmOrder(ConfirmOrder&& src):m_toy(nullptr),m_maxToys(0){
		*this = std::move(src);
	}
	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& src) {
		if (this != &src)
		{
			m_maxToys = src.m_maxToys;
			delete[] m_toy;
			m_toy = src.m_toy;
			src.m_toy = nullptr;
			src.m_maxToys = 0;
		}
		return *this;
	}

	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
		bool check = false;
		for (size_t i = 0;i < m_maxToys;i++)
		{
			if (m_toy[i] == &toy)
			{
				check = true;
			}
		}
		if (!check)
		{
			const Toy** toyTemp = nullptr;
			toyTemp = new const Toy * [m_maxToys + 1];
			for (size_t i = 0;i < m_maxToys;i++)
			{
				toyTemp[i] = m_toy[i];
			}
			toyTemp[m_maxToys] = &toy;
			m_maxToys++;

			delete[] m_toy;
			m_toy = toyTemp;
		}
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
		bool check = false;
		for (size_t i = 0;i < m_maxToys;i++)
		{
			if (m_toy[i] == &toy)
			{
				check = true;
			}
		}
		if (check)
		{
			for (size_t i = 0;i < m_maxToys;i++)
			{
				if (m_toy[i] == &toy)
				{
					m_toy[i] = nullptr;
				}
			}
			m_maxToys--;
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& rhs) {
		ostr << "--------------------------" << std::endl;
		ostr << "Confirmations to Send" << std::endl;
		ostr << "--------------------------" << std::endl;
		if (rhs.m_maxToys == 0)
		{
			ostr << "There are no confirmations to send!"<<std::endl;
		}
		else 
		{
			for (size_t i = 0; i < rhs.m_maxToys; i++) 
			{
				if (rhs.m_toy[i] != nullptr) 
				{
					ostr << *rhs.m_toy[i];
				}
			}
		}
		ostr << "--------------------------"<<std::endl;
		return ostr;
	}
}