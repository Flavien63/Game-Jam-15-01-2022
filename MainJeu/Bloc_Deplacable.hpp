#ifndef __BLOC_DEPLACABLE_HPP__
#define __BLOC_DEPLACABLE_HPP__

#include "Map.hpp"
#include "Bloc.hpp"
const int dim = 50;

class Bloc_Deplacable: public Bloc
{
	static bool actif;

	public:
		Bloc_Deplacable(int largeur, int longeur, int posx, int posy);
		static void rendreActif();
		bool isActif();
		void deplacer();
};


#endif // !__BLOC_DEPLACABLE_HPP__