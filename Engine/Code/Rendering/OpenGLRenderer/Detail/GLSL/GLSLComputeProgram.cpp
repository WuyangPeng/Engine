///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/06 21:06)

#include "Rendering/RenderingExport.h"

#include "GLSLComputeProgram.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Shaders/Flags/ShaderAPIType.h"

Rendering::GLSLComputeProgram::GLSLComputeProgram(OpenGLUInt programHandle, OpenGLUInt computeShaderHandle)
    : ParentType{},
      programHandle{ programHandle },
      computeShaderHandle{ computeShaderHandle },
      reflector{ programHandle }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLComputeProgram::OpenGLUInt Rendering::GLSLComputeProgram::GetProgramHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return programHandle;
}

Rendering::GLSLComputeProgram::OpenGLUInt Rendering::GLSLComputeProgram::GetComputeShaderHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return computeShaderHandle;
}

Rendering::GLSLReflection Rendering::GLSLComputeProgram::GetReflector() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return reflector;
}

Rendering::GLSLComputeProgram::ComputeProgramSharedPtr Rendering::GLSLComputeProgram::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    
    return std::make_shared<ClassType>(*this);
}

Rendering::GLSLComputeProgram::~GLSLComputeProgram() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    if (System::IsGLProgram(programHandle))
    {
        if (System::IsGLShader(computeShaderHandle))
        {
            System::DetachGLShader(programHandle, computeShaderHandle);
            System::DeleteGLShader(computeShaderHandle);
        }

        System::DeleteGLProgram(programHandle);
    }
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GLSLComputeProgram)
