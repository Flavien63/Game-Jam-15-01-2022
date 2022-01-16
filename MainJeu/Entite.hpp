#pragma once

#ifndef __ENTITE_HPP__
#define __ENTITE_HPP__

#include <typeinfo>
#include <iostream>
using namespace std;
#include "Map.hpp"

class Entite
{
	int hauteur;
	int longueur;
	int posx; 
	int posy;
	int vitx;
	int vity;
	static int nbEntite;

public:
	int getHauteur();
	int getLongueur();
	int getPosx();
	int getPosy();
	int getVitx();
	int getVity();

	void setHauteur(int l);
	void setLongueur(int l);
	void setPosx(int x);
	void setPosy(int y);
	void setVitx(int vx);
	void setVity(int vy);
	void setVitesse(int vx, int vy);

	Entite(int larg, int lng, int x, int y, int vx, int vy);



	void deplacer(Map map);
	bool estSol(Map map);
	void affiche(); //Alexandre fera

};

bool operator== (Entite& a, Entite& b);

#endif