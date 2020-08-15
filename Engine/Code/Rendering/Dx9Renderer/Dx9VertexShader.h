// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:40)

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
                Dx9VertexShader(const Dx9VertexShader&) = default;
                Dx9VertexShader& operator=(const Dx9VertexShader&) = default;
                Dx9VertexShader( Dx9VertexShader&&) = default;
                Dx9VertexShader& operator=( Dx9VertexShader&&) = default;

		// Vertex shader operations.
		void Enable (Renderer* renderer, const VertexShader* vshader,const ShaderParameters* parameters);
		void Disable (Renderer* renderer, const VertexShader* vshader,const ShaderParameters* parameters);

	private:
		IDirect3DVertexShader9* mShader = nullptr;
	};

}

#endif // RENDERING_DX9_RENDERER_DX9_VERTEX_SHADER_H
