// Authors: Livia Johan & Tyler Knapp
// File: main.cpp

#include "../include/auction.cpp"


int main() {
  // initialize variables to be used
  double budget;
  int days;
  char decision = 'y';
  char cont = 'y';

  // check if the user wants to run new simulations
  while(cont != 'n') {
    // get user input for budget and number of days
    COUT << "What is your budget? ";
    CIN >> budget;
    COUT << "Budget has been set to: " << budget << ENDL;
    COUT << "How many days will you be bidding? ";
    CIN >> days;
    COUT << "The number of days has been set to: " << days << ENDL;

    // initialize the dynamic arrays
    DynArr<advert> adStream;
  	DynArr<advert> successfulAds;

    // create the bidStream
    createEvent(&adStream, days);

    // run the auction
    successfulAds = auction(adStream, days, budget);

    // print out lengths of ad stream vs. successful ads
  	COUT << "adStream length: " << adStream.length() << ENDL;
  	COUT << "successfulAds length: " << successfulAds.length() << ENDL;

    // ask the user if they want to display the lists
    COUT << "Would you like to see the list of successful ads? (y/n) ";
    CIN >> decision;
    if(decision == 'y')
    {
      for(unsigned int i = 0; i < successfulAds.length(); i++)
      {
        COUT << successfulAds[i];
      }
    }

    // ask user if they would like to run another simulation
    COUT << "Would you like to continue simulating? (y/n) ";
    CIN >> cont;
  }

  return 0;
}
