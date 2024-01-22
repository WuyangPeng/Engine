/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 17:14)

#include "Rendering/RenderingExport.h"

#include "GLSLVisualProgram.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::GLSLVisualProgram::GLSLVisualProgram(const GLSLProgramHandle& programHandle, const GLSLShaderHandle& vertexShaderHandle, const GLSLShaderHandle& pixelShaderHandle, const GLSLShaderHandle& geometryShaderHandle)
    : ParentType{},
      programHandle{ programHandle },
      vertexShaderHandle{ vertexShaderHandle },
      pixelShaderHandle{ pixelShaderHandle },
      geometryShaderHandle{ geometryShaderHandle },
      reflector{ programHandle.GetProgramHandle() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLVisualProgram::OpenGLUInt Rendering::GLSLVisualProgram::GetProgramHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return programHandle.GetProgramHandle();
}

Rendering::GLSLVisualProgram::OpenGLUInt Rendering::GLSLVisualProgram::GetVertexShaderHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexShaderHandle.GetShaderHandle();
}

Rendering::GLSLVisualProgram::OpenGLUInt Rendering::GLSLVisualProgram::GetPixelShaderHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return pixelShaderHandle.GetShaderHandle();
}

Rendering::GLSLVisualProgram::OpenGLUInt Rendering::GLSLVisualProgram::GetGShaderHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return geometryShaderHandle.GetShaderHandle();
}

Rendering::Reflection Rendering::GLSLVisualProgram::GetReflector() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return reflector;
}

Rendering::GLSLVisualProgram::VisualProgramSharedPtr Rendering::GLSLVisualProgram::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GLSLVisualProgram)
