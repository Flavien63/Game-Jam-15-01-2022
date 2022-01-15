#include "Entite.hpp"


int Entite::getLargeur() { return largeur; }
int Entite::getLongueur() { return longueur; }
//GL_TEXTURE_2D Entite::getTexture() { return texture; }
int Entite::getPosx() { return posx; }



void Entite::deplacer()
{
	if (posx + vitx)
	{
		posx += vitx;
		posy += vity;
	}
	//rajouter check block et entite
}

bool Entite::estSol(Map map)
{
	return ((posx % map.largBlock) == 0 && map.tabBlockFixe[posx % map.largBlock] == 0); //check entite
}

void Entite::affiche()
{

}
