#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;
uniform vec2 theta;

void main()
{

    gl_Position = vec4(aPos.x*theta.x-aPos.y*theta.y, aPos.x*theta.y + aPos.y * theta.x, aPos.z, 1.0);
    ourColor.x = (aColor.x + theta.x)*0.5;
    ourColor.y = (aColor.y + theta.y)*0.5;
    ourColor.z = aColor.z;
}