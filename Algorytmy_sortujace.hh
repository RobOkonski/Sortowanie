/*
 * Algorytmy_sortujace.hh
 *
 *  Created on: 8 mar 2019
 *      Author: Robert
 */

#ifndef ALGORYTMY_SORTUJACE_HH_
#define ALGORYTMY_SORTUJACE_HH_

#include <iostream>

//funkcja zamienia ze sob¹ miejscem 2 obiekty
template<typename T>
void Zamien(T* tab,int i,int j)
{
	T temp=tab[i];
	tab[i]=tab[j];
	tab[j]=temp;
}

//funkcja dzieli tablice wzglêdem wybranej osi (po lewj mniesze po prawej wieksze)
template<typename T>
int Podziel(T* tab,int lewy,int prawy)
{
	int i=(lewy+prawy)/2;
	T os=tab[i];
	tab[i]=tab[prawy];
	int j=lewy;

	for(int k=lewy;k<prawy;++k) //wrzucamy mniejsze od osi na poczatek tablicy
	{							//i zamieniamy miejscem os z pierwszym wieszym od niej
		if(tab[k]<os)
		{
			Zamien(tab,k,j);
			++j;
		}
	}
	tab[prawy]=tab[j];
	tab[j]=os; //os wraca na odpowiednie dla niej miejsce

	return j; //zwracamy index osi
}

//sortowanie szybkie
template<typename T>
void Quicksort(T* tab,int lewy,int prawy)
{
	if(lewy<prawy)
	{
		int os=Podziel(tab,lewy,prawy);
		Quicksort(tab,lewy,os-1);
		Quicksort(tab,os+1,prawy);
	}
}


//scalanie podtablic w jedn¹ posortowana
template<typename T>
void Scal(T* tab,T* pom,int lewy,int srodek,int prawy)
{
	int i=lewy;
	int j=srodek+1;

	for(int i=lewy;i<=prawy;++i)//przepisanie tablicy na pomocnicza
	{
		pom[i]=tab[i];
	}

	for(int k=lewy;k<=prawy;++k)//porownywanie najmniejszych z 2 podtablic i wstawianie do koncowej wartosci najmniejszej
	{
		if(i<=srodek)
		{
			if(j<=prawy)
			{
				if(pom[j]<pom[i])
				{
					tab[k]=pom[j++];
				}
				else
				{
					tab[k]=pom[i++];
				}
			}
			else
			{
				tab[k]=pom[i++];
			}
		}
		else
		{
			tab[k]=pom[j++];
		}
	}
}

//sortowanie przez scalanie
template<typename T>
void Mergesort(T* tab,T* pom,int lewy,int prawy)
{
	if(lewy<prawy)
	{
		int srodek=(prawy+lewy)/2;

		Mergesort(tab,pom,lewy,srodek);
		Mergesort(tab,pom,srodek+1,prawy);

		Scal(tab,pom,lewy,srodek,prawy);
	}
}

//tworzenie kopca (przywracanie wlasciwosci kopca)
template<typename T>
void Utworz_kopiec(T* tab,int rozmiar,int i)
{
	int najwieksza;

	while(i<rozmiar/2)
	{	//szukamy najwiekszej by przeniesc w gore
		najwieksza=2*i+1;
		if(najwieksza+1<rozmiar&&tab[najwieksza+1]>tab[najwieksza])
		{
			najwieksza=najwieksza+1;
		}
		if(tab[i]<tab[najwieksza])
		{
			Zamien(tab,i,najwieksza);
		}
		else
		{
			break;
		}
		i=najwieksza;
	}
}

//sortowanie przez kopcowanie (kopiec maksymalny - korzen jest najwiekszy)
template<typename T>
void Heapsort(T* tab,int rozmiar)
{
	int i;

	for (i=(rozmiar-1)/2;i>=0;--i)
		Utworz_kopiec(tab,rozmiar,i);
	for (i = rozmiar - 1; i>=0; --i)
	{
		Zamien(tab,0,i);        //zamiana ostatniego z korzeniem
		Utworz_kopiec(tab,i,0); //tworzenie kopca maksymalnego ale o mniejszym rozmiarze bo ostatnia napewno najwieksza po zamianie
	}
}

//sortowanie introspektywne
template<typename T>
void Introsort(T *tab,int rozmiar,int M) //M - zlozonosc obliczeniowa
{
	int i;

	if(M == 0)//jak wykorzystalismy z³ozonosc na rekurencje to wtedy heapsort
	{
		Heapsort(tab,rozmiar);
		return;
	}

	i=Podziel(tab,0,rozmiar-1);//os podzialu

	if(i>0)
	{
		Introsort(tab,i,M-1);
	}
	if(rozmiar - 1 - i>0)
	{
		Introsort(tab+i+1,rozmiar-1-i,M-1);
	}
}

#endif /* ALGORYTMY_SORTUJACE_HH_ */
