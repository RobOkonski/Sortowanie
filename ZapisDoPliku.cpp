/*
 * ZapisDoPliku.cpp
 *
 *  Created on: 16 mar 2019
 *      Author: Robert
 */

#include "ZapisDoPliku.hh"

//zapisuje wynik poszczególnych sortowañ testu(ka¿dy test oddzielny plik)
void ZapiszWynik(double* wyniki,double suma_czasow,int ilosc_tablic,int rozmiar_tablicy,std::string algorytm,int procent_posortowania)
{
	//tworzenie nazwy pliku i sciezki
	std::string sortowanie;
	if(procent_posortowania==-100)
	{
		sortowanie="OdwrotniePosortowane";
	}
	else if(procent_posortowania==0)
	{
		sortowanie="Losowe";
	}
	else if(procent_posortowania>0&&procent_posortowania<100)
	{
		std::string procent=std::to_string(procent_posortowania);
		sortowanie="Posortowane"+procent+"Procent";
	}
	else if(procent_posortowania==100)
	{
		sortowanie="Posortowane99,7Procent";
	}
	else
	{
		std::cerr << "!!! NIEWLASCIWY PROCENT POSORTOWANIA TABLICY !!!" << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string rozmiar=std::to_string(rozmiar_tablicy);
	std::string nazwa_pliku="D:\\Programy\\PAMSI_L_projekt1\\Wyniki"+algorytm+"Tablica"+rozmiar+sortowanie+".txt";
	const char *sciezka=nazwa_pliku.c_str();

	std::fstream plik;
	plik.open(sciezka,std::ios::out);

	if(plik.good())
	{
		plik << "Czasy" << std::endl;
		for(int i=0;i<ilosc_tablic;++i)
		{
			plik.precision(10);
			plik << wyniki[i] << std::endl;
		}
		plik << "Suma: " << suma_czasow << std::endl;
		plik.close();
	}
	else
	{
		std::cerr << "!!! PROBLEM Z DOSTEPEM DO PLIKU !!!" << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
}

//zapisuje w jednym pliku wyniki (suma czasow poszczegolnych sortowan) wszystkich wykonanych testów
void ZapiszWynikSumy(double suma_czasow,int ilosc_tablic,int rozmiar_tablicy,std::string algorytm,int procent_posortowania)
{
	std::string sciezka="D:\\Programy\\PAMSI_L_projekt1\\Wyniki.txt"; //sciezka stala

	//tworzenie zmiennej tekstowej opisujacej posortowanie tablicy
	std::string sortowanie;
	if(procent_posortowania==-100)
	{
		sortowanie="Odwrotnie";
	}
	else if(procent_posortowania==0)
	{
		sortowanie="Losowo";
	}
	else if(procent_posortowania>0&&procent_posortowania<100)
	{
		sortowanie=std::to_string(procent_posortowania);
	}
	else if(procent_posortowania==100)
	{
		sortowanie="99,7";
	}
	else
	{
		std::cerr << "!!! NIEWLASCIWY PROCENT POSORTOWANIA TABLICY !!!" << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}

	std::fstream plik;
	plik.open(sciezka,std::ios::out | std::ios::app);//nadpis pliku jak chce sie czysty to trzeba usunac stary

	if(plik.good())
	{
		plik << algorytm << " " << ilosc_tablic << " " << rozmiar_tablicy << " " << sortowanie << " " << suma_czasow << std::endl;
		plik.close();
	}
	else
	{
		std::cerr << "!!! PROBLEM Z DOSTEPEM DO PLIKU !!!" << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
}

//zapisuje nag³owek pliku(kompatybilne z funkcja ZapiszWynikSumy())
void ZapiszInfoDoPliku()
{
	std::string sciezka="D:\\Programy\\PAMSI_L_projekt1\\Wyniki.txt"; //stala sciezka

	std::fstream plik;
	plik.open(sciezka,std::ios::out | std::ios::app);

	if(plik.good())
	{
		plik << "Algorytm " << "Ilosc_Tablic " << "Rozmiar_Tablic " << "Procent_Posortowania " << "Suma_Czasow"<< std::endl;
	}
	else
	{
		std::cerr << "!!! PROBLEM Z DOSTEPEM DO PLIKU !!!" << std::endl << std::endl;
		exit(EXIT_FAILURE);
	}
}

