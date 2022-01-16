#include "Perso.hpp"
#include "Bloc_Jump.hpp"

Perso::Perso() : 
	Entite::Entite(10,10,0,0,0,0,0), PV(5), v_saut(1)
{

}

Perso::Perso(int larg, int lng, int x, int y, int vx, int vy):
	Entite(larg,lng,x,y,0,0,0), PV(5), v_saut(1)
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
	bd.deplacer();	
}



bool Perso::estSol( Map &map)
{
	int posX = this->getPosx();
	int posY = this->getPosy();
	bool check;
	check = map.isBlocFixe(posX / map.getLargeurBloc(), (posY - 1) / map.getLargeurBloc());
	int i = 0;
	Entite autre;
	while (!check && i < Entite::getNbEntite() - 1)
	{
		autre = map.getEntite(i);
		check = check && !(posY == autre.getPosy() + autre.getHauteur() + 1);
		++i;
	}
	return check;

}