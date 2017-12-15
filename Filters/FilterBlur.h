#ifndef _FilterBlur_
#define _FilterBlur_

#include "Image.h"
#include "Filter.h"
#include <iostream>

namespace imaging
{
	class FilterBlur : public Filter, public math::Array<float>
	{
	protected:
		int N;

	public:
		FilterBlur() : Filter(), Array<float>() {}

		FilterBlur(std::string name, int N) : Filter(name), Array<float>(N, N), N(N)
		{
			buffer = new std::vector<float>(N*N);
			float value = 1.0 / float(N*N);
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j< N; j++)
				{
					if (N != 0)setP(i, j, value);
				}
			}
		}

		FilterBlur(const FilterBlur &src) : FilterBlur(src.name, src.N) {}

		~FilterBlur() {}

		Image operator << (const Image &image);

	};

}

#endif _FilterBlur_