/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:05)

#include "Rendering/RenderingExport.h"

#include "ComputeProgramImpl.h"
#include "NullComputeProgram.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Shaders/Flags/ReferenceType.h"
#include "Rendering/Shaders/Reflection.h"
#include "Rendering/Shaders/Shader.h"

Rendering::ComputeProgramImpl::ComputeProgramImpl() noexcept
    : computeShader{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ComputeProgramImpl)

Rendering::ComputeProgramImpl::ConstShaderSharedPtr Rendering::ComputeProgramImpl::GetComputeShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return computeShader;
}

Rendering::ComputeProgramImpl::ShaderSharedPtr Rendering::ComputeProgramImpl::GetComputeShader() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return computeShader;
}

void Rendering::ComputeProgramImpl::SetComputeShader(const ShaderSharedPtr& shader)
{
    RENDERING_CLASS_IS_VALID_9;

    if (shader->GetType() != GraphicsObjectType::ComputeShader)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入必须是计算着色器。"))
    }

    computeShader = shader;
}

void Rendering::ComputeProgramImpl::CreateComputeShader()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto reflector = GetReflector();
    const auto shader = std::make_shared<Shader>(GraphicsObjectType::ComputeShader, RendererTypes::OpenGL, reflector, ReferenceType::Compute);

    SetComputeShader(shader);
}
