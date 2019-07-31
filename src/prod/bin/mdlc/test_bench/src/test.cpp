#include <iostream>
#include <stdio.h>
#include <math.h>
#include <chrono>


int x_res = 1920;
int y_res = 1080;

extern "C"
struct float3 {
    float x;
    float y;
    float z;
};

extern "C"
void hello(int x_res, int y_res, float3* buffer);

extern "C"
void save_image(float3* data){
    auto file = fopen("output.ppm" , "wb");
    fprintf(file, "P3\n%d %d\n255\n", x_res, y_res);
    for(int y = y_res - 1; y >= 0; y--){
        for (int x = 0; x < x_res; ++x) {
            if(x > 0){
                fprintf(file, " ");
            }
            fprintf(file, "%i %i %i", static_cast<int>(data[y * x_res +x].x * 255), static_cast<int>(data[y * x_res +x].y * 255),static_cast<int>(data[y * x_res +x].z * 255));
            //fprintf(file, "%i %i %i", y % 255, y % 255, y % 255);
        }
        fprintf(file, "\n");
    }
}


int main(int arc, char** argv) {
    float3* buf = (float3*) malloc(x_res * y_res * sizeof(float3));
    auto start = std::chrono::system_clock::now();
    hello(x_res, y_res, buf);
    auto end = std::chrono::system_clock::now();
    std::cout << "elapsed " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    save_image(buf);
    return 0;
}

