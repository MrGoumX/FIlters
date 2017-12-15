#ifndef _Filter_
#define _Filter_

#include "Image.h"

namespace imaging
{
	class Filter
	{
	protected:
		std::string name;

	public:
		Filter();

		Filter(std::string name) : name(name) {}

		Filter(const Filter &src) : name(src.name) {}

		~Filter() {}

		virtual Image operator<< (const Image & image) = 0;

	};
}

#endif _Filter_