#include "Renderer.h"
#include "SafetyCheck.h"
#include "Matrix4x4.h"

namespace feg {
	Renderer* Renderer::_instance;

	Renderer::Renderer() : _currentLayer(0), _layers()
	{
		_layers[0] = new VertexArray();
		Matrix4x4 mat;
	}

	Renderer& Renderer::Get()
	{
		if (_instance == nullptr) {
			_instance = new Renderer();
		}
		return *_instance;
	}
	void Renderer::Render(const IndexBuffer& ibo, const Shader& shader, const unsigned char& layer) const
	{
		shader.Use();
		GetVao(layer)->Bind();
		ibo.Bind();
		GLCALL(glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, nullptr));
		ibo.Unbind();
		GetVao(layer)->Unbind();
	}

	VertexArray* Renderer::GetVao(const unsigned char& layer) const
	{
		return _layers.at(layer);
	}

}