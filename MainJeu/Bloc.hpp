#ifndef __BLOC_HPP__
#define __BLOC_HPP__

#include "Entite.hpp"

class Bloc: public Entite
{
	public:
		Bloc(int largeur, int longeur, int posx, int posy, int vitx, int vity);
		virtual ~Bloc() = 0;
		virtual void rendreActif() = 0;
		virtual bool isActif() = 0;
};


#endif // !__BLOC_HPP__