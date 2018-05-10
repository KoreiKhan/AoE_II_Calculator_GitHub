/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string, to_string
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


// Declare the function for colorful text
void Entity::displayColorfulText(std::string inputFormatAttribute, std::string inputForegroundColor, std::string inputBackgroundColor, std::string inputText, bool isLineBreak){

	// Declare and initialize variables
	int formatAttributeCode = 0;
	int foregroundColorCode = 0;	
	int backgroundColorCode = 0;

	// Set the format attribute
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

	// Set the text color
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

	// Set the background color
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

	// Display the text
	if(isLineBreak == false){
		std::cout << "\033[" << formatAttributeCode << ";" << foregroundColorCode << ";" << backgroundColorCode << "m" << inputText << "\033[0m";
	}
	else{
		std::cout << "\033[" << formatAttributeCode << ";" << foregroundColorCode << ";" << backgroundColorCode << "m" << inputText << "\033[0m\n";
	}
	
}

// Declare the function for outputting an entity
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
	displayColorfulText("bold","yellow","magenta", std::to_string(entityQuantity), false);
	std::cout << " ";

	displayColorfulText("bold","red","white", medievalAge, false);
	std::cout << " ";

	displayColorfulText("bold","white","blue", entityName, false);

	std::cout << " with ";
	displayColorfulText("bold", "red", "default", std::to_string(entityHealth), false);
	std::cout << "HP"; 
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

	// Only display the relevant armor classes.
	// Convert the armor class numbers into what they are supposed to represented
	// The use of the boolean array meant that I had to write the code this way
	std::cout << " of type: ";
	if(armorClass[0] == true){displayColorfulText("bold", "blue", "default", "Archer ", false);}
	if(armorClass[1] == true){displayColorfulText("bold", "blue", "default", "Building ", false);}
	if(armorClass[2] == true){displayColorfulText("bold", "blue", "default", "Camel ", false);}
	if(armorClass[3] == true){displayColorfulText("bold", "blue", "default", "Castle ", false);}
	if(armorClass[4] == true){displayColorfulText("bold", "blue", "default", "Cavalry ", false);}
	if(armorClass[5] == true){displayColorfulText("bold", "blue", "default", "Cavalry_Archer ", false);}
	if(armorClass[6] == true){displayColorfulText("bold", "blue", "default", "Eagle_Warrior ", false);}
	if(armorClass[7] == true){displayColorfulText("bold", "blue", "default", "Gunpowder_Unit ", false);}
	if(armorClass[8] == true){displayColorfulText("bold", "blue", "default", "Infantry ", false);}
	if(armorClass[9] == true){displayColorfulText("bold", "blue", "default", "Monk ", false);}
	if(armorClass[10] == true){displayColorfulText("bold", "blue", "default", "Ram ", false);}
	if(armorClass[11] == true){displayColorfulText("bold", "blue", "default", "Ship ", false);}
	if(armorClass[12] == true){displayColorfulText("bold", "blue", "default", "Siege_Weapon ", false);}
	if(armorClass[13] == true){displayColorfulText("bold", "blue", "default", "Spearman ", false);}
	if(armorClass[14] == true){displayColorfulText("bold", "blue", "default", "Standard_Building ", false);}
	if(armorClass[15] == true){displayColorfulText("bold", "blue", "default", "Stone_Defence ", false);}
	if(armorClass[16] == true){displayColorfulText("bold", "blue", "default", "Turtle_Ship ", false);}
	if(armorClass[17] == true){displayColorfulText("bold", "blue", "default", "Unique_Unit ", false);}
	if(armorClass[18] == true){displayColorfulText("bold", "blue", "default", "Wall_&_Gate ", false);}
	if(armorClass[19] == true){displayColorfulText("bold", "blue", "default", "War_Elephant ", false);}
	std::cout << "\n";
}