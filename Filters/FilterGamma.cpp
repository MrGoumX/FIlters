#include "FilterGamma.h"

imaging::Image imaging::FilterGamma::operator<<(const Image &image)
{
	int width = image.getWidth();
	int height = image.getHeight();
	Image* nimage = const_cast<Image*>(&image);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			math::Vec3<float> cc = nimage->getP(i, j);
			math::Vec3<float> gc(pow(cc.r, gamma), pow(cc.r, gamma), pow(cc.b, gamma));
			nimage->setP(i, j, gc);
		}
	}
	return image;
}