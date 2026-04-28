
class Shader
{
public: 
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	
	// activate the shader
	void use();

};