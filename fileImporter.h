/** The libaries **/ 
#include <string> // Using: string
#include <fstream> // Using: ifstream, is_open(), good, close()
#include "entity.h" // Using: entity class

/** The file importer class **/
#ifndef FILE_IMPORTER_H
#define FILE_IMPORTER_H
class fileImporter{
	public:
	// Object: A single common file object to store the input file
	std::ifstream inputFile;

	// Functions: The constructor and deconstructor 
	fileImporter();
	~fileImporter();

	// Function: Check if a string is an integer
	int checkIsInteger(std::string inputWord);

	// Function: Get the entity name and quantity from 'entities.csv'
	Entity entitiesFile(int inputPlayerNumber);

	// Function: Get the rest of the information about an entity
	Entity conductASearch(std::string inputEntityName, int inputEntityQuantity);

	// Function: Get the active technologies from 'p1_technologies.csv' or 'p2_technologies.csv'
	int* technologyFile(std::string inputTechnologyFilename);
};
#endif // FILE_IMPORTER_H