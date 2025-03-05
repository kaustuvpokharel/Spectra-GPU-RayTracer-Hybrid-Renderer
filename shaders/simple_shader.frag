#version 450

//layout qualifier which takes location value, i.e takes location 0.
layout (location = 0) out vec4 outColor;

void main()
{
    outColor = vec4(1.0, 0.0, 0.0, 1.0);
}
