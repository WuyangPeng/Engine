///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/31 15:15)

#include "Rendering/RenderingExport.h"

#include "GLSLReflection.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLInit.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionImpl.h"
#include "Rendering/OpenGLRenderer/Flags/ReferenceType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GLSLReflection)

Rendering::GLSLReflection::GLSLReflection(OpenGLUInt handle)
    : impl{ handle }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflection)

Rendering::GLSLReflection::OpenGLUInt Rendering::GLSLReflection::GetProgramHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProgramHandle();
}

Rendering::GLSLReflection::InputContainer Rendering::GLSLReflection::GetInputs() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetInputs();
}

Rendering::GLSLReflection::OutputContainer Rendering::GLSLReflection::GetOutputs() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOutputs();
}

Rendering::GLSLReflection::UniformContainer Rendering::GLSLReflection::GetUniforms() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetUniforms();
}

Rendering::GLSLReflection::DataBlockContainer Rendering::GLSLReflection::GetUniformBlocks() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetUniformBlocks();
}

Rendering::GLSLReflection::BufferVariableContainer Rendering::GLSLReflection::GetBufferVariables() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferVariables();
}

Rendering::GLSLReflection::DataBlockContainer Rendering::GLSLReflection::GetBufferBlocks() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferBlocks();
}

Rendering::GLSLReflection::AtomicCounterBufferContainer Rendering::GLSLReflection::GetAtomicCounterBuffers() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAtomicCounterBuffers();
}

Rendering::GLSLReflection::NumThreads Rendering::GLSLReflection::GetComputeShaderWorkGroupSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetComputeShaderWorkGroupSize();
}

void Rendering::GLSLReflection::Print(std::ofstream& output) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->Print(output);
}
