#include "stdafx.h"
#include "Tablica.h"
#include "Kopiec.h"
#include "Licznik.h"
#include "Kopiec.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>


Tablica::Tablica(int rozmiar)
{
	n = rozmiar;
	tab = new int[rozmiar];
}


Tablica::~Tablica()
{
	delete[] tab;
}

void Tablica::tab_fill()
{
	for (int i = 0; i<n; ++i)
	{
		tab[i] = rand();
	}
}

void Tablica::tab_fill(int *tablica)
{
	for (int i = 0; i<n; ++i)
	{
		tab[i] = tablica[i];
	}
}

void Tablica::tab_show()
{
	cout << "Oto zawartosc tablicy: ";
	for (int i = 0; i<n; ++i)
	{
		cout << tab[i] << ", ";
	}
}

void Tablica::tab_push_beg(int wartosc)
{
	n++;
	int *tmp = new int[n];
	tmp[0] = wartosc;

	for (int i = 1; i<n; i++)
	{
		tmp[i] = tab[i - 1];
	}

	delete[] tab;
	tab = tmp;
}

void Tablica::tab_push_end(int wartosc)
{
	n++;
	int *tmp = new int[n];
	tmp[n - 1] = wartosc;

	for (int i = 0; i<n - 1; i++)
	{
		tmp[i] = tab[i];
	}

	delete[] tab;
	tab = tmp;
}

bool Tablica::tab_search(int wartosc)
{
	for (int i = 0; i<n; ++i)
	{
		if (tab[i] == wartosc)
		{			
			return true;
		}
	}
	return false;
	
}

void Tablica::tab_pop_beg()
{

	if (n == 0)
	{
		return;
	}

	n--;
	int *tmp = new int[n];

	for (int i = 0; i<n; i++)
	{
		tmp[i] = tab[i + 1];
	}

	delete[] tab;
	tab = tmp;

}

void Tablica::tab_pop_end()
{
	if (n == 0)
	{
		return;
	}


	n--;
	int *tmp = new int[n];

	for (int i = 0; i<n; i++)
	{
		tmp[i] = tab[i];
	}

	delete[] tab;
	tab = tmp;

}

void Tablica::tab_push_mid(int wartosc, int pozycja)
{
	if (n == 0)
	{
		tab_push_beg(wartosc);
		return;

	}

	if (pozycja<n && pozycja >= 0)
	{
		if (pozycja == 0 || pozycja == n - 1)
		{
			if (pozycja == 0)
			{
				tab_push_beg(wartosc);
			}
			else
			{
				tab_push_end(wartosc);
			}
		}
		else
		{
			n++;
			int *tmp = new int[n];
			tmp[pozycja] = wartosc;

			for (int i = 0; i<pozycja; i++)
			{
				tmp[i] = tab[i];
			}
			for (int i = pozycja + 1; i<n; i++)
			{
				tmp[i] = tab[i - 1];
			}

			delete[] tab;
			tab = tmp;
		}
	}
	else
	{
		cout << "Nie mozna!" << endl;
	}
}

void Tablica::tab_pop_mid(int pozycja)
{
	if (n == 0)
	{
		return;
	}

	if (pozycja<n && pozycja >= 0)
	{
		if (pozycja == 0 || pozycja == n - 1)
		{
			if (pozycja == 0)
			{
				tab_pop_beg();
			}
			else
			{
				tab_pop_end();
			}
		}
		else
		{
			n--;
			int *tmp = new int[n];

			for (int i = 0; i<pozycja; i++)
			{
				tmp[i] = tab[i];
			}
			for (int i = pozycja; i<n; i++)
			{
				tmp[i] = tab[i + 1];
			}

			delete[] tab;
			tab = tmp;
		}
	}
	else
	{
		cout << "Nie mozna!" << endl;
	}
}

void Tablica::tab_test_push_beg(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "tablica_push_beg_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Tablica *tab;

	int random;

	for (int j = 0; j < 100; j++)
	{

		tab = new Tablica(ilosc);

		tab->tab_fill();
		random = rand();

		licznik.StartCounter();
		tab->tab_push_beg(random);	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete tab;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Tablica::tab_test_push_end(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "tablica_push_end_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Tablica *tab;

	int random;

	for (int j = 0; j < 100; j++)
	{

		tab = new Tablica(ilosc);

		tab->tab_fill();
		random = rand();

		licznik.StartCounter();
		tab->tab_push_end(random);	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete tab;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}


void Tablica::tab_test_push_mid(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "tablica_push_mid_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Tablica *tab;

	int random;
	int rand_poz;

	for (int j = 0; j < 100; j++)
	{

		tab = new Tablica(ilosc);

		tab->tab_fill();
		random = rand();
		rand_poz = rand() % ilosc;
		licznik.StartCounter();
		tab->tab_push_mid(random, rand_poz);	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete tab;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Tablica::tab_test_pop_beg(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "tablica_push_beg_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Tablica *tab;
	
	for (int j = 0; j < 100; j++)
	{

		tab = new Tablica(ilosc);

		tab->tab_fill();

		licznik.StartCounter();
		tab->tab_pop_beg();	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete tab;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Tablica::tab_test_pop_end(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "tablica_pop_end_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Tablica *tab;

	for (int j = 0; j < 100; j++)
	{

		tab = new Tablica(ilosc);

		tab->tab_fill();

		licznik.StartCounter();
		tab->tab_pop_end();	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete tab;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Tablica::tab_test_pop_mid(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "tablica_pop_mid_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Tablica *tab;

	int rand_poz;

	for (int j = 0; j < 100; j++)
	{

		tab = new Tablica(ilosc);

		tab->tab_fill();

		rand_poz = rand()%ilosc;

		licznik.StartCounter();
		tab->tab_pop_mid(rand_poz);	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete tab;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Tablica::tab_test_search(int ilosc, int szukana)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "tablica_search_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Tablica *tab;


	for (int j = 0; j < 100; j++)
	{

		tab = new Tablica(ilosc);

		tab->tab_fill();
		
		licznik.StartCounter();
		tab->tab_search(szukana);	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete tab;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}
