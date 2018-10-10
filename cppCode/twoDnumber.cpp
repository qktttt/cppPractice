#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int row = 2;
	int column = 2;
	int ** twoDnumber = new int*[row];
	
	for(int i = 0; i < row; i++)
	{
		*(twoDnumber + i) = new int[column];
	}

	for(int i = 0; i < row * column; i++)
	{
		*(*(twoDnumber + i / row) + i % column) = i;
	}

	for(int i = 0; i < 4; i++)
	{
		cout << twoDnumber[i / row][i % column] << endl;
	}

	for(int i = 0; i < row; i++)
	{
		// delete each subarray
		delete [] *(twoDnumber + i);
	}

	delete [] twoDnumber;

	return 0;
}