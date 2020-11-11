#include <cstdlib>
#include <iostream>
#include "DynArr.h"
#include "stream.cpp"

#define COUT std::cout
#define ENDL std::endl
#define RAND std::rand

/*
int bidStrategy(advert current_ad)
{
  //double price = rand() % 2;
  current_ad.price = 1;
  return 0;
}
*/

double bidStrategy() {
  //double price = rand() % 2;
  return 1;
}

// Calculates the average amount of money that needs to be spent every hour
double perHour(int hours, double budget) {
  // somehow round off to 2 decimal places
  double budgetHour = budget/hours;
  COUT << "hours left: " << hours << ENDL;
  COUT << "budget left: " << budget << ENDL;
  COUT << "budget/hour: " << budgetHour << ENDL;
  return budgetHour;
}

// returns the winRate for a given advertisement
double auctionModel(advert current_ad)
{
  return current_ad.price * 0.4;
}

DynArr<advert> auction(DynArr<advert> adStream, int days, double budget) {
  int index = 0;
  DynArr<advert> successfulAds;
  int hours = days * 24;
  int hoursLeft = hours;
  double budgetLeft = budget;
  double budgetUsed = 0;
  //Iterates through the number of hours
  for(int i = 0; i < hours; i++) {
    //Recalculates the new budget per hour
    double budgetPerHour = perHour(hoursLeft, budgetLeft);
    //Iterates through all the ads in that hour
    while( (adStream[index].time) < (3600 * (i + 1)) ){
      //Calculates whether we should bid on an ad
      if(budgetPerHour >= bidStrategy()){
        //Setting the price equal to the bid strategy
        adStream[index].price = bidStrategy();
      }
      // Creates random number to compare with win rate
      double probability = (double) rand()/RAND_MAX;
      // Finds the win rate of a single ad
      double winRate = auctionModel(adStream[index]);
      // If we bid on the ad and won the bid -> add the ad to our list and subtract the bid from the budget;
      if((winRate > probability) && (adStream[index].price != 0)){
        successfulAds.push_back(adStream[index]);
        budgetPerHour -= bidStrategy();
        budgetUsed += bidStrategy();
        //COUT << "Successful Ad. Budget = " << budgetPerHour << ENDL;
      }
      index++;
    }
    // Change the hours remaining and budget left 
    hoursLeft--;
    budgetLeft = budget - budgetUsed;
  }
    return successfulAds;
}
