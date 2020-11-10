#include <cstdlib>
#include <iostream>
#include "DynArr.h"
#include "stream.cpp"

#define COUT std::cout
#define ENDL std::endl
#define RAND std::rand

double bidStrategy()
{
  //double price = rand() % 2;
  return 1;
}

// returns the winRate for a given advertisement
double auctionModel(advert * current_ad)
{
  return current_ad->price * 0.8;
}

// Calculates the average amount of money that needs to be spent every hour
double perHour(int hours, double budget)
{
  double budgetHour = budget/hours;
  return budgetHour;
}

// Calculates the average amount of money that needs to be spent every hour
double perDay(int days, double budget)
{
  double budgetDay = budget/days;
  return budgetDay;
}

DynArr<advert> auction(DynArr<advert> adStream, int days, double budget) {
  int index = 0;
  DynArr<advert> successfulAds;
	int hours = 0;
	int hourOfDay = 0;
	int daycount = days;
  //Iterates through the number of hours
  while(hours < (24*days))
	{
		if(hours % 24 == 0)
		{
			hourOfDay = 0;
      if(hours != 0)
      {
        daycount--;
      }
			//COUT << "NEW DAY" << ENDL;
		}
    double budgetPerHour = perDay(daycount, budget)/(24-hourOfDay);

  	if(daycount == 5)
    {
      COUT << "day: " << daycount << ", budget: " << budget << ENDL;
      COUT << "\thour: " << hourOfDay << "\t budgetPerHour: " << budgetPerHour << ENDL;
    }


		//while( (adStream[index].time) < (3600 * (hours + 1)) )
    while( (adStream[index].time) < 3600*24 )
		{
      //COUT << "\t\t\t" << adStream[index].time << ENDL;
    	if(budgetPerHour >= 1)
			{
        COUT << "setting price...\n";
      	adStream[index].price = bidStrategy();
    	}
      else
      {
        adStream[index].price = 0;
      }
      //COUT << adStream[index].price << ", " << adStream[index].time << ENDL;
    	double probability = (double) rand()/RAND_MAX;
    	double winRate = auctionModel(&adStream[index]);
      //COUT << "\t" << adStream[index].price << ", " << adStream[index].time <<", " << probability << ENDL;
    	if((winRate > probability) && (adStream[index].price != 0))
			{
				successfulAds.push_back(adStream[index]);
				budget -= adStream[index].price;
    	}
    	index++;

      if(hours == 23)
      {
        COUT << "\t" << adStream[index].time  << ENDL;
      }
      /*if(adStream[index+1].time > (3600*(hours + 1)))
      {
        hours++;
        hourOfDay++;
      }*/
  	}
    hours++;
    hourOfDay++;

  }
   return successfulAds;
}
