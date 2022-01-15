#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class Entite
{
	int largeur;
	int longueur;
	//GL_TEXTURE_2D texture; //Wrong type
	int posx; 
	int posy;
	int vitx;
	int vity;

public:
	int getLargeur();
	int getLongueur();
	//GL_TEXTURE_2D getTexture();
	int getPosx();
	void setPosx(int x);

	void deplacer();
	bool estSol(Map map);
	void affiche();
};

