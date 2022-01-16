#ifndef __CHECKPOINT_HPP__
#define __CHECKPOINT_HPP__
#include "Bloc.hpp"

class Checkpoint : public Bloc
{
	static bool actif;

public:
	Checkpoint(int largeur, int longeur, int posx, int posy);
	static void rendreActif();
	bool isActif();
};

#endif // !__CHECKPOINT_HPP__