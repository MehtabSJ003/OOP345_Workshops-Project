#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H
#include <iostream>
#include "Toy.h"
namespace seneca {
	class ConfirmOrder {
		const Toy** m_toy;
		size_t m_maxToys;
	public:
		ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& src);
		ConfirmOrder& operator=(const ConfirmOrder& src);
		~ConfirmOrder();
		ConfirmOrder(ConfirmOrder&& src) ;
		ConfirmOrder& operator=(ConfirmOrder&& src) ;

		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmOrder& rhs);
	};
}
#endif