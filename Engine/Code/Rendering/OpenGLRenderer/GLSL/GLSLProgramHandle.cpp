///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.4 (2024/01/15 11:03)

#include "Rendering/RenderingExport.h"

#include "GLSLProgramHandle.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Rendering::GLSLProgramHandle Rendering::GLSLProgramHandle::Create()
{
    return GLSLProgramHandle{ CoreTools::DisableNotThrow::Disable };
}

Rendering::GLSLProgramHandle::GLSLProgramHandle(CoreTools::DisableNotThrow disableNotThrow)
    : programHandle{ System::CreateGLProgram() }
{
    System::UnusedFunction(disableNotThrow);

    if (programHandle == 0u)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序创建失败。"))
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLProgramHandle::~GLSLProgramHandle() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    if (0 < programHandle && System::IsGLProgram(programHandle))
    {
        System::DeleteGLProgram(programHandle);
    }
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLProgramHandle)

Rendering::GLSLProgramHandle::OpenGLUInt Rendering::GLSLProgramHandle::GetProgramHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return programHandle;
}

void Rendering::GLSLProgramHandle::Link() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    System::LinkGLProgram(programHandle);

    if (!GetGLProgram(programHandle, System::ProgramStatus::Link))
    {
        if (const auto logLength = System::GetGLProgram(programHandle, System::ProgramAttributes::InfoLogLength);
            0 < logLength)
        {
            const auto message = System::GetGLProgramInfoLog(programHandle);

            THROW_EXCEPTION(SYSTEM_TEXT("链接失败:\n") + CoreTools::StringConversion::MultiByteConversionStandard(message))
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效信息日志长度。"))
        }
    }
}
