#include "Entite.hpp"


int Entite::getHauteur() { return hauteur; }
int Entite::getLongueur() { return longueur; }
int Entite::getPosx() { return posx; }
int Entite::getPosy() { return posy; }
int Entite::getVitx() { return vitx; }
int Entite::getVity() { return vity; }

void Entite::setHauteur(int l)	{ hauteur = l; }
void Entite::setLongueur(int l) { longueur = l; }
void Entite::setPosx(int x)		{ posx = x; }
void Entite::setPosy(int y)		{ posy = y; }
void Entite::setVitx(int vx)	{ vitx = vx; }
void Entite::setVity(int vy)	{ vity = vy; }
void Entite::setVitesse(int vx, int vy) { vitx = vx; vity = vy; }


Entite::Entite(int larg, int lng, int x, int y, int vx, int vy)
{
	hauteur = larg;
	longueur = lng;
	posx = x;
	posy = y;
	vitx = x;
	vity = y;
}

bool operator== (Entite& a, Entite& b)
{
	return (a.getPosx() == b.getPosx()
		&& a.getPosy() == b.getPosy()
		&& a.getHauteur() == b.getHauteur()
		&& a.getLongueur() == b.getLongueur() 
		&& a.getVitx() == b.getVitx()
		&& a.getVity() == b.getVity());
}

void Entite::deplacer(Map map)
{
	int currEntiteXgrid, currEntiteYgrid;
	bool checkX = true;
	bool checkY = true;
	int i = 0;
	int posXgrid = (posx + vitx) / map.getHauteurBlock();
	int posYgrid = (posy + vity) / map.getHauteurBlock();
	if (!(map.matBlock[posXgrid][posYgrid])) {
		while (check && i<nbEntite)
		{
			Entite currEntite = map.getEntite(i);
			if (!(&currEntite == this))
			{
				currEntiteXgrid = (currEntite.posx + vitx) / map.getHauteurBlock();
				currEntiteYgrid = (currEntite.posy + vity) / map.getHauteurBlock();
				check = (typeid(currEntite) == typeid(Bloc) && 
					!(posx + vitx >= currEntite.posx && posx + vitx <= currEntite.posx + currEntite.longueur) &&
					!(posy + vity >= currEntite.posy && posy + vity <= currEntite.posy + currEntite.hauteur));

			}
			++i;
		}

		if (check) {
			posx += vitx;
			posy += vity;
		}
	}

}	//rajouter deplacement sur plateforme, gerer deplacement vers mur


bool Entite::estSol(Map map)
{
	return ((posx % map.largeBlock) == 0 && map.tabBlockFixe[posx % map.largBlock] == 0); //check entite
}

void Entite::affiche()
{

}
