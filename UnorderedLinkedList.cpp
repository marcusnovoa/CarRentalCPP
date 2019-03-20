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

// template <class T>
// void UnorderedLinkedList::PutItem(T item)
// {
// 	Node *temp = new Node;
// 	temp->data = item;
// 	temp->next = head;
// 	head = temp;
// 	length++;
// }

// template <class T>
// T *UnorderedLinkedList::GetItem(T item)
// {
// 	Node *temp = head;
// 	while (temp != nullptr)
// 	{
// 		if (temp->data == item)
// 		{
// 			item = temp->data;
// 			return &(temp->data);
// 		}
// 		temp = temp->next;
// 	}
// 	return nullptr;
// }

// template <class T>
// void UnorderedLinkedList::DeleteItem(T item)
// {
// 	if (head == nullptr)
// 		return;

// 	Node *temp;
// 	if (head->data == item)
// 	{
// 		temp = head->next;
// 		delete head;
// 		head = temp;
// 		length--;
// 		return;
// 	}
// 	temp = head;
// 	while (temp->next != nullptr)
// 	{
// 		if (temp->next->data == item)
// 		{
// 			Node *temp2 = temp->next;
// 			temp->next = temp->next->next;
// 			delete temp2;
// 			length--;
// 			return;
// 		}
// 		temp = temp->next;
// 	}
// }

void UnorderedLinkedList::ResetList()
{
	currentPos = nullptr;
}

// template <class T>
// T *UnorderedLinkedList::GetNextItem()
// {
// 	if (currentPos == nullptr)
// 		currentPos = head;
// 	else
// 		currentPos = currentPos->next;

// 	return &(currentPos->data);
// }

int UnorderedLinkedList::GetLength()
{
	return length;
}

UnorderedLinkedList::~UnorderedLinkedList()
{
	MakeEmpty();
}

std::ostream &operator<<(std::ostream &os, UnorderedLinkedList &o)
{
	o.ResetList();
	os << "List: [";
	for (int i = 0; i < o.GetLength(); ++i)
	{
		os << "(" << *o.GetNextItem<Car>() << ")";
		if (i < o.GetLength() - 1)
			os << ", ";
	}
	os << "]";
	return os;
}
