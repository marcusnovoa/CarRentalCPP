//
//  main.cpp
//  HW1 - XYZ Car Rental
//
//  Created by Marcus Novoa on 3/18/19.
//  Copyright © 2019 Marcus Novoa. All rights reserved.
//

#include <iostream>
#include "Car.hpp"
#include "Reservation.hpp"
#include "Program.hpp"
#include "UnorderedLinkedList.hpp"

int main(int argc, char const *argv[])
{
  auto carList = new UnorderedLinkedList<Car>();
  auto resList = new UnorderedLinkedList<Reservation>();
  Program<Car, Reservation>::CarsList(carList, resList);
  Program<Car, Reservation>::DisplayMenu(carList, resList);
  delete carList;
  delete resList;
  return 0;
}
