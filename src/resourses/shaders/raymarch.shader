#shader vertex
#version 460 core

layout(location = 0) in vec4 position;
out vec3 rayDirection;

void main(){
    rayDirection = vec3(position.xyz);
    gl_Position = position;
}

#shader fragment
#version 460 core

layout(location = 0) out vec4 color;
in vec3 rayDirection;

const vec4 sphere1 = vec4(1, 1, 1, 1) / 3;
const vec4 sphere2 = vec4(1, -0.5, -0.5, 0.7) / 3;

float signedSphere(vec3 p, float r) {
    return length(p) - r;
}

vec4 raymarch(vec3 ro, vec3 rd) {
    const int maxIters = 640, maxDist = 1000;
    float total = 0;
    vec3 p = ro;
    for (int i = 0; i < maxIters; i++) {
        float dist = min(signedSphere(p - sphere1.xyz, sphere1.w), signedSphere(p - sphere2.xyz, sphere2.w));
        total += dist;
        p += dist * rd;
        if (dist < 0.01) {
            return vec4(1, 0, 0, 1);
        }
        if (total >= maxDist)
            break;
    }
    return vec4(0, 0, 0, 1);
}

void main() {
    color = raymarch(vec3(0, 0, 0), rayDirection);
}