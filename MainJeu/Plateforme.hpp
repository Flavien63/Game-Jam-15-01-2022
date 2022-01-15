#pragma once
#include "Bloc.hpp"

class Plateforme :public Bloc
{
	static bool actif;
	int posA;
	int posB;

	public:
		Plateforme(int new_posA, int new_posB);
		static void rendreActif();
		bool estActif();
};

