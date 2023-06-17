///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:52)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackUnitTestSuite.h"
#include "Detail/AndroidCallBackUnitTestSuiteImpl.h"
#include "System/Android/AndroidInputEventFacade.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"
#include "Framework/WindowProcess/Detail/WindowMessageUnitTestSuiteStream.h"

Framework::AndroidCallBackUnitTestSuite::AndroidCallBackUnitTestSuite(int64_t delta, const std::string& suiteName)
    : ParentType{ delta }, streamType{ std::make_shared<StreamType>(true) }, impl{ suiteName, streamType->GetStreamShared() }, isInit{ false }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AndroidCallBackUnitTestSuite::AndroidCallBackUnitTestSuite(AndroidCallBackUnitTestSuite&& rhs) noexcept
    : ParentType{ std::move(rhs) }, streamType{ move(rhs.streamType) }, impl{ std::move(rhs.impl) }, isInit{ rhs.isInit }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AndroidCallBackUnitTestSuite& Framework::AndroidCallBackUnitTestSuite::operator=(AndroidCallBackUnitTestSuite&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(std::move(rhs));

    streamType = move(rhs.streamType);
    impl = std::move(rhs.impl);
    isInit = rhs.isInit;

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::AndroidCallBackUnitTestSuite::IsValid() const noexcept
{
    if (ParentType::IsValid() && streamType != nullptr)
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

    const auto keyCode = androidKeyEvent.GetKeyCode();

    switch (keyCode)
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

    return streamType->GetStreamShared();
}

int Framework::AndroidCallBackUnitTestSuite::GetPassedNumber() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->GetPassedNumber();
}

// private
bool Framework::AndroidCallBackUnitTestSuite::AddSuiteOnInitialize()
{
    const auto result = ParentType::Initialize();

    InitSuite();

    impl->RunUnitTest();
    impl->PrintReport();

    return result;
}

// private
void Framework::AndroidCallBackUnitTestSuite::ResetTestData()
{
    impl->ResetTestData();
    GetStreamShared() << "�������������㡣\n";
}

// private
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
