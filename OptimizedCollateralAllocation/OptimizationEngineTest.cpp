#include"Borrower.h"
#include"Lender.h"
#include"OptimizationEngine.h"
#include<iostream>
#include"FileReader.h"


int main()
{
	FileReader fr;

	std::vector<std::string> tempVector;
	std::string filePath = "C:\\Users\\Ishan\\Documents\\Visual Studio 2015\\Projects\\OptimizedCollateralAllocation\\OptimizedCollateralAllocation\\stocks.json";
	tempVector = fr.readFile(filePath);

	Borrower* bor = new Borrower();
	bor->setUpBorrowerInventory(tempVector);
	bor->setBorrowedAmount(2000);

	std::cout << "===========================BORROWER INVENTORY======================================================" << std::endl << std::endl;
	bor->populateBorrowerInventory();
	Lender *lend = new Lender(10000, "C");

	OptimizationEngine oE;
	oE.optimizeNew(lend, bor);

	return 0;
}