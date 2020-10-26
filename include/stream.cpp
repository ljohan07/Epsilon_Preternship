#include <cstdlib>
#include <iostream>
#include "DynArr.h"

#define COUT std::cout
#define ENDL std::endl
#define RAND std::rand

struct advert {
	int price;
	double time;
};

double perHour(int days, double budget)
{
	int hours = days * 24;
  // somehow round off to 2 decimal places
  double budgetHour = budget/hours;
  COUT << "hours: " << hours << ENDL;
  COUT << "budget: " << budget << ENDL;
  COUT << "budget/hour" << budgetHour << ENDL;
  COUT << "random number: " << rand() << ENDL;
  return budgetHour;

}
