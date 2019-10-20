#include "stdafx.h"
#include "Lista.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;



Lista::Lista()
{
	n = 0;

	Element *tmp = new Element;

	tmp->prev = NULL;
	glowa = tmp;
	ogon = tmp;
	ogon->next = NULL;

	/*if (rozmiar == 1)
	{
		ogon->next = NULL;
	}*/

	/*if (rozmiar>2)
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
*/

}


Lista::~Lista()
{
	Element *tmp;
	if (n > 1)
		tmp = glowa->next;
	else
		tmp = glowa;
	if (glowa != NULL) delete glowa;

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

	while (tmp != NULL)
	{
		cout << tmp->liczba << ", ";
		tmp = tmp->next;
	}
	cout << "NULL" << endl;
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

void Lista::list_push_end(int x)
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
		if (poz == 0 || poz == n - 1)
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
		if (poz == 0 || poz == n - 1)
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
