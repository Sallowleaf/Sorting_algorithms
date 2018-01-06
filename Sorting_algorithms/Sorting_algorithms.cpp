// Sorting_algorithms.cpp : Exercise in sorting algorithms.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> SelectionSort(std::vector <int> a)
{
	auto temp = a[0];
	std::vector<int> SSResult;

	for (int j = 0; j<a.size()-1; j++)
	{
		for (int i = 0; i < a.size() - 1; i++)
		{
			if (a[i] < a[i + 1])
				std::swap(a[i + 1], a[i]);
		}
		SSResult.push_back(a[a.size() - 1]);
		a.erase(a.begin(),a.end());
	}

	/*std::vector<int> Pile = a;
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
	}
	SSResult.push_back(std::move(temp));
}*/
	return SSResult;
}

std::vector<int> BubbleSort(std::vector <int> a) //Isertion sort function.
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
					std::swap(a[j], a[i]);
				}
			}
		}
	}
	return a;
}
std::vector<int> InsertionSort(std::vector <int> a)
{
	std::vector <int> Pile;
	Pile.push_back(a[0]);

	for (int i = 1; i < a.size(); i++)
	{
		Pile.push_back(a[i]);
		for (int j = i; j != 0; j--)
		{
			if (Pile[j] < Pile[j - 1])
				std::swap(Pile[j - 1], Pile[j]);
		}
	}
	return Pile;
}
std::vector<int> MergeSort(std::vector<int> a)
{
	std::vector<int> Result;
	int Half = a.size() / 2;
	

	if (a.size() < 2)
		Result.push_back(a[0]);

	if (a.size() == 2)
	{
		if (a[0] > a[1])
		{
			Result.push_back(a[1]);
			Result.push_back(a[0]);
		}
		else
		{
			Result.push_back(a[0]);
			Result.push_back(a[1]);
		}
	}
	else
	{	
		std::vector<int> split_lo(a.begin(), a.begin() + (a.size()/2));
		std::vector<int> split_hi(a.begin() + (a.size()/2), a.end());
		MergeSort(split_hi);
		MergeSort(split_lo);

		for (int i = 0; i<split_hi.size()-1; i++)
		{
			if (split_hi[i] < split_lo[i])
				Result.push_back(std::move(split_hi[i]));
			else
				Result.push_back(std::move(split_lo[i]));
		}
	}
	return Result;
}


int main()
{
	std::vector<int> temp;
	std::vector<int> S = { 23,3,5,4,14,1,87,87,96,54,14,78,4,6,78,3,45,985,2,0,5,8,74,7,11,13,10,33,47,112,135,47,26,40,41,62,50 };

	temp = SelectionSort(S);
	//temp = InsertionSort(S);
	//temp = MergeSort(S);

	for (int i = 0; i < temp.size(); i++)
		std::cout << temp[i] << ",";
	std::cout << "\n Result array size. "<< temp.size() << " & Test array size. " << S.size() << "\n";

	return 0;
}

