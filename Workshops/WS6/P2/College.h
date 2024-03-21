#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H
#include <vector>
#include <list>
#include "Person.h"
namespace seneca {
	class College {
		std::vector<Person*> m_persons;
	public:
		College() {};
		College(const College&) = delete;
		College& operator=(const College&) = delete;
		~College();
		College& operator +=(Person* thePerson);
		//First Test
		void display(std::ostream& out) const;

		//Second test
		template <typename T>
		void select(const T& test, std::list<const Person*>& persons)
		{
			for (auto i = m_persons.begin(); i != m_persons.end(); i++) 
			{
				if (test(*i))
				{
					persons.push_back(*i);
				}
			}
		}
	};
}
#endif // !SENECA_COLLEGE_H
