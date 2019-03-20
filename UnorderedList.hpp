//
//  UList.hpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Copyright © 2018 Eugene Lymar. All rights reserved.
//

#ifndef UNORDEREDLIST_HPP
#define UNORDEREDLIST_HPP

#define MAX_ELEMS 100

#include <iostream>
#include <string>
// #include "Item.hpp"

class UnorderedList
{
public:
	virtual void MakeEmpty() = 0;
	template <class T>
	void PutItem(T item);
	template <class T>
	T *GetItem(T item);
	template <class T>
	void DeleteItem(T item);
	virtual void ResetList() = 0;
	template <class T>
	T *GetNextItem();
	virtual int GetLength() = 0;
	virtual ~UnorderedList(){};
};

// std::ostream &operator<<(std::ostream &os, UnorderedList &o);

#endif /* UnorderedList_hpp */
