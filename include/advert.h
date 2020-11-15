// Authors: Livia Johan & Tyler Knapp
// File: advert.h

#define COUT std::cout
#define ENDL std::endl

struct advert {
private:
	double price;
	double time;

public:
	// Default Constructor
  advert(): price(0), time(0){}

	// Constructor taking in a price and time
  advert(int priceIn, double timeIn): price(priceIn), time(timeIn){}

	//Method for setting the time
	void setTime(double t)
	{
		this->time = t;
	}

	//Method for accessing the time
	double getTime() const {
		return time;
	}

	//Method for setting the price
	void setPrice(double p)
	{
		this->price = p;
	}

	//Method for accessing the price
	double getPrice() const {
		return price;
	}

	// Friend Operator for printing out the advertisement
	friend std::ostream& operator <<(std::ostream& output, const advert& theAdvert)
	{
		output << "time: " << theAdvert.time << "\t";
		output << "price: " << theAdvert.price << ENDL;
		return output;
	}

};
