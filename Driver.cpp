//Michael Piechota
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "stockType.h"
#include "stockListType.h"

using namespace std;

const int noOfStocks = 5;

void getData(stockListType& list);

int main()
{
	stockListType stockList;  
	
	cout << fixed << showpoint;
	cout << setprecision(2);

	getData(stockList);

	stockList.sortStockList();
	stockList.printBySymbol();
	cout << endl;
	stockList.printByGain();

	return 0;
}

void getData(stockListType& list)
{
	ifstream infile;
	
	string symbol;
	double OpenPrice;
	double ClosePrice;
	double tHigh;
	double tLow;
	double yClose;
	int	   shares;
	
	stockType temp;

	infile.open("stockdat.txt");

	if (!infile)
	{
		cerr << "Input file does not exist. Program terminates." << endl;
		return;
	}

	infile >> symbol;
	while (infile)
	{
		infile >> OpenPrice >> ClosePrice >> tHigh >> tLow >> yClose >> shares;
		temp.setStockInfo(symbol,OpenPrice,ClosePrice,tHigh,tLow,yClose,shares);
		list.insert(temp);
		infile >> symbol;
	}
}

