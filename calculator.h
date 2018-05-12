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
	protected:
	// Struct: Declare the entities participating in the battle
	Entity combatParticipant1;
	Entity combatParticipant2;

	public:
	// Functions: The constructor and deconstructor 
	combatCalculator();
	~combatCalculator();

	// Function: Set the battle participants
	void setCombatParticipants(Entity inputP1CombatParticipant, Entity inputP2CombatParticipant);

	// Function: Calculate the outcome of a battle
	virtual void roundOutcome() = 0; // Abstract class with no implementation (overrided by the subclasses)
};
#endif // COMBAT_CALCULATOR_H

#ifndef COMBAT_CALCULATOR_ROUND_1_H
#define COMBAT_CALCULATOR_ROUND_1_H
class round1: public combatCalculator{
	public:
	void roundOutcome();
};
#endif // COMBAT_CALCULATOR_ROUND_1_H