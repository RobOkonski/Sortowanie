//============================================================================
// Name        : PAMSI_L_projekt1.cpp
// Author      : Robert
// Version     :
// Copyright   : Your copyright notice
// Description : Algorytmy sortujace, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

#include "Testy.hh"
#include "Algorytmy_sortujace.hh"
#include "ZapisDoPliku.hh"
#include "Tablice.hh"

using namespace std;

#define ILOSC        100
#define ROZMIAR_10K  10000
#define ROZMIAR_50K  50000
#define ROZMIAR_100K 100000
#define ROZMIAR_500K 500000
#define ROZMIAR_1M   1000000

int main()
{
	//TESTER
	/*
	//int tab[10]={17,-2,8,9,-40,60,99,-5,20,1};
	//int pom[10];
	Tablica<int,1,10> tab(-100);
	for(int i=0;i<10;++i)
	{
		cout << tab(0,i)  << " ";
	}
	cout << endl;

	Quicksort(tab[0],0,9);

	for(int i=0;i<10;++i)
		{
			cout << tab(0,i)  << " ";
		}
		cout << endl;
	*/

	ZapiszInfoDoPliku();//tworzymy nag³owek w pliku

	//QUICKSORT
	WykonajTest<int,ILOSC,ROZMIAR_10K>("Quicksort",0);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Quicksort",0);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Quicksort",0);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Quicksort",0);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Quicksort",0);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Quicksort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Quicksort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Quicksort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Quicksort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Quicksort",-100);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Quicksort",25);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Quicksort",25);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Quicksort",25);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Quicksort",25);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Quicksort",25);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Quicksort",50);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Quicksort",50);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Quicksort",50);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Quicksort",50);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Quicksort",50);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Quicksort",75);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Quicksort",75);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Quicksort",75);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Quicksort",75);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Quicksort",75);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Quicksort",95);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Quicksort",95);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Quicksort",95);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Quicksort",95);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Quicksort",95);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Quicksort",99);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Quicksort",99);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Quicksort",99);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Quicksort",99);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Quicksort",99);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Quicksort",100);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Quicksort",100);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Quicksort",100);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Quicksort",100);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Quicksort",100);

	//MERGESORT
	WykonajTest<int,ILOSC,ROZMIAR_10K>("Mergesort",0);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Mergesort",0);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Mergesort",0);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Mergesort",0);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Mergesort",0);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Mergesort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Mergesort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Mergesort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Mergesort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Mergesort",-100);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Mergesort",25);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Mergesort",25);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Mergesort",25);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Mergesort",25);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Mergesort",25);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Mergesort",50);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Mergesort",50);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Mergesort",50);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Mergesort",50);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Mergesort",50);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Mergesort",75);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Mergesort",75);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Mergesort",75);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Mergesort",75);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Mergesort",75);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Mergesort",95);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Mergesort",95);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Mergesort",95);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Mergesort",95);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Mergesort",95);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Mergesort",99);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Mergesort",99);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Mergesort",99);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Mergesort",99);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Mergesort",99);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Mergesort",100);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Mergesort",100);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Mergesort",100);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Mergesort",100);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Mergesort",100);

	//INTROSORT
	WykonajTest<int,ILOSC,ROZMIAR_10K>("Introsort",0);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Introsort",0);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Introsort",0);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Introsort",0);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Introsort",0);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Introsort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Introsort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Introsort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Introsort",-100);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Introsort",-100);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Introsort",25);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Introsort",25);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Introsort",25);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Introsort",25);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Introsort",25);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Introsort",50);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Introsort",50);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Introsort",50);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Introsort",50);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Introsort",50);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Introsort",75);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Introsort",75);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Introsort",75);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Introsort",75);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Introsort",75);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Introsort",95);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Introsort",95);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Introsort",95);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Introsort",95);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Introsort",95);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Introsort",99);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Introsort",99);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Introsort",99);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Introsort",99);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Introsort",99);

	WykonajTest<int,ILOSC,ROZMIAR_10K>("Introsort",100);
	WykonajTest<int,ILOSC,ROZMIAR_50K>("Introsort",100);
	WykonajTest<int,ILOSC,ROZMIAR_100K>("Introsort",100);
	WykonajTest<int,ILOSC,ROZMIAR_500K>("Introsort",100);
	WykonajTest<int,ILOSC,ROZMIAR_1M>("Introsort",100);

	cout << "Koniec dzialania programu :) " << endl;
	return 0;
}
