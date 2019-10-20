#include "stdafx.h"
#include "Licznik.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Licznik::Licznik()
{
	PCFreq = 0.0;
	CounterStart = 0;
}


Licznik::~Licznik()
{
}

void Licznik::StartCounter()
{
	LARGE_INTEGER li;

	if (!QueryPerformanceFrequency(&li))
	{
		cout << "QueryPerformanceFrequency failed!\n";
	}

	PCFreq = double(li.QuadPart) / 1000.0;
	QueryPerformanceCounter(&li);

	CounterStart = li.QuadPart;
}

double Licznik::GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double((li.QuadPart - CounterStart) / PCFreq)*1000;
}