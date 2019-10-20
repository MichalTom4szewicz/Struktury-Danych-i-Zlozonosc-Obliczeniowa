#pragma once

using namespace std;

class Tablica
{
public:

	int n;	//rozmiar
	int *tab;

	Tablica(int);
	~Tablica();

	void tab_fill();
	void tab_fill(int*);
	void tab_show();
	void tab_push_beg(int wartosc);
	void tab_push_end(int wartosc);
	bool tab_search(int wartosc);
	void tab_pop_beg();
	void tab_pop_end();
	void tab_push_mid(int wartosc, int pozycja);
	void tab_pop_mid(int pozycja);

	void tab_test_push_beg(int);
	void tab_test_push_end(int);
	void tab_test_push_mid(int);
	void tab_test_pop_beg(int);
	void tab_test_pop_end(int);
	void tab_test_pop_mid(int);
	void tab_test_search(int, int);


};

