/** Age of Empires II: The Board Game **/ /** Combat Results Calculator **/ /** Coded by: Korei Khan **/

/** The libaries **/
#include <iostream> // Using: cin, cout
#include <string> // Using: string
#include <cstdlib> // Using: exit(EXIT_FAILURE)
#include <stdlib.h> // Using: atoi
#include "entity.h" // Using: entity class
#include "fileImporter.h" // Using: fileImporter class
#include "calculator.h" // Using: calculator class

/** The output entity information function **/
void outputEntityInformation(std::string message, Entity battlingEntityP1, Entity battlingEntityP2, const int inputPlayer1, const int inputPlayer2){
	std::cout << message << "\n";
	battlingEntityP1.outputEntity(inputPlayer1);
	battlingEntityP2.outputEntity(inputPlayer2);
	std::cout << "\n";
}

void checkIfDead(Entity battlingEntityP1, Entity battlingEntityP2){
	if(battlingEntityP1.entityQuantity <=0){
		exit(EXIT_FAILURE);
	}
	else if(battlingEntityP2.entityQuantity <=0){
		exit(EXIT_FAILURE);
	}
}

/** The main function **/
int main(){
	// Constant int: The player numbers
	const int player1 = 1, player2 = 2;

	// Constant int: The number of technologies and events
	const int technologiesNumber = 17, eventsNumber = 46;

	// Int: The current atacker
	std::string attackingPlayer = "1";
	std::cout << "Enter the player number of the current attacker" << "\n";
	std::cin >> attackingPlayer;

	// String: If the entity retreated or not
	std::string retreating = "0";

	// Validate the input player number
	if(attackingPlayer != "1" && attackingPlayer != "2"){
		std::cout << "Error: Input player number not recognized" << "\n";
		exit(EXIT_FAILURE);
	}

	// Object: Declare the file importing object
	fileImporter importFile;

	// Behaviour: Load "entities.csv" and store the information about the input entities
	Entity p1BattleParticipant = importFile.entitiesFile("import/entities.csv", player1); // Declare and get the entity that is participating in the battle for player 1
	Entity p2BattleParticipant = importFile.entitiesFile("import/entities.csv", player2); // Declare and get the entity that is participating in the battle for player 2

	// Behaviour: Load "technologies_[p1/p2].csv" and store the information about the active technologies for player 1 and 2
	int* p1_technologies_array = importFile.aTechnologyOrEventFile("import/technologies_p1.csv", technologiesNumber);
	int* p2_technologies_array = importFile.aTechnologyOrEventFile("import/technologies_p2.csv", technologiesNumber);

	// Behaviour: Load "events_[p1/p2].csv" and store the information about the active events for player 1 and 2
	int* p1_events_array = importFile.aTechnologyOrEventFile("import/events_p1.csv", eventsNumber);
	int* p2_events_array = importFile.aTechnologyOrEventFile("import/events_p2.csv", eventsNumber);

	// Object: Declare the modifiers calculator object
	modifiersCalculator theModifiersCalculator;

	// Behaviour: Apply a range of modifiers to both player's battle participants
	p1BattleParticipant = theModifiersCalculator.applyAllModifiersP1(player1, p1BattleParticipant, p1_technologies_array, p1_events_array, p2BattleParticipant);
	p2BattleParticipant = theModifiersCalculator.applyAllModifiersP2(player2, p2BattleParticipant, p2_technologies_array, p2_events_array, p1BattleParticipant);

	// Behaviour: Return information about the input entities 
	outputEntityInformation("You entered...", p1BattleParticipant, p2BattleParticipant, player1, player2);

	/** Combat round 1 **/
	// Behaviour: Declare the necessary classes
	round1 outcomeRound1;
	combatCalculator *theRound1Calculation = &outcomeRound1;

	// Behaviour: Set the protected values
	theRound1Calculation->setCombatParticipants(p1BattleParticipant, p2BattleParticipant);
	
	// Behaviour: Calculate the damage dealt for each round of the monk combat and display the results
	p1BattleParticipant = outcomeRound1.roundOutcome(player1, 0); 
	p2BattleParticipant = outcomeRound1.roundOutcome(player2, 1);

	// Behaviour: Display the outcome of the monk combat round only if changes occured 
	if(outcomeRound1.monkPowersActivated == true){
		outputEntityInformation("Round 1 (Monk) calculations...", theRound1Calculation->combatParticipantP1, theRound1Calculation->combatParticipantP2, player1, player2);
	}
	else{
		std::cout << "Skipping Round 1 (Monk) calculations..." << "\n";
	}

	/** Combat round 2 - I've yet to calculate building damage **/
	// Behaviour: Declare the necessary classes
	round2 outcomeRound2;
	combatCalculator *theRound2Calculation = &outcomeRound2;

	// Behaviour: Set the protected values
	theRound2Calculation->setCombatParticipants(p1BattleParticipant, p2BattleParticipant);
	
	// Behaviour: Calculate the damage dealt for each round of the archer combat and display the results
	p1BattleParticipant = outcomeRound2.roundOutcome(player1, 0); 
	p2BattleParticipant = outcomeRound2.roundOutcome(player2, 1); 

	// Behaviour: Display the outcome of the archer combat round only if changes occured 
	if(outcomeRound2.rangedAttackActivated == true){
		outputEntityInformation("Round 2 (Archer) calculations...", theRound2Calculation->combatParticipantP1, theRound2Calculation->combatParticipantP2, player1, player2);
	
		// Check that the entities are not dead before continuing
		checkIfDead(p1BattleParticipant, p2BattleParticipant);

		// Behaviour: Ask the attacker if they want to retreat with their archer if they are not versing cavalry or an archer
		std::cout << "Enter 1 if the attacking archer wants to retreat otherwise enter 0" << "\n";
		std::cin >> retreating;

		if( (retreating != "1") && (retreating != "0") ){
			std::cout << "Error: The retreating value can only be a 0 or 1" << "\n";
			exit(EXIT_FAILURE);
		}
	}
	else{
		std::cout << "Skipping Round 2 (Archer) calculations..." << "\n";
	}

	// Behaviour: Do not proceed unless the attacking archer is not retreating (a value of 0)
	if(retreating != "1"){
		/** Combat round 3 - I've yet to calculate building damage **/
		round3 outcomeRound3;
		combatCalculator *theRound3Calculation = &outcomeRound3;

		// Behaviour: Set the protected values
		theRound3Calculation->setCombatParticipants(p1BattleParticipant, p2BattleParticipant);

		// Behaviour: Calculate the damage dealt for each round of the standard combat and display the results
		p1BattleParticipant = outcomeRound3.roundOutcome(player1, 0);
		p2BattleParticipant = outcomeRound3.roundOutcome(player2, 1);

		// Behaviour: Display the outcome of the standard combat round 1 only if changes occured 
		if(outcomeRound3.standardAttack1Activated == true){
			outputEntityInformation("Round 3 (Standard R1) calculations...", theRound3Calculation->combatParticipantP1, theRound3Calculation->combatParticipantP2, player1, player2);
		
			// Check that the entities are not dead before continuing
			checkIfDead(p1BattleParticipant, p2BattleParticipant);

			// Behaviour: Ask the attacker if they want to retreat with their archer if they are not versing cavalry or an archer
			std::cout << "Enter 1 if the attacking entity wants to retreat otherwise enter 0" << "\n";
			std::cin >> retreating;

			if( (retreating != "1") && (retreating != "0") ){
				std::cout << "Error: The retreating value can only be a 0 or 1" << "\n";
				exit(EXIT_FAILURE);
			}
		}
		else{
			std::cout << "Skipping Round 3 (Standard R1) calculations..." << "\n";
		}




	}

	// Behaviour: A required return statement for the system in C++
	return 0;
}