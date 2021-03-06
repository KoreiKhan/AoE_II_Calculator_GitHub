/** Age of Empires II: The Board Game **/ /** Combat Results Calculator **/ /** Coded by: Korei Khan **/

/** The libaries **/
#include <iostream> // Using: cin, cout
#include <string> // Using: string
#include <cstdlib> // Using: exit(EXIT_FAILURE)
#include <stdlib.h> // Using: atoi
#include "entity.h" // Using: entity class
#include "fileImporter.h" // Using: fileImporter class
#include "calculator.h" // Using: calculator class

/** The main function **/
int main(){
	/** Simple declarations **/
	// Constant int: The player numbers
	const int player1 = 1, player2 = 2;

	// Constant Int: The number of entity words
	const int entitiesWords = 8;;

	// Constant int: The number of technology, event, and player detail rows
	const int technologiesRows = 18, eventsRows = 40, playerDetailsRows = 4;

	/** Part 1: Getting information about the input entities **/
	// Object: Declare the file importing object
	fileImporter importFile;

	// Behaviour: Load "entities.csv" and store the information about the input entities
	Entity p1BattleParticipant = importFile.entitiesFile("import/entities.csv", entitiesWords, player1, 0); // Declare and get the entity that is participating in the battle for player 1
	Entity p1MonkParticipant = importFile.entitiesFile("import/entities.csv", entitiesWords, player1, 1); // Declare the monk entity for player 1 if there are any
	Entity p2BattleParticipant = importFile.entitiesFile("import/entities.csv", entitiesWords, player2, 0); // Declare and get the entity that is participating in the battle for player 2
	Entity p2MonkParticipant = importFile.entitiesFile("import/entities.csv", entitiesWords, player2, 1); // Declare the monk entity for player if there are any

	// Behaviour: Load "technologies_[p1/p2].csv" and store the information about the active technologies for player 1 and 2
	int* p1_technologies_array = importFile.aSplitColumnFile("import/technologies_p1.csv", technologiesRows);
	int* p2_technologies_array = importFile.aSplitColumnFile("import/technologies_p2.csv", technologiesRows);

	// Behaviour: Load "events_[p1/p2].csv" and store the information about the active events for player 1 and 2
	int* p1_events_array = importFile.aSplitColumnFile("import/events_p1.csv", eventsRows);
	int* p2_events_array = importFile.aSplitColumnFile("import/events_p2.csv", eventsRows);

	// Behaviour: Load "players.csv"and store information about the player details
	int* player_details_array = importFile.aSplitColumnFile("import/players.csv", playerDetailsRows);

	// Behaviour: Store the details of the player_details_array
	int attackingPlayerNumber = player_details_array[0];
	int player1Age = player_details_array[1];
	int player2Age = player_details_array[2];
	int preferToRollDice = player_details_array[3];

	// Validate the input of the player_details_array
	if( (attackingPlayerNumber !=1) && (attackingPlayerNumber !=2) ){
		std::cout << "Error: The attacking player number should be 1 or 2" << "\n";
		exit(EXIT_FAILURE);
	}
	else if( (player1Age <=0) || (player1Age >= 5) ){
		std::cout << "Error: player 1's age should be between 1 and 4" << "\n";
		exit(EXIT_FAILURE);
	}
	else if( (player2Age <=0) || (player2Age >= 5) ){
		std::cout << "Error: player 2's age should be between 1 and 4" << "\n";
		exit(EXIT_FAILURE);
	}
	if( (preferToRollDice !=0) && (preferToRollDice !=1) ){
		std::cout << "Error: The setting to roll/not roll dice should be 0 or 1" << "\n";
		exit(EXIT_FAILURE);
	}

	// Object: Declare the modifiers calculator object
	modifiersCalculator theModifiersCalculator;

	// Behaviour: Apply a range of modifiers to both player's battle participants
	p1BattleParticipant = theModifiersCalculator.applyAllModifiersP1(player1, p1BattleParticipant, p1MonkParticipant, 0, p1_technologies_array, p1_events_array, p2BattleParticipant, attackingPlayerNumber, player1Age);
	p2BattleParticipant = theModifiersCalculator.applyAllModifiersP2(player2, p2BattleParticipant, p2MonkParticipant, 0, p2_technologies_array, p2_events_array, p1BattleParticipant, attackingPlayerNumber, player2Age);

	p1MonkParticipant = theModifiersCalculator.applyAllModifiersP1(player1, p1BattleParticipant, p1MonkParticipant, 1, p1_technologies_array, p1_events_array, p2BattleParticipant, attackingPlayerNumber, player1Age);
	p2MonkParticipant = theModifiersCalculator.applyAllModifiersP2(player2, p2BattleParticipant, p2MonkParticipant, 1, p2_technologies_array, p2_events_array, p1BattleParticipant, attackingPlayerNumber, player2Age);

	// Behaviour: Return information about the input entities 
	std::cout << "You entered..." << "\n";
	p1BattleParticipant.outputEntity(player1);
	if(p1MonkParticipant.entityQuantity > 0){
		std::cout << "(Assisting) ";
		p1MonkParticipant.outputEntity(player1);
	}
	p2BattleParticipant.outputEntity(player2);
	if(p2MonkParticipant.entityQuantity > 0){
		std::cout << "(Assisting) ";
		p2MonkParticipant.outputEntity(player2);
	}

	/** Part 2: Returning the outcome of each round of combat for the input entities **/
	// Behaviour: Declare the round subclasses
	monkRounds monkRounds;
	archerRounds rangedRounds;
	standardRounds standardRounds;

	// Integer: Declare the rounds of monk combat
	int monkCombatRounds = 1;

	// Object: Declare the combat calculator superclass and set the superclass to the first round
	combatCalculator *theCombatCalculator = &monkRounds;

	// Behaviour: Set the battle participants
	theCombatCalculator->setCombatParticipants(p1BattleParticipant, p2BattleParticipant, p1MonkParticipant, p2MonkParticipant);

	// Behaviour: Calculate the damage dealt for X rounds of monk combat
	monkRounds.roundOutcome(monkCombatRounds, preferToRollDice, attackingPlayerNumber, p1_events_array, p2_events_array); 

	// Behaviour: Get the results after X rounds of monk combat
	p1BattleParticipant = theCombatCalculator->returnModifiedBattleParticipants(player1);
	p2BattleParticipant = theCombatCalculator->returnModifiedBattleParticipants(player2);

	// Integer: Declare the rounds of ranged combat
	int archerCombatRounds = 1;

	// Behaviour: Set the combat calculator to the second round
	theCombatCalculator = &rangedRounds;

	// Behaviour: Set the battle participants
	theCombatCalculator->setCombatParticipants(p1BattleParticipant, p2BattleParticipant, p1MonkParticipant, p2MonkParticipant);
	
	// Behaviour: Calculate the damage dealt for X rounds of archer combat
	rangedRounds.roundOutcome(archerCombatRounds, preferToRollDice, attackingPlayerNumber, p1_events_array, p2_events_array);

	// Behaviour: Get the results after X rounds of ranged combat
	p1BattleParticipant = theCombatCalculator->returnModifiedBattleParticipants(player1);
	p2BattleParticipant = theCombatCalculator->returnModifiedBattleParticipants(player2);

	// Integer: Declare the rounds of normal combat
	int normalCombatRounds = 2;

	// Behaviour: Apply the effects of event 41
	if( (p1_events_array[38] == 1) || (p2_events_array[38] == 1) ){
		// [38] You Will Die! (Saracen) - This battle goes for four rounds of normal combat, instead of 2 rounds. No retreat is allowed without event card effect. Play anytime.
		normalCombatRounds = 4;
	}

	// Behaviour: Apply the effects of event 13
	if( (p1_events_array[13] == 1) || (p2_events_array[13] == 1) ){
		// [13] Gladitorial_Games - You and a target player must move one unit to No-Man's-Land. The units will fight until one is destroyed
		normalCombatRounds = 10; 
	}

	// Behaviour: Set the combat calculator to the third round
	theCombatCalculator = &standardRounds;

	// Behaviour: Set the protected values
	theCombatCalculator->setCombatParticipants(p1BattleParticipant, p2BattleParticipant, p1MonkParticipant, p2MonkParticipant);

	// Behaviour: Calculate the damage dealt for X rounds of standard combat and display the results
	standardRounds.roundOutcome(normalCombatRounds, preferToRollDice, attackingPlayerNumber, p1_events_array, p2_events_array);

	// Behaviour: Get the results after X = two rounds of standard combat
	p1BattleParticipant = theCombatCalculator->returnModifiedBattleParticipants(player1);
	p2BattleParticipant = theCombatCalculator->returnModifiedBattleParticipants(player2);

	// Behaviour: A required return statement for the system in C++
	return 0;
}