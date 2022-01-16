#pragma once

#ifndef __JOUEUR_HPP__
#define __JOUEUR_HPP__

#include "Perso.hpp"

class Joueur : public Perso
{
	int checkpoint;

public:
	Joueur();
	Joueur(int larg, int lng, int x, int y, int vx, int vy);
	~Joueur();
	void CheckpointUp();
	void CheckpointDown();
	void CheckpointRAZ();
	int getCheckpoint();
};

#endif