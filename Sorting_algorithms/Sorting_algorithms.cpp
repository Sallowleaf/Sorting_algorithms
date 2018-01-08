// Sorting_algorithms.cpp : Exercise in sorting algorithms.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> SelectionSort(std::vector <int> a)
{
	std::vector<int> Result;

	while (!a.empty())
	{
		for (int i = 0; i < a.size() - 1; i++)
		{
			if (a[i] < a[i + 1])
				std::swap(a[i + 1], a[i]);
		}
		Result.push_back(a[a.size() - 1]);
		a.pop_back();			//Why a.erase() doesn't work?
	}
	return Result;
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

	if (a.size() < 2)
		return a;

	if (a.size() == 2)
	{
		if (a[0] > a[1])
		{
			Result.push_back(a[1]);
			Result.push_back(a[0]);
			return Result;
		}
		else
		{
			Result.push_back(a[0]);
			Result.push_back(a[1]);
			return Result;
		}
	}

	if (a.size() > 2)
	{
		int Half = (a.size() / 2);
		std::vector<int> split_lo(a.begin(), a.begin() + Half);
		std::vector<int> split_hi(a.begin() + Half, a.end());
		MergeSort(split_hi);
		MergeSort(split_lo);
				
		for (int i = 0; i < split_lo.size() - 1; i++)//Merger last two splits.
		{
			if (split_hi[i] < split_lo[i])
			{
				Result.push_back(std::move(split_hi[i]));
				for (int j = i; j < split_hi.size() - 1; j++)
				{
					int u = i;
					if (split_hi[j + 1] < split_lo[u])
					{
						Result.push_back(std::move(split_hi[i + 1]));
						break;
					}
					else
					{
						Result.push_back(split_lo[u]);
						break;
					}
				}
			}
			else
			{
				Result.push_back(std::move(split_lo[i]));
				for (int j = i; j < split_lo.size() - 1; j++)
				{
					int u = i;
					if (split_lo[j + 1] < split_hi[u])
					{
						Result.push_back(std::move(split_lo[j + 1]));
						break;
					}
					else
					{
						Result.push_back(split_hi[u]);
						break;
					}
				}
			}
		}
		return Result;
	}
}



int main()
{
	std::vector<int> temp;
	std::vector<int> S = { 23,3,5,12,4,14,1,87,87,96,54,14,78,4,6,78,3,45,985,2,0,5,8,74,7,11,13,10,33,47,112,135,47,26,40,41,62,50 };

	//temp = SelectionSort(S);
	//temp = InsertionSort(S);
	temp = MergeSort(S);

	for (int i = 0; i < temp.size(); i++)
		std::cout << temp[i] << ",";
	std::cout << "\n Result array size. "<< temp.size() << " & Test array size. " << S.size() << "\n";

	return 0;
}

