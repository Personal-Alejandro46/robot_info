#include "robot_info/hydraulic_system_monitor.h"

HydraulicSystemMonitor::HydraulicSystemMonitor() :
    hydraulic_oil_temperature_("45.0 C"),
    hydraulic_oil_tank_fill_level_("100%"),
    hydraulic_oil_pressure_("250 bar")
{
}
