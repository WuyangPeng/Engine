///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/20 16:17)

#include "Rendering/RenderingExport.h"

#include "ComputeProgramImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLComputeProgram.h"
#include "Rendering/Shaders/Shader.h"

Rendering::ComputeProgramImpl::ComputeProgramSharedPtr Rendering::ComputeProgramImpl::Create(OpenGLUInt programHandle, OpenGLUInt computeShaderHandle)
{
    return std::make_shared<GLSLComputeProgram>(programHandle, computeShaderHandle);
}

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

void Rendering::ComputeProgramImpl::SetComputeShader(const ShaderSharedPtr& shader)
{
    RENDERING_CLASS_IS_VALID_9;

    if (shader->GetType() != GraphicsObjectType::ComputeShader)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入必须是计算着色器。"));
    }

    computeShader = shader;
}

Rendering::GLSLReflection Rendering::ComputeProgramImpl::GetReflector() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GLSLReflection{ 0 };
}

Rendering::ComputeProgramImpl::ComputeProgramSharedPtr Rendering::ComputeProgramImpl::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}
