#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct CandyBar
{
	char name[20];
	double mass;
	int calorie;	
};

int main(int argc, char const *argv[])
{
	const int candyBarCount = 3;
	/* code */

	CandyBar * theList = new CandyBar[candyBarCount];
	for(int i = 0; i < candyBarCount; i++)
	{
		cout << "Please input the " << i + 1 << "th candy bars' information\n";
		cout << "input the name: ";
		// if the struct is represented via struc object itself
		// use the dot to access its member
		cin >> (*(theList + i)).name;
		cout << "input the mass: ";
		cin >> theList[i].mass;

		// if the struct object is represented via its pointer
		// use -> to request its member
		cout << "input the calories: ";
		cin >> (theList + i) -> calorie;
	}

	for(int i = 0; i < candyBarCount; i++)
	{
		cout << "The candybar " << theList[i].name << 
		" has mass: " << theList[i].mass << ", and calories: " << theList[i].calorie << endl; 
	}

	delete [] theList;
	return 0;
}