#pragma once

#include "Lista.h"
#include <vector>
#include <list>


using namespace std;

class Graf
{

public: /// //////////////////////////////////////// do zakomentarzowania
	struct edge;
	struct top;

	vector <edge> edges;
	//vector <int> edges;
	int wierzcholki;
	int krawedzie;
	int **tab;
	vector <top> *lista;




public:
	Graf(int , int);
	~Graf();

	int wi();//zwraca islosc wierzcholkow w grafie
	int kr();//zwraca ilosc krawedzi w grafie

	bool czy_spojny(); //sprawdza spojnosc grafu nieskierowanego
	bool spoj(); //sprawdza spojnosc grafu skierowanego

	void printmi();//macierz incydencji
	void printmiwwag();//macierz incydencji z wagami
	void insert(int, int, int);//macierz incydencji

	void toedg(int, int, int, int);
	//void toedg(int);

	void printlist(); //lista nastepnikow
	void ins_list(int, int,int, int); //lista nastepnikow

	void dodaj_krawedz(int, int, int);/////////////////////////////////////////////////////////////////////// nie wiem czy to potrzebne... xD

	void przebuduj_graf(int, int);

	double gestosc(int, int);
	void nowy_graf(int, int);
	void przebuduj(int, int);
	void bu_lis();
	
	void prim_mac();
	void prim_lis();

	void dijkstra_lis(int, int);
	void dijkstra_mac(int, int);
	
	//void zmien rozmiar //tego samego grafu
	//void usun_krawedz
	//void usun_wierzcholek

};

