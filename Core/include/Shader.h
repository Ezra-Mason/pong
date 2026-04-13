
class Shader
{
public: 
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	
	void use();

};