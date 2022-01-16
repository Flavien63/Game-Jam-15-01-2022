#pragma once
#ifndef __PIC_HPP__
#define __PIC_HPP__
#include "Bloc.hpp"

class Pic : public Bloc
{
	static bool actif;

public:
	Pic (int largeur, int longeur, int posx, int posy);
	static void rendreActif();
	bool isActif();
};

#endif // !__PIC_HPP__
