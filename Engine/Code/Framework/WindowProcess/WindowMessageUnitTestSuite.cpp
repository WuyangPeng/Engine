/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:30)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuite.h"
#include "Detail/WindowMessageUnitTestSuiteImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"
#include "CoreTools/UnitTestSuite/Suite.h"

Framework::WindowMessageUnitTestSuite::WindowMessageUnitTestSuite(int64_t delta, const std::string& suiteName)
    : ParentType{ delta }, impl{ suiteName }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::WindowMessageUnitTestSuite::WindowMessageUnitTestSuite(int64_t delta, const std::string& suiteName, const Framework::EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, environmentDirectory }, impl{ suiteName }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, WindowMessageUnitTestSuite)

int Framework::WindowMessageUnitTestSuite::GetPassedNumber() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->GetPassedNumber();
}

bool Framework::WindowMessageUnitTestSuite::IsPrintRun() const noexcept
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return impl->IsPrintRun();
}

void Framework::WindowMessageUnitTestSuite::AddSuite(const Suite& suite)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return impl->AddSuite(suite);
}

System::WindowsLResult Framework::WindowMessageUnitTestSuite::CreateMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    if (GetHWnd() == nullptr)
        return AddSuiteOnCreateMessage(hWnd, wParam, lParam);
    else
        return ParentType::CreateMessage(hWnd, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageUnitTestSuite::KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    const auto windowsKeyCodes = boost::numeric_cast<int>(wParam);

    impl->KeyDownMessage(System::UnderlyingCastEnum<System::WindowsKeyCodes>(windowsKeyCodes));

    return ParentType::KeyDownMessage(hwnd, wParam, lParam);
}

void Framework::WindowMessageUnitTestSuite::Display(HWnd hWnd, int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_9;

    return ParentType::Display(hWnd, timeDelta);
}

CoreTools::OStreamShared Framework::WindowMessageUnitTestSuite::GetStreamShared() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return impl->GetStreamShared();
}

void Framework::WindowMessageUnitTestSuite::AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    impl->AddTest(suiteName, suite, testName, unitTest);
}

System::WindowsLResult Framework::WindowMessageUnitTestSuite::AddSuiteOnCreateMessage(HWnd hWnd, WParam wParam, LParam lParam)
{
    const auto result = ParentType::CreateMessage(hWnd, wParam, lParam);

    InitSuite();

    impl->RunUnitTestOnMessage();

    return result;
}

CoreTools::Suite Framework::WindowMessageUnitTestSuite::GenerateSuite(const std::string& name)
{
    return Suite{ name, GetStreamShared(), IsPrintRun() };
}
