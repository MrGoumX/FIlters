#include "FilterLaplace.h"
#include "Vec3.h"

/*imaging::Image imaging::FilterLaplace::operator<<(const imaging::Image &image)
{
	int width = image.getWidth();
	int height = image.getHeight();
	Image* nimage = const_cast<Image*>(&image);
	int w = this->N, t = w / 2;
	for (int i = 0; i<width; i++)
	{
		for (int j = 0; j<height; j++)
		{
			math::Vec3<float> fval;
			for (int k = -1; k<2; k++)
			{
				for (int l = -1; l<2; l++)
				{
					int p1 = i + k, p2 = j + l;
					if (p1 >= 0 && p1 < width && p2 >= 0 && p2 < height) {
						fval += nimage->getP(p1, p2)*this->getP(k +t, l +t);
					}
					else continue;
				}
			}
			fval = fval.clampToLowerBound(0).clampToUpperBound(1);
			nimage->setP(i, j, fval);
		}
	}
	return Image(image);
}*/

imaging::Image imaging::FilterLaplace::operator<<(const imaging::Image &image)
{
	int width = image.getWidth()-1;
	int height = image.getHeight()-1;
	Image* nimage = const_cast<Image*>(&image);
	int w = this->N, t = w / 2;
	for (int i = 1; i<width; i++)
	{
		for (int j = 1; j<height; j++)
		{
			math::Vec3<float> fval;
			for (int k = 0; k<3; k++)
			{
				for (int l = 0; l<3; l++)
				{
					fval += nimage->getP(i + k, j + l)*this->getP(k + t, l + t);
				}
			}
			fval = fval.clampToLowerBound(0).clampToUpperBound(1);
			nimage->setP(i, j, fval);
		}
	}
	return Image(image);
}