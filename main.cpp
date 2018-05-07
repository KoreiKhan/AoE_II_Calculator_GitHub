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

	// Conduct a search for p1BattleParticipantName and p2BattleParticipantName to update p1BattleParticipant and p2BattleParticipant 
	// Note that loading "entities.txt" ought to have passed both the name and quantity of the p1 and p2 entities to p1BattleParticipant and p2BattleParticipant already
	p1BattleParticipant = conductASearch(p1BattleParticipantName, p1BattleParticipantQuantity);
	p2BattleParticipant = conductASearch(p2BattleParticipantName, p2BattleParticipantQuantity);

	// See if this worked test
	// Should return the Age pre-requisite for player 1's entity as inputted inside "entities.txt" 
	std::cout << p1BattleParticipant.unitAge << "\n";
}
