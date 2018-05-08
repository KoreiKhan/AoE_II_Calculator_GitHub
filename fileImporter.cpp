/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string
#include <fstream> // Using: ifstream, is_open(), good, close()
#include <cstdlib> // Using: exit(EXIT_FAILURE)
#include <sstream> // Using: stringstream 
#include <algorithm> // Using: transform, toupper, .begin(), .end()
#include "fileImporter.h" // Using: entitiesFile functions
#include "entity.h" // Using: Entity class

/** Declare fileImporter construct and deconstructor **/
fileImporter::fileImporter(){}

fileImporter::~fileImporter(){}

/** Declare the conduct a search on a large number of Age of Empires II entities function **/
Entity fileImporter::conductASearch(std::string inputEntityName, int inputEntityQuantity){
	// Declare the entity to return the rest of the information for
	Entity returnEntity;

	// Search for the input string and return the entire object
	// Enter CTRL + F and search for "BANANA" to skip this section
	if(inputEntityName == "ARCHER"){
		// runFunction("Archer",2,inputEntityQuantity,6,4,5,0,2)
		returnEntity.entityName = "Archer";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 6; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 5; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2; // 1 wood, 1 gold
		returnEntity.armorClass[0] = true; // Archer armor class
	}
	else if(inputEntityName == "ARCHER_(SARACEN)"){
		returnEntity.entityName = "Archer_(Saracen)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 6; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 5; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2; // 1 wood, 1 gold
		returnEntity.armorClass[0] = true; // Archer armor class

		// 5 standardDamage vs Buildings
	}
	else if(inputEntityName == "ARBALEST"){
		returnEntity.entityName = "Arbalest";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 7; 
		returnEntity.rangedDamage = 8; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2; // 1 wood, 1 gold, 1 book (ignored)
		returnEntity.armorClass[0] = true; // Archer armor class
	}
	else if(inputEntityName == "ARBALEST_(BRITON)"){
		returnEntity.entityName = "Arbalest_(Briton)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 6; 
		returnEntity.rangedDamage = 7; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2; // 1 wood, 1 gold, 1 book (ignored)
		returnEntity.armorClass[0] = true; // Archer armor class
	}
	else if(inputEntityName == "ARCHERY_RANGE"){
		returnEntity.entityName = "Archery_Range";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 120; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 10; 
		returnEntity.pointValue = 11; // 6 wood, 5 villagers
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "BARRACKS"){
		returnEntity.entityName = "Barracks";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 120; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 10; 
		returnEntity.pointValue = 11; // 6 wood, 5 villagers
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "BATTERING_RAM"){
		returnEntity.entityName = "Battering_Ram";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 41; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 11; // 7 wood, 4 gold
		returnEntity.armorClass[10] = true; // Ram armor class
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// 60 standard damage vs Building
		// There is a rule that Archers and Villagers cannot attack Rams.
		// There is a rule that this unit can only attack buildings
	}
	else if(inputEntityName == "BATTERING_RAM_(CELT)"){
		returnEntity.entityName = "Battering_Ram_(Celt)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 41; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 10; // 6 wood, 4 gold
		returnEntity.armorClass[10] = true; // Ram armor class
		returnEntity.armorClass[12] = true; // Siege weapon armor class
	
		// 70 standard damage vs Building
		// There is a rule that Archers and Villagers cannot attack Rams. 
		// There is a rule that this is unit can only attack buildings
	}
	else if(inputEntityName == "BLACKSMITH"){
		returnEntity.entityName = "Blacksmith";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 180; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 10; // 6 wood, 4 gold
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "CAPPED_RAM"){
		returnEntity.entityName = "Capped_Ram";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 46; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 11; // 7 wood, 4 gold, 1 book (ignored)
		returnEntity.armorClass[10] = true; // Ram armor class
		returnEntity.armorClass[12] = true; // Siege weapon armor class
	
		// 110 standard damage vs Building
		// There is a rule that Archers and Villagers cannot attack Rams. 
		// There is a rule that this is unit can only attack buildings
	}
	else if(inputEntityName == "CAPPED_RAM_(CELT)"){
		returnEntity.entityName = "Capped_Ram_Celt";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 46; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 10; // 6 wood, 4 gold, 1 book (ignored)
		returnEntity.armorClass[10] = true; // Ram armor class
		returnEntity.armorClass[12] = true; // Siege weapon armor class
	
		// 120 standard damage vs Building
		// There is a rule that Archers and Villagers cannot attack Rams. 
		// There is a rule that this is unit can only attack buildings
	}
	else if(inputEntityName == "CASTLE"){
		returnEntity.entityName = "Castle";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 440; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 10; 
		returnEntity.pointValue = 30;  // 15 stone, 15 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[3] = true; // Castle armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "CASTLE_(FRANK)"){
		returnEntity.entityName = "Castle_(Frank)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 440; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 10; 
		returnEntity.pointValue = 25;  // 10 stone, 15 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[3] = true; // Castle armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "CAVALIER"){
		returnEntity.entityName = "Cavalier";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 30; 
		returnEntity.standardDamage = 12; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 2 food, 3 gold, 1 book (ignored)
		returnEntity.armorClass[4] = true; // Cavalry armor class
	}
	else if(inputEntityName == "CAVALIER_(FRANK)"){
		returnEntity.entityName = "Cavalier_(Frank)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 36; 
		returnEntity.standardDamage = 12; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 2 food, 3 gold, 1 book (ignored)
		returnEntity.armorClass[4] = true; // Cavalry armor class
	}
	else if(inputEntityName == "CAVALIER_(PERSIAN)"){
		returnEntity.entityName = "Cavalier_(Persian)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 30; 
		returnEntity.standardDamage = 12; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 2 food, 3 gold, 1 book (ignored)
		returnEntity.armorClass[4] = true; // Cavalry armor class

		// +2 standardDamage vs Archers
	}
	else if(inputEntityName == "CAVALRY_ARCHER"){
		returnEntity.entityName = "Cavalry_Archer";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 12; 
		returnEntity.standardDamage = 6; 
		returnEntity.rangedDamage = 7; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 1 wood, 2 gold
		returnEntity.armorClass[0] = true; // Archer armor class
		returnEntity.armorClass[4] = true; // Cavalry armor class
		returnEntity.armorClass[5] = true; // Cavalry archer armor class
	}
	else if(inputEntityName == "CAVALRY_ARCHER_(MONGOL)"){
		returnEntity.entityName = "Cavalry_Archer_(Mongol)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 12; 
		returnEntity.standardDamage = 6; 
		returnEntity.rangedDamage = 9; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 1 wood, 2 gold
		returnEntity.armorClass[0] = true; // Archer armor class
		returnEntity.armorClass[4] = true; // Cavalry armor class
		returnEntity.armorClass[5] = true; // Cavalry archer armor class
	}
	else if(inputEntityName == "CHAMPION"){
		returnEntity.entityName = "Champion";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 20; 
		returnEntity.standardDamage = 13; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "CHAMPION_(CELT)"){
		returnEntity.entityName = "Champion_(Celt)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 20; 
		returnEntity.standardDamage = 13; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "CHAMPION_(GOTH)"){
		returnEntity.entityName = "Champion_(Goth)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 20; 
		returnEntity.standardDamage = 13; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	
		// +2 vs buildings
	}
	else if(inputEntityName == "CHAMPION_(JAPANESE)"){
		returnEntity.entityName = "Champion_(Japanese)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 20; 
		returnEntity.standardDamage = 17; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	
		// +2 vs buildings
	}
	else if(
		(inputEntityName == "CHARLAMAGNE'S_PALACE_AT_AIX_LA'CHAPELLE_(BRITON)") || 
		(inputEntityName == "BRITON_WONDER") ||
		(inputEntityName == "ROCK_OF_CASHEL_(CELT)") ||
		(inputEntityName == "CELT_WONDER") ||
		(inputEntityName == "THE_GOLDEN_TENT_OF_THE_GREAT_KHAN_(MONGOL)") ||
		(inputEntityName == "MONGOL_WONDER") ||
		(inputEntityName == "THE_PALACE_OF_CTESIPHON_ON_THE_TIGRIS_(PERSIAN)") ||
		(inputEntityName == "PERSIAN_WONDER") ||
		(inputEntityName == "TOMB_OF_THEODORIC_(GOTH)") ||
		(inputEntityName == "GOTH_WONDER") ||
		(inputEntityName == "WONDER") 
		){
		// Represents all Wonders
		int turnsInPlay = 0;
		std::cout << "How many turns have the Wonder been in play for?" << "\n";
		std::cin >> turnsInPlay;

		// The rules state that you win if the wonder is in play for 6 turns
		if(turnsInPlay < 1 || turnsInPlay > 6){
			std::cout << "Error: Wonder ought to be in play for 1-6 turns only" << "\n";
			exit(EXIT_FAILURE);
		}

		returnEntity.entityName = "Wonder";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 

		if(turnsInPlay == 1){
			returnEntity.entityHealth = 110; 
		}
		else if (turnsInPlay == 2){
			returnEntity.entityHealth = 220;
		}
		else if(turnsInPlay == 3){
			returnEntity.entityHealth = 330;
		}
		else{
			returnEntity.entityHealth = 440;
		}
		
		returnEntity.standardDamage = 17; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 90;  // 20 wood, 20 stone, 20 gold, 30 bodies
		// The rules do not state a point value for the Wonder but it ought to have one
		returnEntity.armorClass[1] = true; // Building armor class

	}
	else if(inputEntityName == "CROSSBOWMAN"){
		returnEntity.entityName = "Crossbowman";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 5; 
		returnEntity.rangedDamage = 6; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 wood, 1 gold, 1 book (ignored)
		returnEntity.armorClass[0] = true; // Archer armor class
	}
	else if(inputEntityName == "CROSSBOWMAN_(SARACEN)"){
		returnEntity.entityName = "Crossbowman_(Saracen)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 5; 
		returnEntity.rangedDamage = 6; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 wood, 1 gold, 1 book (ignored)
		returnEntity.armorClass[0] = true; // Archer armor class
	
		// 6 standardDamage vs building
	}
	else if(inputEntityName == "DEMOLITION_SHIP"){
		returnEntity.entityName = "Demolition_Ship";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 13; 
		returnEntity.standardDamage = 110; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 1 wood, 2 gold
		returnEntity.armorClass[11] = true; // Ship armor class

		// Only attacks in the second round of combat
		// Units cannot retreat against the Demolition Ship
	}
	else if(inputEntityName == "DOCK"){
		returnEntity.entityName = "Dock";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 150; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 5; 
		returnEntity.pointValue = 8;  // 5 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "DOCK_(PERSIAN)"){
		returnEntity.entityName = "Dock_(Persian)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 300; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 5; 
		returnEntity.pointValue = 8;  // 5 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "DOCK_(VIKING)"){
		returnEntity.entityName = "DOCK_(VIKING)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 150; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 5; 
		returnEntity.pointValue = 6;  // 3 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "ELITE_HUSKARL_(GOTH)"){
		returnEntity.entityName = "Elite_Huskarl_(Goth)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 20; 
		returnEntity.standardDamage = 12; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[17] = true; // Unique unit armor class
	
	// 15 standardDamage vs building
	}
	else if(inputEntityName == "ELITE_LONGBOWMAN_(Briton)"){
		returnEntity.entityName = "Elite_Longbowman_(Briton)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 12; 
		returnEntity.rangedDamage = 10; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 wood, 1 gold, 1 book (ignored)
		returnEntity.armorClass[0] = true; // Archer armor class
		returnEntity.armorClass[17] = true; // Unique unit armor class
	}
	else if(inputEntityName == "ELITE_SKIRMISHER"){
		returnEntity.entityName = "Elite_Skirmisher";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 3; 
		returnEntity.rangedDamage = 5; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 wood, 1 gold, 1 book (ignored)
		returnEntity.armorClass[0] = true; // Archer armor class
	
		// 16 standardDamage against Archers
	}
	else if(inputEntityName == "ELITE_WAR_ELEPHANT_(PERSIAN)"){
		returnEntity.entityName = "Elite_War_Elephant_(Persian)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 126; 
		returnEntity.standardDamage = 25; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 15;  // 10 food, 5 gold, 1 book (ignored)
		returnEntity.armorClass[4] = true; // Cavalry armor class
		returnEntity.armorClass[17] = true; // Unique unit armor class
		returnEntity.armorClass[19] = true; // War Elephant unit armor class

		// The current entity is limited to 1 token per card 
		if(inputEntityQuantity !=1){
			std::cout << "Error: " << returnEntity.entityName << " can only be of 1 quantity" << "\n";
			exit(EXIT_FAILURE);
		}
	
		// 60 standardDamage against Buildings
	}
	else if(inputEntityName == "ELITE_WOAD_RAIDER_(CELT)"){
		returnEntity.entityName = "Elite_Woad_Raider_(Celt)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 22; 
		returnEntity.standardDamage = 13; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[17] = true; // Unique unit armor class

		// 17 standardDamage vs Building
	}
	else if(inputEntityName == "FARM"){
		returnEntity.entityName = "Farm";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 40; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 4;  // 2 wood, 2 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "FISHING_SHIP_(JAPANESE)"){
		returnEntity.entityName = "Fishing_Ship_(Japanese)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 30; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 2 wood
		returnEntity.armorClass[11] = true; // Ship armor class
	}
	else if(inputEntityName == "FISHING_SHIP_(PERSIAN)"){
		returnEntity.entityName = "Fishing_Ship_(Persian)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 2 wood
		returnEntity.armorClass[11] = true; // Ship armor class
	}
	else if(inputEntityName == "FORTIFIED_WALL"){
		returnEntity.entityName = "Fortified_Wall";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 280; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 6 stone, 1 book (ignored)
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
		returnEntity.armorClass[15] = true; // Stone defence armor class
		returnEntity.armorClass[19] = true; // Wall & Gate armor class
	}
	else if(inputEntityName == "GALLEY_(JAPANESE)"){
		returnEntity.entityName = "Galley_(Japanese)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 30; 
		returnEntity.standardDamage = 14; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 4 wood, 2 gold
		returnEntity.armorClass[11] = true; // Ship armor class

		// 30 standardAttack vs Longboat, land unit, building, and galley
		// Bombardment 1 (only eligible to attack in the 1st round of combat)
	}
	else if(inputEntityName == "GALLEY_(SARACEN)"){
		returnEntity.entityName = "Galley_(Saracen)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 30; 
		returnEntity.standardDamage = 17; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 4 wood, 2 gold
		returnEntity.armorClass[11] = true; // Ship armor class

		// 35 standardAttack vs Longboat, land unit, building, and galley
		// Bombardment 0 (only eligible to attack in the 1st round of combat)
	}
	else if(inputEntityName == "GALLEY_(VIKING)"){
		returnEntity.entityName = "Galley_(Viking)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 30; 
		returnEntity.standardDamage = 14; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 2 wood, 1 gold
		returnEntity.armorClass[11] = true; // Ship armor class

		// 30 standardAttack vs Longboat, land unit, building, and galley
		// Bombardment 0 (only eligible to attack in the 1st round of combat)
	}
	else if(inputEntityName == "GATE"){
		returnEntity.entityName = "Gate";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 380; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 3 stone, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
		returnEntity.armorClass[15] = true; // Stone defence armor class
		returnEntity.armorClass[19] = true; // Wall & Gate armor class
	}
	else if(inputEntityName == "GOLD_MINE"){
		returnEntity.entityName = "Gold_Mine";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 80; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 3 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "GOLD_MINE_(JAPANESE)"){
		returnEntity.entityName = "Gold_Mine_(Japanese)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 80; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 4;  // 1 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "HEAVY_CAMEL"){
		returnEntity.entityName = "Heavy_Camel";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 30; 
		returnEntity.standardDamage = 7; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 4;  // 2 food, 2 gold, 1 book (ignored)
		returnEntity.armorClass[2] = true; // Camel armor class

		// 30 standardDamage against Cavalry
	}
	else if(inputEntityName == "HEAVY_CAVALRY_ARCHER"){
		returnEntity.entityName = "Heavy_Cavalry_Archer";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 7; 
		returnEntity.rangedDamage = 8; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 1 wood, 2 gold, 1 book (ignored)
		returnEntity.armorClass[0] = true; // Archer armor class
		returnEntity.armorClass[4] = true; // Cavalry armor class
		returnEntity.armorClass[5] = true; // Cavalry archer armor class
	}
	else if(inputEntityName == "HEAVY_CAVALRY_ARCHER_(MONGOL)"){
		returnEntity.entityName = "Heavy_Cavalry_Archer_(Mongol)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 7; 
		returnEntity.rangedDamage = 10; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 1 wood, 2 gold, 1 book (ignored)
		returnEntity.armorClass[0] = true; // Archer armor class
		returnEntity.armorClass[4] = true; // Cavalry armor class
		returnEntity.armorClass[5] = true; // Cavalry archer armor class
	}
	else if(inputEntityName == "HEAVY_DEMOLITION_SHIP"){
		returnEntity.entityName = "Heavy_Demolition_Ship";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 140; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 3 wood, 3 gold, 1 book (ignored)
		returnEntity.armorClass[11] = true; // Ship armor class

		// Only attacks in the second round of combat
		// Units cannot retreat against the Demolition Ship
	}
	else if(inputEntityName == "HEAVY_DEMOLITION_SHIP_(VIKING)"){
		returnEntity.entityName = "Heavy_Demolition_Ship_(Viking)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 140; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 1 wood, 2 gold, 1 book (ignored)
		returnEntity.armorClass[11] = true; // Ship armor class

		// Only attacks in the second round of combat
		// Units cannot retreat against the Demolition Ship
	}
	else if(inputEntityName == "HEAVY_SCORPION"){
		returnEntity.entityName = "Heavy_Scorpion";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 12; 
		returnEntity.standardDamage = 16; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 8;  // 4 wood, 4 gold, 1 book (ignored)
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// Bombardment 1
		// Only attacks in the first round of combat
		// Area effect attack
	}
	else if(inputEntityName == "HEAVY_SCORPION_(CELT)"){
		returnEntity.entityName = "Heavy_Scorpion_(Celt)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 12; 
		returnEntity.standardDamage = 19; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 7;  // 3 wood, 4 gold, 1 book (ignored)
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// Bombardment 1
		// Only attacks in the first round of combat
		// Area effect attack
	}
	else if(inputEntityName == "HOUSE"){
		returnEntity.entityName = "House";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 80; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 wood, 1 body
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "HUSKARL_(GOTH)"){
		returnEntity.entityName = "Huskarl_(Goth)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 10; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[17] = true; // Unique unit armor class

		// 12 standardDamage vs Archers
		// 12 standardDamage vs Buildings
	}
	else if(inputEntityName == "KNIGHT"){
		returnEntity.entityName = "Knight";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 26; 
		returnEntity.standardDamage = 10; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 2 food, 3 gold
		returnEntity.armorClass[4] = true; // Cavalry armor class
	}
	else if(inputEntityName == "KNIGHT_(FRANK)"){
		returnEntity.entityName = "Knight_(Frank)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 32; 
		returnEntity.standardDamage = 10; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 2 food, 3 gold
		returnEntity.armorClass[4] = true; // Cavalry armor class
	}
	else if(inputEntityName == "KNIGHT_(PERSIAN)"){
		returnEntity.entityName = "Knight_(Persian)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 26; 
		returnEntity.standardDamage = 10; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold
		returnEntity.armorClass[4] = true; // Cavalry armor class

		// +2 standardDamage vs Archers
	}
	else if(inputEntityName == "LIGHT_CAVALRY"){
		returnEntity.entityName = "Light_Cavalry";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 7; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 3 food, 1 book (ignored)
		returnEntity.armorClass[4] = true; // Cavalry armor class
	}
	else if(inputEntityName == "LIGHT_CAVALRY_(MONGOL)"){
		returnEntity.entityName = "Light_Cavalry_(Mongol)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 20; 
		returnEntity.standardDamage = 7; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 3 food, 1 book (ignored)
		returnEntity.armorClass[4] = true; // Cavalry armor class
	}
	else if(inputEntityName == "LONG_SWORDSMAN"){
		returnEntity.entityName = "Long_Swordsman";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 12; 
		returnEntity.standardDamage = 9; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "LONG_SWORDSMAN_(CELT)"){
		returnEntity.entityName = "Long_Swordsman_(Celt)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 12; 
		returnEntity.standardDamage = 9; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "LONG_SWORDSMAN_(GOTH)"){
		returnEntity.entityName = "Long_Swordsman_(Goth)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 12; 
		returnEntity.standardDamage = 9; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class

		// +2 standardAttack vs Building
	}
	else if(inputEntityName == "LONGBOAT_(VIKING)"){
		returnEntity.entityName = "Longboat_(Viking)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 33; 
		returnEntity.standardDamage = 14; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 3 wood, 3 gold
		returnEntity.armorClass[11] = true; // Ship armor class
		returnEntity.armorClass[17] = true; // Unique unit armor class

		// 40 standardAttack vs Demolition Ship, Galley, Longboat, Building, and Land units
		// Bombardment 1 (only attacks in the first round of combat)
	}
	else if(inputEntityName == "LONGBOWMAN_(BRITON)"){
		returnEntity.entityName = "Longbowman_(Briton)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 10; 
		returnEntity.rangedDamage = 8; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 wood, 1 gold
		returnEntity.armorClass[0] = true; // Archer armor class
		returnEntity.armorClass[17] = true; // Unique unit armor class
	}
	else if(inputEntityName == "LONGSWORDSMAN_(JAPANESE)"){
		returnEntity.entityName = "Longswordsman_(Japanese)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 14; 
		returnEntity.standardDamage = 11; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "LONGSWORDSMAN_(VIKING)"){
		returnEntity.entityName = "Longswordsman_(Viking)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 9; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "LUMBER_CAMP"){
		returnEntity.entityName = "Lumber_Camp";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 80; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 3 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "LUMBER_CAMP_(JAPANESE)"){
		returnEntity.entityName = "Lumber_Camp_(Japanese)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 80; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 2 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "MAMELUKE_(SARACEN)"){
		returnEntity.entityName = "Mameluke_(Saracen)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 18; 
		returnEntity.standardDamage = 7; 
		returnEntity.rangedDamage = 4; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 2 food, 3 gold
		returnEntity.armorClass[0] = true; // Archer armor class
		returnEntity.armorClass[4] = true; // Cavalry armor class
		returnEntity.armorClass[2] = true; // Camel armor class
		returnEntity.armorClass[17] = true; // Unique unit armor class

		// 16 standardAttack vs Cavalry
	}
	else if(inputEntityName == "MAN_AT_ARMS_(VIKING)"){
		returnEntity.entityName = "Man_At_Arms_(Viking)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 11; 
		returnEntity.standardDamage = 6; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "MAN_AT_ARMS"){
		returnEntity.entityName = "Man_At_Arms";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 10; 
		returnEntity.standardDamage = 6; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "MAN_AT_ARMS_(CELT)"){
		returnEntity.entityName = "Man_At_Arms_(Celt)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 10; 
		returnEntity.standardDamage = 6; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "MAN_AT_ARMS_(GOTH)"){
		returnEntity.entityName = "Man_At_Arms_(Goth)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 10; 
		returnEntity.standardDamage = 6; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class

		// +2 standardDamage vs buildings
	}
	else if(inputEntityName == "MAN_AT_ARMS_(JAPANESE)"){
		returnEntity.entityName = "Man_At_Arms_(Japanese)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 10; 
		returnEntity.standardDamage = 7; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "MANGONEL"){
		returnEntity.entityName = "Mangonel";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 12; 
		returnEntity.standardDamage = 40; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 12;  // 7 wood, 5 gold
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// 80 standardDamage vs Building
		// Bombardment 1 (only attacks in first round of normal combat)
	}
	else if(inputEntityName == "MANGONEL_(CELT)"){
		returnEntity.entityName = "Mangonel_(Celt)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 12; 
		returnEntity.standardDamage = 40; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 11;  // 6 wood, 5 gold
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// 90 standardDamage vs Building
		// Bombardment 1 (only attacks in first round of normal combat)
	}
	else if(inputEntityName == "MANGUDAI_(MONGOL)"){
		returnEntity.entityName = "Mangudai_(Mongol)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 8; 
		returnEntity.rangedDamage = 7; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 3 wood, 2 gold
		returnEntity.armorClass[0] = true; // Archer armor class
		returnEntity.armorClass[5] = true; // Cavalry Archer armor class
		returnEntity.armorClass[4] = true; // Cavalry armor class
		returnEntity.armorClass[17] = true; // Unique unit armor class

		// 14 standardAttack vs Siege
	}
	else if(inputEntityName == "MARKET"){
		returnEntity.entityName = "Market";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 180; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 12;  // 6 wood, 6 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "MARKET_(SARACEN)"){
		returnEntity.entityName = "Market_(Saracen)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 180; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 12;  // 6 wood, 6 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "MILITIA"){
		returnEntity.entityName = "Militia";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "MILITIA_(CELT)"){
		returnEntity.entityName = "Militia_(Celt)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "MILITIA_(GOTH)"){
		returnEntity.entityName = "Militia_(GOTH)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold
		returnEntity.armorClass[8] = true; // Infantry armor class

		// +2 standardDamage vs Building
	}
	else if(inputEntityName == "MILL"){
		returnEntity.entityName = "Mill";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 80; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 3 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "MILL_(JAPANESE)"){
		returnEntity.entityName = "Mill_(Japanese)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 80; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 2 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "MONASTERY"){
		returnEntity.entityName = "Monastery";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 180; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 10; 
		returnEntity.pointValue = 10;  // 7 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "ONAGER"){
		returnEntity.entityName = "Onager";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 50; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 12;  // 7 wood, 5 gold, 1 books (ignored)
		returnEntity.armorClass[12] = true; // Siege weapon armor class
	
		// 120 standardAttack vs Building
		// Bombardment 2 (only attacks in the first round)
	}
	else if(inputEntityName == "ONAGER_(CELT)"){
		returnEntity.entityName = "Onager_(Celt)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 50; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 11;  // 6 wood, 5 gold, 1 books (ignored)
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// 130 standardAttack vs Building
		// Bombardment 2 (only attacks in the first round)
	}
	else if(inputEntityName == "OUTPOST"){
		returnEntity.entityName = "Outpost";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 40; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 1 wood, 1 stone, 1 body
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "PALADIN"){
		returnEntity.entityName = "Paladin";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 38; 
		returnEntity.standardDamage = 14; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 2 food, 3 gold, 1 book (ignored)
		returnEntity.armorClass[4] = true; // Cavalry armor class
	}
	else if(inputEntityName == "PALADIN_(PERSIAN)"){
		returnEntity.entityName = "Paladin_(Persian)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 38; 
		returnEntity.standardDamage = 14; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 5;  // 2 food, 3 gold, 1 book (ignored)
		returnEntity.armorClass[4] = true; // Cavalry armor class
	
		// standardAttack +2 vs Archers
	}
	else if(inputEntityName == "PALISADE_WALL"){
		returnEntity.entityName = "Palisade_Wall";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 20; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 wood, 1 body
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
		returnEntity.armorClass[18] = true; // Wall & Gate armor class
	}
	else if(inputEntityName == "PIKEMAN"){
		returnEntity.entityName = "Pikeman";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 14; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[13] = true; // Spearman armor class

		// 40 standardDamage versus Cavalry
	}
	else if(inputEntityName == "PIKEMAN_(CELT)"){
		returnEntity.entityName = "Pikeman_(Celt)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 14; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[13] = true; // Spearman armor class

		// 40 standardDamage versus Cavalry
	}
	else if(inputEntityName == "PIKEMAN_(GOTH)"){
		returnEntity.entityName = "Pikeman_(Goth)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 14; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[13] = true; // Spearman armor class

		// 40 standardDamage versus Cavalry
		// +2 standardDamage versus Building
	}
	else if(inputEntityName == "PIKEMAN_(JAPANESE)"){
		returnEntity.entityName = "Pikeman_(Japanese)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 14; 
		returnEntity.standardDamage = 5; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 wood, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[13] = true; // Spearman armor class

		// 40 standardDamage versus Cavalry
	}
	else if(inputEntityName == "PIKEMAN_(VIKING)"){
		returnEntity.entityName = "Pikeman_(Viking)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 wood, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[13] = true; // Spearman armor class

		// 40 standardDamage versus Cavalry
	}
	else if(inputEntityName == "SCORPION"){
		returnEntity.entityName = "Scorpion";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 12; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 8;  // 4 wood, 4 gold 
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// Area Effect
		// Bombardment 1 (only attacks in the first round)
	}
	else if(inputEntityName == "SCORPION_(CELT)"){
		returnEntity.entityName = "Scorpion_(Celt)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 8; 
		returnEntity.standardDamage = 14; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 7;  // 3 wood, 4 gold 
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// Area Effect
		// Bombardment 1 (only attacks in the first round)
	}
	else if(inputEntityName == "SCOUT_CAVALRY"){
		returnEntity.entityName = "Scout_Cavalry";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 10; 
		returnEntity.standardDamage = 5; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 3 food
		returnEntity.armorClass[4] = true; // Cavalry armor class

	}
	else if(inputEntityName == "SIEGE_ONAGER"){
		returnEntity.entityName = "Siege_Onager";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 20; 
		returnEntity.standardDamage = 75; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 12;  // 7 wood, 5 gold, 1 books (ignored)
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// 180 standardAttack vs Building
		// Bombardment 2 (only attacks in the first round)
	}
	else if(inputEntityName == "SIEGE_ONAGER_(CELT)"){
		returnEntity.entityName = "Siege_Onager_(Celt)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 20; 
		returnEntity.standardDamage = 75; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 11;  // 6 wood, 5 gold, 1 books (ignored)
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// 190 standardAttack vs Building
		// Bombardment 2 (only attacks in the first round)
	}
	else if(inputEntityName == "SIEGE_RAM"){
		returnEntity.entityName = "Siege_Ram";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 60; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 11;  // 7 wood, 4 gold, 1 books (ignored)
		returnEntity.armorClass[10] = true; // Ram armor class
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// 220 standardAttack vs Building
		// Only attacks buildings
	}
	else if(inputEntityName == "SIEGE_RAM_(CELT)"){
		returnEntity.entityName = "Siege_Ram_(Celt)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 60; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 10;  // 6 wood, 4 gold, 1 books (ignored)
		returnEntity.armorClass[10] = true; // Ram armor class
		returnEntity.armorClass[12] = true; // Siege weapon armor class

		// 230 standardAttack vs Building
		// Only attacks buildings
	}
	else if(inputEntityName == "SIEGE_WORKSHOP"){
		returnEntity.entityName = "Siege_Workshop";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 180; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 3; 
		returnEntity.pointValue = 11;  // 7 wood, 4 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "SKIRMISHER"){
		returnEntity.entityName = "Skirmisher";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 6; 
		returnEntity.standardDamage = 2; 
		returnEntity.rangedDamage = 3; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 wood
		returnEntity.armorClass[0] = true; // Archer armor class

		// 12 standardDamage vs Archers
		// 13 rangedDamage vs Archers
	}

	else if(inputEntityName == "SPEARMAN"){
		returnEntity.entityName = "Spearman";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 10; 
		returnEntity.standardDamage = 3; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 wood
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[13] = true; // Spearman armor class

		// 25 standardDamage vs Cavalry
	}
	else if(inputEntityName == "SPEARMAN_(JAPANESE)"){
		returnEntity.entityName = "Spearman_(Japanese)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 10; 
		returnEntity.standardDamage = 4; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 wood
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[13] = true; // Spearman armor class

		// 26 standardDamage vs Cavalry
	}
	else if(inputEntityName == "SPEARMAN_(VIKING)"){
		returnEntity.entityName = "Spearman_(Viking)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 11; 
		returnEntity.standardDamage = 3; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 wood
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[13] = true; // Spearman armor class

		// 25 standardDamage vs Cavalry
	}
	else if(inputEntityName == "SPEARMAN_(CELT)"){
		returnEntity.entityName = "Spearman_(Celt)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 10; 
		returnEntity.standardDamage = 3; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 wood
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[13] = true; // Spearman armor class

		// 25 standardDamage vs Cavalry
	}
	else if(inputEntityName == "SPEARMAN_(GOTH)"){
		returnEntity.entityName = "Spearman_(Goth)";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 10; 
		returnEntity.standardDamage = 3; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 wood
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[13] = true; // Spearman armor class

		// 25 standardDamage vs Cavalry
		// +2 standardDamage vs Buildings
	}
	else if(inputEntityName == "STABLE"){
		returnEntity.entityName = "Stable";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 120; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 10; 
		returnEntity.pointValue = 11;  // 6 wood, 5 body
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "STONE_MINE"){
		returnEntity.entityName = "Stone_Mine";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 80; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 3 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "STONE_MINE_(JAPANESE)"){
		returnEntity.entityName = "Stone_Mine_(Japanese)";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 80; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 4;  // 1 wood, 3 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "STONE_WALL"){
		returnEntity.entityName = "Stone_Wall";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 150; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 stone, 1 body
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
		returnEntity.armorClass[15] = true; // Stone defence armor class
		returnEntity.armorClass[18] = true; // Wall & Gate armor class
	}
	else if(inputEntityName == "TOWN_CENTER"){
		returnEntity.entityName = "Town_Center";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 220; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 17;  // 9 wood, 8 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "TOWN_CENTER_(BRITON)"){
		returnEntity.entityName = "Town_Center_(Briton)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 220; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 12;  // 4 wood, 8 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "TOWN_CENTER_(PERSIAN)"){
		returnEntity.entityName = "Town_Center_(Persian)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 440; 
		returnEntity.standardDamage = 0; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 17;  // 9 wood, 8 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
	}
	else if(inputEntityName == "TREBUCHET"){
		returnEntity.entityName = "Trebuchet";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 36; 
		returnEntity.standardDamage = 200; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 17;  // 7 wood, 5 gold, 5 bodies
		returnEntity.armorClass[12] = true; // Siege weapon armor class
		// Ram armorClass if unpacked. Perhaps check this during the combat calculation phase

		// 450 standardAttack vs Buildings
		// Bombardment 3 (only attacks in first round)
	}
	else if(inputEntityName == "TWO-HANDED_SWORDSMAN"){
		returnEntity.entityName = "Two-handed_Swordsman";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 11; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "TWO-HANDED_SWORDSMAN_(CELT)"){
		returnEntity.entityName = "Two-handed_Swordsman_(CELT)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 11; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "TWO-HANDED_SWORDSMAN_(GOTH)"){
		returnEntity.entityName = "Two-handed_Swordsman_(Goth)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 11; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	
		// +2 standardAttack vs Building
	}
	else if(inputEntityName == "TWO-HANDED_SWORDSMAN_(JAPANESE)"){
		returnEntity.entityName = "Two-handed_Swordsman_(Japanese)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 16; 
		returnEntity.standardDamage = 14; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "TWO-HANDED_SWORDSMAN_(VIKING)"){
		returnEntity.entityName = "Two-handed_Swordsman_(Viking)";
		returnEntity.entityAge = 4;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 19; 
		returnEntity.standardDamage = 11; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold, 1 book (ignored)
		returnEntity.armorClass[8] = true; // Infantry armor class
	}
	else if(inputEntityName == "VILLAGER"){
		returnEntity.entityName = "Villager";
		returnEntity.entityAge = 1;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 4; 
		returnEntity.standardDamage = 3; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 1;  // 1 food

		// No armor class
	}
	else if(inputEntityName == "WAR_ELEPHANT_(PERSIAN)"){
		returnEntity.entityName = "War_Elephant_(Persian)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 94; 
		returnEntity.standardDamage = 15; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 15;  // 15 food, 5 gold
		returnEntity.armorClass[4] = true; // Cavalry armor class
		returnEntity.armorClass[17] = true; // War Elephant armor class
		returnEntity.armorClass[19] = true; // Unique Unit armor class

		// The current entity is limited to 1 token per card 
		if(inputEntityQuantity !=1){
			std::cout << "Error: " << returnEntity.entityName << " can only be of 1 quantity" << "\n";
			exit(EXIT_FAILURE);
		}

		// 3o standardDamage versus building
	}
	else if(inputEntityName == "WAR_GALLEY"){
		returnEntity.entityName = "War_Galley";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 34; 
		returnEntity.standardDamage = 16; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 4 wood, 2 gold, 1 book (ignore)
		returnEntity.armorClass[11] = true; // Ship armor class

		// Bombardment 1 (only attacks in the first round of normal combat)
		// 40 standardDamage versus Longboat, Land unit, Building, and Galley
	}
	else if(inputEntityName == "WAR_GALLEY_(JAPANESE)"){
		returnEntity.entityName = "War_Galley_(Japanese)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 34; 
		returnEntity.standardDamage = 16; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 4 wood, 2 gold, 1 book (ignore)
		returnEntity.armorClass[11] = true; // Ship armor class

		// Bombardment 2 (only attacks in the first round of normal combat)
		// 40 standardDamage versus Longboat, Land unit, Building, and Galley
	}
	else if(inputEntityName == "WAR_GALLEY_(SARACEN)"){
		returnEntity.entityName = "War_Galley_(Saracen)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 34; 
		returnEntity.standardDamage = 20; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 6;  // 4 wood, 2 gold, 1 book (ignore)
		returnEntity.armorClass[11] = true; // Ship armor class

		// Bombardment 1 (only attacks in the first round of normal combat)
		// 50 standardDamage versus Longboat, Land unit, Building, and Galley
	}
	else if(inputEntityName == "WAR_GALLEY_(VIKING)"){
		returnEntity.entityName = "War_Galley_(Viking)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 34; 
		returnEntity.standardDamage = 16; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 3;  // 2 wood, 1 gold, 1 book (ignore)
		returnEntity.armorClass[11] = true; // Ship armor class

		// Bombardment 1 (only attacks in the first round of normal combat)
		// 40 standardDamage versus Longboat, Land unit, Building, and Galley
	}
	else if(inputEntityName == "WATCH_TOWER"){
		returnEntity.entityName = "Watch_Tower";
		returnEntity.entityAge = 2;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 100; 
		returnEntity.standardDamage = 15; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 9;  // 5 stone, 5 bodies
		returnEntity.armorClass[1] = true; // Building armor class
		returnEntity.armorClass[14] = true; // Standard building armor class
		returnEntity.armorClass[15] = true; // Stone defence armor class

		// Bombardment 1 (only attacks in the first round of normal combat)
	}
	else if(inputEntityName == "WOAD_RAIDER_(CELT)"){
		returnEntity.entityName = "Woad_Raider_(Celt)";
		returnEntity.entityAge = 3;
		returnEntity.entityQuantity = inputEntityQuantity; 
		returnEntity.entityHealth = 18; 
		returnEntity.standardDamage = 8; 
		returnEntity.rangedDamage = 0; 
		returnEntity.garrisonValue = 0; 
		returnEntity.pointValue = 2;  // 1 food, 1 gold
		returnEntity.armorClass[8] = true; // Infantry armor class
		returnEntity.armorClass[17] = true; // Unique unit armor class

		// 12 standardDamage vs Buildings
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
		// Error: Each entity should have at least 1 armor class unless a villager
		if(returnEntity.entityName != "Villager"){
			std::cout << "Error: " << returnEntity.entityName << " is missing at least 1 armor class" << "\n";
			exit(EXIT_FAILURE); 
		}
	}
	// Make sure that entities with the building armor class only have a quantity of 1
	if(returnEntity.armorClass[1] == true && inputEntityQuantity!=1){
		// Error: Only 1 building can participate in a battle
		std::cout << "Error: " << returnEntity.entityName << " is a building with !=1 quantity" << "\n";
		exit(EXIT_FAILURE);
	}
	// Make sure that entities with the siege weapon armor class only have a quantity of 1
	if(returnEntity.armorClass[12] == true && inputEntityQuantity !=1){
		std::cout << "Error: " << returnEntity.entityName << " can only be of 1 quantity" << "\n";
		exit(EXIT_FAILURE);
	}
	// Make sure that entities with the ship armor class only have a quantity of 1
	if(returnEntity.armorClass[11] == true && inputEntityQuantity !=1){
		std::cout << "Error: " << returnEntity.entityName << " can only be of 1 quantity" << "\n";
		exit(EXIT_FAILURE);
	}


	return returnEntity;
}
// BANANA


/** A necessary function to see if a string is an integer **/
int fileImporter::checkIsInteger(std::string inputWord){
	// Delare data structures
	int anInteger = 0;
	std::stringstream wordConversion;
	wordConversion << inputWord;
	wordConversion >> anInteger;

	// Check to see if the string to integer conversion worked
	if(wordConversion.good()){
		std::cout << "Error: No valid first quantity" << "\n";
		exit(EXIT_FAILURE);
	}
	else if(anInteger == 0){
		if(inputWord!="0"){
			std::cout << "Error: The output was 0 but the input was not 0 for the first quantity" << "\n";
			exit(EXIT_FAILURE);
		}
		else{
			std::cout << "Error: A quantity of < 1 is unacceptable" << "\n";
			exit(EXIT_FAILURE);
		}
	}
	else{
		// std::cout << checkInteger[0] << "\n"; // Optionally display the output
	}

	return anInteger;
}

/** Code to load the entities file, validate the input, and return the input **/
Entity fileImporter::entitiesFile(int inputPlayerNumber){
	// Declare the entity to return
	Entity returnEntityCSV;

	// Declare a file object
	std::ifstream fileObject;

	// Open "entities.csv"
	fileObject.open("entities.csv");

	// Error: Check if "entities.csv" exists or is successfully opened
	if(!fileObject.is_open()){
		// The file did not open
		std::cout << "Error: Opening the file" << "\n";
		exit(EXIT_FAILURE);
	}
	else{

		// Declare an array that can hold up to four words and a variable to increment this array
		std::string words[4] = {"","","",""};
		int count = 0;

		// Declare a string that can hold one word
		std::string word;

		// While we aren't at the end of the file keep running. Similar to .good() and .eof() 
		while(fileObject>>word){
			// Data validation. Ensure that the user doesn't exceed the array bounds of words[4]
			if(count == 4){
				std::cout << "Error: Too much input. Only enter the values for up to two players" << "\n";
				std::cout << "The input is supposed to be: [P1_Entity_Name] [P1_Entity_Quantity] [P2_Entity_Name] [P2_Entity_Quantity]" << "\n";
				exit(EXIT_FAILURE);
			}
			else{
				// Pass the word into the words array
				words[count] = word;
				count ++;
			}
		}

		// Data validation. Ensure that there are at least four words inside of the words array
		if(count <3){
			std::cout << "Error: Too little input. You must enter the values for up to two players" << "\n";
			std::cout << "The input is supposed to be: [P1_Entity_Name] [P1_Entity_Quantity] [P2_Entity_Name] [P2_Entity_Quantity]" << "\n";
			exit(EXIT_FAILURE);
		}

		// Ensure that the integer elements are of the correct data type (i.e. they are integers)
		int p1Quantity = checkIsInteger(words[1]);
		int p2Quantity = checkIsInteger(words[3]);

		// Data validation. Convert words[0] and words[2] into all caps
		std::transform(words[0].begin(), words[0].end(), words[0].begin(), ::toupper);
		std::transform(words[2].begin(), words[2].end(), words[2].begin(), ::toupper);

		// Display the result to the compiler (testing purposes only)
		/**
		for(int i = 0; i < 4; i++){
			std::cout << words[i] << "\n"; // Data validation. There is no whitespace (by default)
		}
		**/

		// Return the entity name / quantity back
		if(inputPlayerNumber == 1){
			returnEntityCSV.entityName = words[0];
			returnEntityCSV.entityQuantity = p1Quantity;
		}
		else if(inputPlayerNumber == 2){
			returnEntityCSV.entityName = words[2];
			returnEntityCSV.entityQuantity = p2Quantity;
		}
		else{
			std::cout << "Error: Enter 1 for player 1 or 2 for player 2";
			exit(EXIT_FAILURE);
		}

		// Run a huge SEARCH function and return the rest of the information (without user input)
		returnEntityCSV = conductASearch(returnEntityCSV.entityName, returnEntityCSV.entityQuantity);

		return returnEntityCSV;
	}

	// Close the file
	fileObject.close();
}

