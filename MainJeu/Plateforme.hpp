#pragma once
#include "Bloc.hpp"

class Plateforme :public Bloc
{
	static bool actif;
	int posAx;
	int posAy;
	int posBx;
	int posBy;
	int sens = 1;

	public:
		Plateforme(int largeur, int longeur, int posx, int posy, int new_posAx, int new_posAy, int new_posBx, int new_posByB);
		static void rendreActif();
		bool isActif();
		void seDeplacer();
};