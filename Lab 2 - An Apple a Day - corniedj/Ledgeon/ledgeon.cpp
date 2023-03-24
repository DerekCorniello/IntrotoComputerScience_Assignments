#include <iostream>
#include <iomanip>

/*
 * This program will calculate the percent difference in
 * patients seen and charity charges for each year 
 * as inputted by the user
 * 
 * Electronic Signature: DC
 */

int main()
{
	int firstYear{};
	int secondYear{};
	int firstYearPatients{}; 
	int secondYearPatients{};
	const double chargePerPatient{ 1071.87 }; //Constant per patient cost.

	//Prompt user for inputs

	std::cout << "Enter the first year: ";
	std::cin >> firstYear;

	std::cout << "Enter the number of patients we saw that year: ";
	std::cin >> firstYearPatients;

	std::cout << "Enter the second year: ";
	std::cin >> secondYear;

	std::cout << "Enter the number of patients we saw that year: ";
	std::cin >> secondYearPatients;

	//All inputs have been taken, do some ouputs and some math

	std::cout << "In year " << firstYear << ", our hospital issued "
			  << (firstYearPatients * chargePerPatient) << " dollars of charity charges." << std::endl;

	std::cout << "In year " << secondYear << ", our hospital issued "
		<< (secondYearPatients * chargePerPatient) << " dollars of charity charges." << std::endl;
	
	//initialize the percentage change variable using the formula, and output it to console.

	double percentCharityIncrease{((static_cast<double>(secondYearPatients) - static_cast<double>(firstYearPatients)) / static_cast<double>(firstYearPatients)*100)};

	std::cout << "Between " << firstYear << " and " << secondYear << ", there was a "
		      << std::setprecision(6) << percentCharityIncrease << "% increase in patients seen at our hospital." << std::endl;
}