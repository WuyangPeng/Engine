/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:45)

#include "OpenGLCreateProgramTesting.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLCreateProgramTesting::OpenGLCreateProgramTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLCreateProgramTesting)

void System::OpenGLCreateProgramTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLCreateProgramTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateProgramTest);
}

void System::OpenGLCreateProgramTesting::CreateProgramTest()
{
    const auto programHandle = CreateGLProgram();

    ASSERT_TRUE(IsGLProgram(programHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLProgramTest, programHandle);
}
