#include "stdafx.h"
#include "Kopiec.h"
#include "Licznik.h"
#include "Kopiec.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

void Kopiec::swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

Kopiec::Kopiec()
{
	n = 0;
}

Kopiec::~Kopiec()
{
	delete tab;

}

void Kopiec::kopiec_push(int liczba)
{
	n++;
	int i = n;
	int *t = new int[i + 1];

	for (int j = 1; j <= n - 1; j++)
	{
		t[j] = tab[j];
	}
	delete tab;
	tab = t;

	tab[i] = liczba;

	while (i>1 && tab[i / 2]< tab[i])
	{
		swap(tab[i], tab[i / 2]);
		i = i / 2;
	}
}

void Kopiec::kopiec_pop()
{
	if (n == 0)
	{
		return;
	}

	swap(tab[1], tab[n]);
	n--;
	int *t = new int[n + 1];

	for (int j = 1; j <= n; j++)
	{
		t[j] = tab[j];
	}

	delete tab;
	tab = t;

	int i = 1;

	while ((2 * i <= n && tab[i]< tab[2 * i]) || (2 * i + 1 <= n && tab[i]< tab[2 * i + 1])) // indeks z którego bêdê korzysta³ mieœci sie w tablicy
	{
		if (2 * i + 1 <= n && tab[2 * i]<tab[2 * i + 1])
		{
			swap(tab[i], tab[2 * i + 1]);
			i = 2 * i + 1;
		}
		else
		{
			swap(tab[i], tab[2 * i]);
			i *= 2;
		}
	}
}

bool Kopiec::kopiec_search(int szukane)
{
	for (int i = 1; i <= n; i++)
	{
		if (tab[i] == szukane)
		{
			return true;
		}

	}
	return false;
}

void Kopiec::kopiec_show()
{
	if (n == 0)
	{
		cout << "pusty" << endl;
	}
	else
	{
		cout << "Kopiec: " << endl;
		int wierz = 1;
		for (int i = 1; i <= n; i++)
		{
			cout << tab[i] << " ";
			if (i == wierz)
			{
				cout << endl;
				//cout << tab[i] << ", ";
				wierz = 2 * wierz + 1;
			}
		}
		cout << endl;
	}
}

void Kopiec::kopiec_test_push(int ilosc)
{
	int *randoms;
	double average = 0.0;

	Licznik licznik;

	double time;

	ofstream plik;

	string nazwa = "kopiec_push_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	for (int j = 0; j < 100; j++)
	{

		randoms = new int[ilosc + 1]; //tablica na wartosci losowe


		for (int i = 0; i<ilosc + 1; i++)
		{
			randoms[i] = rand();		////generowanie wartosci losowych
		}

		Kopiec kopiec;

		for (int i = 0; i<ilosc; i++)
		{
			kopiec.kopiec_push(randoms[i]); //tworzymy kopiec o zadanym rozmiarze
		}

		licznik.StartCounter();
		kopiec.kopiec_push(randoms[ilosc]);	//umieszczamy na kopcu jeszcze jeden element
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete[] randoms;

	}
	
	average = average / 100.0;
	plik << endl << "Czas sredni: " << average <<" mikro sekund."<< endl;
	plik.close();			
}

void Kopiec::kopiec_test_pop(int ilosc)
{
	int *randoms;
	double sum = 0.0;

	Licznik licznik;

	double time;

	ofstream plik;

	string nazwa = "kopiec_pop_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	for (int j = 0; j < 100; j++)
	{

		randoms = new int[ilosc]; //tablica na wartosci losowe


		for (int i = 0; i<ilosc; i++)
		{
			randoms[i] = rand();		////generowanie wartosci losowych
		}

		Kopiec kopiec;

		for (int i = 0; i<ilosc; i++)
		{
			kopiec.kopiec_push(randoms[i]); //tworzymy kopiec o zadanym rozmiarze
		}
		licznik.StartCounter();//licznik start
		kopiec.kopiec_pop();	//zdejmujemy z kopca element na kopcu jeszcze jeden element
		time = licznik.GetCounter();
		plik << time << endl;//licznik stop (odczytujemy wartosc)
		sum += time;
		delete[] randoms;

	}

	double average = sum / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Kopiec::kopiec_test_search(int ilosc, int szukana)
{
	int *randoms;
	double sum = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "kopiec_search_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	for (int j = 0; j < 100; j++)
	{

		randoms = new int[ilosc]; //tablica na wartosci losowe

		for (int i = 0; i<ilosc; i++)
		{
			randoms[i] = rand();		////generowanie wartosci losowych
		}

		Kopiec kopiec;
		
		for (int i = 0; i<ilosc; i++)
		{
			kopiec.kopiec_push(randoms[i]); //tworzymy kopiec o zadanym rozmiarze
		}

		licznik.StartCounter();//licznik start
		kopiec.kopiec_search(szukana);	//szukamy w kopcu elementu szukana
		time = licznik.GetCounter();
		plik << time << endl;//licznik stop (odczytujemy wartosc)
		sum += time;
		delete[] randoms;
	}

	double average = sum / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();

	
}































