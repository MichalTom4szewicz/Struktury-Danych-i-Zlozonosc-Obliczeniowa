#include "stdafx.h"
#include "Graf.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <Windows.h>
#include <queue>
#include <math.h>
#include <functional>

using namespace std;
struct edge;
struct top;

struct Graf::edge
{
	int numer;
	int przed_numer;
	int waga;
	int odl = 999999999;

	bool operator<(edge const &other) const
	{
		return odl < other.odl;
	}

	bool operator>(edge const &other) const
	{
		return odl > other.odl;
	}
};

struct Graf::top //numer wierzcholka do ktorego rpowadzi krawedz o wadze
{
	int numer;
	int waga;
	int przed_numer;
	int odl=999999999;


	
	bool operator<(top const &other) const
	{
		return odl < other.odl;
	}

	bool operator>(top const &other) const
	{
		return odl > other.odl;
	}
};

bool is_in(int liczba, vector<int> tab)
{
	for (int i = 0; i<tab.size(); i++)
	{
		if (tab[i] == liczba)
		{

			//cout << "jeeeest" << endl;
			return true;
		}
	}

	//cout << "nie" << endl;
	return false;
}

//void mini(vector<top> t)
//{
//	top mi;
//	mi.waga = t[0].waga;
//	mi.numer = t[0].numer;
//
//	for (int i = 1; i < t.size(); i++)
//	{
//		if (t[i].waga < min.waga)
//		{
//			min.waga = t[i].waga;
//			min.numer = t[i].numer;
//		}
//	}
//	//return min;
//}


void print(vector<int> tab)
{
	for (int i = 0; i < tab.size(); i++)
	{
		cout << tab[i] << " ";
	}
	cout << endl;
}

Graf::Graf(int kraw, int wierz)
{
	krawedzie = kraw;
	wierzcholki = wierz;

	tab = new int *[wierz];//macierz incydencji
	for (int i = 0; i < wierz; i++)
	{
		tab[i] = new int[kraw];
	}

	lista = new vector<top>[wierz];
}


Graf::~Graf()
{
	for (int i = 0; i < wierzcholki; i++)//usuwamy macierz incydencji
	{
		delete[] tab[i];
	}
	delete[] tab;

	delete[] lista;
}

int Graf::wi()////zwraca ilosc wierzcholkow
{
	return wierzcholki;
}

int Graf::kr()//zwraca ilosc krawedzi
{
	return krawedzie;
}

bool Graf::czy_spojny()
{
	int suma = 0;

	for (int i = 0; i < wierzcholki; i++)
	{
		for (int j = 0; j < krawedzie; j++)
		{
			if (tab[i][j] != 0)
			{
				suma = 1;
			}
		}
		if (suma == 0)
		{
			cout << endl << "Graf nie jest spojny!" << endl;
			return false;
		}
		suma = 0;
	}
	cout << endl << "Graf(nieskierowany) jest spojny" << endl;
	return true;
}

bool Graf::spoj() //sprawdzamy czy graf SKIEROWANY jest spojny
{
	queue<int> kolejka;
	int aktualny;
	vector<int> odwiedzone;


	//odwiedzone.push_back(0);

	for (int iter = 0; iter < wierzcholki; iter++)
	{
		while (!kolejka.empty())
		{
			kolejka.pop();
		}
		odwiedzone.clear();
		aktualny = iter;

		odwiedzone.push_back(aktualny);


		kolejka.push(aktualny);
		while (!kolejka.empty())
		{
			aktualny = kolejka.front();
			kolejka.pop();
			for (int i = 0; i < lista[aktualny].size(); i++)
			{
				if (is_in(lista[aktualny][i].numer, odwiedzone) == false)
				{
					kolejka.push(lista[aktualny][i].numer);
					odwiedzone.push_back(lista[aktualny][i].numer);
					//cout << "lel " << lista[aktualny][i].numer << endl;
				}
			}

			//if (is_in(aktualny, odwiedzone) == false)
			//{
			odwiedzone.push_back(aktualny);
			//}

		}



		for (int i = 0; i < wierzcholki; i++)
		{
			if (is_in(i, odwiedzone) == false)
			{
				//cout <<endl<< "niespojny!" << endl;
				return false;
			}

		}
	}

	//cout << "spojny" << endl;
	return true;
}


void Graf::printmi()
{
	cout << "Macierz incydencji grafu (" << wierzcholki << ", " << krawedzie << ")" << endl << endl;
	cout << "      "; //7 spacji dla 2 cyfrowych, 6 spacji dla 1 cyfrowych
	for (int i = 0; i < krawedzie; i++)
	{
		cout << i << "    "; //5 spacji dla 2 cyfrowych; 4 spacje dla 1 cyfrowych
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < wierzcholki; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < krawedzie; j++)
		{
			cout << "   " << tab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Graf::printmiwwag()
{
	cout << "Macierz incydencji grafu (" << wierzcholki << ", " << krawedzie << ") wraz z wagami poszczegolnych krawedzi" << endl << endl;
	cout << "      ";
	for (int i = 0; i < krawedzie; i++)
	{
		cout << i << "    ";
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < wierzcholki; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < krawedzie; j++)
		{
			cout << "   " << tab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << "wagi: ";
	for (int i = 0; i < krawedzie; i++)
	{
		//cout << edges[i] << "    ";
		cout << edges[i].numer << "|" << edges[i].waga << "    ";
	}
	cout << endl << endl;
}


void Graf::insert(int i, int j, int x)
{
	tab[j][i] = x;
}


void Graf::toedg(int numer, int pwierz, int wierz, int waga)
{
	edge *tmp = new edge;
	tmp->numer = wierz;
	tmp->przed_numer = pwierz;
	tmp->waga = waga;
	edges.push_back(*tmp);
	delete tmp;

}

//void Graf::toedg(int waga)
//{
//	edges.push_back(waga);
//
//}

void Graf::printlist()
{
	cout << "Lista nastepnikow grafu (" << wierzcholki << ", " << krawedzie << ")" << " (waga|wierzcholek)" << endl << endl;
	for (int i = 0; i < wierzcholki; i++)
	{
		cout << "V" << i << " --> ";
		for (int j = 0; j < lista[i].size(); j++)
		{
			cout << lista[i][j].waga << "|" << lista[i][j].numer << ", ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Graf::ins_list(int a, int poz, int przed, int wag) //dodaje element do tablicy list - wskazujemy ktorej tablicy
{
	top *tmp = new top;
	tmp->numer = poz;
	tmp->waga = wag;
	tmp->przed_numer = przed;
	lista[a].push_back(*tmp);
	delete tmp;

}

void Graf::dodaj_krawedz(int pocz, int kon, int wag)
{
	krawedzie++;

	int **tmp = new int *[wierzcholki];//macierz incydencji
	for (int i = 0; i < wierzcholki; i++)
	{
		tmp[i] = new int[krawedzie];
	}

	for (int i = 0; i < wierzcholki; i++)
	{
		for (int j = 0; j < krawedzie; j++)
		{
			tmp[i][j] = 0;

		}
	}

	tmp[pocz][krawedzie - 1] = 1;
	tmp[kon][krawedzie - 1] = 9;

	for (int i = 0; i < wierzcholki; i++)//kopiowanie
	{
		for (int j = 0; j < krawedzie - 1; j++)
		{
			tmp[i][j] = tab[i][j];
		}
	}

	for (int i = 0; i < wierzcholki; i++)//usuwamy macierz incydencji
	{
		delete[] tab[i];
	}
	delete[] tab;

	tab = tmp;

	edge *tmp1 = new edge;
	tmp1->numer = krawedzie - 1;
	tmp1->waga = wag;
	edges.push_back(*tmp1);
	delete tmp1;

	//edges.push_back(wag);

	this->ins_list(pocz, kon, pocz, wag);

}



void Graf::przebuduj_graf(int wierz, int kra)
{
	int **tmp = new int *[wierz];// tymczasowa macierz incydencji
	for (int i = 0; i < wierz; i++)
	{
		tmp[i] = new int[kra];
	}

	for (int i = 0; i < wierz; i++)// wypelniamy zerami macierz inc
	{
		for (int j = 0; j < kra; j++)
		{
			tmp[i][j] = 0;
		}
	}

	for (int i = 0; i < kra; i++) //generujemy nowy wektor wag
	{
		edge temp;
		temp.numer = -1;
		temp.waga = rand() % 9 + 1;

		edges.push_back(temp);
	}


	for (int j = 0; j < kra; j++) //generujemy dane macierzy
	{
		int jed = rand() % wierz;
		tmp[jed][j] = 1;
		int min_jed = rand() % wierz;
		while (min_jed == jed)
		{
			min_jed = rand() % wierz;
		}

		tmp[min_jed][j] = 9;
	}

	int *odwiedzone = new int[wierz];	//ten blok odpowiada za to aby graf byl spojny - sprawdzamy, czy w kazdym wierzu macierzy incydencji znajduje sie przynajmniej 1 element;]
	//int *odwiedzone2 = new int[wierz];
	//vector <int> odwiedzone;
	int suma = 0;
	int suma2 = 0;
	int ma1 = 0;//sprawdza spojnosc do skierowanego
	int ma9 = 0;
	//int ee = 1; //ee==1 - graf nie jest spojny
	while (suma<wierz || suma2<wierz )//suma < wierz)
	{
		for (int i = 0; i < wierz; i++)
		{
			odwiedzone[i] = 0;
			//odwiedzone2[i] = 0;
		}
		ma1 = 0;
		ma9 = 0;
		
		suma2 = 0;
		suma = 0;
		for (int i = 0; i < wierz; i++)
		{
			for (int j = 0; j < kra; j++)
			{
				tmp[i][j] = 0;
			}
		}

		for (int j = 0; j < kra; j++)
		{
			int jed = rand() % wierz;
			odwiedzone[jed] = 1;
			tmp[jed][j] = 1;
			int min_jed = rand() % wierz;
			while (min_jed == jed)
			{
				min_jed = rand() % wierz;
			}
			odwiedzone[min_jed] = 1;

			tmp[min_jed][j] = 9;


		}
		for (int i = 0; i < wierz; i++)
		{
			suma += odwiedzone[i];
		}
		///////testowe
		for (int i = 0; i < wierz; i++)
		{
			for (int j = 0; j < kra; j++)
			{
				if (tmp[i][j] == 1)
				{
					ma1 = 1;
				}
				if (tmp[i][j] == 9)
				{
					ma9 = 1;
				}
			}
			if (ma9 == 1 && ma1 == 1)
			{
				suma2++;
			}
			ma1 = 0;
			ma9 = 0;
		}
	}


	for (int i = 0; i < wierzcholki; i++)//usuwamy stara macierz incydencji
	{
		delete[] tab[i];
	}
	//delete[] tab;

	tab = tmp;

	for (int i = 0; i < wierzcholki; i++)//czyscimy liste nastepnikow
	{
		lista[i].clear();
	}

	wierzcholki = wierz;
	krawedzie = kra;

	edges.clear();	//czyscimy wektor wag

	vector<top> *te = new vector<top>[wierz];
	lista = te;

	//for (int i = 0; i < krawedzie; i++) //generujemy nowy wektor wag
	//{
	//	edges.push_back(rand()%9 + 1);
	//}

	for (int i = 0; i < krawedzie; i++) //generujemy nowy wektor wag
	{
		edge temp;
		temp.numer = -1;
		temp.waga = rand() % 9 + 1;

		edges.push_back(temp);
	}

	for (int i = 0; i < wierzcholki; i++)
	{
		for (int j = 0; j < krawedzie; j++)
		{
			if (tab[i][j] == 9)
			{
				edges[j].numer = i;
			}
			if (tab[i][j] == 1)
			{
				edges[j].przed_numer = i;
			}
		}
	}

}

void Graf::przebuduj(int wierz, int kra) //zmienia rozmair i wypelnia zerami macierz; czyœcitablice wag(staje sie pusta) oraz czyœsi liste nastepnikow
{
	int **tmp = new int *[wierz];//tymczasowa macierz incydencji
	for (int i = 0; i < wierz; i++)
	{
		tmp[i] = new int[kra];
	}

	for (int i = 0; i < wierz; i++) //zerujemy macierz incydencji
	{
		for (int j = 0; j < kra; j++)
		{
			tmp[i][j] = 0;
		}
	}

	for (int i = 0; i < wierzcholki; i++)//usuwamy macierz incydencji    ///ewentualne krawedzie
	{
		delete[] tab[i];
	}
	//delete[] tab;

	tab = tmp;

	for (int i = 0; i < wierzcholki; i++)//czyscimy liste nastepnikow
	{
		lista[i].clear();
	}
	delete[] lista;

	wierzcholki = wierz;
	krawedzie = kra;

	vector<top> *te = new vector<top>[wierz];
	lista = te;

	edges.clear(); //czyscimy wektor wag
}

void Graf::bu_lis()//buduj liste
{
	int pocz = 0;
	int kon = 0;

	for (int i = 0; i < krawedzie; i++)
	{
		top tp;
		for (int j = 0; j < wierzcholki; j++)
		{
			if (tab[j][i] == 1)
			{
				pocz = j;

			}
			if (tab[j][i] == 9)
			{
				kon = j;
			}
		}
		tp.numer = kon;
		tp.przed_numer = pocz;
		tp.waga = edges[i].waga;
		lista[pocz].push_back(tp);
	}
}

double Graf::gestosc(int wi, int kra)
{
	return 2.0*kra / (wi*wi - wi);
}

void Graf::nowy_graf(int wierz, int gest)
{
	double ges = gest / 100.0;
	if (wierz <= 2 || ges <= 0 || ges > 1)
	{
		cout << "Nieprawidlowe dane" << endl;
		return;
	}

	double liczba;

	liczba = (ges*(wierz*wierz - wierz)) / 2;
	liczba = floor(liczba);

	if (liczba < wierz - 1)
	{
		cout << "Blad! graf nie jest spojny!" << endl;
		return;
	}

	this->przebuduj_graf(wierz, liczba);
	this->bu_lis();

	while (this->spoj() == false)
	{
		//this->przebuduj(wierz, liczba);
		this->przebuduj_graf(wierz, liczba);
		this->bu_lis();
	}


}


void Graf::prim_mac()
{
	if (!this->czy_spojny())
	{
		cout << "Ten algorytm dziala tylko dla grafu spojnego! Aktualny graf nie spelnia wymagania spojnosci." << endl;
		return;
	}

	int **t = new int *[wierzcholki - 1];//tablica gdzie beda przechowywane krawedzie
	for (int i = 0; i < wierzcholki; i++)
	{
		t[i] = new int[3];
	}

	//wierzcholkiem poczatkowym bedzie wierzcholek 0;

	vector<int> do_odwiedzenia;
	for (int i = 0; i < wierzcholki; i++)
	{
		do_odwiedzenia.push_back(i);
	}
	do_odwiedzenia.erase(remove(do_odwiedzenia.begin(), do_odwiedzenia.end(), 0), do_odwiedzenia.end());

	vector<int> kraw;
	vector <int> sasiedzi;
	int aktualny = 0; //wierzchoek ktory aktualnie rozpatrujemy

	int licznik = 0;

	vector<int> zuzyte;//zuzyte krawedzie
	vector<int> wzuzyte;//zuzyte wierzcholki
	


	int uzyte = 0;//krawedz
	int wuzyte = 0;//wierzcholek
	int suzyte = 0;//sasiad

	int min = 9999;
	int sasiad;
	int usuw;


	for (int iter = 0; iter <wierzcholki-1; iter++)//wierzcholki-1
	{

		for (int i = 0; i < krawedzie; i++)//znajdujemy krawedzie, ktore wychodza z naszego poddrzewa
		{
			if (tab[aktualny][i] != 0 && is_in(i, zuzyte) == false)
			{
				
				kraw.push_back(i);
				
				//uzyte = 0;
			}
		}


		for (int i = 0; i < kraw.size(); i++) //znajdujemy sasiednie wierzcholki od naszego poddrzewa
		{
			for (int j = 0; j < wierzcholki; j++)
			{
				if (tab[j][kraw[i]] != 0 && j != aktualny && is_in(j, wzuzyte) == false)
				{
					sasiedzi.push_back(j);
				}
			}
		}

		wzuzyte.push_back(aktualny);


		for (int i = 0; i < kraw.size(); i++) //szukamy krawedzi o minimalnej wadze posrod tych dostepnych w tablicy do_siasiadow
		{
			if (edges[kraw[i]].waga < min && !( is_in(edges[kraw[i]].przed_numer, wzuzyte) && is_in(edges[kraw[i]].numer, wzuzyte)))///
			{
				min = edges[kraw[i]].waga;


				usuw = i;
			}
		}
		

		if (is_in(edges[kraw[usuw]].przed_numer, wzuzyte) )
		{
			sasiad = edges[kraw[usuw]].numer;
		}
		else
		{
			sasiad = edges[kraw[usuw]].przed_numer;
		}

		zuzyte.push_back(kraw[usuw]);

		//cout << kraw[usuw]<< endl;

		sasiedzi.erase(remove(sasiedzi.begin(), sasiedzi.end(), sasiad), sasiedzi.end());
		kraw.erase(remove(kraw.begin(), kraw.end(), kraw[usuw]), kraw.end());
		

		for (int i = 0; i < edges.size(); i++)
		{
			if (edges[i].waga == min && edges[i].numer == sasiad && is_in(sasiad, wzuzyte) ==false)//////
			{
				aktualny = edges[i].przed_numer;
			}
			else
			{
				if (edges[i].waga == min && edges[i].przed_numer == sasiad && is_in(sasiad, wzuzyte) == false)////
				{
					aktualny = edges[i].numer;
				}
			}
		}

		t[licznik][0] = edges[zuzyte[zuzyte.size() - 1]].przed_numer;
		t[licznik][1] = edges[zuzyte[zuzyte.size() - 1]].numer;
		t[licznik][2] = edges[zuzyte[zuzyte.size() - 1]].waga;

		aktualny = sasiad;
		licznik++;
		min = 999;
	}

	cout <<endl<< "WYNIKOWA tablica krawedzi" << endl;

	for (int i = 0; i < wierzcholki - 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	licznik = 0;
	cout << endl << endl << endl << endl;

	//for(int i=0; i<edges.)
}

void Graf::prim_lis()
{
	if (!this->czy_spojny())
	{
		cout << "Ten algorytm dziala tylko dla grafu spojnego! Aktualny graf nie spelnia wymagania spojnosci." << endl;
		return;
	}

	int **t = new int *[wierzcholki - 1];//tablica gdzie beda przechowywane krawedzie;tablica wynikowa
	for (int i = 0; i < wierzcholki; i++)
	{
		t[i] = new int[3];
	}

	int aktualny = 0;



	vector <top> sasiedzi; //mamy od razu ich wagi i poprzednikow
	vector <int> wykorzystane;


	int licz_kraw = 0;


	top min;
	min.waga = 999;//warto resetowac hmmmmmm


	int licznik = 0;

	//cout << "----------------------------------------------------" << endl;



	for (int iter = 0; iter < wierzcholki-1; iter++) //wierzcholki - 1
	{
		for (int i = 0; i < lista[aktualny].size(); i++)
		{
			if (is_in(lista[aktualny][i].numer, wykorzystane) == false)
			{
				top temp;
				temp.waga = lista[aktualny][i].waga;
				temp.numer = lista[aktualny][i].numer;
				temp.przed_numer = aktualny;
				sasiedzi.push_back(temp);
			}
			
		}

		for (int i = 0; i < wierzcholki; i++)
		{
			for (int j = 0; j < lista[i].size(); j++)
			{
				if (i != aktualny && (lista[i][j].numer == aktualny || lista[i][j].przed_numer == aktualny) )
				{
					top tmp;
					tmp.numer = i;
					tmp.waga = lista[i][j].waga;
					tmp.przed_numer = aktualny;

					sasiedzi.push_back(tmp);
				}
			}
		}




		for (int i = 0; i < sasiedzi.size(); i++)
		{
			if (sasiedzi[i].waga < min.waga && is_in(sasiedzi[i].numer, wykorzystane)==false)
			{
					min.numer = sasiedzi[i].numer;
					min.przed_numer = sasiedzi[i].przed_numer;
					min.waga = sasiedzi[i].waga;
			}
		}

		wykorzystane.push_back(aktualny);

		if (min.numer == aktualny)
		{
			wykorzystane.push_back(min.przed_numer);
		}
		else
		{
			wykorzystane.push_back(min.numer);
		}


		int a, b, c;
		for (int i = 0; i < sasiedzi.size(); i++)
		{
			if (sasiedzi[i].numer == min.numer && sasiedzi[i].waga == min.waga && sasiedzi[i].przed_numer == min.przed_numer)
			{
				
				//cout << "usunieto " << sasiedzi[i].przed_numer <<"|"<< sasiedzi[i].numer<< endl;
				a = sasiedzi[i].przed_numer;
				b = sasiedzi[i].numer;
				c = sasiedzi[i].waga;
				sasiedzi.erase(sasiedzi.begin() + i);
			}
		}
		//////////////////////////////////////////////////// tu co s zmienic jak wybieramy tego aktualnego
		

		for (int i = 0; i < sasiedzi.size(); i++) //tu sie jebie
		{
			if (sasiedzi[i].numer == min.numer && sasiedzi[i].waga == min.waga)
			{
				aktualny = sasiedzi[i].przed_numer;
			}
			if (sasiedzi[i].przed_numer == min.numer && sasiedzi[i].waga == min.waga)
			{
				aktualny = sasiedzi[i].numer;
			}

		}

		t[licznik][0] = a; //tu cos zmienic
		t[licznik][1] = b; 
		t[licznik][2] = c;


		aktualny = min.numer;
		



		min.waga = 999;
		licznik++;

		
	}






	cout << endl << endl << "WYNIKOWA tablica krawedzi" << endl;///////////////////wyswietlanie wynikow
	for (int i = 0; i < wierzcholki - 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << t[i][j] << " ";
		}
		cout << endl;
	}

	cout << "----------------------------------------------------" << endl;
	cout << endl << endl << endl;

	
}

void Graf::dijkstra_lis(int beg, int end)
{
	if (!this->czy_spojny())
	{
		cout << "Ten algorytm dziala tylko dla grafu spojnego! Aktualny graf nie spelnia wymagania spojnosci." << endl;
		return;
	}

	int niesk = 999999;

	int aktualny = beg;
	
	vector<int> koszty;
	for (int i = 0; i < wierzcholki; i++)
	{
		koszty.push_back(niesk);
	}
	koszty[beg] = 0;

	priority_queue <top, vector <top>, greater <top>> kol; 

	for (int i = 0; i < lista[beg].size(); i++)
	{
		kol.push(lista[beg][i]);
		koszty[lista[beg][i].numer] = lista[beg][i].waga;
	}



	while (! kol.empty())
	{
		
		//zuzyte.push_back(aktualny);
		aktualny = kol.top().numer;
		//cout << "aktualny " << aktualny << endl;

		kol.pop();
		//cout << aktualny << endl;
		for (int i = 0; i < lista[aktualny].size(); i++)
		{

			if (koszty[aktualny] + lista[aktualny][i].waga < koszty[lista[aktualny][i].numer])
			{
				koszty[lista[aktualny][i].numer] = koszty[aktualny] + lista[aktualny][i].waga;

				lista[aktualny][i].odl = koszty[aktualny] + lista[aktualny][i].waga;


				kol.push(lista[aktualny][i]);				
			}
		}
	}

	cout <<endl<< "a tutaj koszty" << endl;
	for (int i = 0; i < wierzcholki; i++)
	{
		cout << koszty[i] << " ";
	}
	cout << endl << "Minimaly koszt drogi z wierzcholka " << beg << " do " << end << " wynosi " << koszty[end] << endl;

}

void Graf::dijkstra_mac(int beg, int end)
{

	if (!this->czy_spojny())
	{
		cout << "Ten algorytm dziala tylko dla grafu spojnego! Aktualny graf nie spelnia wymagania spojnosci." << endl;
		return;
	}

	int niesk = 999999;

	int aktualny = beg;

	vector<int> koszty;
	for (int i = 0; i < wierzcholki; i++)
	{
		koszty.push_back(niesk);
	}
	koszty[beg] = 0;

	priority_queue <edge, vector <edge>, greater <edge>> kol;

	for (int i = 0; i < lista[beg].size(); i++)
	{	
		edge tmp;
		tmp.numer = lista[beg][i].numer;
		tmp.przed_numer = beg;
		tmp.waga = lista[beg][i].waga;
		tmp.odl = 999999999;
		kol.push(tmp);
		//cout << tmp.przed_numer << " " << tmp.numer << " " << tmp.waga << endl;
		koszty[tmp.numer] = tmp.waga;
	}
	


	vector<edge> sas;
	
	vector <int> kra;

	while (!kol.empty())
	{

		aktualny = kol.top().numer;
		//cout << "aktualny " << aktualny << endl;
		kol.pop();
		

		for (int i = 0; i < krawedzie; i++)
		{
			if (tab[aktualny][i] == 1)
			{
				kra.push_back(i);
			}
		}

		for (int i = 0; i < wierzcholki; i++)
		{
			for (int j = 0; j < kra.size(); j++)
			{
				if (tab[i][kra[j]] == 9)
				{
					edge tmp;
					tmp.przed_numer = aktualny;//aktualny
					tmp.numer = i;
					
					tmp.waga = edges[kra[j]].waga;
					tmp.odl - edges[kra[j]].odl;	
					sas.push_back(tmp);
				}
			}
		}



		for (int i = 0; i < sas.size(); i++)
		{
			if (koszty[aktualny] + sas[i].waga < koszty[sas[i].numer])
			{
				koszty[sas[i].numer] = koszty[aktualny] + sas[i].waga;

				edges[kra[i]].odl = koszty[aktualny] + sas[i].waga;

				kol.push(sas[i]);
			}
		}

		sas.clear();
		kra.clear();

	}

	cout << endl << "a tutaj koszty" << endl;
	for (int i = 0; i < wierzcholki; i++)
	{
		cout << koszty[i] << " ";
	}
	cout << endl << "Minimaly koszt drogi z wierzcholka " << beg << " do " << end << " wynosi " << koszty[end] << endl;

}
