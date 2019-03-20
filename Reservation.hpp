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
  Reservation() {}
  ~Reservation() {}
};

#endif /* Reservation.hpp */
