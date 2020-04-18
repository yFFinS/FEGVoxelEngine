#shader vertex
#version 460 core

layout(location = 0) in vec4 position;

void main(){
    gl_Position = vec4(position.y, position.x, 0, position.w);
}

#shader fragment
#version 460 core

layout(location = 0) out vec4 color;

void main() {
    color = vec4(1, 0.7, 0.7, 0.1);
}