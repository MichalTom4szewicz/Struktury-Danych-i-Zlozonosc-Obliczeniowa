#pragma once

using namespace std;

class Lista
{
public:

	int n;//rozmiar

	struct Element
	{
		int liczba;

		Element *next;
		Element *prev;

	};

	Element *glowa;
	Element *ogon;

	Lista(int);
	~Lista();

	void list_fill();
	void list_fill(int*);
	void list_show();
	bool list_search(int x);
	void list_push_beg(int x);
	void list_push_end(int x);
	void list_pop_end();
	void list_pop_beg();
	void list_push_mid(int x, int poz);//pozycja licznona tablicowo liczymy od zera
	void list_pop_mid(int poz);

	void lista_test_push_beg(int);
	void lista_test_push_end(int);
	void lista_test_push_mid(int);

	void lista_test_pop_beg(int);
	void lista_test_pop_end(int);
	void lista_test_pop_mid(int);

	void lista_test_search(int, int);

};

