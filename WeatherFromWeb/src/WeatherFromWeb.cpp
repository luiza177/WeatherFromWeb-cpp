#include "WeatherFromWeb.h"

WeatherFromWeb::WeatherFromWeb(std::string configFile)
{
    std::ifstream file(configFile);
    nlohmann::json jsonConfig;
    if (file.is_open())
    {
        file >> jsonConfig;
        file.close();
        m_appKey = jsonConfig.at("open_weather").at("app_key");
        setOpenWeatherUrl();
    }
    else
    {
        // throw exception
        // RESERVE GOODBIT BADBIT ETC
    }
}
WeatherFromWeb::~WeatherFromWeb() {}

std::string WeatherFromWeb::getCity() const { return m_city; }
void WeatherFromWeb::setCity(std::string city)
{
    m_city = city;
    setOpenWeatherUrl();
}

void WeatherFromWeb::setOpenWeatherUrl()
{
    m_openWeatherUrl = std::string("http://api.openweathermap.org/data/2.5/weather?q=");
    m_openWeatherUrl += m_city;
    m_openWeatherUrl += "&APPID=";
    m_openWeatherUrl += m_appKey;
}

WeatherDataPacket WeatherFromWeb::getWeatherDataPacket() const
{
    return m_WeatherData;
}
    
void WeatherFromWeb::updateWeatherDataPacket()
{
    auto r = cpr::Get(cpr::Url{m_openWeatherUrl});
    if (r.status_code == 200)
    {
        nlohmann::json m_jsonWeatherData = nlohmann::json::parse(r.text);
        m_WeatherData.temperature = m_jsonWeatherData.at("main").at("temp");
        m_WeatherData.humidity = m_jsonWeatherData.at("main").at("humidity");
        m_WeatherData.pressure = m_jsonWeatherData.at("main").at("pressure");
        // std::cout << "Weather data updated!\n"
    }
    else if (r.status_code == 404)
    {
        //throw exception
        // std::cerr << "Failed updating weather data, code: "
        //     << r.status_code << std::endl;
    }
    else
    {
        //throw exception
        // std::cerr << "Failed updating weather data, code: "
        //     << r.status_code << std::endl;
    }
}

std::ostream &operator<<(std::ostream &output, const WeatherFromWeb& wfw)
{
    output << "City: " << wfw.m_city << std::endl;
    output << "Temperature: " << wfw.m_WeatherData.temperature << std::endl;
    output << "Humidity: " << wfw.m_WeatherData.humidity << std::endl;
    output << "Pressure: " << wfw.m_WeatherData.pressure << std::endl;
    return output;
}