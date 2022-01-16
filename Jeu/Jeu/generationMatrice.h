#ifndef _generationMatrice_hpp_
#define _generationMatrice_hpp_

#include <iostream>
#include <fstream>
#include <string>

#define N 50
#define K 100

using namespace std;

void ajoutBlocFixe(int x, int y, int height, int width, int* matrice);

void ajoutBlocSpecialJump(int x, int y, int height, int width, int* matrice);

void ajoutBlocSpecialDeplacable(int x, int y, int height, int width, int* matrice);

void ajoutblocSpecialPlateforme(int x, int y, int height, int width, int* matrice);

void ajoutBlocSpecialCheckpoint(int x, int y, int height, int width, int* matrice);

void ajoutBlocSpecialPic(int x, int y, int height, int width, int* matrice);

void ajoutBlocSpecialItem(int x, int y, int height, int width, int* matrice);

void ouvertureFichier();

int main(int, char**);

#endif
