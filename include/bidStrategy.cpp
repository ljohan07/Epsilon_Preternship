#include <cstdlib>
#include <iostream>
#include "advert.h"
int bidStrategy(advert * current_ad)
{
  int price = rand() % 2;
  current_ad->price = price;
  return 0;
}
