/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:47)

#include "OpenGLShaderStatusTesting.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLShaderStatusTesting::OpenGLShaderStatusTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLShaderStatusTesting)

void System::OpenGLShaderStatusTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLShaderStatusTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ShaderStatusTest);
}

void System::OpenGLShaderStatusTesting::ShaderStatusTest()
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_NOT_THROW_EXCEPTION_1(DoShaderStatusTest, shaderHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteShaderTest, shaderHandle);
}

void System::OpenGLShaderStatusTesting::DoShaderStatusTest(OpenGLUnsignedInt shaderHandle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(ShaderSourceTest, shaderHandle);

    ASSERT_EQUAL(GetGLShader(shaderHandle, ShaderStatus::Compile), false);

    CompileGLShader(shaderHandle);

    ASSERT_EQUAL(GetGLShader(shaderHandle, ShaderStatus::Compile), true);

    ASSERT_EQUAL(GetGLShader(shaderHandle, ShaderStatus::Delete), false);
}
