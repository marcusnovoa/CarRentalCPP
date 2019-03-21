//
//  Car.hpp
//  HW1 - XYZ Car Rental
//
//  Created by Marcus Novoa on 3/18/19.
//  Copyright © 2019 Marcus Novoa. All rights reserved.
//

#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <string>
using namespace std;

static int defaultPlateNum = 100000;

class Car
{
public:
  enum vehicleType
  {
    Coupe,
    Sedan,
    SUV,
    Exotic,
    None
  };
  Car();
  Car(string plateNumber);
  Car(string plateNumber, string make, string model);
  Car(string plateNumber, string make, string model, vehicleType vt, double price);
  ~Car() {}
  string getInfo()
  {
    cout << "Plate Number: " << this->plateNumber << ", ";
    cout << "Make: " << this->make << ", ";
    cout << "Model: " << this->model << ", ";
    cout << "Vehicle Type: " << this->vType << ", ";
    cout << "Price-per-day: " << this->pricePerDay << ", ";
    cout << "Available: " << (this->isAvailable ? "Yes" : "No");
    return "";
  }
  static vehicleType getVehicleType()
  {
    vehicleType vt;
    return vt;
  };
  bool getAvailability() { return this->isAvailable; }
  void setAvailable(bool);
  bool operator<(const Car &other);
  bool operator==(const Car &other);

private:
  string plateNumber; // Key
  string make;
  string model;
  vehicleType vType;
  double pricePerDay;
  bool isAvailable;
};

std::ostream &operator<<(std::ostream &os, Car &c);

#endif /* Car.hpp */
