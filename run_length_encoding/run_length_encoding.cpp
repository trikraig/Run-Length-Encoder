#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

string printEncode(const string& input)
{
	int length = input.length();
	
	ostringstream output;

	for (int i = 0; i < length; i++)
	{
		//Counting occurences of current character
		int count = 1;

		while (i < length - 1 && input[i] == input[i + 1])
		{
			count++;
			i++;
		}

		//Assembling Final Result string
		output << count << input[i];
	}

	
	return output.str();
}

bool readFile(const string& filename, vector <string>& wordsFromFile)
{
	vector <string> wordsFromFile;
	ifstream file;
	string word;
	char x;
	file.open(filename);

	if (!file)
	{
		cerr << filename << " does not exist." << endl;
		return false;
	}

	while (file >> word)
	{
		//Test
		cout << word << endl;
		wordsFromFile.push_back(word);
	}

	
	/*for (auto one : wordsFromFile)
	{
		cout << one << endl;
	}*/

	return true;
}

int main()
{
   //string test = "bbbbaaaaaccchhhhh";
   //string result = printEncode(test);

   //float compressionRatio = static_cast <float> ( test.size()) / static_cast <float> (result.size());

   //cout << "Input: " << test << endl;
   //cout << "Output: " << result << endl;
   //cout << "Compression Ratio: " << compressionRatio << endl;

	vector <string> file1;

	if (!readFile("Data\\compress_decompress_1.txt", file1))
	{
		//Error
	}

   for (int i = 0; i < file1.size(); i++)
   {
	  	string output = printEncode(file1[i]);
		
		cout << "Input: " << file1[i] << endl;
		cout << "Output: " << output << endl;
   }
}

