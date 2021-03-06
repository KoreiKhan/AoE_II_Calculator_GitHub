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
	Entity entitiesFile(std::string inputEntityFilename, int inputNumberOfWords, int inputPlayerNumber, int inputMonkReturnSetting);

	// Function: Get the rest of the information about an entity
	Entity conductASearch(std::string inputEntityName, int inputEntityQuantity);

	// Function: Get the active technologies from '[p1/p2]_technologies.csv', the active events from '[p1/p2]_events.csv', or player details from 'players.csv'
	int* aSplitColumnFile(std::string inputTechnologyOrEventsFilename, int inputNumberOfRows);
};
#endif // FILE_IMPORTER_H