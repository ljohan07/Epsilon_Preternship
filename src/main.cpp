#include "../include/stream.cpp"


int main()
{
  double budget = 50;
  int days = 5;
  double budgetHour = perHour(days, budget);
  COUT << budgetHour << ENDL;

  DynArr<advert> adStream;

  while(budget >= 1)
  {
    budget -= createStream(&adStream);
  }
  COUT << adStream.length() << ENDL << ENDL;

  printStream(adStream);

  return 0;
}
