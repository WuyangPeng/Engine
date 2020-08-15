// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:29)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_SHADER_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_SHADER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "PlatformShaderImpl.h"

namespace Rendering
{
	class VertexShader;

	class RENDERING_HIDDEN_DECLARE PlatformVertexShaderImpl
    {
	public:
		using ClassType = PlatformVertexShaderImpl;
		using PlatformVertexShaderPtr = std::shared_ptr<ClassType>;

    public:
		PlatformVertexShaderImpl() noexcept;
		virtual ~PlatformVertexShaderImpl();
		PlatformVertexShaderImpl(const PlatformVertexShaderImpl&) = default;
		PlatformVertexShaderImpl& operator=(const PlatformVertexShaderImpl&) = default;
		PlatformVertexShaderImpl(PlatformVertexShaderImpl&&) = default;
		PlatformVertexShaderImpl& operator=(PlatformVertexShaderImpl&&) = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// Vertex shader operations.
		virtual void Enable(Renderer* renderer, const VertexShader* vertexShader,const ShaderParameters* parameters) = 0;
		virtual void Disable(Renderer* renderer, const VertexShader* vertexShader,const ShaderParameters* parameters) = 0;
    };
}

#endif // RENDERING_RENDERERS_PLATFORM_VERTEX_SHADER_IMPL_H
