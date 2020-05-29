#pragma once
#ifndef GRA_HPP_
#define GRA_HPP_

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void rysuj_plansze(char* tab, int roz);
void plansza_pola(char* tab, int roz);
bool wygrana(char* tab, int roz, int znaki, char symbol);
bool remis(char* tab, int roz, int znaki);
void czyszczenie_planszy(char* tab, int roz);
void rozgrywka(char* tab, int roz, int znaki, int maksymalna_glebokosc);

int ruch_komputera(char* tab, int roz, int znaki, int maksymalna_glebokosc);
int minmax(char* tab, int roz, int znaki, int obecna_glebokosc, int maksymalna_glebokosc, bool MAX, int alpha, int beta);

#endif /* GRA_HPP_ */
