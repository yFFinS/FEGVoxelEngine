#include "Drawer.h"
#include "Application.h"

namespace feg {

	VertexBuffer* Drawer::_vbo;
	IndexBuffer* Drawer::_ibo;
	Shader* Drawer::_shader;


	void Drawer::Rect(float x, float y, float width, float height)
	{
		const float& swidth = Application::getWidth();
		const float& sheight = Application::getHeight();
		const float& nx = x / swidth, ny = y / sheight, nwidth = width / swidth, nheight = height / sheight;
		Vector3 data[4] = { Vector3(nx, ny, 0), Vector3(nx + nwidth, ny, 0), Vector3(nx, ny + nheight, 0), Vector3(nx + nwidth, ny + nheight, 0) };
		unsigned int indices[6] = { 0, 2, 3, 0, 3, 1 };
		_vbo->SetData(4, data);
		_ibo->SetIndices(6, indices);
		_shader->Use();
		_ibo->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		_ibo->Unbind();
	}

	void Drawer::Initialize()
	{
		_vbo = new VertexBuffer();
		_ibo = new IndexBuffer();
		VertexBufferLayout vbl;
		vbl.Push<float>(3);
		Application::vao->AddBuffer(*_vbo, vbl);
		_shader = &Shader::Parse("resourses/shaders/default.shader");
	}

}