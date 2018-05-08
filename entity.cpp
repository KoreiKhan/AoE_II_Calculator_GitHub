/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <iostream> // Using: cin and cout
#include <string> // Using: string
#include "entity.h" // Using: entity class

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