#include <iostream>
#include "GasEngine.h"
#include "DieselEngine.h"
#include "ManualGear.h"
#include "AutomaticGear.h"
#include "Sedan.h"
#include "SUV.h"
#include "Jeep.h"

int main() {
    // Create engines and gears using smart pointers
    std::unique_ptr<DieselEngine> dieselEngine = std::make_unique<DieselEngine>(6);
    std::unique_ptr<AutomaticGear> automaticGear = std::make_unique<AutomaticGear>();

    // Create different types of cars using smart pointers with templates
    std::unique_ptr<Car> sedanCar = std::make_unique<Sedan<DieselEngine, AutomaticGear>>(std::move(dieselEngine), std::move(automaticGear));
    std::unique_ptr<Car> suvCar = std::make_unique<SUV<DieselEngine, AutomaticGear>>(std::make_unique<DieselEngine>(12), std::make_unique<AutomaticGear>());
    std::unique_ptr<Car> jeepCar = std::make_unique<Jeep<GasEngine, ManualGear>>(std::make_unique<GasEngine>(8), std::make_unique<ManualGear>());

    // Print car information
    std::cout << "Car type: " << sedanCar->getCarType() << std::endl;
    std::cout << "Engine type: " << sedanCar->getEngine()->getFuelType() << " with " << sedanCar->getEngine()->getNumberOfCylinders() << " cylinders" << std::endl;
    std::cout << "Gear type: " << sedanCar->getGear()->getGearType() << std::endl;

    std::cout << "Car type: " << suvCar->getCarType() << std::endl;
    std::cout << "Engine type: " << suvCar->getEngine()->getFuelType() << " with " << suvCar->getEngine()->getNumberOfCylinders() << " cylinders" << std::endl;
    std::cout << "Gear type: " << suvCar->getGear()->getGearType() << std::endl;

    std::cout << "Car type: " << jeepCar->getCarType() << std::endl;
    std::cout << "Engine type: " << jeepCar->getEngine()->getFuelType() << " with " << jeepCar->getEngine()->getNumberOfCylinders() << " cylinders" << std::endl;
    std::cout << "Gear type: " << jeepCar->getGear()->getGearType() << std::endl;

    return 0;
}
