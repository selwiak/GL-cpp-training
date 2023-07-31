#include <iostream>
#include "GasEngine.h"
#include "DieselEngine.h"
#include "ManualGear.h"
#include "AutomaticGear.h"
#include "Sedan.h"
#include "SUV.h"
#include "Jeep.h"

int main() {
    // Create engines and gears
    GasEngine gasEngine(4);
    DieselEngine dieselEngine(6);
    ManualGear manualGear;
    AutomaticGear automaticGear;

    // Create different types of cars
    Sedan sedanCar(&gasEngine, &manualGear);
    SUV suvCar(&dieselEngine, &automaticGear);
    Jeep jeepCar(&dieselEngine, &manualGear);

    // Print car information
    std::cout << "Car type: " << sedanCar.getCarType() << std::endl;
    std::cout << "Engine type: " << sedanCar.getEngine()->getFuelType() << " with " << sedanCar.getEngine()->getNumberOfCylinders() << " cylinders" << std::endl;
    std::cout << "Gear type: " << sedanCar.getGear()->getGearType() << std::endl;

    std::cout << "Car type: " << suvCar.getCarType() << std::endl;
    std::cout << "Engine type: " << suvCar.getEngine()->getFuelType() << " with " << suvCar.getEngine()->getNumberOfCylinders() << " cylinders" << std::endl;
    std::cout << "Gear type: " << suvCar.getGear()->getGearType() << std::endl;

    std::cout << "Car type: " << jeepCar.getCarType() << std::endl;
    std::cout << "Engine type: " << jeepCar.getEngine()->getFuelType() << " with " << jeepCar.getEngine()->getNumberOfCylinders() << " cylinders" << std::endl;
    std::cout << "Gear type: " << jeepCar.getGear()->getGearType() << std::endl;

    return 0;
}
