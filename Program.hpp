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
  static void DisplayMenu(UnorderedLinkedList *ul);
  static void CarsList(UnorderedLinkedList *ul);
  static void AddCar(UnorderedLinkedList *ul);
  static void RemoveCar(UnorderedLinkedList *ul);
  static void ReturnToMenu(UnorderedLinkedList *ul);
};

#endif /* Program.hpp */
