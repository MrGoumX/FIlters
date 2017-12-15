#include <iostream>
#include <string>
#include "Image.h"
#include "Array.h"
#include "Vec3.h"
#include "FilterLinear.h"
#include "FilterGamma.h"
#include "FilterBlur.h"
#include "FilterLaplace.h"

int main(int argc, char * argv[]) {
	std::string name, filename, ext;
	name = argv[argc - 1];
	if (name.find('.') == std::string::npos) {
		std::cerr << "Not a valid file name, no extension" << std::endl;
	}
	else {
		ext = name.substr(name.find_last_of('.'));
		filename = name.substr(0, name.find_last_of('.'));
		imaging::Image A;
		bool loaded = A.load(filename, ext);
		if (loaded) {
			int i = 0;
			while (i < (argc - 1)) {
				if (strcmp(argv[i], "-f") == 0)
				{
					i++;
					if (strcmp(argv[i], "linear") == 0)
					{
						float a(atof(argv[i + 1]));
						math::Vec3<float> an(float(atof(argv[i + 1])), float(atof(argv[i + 2])), float(atof(argv[i + 3])));
						math::Vec3<float> cn(float(atof(argv[i + 4])), float(atof(argv[i + 5])), float(atof(argv[i + 6])));
						imaging::FilterLinear linear(std::to_string(i), an, cn);
						linear << A;
						i += 6;
					}
					else if (strcmp(argv[i], "gamma") == 0)
					{
						float g(atof(argv[i + 1]));
						imaging::FilterGamma gamma(std::to_string(i), g);
						gamma << A;
						i++;
					}
					else if (strcmp(argv[i], "blur") == 0)
					{
						int N(int(atof(argv[i + 1])));
						imaging::FilterBlur blur(std::to_string(i), N);
						blur << A;
						i++;
					}
					else if (strcmp(argv[i], "laplace") == 0)
					{
						imaging::FilterLaplace laplace("laplace", 3);
						laplace << A;
						i++;
					}
				}
				else
				{
					i++;
				}
			}
		}
		bool saved = A.save("filtered_" + filename, ".ppm");
		if (saved)std::cout << "Finished" << std::endl;
	}
	system("pause");
	return 0;
}
