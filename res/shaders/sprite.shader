@VERTEX
#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;

uniform mat4 uProjectionView;

out vec4 vColor;

void main()
{
    gl_Position = uProjectionView * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    vColor = aColor;
}


@FRAGMENT
#version 330 core

in vec4 vColor;

out vec4 FragColor;

void main()
{
   FragColor = vColor;
}