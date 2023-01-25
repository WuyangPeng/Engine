///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/13 13:06)

#include "OpenGLProgramTestingBase.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLProgramTestingBase::OpenGLProgramTestingBase(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLProgramTestingBase)

void System::OpenGLProgramTestingBase::DeleteGLProgramTest(OpenGLUInt programHandle) noexcept
{
    DeleteGLProgram(programHandle);
}

void System::OpenGLProgramTestingBase::DeleteGLShaderTest(OpenGLUInt shaderHandle) noexcept
{
    DeleteGLShader(shaderHandle);
}
