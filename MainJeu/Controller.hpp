#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include "Map.hpp"

class Joueur{};
class Perso {};
//class Map{};

class Controller
{

private:
	Joueur _joueur;
	Map _map;

public:
	Controller();
	void MouvementPerso();
	void deplacementPerso(Perso inPerso);
	

};


#endif