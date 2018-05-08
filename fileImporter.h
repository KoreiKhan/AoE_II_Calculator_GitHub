/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <string> // Using: string
#include "entity.h" // Using: Entity class

/** The file importer class **/
#ifndef FILE_IMPORTER_H
#define FILE_IMPORTER_H
class fileImporter{
	public:
	// Constructor
	fileImporter();

	// Check if a string is an integer function
	int checkIsInteger(std::string inputWord);

	// Get the rest of the information about an entity
	Entity conductASearch(std::string inputEntityName, int inputEntityQuantity);

	// Get the entity name and quantity function
	Entity entitiesFile(int inputPlayerNumber);

	// Deconstructor
	~fileImporter();
};
#endif // FILE_IMPORTER_H

