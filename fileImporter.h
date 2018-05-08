/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <string> // Using: string
#include "entity.h" // Using: Entity class

/** The file importer class **/
#ifndef FILE_IMPORTER_H
#define FILE_IMPORTER_H
class fileImporter{
	public:
	// Referred to functions
	int checkIsInteger(std::string inputWord);

	// File loading functions
	Entity entitiesFile(int inputPlayerNumber);
};
#endif // FILE_IMPORTER_H

