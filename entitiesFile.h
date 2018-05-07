/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string
#include <fstream> // Using: ifstream, is_open(), good, close()
#include <cstdlib> // Using: exit(EXIT_FAILURE)
#include <sstream> // Using: stringstream 
#include <algorithm> // Using: transform, toupper, .begin(), .end()

/** Code to load the entities file, validate the input, and return the input **/
// We will pass each word to the struct Entity class later
// We can perform further data validation later:
	// - Ensuring that word[0] and word[2] are recognized names
	// - Ensuring that the quantity is only 1 for the building class

void entitiesFile(){
	// Declare a file object
	std::ifstream fileObject;

	// Open "entities.csv"
	fileObject.open("entities.csv");

	// Check if "entities.csv" exists or is successfully opened
	if(!fileObject.is_open()){
		// The file did not open
		std::cout << "Error: Opening the file" << "\n";
		exit(EXIT_FAILURE);
	}
	else{
		// Declare an array that can hold up to four words and a variable to increment this array
		std::string words[4] = {"","","",""};
		int count = 0;

		// Declare a string that can hold one word
		std::string word;

		// While we aren't at the end of the file keep running. Similar to .good() and .eof() 
		while(fileObject>>word){
			// Data validation. Ensure that the user doesn't exceed the array bounds of words[4]
			if(count == 4){
				std::cout << "Error: Too much input. Only enter the values for up to two players" << "\n";
				std::cout << "The input is supposed to be: [P1_Entity_Name] [P1_Entity_Quantity] [P2_Entity_Name] [P2_Entity_Quantity]" << "\n";
				exit(EXIT_FAILURE);
			}
			else{
				// Pass the word into the words array
				words[count] = word;
				count ++;
			}
		}

		// Data validation. Ensure that there are at least four words inside of the words array
		if(count <=3){
			std::cout << "Error: Too little input. You must enter the values for up to two players" << "\n";
			std::cout << "The input is supposed to be: [P1_Entity_Name] [P1_Entity_Quantity] [P2_Entity_Name] [P2_Entity_Quantity]" << "\n";
			exit(EXIT_FAILURE);
		}

		// Ensure that the integer elements are of the correct data type (i.e. they are integers)
		std::stringstream word1;
		word1 << words[1];
		std::stringstream word2;
		word2 << words[3];

		int checkInteger[2] = {0, 0};
		word1 >> checkInteger[0];

		if(word1.good()){
			std::cout << "Error: No valid first quantity" << "\n";
			exit(EXIT_FAILURE);
		}
		else if(checkInteger[0] == 0){
			if(words[1]!="0"){
				std::cout << "Error: The output was 0 but the input was not 0 for the first quantity" << "\n";
				exit(EXIT_FAILURE);
			}
			else{
				std::cout << "Error: This program in particular needs a quantity > 1 for the first quantity" << "\n";
				exit(EXIT_FAILURE);
			}
		}
		else{// std::cout << checkInteger[0] << "\n"; // Optionally display the output
		}

		word2 >> checkInteger[1];

		if(word2.good()){
			std::cout << "Error: No valid second quantity" << "\n";
			exit(EXIT_FAILURE);
		}
		else if(checkInteger[1] == 0){
			if(words[1]!="0"){
				std::cout << "Error: The output was 0 but the input was not 0 for the second quantity" << "\n";
				exit(EXIT_FAILURE);
			}
			else{
				std::cout << "Error: This program in particular needs a quantity > 1 for the second quantity" << "\n";
				exit(EXIT_FAILURE);
			}
		}
		else{// std::cout << checkInteger[1] << "\n"; // // Optionally display the output
		}

		// Data validation. Convert words[0] and words[2] into all caps
		std::transform(words[0].begin(), words[0].end(), words[0].begin(), ::toupper);
		std::transform(words[2].begin(), words[2].end(), words[2].begin(), ::toupper);

		// Display the result to the compiler
		for(int i = 0; i < 4; i++){
			std::cout << words[i] << "\n"; // Data validation. There is no whitespace (by default)
		}
	}

	// Close the file
	fileObject.close();
}
