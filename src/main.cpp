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
    createStream(&adStream);
    budget -= 1;
  }

  return 0;
}
