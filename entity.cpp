/** The libaries **/ 
#include <iostream> // Using: cin and cout
#include <string> // Using: string, to_string
#include "entity.h" // Using: entity class
#include <cstdlib> // Using: exit(EXIT_FAILURE)

// Entity functions: The constructor and deconstructor
Entity::Entity(){
	// Behaviour: Set the initial and often derived values
	entityName = "";
	entityAge = 0;
	entityQuantity = 0; 
	entityHealth = 0; 
	standardDamage = 0; 
	rangedDamage = 0; 
	garrisonValue = 0; 
	pointValue = 0; 
	for(int i = 0; i < 43; i ++){
		armorClass[i] = false;
	}
	entitiesArmorClasses = 0;
	onlyAttacksInTheSecondRoundOfStandardCombat = false;
	dealsAreaEffectDamage = false;
	onlyAttacksOnce = false;
	isKamikaze = false;
}

Entity::~Entity(){}

// Inherited entity functions: The constructor and deconstructor
Archer::Archer(){
	entityName = "Archer";
	entityAge = 2;
	entityHealth = 6;
	standardDamage = 4;
	rangedDamage = 5;
	pointValue = 2; // 1 wood, 1 gold
	armorClass[0] = true; // The archer armor class
}

Archer::~Archer(){}

Archer_Saracen::Archer_Saracen(){
	entityName += "_(Saracen)";
	// 5 standardDamage vs Buildings (implemented)
}

Archer_Saracen::~Archer_Saracen(){}

Arbalest::Arbalest(){
	entityName = "Arbalest";
	entityAge = 4;
	entityHealth = 8;
	standardDamage = 6;
	rangedDamage = 7;
}

Arbalest::~Arbalest(){}

Arbalest_Briton::Arbalest_Briton(){
	entityName += "_(Briton)";
	standardDamage = 7; 
	rangedDamage = 8;
}

Arbalest_Briton::~Arbalest_Briton(){}

Arbalest_Saracen::Arbalest_Saracen(){
	entityName += "_(Saracen)"; 
	// 8 standardDamage versus buildings (implemented)
}

Arbalest_Saracen::~Arbalest_Saracen(){}

Archery_Range::Archery_Range(){
	entityName = "Archery_Range";
	entityAge = 2;
	entityHealth = 120;
	garrisonValue = 10;
	pointValue = 11; // 6 wood, 5 villagers
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Archery_Range::~Archery_Range(){}

Barracks::Barracks(){
	entityName = "Barracks";
	entityAge = 1;
	entityHealth = 120; 
	garrisonValue = 10; 
	pointValue = 11; // 6 wood, 5 villagers
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Barracks::~Barracks(){}

Berserk_Viking::Berserk_Viking(){
	entityName = "Berserk_(Viking)";
	entityAge = 3;
	entityHealth = 12; 
	standardDamage = 9; 
	pointValue = 2; // 1 food, 1 gold
	armorClass[8] = true; // Infantry armor class
	armorClass[17] = true; // Unique unit armor class
}

Berserk_Viking::~Berserk_Viking(){}

Battering_Ram::Battering_Ram(){
	entityName = "Battering_Ram";
	entityAge = 3;
	entityHealth = 41; 
	pointValue = 11; // 7 wood, 4 gold
	armorClass[10] = true; // Ram armor class
	armorClass[12] = true; // Siege weapon armor class
	armorClass[27] = true; // Battering ram armor class
	// 60 standard damage vs Building (implemented)
	// There is a rule that Archers and Villagers cannot attack Rams.
	// There is a rule that this unit can only attack buildings
}

Battering_Ram::~Battering_Ram(){}

Battering_Ram_Celt::Battering_Ram_Celt(){
	entityName += "_(Celt)";
	pointValue = 10; // 6 wood, 4 gold
	// 70 standard damage vs Building (implemented)
}

Battering_Ram_Celt::~Battering_Ram_Celt(){}

Blacksmith::Blacksmith(){
	entityName = "Blacksmith";
	entityAge = 2;
	entityHealth = 180; 
	pointValue = 10; // 6 wood, 4 gold
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Blacksmith::~Blacksmith(){}

Camel::Camel(){
	entityName = "Camel";
	entityAge = 3;
	entityHealth = 26;
	standardDamage = 5;
	pointValue = 4;
	armorClass[30] = true; // Camel armor class
	// 20 standardAttack bonus against cavalry (I)
}

Camel::~Camel(){}

Capped_Ram::Capped_Ram(){
	entityName = "Capped_Ram";
	entityAge = 4;
	entityHealth = 46; 
	armorClass[28] = true; // Capped ram armor class
	// 110 standard damage vs Building (implemented)
	// There is a rule that Archers and Villagers cannot attack Rams. 
	// There is a rule that this is unit can only attack buildings
}

Capped_Ram::~Capped_Ram(){}

Capped_Ram_Celt::Capped_Ram_Celt(){
	entityName += "_Celt";
	// 120 standard damage vs Building (implemented)
}

Capped_Ram_Celt::~Capped_Ram_Celt(){}

Castle::Castle(){
	entityName = "Castle";
	entityAge = 3;
	entityHealth = 440; 
	garrisonValue = 10; 
	pointValue = 30;  // 15 stone, 15 bodies
	armorClass[1] = true; // Building armor class
	armorClass[3] = true; // Castle armor class
	armorClass[14] = true; // Standard building armor class
}

Castle::~Castle(){}

Castle_Frank::Castle_Frank(){
	entityName += "_(Frank)";
	pointValue = 25;  // 10 stone, 15 bodies
}

Castle_Frank::~Castle_Frank(){}

Cavalier::Cavalier(){
	entityName = "Cavalier";
	entityAge = 4;
	entityHealth = 30; 
	standardDamage = 12; 
}

Cavalier::~Cavalier(){}

Cavalier_Frank::Cavalier_Frank(){
	entityName += "_(Frank)";
	entityHealth = 36; 
}

Cavalier_Frank::~Cavalier_Frank(){}

Cavalier_Persian::Cavalier_Persian(){
	entityName += "_(Persian)";
	// +2 standardDamage vs Archers (implemented)
}

Cavalier_Persian::~Cavalier_Persian(){}

Cavalry_Archer::Cavalry_Archer(){
	entityName = "Cavalry_Archer";
	entityAge = 3;
	entityHealth = 12; 
	standardDamage = 6; 
	rangedDamage = 7; 
	pointValue = 3;  // 1 wood, 2 gold
	armorClass[0] = true; // Archer armor class
	armorClass[4] = true; // Cavalry armor class
	armorClass[5] = true; // Cavalry archer armor class
}

Cavalry_Archer::~Cavalry_Archer(){}

Cavalry_Archer_Saracen::Cavalry_Archer_Saracen(){
	entityName += "_(Saracen)";
	// 9 standardDamage vs. Building (implemented)
}

Cavalry_Archer_Saracen::~Cavalry_Archer_Saracen(){}

Cavalry_Archer_Mongol::Cavalry_Archer_Mongol(){
	entityName += "_(Mongol)";
	rangedDamage = 9; 
}

Cavalry_Archer_Mongol::~Cavalry_Archer_Mongol(){}

Champion::Champion(){
	entityName = "Champion";
	entityAge = 4;
	entityHealth = 20; 
	standardDamage = 13; 
}

Champion::~Champion(){}

Champion_Celt::Champion_Celt(){
	entityName += "_(Celt)";
}

Champion_Celt::~Champion_Celt(){}

Champion_Viking::Champion_Viking(){
	entityName += "_(Viking)";
	entityHealth = 24;
}

Champion_Viking::~Champion_Viking(){}

Champion_Goth::Champion_Goth(){
	entityName += "_(Goth)";
	// +2 vs buildings (implemented)
}

Champion_Goth::~Champion_Goth(){}

Champion_Japanese::Champion_Japanese(){
	entityName += "_(Japanese)";
	standardDamage = 17; 
	// +2 vs buildings (implemented)
}

Champion_Japanese::~Champion_Japanese(){}

Crossbowman::Crossbowman(){
	entityName = "Crossbowman";
	entityAge = 3;
	entityHealth = 8; 
	standardDamage = 5; 
	rangedDamage = 6; 
}

Crossbowman::~Crossbowman(){}

Crossbowman_Saracen::Crossbowman_Saracen(){
	entityName += "_(Saracen)";
	// 6 standardDamage vs building (implemented)
}

Crossbowman_Saracen::~Crossbowman_Saracen(){}

Demolition_Ship::Demolition_Ship(){
	entityName = "Demolition_Ship";
	entityAge = 3;
	entityHealth = 13; 
	standardDamage = 110; 
	pointValue = 6;  // 3 wood, 3 gold
	armorClass[11] = true; // Ship armor class
	armorClass[21] = true; // Demolition ship armor class
	onlyAttacksInTheSecondRoundOfStandardCombat = true;
	isKamikaze = true;
	// Only attacks in the second round of combat
	// Units cannot retreat against the Demolition Ship
	// Destroyed if it attacks
}

Demolition_Ship::~Demolition_Ship(){}

Demolition_Ship_Viking::Demolition_Ship_Viking(){
	entityName += "_(Viking)";
	pointValue = 3;  // 1 wood, 2 gold
}

Demolition_Ship_Viking::~Demolition_Ship_Viking(){}

Dock::Dock(){
	entityName = "Dock";
	entityAge = 1;
	entityHealth = 150; 
	garrisonValue = 5; 
	pointValue = 8;  // 5 wood, 3 bodies
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Dock::~Dock(){}

Dock_Persian::Dock_Persian(){
	entityName += "_(Persian)";
	entityHealth = 300; 
}

Dock_Persian::~Dock_Persian(){}

Dock_Viking::Dock_Viking(){
	entityName += "_(Viking)";
	pointValue = 6;  // 3 wood, 3 bodies
}

Dock_Viking::~Dock_Viking(){}

Elite_Berserk_Viking::Elite_Berserk_Viking(){
	entityName = "Elite_Berserk_(Viking)";
	entityAge = 4; 
	entityHealth = 18; 
	standardDamage = 14; 
	// 17 StandardDamage vs Building
}

Elite_Berserk_Viking::~Elite_Berserk_Viking(){}


Elite_Huskarl_Goth::Elite_Huskarl_Goth(){
	entityName = "Elite_Huskarl_(Goth)";
	entityAge = 4; 
	entityHealth = 20; 
	standardDamage = 12; 
	// 15 standardDamage vs building (implemented)
	// 16 standardDamage vs Archer
}

Elite_Huskarl_Goth::~Elite_Huskarl_Goth(){}

Elite_Longboat_Viking::Elite_Longboat_Viking(){
	entityName = "Elite_Longboat_(Viking)";
	entityAge = 4;
	entityHealth = 36; 
	standardDamage = 16; 
	// 50 standardDamage versus Demolition Ship, Galley, Longboat, Building, & Land Unit (implemented)
	// Bombardment 2 
}

Elite_Longboat_Viking::~Elite_Longboat_Viking(){}

Elite_Longbowman_Briton::Elite_Longbowman_Briton(){
	entityName = "Elite_Longbowman_(Briton)";
	entityAge = 4;
	entityHealth = 8; 
	standardDamage = 12; 
	rangedDamage = 10; 
}

Elite_Longbowman_Briton::~Elite_Longbowman_Briton(){}

Elite_Mangudai_Mongol::Elite_Mangudai_Mongol(){
	entityName = "Elite_Mangudai_(Mongol)";
	entityAge = 4;
	entityHealth = 16; 
	standardDamage = 10; 
	rangedDamage = 9; 
	// 16 standardDamage versus Siege (implemented)
}

Elite_Mangudai_Mongol::~Elite_Mangudai_Mongol(){}

Elite_Mameluke_Saracen::Elite_Mameluke_Saracen(){
	entityName = "Elite_Mameluke_(Saracen)";
	entityAge = 4;
	entityHealth = 22; 
	standardDamage = 8; 
	rangedDamage = 5; 
	// 20 standardDamage versus Cavalry (implemented)
}

Elite_Mameluke_Saracen::~Elite_Mameluke_Saracen(){}

Elite_Samurai_Japanese::Elite_Samurai_Japanese(){
	entityName = "Elite_Samurai_(Japanese)";
	entityAge = 4;
	entityHealth = 20; 
	standardDamage = 12;
	// 15 standardDamage versus Building (implemented)
	// 18 standardDamage versus Unique units (implemented)
}

Elite_Samurai_Japanese::~Elite_Samurai_Japanese(){}

Elite_Skirmisher::Elite_Skirmisher(){
	entityName = "Elite_Skirmisher";
	entityAge = 3;
	entityHealth = 8; 
	standardDamage = 3; 
	rangedDamage = 5;
	armorClass[33] = true; // Elite_Skirmisher armor class 
	// 16 standardDamage against Archers (implemented)
}

Elite_Skirmisher::~Elite_Skirmisher(){}

Elite_Throwing_Axeman_Frank::Elite_Throwing_Axeman_Frank(){
	entityName = "Elite_Throwing_Axeman_(Frank)";
	entityAge = 4;
	entityHealth = 16; 
	standardDamage = 8; 
	rangedDamage = 5;
	// 12 standardDamage versus Building (implemented)
}

Elite_Throwing_Axeman_Frank::~Elite_Throwing_Axeman_Frank(){}

Elite_War_Elephant_Persian::Elite_War_Elephant_Persian(){
	entityName = "Elite_War_Elephant_(Persian)";
	entityAge = 4;
	entityHealth = 126; 
	standardDamage = 25; 
	// Limited to 1 token per card
	// 60 standardDamage against Buildings (implemented)
}

Elite_War_Elephant_Persian::~Elite_War_Elephant_Persian(){}

Elite_Woad_Raider_Celt::Elite_Woad_Raider_Celt(){
	entityName = "Elite_Woad_Raider_(Celt)";
	entityAge = 4;
	entityHealth = 22; 
	standardDamage = 13; 
	// 17 standardDamage vs Building (implemented)
}

Elite_Woad_Raider_Celt::~Elite_Woad_Raider_Celt(){}

Farm::Farm(){
	entityName = "Farm";
	entityAge = 1;
	entityHealth = 40; 
	pointValue = 4;  // 2 wood, 2 bodies
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Farm::~Farm(){}

Fast_Fire_Ship::Fast_Fire_Ship(){
	entityName = "Fast_Fire_Ship";
	entityAge = 4;
	entityHealth = 30; 
	standardDamage = 6;
	armorClass[34] = true; // Fast Fire Ship armor class
	// Roll a 1d6. Multiply the result by standardDamage to determine damage per round
	// 12 AP vs. Galley, Longboat, Building, Land Units & Fire Ship (implemented)
	// Bombardment 2
}

Fast_Fire_Ship::~Fast_Fire_Ship(){}

Fire_Ship::Fire_Ship(){
	entityName = "Fire_Ship";
	entityAge = 3;
	entityHealth = 26;
	standardDamage = 4;
	pointValue = 6;  // 3 wood, 3 gold
	armorClass[11] = true; // Ship armor class
	armorClass[23] = true; // Fire_Ship armor class
	// Roll a 1d6. Multiply the result by standardDamage to determine damage per round
	// 10 AP vs. Galley, Longboat, Building, Land Units & Fire Ship (implemented)
}

Fire_Ship::~Fire_Ship(){}

Fishing_Ship::Fishing_Ship(){
	entityName = "Fishing_Ship";
	entityAge = 1;
	pointValue = 2;  // 2 wood
	armorClass[11] = true; // Ship armor class
}

Fishing_Ship::~Fishing_Ship(){}

Fishing_Ship_Japanese::Fishing_Ship_Japanese(){
	entityName += "_(Japanese)";
	entityHealth = 30; 
}

Fishing_Ship_Japanese::~Fishing_Ship_Japanese(){}

Fishing_Ship_Persian::Fishing_Ship_Persian(){
	entityName += "_(Persian)";
	entityHealth = 16; 
}

Fishing_Ship_Persian::~Fishing_Ship_Persian(){}

Fortified_Wall::Fortified_Wall(){
	entityName = "Fortified_Wall";
	entityAge = 3;
	entityHealth = 280; 
}

Fortified_Wall::~Fortified_Wall(){}

Galleon::Galleon(){
	entityName = "Galleon";
	entityAge = 4;
	entityHealth = 40;
	standardDamage = 18;
	armorClass[36] = true; // Galleon armor class
	// 50 standardDamage versus Longboat, Land Unit, Buildings, and Galley (implemented)
	// Bombardment 2
}

Galleon::~Galleon(){}

Galleon_Saracen::Galleon_Saracen(){
	entityName += "_(Saracen)";
	entityAge = 4;
	standardDamage = 23;
	// 60 standardDamage versus Longboat, Land Unit, Buildings, and Galley (implemented)
	// Bombardment 2
}

Galleon_Saracen::~Galleon_Saracen(){}

Galleon_Japanese::Galleon_Japanese(){
	entityName += "_(Japanese)";
	entityAge = 4;
	// Bombardment 3
}

Galleon_Japanese::~Galleon_Japanese(){}

Galleon_Viking::Galleon_Viking(){
	entityName += "_(Viking)";
	entityAge = 4;
}

Galleon_Viking::~Galleon_Viking(){}

Galley::Galley(){
	entityName = "Galley";
	entityAge = 2;
	entityHealth = 30;
	standardDamage = 14;
	pointValue = 6;  // 4 wood, 2 gold
	armorClass[11] = true; // Ship armor class
	armorClass[22] = true; // Galley armor class
	onlyAttacksOnce = true;
	// 30 standardAttack vs Longboat, land unit, building, and galley (implemented)
	// Bombardment 0 (only eligible to attack in the 1st round of combat)
}

Galley::~Galley(){}

Galley_Japanese::Galley_Japanese(){
	entityName += "_(Japanese)";
	// Bombardment 1 (only eligible to attack in the 1st round of combat)
}

Galley_Japanese::~Galley_Japanese(){}

Galley_Saracen::Galley_Saracen(){
	entityName += "_(Saracen)";
	standardDamage = 17; 
	// 35 standardAttack vs Longboat, land unit, building, and galley (implemented)
}

Galley_Saracen::~Galley_Saracen(){}

Galley_Viking::Galley_Viking(){
	entityName += "_(Viking)";
	pointValue = 3;  // 2 wood, 1 gold
}

Galley_Viking::~Galley_Viking(){}

Stone_Gate::Stone_Gate(){
	entityName = "Stone_Gate";
	entityAge = 2;
	entityHealth = 380; 
	pointValue = 6;  // 3 stone, 3 bodies
}

Stone_Gate::~Stone_Gate(){}

Throwing_Axeman_Frank::Throwing_Axeman_Frank(){
	entityName = "Throwing_Axeman_(Frank)";
	entityAge = 3;
	standardDamage = 7;
	rangedDamage = 4;
	entityHealth = 14;
	pointValue = 2; // 1 fold, 1 gold
	// 9 standardDamage vs Building (I)
}

Throwing_Axeman_Frank::~Throwing_Axeman_Frank(){}

Trade_Cog::Trade_Cog(){
	entityName = "Trade_Cog";
	entityAge = 2;
	entityHealth = 14;
	pointValue = 5; // 3 wood, 2 gold
}
Trade_Cog::~Trade_Cog(){}

Gold_Mine::Gold_Mine(){
	entityName = "Gold_Mine";
	entityAge = 1;
	entityHealth = 80; 
		pointValue = 6;  // 3 wood, 3 bodies
		armorClass[1] = true; // Building armor class
		armorClass[14] = true; // Standard building armor class
	}

Gold_Mine::~Gold_Mine(){}

Gold_Mine_Japanese::Gold_Mine_Japanese(){
	entityName += "_(Japanese)";
	pointValue = 4;  // 1 wood, 3 bodies
}

Gold_Mine_Japanese::~Gold_Mine_Japanese(){}

// Inherited entity functions: The constructor and deconstructor
Hero::Hero(){
	entityName = "Hero";
	entityAge = 1;
	entityHealth = 12;
	standardDamage = 6;
	pointValue = 3; // 3 gold
	armorClass[42] = true; // The hero armor class
}

Hero::~Hero(){}

Heavy_Camel::Heavy_Camel(){
	entityName = "Heavy_Camel";
	entityAge = 4;
	entityHealth = 30; 
	standardDamage = 7; 
	armorClass[31] = true; // Heavy Camel armor class
	// 30 standardDamage against Cavalry (I)
}

Heavy_Camel::~Heavy_Camel(){}

Heavy_Cavalry_Archer::Heavy_Cavalry_Archer(){
	entityName = "Heavy_Cavalry_Archer";
	entityAge = 4;
	entityHealth = 16; 
	standardDamage = 7; 
	rangedDamage = 8; 
}

Heavy_Cavalry_Archer::~Heavy_Cavalry_Archer(){}

Heavy_Cavalry_Archer_Mongol::Heavy_Cavalry_Archer_Mongol(){
	entityName += "_(Mongol)";
	rangedDamage = 10; 
}

Heavy_Cavalry_Archer_Mongol::~Heavy_Cavalry_Archer_Mongol(){}

Heavy_Cavalry_Archer_Saracen::Heavy_Cavalry_Archer_Saracen(){
	entityName += "_(Saracen)";
	// 10 standardDamage versus Building (I)
}

Heavy_Cavalry_Archer_Saracen::~Heavy_Cavalry_Archer_Saracen(){}

Heavy_Demolition_Ship::Heavy_Demolition_Ship(){
	entityName = "Heavy_Demolition_Ship";
	entityAge = 4;
	entityHealth = 16; 
	standardDamage = 140; 
	// Only attacks in the second round of combat
	// Units cannot retreat against the Demolition Ship
}

Heavy_Demolition_Ship::~Heavy_Demolition_Ship(){}

Heavy_Demolition_Ship_Viking::Heavy_Demolition_Ship_Viking(){
	entityName += "_(Viking)";
}

Heavy_Demolition_Ship_Viking::~Heavy_Demolition_Ship_Viking(){}

Heavy_Scorpion::Heavy_Scorpion(){
	entityName = "Heavy_Scorpion";
	entityAge = 4;
	entityHealth = 12; 
	standardDamage = 16; 
	// Bombardment 1
	// Only attacks in the first round of combat
	// Area effect attack
}

Heavy_Scorpion::~Heavy_Scorpion(){}

Heavy_Scorpion_Celt::Heavy_Scorpion_Celt(){
	entityName += "_(Celt)";
	standardDamage = 19; 
}

Heavy_Scorpion_Celt::~Heavy_Scorpion_Celt(){}

House::House(){
	entityName = "House";
	entityAge = 1;
	entityHealth = 80; 
	pointValue = 2;  // 1 wood, 1 body
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

House::~House(){}

Huskarl_Goth::Huskarl_Goth(){
	entityName = "Huskarl_(Goth)";
	entityAge = 3;
	entityHealth = 16; 
	standardDamage = 10;  
	pointValue = 2;  // 1 food, 1 gold
	armorClass[8] = true; // Infantry armor class
	armorClass[17] = true; // Unique unit armor class
	// 12 standardDamage vs Archers (I)
	// 12 standardDamage vs Buildings (I)
}

Huskarl_Goth::~Huskarl_Goth(){}

Knight::Knight(){
	entityName = "Knight";
	entityAge = 3;
	entityHealth = 26; 
	standardDamage = 10; 
	pointValue = 5;  // 2 food, 3 gold
	armorClass[4] = true; // Cavalry armor class
}

Knight::~Knight(){}

Knight_Frank::Knight_Frank(){
	entityName += "_(Frank)";
	entityHealth = 32; 
}

Knight_Frank::~Knight_Frank(){}

Knight_Persian::Knight_Persian(){
	entityName += "_(Persian)";
	pointValue = 5;  // 3 food, 2 gold
	// +2 standardDamage vs Archers (I)
}

Knight_Persian::~Knight_Persian(){}

Light_Cavalry::Light_Cavalry(){
	entityName = "Light_Cavalry";
	entityAge = 3;
	entityHealth = 16; 
	standardDamage = 7; 
}

Light_Cavalry::~Light_Cavalry(){}

Light_Cavalry_Mongol::Light_Cavalry_Mongol(){
	entityName += "_(Mongol)";
	entityHealth = 20; 
}

Light_Cavalry_Mongol::~Light_Cavalry_Mongol(){}

Longboat_Viking::Longboat_Viking(){
	entityName = "Longboat_(Viking)";
	entityAge = 3;
	entityHealth = 33; 
	standardDamage = 14; 
	pointValue = 6;  // 3 wood, 3 gold
	armorClass[11] = true; // Ship armor class
	armorClass[17] = true; // Unique unit armor class
	onlyAttacksOnce = true;
	// 40 standardAttack vs Demolition Ship, Galley, Longboat, Building, and Land units
	// Bombardment 1 (only attacks in the first round of combat)
}

Longboat_Viking::~Longboat_Viking(){}

Longbowman_Briton::Longbowman_Briton(){
	entityName = "Longbowman_(Briton)";
	entityAge = 3;
	entityHealth = 8; 
	standardDamage = 10; 
	rangedDamage = 8; 
	pointValue = 2;  // 1 wood, 1 gold
	armorClass[0] = true; // Archer armor class
	armorClass[17] = true; // Unique unit armor class
}

Longbowman_Briton::~Longbowman_Briton(){}

Long_Swordsman::Long_Swordsman(){
	entityName = "Long_Swordsman";
	entityAge = 3;
	entityHealth = 12; 
	standardDamage = 9; 
}

Long_Swordsman::~Long_Swordsman(){}

Long_Swordsman_Celt::Long_Swordsman_Celt(){
	entityName += "_(Celt)";
}

Long_Swordsman_Celt::~Long_Swordsman_Celt(){}

Long_Swordsman_Goth::Long_Swordsman_Goth(){
	entityName += "_(Goth)";
	// +2 standardAttack vs Building (I)
}

Long_Swordsman_Goth::~Long_Swordsman_Goth(){}

Long_Swordsman_Japanese::Long_Swordsman_Japanese(){
	entityName += "_(Japanese)";
	entityHealth = 14; 
	standardDamage = 11; 
}

Long_Swordsman_Japanese::~Long_Swordsman_Japanese(){}

Long_Swordsman_Viking::Long_Swordsman_Viking(){
	entityName += "_(Viking)";
	entityHealth = 16; 
}

Long_Swordsman_Viking::~Long_Swordsman_Viking(){}

Lumber_Camp::Lumber_Camp(){
	entityName = "Lumber_Camp";
	entityAge = 1;
	entityHealth = 80; 
	pointValue = 6;  // 3 wood, 3 bodies
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Lumber_Camp::~Lumber_Camp(){}

Lumber_Camp_Japanese::Lumber_Camp_Japanese(){
	entityName += "_(Japanese)";
	pointValue = 5;  // 2 wood, 3 bodies
}

Lumber_Camp_Japanese::~Lumber_Camp_Japanese(){}

Mameluke_Saracen::Mameluke_Saracen(){
	entityName = "Mameluke_(Saracen)";
	entityAge = 3;
	entityHealth = 18; 
	standardDamage = 7; 
	rangedDamage = 4; 
	pointValue = 5;  // 2 food, 3 gold
	armorClass[0] = true; // Archer armor class
	armorClass[4] = true; // Cavalry armor class
	armorClass[2] = true; // Camel armor class
	armorClass[17] = true; // Unique unit armor class
	// 16 standardAttack vs Cavalry (I)
}

Mameluke_Saracen::~Mameluke_Saracen(){}

Man_At_Arms::Man_At_Arms(){
	entityName = "Man_At_Arms";
	entityAge = 2;
	entityHealth = 10; 
	standardDamage = 6; 
}

Man_At_Arms::~Man_At_Arms(){}

Man_At_Arms_Celt::Man_At_Arms_Celt(){
	entityName += "_(Celt)";
}

Man_At_Arms_Celt::~Man_At_Arms_Celt(){}

Man_At_Arms_Goth::Man_At_Arms_Goth(){
	entityName += "_(Goth)";
	// +2 standardDamage vs buildings (I)
}

Man_At_Arms_Goth::~Man_At_Arms_Goth(){}

Man_At_Arms_Japanese::Man_At_Arms_Japanese(){
	entityName += "_(Japanese)";
	standardDamage = 7; 
}

Man_At_Arms_Japanese::~Man_At_Arms_Japanese(){}

Man_At_Arms_Viking::Man_At_Arms_Viking(){
	entityName += "_(Viking)";
	entityHealth = 11; 
}

Man_At_Arms_Viking::~Man_At_Arms_Viking(){}

Mangonel::Mangonel(){
	entityName = "Mangonel";
	entityAge = 3;
	entityHealth = 12; 
	standardDamage = 40; 
	pointValue = 12;  // 7 wood, 5 gold
	armorClass[12] = true; // Siege weapon armor class
	armorClass[37] = true; // Mangonel armor class
	onlyAttacksOnce = true;
	// 80 standardDamage vs Building (I)
	// Bombardment 1 (only attacks in first round of normal combat)
}

Mangonel::~Mangonel(){}

Mangonel_Celt::Mangonel_Celt(){
	entityName += "_(Celt)";
	pointValue = 11;  // 6 wood, 5 gold
	// 90 standardDamage vs Building (I)
}

Mangonel_Celt::~Mangonel_Celt(){}

Mangudai_Mongol::Mangudai_Mongol(){
	entityName = "Mangudai_(Mongol)";
	entityAge = 3;
	entityHealth = 16; 
	standardDamage = 8; 
	rangedDamage = 7; 
	pointValue = 5;  // 3 wood, 2 gold
	armorClass[0] = true; // Archer armor class
	armorClass[5] = true; // Cavalry Archer armor class
	armorClass[4] = true; // Cavalry armor class
	armorClass[17] = true; // Unique unit armor class
	// 14 standardAttack vs Siege (I)
}

Mangudai_Mongol::~Mangudai_Mongol(){}

Market::Market(){
	entityName = "Market";
	entityAge = 2;
	entityHealth = 180; 
	pointValue = 12;  // 6 wood, 6 bodies
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Market::~Market(){}

Market_Saracen::Market_Saracen(){
	entityName += "_(Saracen)";
}

Market_Saracen::~Market_Saracen(){}

Militia::Militia(){
	entityName = "Militia";
	entityAge = 1;
	entityHealth = 8; 
	standardDamage = 4; 
	pointValue = 2;  // 1 food, 1 gold
	armorClass[8] = true; // Infantry armor class
}

Militia::~Militia(){}

Militia_Celt::Militia_Celt(){
	entityName += "_(Celt)";
}

Militia_Celt::~Militia_Celt(){}

Militia_Goth::Militia_Goth(){
	entityName += "_(Goth)";
	// +2 standardDamage vs Building (I)
}

Militia_Goth::~Militia_Goth(){}

Mill::Mill(){
	entityName = "Mill";
	entityAge = 1;
	entityHealth = 80; 
	pointValue = 6;  // 3 wood, 3 bodies
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Mill::~Mill(){}

Mill_Japanese::Mill_Japanese(){
	entityName += "_(Japanese)";
	pointValue = 5;  // 2 wood, 3 bodies
}

Mill_Japanese::~Mill_Japanese(){}

Monastery::Monastery(){
	entityName = "Monastery";
	entityAge = 1;
	entityHealth = 180; 
	garrisonValue = 10; 
	pointValue = 10;  // 7 wood, 3 bodies
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Monastery::~Monastery(){}

Monk::Monk(){
	entityName = "Monk";
	entityAge = 3;
	entityHealth = 3;  
	pointValue = 3;  // 3 food
	armorClass[9] = true; // Monk armor class
}

Monk::~Monk(){}

Onager::Onager(){
	entityName = "Onager";
	entityAge = 4;
	entityHealth = 16; 
	standardDamage = 50; 
	armorClass[38] = true; // Onager armor class
	// 120 standardAttack vs Building (I)
	// Bombardment 2 (only attacks in the first round)
}

Onager::~Onager(){}

Onager_Celt::Onager_Celt(){
	entityName += "_(Celt)";
	// 130 standardAttack vs Building (I)
	// Bombardment 2 (only attacks in the first round)
}

Onager_Celt::~Onager_Celt(){}

Outpost::Outpost(){
	entityName = "Outpost";
	entityAge = 1;
	entityHealth = 40; 
	pointValue = 3;  // 1 wood, 1 stone, 1 body
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Outpost::~Outpost(){}

Paladin::Paladin(){
	entityName = "Paladin";
	entityAge = 4;
	entityHealth = 38; 
	standardDamage = 14; 
	pointValue = 5;  // 2 food, 3 gold, 1 book (ignored)
}

Paladin::~Paladin(){}

Paladin_Persian::Paladin_Persian(){
	entityName += "_(Persian)";
	// standardAttack +2 vs Archers (I)
}

Paladin_Persian::~Paladin_Persian(){}

Paladin_Frank::Paladin_Frank(){
	entityName += "_(Frank)";
	entityHealth = 44;
}

Paladin_Frank::~Paladin_Frank(){}

Palisade_Wall::Palisade_Wall(){
	entityName = "Palisade_Wall";
	entityAge = 1;
	entityHealth = 20; 
	pointValue = 2;  // 1 wood, 1 body
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
	armorClass[18] = true; // Wall & Gate armor class
}

Palisade_Wall::~Palisade_Wall(){}

Pikeman::Pikeman(){
	entityName = "Pikeman";
	entityAge = 3;
	entityHealth = 14; 
	standardDamage = 4; 
	armorClass[41] = true; // Pikeman armor class
	// 40 standardDamage versus Cavalry (I)
}

Pikeman::~Pikeman(){}

Pikeman_Celt::Pikeman_Celt(){
	entityName += "_(Celt)";
}

Pikeman_Celt::~Pikeman_Celt(){}

Pikeman_Goth::Pikeman_Goth(){
	entityName += "_(Goth)";
	// +2 standardDamage versus Building (I)
}

Pikeman_Goth::~Pikeman_Goth(){}

Pikeman_Japanese::Pikeman_Japanese(){
	entityName += "_(Japanese)";
	standardDamage = 5; 
}

Pikeman_Japanese::~Pikeman_Japanese(){}

Pikeman_Viking::Pikeman_Viking(){
	entityName += "_(Viking)";
	entityHealth = 16; 
}

Pikeman_Viking::~Pikeman_Viking(){}

Samurai_Japanese::Samurai_Japanese(){
	entityName = "Samurai_(Japanese)";
	entityAge = 4;
	entityHealth = 16; 
	standardDamage = 8; 
	pointValue = 2;  // 1 gold, 1 food
	armorClass[8] = true; // Infantry armor class
	armorClass[19] = true; // Unique unit armor class
	// 10 standardDamage versus buildings (I)
	// 12 standardDamage versus Unique units (I)
}

Samurai_Japanese::~Samurai_Japanese(){}

Scorpion::Scorpion(){
	entityName = "Scorpion";
	entityAge = 3;
	entityHealth = 8; 
	standardDamage = 12; 
	pointValue = 8;  // 4 wood, 4 gold 
	armorClass[12] = true; // Siege weapon armor class
	onlyAttacksOnce = true;
	dealsAreaEffectDamage = true;
	// Area Effect
	// Bombardment 1 (only attacks in the first round)
}

Scorpion::~Scorpion(){}

Scorpion_Celt::Scorpion_Celt(){
	entityName += "_(Celt)";
	standardDamage = 14; 
	pointValue = 7;  // 3 wood, 4 gold 
}

Scorpion_Celt::~Scorpion_Celt(){}

Scout_Cavalry::Scout_Cavalry(){
	entityName = "Scout_Cavalry";
	entityAge = 2;
	entityHealth = 10; 
	standardDamage = 5; 
	pointValue = 3;  // 3 food
	armorClass[4] = true; // Cavalry armor class
}

Scout_Cavalry::~Scout_Cavalry(){}

Siege_Onager::Siege_Onager(){
	entityName = "Siege_Onager";
	entityAge = 4;
	entityHealth = 20; 
	standardDamage = 75; 
	armorClass[39] = true; // Siege Onager armor class
	// 180 standardAttack vs Building (I)
	// Bombardment 2 (only attacks in the first round)
}

Siege_Onager::~Siege_Onager(){}

Siege_Onager_Celt::Siege_Onager_Celt(){
	entityName += "_(Celt)";
	// 190 standardAttack vs Building (I)
}

Siege_Onager_Celt::~Siege_Onager_Celt(){}

Siege_Ram::Siege_Ram(){
	entityName = "Siege_Ram";
	entityAge = 4;
	entityHealth = 60; 
	armorClass[29] = true; // Siege_Ram armor class
	// 220 standardAttack vs Building (I)
	// Only attacks buildings
}

Siege_Ram::~Siege_Ram(){}

Siege_Ram_Celt::Siege_Ram_Celt(){
	entityName += "_(Celt)"; 
	// 230 standardAttack vs Building (I)
}

Siege_Ram_Celt::~Siege_Ram_Celt(){}

Siege_Workshop::Siege_Workshop(){
	entityName = "Siege_Workshop";
	entityAge = 3;
	entityHealth = 180; 
	garrisonValue = 3; 
	pointValue = 11;  // 7 wood, 4 bodies
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Siege_Workshop::~Siege_Workshop(){}

Skirmisher::Skirmisher(){
	entityName = "Skirmisher";
	entityAge = 2;
	entityHealth = 6; 
	standardDamage = 2; 
	rangedDamage = 3; 
	pointValue = 2;  // 1 food, 1 wood
	armorClass[0] = true; // Archer armor class
	armorClass[32] = true; // Skirmisher armor class
	// 12 standardDamage vs Archers (I)
	// 13 rangedDamage vs Archers (I)
}

Skirmisher::~Skirmisher(){}

Spearman::Spearman(){
	entityName = "Spearman";
	entityAge = 2;
	entityHealth = 10; 
	standardDamage = 3; 
	pointValue = 2;  // 1 food, 1 wood
	armorClass[8] = true; // Infantry armor class
	armorClass[13] = true; // Spearman armor class
	armorClass[40] = true; // Spearman armor class
	// 25 standardDamage vs Cavalry (I)
}

Spearman::~Spearman(){}

Spearman_Celt::Spearman_Celt(){
	entityName += "_(Celt)";
}

Spearman_Celt::~Spearman_Celt(){}

Spearman_Goth::Spearman_Goth(){
	entityName += "_(Goth)";
	// +2 standardDamage vs Buildings (I)
}

Spearman_Goth::~Spearman_Goth(){}

Spearman_Japanese::Spearman_Japanese(){
	entityName += "_(Japanese)";
	standardDamage = 4; 
	// 26 standardDamage vs Cavalry (I)
}

Spearman_Japanese::~Spearman_Japanese(){}

Spearman_Viking::Spearman_Viking(){
	entityName += "_(Viking)";
	entityHealth = 11; 
}

Spearman_Viking::~Spearman_Viking(){}

Stable::Stable(){
	entityName = "Stable";
	entityAge = 2;
	entityHealth = 120; 
	garrisonValue = 10; 
	pointValue = 11;  // 6 wood, 5 body
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Stable::~Stable(){}

Stone_Mine::Stone_Mine(){
	entityName = "Stone_Mine";
	entityAge = 1;
	entityHealth = 80; 
	pointValue = 6;  // 3 wood, 3 bodies
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
}

Stone_Mine::~Stone_Mine(){}

Stone_Mine_Japanese::Stone_Mine_Japanese(){
	entityName += "_(Japanese)";
	pointValue = 4;  // 1 wood, 3 bodies
}

Stone_Mine_Japanese::~Stone_Mine_Japanese(){}

Stone_Wall::Stone_Wall(){
	entityName = "Stone_Wall";
	entityAge = 2;
	entityHealth = 150; 
	pointValue = 2;  // 1 stone, 1 body
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
	armorClass[15] = true; // Stone defence armor class
	armorClass[18] = true; // Wall & Gate armor class
}

Stone_Wall::~Stone_Wall(){}

Town_Center::Town_Center(){
	entityName = "Town_Center";
	entityAge = 3;
	entityHealth = 220; 
	pointValue = 17;  // 9 wood, 8 bodies
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
	armorClass[25] = true; // Town Center armor class
}

Town_Center::~Town_Center(){}

Town_Center_Briton::Town_Center_Briton(){
	entityName += "_(Briton)";
	pointValue = 12;  // 4 wood, 8 bodies
}

Town_Center_Briton::~Town_Center_Briton(){}

Town_Center_Persian::Town_Center_Persian(){
	entityName += "_(Persian)";
	entityHealth = 440; 
}

Town_Center_Persian::~Town_Center_Persian(){}

Trebuchet::Trebuchet(){
	packed = 0;
	entityName = "Trebuchet";
	entityAge = 4;
	entityHealth = 36; 
	standardDamage = 200; 
	pointValue = 17;  // 7 wood, 5 gold, 5 bodies
	armorClass[12] = true; // Siege weapon armor class
	armorClass[42] = true; // Trebuchet armor class
	onlyAttacksOnce = true;
	// 450 standardAttack vs Buildings (I)
	// Bombardment 3 (only attacks in first round)
}

Trebuchet::~Trebuchet(){}

Two_Handed_Swordsman::Two_Handed_Swordsman(){
	entityName = "Two-handed_Swordsman";
	entityAge = 4;
	entityHealth = 16; 
	standardDamage = 11; 
	armorClass[8] = true; // Infantry armor class
}

Two_Handed_Swordsman::~Two_Handed_Swordsman(){}

Two_Handed_Swordsman_Celt::Two_Handed_Swordsman_Celt(){
	entityName += "_(Celt)";
}

Two_Handed_Swordsman_Celt::~Two_Handed_Swordsman_Celt(){}

Two_Handed_Swordsman_Goth::Two_Handed_Swordsman_Goth(){
	entityName += "_(Goth)";
	// +2 standardAttack vs Building (I)
}

Two_Handed_Swordsman_Goth::~Two_Handed_Swordsman_Goth(){}

Two_Handed_Swordsman_Japanese::Two_Handed_Swordsman_Japanese(){
	entityName = "Two-handed_Swordsman_(Japanese)";
	standardDamage = 14; 
}

Two_Handed_Swordsman_Japanese::~Two_Handed_Swordsman_Japanese(){}

Two_Handed_Swordsman_Viking::Two_Handed_Swordsman_Viking(){
	entityName += "_(Viking)";
	entityHealth = 19; 
}

Two_Handed_Swordsman_Viking::~Two_Handed_Swordsman_Viking(){}

Villager::Villager(){
	entityName = "Villager";
	entityAge = 1;
	entityHealth = 4; 
	standardDamage = 3; 
	pointValue = 1;  // 1 food
	armorClass[26] = true; // Villager armor class
	// No armor class
}

Villager::~Villager(){}

War_Elephant_Persian::War_Elephant_Persian(){
	entityName = "War_Elephant_(Persian)";
	entityAge = 3;
	entityHealth = 94; 
	standardDamage = 15; 
	pointValue = 15;  // 15 food, 5 gold
	armorClass[4] = true; // Cavalry armor class
	armorClass[17] = true; // War Elephant armor class
	armorClass[19] = true; // Unique Unit armor class
	// Limit of 1 token
}

War_Elephant_Persian::~War_Elephant_Persian(){}

War_Galley::War_Galley(){
	entityName = "War_Galley";
	entityAge = 3;
	entityHealth = 34; 
	standardDamage = 16; 
	armorClass[35] = true; // War Galley armor class
	// Bombardment 1 (only attacks in the first round of normal combat)
	// 40 standardDamage versus Longboat, Land unit, Building, and Galley (I)
}

War_Galley::~War_Galley(){}

War_Galley_Japanese::War_Galley_Japanese(){
	entityName += "_(Japanese)";
	// Bombardment 2 (only attacks in the first round of normal combat)
}

War_Galley_Japanese::~War_Galley_Japanese(){}

War_Galley_Saracen::War_Galley_Saracen(){
	entityName += "_(Saracen)";
	standardDamage = 20; 
	// 50 standardDamage versus Longboat, Land unit, Building, and Galley (I)
}

War_Galley_Saracen::~War_Galley_Saracen(){}

War_Galley_Viking::War_Galley_Viking(){
	entityName += "_(Viking)";
}

War_Galley_Viking::~War_Galley_Viking(){}

Watch_Tower::Watch_Tower(){
	entityName = "Watch_Tower";
	entityAge = 2;
	entityHealth = 100; 
	standardDamage = 15; 
	pointValue = 9;  // 5 stone, 5 bodies
	armorClass[1] = true; // Building armor class
	armorClass[14] = true; // Standard building armor class
	armorClass[15] = true; // Stone defence armor class
	armorClass[24] = true; // Watch tower armor class
	onlyAttacksOnce = true;
	// Bombardment 1 (only attacks in the first round of normal combat)
}

Watch_Tower::~Watch_Tower(){}

Woad_Raider_Celt::Woad_Raider_Celt(){
	entityName = "Woad_Raider_(Celt)";
	entityAge = 3;
	entityHealth = 18; 
	standardDamage = 8; 
	pointValue = 2;  // 1 food, 1 gold
	armorClass[8] = true; // Infantry armor class
	armorClass[17] = true; // Unique unit armor class
	// 12 standardDamage vs Buildings (I)
}

Woad_Raider_Celt::~Woad_Raider_Celt(){}

Wonder::Wonder(){
	turnsInPlay = 0;
	entityName = "Wonder";
	entityAge = 4;
	pointValue = 90;  // 20 wood, 20 stone, 20 gold, 30 bodies.
	armorClass[1] = true; // Building armor class
}

Wonder::~Wonder(){}

// Function: Update Wonder HP
void Wonder::updateWonderHP(){
	// Behaviour: The rules state that you win if the wonder is in play for 6 turns
	turnsInPlay = 0;
	std::cout << "How many turns have the Wonder been in play for?" << "\n";
	std::cin >> turnsInPlay;

	if ( (turnsInPlay < 1) || (turnsInPlay > 6) ){
		std::cout << "Error: Wonder ought to be in play for 1-6 turns only" << "\n";
		exit(EXIT_FAILURE);
	}
	// Behaviour: Update wonder HP based on the number of turns in play
	else if(turnsInPlay == 1){
		entityHealth = 110; 
	}
	else if (turnsInPlay == 2){
		entityHealth = 220;
	}
	else if(turnsInPlay == 3){
		entityHealth = 330;
	}
	else{
		entityHealth = 440;
	}
}

// Function: Update Trebuchet Armor Class
void Trebuchet::updateTrebuchetArmorClass(){
	// Behaviour: Ram armor class if packed
	packed = false;
	std::cout << "Enter 1 if the Trebuchet is packed. Enter 0 if unpacked" << "\n";
	std::cin >> packed;

	if(packed == 1){
		armorClass[10] = true; // Ram armor class
	}
	else{
		armorClass[10] = false;
	}
}

// Function: Calculate the number of armor classes unique to an entity
int Entity::returnNumberOfArmorClasses(){
	entitiesArmorClasses = 0;

	// Behaviour: Increment entitiesArmorClasses for each present armorClass
	for(int i = 0; i < 44; i ++){
		if (armorClass[i] == true){
			entitiesArmorClasses++;
		} 
	}

	// Behaviour: Return the number of armor classes
	return entitiesArmorClasses;
}

// Function: Make text colorful
void Entity::displayColorfulText(std::string inputFormatAttribute, std::string inputForegroundColor, std::string inputBackgroundColor, std::string inputText, bool isLineBreak){
	// Variables: Store the color codes
	int formatAttributeCode = 0;
	int foregroundColorCode = 0;	
	int backgroundColorCode = 0;

	// Behaviour: Convert the input text into a color code for the attribute
	if(inputFormatAttribute == "default" || inputFormatAttribute == ""){
		formatAttributeCode = 0;
	}
	else if(inputFormatAttribute == "bold"){
		formatAttributeCode = 1;
	}
	else if(inputFormatAttribute == "dim"){
		formatAttributeCode = 2;
	}
	else if(inputFormatAttribute == "underlined"){
		formatAttributeCode = 3;
	}
	else if(inputFormatAttribute == "blink"){
		formatAttributeCode = 5;
	}
	else if(inputFormatAttribute == "reverse"){
		formatAttributeCode = 7;
	}
	else if(inputFormatAttribute == "hidden"){
		formatAttributeCode = 8;
	}
	else{
		std::cout << "Error: formatAttributeCode not found" << "\n";
		exit(EXIT_FAILURE);
	}

	// Behaviour: Convert the input text into a color code for the foreground color (text color)
	if(inputForegroundColor == "black"){
		foregroundColorCode = 30;
	}
	else if(inputForegroundColor == "red"){
		foregroundColorCode = 31;
	}
	else if(inputForegroundColor == "green"){
		foregroundColorCode = 32;
	}
	else if(inputForegroundColor == "yellow"){
		foregroundColorCode = 33;
	}
	else if(inputForegroundColor == "blue"){
		foregroundColorCode = 34;
	}
	else if(inputForegroundColor == "magenta"){
		foregroundColorCode = 35;
	}
	else if(inputForegroundColor == "cyan"){
		foregroundColorCode = 36;
	}
	else if(inputForegroundColor == "light_gray"){
		foregroundColorCode = 37;
	}
	else if(inputForegroundColor == "default" || inputForegroundColor == ""){
		foregroundColorCode = 39;
	}
	else if(inputForegroundColor == "dark_gray"){
		foregroundColorCode = 90;
	}
	else if(inputForegroundColor == "light_red"){
		foregroundColorCode = 91;
	}
	else if(inputForegroundColor == "light_green"){
		foregroundColorCode = 92;
	}
	else if(inputForegroundColor == "light_yellow"){
		foregroundColorCode = 93;
	}
	else if(inputForegroundColor == "light_blue"){
		foregroundColorCode = 94;
	}
	else if(inputForegroundColor == "light_magenta"){
		foregroundColorCode = 95;
	}
	else if(inputForegroundColor == "light_cyan"){
		foregroundColorCode = 96;
	}
	else if(inputForegroundColor == "white"){
		foregroundColorCode = 97;
	}
	else{
		std::cout << "Error: foregroundColorCode not found" << "\n";
		exit(EXIT_FAILURE);
	}

	// Behaviour: Convert the input text into a color code for the background color
	if(inputBackgroundColor == "black"){
		backgroundColorCode = 40;
	}
	else if(inputBackgroundColor == "red"){
		backgroundColorCode = 41;
	}
	else if(inputBackgroundColor == "green"){
		backgroundColorCode = 42;
	}
	else if(inputBackgroundColor == "yellow"){
		backgroundColorCode = 43;
	}
	else if(inputBackgroundColor == "blue"){
		backgroundColorCode = 44;
	}
	else if(inputBackgroundColor == "magenta"){
		backgroundColorCode = 45;
	}
	else if(inputBackgroundColor == "cyan"){
		backgroundColorCode = 46;
	}
	else if(inputBackgroundColor == "light_gray"){
		backgroundColorCode = 47;
	}
	else if(inputBackgroundColor == "default" || inputBackgroundColor == ""){
		backgroundColorCode = 49;
	}
	else if(inputBackgroundColor == "dark_gray"){
		backgroundColorCode = 100;
	}
	else if(inputBackgroundColor == "light_red"){
		backgroundColorCode = 101;
	}
	else if(inputBackgroundColor == "light_green"){
		backgroundColorCode = 102;
	}
	else if(inputBackgroundColor == "light_yellow"){
		backgroundColorCode = 103;
	}
	else if(inputBackgroundColor == "light_blue"){
		backgroundColorCode = 104;
	}
	else if(inputBackgroundColor == "light_magenta"){
		backgroundColorCode = 105;
	}
	else if(inputBackgroundColor == "light_cyan"){
		backgroundColorCode = 106;
	}
	else if(inputBackgroundColor == "white"){
		backgroundColorCode = 107;
	}
	else{
		std::cout << "Error: backgroundColorCode not found" << "\n";
		exit(EXIT_FAILURE);
	}

	// Behaviour: Display the text to the terminal
	if(isLineBreak == false){
		// Behaviour: Do not add a line break
		std::cout << "\033[" << formatAttributeCode << ";" << foregroundColorCode << ";" << backgroundColorCode << "m" << inputText << "\033[0m";
	}
	else{
		// Behaviour: Add a line break
		std::cout << "\033[" << formatAttributeCode << ";" << foregroundColorCode << ";" << backgroundColorCode << "m" << inputText << "\033[0m\n";
	}
	
}

// Function: Return entity information
void Entity::outputEntity(const int inputPlayerNumber){
	// Behaviour: Display the player's name first (no matter what)
	std::string playerName = std::to_string(inputPlayerNumber);
	displayColorfulText("bold", "white", "default", "player " + playerName + "'s", false);
	std::cout << " ";

	// Behaviour: Check that the entity is not dead before proceeding
	if(entityQuantity >=1){
		// Variable: Store the pre-requisite Age in text format
		std::string medievalAge = "";

		// Behaviour: Convert the integer entityAge to text format
		switch(entityAge){
			case 1:
			medievalAge = "Dark_Age";
			break;
			case 2:
			medievalAge = "Feudal_Age";
			break;
			case 3:
			medievalAge = "Castle_Age";
			break;
			case 4:
			medievalAge = "Imperial_Age";
			break;
			default:
			std::cout << "Error: Age not recognized for " << entityName << "\n";
			exit(EXIT_FAILURE);
		}

		// Behaviour: Return standard information about the entity to the console
		displayColorfulText("bold","white","magenta", std::to_string(entityQuantity), false);
		std::cout << " ";
		displayColorfulText("bold","white","dark_gray", medievalAge, false);
		std::cout << " ";
		displayColorfulText("bold","white","light_blue", entityName, false);
		std::cout << " has a total of ";
		displayColorfulText("bold", "red", "default", std::to_string(entityHealth), false);
		std::cout << "HP"; 

		// Behaviour: Return further information about the entities values if the value is present
		if(standardDamage!=0){
			std::cout << ", ";
			displayColorfulText("bold", "yellow", "default", std::to_string(standardDamage), false);
			std::cout << "SD";
		}
		if(rangedDamage!=0){
			std::cout << ", ";
			displayColorfulText("bold", "magenta", "default", std::to_string(rangedDamage), false);
			std::cout << "RD";
		}
		if(pointValue !=0){
			std::cout << ", ";
			displayColorfulText("bold", "cyan", "default", std::to_string(pointValue), false);
			std::cout << "PV"; 
		}
		if(garrisonValue !=0){
			std::cout << ", ";
			displayColorfulText("bold", "green", "default", std::to_string(garrisonValue), false);
			std::cout << "GV";
		}

		// Behaviour: Return further information about the entities armor classes if the armor class is present
		std::cout << " of type: ";

		// Array: Store whether or not an armor class has been displayed
		bool displayedArmorClass[20] = {false};

		// Behaviour: Only display each armor class once and add a space after each armor class except for the last class
		// Reference: Only the armor classes recognized by the AoE II wikipedia are displayed (the first 20)
		for(int i = 0; i != entitiesArmorClasses; i ++){
			if( (armorClass[0] == true) && (displayedArmorClass[0] == false) ) {
				displayColorfulText("bold","white","blue", "Archer", false);
				displayedArmorClass[0] = true;
			}
			else if( (armorClass[1] == true) && (displayedArmorClass[1] == false) ) {
				displayColorfulText("bold","white","blue", "Building", false);
				displayedArmorClass[1] = true;
			}
			else if( (armorClass[2] == true) && (displayedArmorClass[2] == false) ) {
				displayColorfulText("bold","white","blue", "Camel", false);
				displayedArmorClass[2] = true;
			}
			else if( (armorClass[3] == true) && (displayedArmorClass[3] == false) ) {
				displayColorfulText("bold","white","blue", "Castle", false);
				displayedArmorClass[3] = true;
			}
			else if( (armorClass[4] == true) && (displayedArmorClass[4] == false) ) {
				displayColorfulText("bold","white","blue", "Cavalry", false);
				displayedArmorClass[4] = true;
			}
			else if( (armorClass[5] == true) && (displayedArmorClass[5] == false) ) {
				displayColorfulText("bold","white","blue", "Cavalry_Archer", false);
				displayedArmorClass[5] = true;
			}
			else if( (armorClass[6] == true) && (displayedArmorClass[6] == false) ) {
				displayColorfulText("bold","white","blue", "Eagle_Warrior", false);
				displayedArmorClass[6] = true;
			}
			else if( (armorClass[7] == true) && (displayedArmorClass[7] == false) ) {
				displayColorfulText("bold","white","blue", "Gunpowder_Unit", false);
				displayedArmorClass[7] = true;
			}
			else if( (armorClass[8] == true) && (displayedArmorClass[8] == false) ) {
				displayColorfulText("bold","white","blue", "Infantry", false);
				displayedArmorClass[8] = true;
			}
			else if( (armorClass[9] == true) && (displayedArmorClass[9] == false) ) {
				displayColorfulText("bold","white","blue", "Monk", false);
				displayedArmorClass[9] = true;
			}
			else if( (armorClass[10] == true) && (displayedArmorClass[10] == false) ) {
				displayColorfulText("bold","white","blue", "Ram", false);
				displayedArmorClass[10] = true;
			}
			else if( (armorClass[11] == true) && (displayedArmorClass[11] == false) ) {
				displayColorfulText("bold","white","blue", "Ship", false);
				displayedArmorClass[11] = true;
			}
			else if( (armorClass[12] == true) && (displayedArmorClass[12] == false) ) {
				displayColorfulText("bold","white","blue", "Siege_Weapon", false);
				displayedArmorClass[12] = true;
			}
			else if( (armorClass[13] == true) && (displayedArmorClass[13] == false) ) {
				displayColorfulText("bold","white","blue", "Spearman", false);
				displayedArmorClass[13] = true;
			}
			else if( (armorClass[14] == true) && (displayedArmorClass[14] == false) ) {
				displayColorfulText("bold","white","blue", "Standard_Building", false);
				displayedArmorClass[14] = true;
			}
			else if( (armorClass[15] == true) && (displayedArmorClass[15] == false) ) {
				displayColorfulText("bold","white","blue", "Stone_Defence", false);
				displayedArmorClass[15] = true;
			}
			else if( (armorClass[16] == true) && (displayedArmorClass[16] == false) ) {
				displayColorfulText("bold","white","blue", "Turtle_Ship", false);
				displayedArmorClass[16] = true;
			}
			else if( (armorClass[17] == true) && (displayedArmorClass[17] == false) ) {
				displayColorfulText("bold","white","blue", "Unique_Unit", false);
				displayedArmorClass[17] = true;
			}
			else if( (armorClass[18] == true) && (displayedArmorClass[18] == false) ) {
				displayColorfulText("bold","white","blue", "Wall_&_Gate", false);
				displayedArmorClass[18] = true;
			}
			else if( (armorClass[19] == true) && (displayedArmorClass[19] == false) ) {
				displayColorfulText("bold","white","blue", "War_Elephant", false);
				displayedArmorClass[19] = true;
			}

			if(i != entitiesArmorClasses - 1){
				std::cout << " ";
			}
		}
	}
	// Behaviour: Display something different if the entity is dead
	else if(entityQuantity <=0){
		displayColorfulText("bold","white","light_blue", entityName, false);
		std::cout << " is dead";
	}

	std::cout << "\n";
}