/** The libaries **/ /** Apparently using namespace std; is bad  **/
#include <string> // Using: string
#include "entity.h" // Using: Entity class

/** The file importer class **/
#ifndef FILE_IMPORTER_H
#define FILE_IMPORTER_H
// Decalre a struct
struct returnEntities{
	std::string p1EntityName;
	std::string p2EntityName;
	int p1EntityQuantity;
	int p2EntityQuantity;
};

class fileImporter{
	public:
	// Referred to functions
	int checkIsInteger(std::string inputWord);

	// File loading functions
	returnEntities entitiesFile();
};
#endif // FILE_IMPORTER_H

