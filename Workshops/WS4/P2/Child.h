#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H
#include <iostream>
#include "Toy.h"
#include <string>
namespace seneca {
	class Child {
		std::string m_name;
		int m_age;
	    Toy* m_toys{};
		size_t m_totalToys;
	public:
		void reset();
		Child();
		Child(const Child& src);
		Child& operator=(const Child& src);
		Child(Child&& src);
		Child& operator=(Child&& src);
		Child(std::string name, int age, const Toy* toys[], size_t count);
		~Child();
		size_t size() const;

		friend std::ostream& operator<<(std::ostream& ostr, const Child& rhs);
	};
}
#endif