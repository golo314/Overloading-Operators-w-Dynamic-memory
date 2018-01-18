/*
Created by Aleksandr Golovin on 1/12/18.
Project Name: Ass1
File Name: turtleprogram.cpp
Copyright � 2018 Aleksandr Golovin. All rights reserved.
*/

//#include "stdafx.h"
#include "turtleprogram.hpp"
#include <exception>

//Overloaded addition operator, calls += operator for arithmitic,
//Returns array with left and right in one
const TurtleProgram TurtleProgram::operator+(const TurtleProgram & rhs) const
{
	TurtleProgram sum = *this;
	return TurtleProgram(sum+=rhs);
}

//Overloaded addition operator, returns array with left and right in one
TurtleProgram & TurtleProgram::operator+=(const TurtleProgram & rhs)
{
	//Create temp array
	int newSz = this->size + rhs.size;
	string * temp = new string[newSz];

	int index = 0;
	int i;

	//Copy one array into temp array
	for (i = 0; i < this->size; i++)
	{
		temp[index] = this->pString[i];
		index++;
	}

	//Copy second array into temp array
	for (i = 0; i < rhs.size; i++)
	{
		temp[index] = rhs.pString[i];
		index++;
	}

	//If existing array not empty, clear it
	if (this->pString != nullptr)
	{
		clear();	
	}

	//Make new array from deleted array
	this->pString = temp;
	this->size = newSz;

	return *this;
}

//Overloaded multiplication operator, calls *= for arithmitic,
//Returns array with contents repeated given number of times
TurtleProgram TurtleProgram::operator*(int times) const
{
	TurtleProgram reslt = *this;
	return TurtleProgram(reslt*=times);
}

//Overloaded multiplication operator,
//Returns array with contents repeated given number of times
TurtleProgram & TurtleProgram::operator*=(int times)
{
	//Safe guard againest unusual times or empty array
	if (times > 0 && this->pString != nullptr)
	{
		//Create new array
		int nwSz = this->size*times;
		string * nwString = new string[nwSz];
		
		int count = 0;
		//Loops while new array not full
		while (count < nwSz)
		{
			//Copies elements to new array
			for (int i = 0; i < this->size; i++)
			{
				nwString[count++] = this->pString[i];
			}
		}

		//Clear old array
		clear();

		//Reassign old array to new array
		this->pString = nwString;
		this->size = nwSz;
	}

	return *this;
}

//Clears array, zeros size, and handles danging pointer
void TurtleProgram::clear()
{
	delete[] this->pString;
	pString = nullptr;
	size = 0;
}

//Overloaded assignment operator, creates a deep copy
TurtleProgram & TurtleProgram::operator=(const TurtleProgram & rhs)
{
	//Safeguard against reassignment
	if (*this != rhs)
	{
		//If array not empty, clear it
		if (this->pString != nullptr)
		{
			clear();
		}

		//Create new array
		this->pString = new string[rhs.size];
		this->size = rhs.size;

		//Loops copying values from one array to another
		for (int i = 0; i < rhs.size; i++)
		{
			this->pString[i] = rhs.pString[i];
		}

	}

	return *this;
}

//Default constructor, nulls all values
TurtleProgram::TurtleProgram() : pString(nullptr), size(0) {};

//Constructor, creates an array with two string, sets size to two
TurtleProgram::TurtleProgram(const string & one, const string & two)
{
	pString = new string[2]{ one,two };
	size = 2;
}

//Copy constructor, uses = operator for deep copy
TurtleProgram::TurtleProgram(const TurtleProgram & rhs)
{
	int nwSz = rhs.size;

	this->pString = new string[nwSz];
	this->size = nwSz;

	*this = rhs;
}

//Overloaded comparison operator, return true if same
bool TurtleProgram::operator==(const TurtleProgram & rhs) const
{
	bool same = true;

	//Makes sure arrays are same size
	if (this->getLength() == rhs.size)
	{
		int count = 0;

		//While the elements are the same and not at end of arrays
		while (same && count < rhs.size)
		{
			if (this->pString[count] != rhs.pString[count]) same = false;
			else count++;
		}
	}
	else
	{
		same = false;
	}

	return same;
}

//Overloaded comparison operator, call == for comparison and returns opposite
bool TurtleProgram::operator!=(const TurtleProgram & rhs) const
{
	return !(*this==rhs);
}

//Returns size of array
int TurtleProgram::getLength() const
{
	return size;
}

//Returns string at given index
const string & TurtleProgram::getIndex(int index) const
{
	//Safeguard to make sure index is valid and array not empty
	if (size > 0 && index >= 0 && index < size)
		return pString[index];
	else
	{
		cout << "We are sorry, the index you entered is out of bounds or array is empty"
			<< "We will give you the last element\n";
		return pString[size - 1];
	}
}

//Sets given index in array to given value
void TurtleProgram::setIndex(int index, const string & newVal)
{
	//Safeguard to make sure index is valid and array not empty
	if (size>0 && index > -1 && index < size)
	{
		pString[index] = newVal;
	}
}

//Destructor, calls clear()
TurtleProgram::~TurtleProgram()
{
	clear();
}

//Overloaded operator to print contents of array
ostream & operator<<(ostream & out, const TurtleProgram & toPrint)
{
	out << "[ ";

	//Loops through array printing values
	for (int i = 0; i < toPrint.size; i++)
	{
		out << toPrint.pString[i] << " ";
	}
	out << "]\n";

	return out;
}

