#pragma once
class Ennemi
{
	int vitesse;
	Texture texture;

public:
	Ennemi(Texture texture);
	~Ennemi();
	int getVitesse();
	void setVitesse(int);
	void Interragir(Bloc b);
};

