#include <memory>
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
    std::unique_ptr<IEngine> gasEnginePtr = std::make_unique<GasEngine>(4);
    std::unique_ptr<IEngine> dieselEnginePtr = std::make_unique<DieselEngine>(6);
    std::unique_ptr<IEngine> jeepdieselEnginePtr = std::make_unique<DieselEngine>(8);
    std::unique_ptr<IGear> manualGearPtr = std::make_unique<ManualGear>();
    std::unique_ptr<IGear> automaticGearPtr = std::make_unique<AutomaticGear>();
    std::unique_ptr<IGear> jeepmanualGearPtr = std::make_unique<ManualGear>();

    // Create different types of cars
    Sedan sedanCar(std::move(gasEnginePtr), std::move(manualGearPtr));
    SUV suvCar(std::move(dieselEnginePtr), std::move(automaticGearPtr));
    Jeep jeepCar(std::move(jeepdieselEnginePtr), std::move(jeepmanualGearPtr));

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
