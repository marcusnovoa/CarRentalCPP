//
//  UnorderedLinkedList.hpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Modified by Marcus Novoa on 3/19/19.
//  Copyright © 2019 Marcus Novoa. All rights reserved.
//

#ifndef UNORDEREDLINKEDLIST_HPP
#define UNORDEREDLINKEDLIST_HPP

#include <iostream>
#include <string>
#include "UnorderedList.hpp"
#include "Node.hpp"

template <class T>
class UnorderedLinkedList : public UnorderedList
{
private:
	int length;
	Node<T> *currentPos;
	Node<T> *head;

public:
	UnorderedLinkedList() : currentPos{nullptr}, head{nullptr}, length{0} {}

	void MakeEmpty()
	{
		Node<T> *temp = nullptr;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		length = 0;
	}

	~UnorderedLinkedList<T>()
	{
		MakeEmpty();
	}

	// template <class T>
	void PutItem(T item)
	{
		Node<T> *temp = new Node<T>;
		temp->data = item;
		temp->next = head;
		head = temp;
		length++;
	}

	// template <class T>
	T *GetItem(T item)
	{
		Node<T> *temp = head;
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

	// template <class T>
	void DeleteItem(T item)
	{
		if (head == nullptr)
			return;

		Node<T> *temp;
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
				Node<T> *temp2 = temp->next;
				temp->next = temp->next->next;
				delete temp2;
				length--;
				return;
			}
			temp = temp->next;
		}
	}

	void ResetList()
	{
		currentPos = nullptr;
	}

	// template <class T>
	T *GetNextItem()
	{
		if (currentPos == nullptr)
			currentPos = head;
		else
			currentPos = currentPos->next;

		return &(currentPos->data);
	}

	int GetLength()
	{
		return length;
	}

	friend std::ostream &operator<<(std::ostream &os, UnorderedLinkedList<T> &o)
	{
		o.ResetList();
		os << "List: [";
		for (int i = 0; i < o.GetLength(); ++i)
		{
			os << "(" << *o.GetNextItem() << ")";
			if (i < o.GetLength() - 1)
				os << ", ";
		}
		os << "]";
		return os;
	}
};

#endif /* UnorderedLinkedList_hpp */
