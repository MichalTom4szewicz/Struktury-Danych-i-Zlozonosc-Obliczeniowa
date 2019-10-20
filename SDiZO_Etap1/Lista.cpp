#include "stdafx.h"
#include "Lista.h"
#include "Licznik.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;


Lista::Lista(int rozmiar)
{
	n = rozmiar;

	Element *tmp = new Element;

	tmp->prev = NULL;
	glowa = tmp;
	ogon = tmp;

	if (rozmiar == 1)
	{
		ogon->next = NULL;
	}

	if (rozmiar>2)
	{
		for (int i = 0; i<rozmiar - 2; i++)
		{
			tmp = new Element;

			tmp->prev = ogon;
			ogon->next = tmp;
			ogon = tmp;
		}
	}


	if (rozmiar>1)
	{
		tmp = new Element;
		tmp->prev = ogon;
		ogon->next = tmp;
		ogon = tmp;
		ogon->next = NULL;
	}


}


Lista::~Lista()
{
	Element *tmp;
	if (n > 1)
		tmp = glowa->next;
	else
		tmp = glowa;
	if(glowa!=NULL) delete glowa;

	for (int i = 0; i<n - 2; i++)
	{
		Element *next = tmp->next;	

		delete tmp;
		tmp = next;
	}

}

void Lista::list_fill()
{
	Element *tmp = glowa;

	while (tmp != NULL)
	{
		tmp->liczba = rand();
		tmp = tmp->next;
	}
}

void Lista::list_fill(int* tablica)
{
	Element *tmp = glowa;
	int i = 0;

	while (tmp != NULL)
	{
		tmp->liczba = tablica[i];
		tmp = tmp->next;
		i++;
	}
}

void Lista::list_show()
{
	Element *tmp = glowa;

	cout << "Lista: ";

	while (tmp != NULL)
	{
		cout << tmp->liczba << ", ";
		tmp = tmp->next;
	}
}

bool Lista::list_search(int x)
{
	Element *tmp = glowa;

	while (tmp != NULL)
	{
		if (tmp->liczba == x)
		{			
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void Lista::list_push_beg(int x)
{
	Element *tmp = new Element;

	if (n > 0)
	{
		tmp->next = glowa;
		glowa->prev = tmp;
		tmp->liczba = x;
		tmp->prev = NULL;
		glowa = tmp;
		n++;
	}
	else
	{
		tmp->prev = NULL;
		tmp->next = NULL;
		tmp->liczba = x;
		glowa = tmp;
		ogon = tmp;
		n++;
	}
}

void Lista::list_push_end( int x)
{
	Element *tmp = new Element;

	if (n > 0)
	{
		tmp->prev = ogon;
		ogon->next = tmp;
		tmp->liczba = x;
		tmp->next = NULL;
		ogon = tmp;
		n++;
	}
	else
	{
		tmp->prev = NULL;
		tmp->next = NULL;
		tmp->liczba = x;
		glowa = tmp;
		ogon = tmp;
		n++;
	}
}

void Lista::list_pop_end()
{
	if (n == 0)
	{
		return;
	}

	Element *tmp;

	if (n > 1)
	{
		tmp = ogon->prev;
		tmp->next = NULL;
		ogon->prev = NULL;
		delete ogon;
		ogon = tmp;
		n--;
	}
	else
	{
		tmp = ogon;
		delete ogon;
		ogon = NULL;
		glowa = NULL;

	}
}

void Lista::list_pop_beg()
{
	if (n == 0)
	{
		return;
	}

	Element *tmp;

	if (n > 1)
	{
		tmp = glowa->next;
		tmp->prev = NULL;
		glowa->next = NULL;

		delete glowa;
		glowa = tmp;
		n--;
	}
	else
	{
		tmp = glowa;
		delete glowa;
		glowa = NULL;
		ogon = NULL;
		n--;
	}
	
}

void Lista::list_push_mid(int x, int poz)//pozycja licznona tablicowo liczymy od zera
{
	Element *nowy = new Element;
	nowy->liczba = x;
	Element *tmp;
	Element *tmp1;

	if (n == 0)
	{
		list_push_beg(x);
		return;
	}
		


	if (poz <= n && poz >= 0)
	{
		if (poz == 0 || poz == n-1)
		{
			if (poz == 0)
			{
				
			}
			else
			{
				list_push_end(x);
			}
		}
		else
		{
			tmp = glowa;
			for (int i = 0; i<poz - 1; i++)
			{
				tmp = tmp->next;
			}
			tmp1 = tmp->next;
			n++;
			tmp->next = nowy;
			nowy->prev = tmp;
			nowy->next = tmp1;
			tmp1->prev = nowy;
		}
	}
	else
	{
		cout << "Nie mozna" << endl;
	}
}

void Lista::list_pop_mid(int poz)
{
	if (n == 0)
	{
		return;
	}

	Element *tmp;
	Element *tmp1;

	if (poz <= n && poz >= 0)
	{
		if (poz == 0 || poz == n-1)
		{
			if (poz == 0)
			{
				list_pop_beg();
			}
			else
			{
				list_pop_end();
			}
		}
		else
		{
			tmp = glowa;
			for (int i = 0; i<poz - 1; i++)
			{
				tmp = tmp->next;
			}
			tmp1 = tmp->next->next;
			n--;

			tmp->next->next = NULL;
			tmp->next->prev = NULL;
			delete tmp->next;

			tmp->next = tmp1;
			tmp1->prev = tmp;
		}
	}
	else
	{
		cout << "Nie mozna" << endl;
	}
}

void Lista::lista_test_push_beg(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "lista_push_beg_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Lista *lista;

	int random;

	for (int j = 0; j < 100; j++)
	{

		lista = new Lista(ilosc);

		lista->list_fill();
		random = rand();
		
		licznik.StartCounter();
		lista->list_push_beg(random);	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time<< endl;
		average += time;
		delete lista;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Lista::lista_test_push_end(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "lista_push_end_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Lista *lista;

	int random;

	for (int j = 0; j < 100; j++)
	{

		lista = new Lista(ilosc);

		lista->list_fill();
		random = rand();

		licznik.StartCounter();
		lista->list_push_end(random);	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete lista;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Lista::lista_test_push_mid(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "lista_push_mid_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Lista *lista;

	int random;
	int rand_poz;

	for (int j = 0; j < 100; j++)
	{

		lista = new Lista(ilosc);

		lista->list_fill();
		random = rand();
		rand_poz = rand() % ilosc;
		licznik.StartCounter();
		lista->list_push_mid(random, rand_poz);	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete lista;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Lista::lista_test_pop_beg(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "lista_pop_beg_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Lista *lista;

	int random;

	for (int j = 0; j < 100; j++)
	{

		lista = new Lista(ilosc);

		lista->list_fill();

		licznik.StartCounter();
		lista->list_pop_beg();	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete lista;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Lista::lista_test_pop_end(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "lista_pop_end_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Lista *lista;

	int random;

	for (int j = 0; j < 100; j++)
	{

		lista = new Lista(ilosc);

		lista->list_fill();

		licznik.StartCounter();
		lista->list_pop_end();	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete lista;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Lista::lista_test_pop_mid(int ilosc)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "lista_pop_mid_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Lista *lista;

	int rand_poz;

	for (int j = 0; j < 100; j++)
	{

		lista = new Lista(ilosc);

		lista->list_fill();
		rand_poz = rand() % ilosc;
		licznik.StartCounter();
		lista->list_pop_mid(rand_poz);	// wstawiam liczbe
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete lista;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}

void Lista::lista_test_search(int ilosc, int szukana)
{
	double average = 0.0;

	Licznik licznik;
	double time;

	ofstream plik;

	string nazwa = "lista_search_" + to_string(ilosc) + ".txt";

	plik.open(nazwa.c_str());

	Lista *lista;

	for (int j = 0; j < 100; j++)
	{

		lista = new Lista(ilosc);

		lista->list_fill();
		licznik.StartCounter();
		lista->list_search(szukana);	// szukanie
		time = licznik.GetCounter();
		plik << time << endl;
		average += time;
		delete lista;
	}

	average = average / 100.0;
	plik << endl << "Czas sredni: " << average << " mikro sekund." << endl;
	plik.close();
}
