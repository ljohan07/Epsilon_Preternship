#include <cstdlib>
#include <iostream>
#include "advert.h"
// for now, since we are doing flat bidding, bidStrateggy returns either 0 or 1 for the price
int bidStrategy(advert * current_ad)
{
  //double price = rand() % 2;
  current_ad->price = 1;
  return 0;
}
