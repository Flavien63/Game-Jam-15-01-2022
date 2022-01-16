#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include <stdlib.h>     
#include <time.h>  


#include"shaderClass.h"
#include"Entite.hpp"
#include"Texture.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"


// Indices for vertices order



void initvertice(GLfloat* vertices)
{
	vertices[3] = 0.0f;
	vertices[4] = 0.0f;
	vertices[8] = 0.0f;
	vertices[19] = 0.0f;
	vertices[9] = 1.0f;
	vertices[13] = 1.0f;
	vertices[14] = 1.0f;
	vertices[18] = 1.0f;
	for (int k = 2; k < 20; k = k + 5)
	{
		vertices[k] = 0.0f;
	}
}

void carre(GLfloat* vertices, double x, double y, int A, GLfloat a)
{
	GLfloat posx = x / (double)(A / 2);
	GLfloat posy = y / (double)(A / 2);
	vertices[0] = posx;
	vertices[1] = posy;
	vertices[5] = posx;
	vertices[6] = posy + a;
	vertices[10] = posx + a;
	vertices[11] = posy + a;
	vertices[15] = posx + a;
	vertices[16] = posy;
}

int main()
{
	//Entite::InitTexture();
	srand(time(0));
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "Ma super fenetre pas du tout copie sur Internet", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);



	// Generates Shader object using shaders defualt.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	Texture tabTexture[2] = { {"MATHVDT.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE },
		{"super.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE} };

	shaderProgram.Activate();
	constexpr std::size_t nVertices = 20;

	GLfloat vertices[nVertices];
	initvertice(vertices);
	GLfloat a = 0.1f;
	VAO VAO1;
	Entite tabbloc[25];

	for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i < 5; i++)
		{
			tabbloc[5 * k + i].setHauteur(50);
			tabbloc[5 * k + i].setLongueur(50);
			tabbloc[5 * k + i].setPosx(50 * k);
			tabbloc[5 * k + i].setPosy(50 * i);
			tabbloc[5 * k + i].setID(rand() % 2);
		}
	}

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.17f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		for (int k = 0; k < 25; k++)
		{
			GLfloat posx = (100.0f - tabbloc[k].getPosx()) / 800.0f;
			GLfloat posy = (100.0f - tabbloc[k].getPosy()) / 800.0f;
			tabbloc[k].affiche(posx, posy, vertices, VAO1, tabTexture);
		}



		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}