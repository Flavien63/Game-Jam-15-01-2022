#ifndef __MAP_HPP__
#define __MAP_HPP__


#include <string>
#include <iostream>
#include <fstream>

#include "Entite.hpp"

/*
class Bloc{};
class Ennemi{};
*/



using namespace std;

class Map
{
private:
	const int _largeurBloc = 10;

	const int _longueurMap = 11;
	const int _hauteurMap = 4;
	int _mapBlocFix[4][11];

	const int _nbMaxEntites = 50;
	Entite * _entites ;

public:
	Map();
	void chargerMap(string path);
	Entite getEntite(int );
	int getLargeurBloc();

};


enum BlocSpeciale
{
	Rien = 0,
	BlocFixe = 1,
	BlocSpecialJump = 2, // Bloc_Jump
	BlocSpecialDeplacable = 3, // Bloc_Deplacable
	BlocSpecialPateforme = 4, // Plateforme
	BlockSpecialChekpoint = 5, // ...
	BlockSpecialPic = 6, //...
	BlocSpecialItem = 7 // ...
};

#endif