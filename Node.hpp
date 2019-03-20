#ifndef Node_hpp
#define Node_hpp

#include "Car.hpp"
#include "Reservation.hpp"

template <typename T>
struct Node
{
  T data;
  Node *next;
};

#endif
