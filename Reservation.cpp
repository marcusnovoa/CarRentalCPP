//
//  Reservation.cpp
//  HW1 - XYZ Car Rental
//
//  Created by Marcus Novoa on 3/19/19.
//  Copyright © 2019 Marcus Novoa. All rights reserved.
//

#include "Reservation.hpp"

Reservation::Reservation() : name{"N/A"},
                             vehicleRented{"N/A"}
{
}

Reservation::Reservation(string name, string vehicle) : name{name},
                                                        vehicleRented{vehicle}
{
}

bool Reservation::operator<(const Reservation &other)
{
  return name < other.name;
}

bool Reservation::operator==(const Reservation &other)
{
  return name == other.name;
}

std::ostream &operator<<(std::ostream &os, Reservation &r)
{
  os << "Reservation: [" << r.GetInfo() << "]";
  return os;
}
