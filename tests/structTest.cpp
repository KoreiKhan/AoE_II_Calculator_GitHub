#include <iostream>
#include <stdio.h>
#include <string>
using std::cout;
using std::string;

// Declare the struct
struct testingStructs{
	string text;
	int numberArray[21];
};

testingStructs canYouReturnStructsFromFunctions(){
	testingStructs youCanReturnStructsFromFunctions{"hello", 1, 2, 3, 4, 5, 6,
	7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
	17, 18, 19, 20, 21};

	return youCanReturnStructsFromFunctions;
}

int main(){
	// Declare the first struct (see if you can populate the array with a for loop)
	testingStructs test1;
	cout << "test1: ";
	for(int i = 0; i != 22; i ++){
		test1.numberArray[i] = i;
		cout << test1.numberArray[i] << " ";
	}
	cout << "\n";

	// Declare the second struct (see if you can return structs from functions)
	testingStructs test2 = canYouReturnStructsFromFunctions();
	cout << "test 2: " << test2.numberArray[0] << " ";
	cout << test2.text << "\n";

	return 0;
}

