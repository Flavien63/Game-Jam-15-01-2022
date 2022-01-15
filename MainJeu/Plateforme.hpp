#pragma once
#include "Bloc.hpp"

class Plateforme :public Bloc
{
	static bool actif;
	//La plateforme se déplace entre les points posA et posB.
	//sens indique le sens de déplacement de la plateforme:
	//	- il vaut 1 pour un déplacement de posA vers posB;
	//	- il vaut -1 pour un déplacement de posB vers posA;
	int posAx;
	int posAy;
	int posBx;
	int posBy;
	int sens = 1;

	public:
		Plateforme(int largeur, int longeur, int posx, int posy, int new_posAx, int new_posAy, int new_posBx, int new_posBy, int nb_frame);
		static void rendreActif();
		bool isActif();
		void seDeplacer();
};