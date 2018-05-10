#include <iostream>
#include <string>
#include <cstdlib> // Using: exit(EXIT_FAILURE)
// #include "Entity.h"

void displayColorfulText(std::string inputFormatAttribute, std::string inputForegroundColor, std::string inputBackgroundColor, std::string inputText, bool isLineBreak){

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

int main(){
	// Declare variable
	std::string helloWorld = "helloWorld";

	// Entity test;
	// test.tryColour(".");

	// Get the colored version of the text
	displayColorfulText("bold", "cyan", "white", "Hello person", true);
}
 