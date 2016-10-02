//Michael Piechota 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "stockType.h"
#include "stockListType.h"

using namespace std;

void stockListType::insert(const stockType& item)
{
	list.push_back(item);
}

void stockListType::printBySymbol()
{
//	unsigned int i;
	double closingBalance = 0;
	
	cout << "*********  First Investor's Heaven   **********" << endl;
	cout << "*********     Financial Report       **********" << endl; 
	cout << "Stock             Today                 Previous  Percent" << endl;
	cout << "Symbol  Open    Close   High    Low     Close     Gain	     Volume" << endl;
	cout << "------  -----   -----   -----   -----   --------  -------     ------" << endl;

	for (unsigned int i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl;
		closingBalance += list[i].getClosePrice() * list[i].getnoOfShares();
	}

	cout << "Closing Assets: $" << closingBalance << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

void stockListType::printByGain()
{
//	unsigned int i;
	
	cout << "*********  First Inverstor's Heaven  **********" << endl;
	cout << "*********     Financial Report       **********" << endl;
	cout << "*********        Gain/Loss           **********" << endl; 
	cout << "Stock             Today                 Previous  Percent" << endl;
	cout << "Symbol  Open    Close   High    Low     Close     Gain	     Volume" << endl;
	cout << "------  -----   -----   -----   -----   --------  -------     ------ " << endl;

	for (unsigned int i = 0; i < list.size(); i++)
		cout << list[indexByGain[i]] << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

void stockListType::printReports()
{
	printBySymbol();
	cout << endl << endl;
	cout << "***** Report by Gain *****" << endl;
	printByGain();
}

void stockListType::sortStockList()
{
	sort(list.begin(), list.end());

	sortByGain();
}

void stockListType::sortByGain()
{
	bool *temp;

	temp = new bool[list.size()];

//	unsigned int i, j;
	int maxIndex;

	for (unsigned int i = 0; i < list.size(); i++)
		temp[i] = false;

	for (unsigned int i = 0; i < list.size(); i++)
	{
		for (unsigned int j = 0; j < list.size(); j++)
			if (!temp[j])
			{
				maxIndex = j;
				break;
			}

		for (unsigned int j = maxIndex + 1; j < list.size(); j++)
			if (!temp[j])
				if (list[maxIndex].getPercentChange() <
					list[j].getPercentChange())
					maxIndex = j;

		indexByGain.push_back(maxIndex);
		temp[maxIndex] = true;
	
	}
	
	delete [] temp;
}
	


