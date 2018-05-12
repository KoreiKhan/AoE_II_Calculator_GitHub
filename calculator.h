/** The libaries **/ 
#include <iostream> // Using: cin, cout
#include "entity.h" // Using: Entity class

/** The calculator class **/
#ifndef CALCULATOR_H
#define CALCULATOR_H
class calculator{
	public:
	// Functions: The constructor and deconstructor 
	calculator();
	~calculator();

	// Function: Apply the effects of technologies and quantity for player 1's battle participant
	Entity applyModifiersSet1P1(Entity inputP1BattleParticipant, int* inputP1Technologies);

	// Function: Apply the effects of technologies and quantity for player 2's battle participant
	Entity applyModifiersSet1P2(Entity inputP2BattleParticipant, int* inputP2Technologies);

	// Function: Calculate the outcome of a battle
	// virtual Entity battleOutcome() = 0 // Abstract class with no implementation (overrided by the subclasses)
};
#endif // CALCULATOR_H

/**
#ifndef COMBAT_ROUND_1_H
#define COMBAT_ROUND_1_H
class round1: public calculator{
	Entity battleOutcome(){
		std::cout << "Round 1 calculations" << "\n";
	}
};
#endif // COMBAT_ROUND_1_H
**/