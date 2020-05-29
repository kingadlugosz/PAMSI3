#include "gra.h"

/********************************** Rysowanie planszy *******************************************
*																								*
*  Funkcja rysuje plansze do gry w terminalu zapisana w tablicy									*
*																								*
*///*********************************************************************************************
void rysuj_plansze(char* tab, int roz) {

	for (int i = 0; i < roz; i++) {
		for (int j = 0; j < roz; j++) {
			cout << " " << tab[i * roz + j] << " ";
			if ((j + 1) % roz)  cout << "|";										// po elementach œrodkowych wstawiamy |
			if (j + 1 == roz && i + 1 != roz) {										// aby po ostatnim elemêcie nie rysowa³o lini oddzielaj¹cej
				cout << endl;
				for (int a = 0; a < roz; a++) {
					cout << "---";
					if ((a + 1) % roz)  cout << "+";
				}
				cout << endl;
			}
		}
	}
}

/****************** Wyrysowana plansza z zaznaczonymi numerami pol planszy **********************
*																								*
*  Funkcja rysuje plansze z zaznaczonymi numerami pol, w celu uswiadomienia graczowi tego,      *
*  ktore pole odpowiada jakiemu numerowi                                                        *
*  																								*
*  tab- jaka tablice narysowac    																*
*  roz- rozmiar tej tablicy					        											*													*
*///*********************************************************************************************

void plansza_pola(char* tab, int roz) {
	int k = 1;

	cout << endl;
	cout << "Numery pol:" << endl << endl;
	for (int i = 0; i < roz; i++) {
		for (int j = 0; j < roz; j++) {
			cout << "  ";
			if (k < 10) { cout << "0"; };
			cout << k++ << tab[i * roz + j] << "  ";
			if ((j + 1) % roz)  cout << "|";								// po elementach œrodkowych wstawiamy |
			if (j + 1 == roz && i + 1 != roz) {								// aby po ostatnim elemêcie nie rysowa³o lini oddzielaj¹cej
				cout << endl;
				for (int a = 0; a < roz; a++) {
					cout << "-------";
					if ((a + 1) % roz)  cout << "+";
				}
				cout << endl;
			}
		}
	}
	cout << endl << endl << "Rozgrywka:" << endl << endl;
}

/***************************** Sprawdzanie czy jest remis ***************************************
*																								*
*  Funkcja sprawdza czy nie nastapil remis														*
*  																								*
*  tab- tablica ktora chcemy sprawdzic	   														*
*  roz- rozmiar tej tablicy																		*
*  znaki- liczba znakow koniecznych do wygrania													*
*																								*
*///*********************************************************************************************
bool remis(char* tab, int roz, int znaki) {

	for (int i = 0; i < roz * roz; i++) {										// Czyszczenie tablicy
		if (tab[i] == ' ') return false;
	}
	return true;

}

/**************************** Sprawdzanie czy nastapila wygrana**********************************
*																								*
*  Funkcja sprawdza czy jeden z graczy ( komputer lub gracz ) wygra³ rozgrywke					*
*  																								*
*  tab- tablica w ktorej sprawdzzamy wynik  													*
*  roz - rozmiar tej tablicy																	*
*  znaki - liczba znakow potrzebnych do wygrania												*
*  symbol - rozroznia kto wygral (gracz czy kompuer)											*
*																								*
*///*********************************************************************************************
bool wygrana(char* tab, int roz, int znaki, char symbol) {


	int licznik = 0;

																				// Sprawdzanie wierszy
	for (int i = 0; i < roz; i++) {
		for (int j = 0; j <= roz - znaki; j++) {								// sprawdzamy odpowiedniej ilosci kombinacji
			for (int k = 0; k < znaki; k++) {									// sprawdzamy tyle obok siebie ile podano znakow
				if (tab[i * roz + j + k] == symbol) licznik++;					// je¿eli mamy ten sam symbol zwiekszamy licznik
			}

			if (licznik == znaki) return true;									// Jezeli mamy odpowiednia liczbe znakow kolo siebie to mamy wygrana
			licznik = 0;
		}

	}

	// sprawdzanie kolumn

	for (int i = 0; i < roz; i++) {
		for (int j = 0; j <= roz - znaki; j++) {								// sprawdzamy odpowiedniej ilosci kombinacji
			for (int k = 0; k < znaki; k++) {									// sprawdzamy tyle obok siebie ile podano znakow
				if (tab[i + j * roz + k * roz] == symbol) licznik++;			// je¿eli mamy ten sam symbol zwiekszamy licznik
			}

			if (licznik == znaki) return true;									// Jezeli mamy odpowiednia liczbe znakow kolo siebie to wygrana
			licznik = 0;
		}

	}

																				// sprawdzanie przekatnych od lewej
	for (int i = 0; i <= roz - znaki; i++) {
		for (int j = 0; j <= roz - znaki; j++) {								// sprawdzamy odpowiedniej ilosci kombinacji
			for (int k = 0; k < znaki; k++) {									// sprawdzamy tyle obok siebie ile podano znakow
				if (tab[i + j * roz + k * (roz + 1)] == symbol) licznik++;		// je¿eli mamy ten sam symbol zwiekszamy licznik
			}

			if (licznik == znaki) return true;									// Jezeli mamy odpowiednia liczbe znakow kolo siebie to wygrana
			licznik = 0;
		}

	}


																				// sprawdzanie przekatnych od prawej
	for (int i = roz - 1; i >= znaki - 1; i--) {
		for (int j = 0; j <= roz - znaki; j++) {								// sprawdzamy odpowiedniej ilosci kombinacji
			for (int k = 0; k < znaki; k++) {									// sprawdzamy tyle obok siebie ile podano znakow
				if (tab[i + j * roz + k * (roz - 1)] == symbol) licznik++;		// je¿eli mamy ten sam symbol zwiekszamy licznik
			}

			if (licznik == znaki) return true;									// Jezeli mamy odpowiednia liczbe znakow kolo siebie to wygrana
			licznik = 0;
		}

	}



	return false;
}


/********************************** Czyszczenie tablicy *****************************************
*																								*
*  Funkcja czyœci tablice 																		*
*  																								*
*  tab - tablica ktora podlega czyszczeniu														*
*  roz - rozmiar tablicy do czyszczenia															*
*																								*
*///*********************************************************************************************
void czyszczenie_planszy(char* tab, int roz) {

	for (int i = 0; i < roz * roz; i++) {										// Czyszczenie tablicy
		tab[i] = ' ';
	}

}

/******************************** Funkcja zarzadzajaca gra **************************************
*																								*
*  Funkcja zarzadza rozgrywka, wskazuje czyja jest kolej wykonywanego ruchu, oraz sprawdza,     *
*  czy gracz poda³ odpowiedznia wartosc pola.													*
*  																								*
*  tab - tablica na ktorej odbywa sie rozgrywka  												*
*  roz - rozmiar tej tablicy																	*
*  znaki - liczba znakow koniecznych do wygranej												*	
*  maksymalna_glenokosc - maksymalna liczba ruchow do przodu sprawdzanych przez komputer		*
*																								*
*///*********************************************************************************************
void rozgrywka(char* tab, int roz, int znaki, int maksymalna_glebokosc) {

	rysuj_plansze(tab, roz);
	int ruch = 0;

	for (int i = 0; i < roz * roz; i++) {										// wykonujemy ruch tyle razy ile mamy wolnych
		if (i % 2 == 0) {														// miejsc na planszy
			cout << endl << "Gracz wybiera ruch : ";							// gracz wybiera ruch
			cin >> ruch;


																				// Brak mozliwosci podania adresu juz zajetego pola lub numeru spoza przedzialu tablicy
			while (ruch < 1 || ruch > roz * roz || tab[ruch - 1] != ' ') {
				if (ruch < 1 || ruch >(roz * roz)) { 							// Jezeli podano za maly luz za duzy indeks
					cout << "Wprowadzono bledny adres pola!!! " << endl;
					rysuj_plansze(tab, roz);
					cout << endl << "Gracz wybiera ruch : ";
					cin >> ruch;

				}
				else if (tab[ruch - 1] != ' ') { 								// Jezeli pod wskazanym polem stoi juz jakis znak
					cout << "Wskazane pole jest juz zajete!!! " << endl;
					rysuj_plansze(tab, roz);
					cout << endl << "Gracz wybiera ruch : ";
					cin >> ruch;

				}
			}

			tab[ruch - 1] = 'X';												// Sprawdzamy czy po wprowadzeniu znaku nie nastapila wygrana
			rysuj_plansze(tab, roz);
			if (wygrana(tab, roz, znaki, 'X')) {
				cout << endl << "GRATULACJE!!! WYGRALES!!!" << endl;
				return;
			}
		}
		else {																	// ruch wykonuje komputer
			ruch = ruch_komputera(tab, roz, znaki, maksymalna_glebokosc);		// szukanie optymalnego ruchu dla komputera
			cout << endl << "Komputer wybiera ruch : " << ruch + 1 << endl;
			cout << "======================" << endl << endl;

			tab[ruch] = 'O';
			rysuj_plansze(tab, roz);
			if (wygrana(tab, roz, znaki, 'O')) {								// Sprawdzamy czy komputer nie wygra³
				cout << endl << "KOMPUTER WYGRYWA!!!" << endl;
				return;
			}
		}



	}

	cout << endl << "REMIS!!!" << endl;

}


/***************************** Wybieranie ruchu dla komputera ***********************************
*																								*
*  Funkcja wybierajaca najbardziej optymalny ruch dla komputera, wywo³uje algorytm minmax		*
*  w celu osi¹gniecia wygranej																	*
*  																								*
*  tab - tablica na ktorej odbywa sie rozgrywka   												*
*  roz - rozmiar tej tablicy																	*
*  znaki - liczba znakow koniecznych do wygrania												*
*  maksymalna_glenokosc  maksymalna liczba ruchow do przodu sprawdzanych przez komputer			*
*																								*
*///*********************************************************************************************
int ruch_komputera(char* tab, int roz, int znaki, int maksymalna_glebokosc) {

	int najlepszy_ruch = -100;
	int obecny_ruch = -100;
	int alpha = -100;
	int beta = 100;
	int ruch = -1;

	for (int i = 0; i < roz * roz; i++) {												// pêtla wykonuje sie tyle razy ile razy wykonuje sie dana operacja

		if (tab[i] == ' ') {

			tab[i] = 'O';
			obecny_ruch = minmax(tab, roz, znaki, 1, maksymalna_glebokosc - 1, false, alpha, beta);


			tab[i] = ' ';

			if (obecny_ruch > najlepszy_ruch) {											// je¿eli dany ruch jest lepszy wybieramy jego
				najlepszy_ruch = obecny_ruch;
				ruch = i;
			}
		}
	}


	return ruch;																		// zwracamy najbardziej optymalny ruch
}


/***************************** algorytm minmax z ciêciami alfa-beta *****************************
*																								*
*  Funkcja szuka najbardziej optymalnego ruchu dla komputera. Przewiduje zadana liczbe ruchów	*
*  gry do przodu w celu unikniecia porazki. Algorytm jest wyposa¿ony w ciêcia alpha-beta, w 	*
*  celu przyspieszenia algotyrmu wyszukiwanego ruchu, co pozwala na glebsza rekurencje 			*
*  w tym samym czasie																			*
*  																								*
*  tab - tablica na ktorej rozgrywa sie rozryka								   					*
*  roz - rozmiar tej tablicy																    *
*  znaki - liczba znakow koniecznycg do wygranej												*
*  maksymalna_glenokosc -  maksymalna liczba ruchow do przodu sprawdzanych przez komputer		*
*																								*
*///*********************************************************************************************
int minmax(char* tab, int roz, int znaki, int obecna_glebokosc, int maksymalna_glebokosc, bool MAX, int alpha, int beta) {

																						// +/- obecna_glebokosc w celu wybrania najszybszej wygranej lub najdluzej grac jezeli prorazka
	if (wygrana(tab, roz, znaki, 'O'))  return 10 - obecna_glebokosc;					// wygrywa komputer
	if (wygrana(tab, roz, znaki, 'X'))  return -10 + obecna_glebokosc;					// komputer przegrywa
	if (remis(tab, roz, znaki)) return 0;

	if (maksymalna_glebokosc <= 0) return 0;											// Je¿eli brak wygranej lub przegranej, nie wiemy
																						// jak wyglada daleej funcka bo szukamy tylko
																						// pare razy a nie do konca

																						// Sprawdzamy maksymalna wartosc dla gracza, szukamy najwiêkszej wartoœci czyli maksa

	if (MAX) {

		int best = -100;																// pierwszy ruch który na pewno bd mniejszy od szukanego

		for (int i = 0; i < roz * roz; i++) {											// pêtla wykonuje sie tyle razy ile razy wykonuje sie dana operacja

			if (tab[i] == ' ') {

				tab[i] = 'O';

				best = max(best,minmax(tab, roz, znaki, obecna_glebokosc + 1, maksymalna_glebokosc - 1, !MAX, alpha, beta));

				tab[i] = ' ';

				alpha = max(alpha, best);												// Ciêcia alpha-beta w celu przyspieszenia algrytmu
				if (beta <= alpha)  break;
			}
		}

		return best;
	}

	else {

		int best = 100; 																// pierwszy ruch który na pewno bd wiekszy od szukanego
		for (int i = 0; i < roz * roz; i++) {											// pêtla wykonuje sie tyle razy ile razy wykonuje sie dana operacja

			if (tab[i] == ' ') {

				tab[i] = 'X';

				best = min(best,minmax(tab, roz, znaki, obecna_glebokosc + 1, maksymalna_glebokosc - 1, !MAX, alpha, beta));

				tab[i] = ' ';

				beta = min(beta, best);													// ciêcia alpha-beta w celu przyspieszenia algorytmu
				if (beta <= alpha)  break;
			}
		}
		return best;
	}



}
