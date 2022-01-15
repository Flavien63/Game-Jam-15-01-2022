#include "Perso.hpp"

Perso::Perso() :
	PV(5), v_saut(1)
{

}

Perso::~Perso() {

}

int Perso::getPV() {
	return PV;
}

void Perso::PVUp() {
	PV++;
}

void Perso::PVDown() {
	PV--;
}

int Perso::getv_saut()
{
	return v_saut;
}

void Perso::setv_saut(int val)
{
	v_saut = val;
}

void Perso::Sauter(Entite ent, int vitesse) {
	ent.setPosition_y = ent.getPosition_y + vitesse;
}

void Perso::Interagir(Entite ent, Bloc_Jump bj) {
	Sauter(ent, bj.getv_saut());					//vitesse de saut du perso donnée par bloc
}

void Perso::Interragir(Entite ent, Bloc_Deplacable bd, MAP map) {
	bd.setVitx(ent.getVitx());
	bd.deplacer(map);
}