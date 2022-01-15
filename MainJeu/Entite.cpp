#include "Entite.hpp"


int Entite::getLargeur() { return largeur; }
int Entite::getLongueur() { return longueur; }
int Entite::getPosx() { return posx; }
int Entite::getPosy() { return posy; }
int Entite::getVitx() { return vitx; }
int Entite::getVity() { return vity; }

void Entite::setLargeur(int l)	{ largeur = l; }
void Entite::setLongueur(int l) { longueur = l; }
void Entite::setPosx(int x)		{ posx = x; }
void Entite::setPosy(int y)		{ posy = y; }
void Entite::setVitx(int vx)	{ vitx = vx; }
void Entite::setVity(int vy)	{ vity = vy; }


Entite::Entite(int larg, int lng, int x, int y, int vx, int vy)
{
	largeur = larg;
	longueur = lng;
	posx = x;
	posy = y;
	vitx = x;
	vity = y;
}


void Entite::deplacer(Map map)
{
	Entite currEntite;
	int currEntiteXgrid, currEntiteYgrid;
	bool check = true;
	int i = 0;
	int posXgrid = (posx + vitx) / map.getLargeurBlock();
	int posYgrid = (posy + vity) / map.getLargeurBlock();
	if (!(map.matBlock[posXgrid][posYgrid])) {
		while (check && i<nbEntite)
		{
			currEntite = map.getEntite(i);
			if !(currEntite == this)
			{
				currEntiteXgrid = (currEntite.posx + vitx) / map.getLargeurBlock();
				currEntiteYgrid = (currEntite.posy + vity) / map.getLargeurBlock();
				check = (typeid(currEntite) == typeid(Bloc) && posx + currEntite.posx);
			}
			++i;
		}
		posx += vitx;
		posy += vity;
	}

}	//rajouter check block et entite //foutre vitesse a 0 si on se prend un mur

bool operator== (Entite & entite1,Entite & entite2)
{
	return (entite1.getPosx() == entite2.getPosx());
}


bool Entite::estSol(Map map)
{
	return ((posx % map.largeBlock) == 0 && map.tabBlockFixe[posx % map.largBlock] == 0); //check entite
}

void Entite::affiche()
{

}
