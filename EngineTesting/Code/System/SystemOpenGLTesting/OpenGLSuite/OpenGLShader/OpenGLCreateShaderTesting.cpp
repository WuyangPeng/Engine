/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:47)

#include "OpenGLCreateShaderTesting.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLCreateShaderTesting::OpenGLCreateShaderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLCreateShaderTesting)

void System::OpenGLCreateShaderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLCreateShaderTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateShaderTest);
}

void System::OpenGLCreateShaderTesting::CreateShaderTest()
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_TRUE(IsGLShader(shaderHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteShaderTest, shaderHandle);
}
