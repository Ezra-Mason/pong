#include "Shader.h"
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode, fragmentCode;
	std::ifstream vertShaderFile, fragShaderFile;

	vertShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vertShaderFile.open(vertexPath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vertShaderFile.rdbuf();
		
		vertShaderFile.close();

		vertexCode = vShaderStream.str();
	}
	catch (std::ifstream::failure err)
	{
		printf("%s", "Shader Error: could not successfully read file");
	}

	const char* vertShaderCode = vertexCode.c_str();

	unsigned int vertexId, fragmentId;
	vertexId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexId, 1, &vertShaderCode, NULL);
	glCompileShader(vertexId);


	ID = 0; //glCreateProgram()
}

void Shader::use()
{
}
