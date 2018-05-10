/** Age of Empires II: The Board Game **/ 
/** Combat Results Calculator **/
/** Created by: Kory **/
/** Written using English (United States) spelling **/

/** Yet to demonstrate **/
// Polymorphism (e.g. a void calculate() function that only runs depending on the round of combat)

/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string
#include "entity.h" // Using: Entity class
#include "fileImporter.h" // Using: entitiesFile() function
#include <cstdlib> // Using: exit(EXIT_FAILURE)

/** Global variables for all functions **/

/** The main function **/
int main(){
	// Declare the player numbers
	const int player1 = 1;
	const int player2 = 2;

	// Load "entities.csv" and return the values (the name of the entity and quantity of the entity) for player 1 and 2
	fileImporter entitiesCSV;
	Entity p1BattleParticipant = entitiesCSV.entitiesFile(player1); // Declare and get the entity that is participating in the battle for player 1
	Entity p2BattleParticipant = entitiesCSV.entitiesFile(player2); // Declare and get the entity that is participating in the battle for player 2

	// Should return everything about p1BattleParticipant and p2BattleParticipant except "modifiers_set_1" and "modifiers_set_2" (yet to implement)
	p1BattleParticipant.outputEntity();
	p2BattleParticipant.outputEntity();


	// Update values with technology effects
	// p1BattleParticipant = technologiesCSV.technologiesFile(p1BattleParticipant)

	// Determine damage dealt
	// battleOutcome(p1BattleParticipant, p2BattleParticipant)

}