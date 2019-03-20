//
//  UnorderedLinkedList.cpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#include "UnorderedLinkedList.hpp"

void UnorderedLinkedList::MakeEmpty()
{
	Node *temp = nullptr;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	length = 0;
}

void UnorderedLinkedList::PutCar(Car car)
{
	Node *temp = new Node;
	temp->data = car;
	temp->next = head;
	head = temp;
	length++;
}

Car *UnorderedLinkedList::GetCar(Car car)
{
	Node *temp = head;
	while (temp != nullptr)
	{
		if (temp->data == car)
		{
			car = temp->data;
			return &(temp->data);
		}
		temp = temp->next;
	}
	return nullptr;
}

void UnorderedLinkedList::DeleteCar(Car car)
{
	if (head == nullptr)
		return;

	Node *temp;
	if (head->data == car)
	{
		temp = head->next;
		delete head;
		head = temp;
		length--;
		return;
	}
	temp = head;
	while (temp->next != nullptr)
	{
		if (temp->next->data == car)
		{
			Node *temp2 = temp->next;
			temp->next = temp->next->next;
			delete temp2;
			length--;
			return;
		}
		temp = temp->next;
	}
}

void UnorderedLinkedList::ResetList()
{
	currentPos = nullptr;
}

Car *UnorderedLinkedList::GetNextCar()
{
	if (currentPos == nullptr)
		currentPos = head;
	else
		currentPos = currentPos->next;

	return &(currentPos->data);
}

int UnorderedLinkedList::GetLength()
{
	return length;
}

UnorderedLinkedList::~UnorderedLinkedList()
{
	MakeEmpty();
}
