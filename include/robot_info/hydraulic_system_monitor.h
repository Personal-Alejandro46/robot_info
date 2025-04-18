#pragma once
#include <string>

class HydraulicSystemMonitor
{
public:
    HydraulicSystemMonitor();
    ~HydraulicSystemMonitor() {}

    std::string getHydraulicOilTemperature() const { 
    return hydraulic_oil_temperature_; 
    }
    
    std::string getHydraulicOilTankFillLevel() const { 
    return hydraulic_oil_tank_fill_level_; 
    }
    
    std::string getHydraulicOilPressure() const {
     return hydraulic_oil_pressure_; 
    }

    void setHydraulicOilTemperature(const std::string& temp) {
     hydraulic_oil_temperature_ = temp; 
    }
    
    void setHydraulicOilTankFillLevel(const std::string& level) {
     hydraulic_oil_tank_fill_level_ = level; 
    }
    
    void setHydraulicOilPressure(const std::string& pressure) { 
    hydraulic_oil_pressure_ = pressure; 
    }

private:
    std::string hydraulic_oil_temperature_;
    std::string hydraulic_oil_tank_fill_level_;
    std::string hydraulic_oil_pressure_;
};