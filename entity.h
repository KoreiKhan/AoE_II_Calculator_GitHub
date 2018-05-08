/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string

/** The entity class **/
#ifndef ENTITY_H
#define ENTITY_H
struct Entity{ 
	// Declare data members
	std::string entityName; // The name of the entity (including the civilization designator)
	int entityAge; // The Age that the entity is available at (1,2,3,4)
	int entityQuantity; // The quantity of the entity
	int entityHealth; // The health of the entity
	int standardDamage; // The damage that entities often deal
	int rangedDamage; // The damage that ranged entities sometime deal
	int garrisonValue; // The garrison value of the entity
	int pointValue; // The points awarded to the enemy for killing the entity
	bool armorClass[20]; // The 20 armor classes for Age of Empires II: The Age of Conquerors civilizations: 
							// [0]: Archer 
							// [1]: Building
							// [2]: Camel
							// [3]: Castle 
							// [4]: Cavalry 
							// [5]: Cavalry_Archer 
							// [6]: Eagle_Warrior 
							// [7]: Gunpowder_Unit 
							// [8]: Infantry 
							// [9]: Monk 
							// [10]: Ram
							// [11]: Ship 
							// [12]: Siege_Weapon
							// [13]: Spearman
							// [14]: Standard_Building
							// [15]: Stone_Defence
							// [16]: Turtle_Ship
							// [17]: Unique_Unit 
							// [18]: Wall_&_Gate
							// [19]: War_Elephant


	// Declare the initializer (set the initial values)
	Entity();
};
#endif // ENTITY_H