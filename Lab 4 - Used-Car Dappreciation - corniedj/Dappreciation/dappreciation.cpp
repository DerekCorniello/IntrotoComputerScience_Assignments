#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
  int model_year{0};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
  int accidents{0};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
  double msrp{0.0};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */

bool car_has_premium_options() {
  //declare the string variable to see the user output with a null value
  std::string has_options_string{""};

  //prompt the user to see if they have premium options in the car
  std::cout << "Does your car have premium options (yes/no)? ";

  //place the value inputted into the variable
  std::cin >> has_options_string;

  //check to see if the string is "yes", if it is, return true, else, return false.
  if (has_options_string == "yes") {
    return true;
  } else {
    return false;
  }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(2)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}

// Constant Values Declaration

const double TIER_ONE_AGE_PERCENT{.85};
const double TIER_TWO_AGE_PERCENT{.63};
const double TIER_THREE_AGE_PERCENT{.45};
const double CURRENT_YEAR{ 2022 };
const double TIER_ZERO_WRECK_PERCENT{0};
const double TIER_ONE_WRECK_PERCENT{.02};
const double TIER_TWO_WRECK_PERCENT{.1};
const double TIER_THREE_WRECK_PERCENT{.2};
const double PREMIUM_PERCENT{ .5 };

int main() 
{
    double carAge = CURRENT_YEAR - static_cast<double>(car_model_year());
    double numAccidents = car_accidents();

    bool premOptions = car_has_premium_options();
    double carMSRP = car_msrp();

    if (carAge >= 11) 
    {
        print_ineligible_message();
    }

    else 
    {
        double carAgePercent{};
        if (carAge <= 4)
        {
            carAgePercent = TIER_ONE_AGE_PERCENT;
        }
        else if (carAge <= 8)
        {
            carAgePercent = TIER_TWO_AGE_PERCENT;
        }
        else 
        {
            carAgePercent = TIER_THREE_AGE_PERCENT;
        }

        double numAccidentsPercent{};
        if (numAccidents == 0)
        {
            numAccidentsPercent = TIER_ZERO_WRECK_PERCENT;
        }
        else if (numAccidents == 1)
        {
            numAccidentsPercent = TIER_ONE_WRECK_PERCENT;
        }
        else if (numAccidents == 2)
        {
            numAccidentsPercent = TIER_TWO_WRECK_PERCENT;
        }
        else 
        {
            numAccidentsPercent = TIER_THREE_WRECK_PERCENT;
        }

        double premPercent{0};
        if (premOptions)
        {
            premPercent = .05;
        }

        double daprecciationValue = carMSRP * (carAgePercent - numAccidentsPercent + premPercent);
        print_eligible_message(daprecciationValue);
    }

    return 0;
}
