struct advert {
	int price;
	double time;
	double winRate;

  //advert(): price(0), time(0), winRate(0){}

  advert(int priceIn, double timeIn, double winRateIn): price(priceIn), time(timeIn), winRate(winRateIn){}
};
