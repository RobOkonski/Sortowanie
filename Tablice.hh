/*
 * Tablice.hh
 *
 *  Created on: 15 mar 2019
 *      Author: Robert
 */

#ifndef TABLICE_HH_
#define TABLICE_HH_

#include <iostream>
#include <cstdlib>
#include <algorithm>

template<typename T,int ILOSC,int ROZMIAR>
class Tablica{

	T **Tab;

public:
	//konstruktor bezparametryczny (nieuzywany)
	Tablica()
	{
		Tab=new T*[ILOSC];
		for(int i=0;i<ILOSC;++i)
		{
			Tab[i]=new T[ROZMIAR];
			for(int j=0;j<ROZMIAR;++j)
			{
				Tab[i][j]=std::rand();
			}
		}
	}

	//konstruktor parametryczny za parametr procent posortowania (100=99,7%; -100=odwrotnie posortowane)
	//ze wzglêdu na fakt ze alokacja tablic nie jest uwzglêdniana w pomiarch to sortowanie tablic przed
	//wprowadzeniem do w³aœciwych algorytmów jest wykonane funkcj¹ sort() z biblioteki algorithm
	Tablica(int procent)
		{
			if(procent<100&&procent>=0)
			{
				int ilosc_elementow_do_posortowania=(int)(procent*ROZMIAR)/100;
				Tab=new T*[ILOSC];
				for(int i=0;i<ILOSC;++i)
				{
					Tab[i]=new T[ROZMIAR];
					for(int j=0;j<ROZMIAR;++j)
					{
						Tab[i][j]=std::rand();
					}
					std::sort(Tab[i],Tab[i]+ilosc_elementow_do_posortowania);
				}
			}
			else if(procent==-100)
			{
				Tab=new T*[ILOSC];
				for(int i=0;i<ILOSC;++i)
				{
					Tab[i]=new T[ROZMIAR];
					for(int j=0;j<ROZMIAR;++j)
					{
						Tab[i][j]=std::rand();
					}
					std::sort(Tab[i],Tab[i]+ROZMIAR,std::greater<int>());
				}
			}
			else if(procent==100)
			{
				int ilosc_elementow_do_posortowania=(int)(99.7*ROZMIAR)/100;
				Tab=new T*[ILOSC];
				for(int i=0;i<ILOSC;++i)
				{
					Tab[i]=new T[ROZMIAR];
					for(int j=0;j<ROZMIAR;++j)
					{
						Tab[i][j]=std::rand();
					}
					std::sort(Tab[i],Tab[i]+ilosc_elementow_do_posortowania);
				}
			}
			else
			{
				std::cerr << "!!! NIEWLASCIWY PROCENT POSORTOWANIA TABLICY !!!" << std::endl << std::endl;
				exit(EXIT_FAILURE);
			}

		}

	//destruktor
	~Tablica(){}

	//przeciazenie operatrora zwrotu tablicy 1D
	T* operator[](const unsigned int indeks);

	//przeciazenie operatora zwrotu konkretnego elementu
	T operator()(const unsigned int i, const unsigned int j);

	//wypisanie tablicy
	void Wypisz();

};

//przeciazenie operatrora zwrotu tablicy 1D
template<typename T,int ILOSC,int ROZMIAR>
T* Tablica<T,ILOSC,ROZMIAR>::operator[](const unsigned int indeks)
{
	if(indeks<ILOSC)           // jesli miescimy sie w zakresie
	    return Tab[indeks];    // zwroc zadane pole
	else                       // jesli nie zwroc blad i zakoncz program
	{
	    std::cerr << "!!! PRZEKROCZONO ZAKRES !!!" << std::endl << std::endl;
	    exit(EXIT_FAILURE);
	}
}

//przeciazenie operatora zwrotu konkretnego elementu
template<typename T,int ILOSC,int ROZMIAR>
T Tablica<T,ILOSC,ROZMIAR>::operator()(const unsigned int i, const unsigned int j)
{
	if(i<ILOSC&&j<ROZMIAR)         // jesli miescimy sie w zakresie
		    return Tab[i][j];      // zwroc zadane pole
		else                       // jesli nie zwroc blad i zakoncz program
		{
		    std::cerr << "!!! PRZEKROCZONO ZAKRES !!!" << std::endl << std::endl;
		    exit(EXIT_FAILURE);
		}
}

//wypisanie tablicy
template<typename T,int ILOSC,int ROZMIAR>
void Tablica<T,ILOSC,ROZMIAR>::Wypisz()
{
	for(int i=0;i<ILOSC;++i)
			{
				for(int j=0;j<ROZMIAR;++j)
				{
					std::cout<<Tab[i][j]<<", "; //zwroc zadane pole
				}
				std::cout<<std::endl;
			}
}

#endif /* TABLICE_HH_ */
