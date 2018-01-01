// Sorting_algorithms.cpp : Exercise in sorting algorithms.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

//std::vector<int> SelectionSort(std::vector <int> a)
//{
//	auto temp = a[0];
//	std::vector<int> SSResult;
//	//std::vector<int> b = a;
//		
//	for (int i = 0; i < a.size() - 1; i++)
//	{
//		std::vector<int> Pile = a;
//		for (int j = 0; j < Pile.size(); j++)
//		{
//			if (Pile[0] <= Pile[1])
//			{
//				temp = Pile[0];
//				Pile.erase(Pile.begin() + 1);
//							}
//			else
//			{
//				temp = Pile[1];
//				Pile.erase(Pile.begin());
//			}
//			SSResult.push_back(temp);
//			a.erase(std::remove (a.begin(), a.end(), temp);
//		}
//	}
//	return SSResult;
//}

std::vector<int> InsertionSort(std::vector <int> a)
{
	auto b = a;
	auto c=0;
	auto t=0;
	std::vector<int> temp = { a[0], a[1] };

	for (int i = 0; i < a.size()-3; i++)
	{
		for (int j = 0; j < temp.size()-1; j++)
		{
			if (temp[j + 1] < temp[j])
			{
				//temp.emplace_back(temp[j]);
				//std::rotate(temp.begin(), temp.end()-1, temp.end());
				c = temp[j];
				t = temp[j + 1];
				temp.erase(temp.begin()+j);
				temp.erase(temp.begin() + (j+1));
				temp.push_back(t);
				temp.push_back(c);
			}
		}
		temp.push_back(a[i+2]);
	}
	return temp;
}

int main()
{
	std::vector<int> temp;
		std::vector<int> S = { 3,5,4,14,1,87,87,96,54,78,4,6,78,3,45,985,2,0,5,8,74,7,11,13,10,33,47,112,135,47,26,40,41,50 };
				
	//temp = SelectionSort(S);
		temp = InsertionSort(S);

	for (int i = 0; i < temp.size() ; i++)
		std::cout << temp[i]<<",";

	return 0;
}

