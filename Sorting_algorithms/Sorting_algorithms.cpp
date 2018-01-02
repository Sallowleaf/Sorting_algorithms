// Sorting_algorithms.cpp : Exercise in sorting algorithms.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

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
//			}
//			else
//			{
//				temp = Pile[1];
//				Pile.erase(Pile.begin());
//			}
//			SSResult.push_back(temp);
//			a.erase(std::remove(a.begin(), a.end(), temp);
//		}
//	}
//	return SSResult;
//}
//std::vector<int> SelectionSortWMF(std::vector <int> a) //trying to write this sort function with the help of Minimum function.
//{
//	auto temp = 0;
//	for(int i=0; i <a.size(); i++)
//	{
//		temp = std::min_element(a.begin(), a.end());
//	}
//}
std::vector<int> InsertionSort(std::vector <int> a)
{
		for (int i = 0; i < a.size() - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			std::swap(a[i], a[i + 1]);
			for (int j = 0; j <= i && i != 0; j++)
			{
				if (a[i] < a[j])
				{
					//temp.emplace_back(temp[j]);
					//std::rotate(temp.begin(), temp.end()-1, temp.end());
					std::swap(a[j], a[i]);
				}
			}
		}
	}
	return a;
}
std::vector<int> MergeSort(std::vector<int> a)
{
	int Half = a.size() / 2;
	int VecSize = a.size() % Half;
	for (int i = 0; i < a.size()-2; i += 2)
	{
		if (a[i] > a[i + 1])
		{
			std::swap(a[i], a[i + 1]);
		}

	}
	return a;
}

int main()
{
	std::vector<int> temp;
	std::vector<int> S = { 3,5,4,14,1,87,87,96,54,78,4,6,78,3,45,985,2,0,5,8,74,7,11,13,10,33,47,112,135,47,26,40,41,62,50 };

	//temp = SelectionSort(S);
	//temp = InsertionSort(S);
	temp = MergeSort(S);

	for (int i = 0; i < temp.size(); i++)
		std::cout << temp[i] << ",";
	std::cout << "Result array size. "<< temp.size() << " Test array size. " << S.size() << "\n";

	return 0;
}

