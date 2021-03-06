#pragma once
#ifndef RENDERER_H
#define RENDERER_H

namespace feg {

	class Renderer
	{
	private:
		Renderer() = delete;

	public:
		static void Render(const std::shared_ptr<VertexArray>& vao, const std::shared_ptr<Shader>& shader);
	};

}

#endif //!RENDERER_H
