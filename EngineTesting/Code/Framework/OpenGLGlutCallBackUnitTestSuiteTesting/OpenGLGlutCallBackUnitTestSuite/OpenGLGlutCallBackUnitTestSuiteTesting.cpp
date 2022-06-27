///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 16:34)

#include "OpenGLGlutCallBackUnitTestSuiteTesting.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/OpenGLGlutCallBackUnitTestSuiteTesting/OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack.h"

OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTesting(const OStreamShared& ostream, OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack* message)
    : ParentType(ostream), m_Message(message)
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(OpenGLGlutCallBackUnitTestSuiteTesting, OpenGLGlutCallBackUnitTestSuiteTesting)

void OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(KeyDownMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DisplayTest);
}

void OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTesting::KeyDownMessageTest()
{
    ASSERT_TRUE(m_Message->SpecialKeysDown(static_cast<int>(System::GlutKeyCodes::F1), 0, 0));

    ASSERT_EQUAL(m_Message->GetPassedNumber(), 1);
}

void OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTesting::CreateMessageTest()
{
    ASSERT_TRUE(m_Message->Initialize());
}

void OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTesting::DisplayTest()
{
    ASSERT_TRUE(m_Message->IdleFunction());
}
