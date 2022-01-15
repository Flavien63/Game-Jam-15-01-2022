#pragma once
#include "Bloc.hpp"

class Bloc_Deplacable: public Bloc
{
	static bool actif;

	public:
		Bloc_Deplacable();
		static void rendreActif();
		bool estActif();
};

