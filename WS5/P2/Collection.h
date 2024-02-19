/*
Name - MEHTAB SINGH JAGDE
Student ID - 119003226
Email - mjagde@myseneca.ca
Section - ZBB
Date - 18 / 02 / 2024

We have completed this assignment ourselves respecting academic integrity.

*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include<string>
namespace seneca {
    template <typename T>
    class Collection {
        std::string m_name{};
        T* m_items{};
        size_t m_sizeOfItems{};
        void (*m_observerFuncPtr)(const Collection<T>&, const T&);
    public:
        Collection(const std::string& name) {
            m_name = name;
            m_items = nullptr;
            m_sizeOfItems = 0;
            m_observerFuncPtr = nullptr;
        }
        Collection(const Collection&) = delete;
        Collection& operator=(const Collection&) = delete;
        Collection(Collection&& collection) = delete;
        Collection& operator=(Collection&& collection) = delete;
        virtual ~Collection() { 
            delete[] m_items;
        }
        const std::string& name() const {
            return m_name; 
        }
        size_t size() const { 
            return m_sizeOfItems; 
        }
        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            m_observerFuncPtr = observer;
        }
        Collection& operator+=(const T& item) {
            bool duplicate = false;

            for (size_t i = 0; i < m_sizeOfItems; ++i) {
                if (m_items[i].title() == item.title()) {
                    duplicate = true;
                }
            }

            if (!duplicate) {
                T* temp = new T[m_sizeOfItems + 1];
                for (size_t i = 0; i < m_sizeOfItems; i++) {
                    temp[i] = m_items[i];
                }

                temp[m_sizeOfItems] = item;

                delete[] m_items;
                m_items = temp;
                m_sizeOfItems++;


                if (m_observerFuncPtr) {
                    m_observerFuncPtr(*this, item);
                }
            }

            return *this;
        }
        T& operator[](size_t idx) const {

            if (idx >= m_sizeOfItems) {
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_sizeOfItems) + "] items.");
            }

            return m_items[idx];
        }
        T* operator[](const std::string& title) const {
            T* itemAddress = nullptr;

            for (size_t i = 0; i < m_sizeOfItems; ++i) {
                if (m_items[i].title() == title) {
                    itemAddress = &m_items[i];
                }
            }

            return itemAddress;
        }
    };
    template<typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {
        for (size_t i = 0; i < collection.size(); i++) {
            os << collection[i];
        }
        return os;
    }
}
#endif