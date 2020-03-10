// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:01)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_PIXEL_SHADER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_PIXEL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLShader.h"

#include "Rendering/Shaders/PixelShader.h"

namespace Rendering
{
	class Renderer;

	class PdrPixelShader : public OpenGLShader
	{
	public:
		// Construction and destruction.
		PdrPixelShader (Renderer* renderer, const PixelShader* pshader);
		~PdrPixelShader ();

		// Pixel shader operations.
		void Enable (Renderer* renderer, const PixelShader* pshader,const ShaderParameters* parameters);
		void Disable (Renderer* renderer, const PixelShader* pshader,const ShaderParameters* parameters);

	private:
		GLuint mShader;
	};

}

#endif // RENDERING_OPENGL_RENDERER_OPENGL_PIXEL_SHADER_H
