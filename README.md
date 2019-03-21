## Car Rental Console Application
Developed by Marcus Novoa

A console application used to rent vehicles from XYZ Car Rentals, a fictional car rental service.

This project was built using C++.

### Main Menu  
![Main Menu](./img/1_menu.png?raw=true "CarRentalCPP Main Menu")
The main menu lists 7 options to choose from.

### Adding a car  
![Empty Car Inventory](./img/2_list-cars-1.png?raw=true "CarRentalCPP Empty Car Inventory")
The inventory is currently empty.

![Menu Option 1 - Add Car](./img/3_add-car.png?raw=true "CarRentalCPP Menu Option 1 - Add car")
To add a car, users are asked to enter all required vehicle information.

![Updated Car Inventory](./img/4_list-cars-2.png?raw=true "CarRentalCPP Updated Car Inventory")
Here, we can see our vehicle has been successfully added to the inventory list.

### Adding a reservation
![Empty Reservation List](./img/5_list-res-1.png?raw=true "CarRentalCPP Empty Reservation List")
Next, we can consider adding a reservation. There are currently no reservations in place.

![Menu Option 5 - Add Reservation](./img/6_add-res-1.png?raw=true "CarRentalCPP Menu Option 5 - Add Reservation")
Adding a reservation simply requires a user's full name and a license plate number. If the plate number is found within the inventory, the reservation is made.

![Car Availability - False](./img/7_list-cars-2.png?raw=true "CarRentalCPP Car Availability - False")
Here, we can see the reserved vehicle has had its availability changed to false, or "No".

![Updated Reservation List](./img/8_list-res-2.png?raw=true "CarRentalCPP Updated Reservation List")
We can also view our confirmed reservation listed here.

### Removing a reservation
![Menu Option 6 - Cancel Reservation](./img/9_rem-res-1.png?raw=true "CarRentalCPP Menu Option 6 - Cancel Reservation")
Removing a reservation requires a user's full name and a license plate number, once again. If the plate number is found within the reservation list, the reservation is removed.

![Updated Reservation List 2](./img/10_list-res-3.png?raw=true "CarRentalCPP Updated Reservation List 2")
Here, we can see our reservation has been successfully removed.

![Updated Car Inventory 2](./img/11_list-cars-3.png?raw=true "CarRentalCPP Updated Car Inventory 2")
The previously reserved vehicle has also had its availability set back to true, or "Yes".

### Removing a car
![Menu Option 3 - Remove Car](./img/12_rem-car-1.png?raw=true "CarRentalCPP Menu Option 3 - Remove Car")
To remove a car, all that is required is a license plate number. If it is found within the inventory, the vehicle is removed.

![Updated Car Inventory 3](./img/13_list-cars-4.png?raw=true "CarRentalCPP Updated Car Inventory 3")
Here, we can see our vehicle has been successfully removed from the inventory list.

### Exit
![Menu Option 7 - Exit](./img/14_exit.png?raw=true "CarRentalCPP Menu Option 7 - Exit")
Lastly, users can exit the program using option 7.
