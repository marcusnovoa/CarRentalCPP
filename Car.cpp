//
//  Car.cpp
//  HW1 - XYZ Car Rental
//
//  Created by Marcus Novoa on 3/18/19.
//  Copyright © 2019 Marcus Novoa. All rights reserved.
//

#include "Car.hpp"

Car::Car() : plateNumber{to_string(defaultPlateNum)},
             make{"N/A"},
             model{"N/A"},
             //  vehicleType{coupe},
             pricePerDay{100.00},
             isAvailable{true}
{
  defaultPlateNum++;
}

Car::Car(string plateNumber) : plateNumber{plateNumber},
                               make{"N/A"},
                               model{"N/A"},
                               //  vehicleType{coupe},
                               pricePerDay{100.00},
                               isAvailable{true}
{
}

Car::Car(string plateNumber, string make, string model) : plateNumber{plateNumber},
                                                          make{make},
                                                          model{model},
                                                          pricePerDay{100.00},
                                                          isAvailable{true}
{
}

Car::Car(string plateNumber, string make, string model, double price) : plateNumber{plateNumber},
                                                                        make{make},
                                                                        model{model},
                                                                        pricePerDay{price},
                                                                        isAvailable{true}
{
}

void Car::SetAvailable(bool available)
{
  this->isAvailable = available;
}

bool Car::operator<(const Car &other)
{
  return plateNumber < other.plateNumber;
}

bool Car::operator==(const Car &other)
{
  return plateNumber == other.plateNumber;
}

std::ostream &operator<<(std::ostream &os, Car &c)
{
  os << "Car: [" << c.GetInfo() << "]";
  return os;
}
