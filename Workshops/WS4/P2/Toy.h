#ifndef SENECA_TOY_H
#define SENECA_TOY_H
#include <iostream>
#include <utility>
#include <string>
namespace seneca {
	class Toy {
		int m_orderID;
		std::string m_name;
		int m_maxItems;
		double m_price;
		double m_tax = 0.13;
	public:
		Toy();
		void update(int numItems);
		Toy(const std::string& toy);
		friend std::ostream& operator<<(std::ostream& ostr, const Toy& rhs);
	};
}
#endif