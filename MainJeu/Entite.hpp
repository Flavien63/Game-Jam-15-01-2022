#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <typeinfo>

class Entite
{
	int largeur;
	int longueur;
	int posx; 
	int posy;
	int vitx;
	int vity;
	static int nbEntite;

public:
	int getLargeur();
	int getLongueur();
	int getPosx();
	int getPosy();
	int getVitx();
	int getVity();

	void setLargeur(int l);
	void setLongueur(int l);
	void setPosx(int x);
	void setPosy(int y);
	void setVitx(int vx);
	void setVity(int vy);

	Entite();



	void deplacer(Map map);
	bool estSol(Map map);
	void affiche();
};

