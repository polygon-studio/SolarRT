#include <iostream>
#include <fstream>

int main() {
	std::ofstream file;
	file.open("render.ppm");

	const int image_width = 256;
	const int image_height = 256;

	file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for (int j = image_height - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i) {
			auto r = double(i) / (image_width);
			auto g = double(i) / (image_height);
			auto b = 0.25;

			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);

			file << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
	std::cerr << "\nDone.\n";
	file.close();

}