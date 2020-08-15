// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:14)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLShader.h"
#include "Rendering/Shaders/VertexShader.h"

namespace Rendering
{
	class Renderer;

	class PdrVertexShader : public OpenGLShader
	{
	public:
		// Construction and destruction
		PdrVertexShader (Renderer* renderer, const VertexShader* vshader);
		~PdrVertexShader ();
		PdrVertexShader(const PdrVertexShader&) = default;
		PdrVertexShader& operator=(const PdrVertexShader&) = default;
		PdrVertexShader( PdrVertexShader&&) = default;
		PdrVertexShader& operator=( PdrVertexShader&&) = default;

		// Vertex shader operations.
		void Enable (Renderer* renderer, const VertexShader* vshader,const ShaderParameters* parameters);
		void Disable (Renderer* renderer, const VertexShader* vshader,const ShaderParameters* parameters);

	private:
		GLuint mShader = 0;
	};

}

#endif // RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H
