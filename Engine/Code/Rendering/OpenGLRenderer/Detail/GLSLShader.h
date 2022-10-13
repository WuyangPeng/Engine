///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/19 18:04)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_SHADER_H
#define RENDERING_OPENGL_RENDERER_GLSL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/Detail/ShaderImpl.h"

namespace Rendering
{
    class GLSLShader : public ShaderImpl
    {
    public:
        using ClassType = GLSLShader;
        using ParentType = ShaderImpl;

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Set(const std::string& textureName, const TextureSingleSharedPtr& texture, const std::string& samplerName, const SamplerStateSharedPtr& state) override;
        void Set(const std::string& textureName, const TextureArraySharedPtr& texture, const std::string& samplerName, const SamplerStateSharedPtr& state) override;

        NODISCARD bool IsValid(const ShaderData& goal, const ConstantBuffer* resource) const override;
        NODISCARD bool IsValid(const ShaderData& goal, const TextureBuffer* resource) const override;
        NODISCARD bool IsValid(const ShaderData& goal, const StructuredBuffer* resource) const override;
        NODISCARD bool IsValid(const ShaderData& goal, const RawBuffer* resource) const override;
        NODISCARD bool IsValid(const ShaderData& goal, const TextureSingle* resource) const override;
        NODISCARD bool IsValid(const ShaderData& goal, const TextureArray* resource) const override;
        NODISCARD bool IsValid(const ShaderData& goal, const SamplerState* state) const override;

        NODISCARD ShaderSharedPtr Clone() const override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H
