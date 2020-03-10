// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:40)

#ifndef RENDERING_DX9_RENDERER_DX9_VERTEX_SHADER_H
#define RENDERING_DX9_RENDERER_DX9_VERTEX_SHADER_H

#include "Rendering/RenderingDll.h"

#include "Dx9Shader.h"
#include "Rendering/Shaders/VertexShader.h"

namespace Rendering
{

	class Renderer;

	class Dx9VertexShader : public Dx9Shader
	{
	public:
		// Construction and destruction
		Dx9VertexShader(Renderer* renderer, const VertexShader* vshader);
		~Dx9VertexShader();

		// Vertex shader operations.
		void Enable (Renderer* renderer, const VertexShader* vshader,const ShaderParameters* parameters);
		void Disable (Renderer* renderer, const VertexShader* vshader,const ShaderParameters* parameters);

	private:
		IDirect3DVertexShader9* mShader;
	};

}

#endif // RENDERING_DX9_RENDERER_DX9_VERTEX_SHADER_H
