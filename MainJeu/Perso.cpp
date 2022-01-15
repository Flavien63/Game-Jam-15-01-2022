#include "Perso.hpp"

Perso::Perso() :
	PV(5), v_saut(1)
{

}

Perso::~Perso() {

}

void Perso::getPV() {
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

void Perso::Sauter(Perso pers) {
	pers.setPosition_y = pers.getPosition_y + v_saut;
}

void Perso::Interagir(Perso pers, Bloc_Jump bj) {
	v_saut = bj.getv_saut();
	Sauter(pers, v_saut);
}

void Perso::Interragir(Entite ent, Bloc_Deplacable bd, MAP map) {
	bd.setVitx(ent.getVitx());
	deplacer(map);
}