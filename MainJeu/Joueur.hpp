#pragma once

#ifndef __JOUEUR_HPP__
#define __JOUEUR_HPP__

class Joueur
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