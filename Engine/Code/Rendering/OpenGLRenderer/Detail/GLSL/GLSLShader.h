/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/09 16:56)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_SHADER_H
#define RENDERING_OPENGL_RENDERER_GLSL_SHADER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Detail/ShaderImpl.h"

namespace Rendering
{
    class GLSLShader : public ShaderImpl
    {
    public:
        using ClassType = GLSLShader;
        using ParentType = ShaderImpl;

    public:
        GLSLShader(const Reflection& reflector, ReferenceType referenceType);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Set(const std::string& textureName, const TextureSingleSharedPtr& texture, const std::string& samplerName, const SamplerStateSharedPtr& state) override;
        void Set(const std::string& textureName, const TextureArraySharedPtr& texture, const std::string& samplerName, const SamplerStateSharedPtr& state) override;

        NODISCARD bool IsValid(const ShaderData& goal, const ConstantBuffer* resource) const noexcept override;
        NODISCARD bool IsValid(const ShaderData& goal, const TextureBuffer* resource) const noexcept override;
        NODISCARD bool IsValid(const ShaderData& goal, const StructuredBuffer* resource) const noexcept override;
        NODISCARD bool IsValid(const ShaderData& goal, const RawBuffer* resource) const noexcept override;
        NODISCARD bool IsValid(const ShaderData& goal, const TextureSingle* resource) const override;
        NODISCARD bool IsValid(const ShaderData& goal, const TextureArray* resource) const override;
        NODISCARD bool IsValid(const ShaderData& goal, const SamplerState* state) const noexcept override;

        NODISCARD ShaderSharedPtr Clone() const override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_VERTEX_SHADER_H
