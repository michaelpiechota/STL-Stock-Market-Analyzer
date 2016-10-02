//Michael Piechota 
#ifndef H_StockListType
#define H_StockListType

#include <string>
#include <vector>

#include "stockType.h"

using namespace std;

class stockListType
{
public:
	void printBySymbol();
	void printByGain();
	void printReports();
	void sortStockList();
	void sortByGain();
	
	void insert(const stockType& item);
private:
	vector<int> indexByGain;
	vector<stockType> list;
};

#endif
	