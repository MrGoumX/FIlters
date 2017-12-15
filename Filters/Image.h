#ifndef _IMAGE
#define _IMAGE

#include "Array.h"
#include "Vec3.h"

namespace imaging
{

	class Image : public math::Array<math::Vec3<float>>
	{
	public:
		Image();

		Image(int width, int height);

		Image(int width, int height, const std::vector<math::Vec3<float>> * data_ptr);

		Image(const Image &src);

		~Image();

		Image & operator = (const Image & right);

		bool load(const std::string & filename, const std::string & format);

		bool save(const std::string & filename, const std::string & format);
	};

}
#endif _IMAGE
