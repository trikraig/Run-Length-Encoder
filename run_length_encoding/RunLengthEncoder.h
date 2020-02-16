#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class RunLengthEncoder
{
private:

	std::vector <std::string> allWords, allWordsEncoded;
	std::vector <float> compressionSizes;


public:

	string encodeWord(const string& input);
	string decodeWord(const string& input);
	string decodeWordAlt(const string& input);
	bool encodeFile(const string& filename);
	bool decodeFile(const string& filename, const bool& oriContainedNumber);


};

