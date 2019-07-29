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

