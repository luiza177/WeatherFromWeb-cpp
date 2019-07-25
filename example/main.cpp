#include <iostream>
#include "WeatherFromWeb.h"

//TODO: put main in 'example' folder -- write CMake variable to build it or not
//TODO: create README
//TODO: transfer to DPBook exercise
int main(int argc, const char* argv[])
{
    WeatherFromWeb weatherFromWeb("../WeatherFromWeb/config.json");
    weatherFromWeb.setCity("Sao Paulo");
    weatherFromWeb.updateWeatherDataPacket();
    std::cout << weatherFromWeb;

    return 0;
}

