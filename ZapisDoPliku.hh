/*
 * ZapisDoPliku.hh
 *
 *  Created on: 15 mar 2019
 *      Author: Robert
 */

#ifndef ZAPISDOPLIKU_HH_
#define ZAPISDOPLIKU_HH_

#include <iostream>
#include <string>
#include <fstream>

//zapisuje wynik poszczeg�lnych sortowa� testu(ka�dy test oddzielny plik)
void ZapiszWynik(double* wyniki,double suma_czasow,int ilosc_tablic,int rozmiar_tablicy,std::string algorytm,int procent_posortowania);

//zapisuje w jednym pliku wyniki (suma czasow poszczegolnych sortowan) wszystkich wykonanych test�w
void ZapiszWynikSumy(double suma_czasow,int ilosc_tablic,int rozmiar_tablicy,std::string algorytm,int procent_posortowania);

//zapisuje nag�owek pliku(kompatybilne z funkcja ZapiszWynikSumy())
void ZapiszInfoDoPliku();

#endif /* ZAPISDOPLIKU_HH_ */
