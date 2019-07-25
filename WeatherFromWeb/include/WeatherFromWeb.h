#ifndef WEATHERFROMWEB_H
#define WEATHERFROMWEB_H
#include <fstream>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"

struct WeatherDataPacket
{
    double temperature, humidity, pressure;
};

class WeatherFromWeb
{
private:
    std::string m_city = "Boston";
    std::string m_appKey = "4f59e98118b4a0a4c263b2890cb2ea2f";
    std::string m_openWeatherUrl;
    nlohmann::json m_jsonWeatherData;
    WeatherDataPacket m_WeatherData;

    void setOpenWeatherUrl();
public:
    WeatherFromWeb();
    WeatherFromWeb(std::string configFile);
    virtual ~WeatherFromWeb();

    std::string getCity() const;
    void setCity(std::string city);

    WeatherDataPacket getWeatherDataPacket() const;
    void updateWeatherDataPacket();

    friend std::ostream &operator<<(std::ostream &output, const WeatherFromWeb& wfw);
};

// struct MyException : public std::exception 
// {
//    const char* what() const throw()
//    {
//       return "C++ Exception";
//    }
// };

#endif