#ifndef _FilterGamma_
#define _FilterGamma_

#include "Image.h"
#include "Filter.h"

namespace imaging
{
	class FilterGamma : public Filter
	{
		float gamma;

	public:
		FilterGamma() : Filter() {}

		FilterGamma(std::string name, float g) : Filter(name), gamma(g) {}

		FilterGamma(const FilterGamma &src) : Filter(src.name), gamma(src.gamma) {}

		~FilterGamma() {}

		Image operator<<(const Image &image);

	};
}

#endif _FilterGamma_