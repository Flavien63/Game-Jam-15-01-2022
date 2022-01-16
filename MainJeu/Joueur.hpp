#pragma once

#ifndef __JOUEUR_HPP__
#define __JOUEUR_HPP__

#include "Perso.hpp"
#include "Checkpoint.hpp"

class Joueur : public Perso
{
	Checkpoint checkpoint;

public:
	Joueur();
	~Joueur();
	void setCheckpoint(Checkpoint);
	Checkpoint getCheckpoint();
};

#endif