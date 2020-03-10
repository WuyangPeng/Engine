// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:15)

#ifndef RENDERING_RENDERERS_PLATFORM_PIXEL_SHADER_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_PIXEL_SHADER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "PlatformShaderImpl.h"

namespace Rendering
{
	class PixelShader;

	class RENDERING_HIDDEN_DECLARE PlatformPixelShaderImpl
    {
	public:
		using ClassType = PlatformPixelShaderImpl;
		using PlatformPixelShaderPtr = std::shared_ptr<ClassType>;

    public:
		PlatformPixelShaderImpl();
		virtual ~PlatformPixelShaderImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// Vertex shader operations.
		virtual void Enable(Renderer* renderer, const PixelShader* pixelShader,const ShaderParameters* parameters) = 0;
		virtual void Disable(Renderer* renderer, const PixelShader* pixelShader,const ShaderParameters* parameters) = 0;
    };
}

#endif // RENDERING_RENDERERS_PLATFORM_PIXEL_SHADER_IMPL_H
