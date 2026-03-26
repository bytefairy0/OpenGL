#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 ourColor;
uniform float xoffset;

void main(){
    // To draw upside down triangle
    // gl_Position = vec4(aPos.x, -aPos.y, aPos.z, 1.0);
    // To move it to right
    gl_Position = vec4(aPos.x + xoffset, aPos.y, aPos.z, 1.0);
    ourColor = aColor;
}