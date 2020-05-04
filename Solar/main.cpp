#include <iostream>
#include <fstream>
#include "vec3.h"
#include "color.h"

int main() {
	std::ofstream file;
	file.open("render.ppm");

	const int image_width = 256;
	const int image_height = 256;

	file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i) {
			color pixel_color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0.25);
			write_color(file, pixel_color);
		}
	}
	std::cerr << "\nDone.\n";
	file.close();

}