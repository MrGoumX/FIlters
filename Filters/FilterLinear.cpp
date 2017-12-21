#include "FilterLinear.h"

imaging::Image imaging::FilterLinear::operator<<(const imaging::Image &image)
{
	int width = image.getWidth();
	int height = image.getHeight();
	Image* nimage = const_cast<Image*>(&image);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			math::Vec3<float> changed(a*nimage->getP(i, j)+c);
			nimage->setP(i, j, changed);
		}
	}
	return Image(image);
}