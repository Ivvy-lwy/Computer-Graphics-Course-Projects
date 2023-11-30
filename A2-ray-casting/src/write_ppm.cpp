#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  // Reference: https://www.cs.swarthmore.edu/~soni/cs35/f13/Labs/extras/01/ppm_info.html
    std::ofstream img;
    img.open(filename);
    if (img.fail()) {
        std::cout << "Fail to create .ppm file.";
        return false;
    }

    // Image header
    if (num_channels == 3) {
        img << "P3" << std::endl;
    }
    else if (num_channels == 1) {
        img << "P2" << std::endl;
    }
    img << width << " " << height << std::endl;
    img << 255 << std::endl;

    // Image body
    int value;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            for (int i = 0; i < num_channels; i++) {
                value = data[row * width * num_channels + col * num_channels + i];
                img << value << " ";
                if (col == width * num_channels - 1) {
                    img << std::endl;

                }
            }
        }
    }


    img.close();
    return true;
  ////////////////////////////////////////////////////////////////////////////
}
