// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:35)

#ifndef RENDERING_DX9_RENDERER_DX9_PIXEL_SHADER_H
#define RENDERING_DX9_RENDERER_DX9_PIXEL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "Dx9Shader.h"
#include "Rendering/Shaders/PixelShader.h"


namespace Rendering
{

	class Renderer;

	class Dx9PixelShader : public Dx9Shader
	{
	public:
		// Construction and destruction.
		Dx9PixelShader(Renderer* renderer, const PixelShader* pshader);
		~Dx9PixelShader();

		// Pixel shader operations.
		void Enable(Renderer* renderer, const PixelShader* pshader, const ShaderParameters* parameters);
		void Disable(Renderer* renderer, const PixelShader* pshader, const ShaderParameters* parameters);

	private:
		IDirect3DPixelShader9* mShader;
	};

}

#endif // RENDERING_DX9_RENDERER_DX9_PIXEL_SHADER_H
