#include <iostream>

int powerof(int, int);

using namespace std;

int main(int argc, char const *argv[])
{
	for(int i = 0; i < 32; i++)
	{
		cout << powerof(2, i) << endl;
	}	
	return 0;
}

int powerof(int baseNumber, int power)
{
	if(power == 1) return baseNumber;
	if(power == 0) return 1;
	int tmp = powerof(baseNumber, power / 2);
	return power % 2  == 0 ? tmp * tmp : tmp * tmp * baseNumber; 
}

