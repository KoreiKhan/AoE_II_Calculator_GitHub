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

	// Constant variables: The number of technologies/events
	const int technologiesNumber = 17;
	const int eventsNumber = 46;

	// Behaviour: Ensure that the correct player numbers were entered
	if( (player1 != 1) || (player2 !=2) ){
		std::cout << "Error: player1 != 1 or player2 != 2" << "\n";
		exit(EXIT_FAILURE);
	}
	else if(technologiesNumber!=17){
		std::cout << "Error: technologiesNumber != 17" << "\n";
		exit(EXIT_FAILURE);
	}
	else if(eventsNumber!=46){
		std::cout << "Error: eventsNumber != 46" << "\n";
		exit(EXIT_FAILURE);
	}

	// Object: Declare the file importing object
	fileImporter importFile;

	// Behaviour: Load "entities.csv" and store information about the input entities
	Entity p1BattleParticipant = importFile.entitiesFile("import/entities.csv", player1); // Declare and get the entity that is participating in the battle for player 1
	Entity p2BattleParticipant = importFile.entitiesFile("import/entities.csv", player2); // Declare and get the entity that is participating in the battle for player 2

	// Behaviour: Load "technologies_[p1/p2].csv" and store information about the active technologies for player 1 and 2
	int* p1_technologies_array = importFile.aTechnologyOrEventFile("import/technologies_p1.csv", technologiesNumber);
	int* p2_technologies_array = importFile.aTechnologyOrEventFile("import/technologies_p2.csv", technologiesNumber);

	// Behaviour: Load "events_[p1/p2].csv" and store information about the active events for player 1 and 2
	int* p1_events_array = importFile.aTechnologyOrEventFile("import/events_p1.csv", eventsNumber);
	int* p2_events_array = importFile.aTechnologyOrEventFile("import/events_p2.csv", eventsNumber);

	// Declare the modifiers calculator class
	modifiersCalculator theModifiersCalculator;

	// Behaviour: Apply a range of modifiers to both player's battle participants
	p1BattleParticipant = theModifiersCalculator.applyAllModifiersP1(player1, p1BattleParticipant, p1_technologies_array, p1_events_array, p2BattleParticipant);
	p2BattleParticipant = theModifiersCalculator.applyAllModifiersP2(player2, p2BattleParticipant, p2_technologies_array, p2_events_array, p1BattleParticipant);

	// Behaviour: Return information about the input entities 
	std::cout << "You entered..." << "\n";
	p1BattleParticipant.outputEntity();
	p2BattleParticipant.outputEntity();

	// Declare the rounds and combat calculator class
	round1 outcomeRound1;
	combatCalculator *theCombatCalculator = &outcomeRound1;

	// Behaviour: Set the protected values
	theCombatCalculator->setCombatParticipants(p1BattleParticipant, p2BattleParticipant);
	
	// Behaviour: Calculate the damage dealt for the input round of combat
	outcomeRound1.roundOutcome();

	// Behaviour: A required return statement for the system in C++
	return 0;
}