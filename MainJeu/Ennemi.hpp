#pragma once
#ifndef __ENNEMI_HPP__
#define __ENNEMI_HPP__

#include "Perso.hpp"

class Ennemi : public Perso
{
	int vitesse;

public:
	Ennemi();
	~Ennemi();
	int getVitesse();
	void setVitesse(int);
	void Interragir(Ennemi);
};

#endif