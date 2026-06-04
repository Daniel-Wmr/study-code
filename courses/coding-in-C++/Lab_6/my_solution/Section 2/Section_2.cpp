#include <iostream>
#include <string>
#include <stdexcept>

constexpr double ZERO_PERC = 0.0;
constexpr double HUNDRED_PERC = 100.0;
constexpr double MIN_PHYS_POSS_TEMPERATURE = -273.15;

class Sensor
{
protected:
    std::string sensor_name;
    double current_value;
    double min_phys_poss_value;
    double max_phys_poss_value;

public:
    Sensor(std::string name, double cur_value, double min_value, double max_value);
    
    double get_value() const
    {
        return current_value;
    }

    void printInfo() const;

    virtual ~Sensor() = default;

    virtual void update_value(double value) = 0;
};

Sensor::Sensor(std::string name, double cur_value, double min_value, double max_value)
    : sensor_name(name), current_value(cur_value), min_phys_poss_value(min_value), max_phys_poss_value(max_value)
{
    if (max_value < min_value)
    {
        throw std::invalid_argument("Minimum physically possible value is greater than maximum physically possible value.");
    }
}

void Sensor::printInfo() const
{
    std::cout << "Sensor name: " << sensor_name << std::endl;
    std::cout << "Current Value: " << current_value << std::endl;
    std::cout << "Minimum physically possible value: " << min_phys_poss_value << std::endl;
    std::cout << "Maximum physically possible value: " << max_phys_poss_value << std::endl;
}

class Temperature_Sensor : public Sensor
{
public:
    Temperature_Sensor(std::string name, double cur_value, double min_value, double max_value) 
        : Sensor(name, cur_value, min_value, max_value){}

    void update_value(double value) override;
};

void Temperature_Sensor::update_value(double value)
{
    if (value < MIN_PHYS_POSS_TEMPERATURE)
    {
        throw std::out_of_range("Temperature Sensor detected physically impossible temperature (below -273.15°C).");
    }
    if (value < this->min_phys_poss_value)
    {
        throw std::out_of_range("Temperature Sensor detected temperature below sensors physically possible temperature.");
    }
    if (value > this->max_phys_poss_value)
    {
        throw std::out_of_range("Temperature Sensor detected temperature above sensors physically possible temperature.");
    }

    current_value = value;
}

class Humidity_Sensor : public Sensor
{
public:
    Humidity_Sensor(std::string name, double cur_value, double min_value, double max_value);
    
    void update_value(double value) override;
};

Humidity_Sensor::Humidity_Sensor(std::string name, double cur_value, double min_value, double max_value) 
        : Sensor(name, cur_value, min_value, max_value)
{
    if (min_value < ZERO_PERC)
    {
        throw std::invalid_argument("Minimum physically possible value is below 0.0%");
    }

    if (max_value > HUNDRED_PERC)
    {
        throw std::invalid_argument("Maximum physically possible value is above 100.0%");
    }
}

void Humidity_Sensor::update_value(double value)
{
    if (value < this->min_phys_poss_value)
    {
        throw std::out_of_range("Humidity Sensor detected humidity below sensors physically possible percentage.");
    }
    if (value > this->max_phys_poss_value)
    {
        throw std::out_of_range("Humidity Sensor detected humidity above sensors physically possible percentage.");
    }

    current_value = value;
}

class Water_Level_Sensor : public Sensor
{
public: 
    Water_Level_Sensor(std::string name, double cur_value, double min_value, double max_value) 
        : Sensor(name, cur_value, min_value, max_value){}
    
    void update_value(double value) override;
};
    
void Water_Level_Sensor::update_value(double value)
{
    if (value < this->min_phys_poss_value)
    {
        throw std::out_of_range("Water Level Sensor detected water level below sensors physically possible range.");
    }
    if (value > this->max_phys_poss_value)
    {
        throw std::out_of_range("Water Level Sensor detected water level above sensors physically possible percentage.");
    }

    current_value = value;
}

int main()
{
    try
    {
        Temperature_Sensor temp_sensor("Temp", 20.0, -20.0, 100.0);
        temp_sensor.update_value(-500.0);
    }
    catch(const std::exception& ex)
    {
        std::cout << "ERROR: " << ex.what() << std::endl;
    }
    
    try
    {
        Humidity_Sensor humid_sensor("Humid", 50.0, 0.0, 100.0);
        humid_sensor.update_value(150.0);
    }
    catch(const std::exception& ex)
    {
        std::cout << "ERROR: " << ex.what() << std::endl;
    }

    try
    {
        Water_Level_Sensor water_sensor("Water", 10.0, 100.0, 0.0);
    }
    catch(const std::exception& ex)
    {
        std::cout << "ERROR: " << ex.what() << std::endl;
    }

    try
    {
        Temperature_Sensor temp_sensor("Temp", 20.0, -20.0, 100.0);
        temp_sensor.update_value(-500.0);

        Humidity_Sensor humid_sensor("Humid", 50.0, 0.0, 100.0);
        humid_sensor.update_value(150.0);

        Water_Level_Sensor water_sensor("Water", 10.0, 100.0, 0.0);
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << "Invalid argument: " << ex.what() << std::endl;
    }
    catch (const std::out_of_range& ex)
    {
        std::cout << "Out of range: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << "General exception: " << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unknown exception." << std::endl;
    }

    return 0;
}