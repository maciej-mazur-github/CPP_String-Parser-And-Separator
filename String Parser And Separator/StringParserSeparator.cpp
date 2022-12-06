#include "StringParserSeparator.h"
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

void StringParserSeparator::loadString(string& inputString)
{
	if (inputString.length() > 0)           // if the provided string is a non-empty legit string
	{
		this->inputString = &inputString;
		return;
	}

	// otherwise the user needs to fill it in manually

	cout << "As the provided String is empty you need to fill it in now. \nThe text you will type will be saved until you press 'enter' key:\n\t";

	char character = _getch();
	cout << character;

	while (character != 13)    // until enter key (ASCII 13) is pressed
	{
		inputString += character;
		character = _getch();
		cout << character;
	}

	cout << "\n\nThe entered character array is as follows:\n\t";
	cout << inputString;
	this->inputString = &inputString;

}