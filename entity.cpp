/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string
#include "entity.h" // Using: entity class
#include <cstdlib> // Using: exit(EXIT_FAILURE)

// Declare the constructor
Entity::Entity(){
	// Set the initial values
	entityName = "";
	entityAge = 0;
	entityQuantity = 0; 
	entityHealth = 0; 
	standardDamage = 0; 
	rangedDamage = 0; 
	garrisonValue = 0; 
	pointValue = 0; 
	for(int i = 0; i < 20; i ++){
		armorClass[i] = false;
	}
}

// Declare the deconstructor
Entity::~Entity(){}

void Entity::outputEntity(){
	// Declare an integer
	std::string yesOrNo = "";

	// Convert entityAge to the Medieval Ages
	std::string medievalAge = "";
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
		std::cout << "Error: Age not recognized";
		exit(EXIT_FAILURE);
	}

	// Display the Entity values to the console
	std::cout << entityQuantity << " " << medievalAge << " " << entityName <<
	" with " <<  entityHealth << "HP"; 
	if(standardDamage!=0){
		std::cout << ", " << standardDamage << "SD";
	}
	if(rangedDamage!=0){
		std::cout << ", " << rangedDamage << "RD";
	}
	if(pointValue !=0){
		std::cout << ", " << pointValue << "PV";
	}
	if(garrisonValue !=0){
		std::cout << ", " << garrisonValue << "GV";
	}
	// Only display the relevant armor classes.
	// Convert the armor class numbers into what they are supposed to represented
	// The use of the boolean array meant that I had to write the code this way
	std::cout << " of type: ";
	if(armorClass[0] == true){std::cout << "Archer ";}
	if(armorClass[1] == true){std::cout << "Building ";}
	if(armorClass[2] == true){std::cout << "Camel ";}
	if(armorClass[3] == true){std::cout << "Castle ";}
	if(armorClass[4] == true){std::cout << "Cavalry ";}
	if(armorClass[5] == true){std::cout << "Cavalry_Archer ";}
	if(armorClass[6] == true){std::cout << "Eagle_Warrior ";}
	if(armorClass[7] == true){std::cout << "Gunpowder_Unit ";}
	if(armorClass[8] == true){std::cout << "Infantry ";}
	if(armorClass[9] == true){std::cout << "Monk ";}
	if(armorClass[10] == true){std::cout << "Ram ";}
	if(armorClass[11] == true){std::cout << "Ship ";}
	if(armorClass[12] == true){std::cout << "Siege_Weapon ";}
	if(armorClass[13] == true){std::cout << "Spearman ";}
	if(armorClass[14] == true){std::cout << "Standard_Building ";}
	if(armorClass[15] == true){std::cout << "Stone_Defence ";}
	if(armorClass[16] == true){std::cout << "Turtle_Ship ";}
	if(armorClass[17] == true){std::cout << "Unique_Unit ";}
	if(armorClass[18] == true){std::cout << "Wall_&_Gate ";}
	if(armorClass[19] == true){std::cout << "War_Elephant ";}
	std::cout << "\n";
}