/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:08)

#include "Rendering/RenderingExport.h"

#include "ComputeProgram.h"
#include "Reflection.h"
#include "Detail/ComputeProgramFactory.h"
#include "Detail/ComputeProgramImpl.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ComputeProgram)

Rendering::ComputeProgram Rendering::ComputeProgram::Create()
{
    return ComputeProgram{ CoreTools::DisableNotThrow::Disable };
}

Rendering::ComputeProgram::ComputeProgramSharedPtr Rendering::ComputeProgram::Create(const std::string& computeShaderSource, const std::string& version, const ProgramDefines& defines)
{
    if (computeShaderSource.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序必须具有计算着色器。 "))
    }

    const auto programHandle = GLSLProgramHandle::Create();

    GLSLShaderHandle computeShaderHandle{ System::ShaderType::Compute, computeShaderSource, version, defines, programHandle.GetProgramHandle(), SYSTEM_TEXT("编译计算着色器失败。") };
    programHandle.Link();

    const auto program = std::make_shared<ComputeProgram>(programHandle, computeShaderHandle);
    program->CreateComputeShader();

    return program;
}

Rendering::ComputeProgram::ComputeProgram(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseFactory::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ComputeProgram::ComputeProgram(const GLSLProgramHandle& programHandle, const GLSLShaderHandle& computeShaderHandle)
    : impl{ CoreTools::ImplCreateUseFactory::Default, programHandle, computeShaderHandle }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ComputeProgram)

Rendering::ComputeProgram::ConstShaderSharedPtr Rendering::ComputeProgram::GetComputeShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetComputeShader();
}

Rendering::ComputeProgram::ShaderSharedPtr Rendering::ComputeProgram::GetComputeShader() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetComputeShader();
}

void Rendering::ComputeProgram::SetComputeShader(const ShaderSharedPtr& shader)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetComputeShader(shader);
}

Rendering::Reflection Rendering::ComputeProgram::GetReflector() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReflector();
}

void Rendering::ComputeProgram::CreateComputeShader()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateComputeShader();
}

Rendering::ComputeProgram::OpenGLUInt Rendering::ComputeProgram::GetProgramHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProgramHandle();
}
