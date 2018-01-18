/*
	Created by Aleksandr Golovin on 1/12/18.
	Project Name: Ass1
	File Name: ass1.cpp
	Copyright � 2018 Aleksandr Golovin. All rights reserved.
*/

//#include "stdafx.h"
#include <iostream>
#include "turtleprogram.hpp"

#include <fstream>

using namespace std;

int main()
{

	//Sample Test Code to make sure everything works
	TurtleProgram tp1;
	cout << "tp1: " << tp1 << endl;
	TurtleProgram tp2("F", "10");
	cout << "tp2: " << tp2 << endl;
	TurtleProgram tp3("R", "90");
	tp1 = tp2 + tp3;
	cout << "tp1 now as tp2+tp3: " << tp1 << endl;
	tp1 = tp2 * 3;
	cout << "tp1 now as tp2 * 3: " << tp1 << endl;
	TurtleProgram tp4(tp1);
	cout << "tp4 is a copy of tp1: " << tp4 << endl;
	TurtleProgram tp5("F", "10");
	cout << "tp5: " << tp5 << endl;
	cout << boolalpha;
	cout << "tp2 and tp5 are == to each other: " << (tp2 == tp5) << endl;
	cout << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
	cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
	tp2.setIndex(0, "R");
	tp2.setIndex(1, "90");
	cout << "tp2 after 2 calls to setIndex: " << tp2 << endl;
	cout << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;
	TurtleProgram tp6("L", "25");
	cout << "tp6 before += tp5: " << tp6 << endl;
	tp6 += tp5;
	cout << "tp6 after += tp5: " << tp6 << endl;
	cout << "tp3 before *= 4: " << tp3 << endl;
	tp3 *= 4;
	cout << "tp3 after *= 4: " << tp3 << endl;
	cout << tp6.getIndex(20) << endl;
	cout << "Done." << endl;

	//system("pause");
	return 0;
}

