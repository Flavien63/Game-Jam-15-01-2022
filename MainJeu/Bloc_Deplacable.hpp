#pragma once

#ifndef __BLOC_DEPLACABLE_HPP__
#define __BLOC_DEPLACABLE_HPP__

#include "Bloc.hpp"
const int dim = 50;

class Bloc_Deplacable: public Bloc
{
	static bool actif;

	public:
		Bloc_Deplacable(int largeur, int longeur, int posx, int posy);
		static void rendreActif();
		bool isActif();
};

#endif