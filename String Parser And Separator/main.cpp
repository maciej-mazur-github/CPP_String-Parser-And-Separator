#include "StringParserSeparator.h"

int main(void)
{
	StringParserSeparator parser;
	string input;
	string evenOrderWords, oddOrderWords;


	parser.loadString(input);
	parser.separateEvenOddOrderNumberWords(input, oddOrderWords, evenOrderWords);
	parser.separateEvenOddCharacterAmountWords(input, oddOrderWords, evenOrderWords);
}