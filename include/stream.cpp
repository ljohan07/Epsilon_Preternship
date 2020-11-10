#include <cstdlib>
#include <iostream>
#include "DynArr.h"
#include "advert.h"

#define COUT std::cout
#define ENDL std::endl



// Creates a new advertisement and assigns a bidprice to it based on the bid strategy
void createEvent(DynArr<advert> * adStream, int days)
{
	double seconds = days*24*60*60.0;
	double time = 0;
	advert ad(1, time);
	(*adStream).push_back(ad);

	while(time <= seconds)
	{
		advert prev_ad = adStream->end();
		time = prev_ad.time;
		//COUT << "previous time: " << time << ENDL;
		time += (double) rand()/RAND_MAX;
		ad.price = 1;
		ad.time = time;
		(*adStream).push_back(ad);
	}


	/*
	//advert previous = adStream[adStream->length()-1];
	if(adStream->length() > 1)
	{
		advert prev_ad = adStream->end();
		//COUT << "checking for previous: ";
		//COUT << prev_ad.price << ", " << prev_ad.time << ENDL;
		time = prev_ad.time;
	}
	else
	{
		time = 0;
	}


	time += (double) rand()/RAND_MAX;
	COUT << "now time is " << time << ENDL;

	//COUT << time << '\t';
	advert ad(1, time);

	//bidStrategy(&ad);
	(*adStream).push_back(ad);
	//COUT << (*adStream).length() << ENDL;
	*/
}

// prints information about an advertisement
void printStream(DynArr<advert> adStream)
{
	for(unsigned int i = 0; i < adStream.length(); i++)
  {
    COUT << adStream[i].price << ", ";
    COUT << adStream[i].time << ENDL;
  }

}
