#include "Perso.hpp"

void Perso::getPV() {
	return PV;
}

void Perso::PVUp() {
	PV++;
}

void Perso::PVDown() {
	PV--;
}

void Perso::setv_saut(int val)
{
	v_saut = val;
}

void Perso::Sauter(Entite ent, Bloc_Jump bj) {
	ent.deplacer()
}