#pragma once
#include "Bloc.hpp"

class Pic : public Bloc
{
	static bool actif;

public:
	Pic (int largeur, int longeur, int posx, int posy);
	static void rendreActif();
	bool isActif();
};

