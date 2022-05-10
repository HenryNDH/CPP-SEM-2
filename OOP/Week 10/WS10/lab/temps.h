#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H

#include "Collection.h"

namespace sdds {
	template <class type>
	Collection<type> select (const type arr [], int size, const type& obj)
	{
		int match = 0;

		for(int i = 0; i <= size; i++)
		{
			if(arr [i] == obj)
			{
				match += 1;
			}
		}

		Collection<type> collection((unsigned) match);

		int counter = 0;
		for(int i = 0; i <= size; i++)
		{
			if(arr [i] == obj)
			{
				collection [counter] = (arr [i]);
				counter += 1;
			}
		}

		return collection;
	}

	template <class type>
	void printCollection (const Collection<type> obj, const char* title)
	{
		std::cout << title << "\n";

		for(int i = 0; i < (signed) obj.size (); i++)
		{
			std::cout << obj [i] << std::endl;
		}
	}
}

#endif // !SDDS_TEMPS_H



