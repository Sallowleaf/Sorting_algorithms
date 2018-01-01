// Sorting_algorithms.cpp : Exercise in sorting algorithms.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

std::vector<int> SelectionSort(std::vector <int> a)
{
	auto temp = a[0];
	std::vector<int> SSResult;
	//std::vector<int> b = a;
		
	for (int i = 0; i < a.size() - 1; i++)
	{
		std::vector<int> Pile = a;
		for (int j = 0; j < Pile.size(); j++)
		{
			if (Pile[0] <= Pile[1])
			{
				temp = Pile[0];
				Pile.erase(Pile.begin() + 1);
							}
			else
			{
				temp = Pile[1];
				Pile.erase(Pile.begin());
			}
			SSResult.push_back(temp);
			a.erase(std::remove (a.begin(), a.end(), temp);
		}
	}
	return SSResult;
}

int main()
{
	std::vector<int> temp;
		std::vector<int> S = { 3,5,4,14,1,87,87,96,54,78,4,6,78,3,45,985,2,0,5,8,74,7,11,13,10,33,47,112,135,47,26,40,41,50 };

	temp = SelectionSort(S);
	for (int i = 0; i < temp.size() ; i++)
		std::cout << temp[i]<<",";

	return 0;
}

