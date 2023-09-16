///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:26)

#include "OpenGLAttachShaderTesting.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLAttachShaderTesting::OpenGLAttachShaderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLAttachShaderTesting)

void System::OpenGLAttachShaderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLAttachShaderTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AttachShaderTest);
}

void System::OpenGLAttachShaderTesting::AttachShaderTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE_FAILURE_THROW(IsGLProgram(programHandle), "创建GL Program失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(CreateShaderTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteProgramTest, programHandle);
}

void System::OpenGLAttachShaderTesting::CreateShaderTest(OpenGLUInt programHandle)
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);
    ASSERT_NOT_THROW_EXCEPTION_2(DoAttachShaderTest, programHandle, shaderHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteShaderTest, shaderHandle);
}

void System::OpenGLAttachShaderTesting::DoAttachShaderTest(OpenGLUInt programHandle, OpenGLUInt shaderHandle)
{
    AttachGLShader(programHandle, shaderHandle);

    ASSERT_NOT_THROW_EXCEPTION_2(GetAttachedGLShadersTest, programHandle, shaderHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(GetGLShaderInfoLogTest, shaderHandle);

    DetachGLShader(programHandle, shaderHandle);
}

void System::OpenGLAttachShaderTesting::GetAttachedGLShadersTest(OpenGLUInt programHandle, OpenGLUInt shaderHandle)
{
    OpenGLUInt shaderResult{ 0 };
    GetAttachedGLShaders(programHandle, 1, nullptr, &shaderResult);
    ASSERT_EQUAL(shaderResult, shaderHandle);
}

void System::OpenGLAttachShaderTesting::GetGLShaderInfoLogTest(OpenGLUInt shaderHandle)
{
    const auto infoLog = GetGLShaderInfoLog(shaderHandle);

    ASSERT_TRUE(infoLog.empty());
}
