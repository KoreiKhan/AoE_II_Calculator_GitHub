/** The libaries **/ 
#include <iostream> // Using: cin, cout
#include "entity.h" // Using: Entity class

/** The calculator class **/
#ifndef MODIFIERS_CALCULATOR_H
#define MODIFIERS_CALCULATOR_H
class modifiersCalculator{
	public:
	// Functions: The constructor and deconstructor 
	modifiersCalculator();
	~modifiersCalculator();

	// Function: Apply the effects of just the attack bonuses
	Entity applyRockPaperScissorsEffects(Entity inputBattleParticipantP1, Entity inputBattleParticipantP2, int inputPlayerNumber);

	// Function: Apply the effects of just the technologies
	Entity applyTechnologyEffects(Entity inputBattleParticipant, int* inputTechnologies);

	// Function: Apply the effects of just the events
	Entity applyEventCardEffects(Entity inputBattleParticipant, int* inputEvents);

	// Function: Apply the effects of 1) attack bonuses, 2) technologies, 3) the relevant event cards, and 4) quantity for player 1's battle participant
	Entity applyAllModifiersP1(const int inputP1PlayerNumber, Entity inputP1BattleParticipant, int* inputP1Technologies, int* inputP1Events, Entity inputP2BattleParticipant);

	// Function: Apply the effects of 1) attack bonuses, 2) technologies, 3) the relevant event cards, and 4) quantity for player 2's battle participant
	Entity applyAllModifiersP2(const int inputP2PlayerNumber, Entity inputP2BattleParticipant, int* inputP2Technologies, int* inputP2Events, Entity inputP1BattleParticipant);
};
#endif // MODIFIERS_CALCULATOR_H

/** The calculator class **/
#ifndef COMBAT_CALCULATOR_H
#define COMBAT_CALCULATOR_H
class combatCalculator{
	// Reference: I do not need to access this data outside of this superclass and the subclasses
	protected:
	// Boolean: Declare whether or not the quantity of the current entities ought to be increas by 1
	// Reference: The quantity ought to go down by 1 if the quantity does not change for the entire battle
	bool healingEffectP1;
	int startingQuantityP1;
	bool healingEffectP2;
	int startingQuantityP2; 

	// Int: Store the latest die roll
	int dieRoll;

	// String: Store the user input for the die roll
	std::string dieRollInput;

	public:
	// Struct: Declare the entities participating in the battle
	Entity combatParticipantP1;
	Entity combatParticipantP2;

	// Functions: The constructor and deconstructor 
	combatCalculator();
	~combatCalculator();

	// Function: Check the d6 die input
	void checkD6DieInput(std::string inputdieRollString);

	// Function: Set the battle participants
	void setCombatParticipants(Entity inputP1CombatParticipant, Entity inputP2CombatParticipant);

	// Function: Calculate the outcome of a battle
	virtual Entity roundOutcome(const int inputPlayerNumber, int inputRunTimes) = 0; // Abstract class with no implementation (overrided by the subclasses)
};
#endif // COMBAT_CALCULATOR_H

#ifndef COMBAT_CALCULATOR_ROUND_1_H
#define COMBAT_CALCULATOR_ROUND_1_H
class round1: public combatCalculator{
	public:
	// Bool: Track if a monk from either players did something
	bool monkPowersActivated;

	// Functions: The constructor and deconstructor
	round1();
	~round1();

	Entity roundOutcome(const int inputPlayerNumber, int inputRunTimes);
};
#endif // COMBAT_CALCULATOR_ROUND_1_H

#ifndef COMBAT_CALCULATOR_ROUND_2_H
#define COMBAT_CALCULATOR_ROUND_2_H
class round2: public combatCalculator{
	public:
	// Bool: Track if a ranged unit from either players did something
	bool rangedAttackActivated;

	// Functions: The constructor and deconstructor
	round2();
	~round2();

	Entity roundOutcome(const int inputPlayerNumber, int inputRunTimes);
};
#endif // COMBAT_CALCULATOR_ROUND_2_H

#ifndef COMBAT_CALCULATOR_ROUND_3_H
#define COMBAT_CALCULATOR_ROUND_3_H
class round3: public combatCalculator{
	public:
	Entity roundOutcome(const int inputPlayerNumber, int inputRunTimes);
};
#endif // COMBAT_CALCULATOR_ROUND_3_H

#ifndef COMBAT_CALCULATOR_ROUND_4_H
#define COMBAT_CALCULATOR_ROUND_4_H
class round4: public combatCalculator{
	public:
	Entity roundOutcome(const int inputPlayerNumber, int inputRunTimes);
};
#endif // COMBAT_CALCULATOR_ROUND_4_H