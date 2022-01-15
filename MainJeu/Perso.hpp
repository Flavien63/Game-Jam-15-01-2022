#pragma once

#ifndef __PERSO_HPP__
#define __PERSO_HPP__

#include "Entite.hpp"

class Texture{};
class Bloc{};
class Bloc_Jump{};
class Bloc_Deplacable{};
class Map{};

class Perso : Entite
{
	int PV;
	int v_saut;

public:
	Perso();
	~Perso();
	int getPV();
	void PVUp();
	void PVDown();
	int getv_saut();
	void setv_saut(int);
	void Sauter(Entite, int);
	void Interagir(Entite, Bloc_Jump);
	void Interragir(Entite, Bloc_Deplacable, Map);
};

#endif