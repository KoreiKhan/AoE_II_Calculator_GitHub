/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string
#include <fstream> // Using: ifstream, is_open(), good, close()
#include <cstdlib> // Using: exit(EXIT_FAILURE)
#include <sstream> // Using: stringstream 
#include <algorithm> // Using: transform, toupper, .begin(), .end()

/** A necessary function to see if a string is an integer **/
int checkIsInteger(std::string inputWord){
	// Delare data structures
	int anInteger = 0;
	std::stringstream wordConversion;
	wordConversion << inputWord;
	wordConversion >> anInteger;

	// Check to see if the string to integer conversion worked
	if(wordConversion.good()){
		std::cout << "Error: No valid first quantity" << "\n";
		exit(EXIT_FAILURE);
	}
	else if(anInteger == 0){
		if(inputWord!="0"){
			std::cout << "Error: The output was 0 but the input was not 0 for the first quantity" << "\n";
			exit(EXIT_FAILURE);
		}
		else{
			std::cout << "Error: This program in particular needs a quantity > 1 for the first quantity" << "\n";
			exit(EXIT_FAILURE);
		}
	}
	else{
		// std::cout << checkInteger[0] << "\n"; // Optionally display the output
	}

	return anInteger;
}

/** Code to load the entities file, validate the input, and return the input **/
// We will pass each word to the struct Entity class later
// We can perform further data validation inside the conductASearch function at "entity.h":
	// - Ensuring that word[0] and word[2] are recognized names
	// - Ensuring that the quantity is only 1 for the building class

void entitiesFile(){
	// Declare a file object
	std::ifstream fileObject;

	// Open "entities.csv"
	fileObject.open("entities.csv");

	// Error: Check if "entities.csv" exists or is successfully opened
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
		int p1Quantity = checkIsInteger(words[1]);
		int p2Quantity = checkIsInteger(words[3]);

		// Data validation. Convert words[0] and words[2] into all caps
		std::transform(words[0].begin(), words[0].end(), words[0].begin(), ::toupper);
		std::transform(words[2].begin(), words[2].end(), words[2].begin(), ::toupper);

		// Display the result to the compiler (optional)
		for(int i = 0; i < 4; i++){
			std::cout << words[i] << "\n"; // Data validation. There is no whitespace (by default)
		}
		

		// Pass the results back to main (ERRORS)
		// p1BattleParticipant.unitName = words[0];
		// p1BattleParticipant.unitQuantity = p1Quantity;
		// p2BattleParticipant.unitName = words[2];
		// p2BattleParticipant.unitQuantity = p2Quantity;
	}

	// Close the file
	fileObject.close();
}

