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


Entite::Entite()
{
}

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
	int posXgrid = (posx + vitx) / map.getLargeurBlock();
	int posYgrid = (posy + vity) / map.getLargeurBlock();
	if (!(map.matBlock[posXgrid][posYgrid])) {
		while ((checkX || checkY) && i<nbEntite)
		{
			Entite currEntite = map.getEntite(i);
			if (!(&currEntite == this) && (typeid(currEntite) == typeid(Bloc)))
			{
				checkX = checkX && !(posx + vitx + longueur >= currEntite.getPosx() && posx + vitx <= currEntite.getPosx() + currEntite.getLongueur());
				checkY = checkY && !(posy + vity + hauteur >= currEntite.getPosy() && posy + vity <= currEntite.getPosy() + currEntite.getHauteur());

			}
			++i;
		}

		if (checkX) {
			posx += vitx;
		}
		else {
			vitx = 0;
		}

		if (checkY) {
			posy += vity;
		}
		else {
			vity = 0;
		}
	}

}	//rajouter deplacement sur plateforme, gerer deplacement vers mur midair


bool Entite::estSol(Map map)
{
	bool check = (posx % map.getLargeurBloc() == 0 && map.tabBlockFixe[posx % map.getLargeurBlock()] == 0); //check entite
	int i = 0;
	while (check && i < nbEntite)
	{
		Entite currEntite = map.getEntite(i);
		if (!(&currEntite == this) && (typeid(currEntite) == typeid(Bloc)))
		{
			check = check || (posx + longueur > currEntite.getPosx() && posx < currEntite.getPosx() + currEntite.getLongueur() &&
				posy == currEntite.getPosy() + currEntite.getHauteur() + 1);
		}
		++i;
	}

}

void Entite::affiche()
{
	std::cout << "affiche" << std::endl;
}

/*
int main()
{
	Entite test = Entite(0,1,2,3,4,5);
	Entite test2 = Entite(0, 1, 222, 3, 4, 5);
	test.affiche();
	std::cout << (test==test2) << std::endl;
}*/