/*
	Voucher Code Generator

	A program to generate unique random voucher codes.
	Two vectors hold numbers and letters. They are separated so that a number
	is just as likely as a letter. If they were all stored in one vector, an letter
	would be 2.6 times as likely as a number.
	
	Each generated voucher code is checked against all the other ones previously added to the voucher vector.
	If they are the same (which is highly unlikely) new voucher codes are generated until a unique one is found.
	This ensures voucher code integrity within each run.
	
	50 Voucher Codes are generated with each run. Codes are unique to each run, but are not necessarily
	unique across multiple runs.
*/

// Library inclusions
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function declarations
int randNum(int upper, int lower);
bool StringComp(string stringOne, string stringTwo);
char genChar();
string genString();

// Global Variables
vector<char> letters = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
vector<char> numbers = {'1','2','3','4','5','6','7','8','9','0'};
vector<string> vCodes;


// Main Program Here
int main()
{
	// Variable Declarations

	// Alphabet Vector
	string vCodeOut;
	string vCode;
	bool unique;
	vector<string>::iterator found;

	// Voucher codes output	
	cout << "Voucher codes:" << endl;
	
	// Generating the random codes and making sure they are unique.
	for (int i=0; i<50; i++)
	{
		vCodeOut = genString(); // Get the randomly generated voucher code
		
		while (found != vCodes.end()) // While the generated code is not unique compared with the rest of the vector...
		{
			// ... generate a new one and check if it is unique.
			vCodeOut = genString();
			found = find (vCodes.begin(), vCodes.end(), vCodeOut);
		}
		
		vCodes.push_back(vCodeOut); // Add voucher code to the vector of codes
	}
	
	// Outputting the Voucher Codes
	for (int i=0; i<50; i++)
	{
		cout << vCodes.at(i) << endl;
	}

	return 0;
}


/*
	Function: randNum()
	Parameter 1: upper integer limit
	Parameter 2: lower integer limit
	Generates a random number within the specified range.
	
	Uses time() to make a seed that is "more" random.
*/
int randNum(int upper, int lower)
{
	double seed = rand() + static_cast<int>(time(0));
	srand(seed);
	return rand()% (upper-lower +1);
}


/*
	Function: genChar()
	Generate a random letter or number.
	Set to make a letter just as likely as a number.
 
*/
char genChar()
{
	// Randomly choose between the numbers or letters vector.  50-50 chance.
	if (randNum(1,0) == 1)
	{
		return letters.at(randNum(0,25));
	}
	
	else
	{
		return numbers.at(randNum(0,9));
	}
}


/*
	Function: genString()
	To generate random voucher code.
	Calls upon genChar() to generate random letters and numbers.
*/
string genString()
{
	string vCodeOutString = "";
	vCodeOutString = vCodeOutString + genChar() + genChar() + genChar() + genChar() + genChar() + genChar();
	return vCodeOutString;
}