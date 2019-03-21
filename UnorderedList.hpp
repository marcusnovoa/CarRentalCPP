//
//  UList.hpp
//  UList
//
//  Created by Eugene Lymar on 1/30/18.
//  Modified by Marcus Novoa on 3/19/19.
//  Copyright © 2019 Marcus Novoa. All rights reserved.
//

#ifndef UNORDEREDLIST_HPP
#define UNORDEREDLIST_HPP

#define MAX_ELEMS 100

#include <iostream>
#include <string>

class UnorderedList
{
public:
	virtual void MakeEmpty() = 0;
	virtual void ResetList() = 0;
	virtual int GetLength() = 0;
	virtual ~UnorderedList(){};
};

#endif /* UnorderedList_hpp */
