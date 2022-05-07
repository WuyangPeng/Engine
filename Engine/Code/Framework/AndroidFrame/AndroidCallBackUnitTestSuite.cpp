///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 18:51)

#include "Framework/FrameworkExport.h"

#include "AndroidCallBackUnitTestSuite.h"
#include "Detail/AndroidCallBackUnitTestSuiteImpl.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"
#include "Framework/WindowProcess/Detail/WindowMessageUnitTestSuiteStream.h"

using std::make_shared;
using std::move;
using std::string;

Framework::AndroidCallBackUnitTestSuite::AndroidCallBackUnitTestSuite(int64_t delta, const string& suiteName)
    : ParentType{ delta }, streamType{ make_shared<StreamType>(true) }, impl{ suiteName, streamType->GetStreamShared() }, isInit{ false }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AndroidCallBackUnitTestSuite::AndroidCallBackUnitTestSuite(AndroidCallBackUnitTestSuite&& rhs) noexcept
    : ParentType{ move(rhs) }, streamType{ move(rhs.streamType) }, impl{ move(rhs.impl) }, isInit{ rhs.isInit }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

Framework::AndroidCallBackUnitTestSuite& Framework::AndroidCallBackUnitTestSuite::operator=(AndroidCallBackUnitTestSuite&& rhs) noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    ParentType::operator=(move(rhs));

    streamType = move(rhs.streamType);
    impl = move(rhs.impl);
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

    const auto keyCode = System::AndroidKeyEventGetKeyCode(androidInputEvent);

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
    GetStreamShared() << "测试数据已清零。\n";
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
