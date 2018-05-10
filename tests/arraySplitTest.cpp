#include <iostream>
#include <string>

int main(){
	// Declare arrays
	int arrayToSplit[10];
	for(int i = 0; i != 10; i ++){
		arrayToSplit[i] = i;
	}
	int splitArray1[5] = {0};
	int array1Count = 0;
	int splitArray2[5] = {0};
	int array2Count = 0;

	for(int i = 0; i < 10; i ++){
		if(arrayToSplit[i] %2 == 0){
			// Even
			splitArray1[array1Count] = arrayToSplit[i];
			array1Count++;
		}
		else{
			// Odd
			splitArray2[array2Count] = arrayToSplit[i];
			array2Count++;
		}
	}

	// Display split array 1/2
	for(int i = 0; i < 5; i ++){
		std::cout << splitArray2[i] << "\n";
	}

}