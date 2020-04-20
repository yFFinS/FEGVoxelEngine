#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace feg {

	class Renderer
	{
	private:
		Renderer() = delete;

	public:
		static void Render(const std::shared_ptr<VertexArray>& vao, const Shader& shader);
	};

}

#endif //!RENDERER_H
