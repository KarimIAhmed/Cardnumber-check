#include <iostream>;
#include <string>;

using namespace std;

bool isvalid(string);
int sumofdoubleeven(string);
int getdigit(int);
int sumofoddplace(string);


int main()
{
	string cardnumber;
	cout << " -----Using the Luhn algorithm, this program validates debit/credit cardnumbers----- " << endl << endl;
	cout << " Enter your card number: " << endl;
	cin >> cardnumber;
	
	
	if (isvalid(cardnumber))
	{
		cout << "This is a valid card number according to the algorithm" << endl;
	}
	else
	{ cout << "This is not a valid card number according to the algorithm" << endl; }
	

}


int sumofoddplace(string cardnumber)
{
	// Using a for loop, this functon adds all the numbers in the odd places from RIGHT to LEFT
	// it then stores them in the totalodd variable
	int totalodd =0;
	int size = cardnumber.size();
	for (int i = size - 1; i >= 0; i-=2)
	{
		totalodd += cardnumber[i] - '0';

		
	}
	return totalodd;
}
int getdigit(int numbers)
{
	// This was a fun part to figure out
	// Function sumofdoubleeven passes the value to here, and if its 
	// a single digit it is returned. But if it isn't, then I just take the
	// resulting / 10 and % 10 and add them together
	if (numbers <= 9 )
	{
		return numbers;
	}
	else
	{
		return (numbers / 10) + (numbers % 10);
	}

}

int sumofdoubleeven(string cardnumber)
{
	// This was an interesting function to work on
	// It takes every other digit from the entered card number from RIGHT to LEFT 
	// then doubles it. If the doubled number is double digits (6*2 giving 12) 
	// then those 2 digits need to be added to one number (1+2 = 3). I made the
	// get digit function to test and convert the resulting number if necessary 
	int totaleven = 0;
	int size = cardnumber.size();
	for (int i = size - 2 ; i >=0;i -=2)
	{
		totaleven += getdigit((cardnumber[i] - '0')*2);
	}
	return totaleven;

}

bool isvalid(string cardnumber)
{
	//For the card number to be right, the result number from 
	// sumofdoubleeven and sumofoddplace needs to be divisible by 10
	// it also needs to start with "4","5","6" or "37"
	if ((sumofdoubleeven(cardnumber) + sumofoddplace(cardnumber)) % 10 ==0)
	{
		if (cardnumber[0] == '4' || cardnumber[0] == '5' || cardnumber[0] == '6')
		{
			return true;
		}
		else if (cardnumber[0] == '3' && cardnumber[1] == '7')
		{
			return true;
		} return true;
	}
	else
	{
		return false;
	}
}

