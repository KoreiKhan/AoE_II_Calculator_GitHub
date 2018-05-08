/** Age of Empires II: The Board Game **/ 
/** Combat Results Calculator **/
/** Created by: Kory **/
/** Written using English (United States) spelling **/

/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string
#include "entity.h" // Using: Entity class
#include "fileImporter.h" // Using: entitiesFile() function
#include <cstdlib> // Using: exit(EXIT_FAILURE)

/** Declare the conduct a search on a large number of Age of Empires II entities function **/
Entity conductASearch(std::string inputEntityName, int inputEntityQuantity){
	// We can perform even more data validation (than "entitiesFile.h" inside this function :
	// - Ensuring that word[0] and word[2] are recognized names
	// - Ensuring that the quantity is only 1 for the building class

	// Declare the entity to return the rest of the information for
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
	else{
		// Make sure that the name inputted into entites.txt is recognized
		std::cout << "Error: The name you entered for one of the entities was not recognized" << "\n";
		exit(EXIT_FAILURE);
	}

	// A few more data validation tests for my manual input
	// Make sure that I entered the age in correctly
	if(returnEntity.entityAge <1 || returnEntity.entityAge > 5){
		// Error: Age not recognized
		std::cout << "Error: " << returnEntity.entityName << " contains an Age other than 1-4" << "\n";
		exit(EXIT_FAILURE); 
	}
	// Make sure that each entity has at least 1 armor class
	bool hasArmorClass = false;
	for(int i = 0; i < 20; i ++){
		if(returnEntity.armorClass[i] == true){
			hasArmorClass = true;
		}
	}
	if(hasArmorClass == false){
		// Error: Each entity should have at least 1 armor class
		std::cout << "Error: " << returnEntity.entityName << " is missing at least 1 armor class" << "\n";
		exit(EXIT_FAILURE); 
	}
	// Make sure that the building armor class only has a quantity of 1
	if(returnEntity.armorClass[1] == true && inputEntityQuantity!=1){
		// Error: Only 1 building can participate in a battle
		std::cout << "Error: " << returnEntity.entityName << " is a building with !=1 quantity" << "\n";
		exit(EXIT_FAILURE);
	}


	return returnEntity;
}

/** The main function **/
int main(){
	// Declare the player numbers
	const int player1 = 1;
	const int player2 = 2;

	Entity p1BattleParticipant; // Declare the entity that is participating in the battle for player 1
	Entity p2BattleParticipant; // Declare the entity that is participating in the battle for player 2

	// Load "entities.csv" and return the values (the name of the entity and quantity of the entity) for player 1 and 2
	fileImporter entitiesCSV;
	p1BattleParticipant = entitiesCSV.entitiesFile(player1);
	p2BattleParticipant = entitiesCSV.entitiesFile(player2);

	// Now that we have attained the name and quantity of the entity, conduct a search to update p1BattleParticipant and p2BattleParticipant with more values
	p1BattleParticipant = conductASearch(p1BattleParticipant.entityName, p1BattleParticipant.entityQuantity);
	p2BattleParticipant = conductASearch(p2BattleParticipant.entityName, p2BattleParticipant.entityQuantity);

	// Should return everything about p1BattleParticipant and p2BattleParticipant except "modifiers_set_1" and "modifiers_set_2"
	p1BattleParticipant.outputEntity();
	p2BattleParticipant.outputEntity();
}
