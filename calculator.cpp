/** The libaries **/ 
#include <iostream> // Using: cin, cout
#include <string> // Using: string
#include <cstdlib> // Using: exit(EXIT_FAILURE)
#include <stdlib.h> // Using: atoi
#include <cmath> // Using: floor
#include "entity.h" // Using: entity class
#include "calculator.h" // Using: calculator class

// Functions: The constructor and deconstructor 
modifiersCalculator::modifiersCalculator(){}
modifiersCalculator::~modifiersCalculator(){}

// Function: Apply the effects of just the rock/paper/scissors system
Entity modifiersCalculator::applyRockPaperScissorsEffects(Entity inputBattleParticipantP1, Entity inputBattleParticipantP2, int inputPlayerNumber){
	Entity applyRockPaperScissorsModifiers;
	Entity comparisonEntity;

	// I have yet to apply rock/paper/scissors bonuses for general entities to the civilization specific entities
	// I'll have to store every general entity type as an armor class to do this

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
	(applyRockPaperScissorsModifiers.entityName == "Battering_Ram") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 60;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Capped_Ram") &&
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 110;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Siege_Ram") &&
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
	(applyRockPaperScissorsModifiers.entityName == "Heavy_Camel") &&
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
		// Yet to add the armor classes for the entities I search for with a string
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.entityName == "Demolition_Ship") ||
		(comparisonEntity.entityName == "Galley") || 
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 40;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_Longboat_(Viking)") && (
		// Yet to add the armor classes for the entities I search for with a string
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.entityName == "Demolition_Ship") ||
		(comparisonEntity.entityName == "Galley") || 
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
	(applyRockPaperScissorsModifiers.entityName == "Skirmisher") && (
		(comparisonEntity.armorClass[0] == true) || // Archer
		(comparisonEntity.armorClass[5] == true) // Cavalry Archer
	)){
		applyRockPaperScissorsModifiers.standardDamage = 12;
		applyRockPaperScissorsModifiers.rangedDamage = 13;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Elite_Skirmisher") && (
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
	(applyRockPaperScissorsModifiers.entityName == "Fire_Ship") && (
		// Yet to add the armor classes for the entities I search for with a string
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.entityName == "Fire_Ship") ||
		(comparisonEntity.entityName == "Galley") || 
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 10;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Fast_Fire_Ship") && (
		// Yet to add the armor classes for the entities I search for with a string
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.entityName == "Fire_Ship") ||
		(comparisonEntity.entityName == "Galley") || 
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 12;
	}

	// Galley line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Galley") && (
		// Yet to add the armor classes for the entities I search for with a string
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.entityName == "Galley") ||
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 30;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "War_Galley") && (
		// Yet to add the armor classes for the entities I search for with a string
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.entityName == "Galley") ||
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 40;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Galleon") && (
		// Yet to add the armor classes for the entities I search for with a string
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.entityName == "Galley") ||
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 50;
	}

	// Galley_(Saracen) line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Galley_(Saracen)") && (
		// Yet to add the armor classes for the entities I search for with a string
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.entityName == "Galley") ||
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 35;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "War_Galley_(Saracen)") && (
		// Yet to add the armor classes for the entities I search for with a string
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.entityName == "Galley") ||
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 50;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Galleon_(Saracen)") && (
		// Yet to add the armor classes for the entities I search for with a string
		(comparisonEntity.armorClass[1] == true) || // Building
		(comparisonEntity.entityName == "Galley") ||
		(comparisonEntity.entityName == "Longboat_(Viking)") ||
		(comparisonEntity.armorClass[11] != true) // Non-Ship (Land unit)
	)){
		applyRockPaperScissorsModifiers.standardDamage = 60;
	}

	// Mangonel line
	if(
	(applyRockPaperScissorsModifiers.entityName == "Mangonel") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 80;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Onager") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 120;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Siege_Onager") && 
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
	(applyRockPaperScissorsModifiers.entityName == "Spearman") &&
	(comparisonEntity.armorClass[4] == true) // Cavalry
	){
		applyRockPaperScissorsModifiers.standardDamage = 25;
	}
	else if(
	(applyRockPaperScissorsModifiers.entityName == "Pikeman") &&
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
		if(comparisonEntity.armorClass[4] == true){
			applyRockPaperScissorsModifiers.standardDamage = 25;
		}
		else if(comparisonEntity.armorClass[1] == true){
			applyRockPaperScissorsModifiers.standardDamage += 2;
		}
	}
	if(
	(applyRockPaperScissorsModifiers.entityName == "Pikeman_(Goth)") && (
		(comparisonEntity.armorClass[4] == true) || // Cavalry
		(comparisonEntity.armorClass[1] == true) // Building
	)){
		if(comparisonEntity.armorClass[4] == true){
			applyRockPaperScissorsModifiers.standardDamage = 40;
		}
		else if(comparisonEntity.armorClass[1] == true){
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
	(applyRockPaperScissorsModifiers.entityName == "Trebuchet") && 
	(comparisonEntity.armorClass[1] == true) // Building
	){
		applyRockPaperScissorsModifiers.standardDamage = 450;
	}

	return applyRockPaperScissorsModifiers;
}

// Function: Apply the effects of just the technologies
Entity modifiersCalculator::applyTechnologyEffects(Entity inputBattleParticipant, int* inputTechnologies){
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
		(applyTechnologyModifiers.entityName == "Watch_Tower") || // Tower example
		(applyTechnologyModifiers.armorClass[3] == true) || // Castle
		(applyTechnologyModifiers.entityName == "Town_Center") || // Town Center example
		(applyTechnologyModifiers.entityName == "Galley") || // Galley example
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
		(applyTechnologyModifiers.entityName == "Watch_Tower") || // Tower example
		(applyTechnologyModifiers.armorClass[3] == true) || // Castle
		(applyTechnologyModifiers.entityName == "Town_Center") || // Town Center example
		(applyTechnologyModifiers.entityName == "Galley") || // Galley example
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
		(applyTechnologyModifiers.entityName == "Watch_Tower") || // Tower example
		(applyTechnologyModifiers.armorClass[3] == true) || // Castle
		(applyTechnologyModifiers.entityName == "Town_Center") || // Town Center example
		(applyTechnologyModifiers.entityName == "Galley") || // Galley example
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
		if(applyTechnologyModifiers.entityName == "Villager"){ // Villager example
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

Entity modifiersCalculator::applyEventCardEffects(Entity inputBattleParticipant, int* inputEvents){
	Entity applyEventCardModifiers = inputBattleParticipant;

	if(inputEvents[0] == 1){
		// A Just Case 
		applyEventCardModifiers.standardDamage +=1;
	}
	// [1] Bad Omen - Target unit takes 5 damage for each monk attached (skip for now)
	// [2] Barrel of Grog - If target unit is Celt, they get +2 HP (ought to calculate now)
	if(inputEvents[3] == 1){
		// [3] Bone_Shaft_Arrows_(Mongol)
		if(applyEventCardModifiers.armorClass[5] == true){ // Cavalry Archer
			applyEventCardModifiers.standardDamage +=4;
		} 
	}
	// [4] Caught from the Crow's Nest - Target Galley or Fire Ship may deal a bombardment attack begings. This in addition to their one normal bombardment (skip for now)
	if(inputEvents[5] == 1){
		// [5] Celtic_Battle_Cry_(Celt)
		if(applyEventCardModifiers.armorClass[8] == true){ // Infantry
			applyEventCardModifiers.standardDamage +=2;
		} 
	}
	// [6] Dangerous_Times - Attach to a military building. The building has +5 garrison until destroyed (ought to calculate now)
	// [7] Fat Friars Tavern O'Spirits - Monks on target unit may not have any Conversion or Healling attempts this turn (skip for now)
	if(inputEvents[8] == 1){
		// [8] Field Testing
		if(applyEventCardModifiers.armorClass[8] == true){ // Infantry
			applyEventCardModifiers.entityHealth +=2;
			applyEventCardModifiers.standardDamage +=1;
		} 
	}
	// [9] First Battle Jitter - Two tokens on target unit have 0 standardAttack for this battle. Target unit must have five tokens on it (skip for now)
	// [10] Flaming_Arrows - Attach to an Archer unit. This unit now gets +2 standardAttack vs Buildings (ought to calculate now) 
	// [11] Fortune_Favors_The_Foolish - Affects standardAttack of attacker/defender entities (ought to calculate now)
	// [13] Fresh_Bow_String_(Briton) - After attacks are declared, switch target Archer with any defending unit (skip for now)
	if(inputEvents[13] == 1){
		// [13] Gatherin' A Rowdy Bunch
		applyEventCardModifiers.standardDamage -=1;
	}
	// [14] Gladitorial_Games - You and a target player must move one unit to No-Man's-Land. The units will fight until one is destroyed (no retreat).  Target player chooses unit first (skip for now).
	// [15] Good_Wind - +1 bombardment for all siege units (ought to calculate now)
	// [16] Hard to Starboard - Reduce damage dealt to target ship by 10 points per round of combat this turn (skip for now)
	// [17] Heavy Tree Cover - Negate range combat round in target battle involving one of your units (skip for now)
	// [18] High Ground - Target Archer gains range bonus for this battle. Age II-+1. Age III+2. Age IV+3 (ought to calculate now)
	// [19] Husbandry - Attach to a Cavalry Unit. That unit gains +2 HP (ought to calculate now)
	// [20] It's A Miracle - A successful Healing attempt saves us up three tokens, instead of one. Play this card before an attempt is made (skip for now)
	// [21] Listen To A Story - Attempt 1-3 conversions this battle. Pay per conversion (skip for now)
	// [22] Medieval Trappings - Attach to one of your buildings. Every turn an enemy non-siege, non-unique unit resides on attached building, they must lose one token (skip for now)
	// [23] Muddy Battlefield - Target infantry gets double standardAttack versus Cavalry this turn (ought to calculate now)
	// [24] Non-Compos Mentis - Roll a 1d6 when in combat. On a: 1: take 10 extra damage per round, 2: draw 2 cards, 3: no effect, 4: deal 10 extra damage per round, 5: discard 2 cards, 6: deal 15 extra damage per round. Play anytime. (skip for now)
	// [25] Opportunity Knocks - If you have two adjacent attacking units, they may target the same defending unit. There is no retreat allowed this battle. Or you may draw three cards (skip for now)
	// [26] Piety - If you have one monk attached to a unit, your conversion rate is 4. If the attempt fails, the monk dies (skip for now)
	// [27] Poor Morale - Play when a target unit loses at least 1 token in battle. That unit must retreat. Can be played after archer range round (skip for now)
	if(inputEvents[28] == 1){
		// [28] Rally The Workers
		if(applyEventCardModifiers.entityName == "Villager"){
			applyEventCardModifiers.standardDamage += 3;
		}
	}
	// [29] Relentless Attack - This battle, any damage remaining in a round after casualties have been taken carries over into the next round. Remaining damage at the end of this battle is lost (skip for now)
	// [30] Retreat - Target unit must retreat before the first round of combat. The ranged round does not count as the first round of combat (skip for now)
	// [31] Rough Waters - Target ship may not defend this turn (skip for now)
	// [32] Shots In The Back (Briton) - If a unit in combat with your Archer retreats, your Archer deals an additional round of range damage without taking any damage (skip for now)
	// [33] Soak The Timbers - All enemy Fire Ships get an automatic result of 1 for their die roll when calculating damage this turn (skip for now)
	// [34] Spirits of the Ancestors - Target imit may not attack or move this turn. For unit owner's next turn, the unit get +3 standardAttack (skip for now)
	// [35] Squires - Attach to an Infantry Unit. That unit gets +2 HP (ought to calculate now)
	// [36] Steady Hand - Target Archer unit may do ranged damage to a Cavalry unit this turn (skip for now)
	// [37] Stealth Attack - Do 20 damage to a building (skip for now)
	// [38] The Hammer's Cavalry (Franks) - Play when one of your Cavalry units is reduced to 1 token. Add two tokens to the unit at no cost (skip for now)
	// [39] The Jester Is Dead, Let's Get Em (Celt) = Sacrifice 1 of your villagers. +4 standardAttack to all defending units this turn (skip for now)
	// [40] Uji (Japanese) - Before any damage is dealt, switch any one of your units being attacked with another one of your units. Must be played in your village (skip for now)
	// [41] Urgent Need (Goth) - Play when your unoccupied Building is being attacked. This card is a full militia card defending the Building until the end of the battle (skip for now)
	// [42] Vengeance Is Mine! - Target unit gets +3 HP +3 AP this turn, when defending in your village. Play anytime.(ought to calculate now)
	// [43] While They're Sleeping - Target attacking Infantry unit takes no damage for the first round of combat. The ranged round does not count as the first round of combat (skip for now)
	// [44] You Will Die! (Saracen) - This battle goes for four rounds of normal combat, instead of 2 rounds. No retreat is allowed without event card effect. Play anytime.(skip for now)
	// [45] Zealous Monks - Target Monk unit gets 1 conversion roll at a 3 or less rate for each monk attached (skip for now)

	return applyEventCardModifiers;
}


// Function: Apply the effects of 1) attack bonuses, 2) technologies, 3) the relevant event cards, and 4) quantity for player 1's battle participant
Entity modifiersCalculator::applyAllModifiersP1(const int inputP1PlayerNumber, Entity inputP1BattleParticipant, int* inputP1Technologies, int* inputP1Events, Entity inputP2BattleParticipant){
	// Struct: The modified battle participant to return
	Entity p1BattleParticipantModified = inputP1BattleParticipant;

	//1) Attack bonus effects
	p1BattleParticipantModified = applyRockPaperScissorsEffects(inputP1BattleParticipant, inputP2BattleParticipant, inputP1PlayerNumber);

	//2) Technology effects
	p1BattleParticipantModified = applyTechnologyEffects(p1BattleParticipantModified, inputP1Technologies);

	//3) The relevant event card effects (where easy to implement)
	p1BattleParticipantModified = applyEventCardEffects(p1BattleParticipantModified, inputP1Events);

	//4) Quantity effects
	p1BattleParticipantModified.standardDamage *= p1BattleParticipantModified.entityQuantity;
	p1BattleParticipantModified.rangedDamage *= p1BattleParticipantModified.entityQuantity;
	p1BattleParticipantModified.pointValue *= p1BattleParticipantModified.entityQuantity;

	return p1BattleParticipantModified;
}

// Function: Apply the effects of 1) attack bonuses, 2) technologies, 3) the relevant event cards, and 4) quantity for player 2's battle participant
Entity modifiersCalculator::applyAllModifiersP2(const int inputP2PlayerNumber, Entity inputP2BattleParticipant, int* inputP2Technologies, int* inputP2Events, Entity inputP1BattleParticipant){
	// Struct: The modified battle participant to return
	Entity p2BattleParticipantModified = inputP2BattleParticipant;

	//1) Attack bonus effects
	p2BattleParticipantModified = applyRockPaperScissorsEffects(inputP1BattleParticipant, inputP2BattleParticipant, inputP2PlayerNumber);

	//2) Technology effects
	p2BattleParticipantModified = applyTechnologyEffects(p2BattleParticipantModified, inputP2Technologies);

	//3) The relevant event card effects (where easy to implement)
	p2BattleParticipantModified = applyEventCardEffects(p2BattleParticipantModified, inputP2Events);

	//4) Quantity effects
	p2BattleParticipantModified.standardDamage *= p2BattleParticipantModified.entityQuantity;
	p2BattleParticipantModified.rangedDamage *= p2BattleParticipantModified.entityQuantity;
	p2BattleParticipantModified.pointValue *= p2BattleParticipantModified.entityQuantity;

	return p2BattleParticipantModified;
}

// Function: The constructor/deconstructor
combatCalculator::combatCalculator(){
	healingEffectP1 = false;
	startingQuantityP1 = 0;
	healingEffectP2 = false;
	startingQuantityP2 = 0;
	dieRoll = 0;
	dieRollInput = "";
}
combatCalculator::~combatCalculator(){}

// Function: Set the battle participants
void combatCalculator::setCombatParticipants(Entity inputP1CombatParticipant, Entity inputP2CombatParticipant){
	combatParticipantP1 = inputP1CombatParticipant;
	combatParticipantP2 = inputP2CombatParticipant;
}

void combatCalculator::checkD6DieInput(std::string inputdieRollString){
	if(
		(inputdieRollString != "1") &&
		(inputdieRollString != "2") &&
		(inputdieRollString != "3") &&
		(inputdieRollString != "4") &&
		(inputdieRollString != "5") &&
		(inputdieRollString != "6")
	){
		std::cout << "Error: A d6 die only reads the numbers 1-6" << "\n";
		exit(EXIT_FAILURE);
	}
	else{
		// The input is fine}
	}
}

// Function: The constructor / deconstructor
round1::round1(){
	monkPowersActivated = false;
}
round1::~round1(){}

// Function: Calculate the outcome of a battle
Entity round1::roundOutcome(const int inputPlayerNumber, int inputRunTimes){
	// Make sure that the results are not calculated twice
	if(inputRunTimes == 0){
		// Bool: See if the monk powers are activated for player 1 and 2
		bool monkPowersActivatedP1 = false;
		bool monkPowersActivatedP2 = false;

		// Behaviour: See if player 1 has a monk
		if(combatParticipantP1.armorClass[9] == true){
			// Behaviour: Make sure that the quantity of monks is correct
			if( (combatParticipantP1.entityQuantity < 0) && (combatParticipantP1.entityQuantity > 5) ){
				std::cout << "Error: The first player's battle participant must have between 0-5 monks" << "\n";
				exit(EXIT_FAILURE);
			}

			// Behaviour: Ask the user if they are performing a conversion or healing attempt and store the answer
			std::string calculationModeP1 = "0";
			std::cout << "Is player 1's monk performing a conversion (enter 0) or healing attempt (enter 1)?" << "\n";
			std::cin >> calculationModeP1;

			// Behaviour: Validate the input before proceeding
			if( (calculationModeP1 != "0") && (calculationModeP1 != "1") ){
				std::cout << "Error: Player 1 entered non-zero and non-one for the monk" << "\n";
				exit(EXIT_FAILURE);
			}

			// Reference: Generating a random number between 0 and 6 is not random enough so I get dice input
			// Behaviour: Ask the user to roll a dice and enter the results of the dice roll
			std::cout << "Get player 1 to roll a d6 dice and enter the result" << "\n";
			std::cin >> dieRollInput;

			// Behaviour: Validate the input before proceeding
			checkD6DieInput(dieRollInput);

			// Conver the dice roll input string into an integer
			dieRoll = atoi(dieRollInput.c_str());

			// Behaviour: See if the monk powers are activated
			if(combatParticipantP1.entityQuantity >= dieRoll){
				monkPowersActivatedP1 = true;
			}
			
			// Behaviour: Act on the success odds
			if( (monkPowersActivatedP1 == true) && (calculationModeP1 == "0") ){
				// Behaviour: Act on the conversion attempt being successful
				std::cout << "The conversion attempt by player 1's monk was successful" << "\n";
				combatParticipantP2.entityQuantity --;
				monkPowersActivated = true;
			}
			else if ( (monkPowersActivatedP1 == true) && (calculationModeP1 == "1") ){
				// Behaviour: Act on the healing attempt being successful
				std::cout << "The healing attempt by player 1's monk was successful" << "\n";
				healingEffectP1 = true;
				combatParticipantP1.entityQuantity ++;
				startingQuantityP1 = combatParticipantP1.entityQuantity;
				monkPowersActivated = true;
			}
			else{
				// Behaviour: Return the fact that the attempt was unsuccessful
				std::cout << "Player 1's monk powers failed to activate" << "\n";
			}
		}

		// Behaviour: See if player 2 has a monk
		if(combatParticipantP2.armorClass[9] == true){
			// Behaviour: Make sure that the quantity of monks is correct
			if( (combatParticipantP2.entityQuantity < 0) && (combatParticipantP2.entityQuantity > 5) ){
				std::cout << "Error: The second player's battle participant must have between 0-5 monks" << "\n";
				exit(EXIT_FAILURE);
			}

			// Behaviour: Ask the user if they are performing a conversion or healing attempt and store the answer
			std::string calculationModeP2 = "0";
			std::cout << "Is player 2's monk performing a conversion (enter 0) or healing attempt (enter 1)?" << "\n";
			std::cin >> calculationModeP2;

			// Behaviour: Validate the input before proceeding
			if( (calculationModeP2 != "0") && (calculationModeP2 != "1") ){
				std::cout << "Error: Player 2 entered non-zero and non-one for the monk" << "\n";
				exit(EXIT_FAILURE);
			}

			// Reference: Generating a random number between 0 and 6 is not random enough so I get dice input
			// Behaviour: Ask the user to roll a dice and enter the results of the dice roll
			std::cout << "Get player 2 to roll a d6 dice and enter the result" << "\n";
			std::cin >> dieRollInput;

			// Behaviour: Validate the input before proceeding
			checkD6DieInput(dieRollInput);

			// Conver the dice roll input string into an integer
			dieRoll = atoi(dieRollInput.c_str());

			// Behaviour: See if the monk powers are activated
			if(combatParticipantP2.entityQuantity >= dieRoll){
				monkPowersActivatedP2 = true;
			}
			// Behaviour: Act on the success odds
			if( (monkPowersActivatedP2 == true) && (calculationModeP2 == "0") ){
				// Behaviour: Act on the conversion attempt being successful
				std::cout << "The conversion attempt by player 2's monk was successful" << "\n";
				combatParticipantP2.entityQuantity --;
				monkPowersActivated = true;
			}
			else if ( (monkPowersActivatedP2 == true) && (calculationModeP2 == "1") ){
				// Behaviour: Act on the healing attempt being successful
				std::cout << "The healing attempt by player 2's monk was successful" << "\n";
				healingEffectP2 = true;
				combatParticipantP2.entityQuantity ++;
				startingQuantityP2 = combatParticipantP2.entityQuantity;
				monkPowersActivated = true;
			}
			else{
				// Behaviour: Return the fact that the attempt was unsuccessful
				std::cout << "Player 2's monk powers failed to activate" << "\n";
			}
		}

		// Behaviour: Check if either monk did something (for output purposes)
		if ( (monkPowersActivatedP1 == true) || (monkPowersActivatedP2 == true) ){
			monkPowersActivated = true;
		}
	}

	// Behaviour: Return the entities with the combat results applied
	if(inputPlayerNumber == 1){
		return combatParticipantP1;
	}
	else if(inputPlayerNumber == 2){
		return combatParticipantP2;
	}
	else{}
}

// Functions: The constructor and deconstructor
round2::round2(){
	// Behaviour: Initialize the default values
	rangedAttackActivated = false;
}

round2::~round2(){

}

// Function: Calculate the outcome of a battle
Entity round2::roundOutcome(const int inputPlayerNumber, int inputRunTimes){
	// Make sure that the results are not calculated twice
	if(inputRunTimes == 0){
// Integer: Declare the number of units killed in this round
		int p1EntityDeaths = 0;
		int p2EntityDeaths = 0;

		// Behaviour: Check if player 1 or player 2 has an archer and if they do that they are not fighting cavalry
		if( (((combatParticipantP1.armorClass[0] == true) || (combatParticipantP1.armorClass[5] == true)) && (combatParticipantP2.armorClass[4] != true))
			|| (((combatParticipantP2.armorClass[0] == true) || (combatParticipantP2.armorClass[5] == true)) && (combatParticipantP1.armorClass[4] != true))
		){
			// Behaviour: Determine the amount of damage dealt (simultaneously dealt)
			// Behaviour: Calculate the number of units P2 killed
			p1EntityDeaths = std::floor( (combatParticipantP2.rangedDamage) / (combatParticipantP1.entityHealth) ); 

			// Behaviour: Calculate the number of units P1 killed
			p2EntityDeaths = std::floor( (combatParticipantP1.rangedDamage) / (combatParticipantP2.entityHealth) ); 

			// Behaviour: Track that ranged damage occured
			rangedAttackActivated = true;
		}

		// Behaviour: Update the quantity based on the results
		if(rangedAttackActivated == true){
			// Behaviour: Divide the standardDamage / pointValue by the current quantity to get the values by 1
			combatParticipantP1.standardDamage /= combatParticipantP1.entityQuantity;
			combatParticipantP2.standardDamage /= combatParticipantP2.entityQuantity;
			combatParticipantP1.rangedDamage /= combatParticipantP1.entityQuantity;
			combatParticipantP2.rangedDamage /= combatParticipantP2.entityQuantity;
			combatParticipantP1.pointValue /= combatParticipantP1.entityQuantity;
			combatParticipantP2.pointValue /= combatParticipantP2.entityQuantity;

			// Behaviour: Now decrease the quantity
			combatParticipantP1.entityQuantity -= p1EntityDeaths;
			combatParticipantP2.entityQuantity -= p2EntityDeaths;

			// Behaviour: Now multiply the standardDamage, rangedDamage, and pointValue by the new quantity
			combatParticipantP1.standardDamage *= combatParticipantP1.entityQuantity;
			combatParticipantP2.standardDamage *= combatParticipantP2.entityQuantity;
			combatParticipantP1.rangedDamage *= combatParticipantP1.entityQuantity;
			combatParticipantP2.rangedDamage *= combatParticipantP2.entityQuantity;
			combatParticipantP1.pointValue *= combatParticipantP1.entityQuantity;
			combatParticipantP2.pointValue *= combatParticipantP2.entityQuantity;
		}
	}
		
	// Behaviour: Return the entities with the combat results applied
	if(inputPlayerNumber == 1){
		return combatParticipantP1;
	}
	else if(inputPlayerNumber == 2){
		return combatParticipantP2;
	}
	else{}
}

// Function: Calculate the outcome of a battle
Entity round3::roundOutcome(const int inputPlayerNumber, int inputRunTimes){
	std::cout << "Round 3 calculations" << "\n";
}

// Function: Calculate the outcome of a battle
Entity round4::roundOutcome(const int inputPlayerNumber, int inputRunTimes){
	std::cout << "Round 4 calculations" << "\n";
}