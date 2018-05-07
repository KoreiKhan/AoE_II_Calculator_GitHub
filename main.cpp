/** Age of Empires II: The Board Game **/ 
/** Combat Results Calculator **/
/** Created by: Kory **/
/** Written using English (United States) spelling **/

/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string
// #include "calculator.h"; // Using: calculator class (down the line)
using std::string; // Eliminates the need to write std:: for strings
using std::cout; // Eliminates the need to write std:: for cout
using std::cin; // Eliminates the need to write std:: for cin

/** The entity class **/
struct Entity{ 
	string unitName; // The name of the entity (including the civilization designator)
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

Entity blankSelection{"",0,0,0,0,0,0,0,
false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false}; // Declare an entity with no values

Entity p1BattleParticipant = blankSelection; // Declare the entity that is participating in the battle for player 1
Entity p2BattleParticipant = blankSelection; // Declare the entity that is participating in the battle for player 2

/** Take a name and return the object associated to this name function **/
Entity conductASearch(string inputEntityName){
	Entity returnEntity = blankSelection;

	// Search for the input string and return the entire object
	if(inputEntityName == "ARCHER_(SARACEN)"){
		returnEntity = {"ARCHER_(SARACEN)",1,1,6,4,5,2,
		true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false}; // Update the entity selected by p1
	
	}
	else if(inputEntityName == "CASTLE"){
		returnEntity = {"CASTLE",3,1,440,0,0,30,
		false,true,false,true,false,false,false,false,false,false,false,false,false,false,true,false,false,false,false}; // Update the entity selected by p2
	}

	return returnEntity;
}


/** The main function **/
int main(){
	// Get the name of the entities owned by p1 and p2 from "entities.txt"
	string p1BattleParticipantName = "";
	string p2BattleParticipantName = "";

	// Get the quantity of the entities owned by p1 and p2 from "entities.txt"
	int p1BattleParticipantQuantity = 0;
	int p2BattleParticipantQuantity = 0;

	// Conduct a search for p1BattleParticipantName and p2BattleParticipantName to update p1BattleParticipant and p2BattleParticipant 
	p1BattleParticipant = conductASearch(p1BattleParticipantName);
	p2BattleParticipant = conductASearch(p2BattleParticipantName);
}
