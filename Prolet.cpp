#include <iostream>

int get_int();
double calculate_per_capita_gdp_estimate(int quarters_from_epoch);
std::string format_money(double money);
std::string quarter_to_ordinal(int quarter);

/*
 * Use the user input to gather information on the year and quarter
 * in question, then output the result projected GDP
 */

int main() 
{
	int projectionYear{};
	int projectionQuarter{};

	int epochQuarters{1977*4};

	std::cout << "Please enter the year for the calculation: ";
	projectionYear = get_int();

	std::cout << "Please enter the quarter for the calculation: ";
	projectionQuarter = get_int();

	int totalQuarters{ (projectionYear * 4) + (projectionQuarter - 1) };
	int quartersBetweenProjection{totalQuarters-epochQuarters};
	double gdpEstimate{calculate_per_capita_gdp_estimate(quartersBetweenProjection)};

	std::cout << "In the " << quarter_to_ordinal(projectionQuarter) << " quarter of " << projectionYear
		<< ", the projected contribution to GDP per working-age person is $" << format_money(gdpEstimate) << ".\n";

	return 0;
}