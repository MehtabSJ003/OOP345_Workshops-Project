#ifndef SENECA_SET_H
#define SENECA_SET_H
#include "Collection.h"
namespace seneca {
	template <typename T>
	class Set : public Collection<T, 100> {
	public:
		bool add(const T& item);
	};

	// Override the inherited function add to prevent adding an item if it already exists in the Set
	template<typename T>
	bool Set<T>::add(const T& item) {
		bool check = true;
		size_t size = this->size();
		for (size_t i = 0;i < size;++i)
		{
			if ((*this)[i] == item)
			{
				check = false;
			}
		}
		if (check)
		{
			Collection<T, 100>::add(item);
		}
		return check;
	}

	// Specialization
	template<>
	bool Set<double>::add(const double& item) {
		bool check = true;
		size_t size = this->size();
		for (size_t i = 0;i < size;++i)
		{
			if( ((*this)[i] - item <0.01) && (item - (*this)[i]<0.01))
			{
				check = false;
			}
		}
		if (check)
		{
			Collection<double, 100>::add(item);
		}
		return check;
	}
}
#endif