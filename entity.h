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
	bool armorClass[20]; // Hold the 20 armor classes for Age of Empires II: The Age of Conquerors (refer to void outputEntity)

	// Declare the initializer/constructor (set the initial values)
	Entity();

	// Declare a function to help with making text colorful
	void displayColorfulText(std::string inputFormatAttribute, std::string inputForegroundColor, std::string inputBackgroundColor, std::string inputText, bool isLineBreak);

	// Declare a function to output information about an entity
	void outputEntity();

	// Delare the deconstructor
	~Entity();
};
#endif // ENTITY_H