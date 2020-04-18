#pragma once
#ifndef DRAWER_H
#define DRAWER_H
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"

namespace feg {

	class Drawer
	{
	private:
		static VertexBuffer* _vbo;
		static IndexBuffer* _ibo;
		static Shader* _shader;
	public:
		static void Rect(float x, float y, float width, float height);
		static void Initialize();
	};
}



#endif // !DRAWER_H
