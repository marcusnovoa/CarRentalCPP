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
private:
  string plateNumber; // Key
  string make;
  string model;
  enum vehicleType
  {
    coupe,
    sedan,
    suv,
    exotic
  };
  double pricePerDay;
  bool isAvailable;

public:
  Car();
  Car(string plateNumber);
  Car(string plateNumber, string make, string model);
  Car(string plateNumber, string make, string model, double price);
  ~Car() {}
  string GetInfo()
  {
    cout << "Plate Number: " << this->plateNumber << ", ";
    cout << "Make: " << this->make << ", ";
    cout << "Model: " << this->model << ", ";
    // cout << "Vehicle Type: " << this->vehicleType << ", ";
    cout << "Price-per-day: " << this->pricePerDay << ", ";
    cout << "Available: " << (this->isAvailable ? "Yes" : "No");
    return "";
  }
  void SetAvailable(bool);
  bool operator<(const Car &other);
  bool operator==(const Car &other);
};

std::ostream &operator<<(std::ostream &os, Car &c);

#endif /* Car.hpp */
