#include <cstdlib>
#include <iostream>
#include "DynArr.h"
#include "advert.h"

#define COUT std::cout
#define ENDL std::endl

// for the time being, assign all prices to be $1
// assume always gets deducted

double perHour(int days, double budget)
{
	int hours = days * 24;
  // somehow round off to 2 decimal places
  double budgetHour = budget/hours;
  COUT << "hours: " << hours << ENDL;
  COUT << "budget: " << budget << ENDL;
  COUT << "budget/hour: " << budgetHour << ENDL;
  return budgetHour;
}

int createStream(DynArr<advert> * adStream)
{
	double time = (double) rand()/RAND_MAX;
	COUT << time << '\t';
	advert ad(1, time, 1);
	(*adStream).push_back(ad);
	COUT << (*adStream).length() << ENDL;
	return 1;
}
