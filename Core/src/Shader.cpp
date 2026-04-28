#include "Shader.h"
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexShaderStr, fragmentShaderStr;
	std::ifstream vertShaderFile, fragShaderFile;

	vertShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fragShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::filesystem::path root = std::filesystem::current_path();
	std::filesystem::path v(vertexPath);
	std::filesystem::path f(fragmentPath);
	auto vertPath = root / v;
	auto fragPath = root / f;

	// read file data
	try
	{
		vertShaderFile.open(vertPath);
		fragShaderFile.open(fragPath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vertShaderFile.rdbuf();
		fShaderStream << fragShaderFile.rdbuf();

		vertShaderFile.close();
		fragShaderFile.close();

		vertexShaderStr = vShaderStream.str();
		fragmentShaderStr = fShaderStream.str();
	}
	catch (std::ifstream::failure& err)
	{
		std::cout << "Shader Error: could not successfully read file: " << vertexPath<<", err: " << err.what() << std::endl;
	}

	const char* vertShaderCode = vertexShaderStr.c_str();
	const char* fragShaderCode = fragmentShaderStr.c_str();

	// compile and link the shaders
	unsigned int vertexId, fragmentId;
	int compSuccess, linkSuccess;
	char infoLog[512];
	// vertex shader
	vertexId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexId, 1, &vertShaderCode, NULL);
	glCompileShader(vertexId);
	glGetShaderiv(vertexId, GL_COMPILE_STATUS, &compSuccess);
	if (!compSuccess)
	{
		glGetShaderInfoLog(vertexId, 512, NULL, infoLog);
		std::cout << "Error: failed to compile vertex shader at path " << vertexPath << "\n infolog: "<< infoLog << std::endl;
	}
	// fragment shader
	fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentId, 1, &fragShaderCode, NULL);
	glCompileShader(fragmentId);
	glGetShaderiv(fragmentId, GL_COMPILE_STATUS, &compSuccess);
	if (!compSuccess)
	{
		glGetShaderInfoLog(fragmentId, 512, NULL, infoLog);
		std::cout << "Error: failed to compile fragment shader at path " << fragmentPath << std::endl;
	}

	// create shader program and link shaders
	ID = glCreateProgram();
	glAttachShader(ID, vertexId);
	glAttachShader(ID, fragmentId);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &linkSuccess);
	if (!linkSuccess)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "Error: failed to link shader program" << std::endl;
	}

	// shaders are linked to program, can delete now
	glDeleteShader(vertexId);
	glDeleteShader(fragmentId);
}

void Shader::use()
{
	glUseProgram(ID);
}
