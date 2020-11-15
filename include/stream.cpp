// Authors: Livia Johan & Tyler Knapp
// File: stream.cpp

#include <cstdlib>
#include <iostream>
#include <time.h>
#include "DynArr.h"
#include "advert.h"

#define COUT std::cout
#define ENDL std::endl



// Creates a new advertisement and assigns a bidprice to it based on the bid strategy
void createEvent(DynArr<advert> * adStream, int days)
{
	//Making time values random each time
	time_t t1 = time(0);
	unsigned int t2 = (unsigned int) t1;
	srand(t2);
	// Converting the time from days to seconds
	double seconds = days*24*60*60.0;
	double time = 0;
	// Creates the initial ad
	advert ad(0, time);
	(*adStream).push_back(ad);

	// Creates a stream of events until the timestamps reach the total amount of time inputted.
	while(time <= seconds)
	{
		advert prev_ad = adStream->end();
		time = prev_ad.getTime();
		//COUT << "previous time: " << time << ENDL;
		time += (double) rand()/RAND_MAX;
		ad.setPrice(0);
		ad.setTime(time);
		(*adStream).push_back(ad);
	}
}
