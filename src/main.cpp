//#include "../include/stream.cpp"
#include "../include/auction.cpp"


int main()
{
  double budget = 5;
  int days = 5;
  //double budgetHour = perHour(days, budget);
  //COUT << budgetHour << ENDL;


  DynArr<advert> adStream;
	DynArr<advert> successfulAds;

  createEvent(&adStream, days);

  successfulAds = auction(adStream, days, budget);

  //printStream(adStream);
	//printStream(successfulAds);
	COUT << "adStream length: " << adStream.length() << ENDL;
	COUT << "successfulAds length: " << successfulAds.length() << ENDL;
	//COUT << "timestamp of last successful ad: " << successfulAds[successfulAds.length() - 1].time << ENDL;
	/*for(unsigned int i = 0; i < successfulAds.length(); ++i)
	{
		COUT << "timestamp of bid " << i << ": " << successfulAds[i].time << ENDL;
	}*/
  return 0;
}
