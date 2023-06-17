///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:35)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_SHADER_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_SHADER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformVertexShaderImpl
    {
    public:
        using ClassType = PlatformVertexShaderImpl;
        using PlatformVertexShaderPtr = std::shared_ptr<ClassType>;

    public:
        PlatformVertexShaderImpl() noexcept;
        virtual ~PlatformVertexShaderImpl() noexcept = default;
        PlatformVertexShaderImpl(const PlatformVertexShaderImpl& rhs) noexcept = default;
        PlatformVertexShaderImpl& operator=(const PlatformVertexShaderImpl& rhs) noexcept = default;
        PlatformVertexShaderImpl(PlatformVertexShaderImpl&& rhs) noexcept = default;
        PlatformVertexShaderImpl& operator=(PlatformVertexShaderImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Enable(Renderer* renderer, const VertexShader* vertexShader, const ShaderParameters* parameters) = 0;
        virtual void Disable(Renderer* renderer, const VertexShader* vertexShader, const ShaderParameters* parameters) = 0;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_VERTEX_SHADER_IMPL_H
