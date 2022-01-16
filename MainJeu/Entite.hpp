#ifndef ENTITE_H
#define ENTITE_H

#include <typeinfo>
#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>

#include"Texture.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"shaderClass.h"

using namespace std;

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

public:
	int getHauteur();
	int getLongueur();
	int getPosx();
	int getPosy();
	int getVitx();
	int getVity();

	void setHauteur(int l);
	void setLongueur(int l);
	void setPosx(int x);
	void setPosy(int y);
	void setVitx(int vx);
	void setVity(int vy);
	void setVitesse(int vx, int vy);
	void setID(int id);
	Entite();
	Entite(int larg, int lng, int x, int y, int vx, int vy);



	void deplacer();
	void affiche(GLfloat posx, GLfloat posy, GLfloat* vertices, VAO& VAO, Texture* tabTexture);

};

bool operator== (Entite& a, Entite& b);

#endif