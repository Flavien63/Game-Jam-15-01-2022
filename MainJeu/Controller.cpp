#include "Controller.hpp"

Controller::Controller() : _joueur(100,200,20*60,45*60,1,1), _map()
{
	_map.chargerMap("Carte.txt");
}

void Controller::MouvementPerso(int dirH, int dirV)
{
	/*
	if (glfwGetKey(Window, GLFW_KEY_D) == GLFW_PRESS)
	{	}
	*/
	_joueur.setVitx(dirH);
	_joueur.setVity(dirV);

}

GLuint indices2[] =
{
	0,1,2,
	0,2,3
};

void Controller::deplacementEntite()
{

	bool checkX, checkY = true;
	Entite e;
	Entite autre;

	int newPosX, newPosY, newPosXDroite, newPosYHaut;
	int newPosXgrid, newPosYgrid, newPosXgridDroite, newPosYgridHaut;


	for (int k = 0; k < Entite::getNbEntite(); ++k)
	{
		checkX, checkY = true;
		if (k == Entite::getNbEntite())
		{
			e = _joueur;
		}
		else
		{
			e = _map.getEntite(k);
		}

		 newPosX = (e.getPosx() + e.getVitx());
		 newPosY = (e.getPosy() + e.getVity());
		 newPosXDroite = (e.getPosx() + e.getVitx() + e.getLongueur());
		 newPosYHaut = (e.getPosy() + e.getVity() + e.getHauteur());

		 newPosXgrid = newPosX / _map.getLargeurBloc();
		 newPosYgrid = newPosY / _map.getLargeurBloc();
		 newPosXgridDroite = newPosXDroite / _map.getLargeurBloc();
		 newPosYgridHaut = newPosYHaut / _map.getLargeurBloc();

		checkX = !(_map.isBlocFixe(newPosXgrid, e.getPosy() / _map.getLargeurBloc())) &&
			!(_map.isBlocFixe(newPosXgridDroite, e.getPosy() / _map.getLargeurBloc()));
		checkY = !(_map.isBlocFixe(e.getPosx() / _map.getLargeurBloc(), newPosYgrid)) &&
			!(_map.isBlocFixe(e.getPosx() / _map.getLargeurBloc(), newPosYgridHaut));
		int i = 0;
		while ((checkX || checkY) && i < Entite::getNbEntite() - 1)
		{
			if (!(autre == e))
			{
				autre = _map.getEntite(i);
				checkX = checkX && !(newPosXDroite >= autre.getPosx() && newPosX <= autre.getPosx() + autre.getLongueur());
				checkY = checkY && !(newPosYHaut >= autre.getPosy() && newPosY <= autre.getPosy() + autre.getHauteur());
			}
			++i;
		}
		if (!checkX)
		{
			e.setVitx(0);
		}
		if (!checkY)
		{
			e.setVity(0);
		}
		e.deplacer();
	}
	

	
}

void Controller::afficherEntite()
{
	int joueurPosX = _joueur.getPosx();
	int joueurPosY = _joueur.getPosy();

	int entitePosX, entitePosY;

	for (int i = 0; i < Entite::getNbEntite() - 1; i++)
	{
		entitePosX = _map.getEntite(i).getPosx();
		entitePosY = _map.getEntite(i).getPosy();

		if (abs(joueurPosX - entitePosX) < tailleEcranX
			&& abs(joueurPosY - entitePosY) < tailleEcranY)
		{
			// _map.getEntite(i).afficher(); // TA fonction Alexandre
		}

	}
}

void Controller::afficherMap(GLfloat* vertices, std::size_t nVertices, VAO& VAO1, Texture* tabTexture)
{
	for (int k = 0; k < 50;k++)
	{
		for (int i = 0; i < 100; i++)
		{
			if (_map.isBlocFixe(i, k))
			{
				GLfloat posx = (_joueur.getPosx() - i*60) / 800.0f;				
				GLfloat posy = (_joueur.getPosy() - k*60) / 800.0f;
					vertices[0] = posx;
					vertices[1] = posy;
					vertices[5] = posx;
					vertices[6] = posy + (60.0f / 800.0f);
					vertices[10] = posx + (60.0f / 800.0f);
					vertices[11] = posy + (60.0f / 800.0f);
					vertices[15] = posx + (60.0f / 800.0f);
					vertices[16] = posy;
					VAO1.Bind();
					VBO VBO1(vertices, nVertices * sizeof(*vertices));
					EBO EBO1(indices2, sizeof(indices2));
					VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
					VAO1.LinkAttrib(VBO1, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
					VAO1.Unbind();
					VBO1.Unbind();
					EBO1.Unbind();
					VBO1.Delete();
					EBO1.Delete();
					tabTexture[0].Bind();
					VAO1.Bind();
					glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
					VAO1.Unbind();
			}
		}
	}
}
