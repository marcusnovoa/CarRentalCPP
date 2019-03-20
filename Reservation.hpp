//
//  Reservation.hpp
//  HW1 - XYZ Car Rental
//
//  Created by Marcus Novoa on 3/18/19.
//  Copyright © 2019 Marcus Novoa. All rights reserved.
//

#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <iostream>
#include <string>
using namespace std;

class Reservation
{
private:
  string name;          // Key
  string vehicleRented; // Plate of the car which is our key for the list
public:
  Reservation(string name, string vehicle);
  ~Reservation() {}
  string GetInfo()
  {
    cout << "Name: " << this->name << ", ";
    cout << "Rented Vehicle: " << this->vehicleRented;
    return "";
  }
  bool operator<(const Reservation &other);
  bool operator==(const Reservation &other);
};

std::ostream &operator<<(std::ostream &os, Reservation &r);

#endif /* Reservation.hpp */
