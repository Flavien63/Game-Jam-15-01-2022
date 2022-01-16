#pragma once

#ifndef __BLOC_JUMP_HPP__
#define __BLOC_JUMP_HPP__

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

#endif