#pragma once
#include "Bloc.hpp"

class Bloc_Jump : public Bloc
{
	static bool actif;
	float v_saut;
	
	public:
		Bloc_Jump();
		static void rendreActif();
		bool estActif();
};

