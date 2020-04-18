#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include <map>

namespace feg {

	class Renderer
	{
	private:
		std::map<unsigned char, VertexArray*> _layers;
		unsigned char _currentLayer;
		static Renderer* _instance;
	private:
		Renderer();
		Renderer(const Renderer&) = delete;
		Renderer& operator=(Renderer&) = delete;

	public:
		static Renderer& Get();

		void Render(const IndexBuffer& ibo, const Shader& shader, const unsigned char& layer = 0) const;
		VertexArray* GetVao(const unsigned char& layer) const;
	};

}

#endif //!RENDERER_H
