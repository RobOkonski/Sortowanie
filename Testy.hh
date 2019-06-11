/*
 * Testy.hh
 *
 *  Created on: 15 mar 2019
 *      Author: Robert
 */

#ifndef TESTY_HH_
#define TESTY_HH_

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

#include "Algorytmy_sortujace.hh"
#include "Tablice.hh"
#include "ZapisDoPliku.hh"

//funkcja wykonuje zadany test
template<typename T,int ilosc_tablic,int rozmiar_tablic>
void WykonajTest(std::string algorytm,const int procent_posortowania)
{
	double wyniki[ilosc_tablic];//tablica na wyniki sortowan pojedynczych tablic
	double suma_czasow=0;
	std::chrono::duration<double> czas;
	Tablica<T,ilosc_tablic,rozmiar_tablic> Tab(procent_posortowania); //tworzymy i alokujemy zadana ilosc tablic

	for(int i=0;i<ilosc_tablic;++i)
	{
		if(algorytm=="Introsort")
		{
			auto start=std::chrono::system_clock::now();
			Introsort(Tab[i],rozmiar_tablic,(int)floor(2*log2(rozmiar_tablic)));
			auto stop=std::chrono::system_clock::now();
			czas = stop-start;
		}
		else if(algorytm=="Mergesort")
		{
			T* pom=new T[rozmiar_tablic];
			auto start=std::chrono::system_clock::now();
			Mergesort(Tab[i],pom,0,rozmiar_tablic-1);
			auto stop=std::chrono::system_clock::now();
			czas = stop-start;
		}
		else if(algorytm=="Quicksort")
		{
			auto start=std::chrono::system_clock::now();
			Quicksort(Tab[i],0,rozmiar_tablic-1);
			auto stop=std::chrono::system_clock::now();
			czas = stop-start;
		}
		else
		{
			std::cerr << "!!! NIEWLASCIWY ALGORYTM SORTOWANIA !!!" << std::endl << std::endl;
			exit(EXIT_FAILURE);
		}
		wyniki[i]=czas.count();//obliczamy czas sortowania jednej tablicy
		suma_czasow+=wyniki[i];//suma dla wszystkich tablic
	}
	ZapiszWynikSumy(suma_czasow,ilosc_tablic,rozmiar_tablic,algorytm,procent_posortowania);//zapisujemy wynik
}

#endif /* TESTY_HH_ */
