#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{
	using namespace std;
	char word[30];
	char done[] = "done";
	cin >> word;
	int counter = 0;
	while(strcmp(word, done) != 0) {
		counter++;
		cin >> word;
	}

	cout << "The word count is: " << counter << endl;
	return 0;
}