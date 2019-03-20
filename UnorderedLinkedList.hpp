//
//  UnorderedLinkedList.hpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef UnorderedLinkedList_hpp
#define UnorderedLinkedList_hpp

#include <iostream>
#include <string>
#include "UnorderedList.hpp"
#include "Node.hpp"

class UnorderedLinkedList : public UnorderedList
{
private:
	int length;
	Node *currentPos;
	Node *head;

public:
	UnorderedLinkedList() : currentPos{nullptr}, head{nullptr}, length{0} {}
	~UnorderedLinkedList();

	void MakeEmpty();

	template <class T>
	void PutItem(T item)
	{
		Node *temp = new Node;
		temp->data = item;
		temp->next = head;
		head = temp;
		length++;
	}

	template <class T>
	T *GetItem(T item)
	{
		Node *temp = head;
		while (temp != nullptr)
		{
			if (temp->data == item)
			{
				item = temp->data;
				return &(temp->data);
			}
			temp = temp->next;
		}
		return nullptr;
	}

	template <class T>
	void DeleteItem(T item)
	{
		if (head == nullptr)
			return;

		Node *temp;
		if (head->data == item)
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
			if (temp->next->data == item)
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

	void ResetList();

	template <class T>
	T *GetNextItem()
	{
		if (currentPos == nullptr)
			currentPos = head;
		else
			currentPos = currentPos->next;

		return &(currentPos->data);
	}

	int GetLength();
};

std::ostream &operator<<(std::ostream &os, UnorderedLinkedList &o);

#endif /* UnorderedLinkedList_hpp */
