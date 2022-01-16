#pragma once
#ifndef __ENNEMI_HPP__
#define __ENNEMI_HPP__

#include "Perso.hpp"

class Ennemi
{
	int vitesse;
	Texture texture;

public:
	Ennemi(Texture);
	~Ennemi();
	int getVitesse();
	void setVitesse(int);
	void Interragir(Ennemi);
};

#endif