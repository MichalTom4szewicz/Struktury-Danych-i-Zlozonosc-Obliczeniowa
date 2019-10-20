#include "stdafx.h"
#include "Menu.h"
#include "Kopiec.h"
#include "Licznik.h"
#include "Lista.h"
#include "Tablica.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::program()
{

	srand(time(NULL));
	cout << "STRUKTURY DANYCH I ZLOZONOSC OBLICZENIOWA - PROJEKT" << endl;
	cout << endl << "Autor: Michal Tomaszewicz" << endl;
	cout << "Prowadzacy projekt: Dr inz. Dariusz Banasiak" << endl << endl;

	cout << "Ten program spelnia 2 zadania. 1: generuje pliki tekstowe z wynikami (iloscia czasu potrzebnego na wykonanie poszczegolnych operacji na roznych strukturach danych) eksperymentow.";
	cout << "2: umozliwa przetestowanie funkcjonalnosci poszczegolnych struktur." << endl << endl;;


	bool running = true;	//glowny program
	bool running_1 = true;	//testowanie case1
	bool running_2 = true; //testowanie case2
	bool running_3 = true; //testowanie case3
	bool run = true;
	bool first_time = true;

	Licznik co;	//licznik podajacy cza trwania generacji plikow wynikowych
	Kopiec kopiec;	// case 1
	Lista lista(1);	// case 1
	Tablica tablica(1);	// case 1

	Kopiec *k;	//case 2
	Lista *lis;	//case 2
	Tablica *tab;// case 2

	fstream plik;
	string nazwa_pliku;
	int wielkosc;
	int *dane;

	//zmienne sterujace poszczegolnymi menu
	char ster1;
	char ster2;
	char ster31;
	char ster32;
	char ster33;

	int element;
	int pozycja;

	while (running)
	{
		cout << "-----MENU-----" << endl;
		cout << "(nacisnij)" << endl;
		cout << "1	- aby wygenerowac wyniki ekserymentow." << endl;
		cout << "2	- aby przetestowac struktury." << endl;
		cout << "dowolny inny przycisk aby wyjsc z programu" << endl;
		cout << endl << "Wybieram ";

		ster1 = _getch();
		switch (ster1)
		{
		case '1':

			cout << "Operacje dla Kopca binarnego" << endl;
			cout << "licze..." << endl;

			co.StartCounter();

			kopiec.kopiec_test_push(2000);
			kopiec.kopiec_test_push(5000);
			kopiec.kopiec_test_push(10000);
			kopiec.kopiec_test_push(20000);
			cout << endl << "wykonano push dla 2; 5; 10; 20 tys. elementow" << endl;


			kopiec.kopiec_test_pop(2000);
			kopiec.kopiec_test_pop(5000);
			kopiec.kopiec_test_pop(10000);
			kopiec.kopiec_test_pop(20000);
			cout << endl << "wykonano pop dla 2; 5; 10; 20 tys. elementow" << endl;


			kopiec.kopiec_test_search(2000, 42);
			kopiec.kopiec_test_search(5000, 42);
			kopiec.kopiec_test_search(10000, 42);
			kopiec.kopiec_test_search(20000, 42);
			cout << endl << "wykonano search dla 2; 5; 10; 20 tys. elementow" << endl;


			cout << "Operacje dla Listu dwukierunkowej" << endl;
			cout << "licze..." << endl;


			lista.lista_test_push_beg(2000);
			lista.lista_test_push_beg(5000);
			lista.lista_test_push_beg(10000);
			lista.lista_test_push_beg(20000);
			cout << endl << "wykonano push beg dla 2; 5; 10; 20 tys. elementow" << endl;

			lista.lista_test_push_end(2000);
			lista.lista_test_push_end(5000);
			lista.lista_test_push_end(10000);
			lista.lista_test_push_end(20000);
			cout << endl << "wykonano push end dla 2; 5; 10; 20 tys. elementow" << endl;

			lista.lista_test_push_mid(2000);
			lista.lista_test_push_mid(5000);
			lista.lista_test_push_mid(10000);
			lista.lista_test_push_mid(20000);
			cout << endl << "wykonano push mid dla 2; 5; 10; 20 tys. elementow" << endl;

			lista.lista_test_pop_beg(2000);
			lista.lista_test_pop_beg(5000);
			lista.lista_test_pop_beg(10000);
			lista.lista_test_pop_beg(20000);
			cout << endl << "wykonano push beg dla 2; 5; 10; 20 tys. elementow" << endl;

			lista.lista_test_pop_end(2000);
			lista.lista_test_pop_end(5000);
			lista.lista_test_pop_end(10000);
			lista.lista_test_pop_end(20000);
			cout << endl << "wykonano push end dla 2; 5; 10; 20 tys. elementow" << endl;

			lista.lista_test_pop_mid(2000);
			lista.lista_test_pop_mid(5000);
			lista.lista_test_pop_mid(10000);
			lista.lista_test_pop_mid(20000);
			cout << endl << "wykonano push mid dla 2; 5; 10; 20 tys. elementow" << endl;

			lista.lista_test_search(2000, 42);
			lista.lista_test_search(5000, 42);
			lista.lista_test_search(10000, 42);
			lista.lista_test_search(20000, 42);
			cout << endl << "wykonano search dla 2; 5; 10; 20 tys. elementow" << endl;


			cout << "Operacje dla tablicy" << endl;
			cout << "licze..." << endl;


			tablica.tab_test_push_beg(5000);
			tablica.tab_test_push_beg(10000);
			tablica.tab_test_push_beg(20000);
			cout << endl << "wykonano push beg dla 2; 5; 10; 20 tys. elementow" << endl;

			tablica.tab_test_push_end(2000);
			tablica.tab_test_push_end(5000);
			tablica.tab_test_push_end(10000);
			tablica.tab_test_push_end(20000);
			cout << endl << "wykonano push end dla 2; 5; 10; 20 tys. elementow" << endl;

			tablica.tab_test_push_mid(2000);
			tablica.tab_test_push_mid(5000);
			tablica.tab_test_push_mid(10000);
			tablica.tab_test_push_mid(20000);
			cout << endl << "wykonano push mid dla 2; 5; 10; 20 tys. elementow" << endl;

			tablica.tab_test_pop_beg(2000);
			tablica.tab_test_pop_beg(5000);
			tablica.tab_test_pop_beg(10000);
			tablica.tab_test_pop_beg(20000);
			cout << endl << "wykonano pop beg dla 2; 5; 10; 20 tys. elementow" << endl;

			tablica.tab_test_pop_end(2000);
			tablica.tab_test_pop_end(5000);
			tablica.tab_test_pop_end(10000);
			tablica.tab_test_pop_end(20000);
			cout << endl << "wykonano pop end dla 2; 5; 10; 20 tys. elementow" << endl;

			tablica.tab_test_pop_mid(2000);
			tablica.tab_test_pop_mid(5000);
			tablica.tab_test_pop_mid(10000);
			tablica.tab_test_pop_mid(20000);
			cout << endl << "wykonano pop mid dla 2; 5; 10; 20 tys. elementow" << endl;

			tablica.tab_test_search(2000, 42);
			tablica.tab_test_search(5000, 42);
			tablica.tab_test_search(10000, 42);
			tablica.tab_test_search(20000, 42);
			cout << endl << "wykonano search dla 2; 5; 10; 20 tys. elementow" << endl;

			cout << "Zakonczono generowanie plikow tekstowych ";
			cout << "w czasie: " << co.GetCounter() / 1000000 << " sekund." << endl << endl;

			Sleep(6000);
			system("cls");
			cout << "Wygenerowano" << endl;

			break;

		case '2':

			system("cls");
			cout << endl;
			cout << "Plik z danymi powinien znajdowac sie w tym samym olderze co program." << endl;
			cout << "Podaj nazwe pliku z ktorego chcesz wczytac dane (z rozszerzeniem .txt): ";
			cin >> nazwa_pliku;
			plik.open(nazwa_pliku.c_str());

			if (!plik.good())
			{
				cout << endl << "Nie ma takiego pliku!" << endl << endl;;
				break;	//wyjscie do menu glownego
			}


			plik >> wielkosc;

			dane = new int[wielkosc];

			for (int i = 0; i < wielkosc; i++)
			{
				plik >> dane[i];
			}
			plik.close();

			//////////////// tworzymy obiekty do testowania ich funkcji
			k = new Kopiec;
			for (int i = 0; i < wielkosc; i++)
			{
				k->kopiec_push(dane[i]);
			}

			lis = new Lista(wielkosc);
			lis->list_fill(dane);

			tab = new Tablica(wielkosc);
			tab->tab_fill(dane);

			cout << endl << "Pomyslnie wczytano dane." << endl << endl;
			//first_time = false;

			run = true;
			while (run)
			{
				cout << "Jaka strukture chcesz przetestowac?" << endl << "(nacisnij)" << endl;
				cout << "1	- tablice" << endl;
				cout << "2	- liste" << endl;
				cout << "3	- kopiec" << endl;
				cout << "	- dowolny klawisz aby wyjsc z tego menu" << endl;


				cout << "Wybieram ";

				ster2 = _getch();

				system("cls");

				switch (ster2)
				{
				case '1':
					running_1 = true;
					while (running_1)
					{
						tab->tab_show();

						cout << "Poszczegolne funkcje: " << endl << "(nacisnij)" << endl;
						cout << "1	- aby dodac podany element na poczatek tablicy." << endl;
						cout << "2	- aby dodac podany element na koniec tablicy" << endl;
						cout << "3	- aby dodac podany element na podane miejsce w tablicy" << endl;
						cout << "4	- aby usunac element z poczatku tablicy" << endl;
						cout << "5	- abyusunac element z konca tablicy" << endl;
						cout << "6	- aby usunac element z podanego miejsca w tablicy" << endl;
						cout << "7	- aby wyszukac podany element w tablicy" << endl;
						cout << "dowolny inny klawisza by wyjsc z tego menu" << endl;

						cout << endl << "Wybieram ";

						ster31 = _getch();
						cout << endl;
						switch (ster31)
						{
						case '1':
							cout << endl << "Podaj element jaki chesz dodac do tablicy: ";
							cin >> element;
							tab->tab_push_beg(element);
							system("cls");
							cout << "dodano" << endl;
							break;

						case '2':
							cout << endl << "Podaj element jaki chesz dodac do tablicy: ";
							cin >> element;
							tab->tab_push_end(element);
							system("cls");
							cout << "dodano" << endl;
							break;

						case '3':
							cout << endl << "Podaj element jaki chesz dodac do tablicy: ";
							cin >> element;
							cout << "Podaj pozycje an ktorej chcesz umiescic element.(nie mniejsza niz 0 oraz nie wieksza niz " << tab->n - 1 << ")" << endl;
							cin >> pozycja;
							tab->tab_push_mid(element, pozycja);
							system("cls");
							cout << "dodano" << endl;
							break;
						case '4':
							tab->tab_pop_beg();
							system("cls");
							cout << "usunieto" << endl;
							break;
						case '5':
							tab->tab_pop_end();
							system("cls");
							cout << "usunieto" << endl;
							break;
						case '6':

							cout << "Podaj pozycje z ktorej chcesz usunac element.(nie mniejsza niz 0 oraz nie wieksza niz " << tab->n - 1 << ")" << endl;
							cin >> pozycja;
							tab->tab_pop_mid(pozycja);
							system("cls");
							cout << "usunieto" << endl;
							break;
						case '7':
							cout << "Podaj element ktory chesz znalezc w tablicy ";
							cin >> element;
							system("cls");
							if (tab->tab_search(element))
							{
								cout << "Znaleziono" << endl;
							}
							else cout << "Brak elementu" << endl;
							break;

						default:
							cout << endl << "Powrot" << endl << endl;
							running_1 = false;
							break;

						}

					}

					break;

				case '2':

					running_2 = true;
					while (running_2)
					{
						lis->list_show();

						cout << "Poszczegolne funkcje: " << endl << "(nacisnij)" << endl;
						cout << "1	- aby dodac podany element na poczatek listy." << endl;
						cout << "2	- aby dodac podany element na koniec listy" << endl;
						cout << "3	- aby dodac podany element na podane miejsce w liscie" << endl;
						cout << "4	- aby usunac element z poczatku listy" << endl;
						cout << "5	- abyusunac element z konca listy" << endl;
						cout << "6	- aby usunac element z podanego miejsca w liscie" << endl;
						cout << "7	- aby wyszukac podany element w liscie" << endl;
						cout << "dowolny inny klawisza by wyjsc z tego menu" << endl;

						cout << endl << "Wybieram ";

						ster32 = _getch();
						cout << endl;
						switch (ster32)
						{
						case '1':
							cout << endl << "Podaj element jaki chesz dodac do listy: ";
							cin >> element;
							lis->list_push_beg(element);
							system("cls");
							cout << "dodano" << endl;
							break;

						case '2':
							cout << endl << "Podaj element jaki chesz dodac do listy: ";
							cin >> element;
							lis->list_push_end(element);
							system("cls");
							cout << "dodano" << endl;
							break;

						case '3':
							cout << endl << "Podaj element jaki chesz dodac do listy: ";
							cin >> element;
							cout << "Podaj pozycje an ktorej chcesz umiescic element.(nie mniejsza niz 0 oraz nie wieksza niz " << lis->n - 1 << ")" << endl;
							cin >> pozycja;
							lis->list_push_mid(element, pozycja);
							system("cls");
							cout << "dodano" << endl;
							break;
						case '4':
							lis->list_pop_beg();
							system("cls");
							cout << "usunieto" << endl;
							break;
						case '5':
							lis->list_pop_end();
							system("cls");
							cout << "usunieto" << endl;
							break;
						case '6':

							cout << "Podaj pozycje z ktorej chcesz usunac element.(nie mniejsza niz 0 oraz nie wieksza niz " << lis->n - 1 << ")" << endl;
							cin >> pozycja;
							lis->list_pop_mid(pozycja);
							system("cls");
							cout << "usunieto" << endl;
							break;
						case '7':
							cout << "Podaj element ktory chesz znalezc w liscie ";
							cin >> element;
							system("cls");
							if (lis->list_search(element))
							{
								cout << "Znaleziono" << endl;
							}
							else cout << "Brak elementu" << endl;
							break;

						default:
							cout << endl << "Powrot" << endl << endl;
							running_2 = false;
							break;
						}
					}
					break;

				case '3':

					running_3 = true;
					while (running_3)
					{
						k->kopiec_show();

						cout << "Poszczegolne funkcje: " << endl << "(nacisnij)" << endl;
						cout << "1	- aby dodac podany element do kopca" << endl;
						cout << "2	- aby usunac podany element z kopca" << endl;
						cout << "3	- aby wyszukac podany element w kopcu" << endl;
						cout << "dowolny inny klawisza by wyjsc z tego menu" << endl;

						cout << endl << "Wybieram ";

						ster33 = _getch();
						cout << endl;

						switch (ster33)
						{
						case '1':

							cout << endl << "Podaj element jaki chesz dodac do kopca: ";
							cin >> element;
							k->kopiec_push(element);
							system("cls");
							cout << "dodano" << endl;
							break;

						case '2':
							k->kopiec_pop();
							system("cls");
							cout << "usunieto" << endl;
							break;

							break;

						case '3':

							cout << "Podaj element ktory chesz znalezc w kopcu ";
							cin >> element;
							system("cls");
							if (k->kopiec_search(element))
							{
								cout << "Znaleziono" << endl;
							}
							else cout << "Brak elementu" << endl;
							break;

						default:

							cout << endl << "Powrot" << endl << endl;
							running_3 = false;
							break;
						}

					}

					break;

				default:
					cout << "Nie wybrano zadnej z powyzszych struktur." << endl;
					run = false;

					delete k;
					delete lis;
					delete tab;
					delete[] dane;
					break;

				}
			}
			break;

		default:
			running = false;
			break;
		}
	}

	cout << "Zamknieto program." << endl << endl;

}
