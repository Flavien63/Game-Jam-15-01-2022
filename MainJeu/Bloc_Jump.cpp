#include "Bloc_Jump.hpp"

bool Bloc_Jump::actif = false;

Bloc_Jump::Bloc_Jump():
	v_saut(0)
{}

void Bloc_Jump::rendreActif()
{
	actif = true;
}

bool Bloc_Jump::estActif()
{
	return actif;
}