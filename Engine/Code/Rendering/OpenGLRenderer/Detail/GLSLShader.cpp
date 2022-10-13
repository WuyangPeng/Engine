///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/19 18:04)

#include "Rendering/RenderingExport.h"

#include "GLSLShader.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GLSLShader)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::GLSLShader::Set(MAYBE_UNUSED const std::string& textureName, MAYBE_UNUSED const TextureSingleSharedPtr& texture, MAYBE_UNUSED const std::string& samplerName, MAYBE_UNUSED const SamplerStateSharedPtr& state)
{
    throw std::logic_error("The method or operation is not implemented.");
}

void Rendering::GLSLShader::Set(MAYBE_UNUSED const std::string& textureName, MAYBE_UNUSED const TextureArraySharedPtr& texture, MAYBE_UNUSED const std::string& samplerName, MAYBE_UNUSED const SamplerStateSharedPtr& state)
{
    throw std::logic_error("The method or operation is not implemented.");
}

#include STSTEM_WARNING_POP

bool Rendering::GLSLShader::IsValid(MAYBE_UNUSED const ShaderData& goal, MAYBE_UNUSED const ConstantBuffer* resource) const
{
    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::GLSLShader::IsValid(MAYBE_UNUSED const ShaderData& goal, MAYBE_UNUSED const SamplerState* state) const
{
    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::GLSLShader::IsValid(MAYBE_UNUSED const ShaderData& goal, MAYBE_UNUSED const TextureArray* resource) const
{
    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::GLSLShader::IsValid(MAYBE_UNUSED const ShaderData& goal, MAYBE_UNUSED const TextureSingle* resource) const
{
    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::GLSLShader::IsValid(MAYBE_UNUSED const ShaderData& goal, MAYBE_UNUSED const RawBuffer* resource) const
{
    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::GLSLShader::IsValid(MAYBE_UNUSED const ShaderData& goal, MAYBE_UNUSED const StructuredBuffer* resource) const
{
    throw std::logic_error("The method or operation is not implemented.");
}

bool Rendering::GLSLShader::IsValid(MAYBE_UNUSED const ShaderData& goal, MAYBE_UNUSED const TextureBuffer* resource) const
{
    throw std::logic_error("The method or operation is not implemented.");
}

Rendering::GLSLShader::ShaderSharedPtr Rendering::GLSLShader::Clone() const
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    return std::make_shared<ClassType>(*this);
}