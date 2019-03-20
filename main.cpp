//
//  main.cpp
//  HW1 - XYZ Car Rental
//
//  Created by Marcus Novoa on 3/18/19.
//  Copyright © 2019 Marcus Novoa. All rights reserved.
//

#include <iostream>
#include "Car.hpp"
#include "Program.hpp"
#include "UnorderedLinkedList.hpp"

int main(int argc, char const *argv[])
{
  auto ull = new UnorderedLinkedList();
  Program::CarsList(ull);
  Program::DisplayMenu(ull);
  delete ull;
  return 0;
}
