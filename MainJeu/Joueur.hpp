#pragma once
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

