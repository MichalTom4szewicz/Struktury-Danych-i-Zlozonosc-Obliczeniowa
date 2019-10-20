#pragma once
using namespace std;

class Kopiec
{
public:

	int n; // ilosc elementow
	int*tab; //wskaznik na tablicew ktorej bedzie przechowywany kopiec

	Kopiec();

	~Kopiec();

	void swap(int&, int&);
	void kopiec_push(int);
	void kopiec_pop();
	bool kopiec_search(int);
	void kopiec_show();

	void kopiec_test_push(int);
	void kopiec_test_pop(int);
	void kopiec_test_search(int, int);
};