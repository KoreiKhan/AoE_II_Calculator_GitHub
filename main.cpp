/** Age of Empires II: The Board Game **/ 
/** Combat Results Calculator **/
/** Created by: Kory **/
/** Written using English (United States) spelling **/

/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string
#include "entity.h" // Using: Entity class
#include "fileImporter.h" // Using: entitiesFile() function

/** Declare the conduct a search on a large number of Age of Empires II entities function **/
Entity conductASearch(std::string inputEntityName, int inputEntityQuantity){
	// We can perform even more data validation (than "entitiesFile.h" inside this function :
	// - Ensuring that word[0] and word[2] are recognized names
	// - Ensuring that the quantity is only 1 for the building class

	// Declare the entity to return
	Entity returnEntity;

	// Search for the input string and return the entire object
	if(inputEntityName == "ARCHER_(SARACEN)"){
		returnEntity.entityName = "Archer_(Saracen)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 6; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 5; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2; 
		returnEntity.armorClass[0] = true; // Archer armor class
	}
	else if(inputEntityName == "CASTLE"){
		returnEntity.entityName = "Castle";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 440; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 30; 
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[3] = true; // Castle armor class
	}

	return returnEntity;
}

/** The main function **/
int main(){
	Entity p1BattleParticipant; // Declare the entity that is participating in the battle for player 1
	Entity p2BattleParticipant; // Declare the entity that is participating in the battle for player 2

	// Load "entities.csv"
	fileImporter entitiesCSV;
	entitiesCSV.entitiesFile();

	// Conduct a search for p1BattleParticipantName and p2BattleParticipantName to update p1BattleParticipant and p2BattleParticipant 
	// Note that loading "entities.txt" ought to have passed both the name and quantity of the p1 and p2 entities to p1BattleParticipant and p2BattleParticipant already
	p1BattleParticipant = conductASearch(p1BattleParticipant.entityName, p1BattleParticipant.entityQuantity);
	p2BattleParticipant = conductASearch(p2BattleParticipant.entityName, p2BattleParticipant.entityQuantity);

	// See if this worked test
	// Should return the Age pre-requisite for player 1's entity as inputted inside "entities.txt" 
	std::cout << p1BattleParticipant.entityAge << "\n";
}
