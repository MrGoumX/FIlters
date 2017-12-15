#ifndef _FilterLinear_
#define _FilterLinear_

#include "Image.h"
#include "Filter.h"

namespace imaging
{
	class FilterLinear : public Filter
	{
		math::Vec3<float> a, c;

	public:
		FilterLinear() : Filter() {}

		FilterLinear(std::string name, math::Vec3<float> a, math::Vec3<float> c) : Filter(name), a(a), c(c) {}

		FilterLinear(const FilterLinear &src) : Filter(src.name), a(src.a), c(src.c) {}

		~FilterLinear() {}

		Image operator << (const Image &image);

	};

}

#endif _FilterLinear_