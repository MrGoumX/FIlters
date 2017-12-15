#ifndef _Array_
#define _Array_

#include <vector>
#include <filesystem>

namespace math {
	template <typename T>
	class Array
	{
	protected:
		std::vector<T> * buffer;
		int width, height;

	public:
		const int getWidth() const { return width; }

		const int getHeight() const { return height; }

		std::vector<T> * getRawDataPtr()
		{
			return buffer;
		}

		T getP(int x, int y)
		{
			if (x < width && y < height && !buffer->empty()) {
				return buffer->at(x + y*width);
			}
		}

		void setP(int x, int y, T & value)
		{
			if (x < width && y < height && !buffer->empty()) {
				buffer->at(x + y*width) = value;
			}
		}

		void setData(const std::vector<T> * & data_ptr)
		{
			if (buffer != nullptr && width != 0 && height != 0) {
				buffer = new std::vector<T>(data_ptr->size());
				for (int i = 0; i< data_ptr->size(); i++)
				{
					buffer->at(i) = data_ptr->at(i);
				}
			}
		}

		T operator()(int x, int y) {
			return getP(y, x);
		}

		Array()
		{
			this->width = this->height = 0;
			this->buffer = nullptr;
		}

		Array(int width, int height)
		{
			this->width = width;
			this->height = height;
			this->buffer = nullptr;
		}

		Array(int width, int height, const std::vector<T> * data_ptr) : Array(width, height)
		{
			setData(data_ptr);
		}

		Array(const Array &src) : Array(src.width, src.height)
		{
			buffer = new std::vector<T>(src.buffer->size());
			for (int i = 0; i< src.buffer->size(); i++)
			{
				buffer->at(i) = src.buffer->at(i);
			}
		}

		~Array()
		{
			if (buffer != nullptr)
			{
				delete buffer;
			}
		}

		Array & operator = (const Array & right)
		{
			if (this != &right) {
				width = right.width;
				height = right.height;
				if (buffer != nullptr) {
					delete buffer;
				}
				buffer = new std::vector<T>(right.buffer->size());
				for (int i = 0; i< right.buffer->size(); i++)
				{
					buffer->at(i) = right.buffer->at(i);
				}
			}
			return *this;
		}

	};

}

#endif _Array_