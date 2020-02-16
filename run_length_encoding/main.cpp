#include <iostream>
#include "RunLengthEncoder.h"

//Created by Craig Palmer, Teesside University Student at craigplmr434@gmail.com for Playground Games Student Placement 2020 Test. Final Version created 16/11/2019.

int main()
{

	RunLengthEncoder rle;
	bool isProgramRunning{ true };
	bool isSectionRunning{ true };
	bool isNumberContained{ true };
	char input;
	string inputString, outputString;


	/*

	READ FIRST

	Can call functions by using rle but thought might make a small menu system to navigate through.

	If want to use directly then just use the commented code and comment out the while loop.



	string file1 = "compress_decompress_1.txt";


	rle.encodeFile(file1);

	rle.decodeFile(file1, true);*/

	/*string original = "kk3p";
	string encoded = rle.encodeWord(original);
	string decoded = rle.decodeWord(encoded);
	string alt = rle.decodeWordAlt(encoded);

	cout << "Test: " << original << endl;
	cout << "Encoded: " << encoded << endl;
	cout << "Decoded: " << decoded << endl;
	cout << "Alt Decoded: " << alt << endl;

	*/

	while (isProgramRunning)
	{
		cout << "Welcome to my run length encoder.\nPlease see the following options" << endl;
		cout << "1 - Encode Single String" << endl;
		cout << "2 - Decode Single String" << endl;
		cout << "3 - Decode Single String Alt \n\nOriginal string contains numbers before being encoded. \n\nNot to be used for sequences of characters greater than 10.\n  " << endl;
		cout << "4 - Encode File" << endl;
		cout << "5 - Decode File" << endl;
		cout << "Q - Quit" << endl;
		cout << "\nPlease enter selection and press enter" << endl;

		cin >> input;

		switch (input)
		{
		case '1':
		{
			while (isSectionRunning)
			{
				cout << "Option 1 Selected" << endl;
				cout << "Please enter string to be encoded" << endl;
				cin >> inputString;
				outputString = rle.encodeWord(inputString);
				cout << "Result: " << outputString << endl;
				cout << "Compression Ratio: " << static_cast <float> (inputString.size()) / static_cast <float> (outputString.size()) << endl;
				cout << "Would you like to encode another word? Y/N" << endl;
				cin >> input;
				if (input == 'n' || input == 'N')
				{
					isSectionRunning = false;
				}
			}

			isSectionRunning = true;
			cout << string(5, '\n');
			break;
		}
		case '2':
		{
			while (isSectionRunning)
			{
				cout << "Option 2 Selected" << endl;
				cout << "Please enter string to be decode" << endl;
				cin >> inputString;
				outputString = rle.decodeWord(inputString);
				cout << "Result: " << outputString << endl;
				cout << "Would you like to decode another word? Y/N" << endl;
				cin >> input;
				if (input == 'n' || input == 'N')
				{
					isSectionRunning = false;
				}
			}
			isSectionRunning = true;
			cout << string(5, '\n');
			break;
		}
		case '3':
		{
			while (isSectionRunning)
			{
				cout << "Option 3 Selected" << endl;
				cout << "Please enter string to be decode" << endl;
				cin >> inputString;
				outputString = rle.decodeWordAlt(inputString);
				cout << "Result: " << outputString << endl;
				cout << "Would you like to decode another word? Y/N" << endl;
				cin >> input;
				if (input == 'n' || input == 'N')
				{
					isSectionRunning = false;
				}
			}

			isSectionRunning = true;
			cout << string(5, '\n');
			break;
		}

		case '4':
		{
			while (isSectionRunning)
			{
				cout << "Option 4 Selected" << endl;
				cout << "Please enter directory of file to encode. E.g compress_decompress_1.txt" << endl;
				cin >> inputString;
				if (!rle.encodeFile(inputString))
				{
					cerr << "File not found" << endl;
				}

				cout << "Would you like to encode another file? Y/N" << endl;
				cin >> input;
				if (input == 'n' || input == 'N')
				{
					isSectionRunning = false;
				}
			}

			isSectionRunning = true;
			cout << string(5, '\n');
			break;
		}
		case '5':
		{
			while (isSectionRunning)
			{
				cout << "Option 5 Selected" << endl;
				cout << "Please enter directory of file to decode. E.g compress_decompress_1.txt" << endl;
				cin >> inputString;
				cout << "Do any of the strings to be encoded have a number already? Y/N" << endl;
				cin >> input;
				if (input == 'n' || input == 'N')
				{
					isNumberContained = false;
				}
				cout << "Would you like to decode another file? Y/N" << endl;
				cin >> input;
				if (input == 'n' || input == 'N')
				{
					isSectionRunning = false;
				}
				if (!rle.decodeFile(inputString, isNumberContained))
				{
					cerr << "File not found" << endl;
				}
			}

			isSectionRunning = true;
			std::cout << string(5, '\n');
			break;
		}
		case 'q':
		case 'Q':
			cout << "\nGoodbye" << endl;
			isProgramRunning = false;
			break;

		default:
			break;
		}


	}



}

