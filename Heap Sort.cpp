// Heap Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include"vector.h"
#include<cmath>
using namespace std;
template<typename T>
void removemax(T*);
template<typename E>
class Less {
public:
	bool operator()(const E& left, const E& right)
	{
		return left < right;
	}
};

template<typename T>
T* pos(int i, T*);
template<typename T>
void upheapbubbling(T*);
template<typename T>
int idx(T*);
vector<int> object;
int main()
{
	object.push_back(3);
	object.push_back(7);
	object.push_back(2);
	object.push_back(1);
	object.push_back(4);
	object.push_back(0);
	object.push_back(10);
	object.push_back(3);
	for (int i = 1; i <= object.size(); i++)
	{
		upheapbubbling(&object[i - 1]);
	}
	for (int i = 1; i <= object.size(); i++)
	{
		removemax(&object[object.size() - i]);
	}
	for (auto it : object)
	{
		cout << it<<endl;
	}
}
template<typename T>
bool hasRight(T* p, int i)
{
	return (2 * idx(p) + 2) < i;
}
template<typename T>
bool hasLeft(T* p, int i)
{
	return (2 * idx(p) + 1) < i;
}
template<typename T>
int idx(T* p)
{
	return p - object.begin();
}
template<typename T>
T* pos(int i, T* p)
{
	return  object.begin() + i;
}
template<typename T>
T* parent(T* p)
{
	if (idx(p) % 2 == 0)
		return pos(floor(((idx(p) - 1) / 2.0)), p);
	return pos(floor(idx(p) / 2.0), p);
}
template<typename T>
void swap(T* p, T* q)
{
	T e = *q; *q = *p; *p = e;
}
template<typename T>
T* left(T* p)
{
	return pos(((2 * idx(p)) + (1)), p);
}
template<typename T>
T* right(T* p)
{
	return pos((2 * idx(p) + 2), p);
}
template<typename T>
void removemax(T* p)
{
	Less<T> isLess;
	int i = idx(p);
	swap(&object[0], &object[i]);
	int j = 0;
	while (hasLeft(&object[j], i) || hasRight(&object[j], i))
	{
		T* s = left(&object[j]);
		if (hasRight(&object[j], i) && isless(*s, *right(&object[j])))
			s = right(&object[j]);
		if (isless(object[j], *s))
		{
			swap(&object[j], s);
			j = idx(s);
		}
		else
			break;

	}
}
template<typename T>
void upheapbubbling(T* last)
{
	if (idx(last) == 0)
		return;
	Less<T> isLess;
	while (idx(last) != 0)
	{

		T* par = parent(last);
		if (isLess(*par, *last))
		{
			swap(par, last);
			last = par;
		}
		else {
			break;
		}

	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
