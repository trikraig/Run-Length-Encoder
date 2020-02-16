#include "RunLengthEncoder.h"

string RunLengthEncoder::encodeWord(const string& input)
{
	int length = input.length();

	ostringstream output;

	for (int i = 0; i < length; i++)
	{
		//Counting occurences of current character
		int count = 1;

		while (i < length - 1 && input[i] ==  input[i + 1])
		{
			count++;
			i++;
		}

		//Assembling Final Result string
		output << count << input[i];
	}

	float sizeRatio = static_cast <float> (input.size()) / static_cast <float> (output.str().size());
	compressionSizes.push_back(sizeRatio);

	return output.str();
}

//Will work for strings with more than 10 of the same character. 
//Will not work if original string contained a number before encoding as confuses the count, e.g. kk3p becomes 2k131p which could become 131 instances of p.
string RunLengthEncoder::decodeWord(const string& input)
{
	int length = input.length();
	int count{ 0 };
	int index{ 0 };
	bool isIndex{ true };
	bool isNextDigit{ true };

	ostringstream output;

	for (int i = 0; i < length; i++)
	{
		char c = input[i];

		if (isdigit(c) && isIndex) //c is a number
		{
			//-'0' is shortcut for converting ascii to ints.		
			count = count * 10 + c - '0';
			index = count;
			int inc = 1;
			while (isNextDigit)
			{
				if (input[i + inc] == '0')
				{
					count = count * 10;
					inc++;
				}
				if (isdigit(input[i + inc]))
				{
					count = count * 10 + (input[i + inc] - '0');
					inc++;
				}

				else
				{
					i = inc - 1;
					isNextDigit = false;
					isIndex = false;

				}
			}
		}
		else //c is a letter of the alphabet
		{
			if (count == 0)
			{
				count = 1;
			}
			while (count > 0) //Appends count copies of c to result
			{
				output << c;
				count--;
			}

			isIndex = true;
		}
	}

	return output.str();

}

//Does work if more than 10 instances of a character but does allow encoding of numbers if less than 10 instance, e.g. kk3p.
string RunLengthEncoder::decodeWordAlt(const string& input)
{
	int length = static_cast <int> (input.length());
	int count = 0;
	bool isIndex = true;
	ostringstream output;

	for (int i = 0; i < length; i++)
	{
		char c = input[i];
		if (isdigit(c) && isIndex) //c is a number
		{
			count = count * 10 + c - '0';
			isIndex = false;
		}
		else //c is a letter of the alphabet
		{
			while (count > 0) //Appends count copies of c to result
			{
				output << c;
				count--;
				isIndex = true;
			}
		}
	}

	return output.str();
}

bool RunLengthEncoder::encodeFile(const string& filename)
{
	//Vector is being used for both files so clearing each time to make sure no incorrect data.
	allWords.clear();
	allWordsEncoded.clear();
	compressionSizes.clear();
	ifstream file;
	string word;
	file.open(filename);

	if (!file)
	{
		cerr << filename << " does not exist." << endl;
		return false;
	}
	//Reading all words from file and adding to vector for access and conversion.
	while (file >> word)
	{
		//cout << word << endl;
		allWords.push_back(word);
	}

	//Creating File

	ofstream writer(filename);

	if (!writer)
	{
		cerr << "Error creating file" << endl;
	}

	//Encoding all words in vector, ready to print or print to file.
	for (auto one : allWords)
	{
		string encodedWord = encodeWord(one);
		allWordsEncoded.push_back(encodedWord);
		writer << encodedWord << ' ';
	}

	writer.close();
	file.close();

	//Calculating Compression Ratio -----------------------------------------------

	float compressionRatio{ 0 };

	for (int i = 0; i < compressionSizes.size(); i++)
	{
		compressionRatio += compressionSizes[i];
	}

	//-----------------------------------------------------------------------------

	cout << "Encoding complete. Please see directory for result.txt \nFile Compression Ratio: " << compressionRatio << endl;

	return true;
}

bool RunLengthEncoder::decodeFile(const string& filename, const bool& oriContainedNumber)
{
	allWords.clear();
	allWordsEncoded.clear();
	ifstream file;
	string word;
	file.open(filename);

	if (!file)
	{
		cerr << filename << " does not exist." << endl;
		return false;
	}

	//Reading all words from file and adding to vector for access and conversion.
	while (file >> word)
	{
		//cout << word << endl;
		allWordsEncoded.push_back(word);
	}

	//Creating File

	ofstream writer(filename);

	if (!writer)
	{
		cerr << "Error creating file" << endl;
	}

	//If file contains any strings like kk3p where number is in string then uses alt function. 
	if (oriContainedNumber)
	{
		for (auto one : allWordsEncoded)
		{
			string decodedWord = decodeWordAlt(one);
			allWords.push_back(decodedWord);
			writer << decodedWord << ' ';
		}
	}
	else
	{
		for (auto one : allWordsEncoded)
		{
			string decodedWord = decodeWord(one);
			allWords.push_back(decodedWord);
			writer << decodedWord << ' ';
		}
	}

	writer.close();
	file.close();

	cout << "Decoding complete. Please see data directory for result" << endl;


	return true;
}
