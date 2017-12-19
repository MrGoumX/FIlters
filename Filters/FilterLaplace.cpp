#include "FilterLaplace.h"
#include "Vec3.h"

imaging::Image imaging::FilterLaplace::operator<<(const imaging::Image &image)
{
	int width = image.getWidth();
	int height = image.getHeight();
	Image* nimage = const_cast<Image*>(&image);
	int w = this->N, m = -w / 2, n = -w / 2, f = w / 2 + 1;
	this->setData(standar);
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
						math::Vec3<float> val(nimage->getP(p1, p2)*this->getP(k + 1, l + 1));
						math::Vec3<float> val1 = val.clampToLowerBound(0);
						math::Vec3<float> val2 = val1.clampToUpperBound(1);
						fval += val2;
					}
					else continue;
				}
			}
			nimage->setP(i, j, fval);
		}
	}
	return Image(image);
}