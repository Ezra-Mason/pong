#version 330 core
out vec4 FragColor;
in vec4 ourColour;
void main()
{
    FragColor = ourColour;
}