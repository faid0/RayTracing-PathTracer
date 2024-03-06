#include <iostream>

//Image width and height
int width = 256;
int height = 256;


int main(int argc, char *argv[]) {
    std::cout << "P3\n" << width << " " << height << "\n255\n";


    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            auto r = double(i) / (width - 1);
            auto g = double(j) / (height - 1);
            auto b = 0;

            int rInt = static_cast<int>(255.999 * r);
            int gInt = static_cast<int>(255.999 * g);
            int bInt = static_cast<int>(255.999 * b);
            std::cout << rInt << " " << gInt << " " << bInt << "\n";
        }
    }

}
