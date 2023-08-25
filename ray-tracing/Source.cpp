#include <iostream>
#include <fstream>

#include "color.h"
#include "vec3.h"

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Creating output Image

    std::ofstream outputFile("out.ppm");

    if (!outputFile) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        return 1;
    }

    // Render

    std::cout << "Creating a render with size: " << image_width << " x " << image_height << "\n";

    outputFile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
           auto pixel_color = color(double(i) / (image_width - 1), double(j) / (image_height - 1), 255.0);
            write_color(outputFile, pixel_color);

            //std::cout << ir << ' ' << ig << ' ' << ib << '\n';

        }
    }

    outputFile.close();
    std::clog << "\rDone.                 \n";
    std::cout << "Archivo PPM creado exitosamente." << std::endl;
}