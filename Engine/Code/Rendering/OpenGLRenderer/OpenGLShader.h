// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:06)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_SHADER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "OpenGLRendererData.h" 
#include "Rendering/Shaders/ShaderBase.h"
#include "Rendering/Shaders/ShaderParameters.h"

namespace Rendering
{

	class Renderer;

	class OpenGLShader
	{
	public:
		// Construction and destruction.  The derived classes are
		// PdrVertexShader and PdrPixelShader.  Both classes hide the
		// base-class destructor.  This is not a problem because the
		// derived-class destructors are called explicitly when the shaders
		// are destroyed by Renderer.
		OpenGLShader() noexcept; 

	protected:
		void SetSamplerState (Renderer* renderer, const ShaderBase* shader,int profile, 
							  const ShaderParameters* parameters, int maxSamplers,RendererData::SamplerState* currentSS);

		void DisableTextures (Renderer* renderer, const ShaderBase* shader,int profile, const ShaderParameters* parameters, int maxSamplers);
	};

}

#endif // RENDERING_OPENGL_RENDERER_OPENGL_SHADER_H
