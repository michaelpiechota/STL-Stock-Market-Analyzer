//Michael Piechota 
#ifndef H_stockType
#define H_stockType

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class stockType
{
	friend ostream& operator<<(ostream&, const stockType&);
	friend ifstream& operator>>(ifstream&, stockType&);

public:
	void setStockInfo(string symbol, double openPrice,
				      double closeProce, double high,
				      double Low, double prevClose,
					  int	shares);
	string getSymbol();
	double getPercentChange();
	double getOpenPrice();
	double getClosePrice();
	double getHighPrice();
	double getLowPrice();
	double getPrevPrice();
	int getnoOfShares();

	stockType();
	stockType(string symbol, double openPrice,
			  double closeProce, double high,
			  double Low, double prevClose,
			  int	shares);

	bool operator ==(const stockType& other) const;
	bool operator !=(const stockType& other) const;
	bool operator <=(const stockType& other) const;
	bool operator >=(const stockType& other) const;
	bool operator >(const stockType& other) const;
	bool operator <(const stockType& other) const;

private:
	string	stockSymbol;
	double	todayOpenPrice;
	double	todayClosePrice;
	double	todayHigh;
	double	todayLow;
	double	yesterdayClose;
	double	percentChange;
	int		noOfShares;
};

#endif