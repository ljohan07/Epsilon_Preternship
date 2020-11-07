#include "../include/stream.cpp"


int main()
{
  //double budget = 500;
  int days = 5;
  //double budgetHour = perHour(days, budget);
  //COUT << budgetHour << ENDL;


  DynArr<advert> adStream;

  createEvent(&adStream, days);
  

  //printStream(adStream);

  return 0;
}
