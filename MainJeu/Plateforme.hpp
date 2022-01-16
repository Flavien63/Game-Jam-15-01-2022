#ifndef __PLATEFORME_HPP__
#define __PLATEFORME_HPP__

#include "Map.hpp"
#include "Bloc.hpp"


class Plateforme : public Bloc
{
	static bool actif;
	//La plateforme se d�place entre les points posA et posB.
	//sens indique le sens de d�placement de la plateforme:
	//	- il vaut 1 pour un d�placement de posA vers posB;
	//	- il vaut -1 pour un d�placement de posB vers posA;
	int posAx;
	int posAy;
	int posBx;
	int posBy;

	public:
		Plateforme(int largeur, int longeur, int posx, int posy, int new_posAx, int new_posAy, int new_posBx, int new_posBy, int nb_frame);
		static void rendreActif();
		bool isActif();
		void deplacer();
};

#endif // !#define__PALTEFORME_HPP__