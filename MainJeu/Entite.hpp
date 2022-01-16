#ifndef __ENTITE_HPP__
#define __ENTITE_HPP__

#include <typeinfo>
#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>

#include"Texture.h"

using namespace std;

//#include "Bloc.hpp"
#include "Map.hpp"

class Map;

class Entite
{
	int hauteur;
	int longueur;
	int posx; 
	int posy;
	int vitx;
	int vity;
	static int nbEntite;
	int IDtexture;
	static Texture* tabTexture;

public:
	int getHauteur();
	int getLongueur();
	int getPosx();
	int getPosy();
	int getVitx();
	int getVity();
	static int getNbEntite();

	void setHauteur(int l);
	void setLongueur(int l);
	void setPosx(int x);
	void setPosy(int y);
	void setVitx(int vx);
	void setVity(int vy);
	void setVitesse(int vx, int vy);
	static void InitTexture();

	Entite();
	Entite(int larg, int lng, int x, int y, int vx, int vy);


	void deplacer(Map map);
	bool estSol(Map map);
	void affiche(GLfloat posx, GLfloat posy, GLfloat* vertices, VAO& VAO);

};

bool operator== (Entite& a, Entite& b);

#endif