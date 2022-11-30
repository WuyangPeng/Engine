///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/06 21:06)

#include "Rendering/RenderingExport.h"

#include "GLSLVisualProgram.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Shaders/Flags/ShaderAPIType.h"

Rendering::GLSLVisualProgram::GLSLVisualProgram(OpenGLUInt programHandle, OpenGLUInt vertexShaderHandle, OpenGLUInt pixelShaderHandle, OpenGLUInt geometryShaderHandle)
    : ParentType{},
      programHandle{ programHandle },
      vertexShaderHandle{ vertexShaderHandle },
      pixelShaderHandle{ pixelShaderHandle },
      geometryShaderHandle{ geometryShaderHandle },
      reflector{ programHandle }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLVisualProgram::OpenGLUInt Rendering::GLSLVisualProgram::GetProgramHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return programHandle;
}

Rendering::GLSLVisualProgram::OpenGLUInt Rendering::GLSLVisualProgram::GetVertexShaderHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexShaderHandle;
}

Rendering::GLSLVisualProgram::OpenGLUInt Rendering::GLSLVisualProgram::GetPixelShaderHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pixelShaderHandle;
}

Rendering::GLSLVisualProgram::OpenGLUInt Rendering::GLSLVisualProgram::GetGShaderHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return geometryShaderHandle;
}

Rendering::GLSLReflection Rendering::GLSLVisualProgram::GetReflector() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return reflector;
}

Rendering::GLSLVisualProgram::VisualProgramSharedPtr Rendering::GLSLVisualProgram::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::GLSLVisualProgram::~GLSLVisualProgram() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    if (System::IsGLProgram(programHandle))
    {
        if (System::IsGLShader(vertexShaderHandle))
        {
            System::DetachGLShader(programHandle, vertexShaderHandle);
            System::DeleteGLShader(vertexShaderHandle);
        }

        if (System::IsGLShader(pixelShaderHandle))
        {
            System::DetachGLShader(programHandle, pixelShaderHandle);
            System::DeleteGLShader(pixelShaderHandle);
        }

        if (System::IsGLShader(geometryShaderHandle))
        {
            System::DetachGLShader(programHandle, geometryShaderHandle);
            System::DeleteGLShader(geometryShaderHandle);
        }

        System::DeleteGLProgram(programHandle);
    }
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GLSLVisualProgram)
