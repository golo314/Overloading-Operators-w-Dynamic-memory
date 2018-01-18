/*
Created by Aleksandr Golovin on 1/12/18.
Project Name: Ass1
File Name: turtleprogram.hpp
Copyright © 2018 Aleksandr Golovin. All rights reserved.
*/

#include <string>
#include <iostream>

using namespace std;

//Guard, to keep from recompilation
#ifndef turtleprogram_h
#define turtleprogram_h

class TurtleProgram
{
private:

	string * pString;
	int size;

	//Helper function to clear pString
	void clear();

public:

	//Friend overloaded operator to print contents of array
	friend ostream & operator << (ostream &out, const TurtleProgram & toPrint);

	//Overloaded equal operator, makes deep copy of array
	TurtleProgram & operator = (const TurtleProgram & rhs);

	//Overloaded addition operator, adds two arrays together
	const TurtleProgram operator+(const TurtleProgram & rhs)const;
	TurtleProgram & operator +=(const TurtleProgram & rhs);

	//Overloaded multiplication operator,
	//Repeats instructions in array the number of given times
	TurtleProgram operator *(int times)const;
	TurtleProgram & operator *=(int times);

	//Default constructor
	TurtleProgram();

	//Constructor that take two string to put into array
	TurtleProgram(const string & one, const string & two);

	//Copy constructor
	TurtleProgram(const TurtleProgram & rhs);

	//Overloaded comparison operator, return true if same
	bool operator ==(const TurtleProgram & rhs) const;

	//Overloaded not equal operator, return false if same
	bool operator !=(const TurtleProgram & rhs) const;

	//Returns number of elements in array
	int getLength() const;

	//Return the string at a given index
	const string & getIndex(int index) const;

	//Given an index, the element of array is assigned a given value
	void setIndex(int index, const string & newVal);

	//Destructor
	~TurtleProgram();
};

#endif // turtleprogram_h