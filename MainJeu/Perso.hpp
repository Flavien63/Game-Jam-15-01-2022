#pragma once

#ifndef __PERSO_HPP__
#define __PERSO_HPP__

#include "Entite.hpp"
#include "Map.hpp"
#include "Bloc.hpp"
#include "Bloc_Deplacable.hpp"
#include "Bloc_Jump.hpp"

class Perso : public Entite
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
	void Sauter(int);
	void Interagir(Bloc_Jump);
	void Interragir(Bloc_Deplacable, Map);
	bool estSol(Map& map);
};

#endif