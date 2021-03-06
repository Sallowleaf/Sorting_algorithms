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
	{
		Result.push_back(a[0]);	
		return Result;
	}
	if (a.size() == 2)
	{
		if (a[0] >= a[1])
		{
			Result.push_back(a[1]);
			Result.push_back(a[0]);	
			return Result;
		}
		else
			return a;		
	}
	if (a.size() > 2)
	{
		int Half = (a.size() / 2);
		std::vector<int> split_lo=(MergeSort(std::vector<int>(a.begin(), a.begin() + (a.size() / 2))));
		std::vector<int> split_hi=(MergeSort(std::vector<int>(a.begin() + (a.size() / 2), a.end())));

		do
		{
			if (split_lo[0] <= split_hi[0])
			{
				Result.push_back(split_lo[0]);
				split_lo.erase(split_lo.begin());
			}
			else
			{
				Result.push_back(split_hi[0]);
				split_hi.erase(split_hi.begin());
			}			
		} while (!split_hi.empty()&& !split_lo.empty());//Merge two sorted lists. 

		while (!split_lo.empty())
		{
			Result.push_back(split_lo[0]);
			split_lo.erase(split_lo.begin());
		}
		while (!split_hi.empty())
		{
			Result.push_back(split_hi[0]);
			split_hi.erase(split_hi.begin());
		}		
	}
	return Result;
}
std::vector<int> QuickSort(std::vector<int> a)
{
	int Pivot, left = 0, Right = a.size()-1;
	int leftarrow = left;
	int Rightarrow = Right;
	Pivot = a[(left + Right) / 2];
	do
	{
		while (a[leftarrow] < Pivot)
			leftarrow++;
		while (Rightarrow > Pivot)
			Rightarrow--;
		if (leftarrow <= Rightarrow)
		{
			std::swap(a[leftarrow], a[Rightarrow]);
			leftarrow++;
			Rightarrow--;
		}
	} while (leftarrow <= Rightarrow);

	if (left < Rightarrow)
		QuickSort(std::vector<int> (a.begin()+left, a.begin()+(left + Right) / 2));
	if (leftarrow < Right)
		QuickSort(std::vector<int> (a.begin()+(left + Right) / 2, a.begin()+Right));

	return a;
}
std::vector<int> StoogeSort(std::vector<int> a)
{
	int Head = 0, Tail = a.size() - 1;
	if ((Tail - Head + 1) <= 2)
	{
		if (a[Head] > a[Tail])
			std::swap(a[Head], a[Tail]);
		return a;
	}
	if ((Tail - Head + 1)>2)
	{
		int Trimester = (Tail-Head+1) / 3;
		StoogeSort(std::vector<int>(a[Head],a[Tail-Trimester]));
		StoogeSort(std::vector<int>(a[Head + Trimester], a[Tail]));
		StoogeSort(std::vector<int>(a[Head], a[Tail - Trimester]));
	}
	return a;
}

int main()
{
	std::vector<int> temp;
	std::vector<int> S = { 23,3,5,12,4,14,1,87,87,96,54,14,78,4,6,78,3,45,985,19,14,2,0,5,8,74,37,7,11,13,10,33,47,112,135,47,26,40,41,62,50 };
	std::vector<int> T = {4,0};

	//temp = SelectionSort(S);
	//temp = InsertionSort(S);
	//temp = MergeSort(S);
	//temp = QuickSort(S);
	temp = StoogeSort(S);

	for (int i = 0; i < temp.size(); i++)
		std::cout << temp[i] << ",";
	std::cout << "\n Result array size. "<< temp.size() << " & Test array size. " << S.size() << "\n";

	return 0;
}

