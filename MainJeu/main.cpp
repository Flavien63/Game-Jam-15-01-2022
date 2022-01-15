#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>

#include"shaderClass.h"
#include"Texture.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"


// Indices for vertices order
GLuint indices[] =
{
	0,1,2,
	0,2,3
};



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
	GLfloat posx = x /(double)(A / 2);
	GLfloat posy = y /(double)(A / 2);
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

	int widthImg, heightImg, numColCh;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load("MATHVDT.jpg", &widthImg, &heightImg, &numColCh, 0);
	Texture MATHVDT("MATHVDT.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	MATHVDT.texUnit(shaderProgram, "tex0", 0);

	bytes = stbi_load("super.jpg", &widthImg, &heightImg, &numColCh, 0);
	Texture Super("super.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	Super.texUnit(shaderProgram, "tex0", 0);
	GLfloat vertices[20];
	initvertice(vertices);
	GLfloat a = 0.1f;
	VAO VAO1;

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		carre(vertices, -100.2, -100.2, 400, 0.5f);
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
		Super.Bind();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		VAO1.Unbind();

		carre(vertices, 100.2, 100.2, 400, 0.5f);
		VAO1.Bind();
		VBO VBO2(vertices, sizeof(vertices));
		EBO EBO2(indices, sizeof(indices));
		VAO1.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 5 * sizeof(float), (void*)0);
		VAO1.LinkAttrib(VBO2, 1, 2, GL_FLOAT, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		VAO1.Unbind();
		VBO2.Unbind();
		EBO2.Unbind();
		VBO2.Delete();
		EBO2.Delete();
		MATHVDT.Bind();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		


		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	MATHVDT.Delete();
	Super.Delete();
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}