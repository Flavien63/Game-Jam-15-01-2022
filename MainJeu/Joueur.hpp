#pragma once

#ifndef __JOUEUR_HPP__
#define __JOUEUR_HPP__

#include "Perso.hpp"

class Joueur : public Perso
{
	int checkpoint;

public:
	Joueur();
	~Joueur();
	void CheckpointUp();
	void CheckpointDown();
	void CheckpointRAZ();
	int getCheckpoint();
};

#endif