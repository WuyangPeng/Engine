///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:25)

#include "OpenGLProgramLinkTesting.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLProgramLinkTesting::OpenGLProgramLinkTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLProgramLinkTesting)

void System::OpenGLProgramLinkTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLProgramLinkTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LinkTest);
}

void System::OpenGLProgramLinkTesting::LinkTest()
{
    const auto programHandle = CreateGLProgram();

    ASSERT_NOT_THROW_EXCEPTION_1(DoLinkTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLProgramTest, programHandle);
}

void System::OpenGLProgramLinkTesting::DoLinkTest(OpenGLUInt programHandle)
{
    ASSERT_TRUE(IsGLProgram(programHandle));

    LinkGLProgram(programHandle);

    const auto infoLog = GetGLProgramInfoLog(programHandle);

    ASSERT_TRUE(infoLog.empty());
}
