#ifndef _FilterLaplace_
#define _FilterLaplace_

#include "Image.h"
#include "FilterBlur.h"

namespace imaging
{
	class FilterLaplace : public FilterBlur
	{
		//const std::vector<float> * standar = new const std::vector<float>{0, 1, 0, 1, -4, 1, 0, 1, 0};

	public:
		
		FilterLaplace(std::string name, int n) : FilterBlur(name, n)
		{
			buffer = new std::vector<float>{ 0.0F, 1.0F, 0.0F, 1.0F, -4.0F, 1.0F, 0.0F, 1.0F, 0.0F };
		}

		~FilterLaplace() {}

		Image operator << (const Image &image);

	};

}

#endif _FilterLaplace_