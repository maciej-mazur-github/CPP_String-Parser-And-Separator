#include "StringParserSeparator.h"
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;


void StringParserSeparator::separateEvenOddCharacterAmountWords(string sourceString, string oddWordsString, string evenWordsString)
{
	if (sourceString.compare("") == 0)
	{
		cout << "The provided source string is empty. Please use a non-empty string or use the method loadString to generate one.\n";
		return;
	}

	int sourceIterator = 0;
	int characterCounter = 0;
	int sourceLength = sourceString.length();
	string tempString;

	while (sourceIterator < sourceLength)
	{
		while ((sourceString[sourceIterator] == 9 || sourceString[sourceIterator] == 32) && sourceIterator < sourceLength)    // if inspected source character is either space or tab; also guarded the case where inputString is full of space characters
		{
			sourceIterator++;
		}

		if ((sourceString[sourceIterator] >= 48 && sourceString[sourceIterator] <= 57)
			|| (sourceString[sourceIterator] >= 65 && sourceString[sourceIterator] <= 90)
			|| (sourceString[sourceIterator] >= 97 && sourceString[sourceIterator] <= 122))   //   to filter out only digits and all letters (lower and uppercase)
		{
			while (sourceString[sourceIterator] != 9 && sourceString[sourceIterator] != 32 && sourceIterator < sourceLength)  // if inspected source character is either space or tab
			{
				if ((sourceString[sourceIterator] >= 48 && sourceString[sourceIterator] <= 57)
					|| (sourceString[sourceIterator] >= 65 && sourceString[sourceIterator] <= 90)
					|| (sourceString[sourceIterator] >= 97 && sourceString[sourceIterator] <= 122))
				{
					tempString += sourceString[sourceIterator];
					characterCounter++;
				}

				sourceIterator++;
			}

			tempString += " ";   // add space to separate consecutive words in output strings

			if (characterCounter % 2)
			{
				oddWordsString += tempString;
			}
			else
			{
				evenWordsString += tempString;
			}

			characterCounter = 0;
			tempString = "";
		}
		else
		{
			sourceIterator++;       // in case character ASCII code is not digit nor letter then it will not be saved to any of output arrays but still the sourceIterator needs to be moved on
		}
	}


	cout << "\n\n***********************************************************************\n";
	cout << "Array of words having odd amount of characters is as follows:\n\t";
	cout << oddWordsString << endl << endl;

	cout << "\nArray of words having even amount of characters is as follows:\n\t";
	cout << evenWordsString << endl << endl;
	cout << "***********************************************************************\n";
}


void StringParserSeparator::separateEvenOddOrderNumberWords(string sourceString, string oddWordsString, string evenWordsString)
{
	if (sourceString.compare("") == 0)
	{
		cout << "The provided source string is empty. Please use a non-empty string or use the method loadString to generate one.\n";
		return;
	}
	
	int sourceIterator = 0;
	int oddIterator = 0;
	int evenIterator = 0;
	int wordCounter = 0;
	int sourceLength = sourceString.length();

	while (sourceIterator < sourceLength)
	{
		while ((sourceString[sourceIterator] == 9 || sourceString[sourceIterator] == 32) && sourceIterator < sourceLength)    // if inspected source character is either space or tab; also guarded the case where inputString is full of space characters
		{
			sourceIterator++;
		}

		if ((sourceString[sourceIterator] >= 48 && sourceString[sourceIterator] <= 57)
			|| (sourceString[sourceIterator] >= 65 && sourceString[sourceIterator] <= 90)
			|| (sourceString[sourceIterator] >= 97 && sourceString[sourceIterator] <= 122))   //   to filter out only digits and all letters (lower and uppercase)
		{
			wordCounter++;

			if (wordCounter % 2)   // if this now the word of odd order number
			{
				while (sourceString[sourceIterator] != 9 && sourceString[sourceIterator] != 32 && sourceIterator < sourceLength)  // if inspected source character is either space or tab
				{
					if ((sourceString[sourceIterator] >= 48 && sourceString[sourceIterator] <= 57)
						|| (sourceString[sourceIterator] >= 65 && sourceString[sourceIterator] <= 90)
						|| (sourceString[sourceIterator] >= 97 && sourceString[sourceIterator] <= 122))
					{
						oddWordsString += sourceString[sourceIterator];
						oddIterator++;
					}

					sourceIterator++;
				}

				oddWordsString += 32;     // put space where the word ended
				oddIterator++;
			}
			else           // if this now the word of even order number
			{
				while (sourceString[sourceIterator] != 9 && sourceString[sourceIterator] != 32 && sourceIterator < sourceLength)  // if inspected source character is either space or tab
				{
					if ((sourceString[sourceIterator] >= 48 && sourceString[sourceIterator] <= 57)
						|| (sourceString[sourceIterator] >= 65 && sourceString[sourceIterator] <= 90)
						|| (sourceString[sourceIterator] >= 97 && sourceString[sourceIterator] <= 122))
					{
						evenWordsString += sourceString[sourceIterator];
						evenIterator++;
					}

					sourceIterator++;
				}

				evenWordsString += 32;     // put space where the word ended
				evenIterator++;
			}
		}
		else
		{
			sourceIterator++;       // in case character ASCII code is not digit nor letter then it will not be saved to any of output arrays but still the sourceIterator needs to be moved on
		}
	}


	cout << "\n\n***********************************************************************\n";
	cout << "Array of words of odd order number is as follows:\n\t";
	cout << oddWordsString << endl << endl;

	cout << "\nArray of words of even order number is as follows:\n\t";
	cout << evenWordsString << endl << endl;
	cout << "***********************************************************************\n";

}




void StringParserSeparator::loadString(string& inputString)
{
	if (inputString.length() > 0)           // if the provided string is a non-empty legit string
	{
		cout << "The provided string is not empty, therefore no manual filling in will be processed.\n";
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

}