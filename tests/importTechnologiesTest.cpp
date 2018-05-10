#include <iostream> // Uses: cout
#include <fstream> // Uses: importing files (ifstream, is_open(), good, close())
#include <cstdlib> // Uses: exit(EXIT_FAILURE)
#include <string> // Uses: string
#include <sstream> // Uses: stringstream 
#include <algorithm> // Uses: Uppercase text (transform, toupper, .begin(), .end())

/** Code to load the technology file, validate the input, and return the input **/

int* returnActiveTechnologies(std::string technologiesFileName){
	// Declare a file object
	std::ifstream fileObject;

	// Open "technologies.csv" for player 1 or player 2
	if(technologiesFileName == "technologies_p1.csv"){
		fileObject.open("technologies_p1.csv");
	}
	else if(technologiesFileName == "technologies_p2.csv"){
		fileObject.open("technologies_p2.csv");
	}
	else{
		std::cout << "Error: Technology file not recognized" << "\n";
		exit(EXIT_FAILURE);
	}
	

	// Check if "technologies.csv" exists or is successfully opened
	if(!fileObject.is_open()){
		// The file did not open
		std::cout << "Error: Opening the file" << "\n";
		exit(EXIT_FAILURE);
	}
	else{
		// Declare the number of words in the technologies array
		int columns = 2; // Active column and the technology name column
		int rows = 17; // There are 17 recognized technologies for both files
		int arrayWords = columns * rows;

		// Declare and initialize what is necessary to sort through the words array
		std::string words[arrayWords];
		for(int i = 0; i < arrayWords; i ++){
			words[i] = "";
		}
		int count = 0;
		std::string word = "";


		// While we aren't at the end of the file keep running. Similar to .good() and .eof() 
		while(fileObject>>word){
			// Data validation. Ensure that the user doesn't exceed the array bounds
			if(count >= arrayWords+1){
				std::cout << "Error: You have entered too much input into technologies_p1.csv" << "\n";
				std::cout << "You will have to replace the existing 'technologies_p1.csv' file with the one in the backups folder" << "\n";
				exit(EXIT_FAILURE);
			}
			else{
				words[count] = word;
				count ++;
			}
		}

		// Data validation. Ensure that there are at least arrayWords inside of the array
		if(count <=arrayWords-1){
			std::cout << "Error: You have entered too little input input into technologies.csv" << "\n";
			std::cout << "You will have to replace the existing 'technologies.csv' file with the one in the backups folder" << "\n";
			exit(EXIT_FAILURE);
		}

		// Store the even words (MEMORY MANAGEMENT)
		/** You need the new keyword to store the array in the heap and not the stack **/
		/** If you store in the heap then it will not get deleted straight away **/
		/** Struct passes everything and avoids this issue **/

		int* everySecondElement = new int[arrayWords/2]; 
		int incrementOutsideArray = 0;
		int incrementInnerArray = 0;
		int value = 0;

		// Return the even numbers of the array
		for(int i = 0; i < arrayWords; i ++){
			// Check if incrementOutsideArray is even
			// incrementOutsideArray represents every second even element inside of the array of words
			if(incrementOutsideArray % 2 == 0){
				// Validate that the words input is either 0 or 1 before trying to convert the string into an integer and passing this to the integer array
				if (words[i] !="0" && words[i] !="1"){
					std::cout << "Error: For each technology, enter 0 (inactive) or 1 (active) only" << " not " << words[i] << "\n";
					std::cout << "Note that you must leave the technology names next to the numbers" << "\n";
					std::cout << "You may have to replace the existing 'technologies.csv' file with the one in the backups folder" << "\n";
					exit(EXIT_FAILURE);
				}
				everySecondElement[incrementInnerArray] = atoi(words[i].c_str());
				incrementInnerArray++;
			}
			incrementOutsideArray++;
		}

		// Return everySecondElement, a string of technologies
		return everySecondElement;
	}

	// Close the file
	fileObject.close();
}

int main(){
	int* p1_technologies_array = returnActiveTechnologies("technologies_p1.csv");// Get what technologies player 1 has researched
	int* p2_technologies_array = returnActiveTechnologies("technologies_p2.csv");// Get what technologies player 2 has researched

	// Output player 1's technologies (test)
	std::cout << "player 1" << "\n";
	for(int i = 0; i < 17; i ++){
		std::cout << p1_technologies_array[i] << "\n";
	}

	// Output player 2's technologies
	std::cout << "player 2" << "\n";
	for(int i = 0; i < 17; i ++){
		std::cout << p2_technologies_array[i] << "\n";
	}
}