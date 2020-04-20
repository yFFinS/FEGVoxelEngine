#include "Renderer.h"
#include "SafetyCheck.h"
#include "Matrix4x4.h"

namespace feg {


	void Renderer::Render(const std::shared_ptr<VertexArray>& vao, const Shader& shader)
	{
		shader.Bind();
		vao->Bind();
		GLCALL(glDrawElements(GL_TRIANGLES, vao->GetIndexBuffer()->GetCount(), GL_UNSIGNED_SHORT, nullptr));
		vao->Unbind();
		shader.Unbind();
	}

}