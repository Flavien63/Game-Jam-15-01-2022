#pragma once
#ifndef __ENNEMI_HPP__
#define __ENNEMI_HPP__

#endif // !__ENNEMI_HPP__

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

#endif