///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/13 22:14)

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
