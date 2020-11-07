#include <cstdlib>
#include <iostream>
#include "DynArr.h"
#include "advert.h"

#define COUT std::cout
#define ENDL std::endl
#define RAND std::rand

int bidStrategy(advert * current_ad)
{
  //double price = rand() % 2;
  current_ad->price = 1;
  return 0;
}

// Calculates the average amount of money that needs to be spent every hour
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

DynArr<advert> auction(DynArr<advert> * adStream, int days, double budget) {
  int index = 0;
  DynArr<advert> successfulAds;
  //Iterates through the number of hours
  for(int i = 0; i < hours; i++) {
    //*************************************************************
    // NEED TO ACCOUNT FOR IF WE DONT REACH THE BUDGET IN THAT HOUR
    //*************************************************************
    double budgetPerHour = perHour(days, budget);
    //Iterates through all the ads in that hour
    while( (adStream[index].time) < (3600 * (i + 1)) ){
      //Calculates whether we should bid on an ad
      if(budgetPerHour >= bidStrategy)

      // Creates random number to compare with win rate
      double probability = (double) rand()/RAND_MAX;
      // Finds the win rate of a single ad
      double winRate = auctionModel(adStream[index]);

      index++;
    }
  }


  if(winRate > probability)
  {
    return *current_ad;
  }
  else
  {
    return NULL;
  }
}

// returns the winRate for a given advertisement
double auctionModel(advert * current_ad)
{
  return current_ad->price * 0.8;
}
