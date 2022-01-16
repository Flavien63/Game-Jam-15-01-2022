#pragma once

#ifndef __JOUEUR_HPP__
#define __JOUEUR_HPP__

#include "Perso.hpp"

class Joueur : public Perso
{
	Texture texture;
	int checkpoint;

public:
	Joueur();
	~Joueur();
	void CheckpointUp();
	void CheckpointDown();
	int getCheckpoint();
};

#endif