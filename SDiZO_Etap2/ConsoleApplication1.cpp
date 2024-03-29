#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
#include <vector>
#include "Graf.h"
#include <fstream>
#include "Lista.h"
#include <list>
#include <cmath>
#include <conio.h>
#include <queue>
#include "Licznik.h"

using namespace std;

int needed_edg(int wi, int pro)
{
	double ges = pro / 100.0;

	double liczba;

	liczba = (ges*(wi*wi - wi)) / 2;
	liczba = floor(liczba);
	int a = liczba;
	return a;
}

double gestosc(int wi, int kra)
{
	return 2.0*kra/(wi*wi - wi);
}

struct edge
{
	int numer;

	int waga;	
};
struct top
{
	int numer=0;
	int waga=0;
	int przed_numer = 0;
};

int main()
{
	srand(time(NULL));
	cout << "Hello world!" << endl << endl;

	int k;
	int w;
	
	int tmp1;
	int tmp2;
	int tmp3;

	bool run = true;////////////
	bool run1 = true;
	bool run2 = true;
	char r1;/////////////////
	char r2;
	char r3;

	ofstream file;
	fstream plik;

	Graf*graf = new Graf(7, 6); //kraw wierz
	graf->nowy_graf(6, 75); //wierz, %

	Licznik stoper;
	double czas=0.0;
	int gestosc;
	int wierki;
	int poc;
	int kon;

	int p;
	int ko;
	int blad = 0;
	int blad1 = 0;
	int blad2 = 0;
	string nazwa_pliku;

	//cout << "pierwszy graf" << endl;
	//graf->bu_lis();

	while (run)
	{
		cout << endl;
		cout << "----- MENU -----" << endl;
		cout << "1 - wczytaj z pliku." << endl;
		cout << "2 - wygeneruj losowo." << endl;
		cout << "3 - aby wyjsc." << endl;
		cout << "8 - wyswiettl obie reprezentacje grafu" << endl;
		cout << "9 - problem MST" << endl;
		cout << "0 - problem najkrotszej sciezki" << endl;
		cout << endl << "Uwaga wszystkie wartosci, ktore wpisuje urzytkownik powinny byc lcizbami calkowitymi!" << endl;

		r1 = getchar(); //toupper(getchar());
		//getchar();

		switch (r1)
		{
		case '1':

			system("cls");
			cout << endl;
			cout << "Plik z danymi powinien znajdowac sie w tym samym olderze co program." << endl;
			cout << "Podaj nazwe pliku z ktorego chcesz wczytac dane (z rozszerzeniem .txt): ";
			cin >> nazwa_pliku;
			//_getch();
			//Sleep(100);
			plik.open(nazwa_pliku.c_str());

			if (!plik.good())
			{
				cout << endl << "Nie ma takiego pliku!" << endl << endl;;
				break;	//wyjscie do menu glownego
			}


			//plik.open("graf.txt");

			plik >> k;
			plik >> w;

			graf->przebuduj(w, k);

			for (int i = 0; i < k; i++)// tworzy macierz incydencji
			{
				blad = 0;
				plik >> tmp1;
				plik >> tmp2;
				plik >> tmp3;

				if (tmp1 < 0 || tmp1 >= w)
				{
					cout << "Blad - dane nie spelniaja wymagan poprawnosci." << endl;
					blad = 1;
				}
				if (tmp2 < 0 || tmp2 >= w)
				{
					cout << "Blad - dane nie spelniaja wymagan poprawnosci." << endl;
					blad = 1;
				}
				if (tmp3 <=0 )
				{
					cout << "Blad - dane nie spelniaja wymagan poprawnosci." << endl;
					blad = 1;
				}

				if (blad == 0)
				{
					graf->insert(i, tmp1, 1);
					graf->insert(i, tmp2, 9);
					graf->toedg(i, tmp1, tmp2, tmp3);

					graf->ins_list(tmp1, tmp2, tmp1, tmp3); //tworzy liste nastepnikow
				}

				
			}


			plik.close();
			if (blad == 0)
			{
				graf->printmiwwag();
				graf->printlist();

				graf->czy_spojny();
			}
			else
			{
				graf->nowy_graf(6, 75); //wierz, %
			}

			

			break;
			
		case '2':
			system("cls");
			blad1 = 0;
			cout <<endl<< "Generowany jest graf typu skladowa silnie spójna. Ozanacza to, ze powstaly graf posiada wlasnosc nastepujaca: z kazdego wierzcholka istnieje droga do wszystkich pozostalych wierzcholkow. Wiaze sie to z pewnymi ograniczeniami." << endl;
			cout << "Zaleca sie ilosc wierzcholkow wieksza niz 3 przy danych ograniczneiach:" << endl;
			cout << "4 wierzcholki; gestosc >= 99%" << endl;
			cout << "5 wierzcholkow; gestosc >= 75%" << endl;
			cout << "6 wierzcholkow; gestosc >= 50%" << endl;
			cout << "7 wierzcholkow; gestosc >= 40%" << endl;
			cout << "8 wierzcholkow i wiecej; gestosc >=25%" << endl;

			cout << endl << " Podaj ilosc wierzcholkow i gestosc grafu ";
			cin >> wierki;
			cin >> gestosc;
			if (wierki < 4 || (gestosc<25 || gestosc > 100 ))
			{
				cout << "Za malo wierzcholkow lub niepoprawna gestosc" << endl;

			}
			else
			{
				if (wierki == 4 && gestosc < 99)
				{
					cout << "Niewystarczajaco duza gestosc" << endl; blad1 = 1;
				}
				if (wierki == 5 && gestosc < 75)
				{
					cout << "Niewystarczajaco duza gestosc" << endl; blad1 = 1;
				}
				if (wierki == 6 && gestosc < 50)
				{
					cout << "Niewystarczajaco duza gestosc" << endl; blad1 = 1;
				}
				if (wierki == 7 && gestosc < 40)
				{
					cout << "Niewystarczajaco duza gestosc" << endl; blad1 = 1;
				}

				if (blad1 == 0)
				{
					graf->nowy_graf(wierki, gestosc);

					graf->printmiwwag();
					graf->printlist();
				}
			}

			
			break;

		case '3':
			system("cls");
			cout << "bye bye" << endl;
			system("pause");
			return 0;
			break;

		

		case '8':
			system("cls");
			graf->printmiwwag();
			graf->printlist();
			system("pause");

			/*double czas;
			stoper.StartCounter();
			Sleep(1000);
			czas = stoper.GetCounter();
			cout << "czas " << czas << endl;*/
			break;

		case '9':
			system("cls");

			run1 = true;

			//system("cls");
			while (run1)
			{
				
				cout << "1 - algorytm prima dla macierzy incydencji" << endl;
				cout << "2 - algorytm Prima dla listy nastepnikow" << endl;
				cout << "3 - exit" << endl;

				r2 = getchar();
				//Sleep(300);
				//_getch();
				//getchar();

				switch (r2)
				{
				case'1':
					graf->prim_mac();
					system("pause");
					break;

				case '2':
					graf->prim_lis();
					system("pause");
					break;

				case '3':
					run1 = false;
					break;

				default:
					//_getch();
					system("cls");
					break;
				}
			}
			
			break;

		case '0':
			
			system("cls");
			run2 = true;
			//system("cls");
			while (run2)
			{
				//system("cls");
				cout << "1 - algorytm dijkstry dla macierzy incydencji" << endl;
				cout << "2 - algorytm dijkstry dla listy nastepnikow" << endl;
				cout << "3 - exit" << endl;
				//system("cls");

				r3 = getchar();
				//Sleep(300);
				//getchar();

				switch (r3)
				{
				case'1':
					blad2 = 0;
					cout << "Podaj poczatkowy i koncowy wierzcholek ";
					
					cin >> poc;
					cin >> kon;
					//getchar();

					if (poc <0 || poc >graf->wi() - 1)
					{
						blad2 = 1;
					}
					if (kon <0 || kon >graf->wi() - 1)
					{
						blad2 = 1;
					}
					if (blad2 == 0)
					{
						graf->dijkstra_mac(poc, kon);
						system("pause");
						break;
					}
					else
					{
						cout << "Wprowadzono niepoprawne dane" << endl;
						system("pause");
						break;
					}

					//break;

				case '2':
					
					blad2 = 0;
					cout << "Podaj poczatkowy i koncowy wierzcholek ";
					cin >> poc;
					cin >> kon;
					//getchar();

					if (poc <0 || poc >graf->wi() - 1)
					{
						blad2 = 1;
					}
					if (kon <0 || kon >graf->wi() - 1)
					{
						blad2 = 1;
					}
					if (blad2 == 0)
					{
						graf->dijkstra_lis(poc, kon);
						system("pause");
						break;
					}
					else
					{
						cout << "Wprowadzono niepoprawne dane" << endl;
						system("pause");
						break;
					}

					//break;

				case '3':
					run2 = false;
					break;

				default:

					//run2 = false;
					//_getch();
					system("cls");
					break;
				}
				//system("cls");
			}


			break;

		default:
			//cout << "Zly guzik" << endl;
			//system("cls");
			//_getch();
			break;
		}
		system("cls");
	}

	

	//system("Pause");
    //return 0;
}

