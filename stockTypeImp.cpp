//Michael Piechota 
#include <iostream>
#include <iomanip>
#include <string>
#include "stockType.h"

using namespace std;

void stockType::setStockInfo(string symbol, double openPrice,
				      double closeProce, double high,
				      double low, double prevClose,
					  int shares)
{
		stockSymbol = symbol;
		todayOpenPrice = openPrice;
		todayClosePrice = closeProce;
		todayHigh = high;
		todayLow = low;
		yesterdayClose = prevClose;
		percentChange = (todayClosePrice - yesterdayClose) / yesterdayClose;
		noOfShares = shares;
}

string stockType::getSymbol()
{
	return stockSymbol;
}

double stockType::getPercentChange()
{
	return percentChange;
}

double stockType::getOpenPrice()
{
	return todayOpenPrice;
}

double stockType::getClosePrice()
{
	return todayClosePrice;
}

double stockType::getHighPrice()
{
	return todayHigh;
}

double stockType::getLowPrice()
{ 
	return todayLow;
}

double stockType::getPrevPrice()
{
	return yesterdayClose;
}

int stockType::getnoOfShares()
{
	return noOfShares;
}

stockType::stockType()
{
    stockSymbol = "";
    todayOpenPrice = 0;
    todayClosePrice = 0;
    todayHigh = 0;
    todayLow = 0;
    yesterdayClose = 0;
    percentChange = 0;
    noOfShares =  0;
}
stockType::stockType(string symbol, double openPrice,
			  double closeProce, double high,
			  double low, double prevClose,
			  int	shares)
{
    stockSymbol = symbol;
    todayOpenPrice = openPrice;
    todayClosePrice = closeProce;
    todayHigh = high;
    todayLow = low;
    yesterdayClose = prevClose;
    percentChange = (todayClosePrice - yesterdayClose) / yesterdayClose;
    noOfShares = shares;
}

bool stockType::operator ==(const stockType& other)  const
{
	return (stockSymbol == other.stockSymbol);
}

bool stockType::operator !=(const stockType& other) const
{
	return (stockSymbol != other.stockSymbol);
}

bool stockType::operator <=(const stockType& other) const
{
	return (stockSymbol <= other.stockSymbol);
}

bool stockType::operator >=(const stockType& other) const
{
	return (stockSymbol >= other.stockSymbol);
}

bool stockType::operator >(const stockType& other) const
{
	return (stockSymbol > other.stockSymbol);
}

bool stockType::operator <(const stockType& other) const
{
	return (stockSymbol < other.stockSymbol);
}


ostream& operator<<(ostream& os, const stockType& stock)
{
	os << setw(6) << stock.stockSymbol << "  "
   	   << setw(6) << stock.todayOpenPrice << "  "
  	   << setw(6) << stock.todayClosePrice << "  "
	   << setw(6) << stock.todayHigh << "  "
	   << setw(6) << stock.todayLow << "  "
	   << setw(6) << stock.yesterdayClose << "  "	  
	   << setw(8) << stock.percentChange * 100 << "% "
	   << setw(10) << stock.noOfShares;
	return os;
}

ifstream& operator>>(ifstream& inf, stockType& stock)
{
	inf >> stock.stockSymbol>>stock.todayOpenPrice
		>> stock.todayClosePrice>>stock.todayHigh
		>> stock.todayLow>>stock.yesterdayClose
		>> stock.noOfShares;
	
	stock.percentChange = (stock.todayClosePrice - stock.yesterdayClose) / stock.yesterdayClose;

	return inf;
}