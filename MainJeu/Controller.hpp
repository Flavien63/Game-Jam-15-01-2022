#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <cstdlib>
#include "Map.hpp"
#include "Entite.hpp"
#include "Joueur.hpp"

/*
class Joueur{};
class Perso {};
class Map{};
*/

class Controller
{

private:
	const int tailleEcranX = 10;
	const int tailleEcranY = 10;
	Joueur _joueur;
	Map _map;

public:
	Controller();
	void MouvementPerso(int dirH, int dirV);
	void deplacementEntite();
	void afficherEntite();
	void afficherMap(GLfloat* vertices, std::size_t nVertices, VAO& VAO1, Texture* tabTexture);
	

};


#endif