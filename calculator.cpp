/** The libaries **/ 
#include <iostream> // Using: cin, cout
#include <string> // Using: string
#include <cstdlib> // Using: exit(EXIT_FAILURE), srand(), rand()
#include <stdlib.h> // Using: atoi
#include <cmath> // Using: floor
#include <ctime> // Using: time()
#include "entity.h" // Using: entity class
#include "calculator.h" // Using: calculator class

// Functions: The constructor and deconstructor 
modifiersCalculator::modifiersCalculator(){}
modifiersCalculator::~modifiersCalculator(){}

// Function: Apply the effects of just the rock/paper/scissors system
Entity modifiersCalculator::applyRockPaperScissorsEffects(Entity inputBattleParticipantP1, Entity inputBattleParticipantP2, int inputPlayerNumber){
	Entity applyRockPaperScissorsModifiers;
	Entity comparisonEntity;

	// Behaviour: Set the entity and the comparison entity
	if(inputPlayerNumber == 1){
		applyRockPaperScissorsModifiers = inputBattleParticipantP1;
		comparisonEntity = inputBattleParticipantP2;
	}
	else if(inputPlayerNumber == 2){
		applyRockPaperScissorsModifiers = inputBattleParticipantP2;
		comparisonEntity = inputBattleParticipantP1;
	}
	
	// Archer_(Saracen) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Archer_(Saracen)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 5;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Crossbowman_(Saracen)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 6;
	} 
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Arbalest_(Saracen)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 8;
	} 

	// Battering_Ram line
	if(
	(applyRockPaperScissorsModifiers.armorClass[27] == true) && // Battering Ram
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 60;
	}
	else if(
	(applyRockPaperScissorsModifiers.armorClass[28] == true) && // Capped ram
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 110;
	}
	else if(
	(applyRockPaperScissorsModifiers.armorClass[29] == true) && // Siege ram
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 220;
	}

	// Battering_Ram_(Celt) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Battering_Ram_(Celt)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 70;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Capped_Ram_(Celt)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 120;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Siege_Ram_(Celt)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 230;
	}

	// Knight_(Persian) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Knight_(Persian)") &&
	(comparisonEntity.armorClass[0] == true) // Archer
	){
		applyRockPaperScissorsModifiers.standardDamage += 2;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Cavalier_(Persian)") &&
	(comparisonEntity.armorClass[0] == true) // Archer
	){
		applyRockPaperScissorsModifiers.standardDamage += 2;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Paladin_(Persian)") &&
	(comparisonEntity.armorClass[0] == true) // Archer
	){
		applyRockPaperScissorsModifiers.standardDamage += 2;
	}

	// Camel line
	if(
	(applyRockPaperScissorsModifiers.armorClass[30] == true) && // Camel
	(comparisonEntity.armorClass[4] == true) // Cavalry
	){
		applyRockPaperScissorsModifiers.standardDamage = 20;
	}
	else if(
	(applyRockPaperScissorsModifiers.armorClass[31] == true) && // Heavy camel armor class
	(comparisonEntity.armorClass[4] == true) // Cavalry
	){
		applyRockPaperScissorsModifiers.standardDamage = 30;
	}

	// Cavalry_Archer_(Saracen) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Cavalry_Archer_(Saracen)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 9;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Heavy_Cavalry_Archer_(Saracen)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 10;
	}


	// Militia_(Goth) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Militia_(Goth)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage += 2;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Man_At_Arms_(Goth)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage += 2;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Long_Swordsman_(Goth)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage += 2;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Champion_(Goth)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage += 2;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Two_Handed_Swordsman_(Goth)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage += 2;
	}

	// Militia_(Japanese) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Champion_(Japanese)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage += 2;
	}

	// Berserk_(Viking) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_Berserk_(Viking)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 17;
	}

	// Huskarl_(Goth) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Huskarl_(Goth)") && (
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[0] == true) // Archer
	)){
		if(comparisonEntity.armorClass[1] == true){
			applyRockPaperScissorsModifiers.standardDamage = 12;
		}
		else if(comparisonEntity.armorClass[0] == true){
			applyRockPaperScissorsModifiers.standardDamage = 12;
		}
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_Huskarl_(Goth)") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 15;
	}

	// Longboat_(Viking) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Longboat_(Viking)") && (
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[21] == true) || // Demolition Ship
		(comparisonEntity.armorClass[22] == true) || // Galley
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 40;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_Longboat_(Viking)") && (
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[21] == true) || // Demolition Ship
		(comparisonEntity.armorClass[22] == true) || // Galley
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 50;
	}

	// Mangudai_(Mongol) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Mangudai_(Mongol)") &&
	(comparisonEntity.armorClass[12] == true) // Siege
	){
		applyRockPaperScissorsModifiers.standardDamage = 14;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_Mangudai_(Mongol)") &&
	(comparisonEntity.armorClass[12] == true) // Siege
	){
		applyRockPaperScissorsModifiers.standardDamage = 16;
	}

	// Mameluke_(Saracen) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Mameluke_(Saracen)") &&
	(comparisonEntity.armorClass[4] == true) // Cavalry
	){
		applyRockPaperScissorsModifiers.standardDamage = 16;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_Mameluke_(Saracen)") &&
	(comparisonEntity.armorClass[4] == true) // Cavalry
	){
		applyRockPaperScissorsModifiers.standardDamage = 20;
	}

	// Samurai_(Japanese) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Samurai_(Japanese)") && (
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[17] == true) // Unique Unit
	)){
		if(comparisonEntity.armorClass[1] == true){
			applyRockPaperScissorsModifiers.standardDamage = 10;
		}
		else if(comparisonEntity.armorClass[17] == true){
			applyRockPaperScissorsModifiers.standardDamage = 12;
		}
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_Samurai_(Japanese)") && (
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[17] == true) // Unique Unit
	)){
		if(comparisonEntity.armorClass[1] == true){
			applyRockPaperScissorsModifiers.standardDamage = 15;
		}
		else if(comparisonEntity.armorClass[17] == true){
			applyRockPaperScissorsModifiers.standardDamage = 18;
		}
	}

	// Skirmisher line
	if(
	(applyRockPaperScissorsModifiers.armorClass[32] == true) && ( // Skirmisher
		(comparisonEntity.armorClass[0] == true) || // Archer
		(comparisonEntity.armorClass[5] == true) // Cavalry Archer
	)){
		applyRockPaperScissorsModifiers.standardDamage = 12;
		applyRockPaperScissorsModifiers.rangedDamage = 13;
	}
	else if(
	(applyRockPaperScissorsModifiers.armorClass[33] == true) && ( // Elite Skirmisher
		(comparisonEntity.armorClass[0] == true) || // Archer
		(comparisonEntity.armorClass[5] == true) // Cavalry Archer
	)){
		applyRockPaperScissorsModifiers.standardDamage = 16;
	}

	// Throwing_Axeman_(Frank) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Throwing_Axeman_(Frank)") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 9;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_Throwing_Axeman_(Frank)") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 12;
	}

	// War_Elephant_(Persian) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_War_Elephant_(Persian)") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 60;
	}

	// Woad_Raider_(Celt) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Woad_Raider_(Celt)") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 12;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_Woad_Raider_(Celt)") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 17;
	}

	// Fire_Ship line
	if(
	(applyRockPaperScissorsModifiers.armorClass[23] == true) && ( // Fire Ship
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[23] == true) || // Fire Ship
		(comparisonEntity.armorClass[22] == true) || // Galley
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 10;
	}
	else if(
	(applyRockPaperScissorsModifiers.armorClass[34] == true) && ( // Fast Fire Ship
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[23] == true) || // Fire Ship
		(comparisonEntity.armorClass[22] == true) || // Galley
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 12;
	}

	// Galley line
	if(
	(applyRockPaperScissorsModifiers.armorClass[22] == true) && ( // Galley
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[22] == true) || // Galley
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 30;
	}
	else if(
	(applyRockPaperScissorsModifiers.armorClass[35] == true) && ( // War Galley
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[22] == true) || // Galley
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 40;
	}
	else if(
	(applyRockPaperScissorsModifiers.armorClass[36] == true) && ( // Galleon
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[22] == true) || // Galley
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 50;
	}

	// Galley_(Saracen) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Galley_(Saracen)") && (
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[22] == true) || // Galley
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 35;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "War_Galley_(Saracen)") && (
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[22] == true) || // Galley
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 50;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Galleon_(Saracen)") && (
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.armorClass[22] == true) || // Galley
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 60;
	}

	// Mangonel line
	if(
	(applyRockPaperScissorsModifiers.armorClass[37] == true) && // Mangonel 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 80;
	}
	else if(
	(applyRockPaperScissorsModifiers.armorClass[38] == true) && // Onager 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 120;
	}
	else if(
	(applyRockPaperScissorsModifiers.armorClass[39] == true) && // Siege Onager 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 180;
	}

	// Mangonel_(Celt) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Mangonel_(Celt)") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 90;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Onager_(Celt)") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 130;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Siege_Onager_(Celt)") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 190;
	}

	// Spearman line
	if(
	(applyRockPaperScissorsModifiers.armorClass[40] == true) && // Spearman
	(comparisonEntity.armorClass[4] == true) // Cavalry
	){
		applyRockPaperScissorsModifiers.standardDamage = 25;
	}
	else if(
	(applyRockPaperScissorsModifiers.armorClass[41] == true) && // Pikeman
	(comparisonEntity.armorClass[4] == true) // Cavalry
	){
		applyRockPaperScissorsModifiers.standardDamage = 40;
	}

	// Spearman_(Goth) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Spearman_(Goth)") && (
		(comparisonEntity.armorClass[4] == true) || // Cavalry
		(comparisonEntity.armorClass[1] == true) // Building
	)){
		if(comparisonEntity.armorClass[1] == true){
			applyRockPaperScissorsModifiers.standardDamage += 2;
		}
	}
	if(
	(applyRockPaperScissorsModifiers.entityName == "Pikeman_(Goth)") && (
		(comparisonEntity.armorClass[4] == true) || // Cavalry
		(comparisonEntity.armorClass[1] == true) // Building
	)){
		if(comparisonEntity.armorClass[1] == true){
			applyRockPaperScissorsModifiers.standardDamage += 2;
		}
	}

	// Spearman_(Japanese) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Spearman_(Japanese") &&
	(comparisonEntity.armorClass[4] == true) // Cavalry
	){
		applyRockPaperScissorsModifiers.standardDamage = 26;
	}

	// Trebuchet line
	if(
	(applyRockPaperScissorsModifiers.armorClass[42] == true) && // Trebuchet 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 450;
	}

	return applyRockPaperScissorsModifiers;
}

// Function: Apply the effects of just the technologies
Entity modifiersCalculator::applyTechnologyEffects(Entity inputBattleParticipant, int* inputTechnologies){
	// Object: Declare an entity to make what is happening clearer
	Entity applyTechnologyModifiers = inputBattleParticipant;

	if(inputTechnologies[0] == 1){
		// Blast_Furnace - +6 standardDamage to all Cavalry and Infantry
		if( 
		(applyTechnologyModifiers.armorClass[4] == true) || // Cavalry 
		(applyTechnologyModifiers.armorClass[8] == true) ){ // Infantry
			applyTechnologyModifiers.standardDamage +=6;
		}
	}
	if(inputTechnologies[1] == 1){
		// Bodkin_Arrow - +4 standardDamage and +2 rangedDamage to:
		// Archer, Cavalry Archer, Tower, Castle, Town Center, Galley, Longboat
		// I have yet to include civilization specific versions of the string searched for entities
		if( 
		(applyTechnologyModifiers.armorClass[0] == true) || // Archer
		(applyTechnologyModifiers.armorClass[5] == true) || // Cavalry Archer
		(applyTechnologyModifiers.armorClass[24] == true) || // Watch Tower
		(applyTechnologyModifiers.armorClass[3] == true) || // Castle
		(applyTechnologyModifiers.armorClass[25] == true) || // Town Center
		(applyTechnologyModifiers.armorClass[22] == true) || // Galley
		(applyTechnologyModifiers.entityName == "Longboat_(Viking)") // Longboat example
		){
			applyTechnologyModifiers.standardDamage +=4;
			applyTechnologyModifiers.rangedDamage += 2;
		}
	}
	if(inputTechnologies[2] == 1){
		// Bracer - +6 standardDamage and +3 rangedDamage to:
		// Archer, Cavalry Archer, Tower, Castle, Town Center, Galley, Longboat
		// I have yet to include civilization specific versions of the string searched for entities
		if( 
		(applyTechnologyModifiers.armorClass[0] == true) || // Archer
		(applyTechnologyModifiers.armorClass[5] == true) || // Cavalry Archer
		(applyTechnologyModifiers.armorClass[24] == true) || // Watch Tower
		(applyTechnologyModifiers.armorClass[3] == true) || // Castle
		(applyTechnologyModifiers.armorClass[25] == true) || // Town Center
		(applyTechnologyModifiers.armorClass[22] == true) || // Galley
		(applyTechnologyModifiers.entityName == "Longboat_(Viking)") // Longboat example
		){
			applyTechnologyModifiers.standardDamage +=6;
			applyTechnologyModifiers.rangedDamage += 3;
		}
	}
	if(inputTechnologies[3] == 1){
		// Chain_Barding_Armor - +4 HP to all Cavalry
		if(applyTechnologyModifiers.armorClass[4] == true){ // Cavalry
			applyTechnologyModifiers.entityHealth += 4;
		}  
	}
	if(inputTechnologies[4] == 1){
		// Chain_Mail_Armor- +4 HP to all Infantry
		if(applyTechnologyModifiers.armorClass[8] == true){ // Infantry
			applyTechnologyModifiers.entityHealth += 4;
		} 
	}
	if(inputTechnologies[5] == 1){
		// Fletching - +2 standardDamage and +1 rangedDamage to:
		// Archer, Cavalry Archer, Tower, Castle, Town Center, Galley, Longboat
		// I have yet to include civilization specific versions of the string searched for entities
		if( 
		(applyTechnologyModifiers.armorClass[0] == true) || // Archer
		(applyTechnologyModifiers.armorClass[5] == true) || // Cavalry Archer
		(applyTechnologyModifiers.armorClass[24] == true) || // Watch Tower
		(applyTechnologyModifiers.armorClass[3] == true) || // Castle
		(applyTechnologyModifiers.armorClass[25] == true) || // Town Center
		(applyTechnologyModifiers.armorClass[22] == true) || // Galley
		(applyTechnologyModifiers.entityName == "Longboat_(Viking)") // Longboat example
		){
			applyTechnologyModifiers.standardDamage +=2;
			applyTechnologyModifiers.rangedDamage += 1;
		}
	}
	if(inputTechnologies[6] == 1){
		// Forging - +2 standardDamage to all Cavalry and Infantry
		if( 
		(applyTechnologyModifiers.armorClass[4] == true) || // Cavalry 
		(applyTechnologyModifiers.armorClass[8] == true) ){ // Infantry
			applyTechnologyModifiers.standardDamage +=2;
		}
	}
	if(inputTechnologies[7] == 1){
		// Hoardings - Increase the HP of Castes by +80
		if(applyTechnologyModifiers.armorClass[3] == true){ // Castle 
			applyTechnologyModifiers.entityHealth += 80;
		}
	}
	if(inputTechnologies[8] == 1){
		// Iron_Casting - +4 standardDamage to all Cavalry and Infantry
		if( 
		(applyTechnologyModifiers.armorClass[4] == true) || // Cavalry 
		(applyTechnologyModifiers.armorClass[8] == true) ){ // Infantry
			applyTechnologyModifiers.standardDamage +=4;
		}
	}
	if(inputTechnologies[9] == 1){
		// Leather_Archer_Armor - Increase the HP of Archers, Cavalry Archers by 4
		if( 
		(applyTechnologyModifiers.armorClass[0] == true) || // Archer
		(applyTechnologyModifiers.armorClass[5] == true) // Cavalry Archer
		){
			applyTechnologyModifiers.entityHealth +=4;
		}
	}
	if(inputTechnologies[10] == 1){
		// Loom - +2 HP for Villagers
		if(applyTechnologyModifiers.armorClass[26] == true){ // Villager 
			applyTechnologyModifiers.entityHealth += 2;
		}
	}
	if(inputTechnologies[11] == 1){
		// Padded_Archer_Armor - +2 HP to all Archers, Cavalry Archers
		if( 
		(applyTechnologyModifiers.armorClass[0] == true) || // Archer
		(applyTechnologyModifiers.armorClass[5] == true) // Cavalry Archer
		){
			applyTechnologyModifiers.entityHealth +=2;
		}
	}
	if(inputTechnologies[12] == 1){
		// Plate_Barding_Armor - +6 HP to all Cavalry
		if(applyTechnologyModifiers.armorClass[4] == true){ // Cavalry
			applyTechnologyModifiers.entityHealth += 6;
		}  
	}
	if(inputTechnologies[13] == 1){
		// Plate_Mail_Armor - +6 HP to all Infantry
		if(applyTechnologyModifiers.armorClass[8] == true){ // Infantry
			applyTechnologyModifiers.entityHealth += 6;
		} 
	}
	if(inputTechnologies[14] == 1){
		// Ring_Archer_Armor - +6 HP to all Archers, Cavalry Archers
		if( 
		(applyTechnologyModifiers.armorClass[0] == true) || // Archer
		(applyTechnologyModifiers.armorClass[5] == true) // Cavalry Archer
		){
			applyTechnologyModifiers.entityHealth +=6;
		}
	}
	if(inputTechnologies[15] == 1){
		// Scale_Barding_Armor - +2 HP to all Cavalry
		if(applyTechnologyModifiers.armorClass[4] == true){ // Cavalry
			applyTechnologyModifiers.entityHealth += 2;
		}  
	}
	if(inputTechnologies[16] == 1){
		// Scale_Mail_Armor - +2 HP to all Infantry
		if(applyTechnologyModifiers.armorClass[8] == true){ // Infantry
			applyTechnologyModifiers.entityHealth += 2;
		} 
	}
	
	return applyTechnologyModifiers;
}

Entity modifiersCalculator::applyEventCardEffects(Entity inputBattleParticipant, int* inputEvents, int inputAttackingPlayerNumber, int inputAge){
	Entity applyEventCardModifiers = inputBattleParticipant;

	// String: Store the result from certain event card questions
	std::string isThisRelevant = "";

	if(inputEvents[0] == 1){
		// A Just Case 
		applyEventCardModifiers.standardDamage +=1;
	}
	// [1] Bad Omen - Target unit takes 5 damage for each monk attached
	// [1] Incomplete - Requires Monk + Non-Monk input
	if(inputEvents[2] == 1){
		// [2] Barrel of Grog - If target unit is Celt, they get +2 HP (ought to calculate now)
		std::cout << "Is " << applyEventCardModifiers.entityName << " Celt?" << "\n";
		std::cin >> isThisRelevant;

		if(isThisRelevant == "1"){
			applyEventCardModifiers.entityHealth +=2;
		}
	}
	if(inputEvents[3] == 1){
		// [3] Bone_Shaft_Arrows_(Mongol)
		if(applyEventCardModifiers.armorClass[5] == true){ // Cavalry Archer
			applyEventCardModifiers.standardDamage +=4;
		} 
	}
	// [4] Caught from the Crow's Nest - Target Galley or Fire Ship may deal a bombardment attack before the normal combat begins. This in addition to their one normal bombardment
	// [4] Incomplete - Requires a new bombardment class round
	if(inputEvents[5] == 1){
		// [5] Celtic_Battle_Cry_(Celt)
		if(applyEventCardModifiers.armorClass[8] == true){ // Infantry
			applyEventCardModifiers.standardDamage +=2;
		} 
	}
	if(inputEvents[6] == 1){
		// [6] Dangerous_Times - Attach to a military building. The building has +5 garrison until destroyed (ought to calculate now)
		if(applyEventCardModifiers.armorClass[1] == true){ // Building
			std::cout << "Is Dangerous_Times attached to " << applyEventCardModifiers.entityName << "? Enter 1 if so" << "\n";
			std::cin >> isThisRelevant;

			if(isThisRelevant == "1"){
				applyEventCardModifiers.garrisonValue +=5;
			}
		} 
	}
	// [7] Fat Friars Tavern O'Spirits (done elsewhere)
	if(inputEvents[8] == 1){
		// [8] Field Testing
		if(applyEventCardModifiers.armorClass[8] == true){ // Infantry
			applyEventCardModifiers.entityHealth +=2;
			applyEventCardModifiers.standardDamage +=1;
		} 
	}
	// [9] First Battle Jitter (done elsewhere)
	if(inputEvents[10] == 1){
		// [10] Flaming_Arrows - Attach to an Archer unit. This unit now gets +2 standardDamage vs Buildings (ought to calculate now) 
		if(applyEventCardModifiers.armorClass[0] == true){ // Archer
			std::cout << "Is Flaming_Arrows attached to " << applyEventCardModifiers.entityName << "? Enter 1 if so" << "\n";
			std::cin >> isThisRelevant;

			if(isThisRelevant == "1"){
				applyEventCardModifiers.standardDamage +=2;
			}
		}
	}
	// [11] Fortune_Favors_The_Foolish (done elsewhere)
	if(inputEvents[13] == 1){
		// [12] Gatherin' A Rowdy Bunch
		applyEventCardModifiers.standardDamage -=1;
	}
	// [13] Gladitorial_Games (done elsewhere)
	// [14] Hard to Starboard - Reduce damage dealt to target ship by 10 points per round of combat this turn
	// [14] Incomplete - Not sure about this one
	// [15] Heavy Tree Cover (done elsewhere)
	if(inputEvents[16] == 1){
		// [16] High Ground - Target Archer gains range bonus for this battle. Age II-+1. Age III+2. Age IV+3 (ought to calculate now)
		if(applyEventCardModifiers.armorClass[0] == true){ // Archer
			std::cout << "Is High_Ground attached to " << applyEventCardModifiers.entityName << "? Enter 1 if so" << "\n";
			std::cin >> isThisRelevant;

			if(isThisRelevant == "1"){
				switch(inputAge){
					case 1:
					break;
					case 2:
					applyEventCardModifiers.rangedDamage +=1;
					break;
					case 3:
					applyEventCardModifiers.rangedDamage +=2;
					break;
					case 4:
					applyEventCardModifiers.rangedDamage +=3;
					break;
				}
			}
		}
	}

	if(inputEvents[17] == 1){
		// [17] Husbandry - Attach to a Cavalry Unit. That unit gains +2 HP (ought to calculate now)
		if(applyEventCardModifiers.armorClass[4] == true){ // Cavalry
			std::cout << "Is Husbandry attached to " << applyEventCardModifiers.entityName << "? Enter 1 if so" << "\n";
			std::cin >> isThisRelevant;

			if(isThisRelevant == "1"){
				applyEventCardModifiers.entityHealth +=2;
			}
		}
	}
	// [18] It's A Miracle (done elsewhere)
	// [19] Listen To A Story - Attempt 1-3 conversions this battle. Pay per conversion
	// [19] Incomplete - Not working
	// [20] Muddy Battlefield (done elsewhere)
	// [21] Non-Compos Mentis - Roll a 1d6 when in combat. On a: 1: take 10 extra damage per round, 2: draw 2 cards, 3: no effect, 4: deal 10 extra damage per round, 5: discard 2 cards, 6: deal 15 extra damage per round. Play anytime. (skip for now)
	// [21] Incomplete - Not sure about
	// [22] Opportunity Knocks - If you have two adjacent attacking units, they may target the same defending unit. There is no retreat allowed this battle. Or you may draw three cards (skip for now)
	// [22] Incomplete - Not sure about
	// [23] Piety - If you have one monk attached to a unit, your conversion rate is 4. If the attempt fails, the monk dies
	// [23] Incomplete - Want to figure out why [19] is not working first
	// [24] Poor Morale - Play when a target unit loses at least 1 token in battle. That unit must retreat. Can be played after archer range round (skip for now)
	if(inputEvents[25] == 1){
		// [25] Rally The Workers
		if(applyEventCardModifiers.entityName == "Villager"){
			applyEventCardModifiers.standardDamage += 3;
		}
	}
	// [26] Relentless Attack - This battle, any damage remaining in a round after casualties have been taken carries over into the next round. Remaining damage at the end of this battle is lost (skip for now)
	// [26] Incomplete - Not sure about
	// [27] Retreat - Target unit must retreat before the first round of combat. The ranged round does not count as the first round of combat (skip for now)
	// [27] Incomplete - Requires global storing of retreat
	// [28] Rough Waters - Target ship may not defend this turn
	// [28] Incomplete - Not sure about
	// [29] Shots In The Back (Briton) - If a unit in combat with your Archer retreats, your Archer deals an additional round of range damage without taking any damage
	// [29] Incomplete - Not sure about
	// [30] Soak The Timbers (done elsewhere)
	if(inputEvents[31] == 1){
		// [31] Spirits of the Ancestors - Target imit may not attack or move this turn. For unit owner's next turn, the unit get +3 standardDamage (skip for now)
		std::cout << "Is it player " << inputAttackingPlayerNumber << "'s next turn in regards to Spirits of the Ancestors? Enter 1 if so" << "\n";
			std::cin >> isThisRelevant;

			if(isThisRelevant == "1"){
				applyEventCardModifiers.standardDamage +=3;
			}
	}

	if(inputEvents[32] == 1){
		// [32] Squires - Attach to an Infantry Unit. That unit gets +2 HP (ought to calculate now)
		if(applyEventCardModifiers.armorClass[8] == true){ // Infantry
			std::cout << "Is Squires attached to " << applyEventCardModifiers.entityName << "? Enter 1 if so" << "\n";
			std::cin >> isThisRelevant;

			if(isThisRelevant == "1"){
				applyEventCardModifiers.entityHealth +=2;
			}
		}
	}
	// [33] Steady Hand - Target Archer unit may do ranged damage to a Cavalry unit this turn
	// [33] Incomplete - Not sure about
	// [34] The Hammer's Cavalry (Franks) - Play when one of your Cavalry units is reduced to 1 token. Add two tokens to the unit at no cost
	// [34] Incomplete - Not sure about
	// [35] The Jester Is Dead, Let's Get Em (Celt) (done elsewhere)
	if(inputEvents[36] == 1){
		// [36] Vengeance Is Mine! - Target unit gets +3 HP +3 AP this turn, when defending in your village. Play anytime.(ought to calculate now)
		std::cout << "Is Vengeance_Is_Mine! attached to " << applyEventCardModifiers.entityName << "? Enter 1 if so" << "\n";
		std::cin >> isThisRelevant;

		if(isThisRelevant == "1"){
			applyEventCardModifiers.standardDamage +=2;
			applyEventCardModifiers.entityHealth += 3;
		}
	}
	// [37] While They're Sleeping - Target attacking Infantry unit takes no damage for the first round of combat. The ranged round does not count as the first round of combat
	// [37] Incomplete - Not sure about
	// [38] You Will Die! (Done elsewhere)
	// [39] Zealous Monks - Target Monk unit gets 1 conversion roll at a 3 or less rate for each monk attached (skip for now)
	// [39] Incomplete - Waiting on [19] to work

	return applyEventCardModifiers;
}


// Function: Apply the effects of 1) attack bonuses, 2) technologies, 3) the relevant event cards, and 4) quantity for player 1's battle participant
Entity modifiersCalculator::applyAllModifiersP1(const int inputP1PlayerNumber, Entity inputP1BattleParticipant, int* inputP1Technologies, int* inputP1Events, Entity inputP2BattleParticipant, int inputAttackingPlayerNumber, int inputPlayer1Age){
	// Struct: The modified battle participant to return
	Entity p1BattleParticipantModified = inputP1BattleParticipant;

	//1) Attack bonus effects
	p1BattleParticipantModified = applyRockPaperScissorsEffects(inputP1BattleParticipant, inputP2BattleParticipant, inputP1PlayerNumber);

	//2) Technology effects
	p1BattleParticipantModified = applyTechnologyEffects(p1BattleParticipantModified, inputP1Technologies);

	//3) The relevant event card effects (where easy to implement)
	p1BattleParticipantModified = applyEventCardEffects(p1BattleParticipantModified, inputP1Events, inputAttackingPlayerNumber, inputPlayer1Age);

	//4) Quantity effects
	p1BattleParticipantModified.standardDamage *= p1BattleParticipantModified.entityQuantity;
	p1BattleParticipantModified.rangedDamage *= p1BattleParticipantModified.entityQuantity;
	p1BattleParticipantModified.pointValue *= p1BattleParticipantModified.entityQuantity;

	return p1BattleParticipantModified;
}

// Function: Apply the effects of 1) attack bonuses, 2) technologies, 3) the relevant event cards, and 4) quantity for player 2's battle participant
Entity modifiersCalculator::applyAllModifiersP2(const int inputP2PlayerNumber, Entity inputP2BattleParticipant, int* inputP2Technologies, int* inputP2Events, Entity inputP1BattleParticipant, int inputAttackingPlayerNumber, int inputPlayer2Age){
	// Struct: The modified battle participant to return
	Entity p2BattleParticipantModified = inputP2BattleParticipant;

	//1) Attack bonus effects
	p2BattleParticipantModified = applyRockPaperScissorsEffects(inputP1BattleParticipant, inputP2BattleParticipant, inputP2PlayerNumber);

	//2) Technology effects
	p2BattleParticipantModified = applyTechnologyEffects(p2BattleParticipantModified, inputP2Technologies);

	//3) The relevant event card effects (where easy to implement)
	p2BattleParticipantModified = applyEventCardEffects(p2BattleParticipantModified, inputP2Events, inputAttackingPlayerNumber, inputPlayer2Age);

	//4) Quantity effects
	p2BattleParticipantModified.standardDamage *= p2BattleParticipantModified.entityQuantity;
	p2BattleParticipantModified.rangedDamage *= p2BattleParticipantModified.entityQuantity;
	p2BattleParticipantModified.pointValue *= p2BattleParticipantModified.entityQuantity;

	return p2BattleParticipantModified;
}

// Function: The constructor/deconstructor
combatCalculator::combatCalculator(){
	// Behaviour: Declare the initial values
	healingEffectP1 = false;
	startingQuantityP1 = 0;
	healingEffectP2 = false;
	startingQuantityP2 = 0;
	d6DieRoll = 0;
	aDeathHasOccured = false;
	isRetreating = "";
}
combatCalculator::~combatCalculator(){}

// Function: Set the battle participants
void combatCalculator::setCombatParticipants(Entity inputP1CombatParticipant, Entity inputP2CombatParticipant){
	combatParticipantP1 = inputP1CombatParticipant;
	combatParticipantP2 = inputP2CombatParticipant;
}

int combatCalculator::generateD6DieInput(){
	// Int: Declare a variable to store the generated integer value
	int d6Value = 0;

	// Behaviour: Use an integer value as a random seed for pseudo random number generation
	srand(time(0));

	// Behaviour: Store a random number between 1 and 6
	d6Value = rand() % 6 + 1; 

	// Behaviour: Check that the random function worked
	if(
		(d6Value != 1) &&
		(d6Value != 2) &&
		(d6Value != 3) &&
		(d6Value != 4) &&
		(d6Value != 5) &&
		(d6Value != 6)
	){
		std::cout << "Error: A d6 die only reads the numbers 1-6" << "\n";
		exit(EXIT_FAILURE);
	}
	else{
		return d6Value;
	}
}

// Function: Return the modified battle participants based on the input player number
Entity combatCalculator::returnModifiedBattleParticipants(const int inputPlayerNumber){
	// Behaviour: Return the entities with the combat results applied
	if(inputPlayerNumber == 1){
		return combatParticipantP1;
	}
	else if(inputPlayerNumber == 2){
		return combatParticipantP2;
	}
	else{
		std::cout << "Error: Input player number not recognized" << "\n";
		exit(EXIT_FAILURE);
	}
}

// Function: Check if any of the entities have died before proceeding to the next round of combat
void combatCalculator::checkIfDead(){
	if(combatParticipantP1.entityQuantity <=0){
		aDeathHasOccured = true;
	}
	else if(combatParticipantP2.entityQuantity <=0){
		aDeathHasOccured = true;
	}
}

// Function: Check if the attacking ranged archer is retreating
void combatCalculator::checkIfRetreating(){
	// Behaviour: Ask the attacker if they want to retreat with their archer if they are not versing cavalry or an archer
	std::cout << "For entities that can retreat: Enter 1 if retreating or 0 if fighting in the next round" << "\n";
	std::cin >> isRetreating;

	if( (isRetreating != "1") && (isRetreating != "0") ){
		std::cout << "Error: The retreating value can only be a 0 or 1" << "\n";
		exit(EXIT_FAILURE);
	}
}

/** Function: Output the entity information with a message **/
void combatCalculator::outputEntityInformation(std::string inputMessage){
	// Behaviour: Only display the message if there is a message to be displayed
	std::cout << "\n";

	if(inputMessage != ""){
		std::cout << inputMessage << "\n";
	}

	// Behaviour: Run a function to output the entity inforamtion
	combatParticipantP1.outputEntity(1);
	combatParticipantP2.outputEntity(2);	
}

// Function: Make some final checks (after the end of the rounds of combat)
void combatCalculator::finalChecks(){
	// Behaviour: Check if the extra unit from the monk healing power ought to die
	if(combatParticipantP1.entityQuantity == startingQuantityP1){
		combatParticipantP1.entityQuantity -= 1;
	}
	if(combatParticipantP2.entityQuantity == startingQuantityP2){
		combatParticipantP2.entityQuantity -= 1;
	}
}

// Function: The constructor / deconstructor
monkRounds::monkRounds(){}
monkRounds::~monkRounds(){}

// Function: Calculate the outcome of a monk battle
void monkRounds::roundOutcome(int inputRunTimes, int inputAttackingPlayerNumber, int* inputP1Events, int* inputP2Events){
	// Bool: Track if either player has a monk to begin with
	bool monkPresentP1 = false, monkPresentP2 = false;

	// Bool: Track if a monk from either players did something
	bool monkPowersActivatedP1 = false, monkPowersActivatedP2 = false;

	// Integer: Declare the amount of points awarded
	int p1PointsLost = 0, p2PointsLost = 0;

	// Integer: Declare the amount of entities saved (by healing)
	int p1EntitiesHealed = 1;
	int p2EntitiesHealed = 1;

	// Behaviour: Increase the number of entities saved (by healing) if event 18 is active
	if(inputP1Events[18] == 1){
		// [18] It's A Miracle - A successful Healing attempt saves us up three tokens, instead of one. Play this card before an attempt is made
		p1EntitiesHealed = 3;
	}

	if(inputP2Events[18] == 1){
		// [18] It's A Miracle - A successful Healing attempt saves us up three tokens, instead of one. Play this card before an attempt is made
		p2EntitiesHealed = 3;
	}

	// Behaviour: Run the monk battle round for X times
	for(int i = 0; i < inputRunTimes; i ++){
		// Behaviour: Check that no deaths have occured
		checkIfDead();

		// Behaviour: Make sure that no deaths have occured before proceeding
		if(aDeathHasOccured == false) {

			// Behaviour: See if player 1 has a monk
			if(combatParticipantP1.armorClass[9] == true){
				monkPresentP1 = true;
			}
			else{
				monkPresentP1 = false;
			}

			// Behaviour: See if player 2 has a monk
			if(combatParticipantP2.armorClass[9] == true){
				monkPresentP2 = true;
			}
			else{
				monkPresentP2 = false;
			}

			// Behaviour: If player 2 plays event 7 then player 1's monk is practically non-present
			if(inputP2Events[7] == 1){
				// [7] Fat Friars Tavern O'Spirits - Monks on target unit may not have any Conversion or Healing attempts this turn
				monkPresentP1 = false;
			}

			// Behaviour: If player 1 plays event 7 then player 2's monk is practically non-present
			if(inputP1Events[7] == 1){
				// [7] Fat Friars Tavern O'Spirits - Monks on target unit may not have any Conversion or Healing attempts this turn
				monkPresentP2 = false;
			}

			// Behaviour: If player 1's monk powers is present then proceed
			if(monkPresentP1 == true){
				// Behaviour: Ask the user if they are performing a conversion or healing attempt and store the answer
				std::string calculationModeP1 = "0";
				std::cout << "Is player 1's monk performing a conversion (enter 0) or healing attempt (enter 1)?" << "\n";
				std::cin >> calculationModeP1;

				// Behaviour: Validate the input before proceeding
				if( (calculationModeP1 != "0") && (calculationModeP1 != "1") ){
					std::cout << "Error: Player 1 entered non-zero and non-one for the monk" << "\n";
					exit(EXIT_FAILURE);
				}

				// Behaviour: Generate, validate, and return d6 dice input before proceeding
				d6DieRoll = generateD6DieInput(); 

				/**
				// Behaviour: Give the player the option to roll the die again if they have event 19
				if(inputP1Events[19] == 1){
					bool stopWhileLoop = false;
					std::string getP1Response = "";

					// While will loop the code if the conditions are true
					while(d6DieRoll < combatParticipantP1.entityQuantity && stopWhileLoop == false){
						std::cout << "The conversion failed. Would player 1 with Listen_To_A_Story like to attempt another conversion? Enter 1 if so. ENter 0 if not" << "\n";
						std::cin >> getP1Response;
						if(getP1Response == "1"){
							d6DieRoll = generateD6DieInput();
							std::cout << "<< Player 1 must pay 2 gold" << "\n";
						}
						else if(getP1Response == "0"){
							stopWhileLoop = true;
						}
					}
				}
				**/

				// Behaviour: See if the monk powers are activated
				if(combatParticipantP1.entityQuantity >= d6DieRoll){
					monkPowersActivatedP1 = true;
				}
				else{
					monkPowersActivatedP1 = false;
					// Behaviour: Return the fact that the attempt was unsuccessful
					std::cout << "Player 1's monk powers failed to activate" << "\n";
				}

				// Behaviour: Act on the success odds
				if( (monkPowersActivatedP1 == true) && (calculationModeP1 == "0") ){
					// Behaviour: Act on the conversion attempt being successful
					// std::cout << "The conversion attempt by player 1's monk was successful" << "\n";
					p2PointsLost = (combatParticipantP2.pointValue / combatParticipantP2.entityQuantity);
					combatParticipantP2.entityQuantity -= 1;
				}
				else if ( (monkPowersActivatedP1 == true) && (calculationModeP1 == "1") ){
					// Behaviour: Act on the healing attempt being successful
					// std::cout << "The healing attempt by player 1's monk was successful" << "\n";
					healingEffectP1 = true;
					startingQuantityP1 = combatParticipantP1.entityQuantity;
					combatParticipantP1.entityQuantity += p1EntitiesHealed;
				}
				else{
					// Skipped
				}
			}


			// Behaviour: If player 2's monk powers is present then proceed
			if(monkPresentP2 == true){
				// Behaviour: Ask the user if they are performing a conversion or healing attempt and store the answer
				std::string calculationModeP2 = "0";
				std::cout << "Is player 2's monk performing a conversion (enter 0) or healing attempt (enter 1)?" << "\n";
				std::cin >> calculationModeP2;

				// Behaviour: Validate the input before proceeding
				if( (calculationModeP2 != "0") && (calculationModeP2 != "1") ){
					std::cout << "Error: Player 2 entered non-zero and non-one for the monk" << "\n";
					exit(EXIT_FAILURE);
				}

				// Behaviour: Generate, validate, and return d6 dice input before proceeding
				d6DieRoll = generateD6DieInput(); 

				// Behaviour: See if the monk powers are activated
				if(combatParticipantP2.entityQuantity >= d6DieRoll){
					monkPowersActivatedP2 = true;
				}
				else{
					monkPowersActivatedP2 = false;
					// Behaviour: Return the fact that the attempt was unsuccessful
					std::cout << "Player 2's monk powers failed to activate" << "\n";
				}

				// Behaviour: Act on the success odds
				if( (monkPowersActivatedP2 == true) && (calculationModeP2 == "0") ){
					// Behaviour: Act on the conversion attempt being successful
					// std::cout << "The conversion attempt by player 2's monk was successful" << "\n";
					p1PointsLost = (combatParticipantP1.pointValue / combatParticipantP1.entityQuantity);
					combatParticipantP1.entityQuantity -=1;
				}
				else if ( (monkPowersActivatedP2 == true) && (calculationModeP2 == "1") ){
					// Behaviour: Act on the healing attempt being successful
					// std::cout << "The healing attempt by player 2's monk was successful" << "\n";
					healingEffectP2 = true;
					startingQuantityP2 = combatParticipantP2.entityQuantity;
					combatParticipantP2.entityQuantity += p2EntitiesHealed;
				}
				else{
					// No effect
				}
			}
				
			// Behaviour: Display the outcome of the monk combat round only if changes occured 
			if( (monkPowersActivatedP1 == true) || (monkPowersActivatedP2 == true) ){
				std::string outputString = "Phase 1) Monk round "+std::to_string(i+1)+" calculations...";
				outputEntityInformation(outputString);

				// Behaviour: Display how many points were added if appropriate
				if(p2PointsLost != 0){
					std::cout << ">> Player 1 gets " << p2PointsLost << " points" << "\n";
				}
				if(p1PointsLost !=0){
					std::cout << ">> Player 2 gets " << p1PointsLost << " points" << "\n";
				}
			}
			else{
				std::cout << "\n" << "Skipping Phase 1) Monk round "+std::to_string(i+1)+" calculations..." << "\n";
			}

			// Behaviour: Check if a death has occured
			checkIfDead();
		}
	}
}

// Functions: The constructor and deconstructor
archerRounds::archerRounds(){}

archerRounds::~archerRounds(){}

// Function: Calculate the outcome of a ranged battle
void archerRounds::roundOutcome(int inputRunTimes, int inputAttackingPlayerNumber, int* inputP1Events, int* inputP2Events){
	// Bool: Track if a ranged unit from either players did something
	bool p1ArcherPresent = false, p2ArcherPresent = false;

	// Integer: Declare the number of units killed in this round
	int p1EntityDeaths = 0, p2EntityDeaths = 0;

	// Integer: Declare the amount of damage dealt to buildings in this round
	int p1BuildingDamage = 0, p2BuildingDamage = 0, roundDownMultiple = 10;

	// Integer: Get whether the archer entity is fighting a building
	bool isP1FightingBuilding = false, isP2FightingBuilding = false;

	// Integer: Declare the amount of damage die to place onto buildings
	int p1DamageDie = 0, p2DamageDie = 0;

	// Integer: Declare the amount of points awarded
	float p1PointsLost = 0, p2PointsLost = 0;

	// Integer: Track if changes occured to the quantity
	int p1StartingQuantity = 0, p1EndingQuantity = 0;
	int p2StartingQuantity = 0, p2EndingQuantity = 0;

	// Behaviour: Run the ranged battle round for X times
	for(int i = 0; i < inputRunTimes; i ++){
		// Behaviour: Check that no deaths have occured
		checkIfDead();

		// Behaviour: Set the activation conditions to false
		p1ArcherPresent = false;
		p2ArcherPresent = false;
		isP1FightingBuilding = false;
		isP2FightingBuilding = false;

		// Behaviour: Make sure that no deaths have occured and that the attacking entity is not retreating before proceeding
		if( (aDeathHasOccured == false) && (isRetreating != "1") ) {
			// Behaviour: Check if player 1 has an archer and if they are not fighting cavalry
			if( (combatParticipantP1.armorClass[0] == true) && (combatParticipantP2.armorClass[4] != true) ){
				// Behaviour: Check if player 1 is fighting a building
				if(combatParticipantP2.armorClass[1] == true){ // Building p2
					isP1FightingBuilding = true;
				}
				else{
					isP1FightingBuilding = false;
				}

				// Behaviour: Calculate the damage against buildings if player 1 is fighting a building
				if(isP1FightingBuilding == true){
					p2BuildingDamage = ((combatParticipantP1.rangedDamage) - ((combatParticipantP1.rangedDamage) % roundDownMultiple));
					p2DamageDie = p2BuildingDamage/10;
				}
				// Behaviour: Calculate the damage against units if player 1 is fighting a unit
				else{
					p2EntityDeaths = std::floor( (combatParticipantP1.rangedDamage) / (combatParticipantP2.entityHealth) ); 
				}

				p1ArcherPresent = true;
			}
			else{
				p1ArcherPresent = false;
			}


			// Behaviour: Check if player 2 has an archer and if they are not fighting cavalry
			if( (combatParticipantP2.armorClass[0] == true) && (combatParticipantP1.armorClass[4] != true) ){
				// Behaviour: Check if player 2 is fighting a building
				if(combatParticipantP1.armorClass[1] == true){ // Building p1
					isP2FightingBuilding = true;
				}
				else{
					isP2FightingBuilding = false;
				}

				// Behaviour: Calculate the damage against buildings if player 2 is fighting a building
				if(isP2FightingBuilding == true){
					p1BuildingDamage = ((combatParticipantP2.rangedDamage) - ((combatParticipantP2.rangedDamage) % roundDownMultiple));
					p1DamageDie = p1BuildingDamage/10;
				}
				// Behaviour: Calculate the damage against units if player 2 is fighting a unit
				else{
					p1EntityDeaths = std::floor( (combatParticipantP2.rangedDamage) / (combatParticipantP1.entityHealth) ); 
				}

				p2ArcherPresent = true;
			}
			else{
				p2ArcherPresent = false;
			}

			// Behaviour: Negate the ranged attack round for p2 if p2 has heavy tree cover
			if(inputP2Events[15] == 1){
				// [15] Heavy Tree Cover - Negate range combat round in target battle involving one of your units
				p2EntityDeaths = 0;
				p2BuildingDamage = 0;
				p2DamageDie = 0;
			}

			// Behaviour: Negate the ranged attack round for p1 if p1 has heavy tree cover
			if(inputP1Events[15] == 1){
				// [15] Heavy Tree Cover - Negate range combat round in target battle involving one of your units
				p1EntityDeaths = 0;
				p1BuildingDamage = 0;
				p1DamageDie = 0;
			}

			// Behaviour: Apply the results for p1 if ranged damage occured
			if(p1ArcherPresent == true){
				// Behaviour: Apply the results to buildings or non-buildings
				if(isP1FightingBuilding == true){
					// Behaviour: Decrease the building HP
					if(p2BuildingDamage != 0){
						// Behaviour: Set the point value to the buildings point
						p2PointsLost = combatParticipantP2.pointValue;

						combatParticipantP2.entityHealth -= p2BuildingDamage;

						// Behaviour: if the HP of the building is > 0 then do not keep the set the point value
						if(combatParticipantP2.entityHealth > 0){
							p2PointsLost = 0;
						}
					}
				}
				else{
					// Behavior: Store the starting quantity
					p2StartingQuantity = combatParticipantP2.entityQuantity;

					// Behaviour: Store how many points the entity is individually worth
					p2PointsLost = (combatParticipantP2.pointValue / combatParticipantP2.entityQuantity);

					// Behaviour: Divide the rangedDamage and pointValue by the current quantity to get the values by 1
					combatParticipantP2.rangedDamage /= combatParticipantP2.entityQuantity;
					combatParticipantP2.pointValue /= combatParticipantP2.entityQuantity;

					// Behaviour: Now decrease the quantity
					combatParticipantP2.entityQuantity -= p2EntityDeaths;

					// Behaviour: Now multiply the rangedDamage and pointValue by the new quantity
					combatParticipantP2.rangedDamage *= combatParticipantP2.entityQuantity;
					combatParticipantP2.pointValue *= combatParticipantP2.entityQuantity;

					// Behavior: Store the ending quantity and cap the ending quantity at 0
					if(combatParticipantP2.entityQuantity < 0){
						p2EndingQuantity = 0;
					}
					else{
						p2EndingQuantity = combatParticipantP2.entityQuantity;
					}

					// Behaviour: Calculate the difference between the two quantities
					int p2QuantityDifference = (p2StartingQuantity - p2EndingQuantity);

					// Behaviour: Award points if deaths occured
					if(p2EntityDeaths >=0){
						// Behavior: Calculate the difference between the two quantities
						p2PointsLost *= p2QuantityDifference;
					}
					else{
						p2PointsLost = 0;
					}
				}
			}

			// Behaviour: Apply the results for p2 if ranged damage occured
			if(p2ArcherPresent == true){
				// Behaviour: Apply the results to buildings or non-buildings
				if(isP2FightingBuilding == true){
					// Behaviour: Decrease the building HP
					if(p1BuildingDamage != 0){
						// Behaviour: Set the point value to the buildings point
						p1PointsLost = combatParticipantP1.pointValue;

						combatParticipantP1.entityHealth -= p1BuildingDamage;

						// Behaviour: if the HP of the building is > 0 then do not keep the set the point value
						if(combatParticipantP1.entityHealth > 0){
							p1PointsLost = 0;
						}
					}
				}
				else{
					// Behavior: Store the starting quantity
					p1StartingQuantity = combatParticipantP1.entityQuantity;

					// Behaviour: Store how many points the entity is individually worth
					p1PointsLost = (combatParticipantP1.pointValue / combatParticipantP1.entityQuantity);

					// Behaviour: Divide the rangedDamage and pointValue by the current quantity to get the values by 1
					combatParticipantP1.rangedDamage /= combatParticipantP1.entityQuantity;
					combatParticipantP1.pointValue /= combatParticipantP1.entityQuantity;

					// Behaviour: Now decrease the quantity
					combatParticipantP1.entityQuantity -= p1EntityDeaths;

					// Behaviour: Now multiply the rangedDamage and pointValue by the new quantity
					combatParticipantP1.rangedDamage *= combatParticipantP1.entityQuantity;
					combatParticipantP1.pointValue *= combatParticipantP1.entityQuantity;
				
					// Behavior: Store the ending quantity and cap the ending quantity at 0
					if(combatParticipantP1.entityQuantity < 0){
						p1EndingQuantity = 0;
					}
					else{
						p1EndingQuantity = combatParticipantP1.entityQuantity;
					}

					// Behaviour: Calculate the difference between the two quantities
					int p1QuantityDifference = (p1StartingQuantity - p1EndingQuantity);

					// Behaviour: Award points if deaths occured
					if(p1EntityDeaths >=0){
						// Behavior: Calculate the difference between the two quantities
						p1PointsLost *= p1QuantityDifference;
					}
					else{
						p1PointsLost = 0;
					}
				}
			}


			// Behaviour: Display the outcome of the archer combat round only if changes occured 
			if ( (p1ArcherPresent == true) || (p2ArcherPresent == true) ) {
				std::string outputString = "Phase 2) Archer round "+std::to_string(i+1)+" calculations...";
				outputEntityInformation(outputString);

				// Behaviour: Display how many damage die to place if appropriate
				if(isP1FightingBuilding == true){
					std::cout << ">> Place " << p2DamageDie << " damage die onto player 2's " << combatParticipantP2.entityName << "\n";
				}
				else if(isP2FightingBuilding == true){
					std::cout << ">> Place " << p1DamageDie << " damage die onto player 1's " << combatParticipantP1.entityName << "\n";
				}

				// Behaviour: Display how many points were added if appropriate
				if(p2PointsLost !=0){
					std::cout << ">> Player 1 gets " << p2PointsLost << " points" << "\n";
				}
				if(p1PointsLost !=0){
					std::cout << ">> Player 2 gets " << p1PointsLost << " points" << "\n";
				}

				std::cout << "\n";

				// Behaviour: Check if a death has occured
				checkIfDead();

				// Behaviour: Check if the attacking archer is retreating
				if(aDeathHasOccured == false){
					checkIfRetreating();
				}
			}
			else{
				std::cout << "\n" << "Skipping Phase 2) Archer round "+std::to_string(i+1)+" calculations..." << "\n";
			}
		}
	}
}

// Functions: The constructor and deconstructor
standardRounds::standardRounds(){}

standardRounds::~standardRounds(){}

// Function: Calculate the outcome of a standard round of battle
void standardRounds::roundOutcome(int inputRunTimes, int inputAttackingPlayerNumber, int* inputP1Events, int* inputP2Events){
	// Bool: Track if the standard attack round got activated
	bool standardRoundActivated = false;

	// Integer: Declare the number of units killed in this round
	int p1EntityDeaths = 0, p2EntityDeaths = 0;

	// Integer: Declare the amount of damage dealt to buildings in this round
	int p1BuildingDamage = 0, p2BuildingDamage = 0, roundDownMultiple = 10;

	// Integer: Get whether the archer entity is fighting a building
	bool isP1FightingBuilding = false, isP2FightingBuilding = false;

	// Integer: Declare the amount of damage die to place onto buildings
	int p1DamageDie = 0, p2DamageDie = 0;

	// Integer: Declare the amount of points awarded
	float p1PointsLost = 0, p2PointsLost = 0;

	// Integer: Track if changes occured to the quantity
	int p1StartingQuantity = 0, p1EndingQuantity = 0;
	int p2StartingQuantity = 0, p2EndingQuantity = 0;

	// Behaviour: Figure out the attacker/defender for 2 players
	int currentAttacker = inputAttackingPlayerNumber;
	int currentDefender = 0;
	if(currentAttacker == 1){
		currentDefender = 2;
	}
	else if(currentAttacker == 2){
		currentDefender = 1;
	}

	// Behaviour: Give the attacker/defender more attack based on a d6 die roll
	if(inputP1Events[11] == 1){
		// [11] = Fortune Favors The Foolish
		// 1: Defending unit deals double damage
		// 2: Defending units gain +2 standardDamage per token
		// 3: No effect
		// 4: Attacking unit gains +2 standardDamage per token
		// 5: Attacking unit gains +4 standardDamage per token
		// 6: Attacking unit deals double damage until the end of the turn
		d6DieRoll = generateD6DieInput();
		switch(d6DieRoll){
			case 1:
			if(currentDefender == 1){
				combatParticipantP1.standardDamage *=2;
			}
			else if(currentDefender == 2){
				combatParticipantP2.standardDamage *=2;
			}
			break;
			case 2:
			if(currentDefender == 1){
				combatParticipantP1.standardDamage += (combatParticipantP1.entityQuantity * 2);
			}
			else if(currentDefender == 2){
				combatParticipantP2.standardDamage += (combatParticipantP2.entityQuantity * 2);
			}
			break;
			case 3:
			// No effect
			break;
			case 4:
			if(currentAttacker == 1){
				combatParticipantP1.standardDamage += (combatParticipantP1.entityQuantity * 2);
			}
			else if(currentAttacker == 2){
				combatParticipantP2.standardDamage += (combatParticipantP2.entityQuantity * 2);
			}
			break;
			case 5:
			if(currentAttacker == 1){
				combatParticipantP1.standardDamage += (combatParticipantP1.entityQuantity * 4);
			}
			else if(currentAttacker == 2){
				combatParticipantP2.standardDamage += (combatParticipantP2.entityQuantity * 4);
			}
			break;
			case 6:
			if(currentAttacker == 1){
				combatParticipantP1.standardDamage *=2;
			}
			else if(currentAttacker == 2){
				combatParticipantP2.standardDamage *=2;
			}
			break;
		}
	} 

	if(inputP2Events[11] == 1){
		// [11] = Fortune Favors The Foolish
		// 1: Defending unit deals double damage
		// 2: Defending units gain +2 standardDamage per token
		// 3: No effect
		// 4: Attacking unit gains +2 standardDamage per token
		// 5: Attacking unit gains +4 standardDamage per token
		// 6: Attacking unit deals double damage until the end of the turn
		d6DieRoll = generateD6DieInput();
		switch(d6DieRoll){
			case 1:
			if(currentDefender == 1){
				combatParticipantP1.standardDamage *=2;
			}
			else if(currentDefender == 2){
				combatParticipantP2.standardDamage *=2;
			}
			break;
			case 2:
			if(currentDefender == 1){
				combatParticipantP1.standardDamage += (combatParticipantP1.entityQuantity * 2);
			}
			else if(currentDefender == 2){
				combatParticipantP2.standardDamage += (combatParticipantP2.entityQuantity * 2);
			}
			break;
			case 3:
			// No effect
			break;
			case 4:
			if(currentAttacker == 1){
				combatParticipantP1.standardDamage += (combatParticipantP1.entityQuantity * 2);
			}
			else if(currentAttacker == 2){
				combatParticipantP2.standardDamage += (combatParticipantP2.entityQuantity * 2);
			}
			break;
			case 5:
			if(currentAttacker == 1){
				combatParticipantP1.standardDamage += (combatParticipantP1.entityQuantity * 4);
			}
			else if(currentAttacker == 2){
				combatParticipantP2.standardDamage += (combatParticipantP2.entityQuantity * 4);
			}
			break;
			case 6:
			if(currentAttacker == 1){
				combatParticipantP1.standardDamage *=2;
			}
			else if(currentAttacker == 2){
				combatParticipantP2.standardDamage *=2;
			}
			break;
		}
	} 

	// Behaviour: Give the attacker/defender more attack
	if(inputP1Events[35] == 1){
		// [35] The Jester Is Dead, Let's Get Em (Celt) = Sacrifice 1 of your villagers. +4 standardDamage to all defending units this turn
		if(currentDefender == 1){
			combatParticipantP1.standardDamage +=4;
		}
	}

	if(inputP2Events[35] == 1){
		// [35] The Jester Is Dead, Let's Get Em (Celt) = Sacrifice 1 of your villagers. +4 standardDamage to all defending units this turn
		if(currentDefender == 2){
			combatParticipantP2.standardDamage +=4;
		}
	}

	// Behaviour: Infantry double standard attack vs cavalry
	if(inputP1Events[20] == 1){
		// [20] Muddy Battlefield - Target infantry gets double standardAttack versus Cavalry this turn 
		if( (combatParticipantP1.armorClass[8]) && (combatParticipantP2.armorClass[4]) ){
			combatParticipantP1.standardDamage *=2;
		}
	}

	if(inputP2Events[20] == 1){
		// [20] Muddy Battlefield - Target infantry gets double standardAttack versus Cavalry this turn 
		if( (combatParticipantP2.armorClass[8]) && (combatParticipantP1.armorClass[4]) ){
			combatParticipantP2.standardDamage *=2;
		}
	}

	// Behaviour: Decrease the standardDamage by two units if event 9 is played
	if(inputP1Events[9] == 1){
		// [9] First Battle Jitter - Two tokens on target unit have 0 standardDamage for this battle. Target unit must have five tokens on it
		if(combatParticipantP2.entityQuantity >=5){
			int getIndividualAttackP2 = (combatParticipantP2.standardDamage / combatParticipantP2.entityQuantity);
			combatParticipantP2.standardDamage -= getIndividualAttackP2;
			combatParticipantP2.standardDamage -= getIndividualAttackP2;
		}
	}

	if(inputP2Events[9] == 1){
		// [9] First Battle Jitter - Two tokens on target unit have 0 standardDamage for this battle. Target unit must have five tokens on it
		if(combatParticipantP1.entityQuantity >=5){
			int getIndividualAttackP1 = (combatParticipantP2.standardDamage / combatParticipantP2.entityQuantity);
			combatParticipantP1.standardDamage -= getIndividualAttackP1;
			combatParticipantP1.standardDamage -= getIndividualAttackP1;
		}
	}

	// Behaviour: Multiply the standardDamage by a random number between 1-6 if a Fire Ship
	d6DieRoll = generateD6DieInput(); 

	// Behaviour: Set the result to 0 if player 2 has Soak_The_Timbers
	if(inputP2Events[30] == 1){
		// [30] Soak The Timbers - All enemy Fire Ships get an automatic result of 1 for their die roll when calculating damage this turn
		d6DieRoll = 1;
	}

	if( (combatParticipantP1.armorClass[23] == true) || (combatParticipantP1.armorClass[23] == true) ) { // Fire Ship or Fast Fire Ship
		combatParticipantP1.standardDamage *= d6DieRoll;
	}

	d6DieRoll = generateD6DieInput(); 

	// Behaviour: Set the result to 0 if player 1 has Soak_The_Timbers
	if(inputP1Events[30] == 1){
		// [30] Soak The Timbers - All enemy Fire Ships get an automatic result of 1 for their die roll when calculating damage this turn
		d6DieRoll = 1;
	}

	if( (combatParticipantP2.armorClass[23] == true) || (combatParticipantP2.armorClass[23] == true) ) { // Fire Ship or Fast Fire Ship
		combatParticipantP2.standardDamage *= d6DieRoll;
	}

	// Behaviour: Run the ranged battle round for X times
	for(int i = 0; i < inputRunTimes; i ++){
		// Behaviour: Check that no deaths have occured
		checkIfDead();

		// Set the activation conditions to false
		standardRoundActivated = false;
		isP1FightingBuilding = false;
		isP2FightingBuilding = false;

		// Behaviour: Make sure that no deaths have occured and that the attacking entity is not retreating before proceeding
		if( (aDeathHasOccured == false) && (isRetreating != "1") ) {
			// Behaviour: Check if player 1 is fighting a building
			if(combatParticipantP2.armorClass[1] == true){ // Building p2
				isP1FightingBuilding = true;
			}
			else{
				isP1FightingBuilding = false;
			}

			// Behaviour: Calculate the damage against buildings if player 1 is fighting a building
			if(isP1FightingBuilding == true){
				p2BuildingDamage = ((combatParticipantP1.standardDamage) - ((combatParticipantP1.standardDamage) % roundDownMultiple));
				p2DamageDie = p2BuildingDamage/10;
			}
			// Behaviour: Calculate the damage against units if player 1 is fighting a unit
			else{
				// Behaviour: Check if player 1 has an area effect unit and if so then apply area effect damage
				if(combatParticipantP1.dealsAreaEffectDamage == true){
					int p1AreaEffectUnitDamage = combatParticipantP1.standardDamage / combatParticipantP1.entityQuantity;
					p2EntityDeaths = std::floor ( (((combatParticipantP2.entityQuantity) * (p1AreaEffectUnitDamage)) / combatParticipantP2.entityHealth) );
				}
				else{
					p2EntityDeaths = std::floor( (combatParticipantP1.standardDamage) / (combatParticipantP2.entityHealth) ); 
				}
				
			}

			// Behaviour: Check if player 1 is fighting a building
			if(combatParticipantP1.armorClass[1] == true){ // Building p1
				isP2FightingBuilding = true;
			}
			else{
				isP2FightingBuilding = false;
			}

			// Behaviour: Calculate the damage against buildings if player 2 is fighting a building
			if(isP2FightingBuilding == true){
				p1BuildingDamage = ((combatParticipantP2.standardDamage) - ((combatParticipantP2.standardDamage) % roundDownMultiple));
				p1DamageDie = p1BuildingDamage/10;
			}
			// Behaviour: Calculate the damage against units if player 2 is fighting a unit
			else{
				// Behaviour: Check if player 2 has an area effect unit and if so then apply area effect damage
				if(combatParticipantP2.dealsAreaEffectDamage == true){
					int p2AreaEffectUnitDamage = combatParticipantP2.standardDamage / combatParticipantP2.entityQuantity;
					p1EntityDeaths = std::floor ( (((combatParticipantP1.entityQuantity) * (p2AreaEffectUnitDamage)) / combatParticipantP1.entityHealth) );
				}
				else{
					p1EntityDeaths = std::floor( (combatParticipantP2.standardDamage) / (combatParticipantP1.entityHealth) ); 
				}
			}

			standardRoundActivated = true;
		}
		else{
			standardRoundActivated = false;
		}

		// Behaviour: Clear the results if the entity only attacks once (in the first round of combat) and we are not in the 1st round
		if( (combatParticipantP1.onlyAttacksOnce == true) && (i+1 != 1) ){
			p2BuildingDamage = 0;
			p2DamageDie = 0;
			p2EntityDeaths = 0;
		}
		
		if( (combatParticipantP2.onlyAttacksOnce == true) && (i+1 != 1) ){
			p1BuildingDamage = 0;
			p1DamageDie = 0;
			p1EntityDeaths = 0;
		}

		// Behaviour: Clear the results if the entity only attacks in the second round of combat and we are not in the 2nd round
		if( (combatParticipantP1.onlyAttacksInTheSecondRoundOfStandardCombat == true) && (i+1 != 2) ){
			p2BuildingDamage = 0;
			p2DamageDie = 0;
			p2EntityDeaths = 0;
		}
		
		if( (combatParticipantP2.onlyAttacksInTheSecondRoundOfStandardCombat == true) && (i+1 != 2) ){
			p1BuildingDamage = 0;
			p1DamageDie = 0;
			p1EntityDeaths = 0;
		}

		
		// Behaviour: Apply the results for p1 if the activation conditions were met
		if(standardRoundActivated == true){
			// Behaviour: Apply the results to buildings or non-buildings
			if(isP1FightingBuilding == true){
				// Behaviour: Decrease the building HP
				if(p2BuildingDamage != 0){
					// Behaviour: Set the point value to the buildings point
					p2PointsLost = combatParticipantP2.pointValue;

					combatParticipantP2.entityHealth -= p2BuildingDamage;

					// Behaviour: if the HP of the building is > 0 then do not keep the set the point value
					if(combatParticipantP2.entityHealth > 0){
						p2PointsLost = 0;
					}
				}
			}
			else{
				// Behavior: Store the starting quantity
				p2StartingQuantity = combatParticipantP2.entityQuantity;

				// Behaviour: Store how many points the entity is individually worth
				p2PointsLost = (combatParticipantP2.pointValue / combatParticipantP2.entityQuantity);

				// Behaviour: Divide the standardDamage and pointValue by the current quantity to get the values for a quantity of 1
				combatParticipantP2.standardDamage /= combatParticipantP2.entityQuantity;
				combatParticipantP2.pointValue /= combatParticipantP2.entityQuantity;

				// Behaviour: Now decrease the quantity
				combatParticipantP2.entityQuantity -= p2EntityDeaths;

				// Behaviour: Now multiply the standardDamage and pointValue by the new quantity
				combatParticipantP2.standardDamage *= combatParticipantP2.entityQuantity;
				combatParticipantP2.pointValue *= combatParticipantP2.entityQuantity;

				// Behavior: Store the ending quantity and cap the ending quantity at 0
				if(combatParticipantP2.entityQuantity < 0){
					p2EndingQuantity = 0;
				}
				else{
					p2EndingQuantity = combatParticipantP2.entityQuantity;
				}

				// Behaviour: Calculate the difference between the two quantities
				int p2QuantityDifference = (p2StartingQuantity - p2EndingQuantity);

				// Behaviour: Award points if deaths occured
				if(p2EntityDeaths >=0){
					// Behavior: Calculate the difference between the two quantities
					p2PointsLost *= p2QuantityDifference;
				}
				else{
					p2PointsLost = 0;
				}
			}
		}

		// Behaviour: Apply the results for p2 if ranged damage occured
		if(standardRoundActivated == true){
			// Behaviour: Apply the results to buildings or non-buildings
			if(isP2FightingBuilding == true){
				// Behaviour: Decrease the building HP
				if(p1BuildingDamage != 0){
					// Behaviour: Set the point value to the buildings point
					p1PointsLost = combatParticipantP1.pointValue;

					combatParticipantP1.entityHealth -= p1BuildingDamage;

					// Behaviour: if the HP of the building is > 0 then do not keep the set the point value
					if(combatParticipantP1.entityHealth > 0){
						p1PointsLost = 0;
					}
				}
			}
			else{
				// Behavior: Store the starting quantity
				p1StartingQuantity = combatParticipantP1.entityQuantity;

				// Behaviour: Store how many points the entity is individually worth
				p1PointsLost = (combatParticipantP1.pointValue / combatParticipantP1.entityQuantity);

				// Behaviour: Divide the standardDamage and pointValue by the current quantity to get the values for a quantity of 1
				combatParticipantP1.standardDamage /= combatParticipantP1.entityQuantity;
				combatParticipantP1.pointValue /= combatParticipantP1.entityQuantity;

				// Behaviour: Now decrease the quantity
				combatParticipantP1.entityQuantity -= p1EntityDeaths;

				// Behaviour: Now multiply the standardDamage and pointValue by the new quantity
				combatParticipantP1.standardDamage *= combatParticipantP1.entityQuantity;
				combatParticipantP1.pointValue *= combatParticipantP1.entityQuantity;
			
				// Behavior: Store the ending quantity and cap the ending quantity at 0
				if(combatParticipantP1.entityQuantity < 0){
					p1EndingQuantity = 0;
				}
				else{
					p1EndingQuantity = combatParticipantP1.entityQuantity;
				}

				// Behaviour: Calculate the difference between the two quantities
				int p1QuantityDifference = (p1StartingQuantity - p1EndingQuantity);

				// Behaviour: Award points if deaths occured
				if(p1EntityDeaths >=0){
					// Behavior: Calculate the difference between the two quantities
					p1PointsLost *= p1QuantityDifference;
				}
				else{
					p1PointsLost = 0;
				}
			}
		}

		// Apply the effects of certain entities that automatically die in the second round of combat
		if(i+1 == 2){
			if(combatParticipantP1.isKamikaze == true){
				p1PointsLost = (combatParticipantP1.pointValue / combatParticipantP1.entityQuantity);
				combatParticipantP1.entityQuantity = 0;
			}
			else if(combatParticipantP1.isKamikaze == true){
				p2PointsLost = (combatParticipantP2.pointValue / combatParticipantP2.entityQuantity);
				combatParticipantP2.entityQuantity = 0;
			}
		}


		// Behaviour: Display the outcome of the archer combat round only if changes occured 
		if (standardRoundActivated == true){
			std::string outputString = "Phase 3) Standard round "+std::to_string(i+1)+" calculations...";
			outputEntityInformation(outputString);

			// Behaviour: Display how many damage die to place if appropriate
			if(isP1FightingBuilding == true){
				std::cout << ">> Place " << p2DamageDie << " damage die onto player 2's " << combatParticipantP2.entityName << "\n";
			}
			else if(isP2FightingBuilding == true){
				std::cout << ">> Place " << p1DamageDie << " damage die onto player 1's " << combatParticipantP1.entityName << "\n";
			}

			// Behaviour: Display how many points were added if appropriate
			if(p2PointsLost !=0){
				std::cout << ">> Player 1 gets " << p2PointsLost << " points" << "\n";
			}
			if(p1PointsLost !=0){
				std::cout << ">> Player 2 gets " << p1PointsLost << " points" << "\n";
			}

			std::cout << "\n";

			// Behaviour: Check if a death has occured
			checkIfDead();

			// Behaviour: Check if the attacking entity is retreating
			if(aDeathHasOccured == false){
				checkIfRetreating();
			}
		}
		else{
			std::cout << "Skipping Phase 3) Standard round "+std::to_string(i+1)+" calculations..." << "\n";
		}
	}
}