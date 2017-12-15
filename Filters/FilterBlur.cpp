#include "FilterBlur.h"

imaging::Image imaging::FilterBlur::operator<<(const imaging::Image &image)
{
	int width = image.getWidth();
	int height = image.getHeight();
	Image* nimage = const_cast<Image*>(&image);
	int w = this->N, m = -w / 2, n = -w / 2, f = w / 2 + 1, t  = w/2;
	for (int i = 0; i<width; i++)
	{
		for (int j = 0; j<height; j++)
		{
			math::Vec3<float> fval;
			for (int k = m; k<f; k++)
			{
				for (int l = n; l<f; l++)
				{
					int p1 = i + k, p2 = j + l;
					if (p1 >= 0 && p1 < width && p2 >= 0 && p2<height) {
						fval += nimage->getP(p1, p2)*this->getP(k+t,l+t);
					}
					else continue;
				}
			}
			nimage->setP(i, j, fval);
		}
	}
	return Image(image);
}