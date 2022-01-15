#pragma once
class Perso : Entite
{
	int PV;
	double v_saut;

public:
	Perso();
	~Perso();
	void getPV();
	void PVUp();
	void PVDown();
	int getv_saut();
	void setv_saut(int);
	void Sauter(Perso);
	void Perso::Interagir(Entite, Bloc_Jump);
	void Perso::Interragir(Entite, Bloc_Deplacable, MAP);
};

