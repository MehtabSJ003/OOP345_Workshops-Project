#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H
#include <iostream>
#include <iomanip>
#include "Pair.h"
namespace seneca {
    // Collection class template
    template <typename T, int CAPACITY>
    class Collection {
        T m_elements[CAPACITY];
        // static because it is a class variable
        static T m_dummy;
	size_t m_size;
    public:
        Collection();
	virtual ~Collection();
        size_t size() const;
        std::ostream& display(std::ostream& os = std::cout) const;
        virtual bool add(const T& item);
        T operator[](const int index) const;
    };

    // declare class variable
    template <typename T, int CAPACITY>
    T Collection<T, CAPACITY>::m_dummy{};

    // specialize m_dummy using 2-arg constructor for Pair
    template <>
    Pair Collection<Pair, 100>::m_dummy("No Key", "No Value");

	// Default Constructor
	template <typename T, int CAPACITY>
	Collection<T, CAPACITY>::Collection() {
		m_size = {};
	}

	// Empty Body desctructor
	template <typename T, int CAPACITY>
	Collection<T, CAPACITY>::~Collection() {};

	// Return current Number of elements in the collection
	template <typename T, int CAPACITY>
	size_t Collection<T, CAPACITY>::size() const {
		return m_size;
	}

	// Display Collection
	template<typename T, int CAPACITY>
	std::ostream& Collection<T, CAPACITY>::display(std::ostream& ostr)const {
		ostr << "----------------------" << std::endl;
		ostr << "| Collection Content |" << std::endl;
		ostr << "----------------------" << std::endl;
		for (auto i = 0ul; i < m_size; ++i)
			ostr << m_elements[i] << std::endl;
		ostr << "----------------------" << std::endl;
		return ostr;
	}

	// Add an item to collection
	template <typename T, int CAPACITY>
	bool Collection<T, CAPACITY>::add(const T& item) {
		bool check = false;
		if (m_size < CAPACITY - 1)
		{
			m_elements[m_size++] = item;
			check = true;
		}
		return check;
	}

	// [] overload returns a record in the collection at index
	template<typename T, int CAPACITY>
	T Collection<T, CAPACITY>::operator[](const int index)const {
		T tempDummy;
		if (index < (int)m_size)
		{
			tempDummy = m_elements[index];
		}
		else
		{
			tempDummy = m_dummy;
		}
		return tempDummy;
	}
}
#endif
