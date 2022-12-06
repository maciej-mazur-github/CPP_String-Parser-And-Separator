#pragma once
#include <iostream>

using namespace std;

class StringParserSeparator
{
public:
	void loadString(string& inputString);
	void separateEvenOddOrderNumberWords(string sourceString, string oddWordsString, string evenWordsString);
	void separateEvenOddCharacterAmountWords(string sourceString, string oddWordsString, string evenWordsString);
};


