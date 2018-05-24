/** The libaries **/ 
#include <iostream> // Using: cin, cout
#include "entity.h" // Using: Entity class

/** The combat calculator class **/
#ifndef COMBAT_CALCULATOR_H
#define COMBAT_CALCULATOR_H
class combatCalculator{
	// Reference: I do not need to access this data outside of this superclass and the subclasses
	protected:
	// Boolean: Declare whether or not the quantity of the current entities ought to stay increased by 1 due to monk combat
	// Reference: The quantity ought to go down by 1 if the quantity does not change for the entire battle and healing effect is true for each player
	bool healingEffectP1, healingEffectP2;
	int startingQuantityP1, startingQuantityP2;

	// Int: Store the die roll input 
	int d6DieRoll;

	// Bool: Store whether or not one of the unit has died
	bool aDeathHasOccured;

	// String: Store whether or not an entity is retreating
	std::string isRetreating;

	// Float: Store the remainder for each round of combat
	float *remainingCombatDamageP1;
	float *remainingCombatDamageP2;
	
	// Struct: Declare the entities participating in the battle
	Entity combatParticipantP1, combatParticipantP2, monkParticipantP1, monkParticipantP2;

	// Integer: Store remaining damage
	float remainingDamageP1; // Ought to be static for the calculation of event [26] Relentless Attack. Hard to implement
	float remainingDamageP2; // Ought to be static for the calculation of event [26] Relentless Attack. Hard to implement

	// Integer: Store modifiers to the attack dealt
	int roundAttackModifiersP1;
	int roundAttackModifiersP2;

	public:
	// Functions: The constructor and deconstructor 
	combatCalculator();
	~combatCalculator();

	// Function: Set the battle participants

	// Function: The constructor with variable
	combatCalculator(float* inputRemainingDamageP1, float *inputRemainingDamageP2);

	// Function: Generate d6 die input
	int generateD6DieInput();

	// Function: Calculate the non-rounded value (the decimal value)
	float calculateRemainder(int roundedNumber, int inputAttackerDamage, int inputAttackerModifier, int inputDefenderHealth, int inputSetting);

	// Function: Return the remainder
	float updateRemainder();

	// Function: Check the randomness of the d6 dice roller
	void checkD6DiceSimulator();

	// Function: Set the battle participants
	void setCombatParticipants(Entity inputP1CombatParticipant, Entity inputP2CombatParticipant, Entity inputP1MonkBattleParticipant, Entity inputP2MonkBattleParticipant, int inputRoundAttackModifiersP1, int inputRoundAttackModifiersP2);

	// Function: Return the modified battle participants based on the input player number
	Entity returnModifiedBattleParticipants(const int inputPlayerNumber);

	/** Function: Output the entity information with a message **/
	void outputEntityInformation(std::string inputMessage);

	// Function: Check if any of the entities have died before proceeding to the next round of combat
	void checkIfDead();

	// Function: Check if the attacking ranged archer is retreating
	void checkIfRetreating();

	// Function: Make some final checks (after the end of the rounds of combat)
	void finalChecks();

	// Function: Divide the values by the quantity (to get the individual values)
	void getIndividualValues();

	// Function: Times the values by the quantity (to get the total values)
	void getTotalValues();

	// Function: Calculate the outcome of a battle
	virtual void roundOutcome(int inputRunTimes, int* inputP1Events, int* inputP2Events) = 0; // Abstract class with no implementation (overrided by the subclasses)
};
#endif // COMBAT_CALCULATOR_H

#ifndef COMBAT_CALCULATOR_MONK_ROUNDS_H
#define COMBAT_CALCULATOR_MONK_ROUNDS_H
class monkRounds: public combatCalculator{
	public:
	// Functions: The constructor and deconstructor
	monkRounds();
	~monkRounds();

	// Function: Calculate the outcome of a monk battle
	void roundOutcome(int inputRunTimes, int* inputP1Events, int* inputP2Events);
};
#endif // COMBAT_CALCULATOR_MONK_ROUNDS_H

#ifndef COMBAT_CALCULATOR_ARCHER_ROUNDS_H
#define COMBAT_CALCULATOR_ARCHER_ROUNDS_H
class archerRounds: public combatCalculator{
	public:
	// Functions: The constructor and deconstructor
	archerRounds();
	~archerRounds();

	// Function: Calculate the outcome of a ranged battle
	void roundOutcome(int inputRunTimes, int* inputP1Events, int* inputP2Events);
};
#endif // COMBAT_CALCULATOR_ARCHER_ROUNDS_H

#ifndef COMBAT_CALCULATOR_BOMBARDMENT_ROUNDS_H
#define COMBAT_CALCULATOR_BOMBARDMENT_ROUNDS_H
class bombardmentRounds: public combatCalculator{
	public:
	// Functions: The constructor and deconstructor
	bombardmentRounds();
	~bombardmentRounds();

	// Function: Calculate the outcome of a bombardment battle
	void roundOutcome(int inputRunTimes, int* inputP1Events, int* inputP2Events);
};
#endif // COMBAT_CALCULATOR_BOMBARDMENT_ROUNDS_H

#ifndef COMBAT_CALCULATOR_STANDARD_ROUNDS_H
#define COMBAT_CALCULATOR_STANDARD_ROUNDS_H
class standardRounds: public combatCalculator{
	public:
	// Functions: The constructor and deconstructor
	standardRounds();
	~standardRounds();

	// Function: Calculate the outcome of a standard battle
	void roundOutcome(int inputRunTimes, int* inputP1Events, int* inputP2Events);
};
#endif // COMBAT_CALCULATOR_STANDARD_ROUNDS_H