#include "Entite.hpp"
#include "Bloc.hpp"

int Entite::nbEntite=0;

int Entite::getHauteur() { return hauteur; }
int Entite::getLongueur() { return longueur; }
int Entite::getPosx() { return posx; }
int Entite::getPosy() { return posy; }
int Entite::getVitx() { return vitx; }
int Entite::getVity() { return vity; }
int Entite::getNbEntite() { return nbEntite; }


void Entite::setHauteur(int l)	{ hauteur = l; }
void Entite::setLongueur(int l) { longueur = l; }
void Entite::setPosx(int x)		{ posx = x; }
void Entite::setPosy(int y)		{ posy = y; }
void Entite::setVitx(int vx)	{ vitx = vx; }
void Entite::setVity(int vy)	{ vity = vy; }
void Entite::setVitesse(int vx, int vy) { vitx = vx; vity = vy; }

const GLuint indices[] =
{
	0,1,2,
	0,2,3
};


void Entite::InitTexture()
{
	//TO DO
}

Entite::Entite()
{
}

Entite::Entite(int larg, int lng, int x, int y, int vx, int vy)
{
	hauteur = larg;
	longueur = lng;
	posx = x;
	posy = y;
	vitx = x;
	vity = y;
	nbEntite++;
}

bool operator== (Entite& a, Entite& b)
{
	return (a.getPosx() == b.getPosx()
		&& a.getPosy() == b.getPosy()
		&& a.getHauteur() == b.getHauteur()
		&& a.getLongueur() == b.getLongueur() 
		&& a.getVitx() == b.getVitx()
		&& a.getVity() == b.getVity());
}

void Entite::deplacer(Map map)
{
	int currEntiteXgrid, currEntiteYgrid;
	bool checkX = true;
	bool checkY = true;
	int i = 0;
	int posXgrid = (posx + vitx) / map.getLargeurBlock();
	int posYgrid = (posy + vity) / map.getLargeurBlock();
	if (!(map.matBlock[posXgrid][posYgrid])) {
		while ((checkX || checkY) && i<nbEntite)
		{
			Entite currEntite = map.getEntite(i);
			if (!(&currEntite == this) && (typeid(currEntite) == typeid(Bloc)))
			{
				checkX = checkX && !(posx + vitx + longueur >= currEntite.getPosx() && posx + vitx <= currEntite.getPosx() + currEntite.getLongueur());
				checkY = checkY && !(posy + vity + hauteur >= currEntite.getPosy() && posy + vity <= currEntite.getPosy() + currEntite.getHauteur());

			}
			++i;
		}

		if (checkX) {
			posx += vitx;
		}
		else {
			vitx = 0;
		}

		if (checkY) {
			posy += vity;
		}
		else {
			vity = 0;
		}
	}

}	//rajouter deplacement sur plateforme, gerer deplacement vers mur midair


bool Entite::estSol(Map map)
{
	bool check = (posx % map.getLargeurBloc() == 0 && map.tabBlockFixe[posx % map.getLargeurBlock()] == 0); //check entite
	int i = 0;
	while (check && i < nbEntite)
	{
		Entite currEntite = map.getEntite(i);
		if (!(&currEntite == this) && (typeid(currEntite) == typeid(Bloc)))
		{
			check = check || (posx + longueur > currEntite.getPosx() && posx < currEntite.getPosx() + currEntite.getLongueur() &&
				posy == currEntite.getPosy() + currEntite.getHauteur() + 1);
		}
		++i;
	}

}

void Entite::affiche(GLfloat posx, GLfloat posy, GLfloat* vertices, VAO& VAO1)
{
	vertices[0] = posx;
	vertices[1] = posy;
	vertices[5] = posx;
	vertices[6] = posy + hauteur;
	vertices[10] = posx + longueur;
	vertices[11] = posy + hauteur;
	vertices[15] = posx + longueur;
	vertices[16] = posy;
	VAO1.Bind();
	VBO VBO1(vertices, sizeof(vertices));
	EBO EBO1(indices, sizeof(indices));
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));

	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();
	VBO1.Delete();
	EBO1.Delete();
	tabTexture[IDtexture].Bind();
	VAO1.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	VAO1.Unbind();
}

/*
int main()
{
	Entite test = Entite(0,1,2,3,4,5);
	Entite test2 = Entite(0, 1, 222, 3, 4, 5);
	test.affiche();
	std::cout << (test==test2) << std::endl;
}*/
