#include "../include/stream.cpp"


int main()
{
  double budget = 50000;
  int days = 27;
  double budgetHour = perHour(days, budget);
  COUT << budgetHour << ENDL;

  DynArr<advert> adStream;

  while(budget >= 1)
  {
    budget -= 1;
  }

  COUT << (float) rand() / RAND_MAX << ENDL;
  COUT << (float) rand() / RAND_MAX << ENDL;

  return 0;
}
