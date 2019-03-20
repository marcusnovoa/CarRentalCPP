//
//  Program.hpp
//  HW1 - XYZ Car Rental
//
//  Created by Marcus Novoa on 3/18/19.
//  Copyright © 2019 Marcus Novoa. All rights reserved.
//

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <iostream>
#include <string>
#include "UnorderedLinkedList.hpp"

class Program
{
public:
  static void DisplayMenu(UnorderedList *ul);
  static void CarsList(UnorderedList *ul);
  static void AddCar(UnorderedList *ul);
  static void RemoveCar(UnorderedList *ul);
  static void ReturnToMenu(UnorderedList *ul);
};

#endif /* Program.hpp */
