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

template <class T, class T2>
class Program
{
public:
  /***** MENU *****/
  static void displayMenu(UnorderedLinkedList<T> *cl, UnorderedLinkedList<T2> *rl)
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
      cout << "5. Add a reservation" << endl;
      cout << "6. Cancel reservation" << endl;
      cout << "7. Exit\n\n";

      cout << "Choose an option: ";
      cin >> choice;
      cout << endl;

      switch (choice)
      {
      case 1:
        if (cl->GetLength() < 1)
        {
          cout << "There are no cars in the list." << endl;
          Program<T, T2>::returnToMenu(cl, rl);
        }
        else
        {
          cout << *cl << endl;
          Program<T, T2>::returnToMenu(cl, rl);
        }
        break;
      case 2:
        addCar(cl, rl);
        break;
      case 3:
        removeCar(cl, rl);
        break;
      case 4:
        if (rl->GetLength() < 1)
        {
          cout << "There are no current reservations." << endl;
          Program<T, T2>::returnToMenu(cl, rl);
        }
        else
        {
          cout << *rl << endl;
          Program<T, T2>::returnToMenu(cl, rl);
        }
        break;
      case 5:
        addReservation(cl, rl);
        break;
      case 6:
        cancelReservation(cl, rl);
        break;
      case 7:
        cout << "Exiting...\n\n";
        menuActive = false;
        break;
      }
    }
  }

  static void returnToMenu(UnorderedLinkedList<T> *cl, UnorderedLinkedList<T2> *rl)
  {
    char returnToMenu;
    cout << "Press Enter key to return to menu..." << endl;
    returnToMenu = getchar();
    switch (returnToMenu)
    {
    case 10 | 13:
      Program<T, T2>::displayMenu(cl, rl);
    default:
      returnToMenu = getchar();
    }
  }

  /***** CARS *****/
  static void addCar(UnorderedLinkedList<T> *cl, UnorderedLinkedList<T2> *rl)
  {
    string plate, make, model;
    Car::vehicleType vType;
    int vehicleTypeChoice;
    double price;
    bool available;

    cout << "Please enter all vehicle information:" << endl;
    cout << "License Plate Number: ";
    cin >> plate;

    // Check if license plate number exists
    auto c = new Car(plate);
    if (cl->GetItem(*c) != nullptr)
    {
      cout << "Car with license plate number " << plate << " already exists." << endl;
    }
    else
    {
      cin.ignore();
      cout << "Make: ";
      getline(cin, make);
      cout << "Model: ";
      getline(cin, model);
      cout << "Enter the number of your vehicle type:" << endl;
      cout << "1. Coupe" << endl;
      cout << "2. Sedan" << endl;
      cout << "3. SUV" << endl;
      cout << "4. Exotic" << endl;
      cin >> vehicleTypeChoice;
      switch (vehicleTypeChoice - 1)
      {
      case 0:
        vType = Car::vehicleType::Coupe;
        break;
      case 1:
        vType = Car::vehicleType::Sedan;
        break;
      case 2:
        vType = Car::vehicleType::SUV;
        break;
      case 3:
        vType = Car::vehicleType::Exotic;
        break;
      }
      cout << "Price-per-day: ";
      cin >> price;

      cl->PutItem(Car(plate, make, model, vType, price));
      cout << "Car has been added to the list!" << endl;
    }
    delete c;
    Program<T, T2>::returnToMenu(cl, rl);
  }
  static void removeCar(UnorderedLinkedList<T> *cl, UnorderedLinkedList<T2> *rl)
  {
    string plate;
    cout << "Please enter the license plate number of the vehicle you wish to delete:" << endl;
    cin >> plate;
    cout << endl;

    auto c = new Car(plate);
    if (cl->GetItem(*c) != nullptr)
    {
      cl->DeleteItem(*c);
      cout << "Car with license plate number " << plate << " has successfully been removed from the list." << endl;
    }
    else
    {
      cout << "Car was not found within the list." << endl;
    }
    Program<T, T2>::returnToMenu(cl, rl);
  }
  // static void carsList(UnorderedLinkedList<T> *cl, UnorderedLinkedList<T2> *rl)
  // {
  //   // cout << "List Length: " << cl->GetLength() << endl;
  //   // auto cars = {Car(), Car(), Car()};
  //   auto cars = {Car("A2GH78", "Honda", "Civic"), Car("B3G78A", "Subaru", "WRX STI"), Car("C41AWL", "Toyota", "Corolla")};
  //   for (auto i : cars)
  //     cl->PutItem(i);
  //   cout << cl->GetLength() << " cars created!" << endl;
  //   // cout << "List Length: " << cl->GetLength() << endl;
  //   // cout << *cl << endl;
  // }

  /***** RESERVATIONS *****/
  static void addReservation(UnorderedLinkedList<T> *cl, UnorderedLinkedList<T2> *rl)
  {
    string name, plate;
    cout << "Please enter all reservation information:" << endl;
    cin.ignore();
    cout << "Full Name: ";
    getline(cin, name);
    cout << "Rented Vehicle License Plate Number: ";
    cin >> plate;

    // Find Car
    auto c = new Car(plate);
    if (cl->GetItem(*c) != nullptr)
    {
      auto *car = cl->GetItem(*c);
      if (car->getAvailability() == false)
        cout << "Car with license plate number " << plate << " has already been reserved." << endl;
      else
      {
        car->setAvailable(false);
        rl->PutItem(Reservation(name, plate));
        cout << "Car with license plate number " << plate << " has successfully been reserved.\n\n";
      }
    }
    else
    {
      cout << "Car was not found within the list." << endl;
    }
    delete c;
    Program<T, T2>::returnToMenu(cl, rl);
  }
  static void cancelReservation(UnorderedLinkedList<T> *cl, UnorderedLinkedList<T2> *rl)
  {
    string name, plate;
    cout << "Please enter reservation cancellation information:" << endl;
    cin.ignore();
    cout << "Full Name: ";
    getline(cin, name);
    cout << "Rented Vehicle License Plate Number: ";
    cin >> plate;

    auto r = new Reservation(name, plate);
    auto c = new Car(plate);

    // Find Reservation
    if (rl->GetItem(*r) != nullptr)
    {
      auto *car = cl->GetItem(*c);
      if (car)
      {
        car->setAvailable(true);
        rl->DeleteItem(*r);
        cout << "Reservation under " << name << " has successfully been cancelled.\n\n";
      }
      else
      {
        cout << "Reservation was not found within the list." << endl;
      }
    }
    else
    {
      cout << "Reservation was not found within the list." << endl;
    }

    delete r;
    delete c;
    Program<T, T2>::returnToMenu(cl, rl);
  }
};

#endif /* Program.hpp */
