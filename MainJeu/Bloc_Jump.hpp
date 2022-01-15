#pragma once
#include "Bloc.hpp"

class Bloc_Jump : public Bloc
{
	static bool actif;
	int vit_saut;
	
	public:
		Bloc_Jump(int largeur, int longeur, int posx, int posy);
		static void rendreActif();
		bool isActif();
};

