/** Age of Empires II: The Board Game **/ /** Combat Results Calculator **/ /** Coded by: Kory **/

/** The libaries **/
#include <iostream> // Using: cin, cout
#include <string> // Using: string
#include <cstdlib> // Using: exit(EXIT_FAILURE)
#include "entity.h" // Using: entity class
#include "fileImporter.h" // Using: fileImporter class
#include "calculator.h" // Using: calculator class

/** The main function **/
int main(){
	// Constant variables: The player numbers
	const int player1 = 1;
	const int player2 = 2;

	// Behaviour: Ensure that the correct player numbers were entered
	if( (player1 != 1) || (player2 !=2) ){
		std::cout << "Error: player1 != 1 or player2 != 2";
		exit(EXIT_FAILURE);
	}

	// Object: Declare the file importing object
	fileImporter importFile;

	// Behaviour: Load "entities.csv" and store information about the input entities
	Entity p1BattleParticipant = importFile.entitiesFile(player1); // Declare and get the entity that is participating in the battle for player 1
	Entity p2BattleParticipant = importFile.entitiesFile(player2); // Declare and get the entity that is participating in the battle for player 2

	// Behaviour: Return information about the input entities 
	p1BattleParticipant.outputEntity();
	p2BattleParticipant.outputEntity();

	// Behaviour: Load "technologies_[p1/p2].csv" and store information about the active technologies for player 1 and 2
	int* p1_technologies_array = importFile.technologyFile("technologies_p1.csv");
	int* p2_technologies_array = importFile.technologyFile("technologies_p2.csv");

	// Declare the calculator class
	calculator theCalculator;

	// Behaviour: Apply the effects of the technologies and quantity for player 1 and 2
	p1BattleParticipant = theCalculator.applyModifiersSet1P1(p1BattleParticipant, p1_technologies_array);
	p2BattleParticipant = theCalculator.applyModifiersSet1P2(p2BattleParticipant, p2_technologies_array);

	// Behaviour: Calculate the damage dealt for the input round of combat

	// Behaviour: A required return statement for the system in C++
	return 0;
}