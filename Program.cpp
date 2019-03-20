//
//  Program.cpp
//  HW1 - XYZ Car Rental
//
//  Created by Marcus Novoa on 3/18/19.
//  Copyright © 2019 Marcus Novoa. All rights reserved.
//

#include <string>
#include "Car.hpp"
#include "Program.hpp"

using namespace std;

void Program::DisplayMenu(UnorderedList *ul)
{
  int choice;
  bool menuActive = true;

  while (menuActive)
  {
    cout << "-------------------------------------------" << endl;
    cout << "XYZ Car Rental" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "1. List all cars" << endl;
    cout << "2. Add car to inventory" << endl;
    cout << "3. Remove car from inventory" << endl;
    cout << "4. List all reservations" << endl;
    cout << "5. Add a reservations" << endl;
    cout << "6. Cancel reservation" << endl;
    cout << "7. Exit\n\n";

    cout << "Choose an option: ";
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
      if (ul->GetLength() < 1)
      {
        cout << "There are no cars in the list." << endl;
        Program::ReturnToMenu(ul);
      }
      else
      {
        cout << *ul << endl;
        Program::ReturnToMenu(ul);
      }
      break;
    case 2:
      AddCar(ul);
      break;
    case 3:
      RemoveCar(ul);
      break;
    case 7:
      cout << "Exiting...\n\n";
      menuActive = false;
      break;
    }
  }
}

void Program::CarsList(UnorderedList *ul)
{
  // cout << "List Length: " << ul->GetLength() << endl;
  // auto cars = {Car(), Car(), Car()};
  auto cars = {Car("A2GH78", "Honda", "Civic"), Car("B3G78A", "Subaru", "WRX STI"), Car("C41AWL", "Toyota", "Corolla")};
  for (auto i : cars)
    ul->PutCar(i);
  cout << ul->GetLength() << " cars created!" << endl;
  // cout << "List Length: " << ul->GetLength() << endl;
  // cout << *ul << endl;
}

void Program::AddCar(UnorderedList *ul)
{
  string plate, make, model;
  double price;
  bool available;

  cout << "Please enter all vehicle information:" << endl;
  cout << "License Plate Number: ";
  cin >> plate;
  cin.ignore();
  cout << "Make: ";
  getline(cin, make);
  cout << "Model: ";
  getline(cin, model);
  cout << "Price-per-day: ";
  cin >> price;

  ul->PutCar(Car(plate, make, model, price));
  cout << "Car has been added to the list!" << endl;

  Program::ReturnToMenu(ul);
}

void Program::RemoveCar(UnorderedList *ul)
{
  string plate;
  cout << "Please enter the license plate number of the vehicle you wish to delete:" << endl;
  cin >> plate;
  cout << endl;

  auto c = new Car(plate);
  if (ul->GetCar(*c) != nullptr)
  {
    ul->DeleteCar(*c);
    cout << "Car with license plate number " << plate << " has successfully been removed from the list.\n\n";
  }
  else
  {
    cout << "Car was not found within the list." << endl;
    Program::ReturnToMenu(ul);
  }
}

void Program::ReturnToMenu(UnorderedList *ul)
{
  char returnToMenu;
  cout << "Press Enter key to return to menu..." << endl;
  returnToMenu = getchar();
  switch (returnToMenu)
  {
  case 10 | 13:
    Program::DisplayMenu(ul);
  default:
    returnToMenu = getchar();
  }
}
