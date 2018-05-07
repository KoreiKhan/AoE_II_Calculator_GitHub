/** Age of Empires II: The Board Game **/ 
/** Combat Results Calculator **/
/** Created by: Kory **/
/** Written using English (United States) spelling **/

/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string
#include "entity.h" // Using: Entity class
#include "entitiesFile.h" // Using: entitiesFile() function

// Refer to these members of the Entity class
extern Entity blankSelection;
extern Entity p1BattleParticipant;
extern Entity p2BattleParticipant;

/** The main function **/
int main(){
	// Load "entities.txt"
	entitiesFile();

	// Get the name of the entities owned by p1 and p2 from "entities.txt"
	std::string p1BattleParticipantName = "";
	std::string p2BattleParticipantName = "";

	// Get the quantity of the entities owned by p1 and p2 from "entities.txt"
	int p1BattleParticipantQuantity = 0;
	int p2BattleParticipantQuantity = 0;

	// Conduct a search for p1BattleParticipantName and p2BattleParticipantName to update p1BattleParticipant and p2BattleParticipant 
	p1BattleParticipant = conductASearch(p1BattleParticipantName, p1BattleParticipantQuantity);
	p2BattleParticipant = conductASearch(p2BattleParticipantName, p2BattleParticipantQuantity);

	// Output test
	std::cout << p1BattleParticipant.unitName;
}
