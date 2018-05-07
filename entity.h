/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string

/** The entity class **/
struct Entity{ 
	std::string unitName; // The name of the entity (including the civilization designator)
	int unitAge; // The Age that the entity is available at (1,2,3,4)
	int unitQuantity; // The quantity of the entity
	int unitHealth; // The health of the entity
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
};

/** Best practice revolves around setting initial values to a declared thing **/ /** I am too lazy to write this multiple times **/
Entity blankSelection{"",0,0,0,0,0,0,0,
false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false}; // Declare an entity with no values

Entity p1BattleParticipant = blankSelection; // Declare the entity that is participating in the battle for player 1
Entity p2BattleParticipant = blankSelection; // Declare the entity that is participating in the battle for player 2

/** A function to take a name and quantity, and return the rest of the information about this entity **/ 
/** Note: 
	- There are a lot of entities in Age of Empires II: The Board Game so the function is long
	- The function reduces the amount of user input **/
Entity conductASearch(std::string inputEntityName, int inputEntityQuantity){
	Entity returnEntity = blankSelection;

	// Search for the input string and return the entire object
	if(inputEntityName == "ARCHER_(SARACEN)"){
		returnEntity = {"ARCHER_(SARACEN)",1,inputEntityQuantity,6,4,5,0,2,
		true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false}; // Update the entity selected by p1
	
	}
	else if(inputEntityName == "CASTLE"){
		returnEntity = {"CASTLE",3,inputEntityQuantity,440,0,0,0,30,
		false,true,false,true,false,false,false,false,false,false,false,false,false,false,true,false,false,false,false}; // Update the entity selected by p2
	}

	return returnEntity;
}