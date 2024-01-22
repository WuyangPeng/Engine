/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:30)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackUnitTestSuite.h"
#include "Detail/AndroidCallBackUnitTestSuiteImpl.h"
#include "System/Android/AndroidInputEventFacade.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowProcess/Detail/WindowMessageUnitTestSuiteStream.h"

Framework::AndroidCallBackUnitTestSuite::AndroidCallBackUnitTestSuite(int64_t delta, const std::string& suiteName)
    : ParentType{ delta }, impl{ suiteName }, isInit{ false }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::AndroidCallBackUnitTestSuite::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

bool Framework::AndroidCallBackUnitTestSuite::Initialize()
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (!isInit)
    {
        isInit = true;

        return AddSuiteOnInitialize();
    }
    else
    {
        return true;
    }
}

int Framework::AndroidCallBackUnitTestSuite::KeyDownMessage(AndroidApp* androidApp, AndroidInputEvent* androidInputEvent)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    System::AndroidInputEventFacade androidKeyEvent{ androidInputEvent };

    switch (const auto keyCode = androidKeyEvent.GetKeyCode();
            keyCode)
    {
        case System::AndroidKeyCodes::F1:
        {
            ResetTestData();
            break;
        }

        case System::AndroidKeyCodes::F5:
        {
            RunUnitTest();
            break;
        }

        default:
            break;
    }

    return ParentType::KeyDownMessage(androidApp, androidInputEvent);
}

void Framework::AndroidCallBackUnitTestSuite::Display(AndroidApp* androidApp, int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Display(androidApp, timeDelta);
}

void Framework::AndroidCallBackUnitTestSuite::AddSuite(const Suite& suite)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->AddSuite(suite);
}

CoreTools::OStreamShared Framework::AndroidCallBackUnitTestSuite::GetStreamShared() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->GetStreamShared();
}

int Framework::AndroidCallBackUnitTestSuite::GetPassedNumber() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->GetPassedNumber();
}

bool Framework::AndroidCallBackUnitTestSuite::AddSuiteOnInitialize()
{
    const auto result = ParentType::Initialize();

    InitSuite();

    impl->RunUnitTest();
    impl->PrintReport();

    return result;
}

void Framework::AndroidCallBackUnitTestSuite::ResetTestData()
{
    impl->ResetTestData();
    GetStreamShared() << "测试数据已清零。\n";
}

void Framework::AndroidCallBackUnitTestSuite::RunUnitTest()
{
    impl->RunUnitTest();
    impl->PrintReport();
}

void Framework::AndroidCallBackUnitTestSuite::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    impl->AddTest(suiteName, suite, testName, unitTest);
}

bool Framework::AndroidCallBackUnitTestSuite::IsPrintRun() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return true;
}

Framework::AndroidCallBackUnitTestSuite::Suite Framework::AndroidCallBackUnitTestSuite::GenerateSuite(const std::string& name)
{
    FRAMEWORK_CLASS_IS_VALID_CONST_1;

    return Suite{ name, GetStreamShared(), IsPrintRun() };
}
