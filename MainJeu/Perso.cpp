#include "Perso.hpp"
#include "Bloc_Jump.hpp"

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

void Perso::Sauter(int vitesse) {
	this->setPosy(this->getPosy() + vitesse);
	
}

void Perso::Interagir(Bloc_Jump bj) {
	this->Sauter(bj.getVit_saut());					//vitesse de saut du perso donnée par bloc
}

void Perso::Interragir(Bloc_Deplacable bd, Map map) {
	bd.setVitx(this->getVitx());					//vitesse du bloc identique a celle du perso
	bd.deplacer(map);	
}