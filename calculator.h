/** The libaries **/ 
#include <iostream> // Using: cin, cout
#include "entity.h" // Using: Entity class

/** The modifiers calculator class **/
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
	Entity applyEventCardEffects(Entity inputBattleParticipant, int* inputEvents, int inputAttackingPlayerNumber, int inputAge);

	// Function: Apply the effects of 1) attack bonuses, 2) technologies, 3) the relevant event cards, and 4) quantity for player 1's battle participant
	Entity applyAllModifiersP1(const int inputP1PlayerNumber, Entity inputP1BattleParticipant, int* inputP1Technologies, int* inputP1Events, Entity inputP2BattleParticipant, int inputAttackingPlayerNumber, int inputPlayer1Age);

	// Function: Apply the effects of 1) attack bonuses, 2) technologies, 3) the relevant event cards, and 4) quantity for player 2's battle participant
	Entity applyAllModifiersP2(const int inputP2PlayerNumber, Entity inputP2BattleParticipant, int* inputP2Technologies, int* inputP2Events, Entity inputP1BattleParticipant, int inputAttackingPlayerNumber, int inputPlayer2Age);
};
#endif // MODIFIERS_CALCULATOR_H

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

	public:
	// Struct: Declare the entities participating in the battle
	Entity combatParticipantP1, combatParticipantP2;

	// Functions: The constructor and deconstructor 
	combatCalculator();
	~combatCalculator();

	// Function: Generate d6 die input
	int generateD6DieInput();

	// Function: Set the battle participants
	void setCombatParticipants(Entity inputP1CombatParticipant, Entity inputP2CombatParticipant);

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

	// Function: Calculate the outcome of a battle
	virtual void roundOutcome(int inputRunTimes, int inputAttackingPlayerNumber, int* inputP1Events, int* inputP2Events) = 0; // Abstract class with no implementation (overrided by the subclasses)
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
	void roundOutcome(int inputRunTimes, int inputAttackingPlayerNumber, int* inputP1Events, int* inputP2Events);
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
	void roundOutcome(int inputRunTimes, int inputAttackingPlayerNumber, int* inputP1Events, int* inputP2Events);
};
#endif // COMBAT_CALCULATOR_ARCHER_ROUNDS_H

#ifndef COMBAT_CALCULATOR_STANDARD_ROUNDS_H
#define COMBAT_CALCULATOR_STANDARD_ROUNDS_H
class standardRounds: public combatCalculator{
	public:
	// Functions: The constructor and deconstructor
	standardRounds();
	~standardRounds();

	// Function: Calculate the outcome of a standard battle
	void roundOutcome(int inputRunTimes, int inputAttackingPlayerNumber, int* inputP1Events, int* inputP2Events);
};
#endif // COMBAT_CALCULATOR_STANDARD_ROUNDS_H