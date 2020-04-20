#include "Application.h"
#include "Mesh.h"
#include <iostream>
#include "Shader.h"
#include <string>
#include "Time.h"
#include "Drawer.h"

using namespace feg;

static const Vector3 vertices[4] = { Vector3(-0.5f, -0.5f, 0), Vector3(-0.5f, 0.5f, 0), Vector3(0.5f, 0.5f, 0), Vector3(0.5f, -0.5f, 0) };
static const uint16_t indices[6] = { 0, 1, 2, 0, 2, 3 };
static Mesh* mesh;

void render() {
	Application::SetTitle((std::to_string(int(1 / Time::getDeltaTime())) + " FPS").c_str());
}

int main()
{
	if (!Application::Initialize(800, 600, "Test window"))
		return -1;
	mesh = new Mesh();
	mesh->SetVertices(sizeof(vertices) / sizeof(*vertices), vertices);
	mesh->SetIndices(sizeof(indices) / sizeof(*indices), indices);
	Shader shad = Shader::Parse("resourses/shaders/default.shader");
	shad.Bind();
	Action act(render);
	Application::onUpdate.Subscribe(act);
	Application::Run();
	return 0;
}
