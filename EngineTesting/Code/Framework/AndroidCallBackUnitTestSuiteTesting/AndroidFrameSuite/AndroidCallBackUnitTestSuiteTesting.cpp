// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.0.4 (2019/09/10 14:34)

#include "AndroidCallBackUnitTestSuiteTesting.h"
#include "System/Android/Flags/AndroidInputFlags.h"
#include "System/Android/Using/AndroidInputUsing.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidCallBackUnitTestSuiteTesting/AndroidCallBackUnitTestSuiteTestingAndroidCallBack.h"
#include "Framework/WindowProcess/WindowMessageUnitTestSuite.h"

using std::ostream;

AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting(const CoreTools::OStreamShared& osPtr, AndroidCallBackUnitTestSuiteTestingAndroidCallBack* message)
    : ParentType{ osPtr }, m_Message{ message }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(AndroidCallBackUnitTestSuiteTesting, AndroidCallBackUnitTestSuiteTesting)

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(KeyDownMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMessageTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DisplayTest);
}

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::KeyDownMessageTest()
{
    System::AndroidInputEvent event;
    event.SetAndroidKeyCodes(System::AndroidKeyCodes::F1);
    ASSERT_EQUAL(m_Message->KeyDownMessage(m_Message->GetAndroidApp(), &event), 0);

    ASSERT_EQUAL(m_Message->GetPassedNumber(), 1);
}

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::CreateMessageTest()
{
    ASSERT_TRUE(m_Message->Initialize());
}

void AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting::DisplayTest()
{
    m_Message->Display(m_Message->GetAndroidApp(), 0);
}
