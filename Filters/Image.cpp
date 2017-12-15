#include <string>
#include <iostream>
#include "Image.h"
#include "Array.h"
#include "Vec3.h"
#include "ppm/ppm.h"

imaging::Image::Image() : Array<math::Vec3<float>>() {}

imaging::Image::Image(int x, int y) : Array<math::Vec3<float>>(x, y) {}

imaging::Image::Image(int width, int height, const std::vector<math::Vec3<float>> * data_ptr) : Array<math::Vec3<float>>(width, height, data_ptr) {}

imaging::Image::Image(const Image &src) : Array<math::Vec3<float>>(src) {}

imaging::Image::~Image() {}

imaging::Image & imaging::Image::operator=(const Image & right) {
	if (this != &right) {
		width = right.width;
		height = right.height;
		if (!buffer->empty()) {
			delete buffer;
		}
		for (int i = 0; i< right.buffer->size(); i++)
		{
			buffer->at(i) = right.buffer->at(i);
		}
	}
	return *this;
}

bool imaging::Image::load(const std::string & filename, const std::string & format)
{
	if (format.compare(".ppm") == 0) {
		if (width != 0 || height != 0 || buffer != nullptr) {
			width = 0;
			height = 0;
			buffer = nullptr;
		}
		int w, h;
		float * temp = ReadPPM((filename + format).c_str(), &w, &h);
		if (temp != nullptr) {
			width =w;
			height =h;
			buffer = new std::vector<math::Vec3<float>>(width*height);
			int i = 0;
			for (std::vector<math::Vec3<float>>::iterator k = buffer->begin(); k != buffer->end(); k++, i++) {
				*k = math::Vec3<float>(temp[i * 3], temp[i * 3 + 1], temp[i * 3 + 2]);
			}
			delete[] temp;
			return true;
		}
	}
	else {
		std::cerr << "This extension is not supported" << std::endl;
	}
	return false;
}

bool imaging::Image::save(const std::string & filename, const std::string & format)
{
	if (buffer != nullptr) {
		float * temp = new float[width*height * 3];
		int i = 0;
		for (std::vector<math::Vec3<float>>::const_iterator k = buffer->begin(); k != buffer->end(); k++, i++) {
			temp[i * 3] = k->r;
			temp[i * 3 + 1] = k->g;
			temp[i * 3 + 2] = k->b;
		}
		if (format.compare(".ppm") == 0) {
			if (width != 0 && height != 0 && temp != nullptr) {
				bool saved = WritePPM(temp, width, height, (filename + format).c_str());
				if (saved) {
					delete[] temp;
					return true;
				}
				return false;
			}
			return false;
		}
		else {
			std::cerr << "This extension is not supported" << std::endl;
		}
		return false;
	}
	return false;
}