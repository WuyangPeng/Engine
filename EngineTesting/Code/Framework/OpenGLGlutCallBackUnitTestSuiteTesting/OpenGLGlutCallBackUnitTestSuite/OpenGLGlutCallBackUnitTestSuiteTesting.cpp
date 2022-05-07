// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.4 (2019/09/17 09:37)

#include "OpenGLGlutCallBackUnitTestSuiteTesting.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/OpenGLGlutCallBackUnitTestSuiteTesting/OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack.h"

using std::ostream;

OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTesting::OpenGLGlutCallBackUnitTestSuiteTesting(OpenGLGlutCallBackUnitTestSuiteTestingOpenGLGlutCallBack* message, const OStreamShared& osPtr)
    : ParentType(osPtr), m_Message(message)
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
