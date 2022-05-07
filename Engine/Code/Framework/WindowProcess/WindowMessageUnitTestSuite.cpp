///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:46)

#include "Framework/FrameworkExport.h"

#include "WindowMessageUnitTestSuite.h"
#include "Detail/WindowMessageUnitTestSuiteImpl.h"
#include "Detail/WindowMessageUnitTestSuiteStream.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"
#include "CoreTools/UnitTestSuite/Suite.h"

using std::make_shared;
using std::string;

Framework::WindowMessageUnitTestSuite::WindowMessageUnitTestSuite(int64_t delta, const string& suiteName)
    : ParentType{ delta }, stream{ make_shared<StreamType>(true) }, impl{ suiteName, stream->GetStreamShared() }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Framework::WindowMessageUnitTestSuite::IsValid() const noexcept
{
    if (ParentType::IsValid() && stream != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

System::WindowsLResult Framework::WindowMessageUnitTestSuite::CreateMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    if (GetHwnd() == nullptr)
        return AddSuiteOnCreateMessage(hwnd, wParam, lParam);
    else
        return ParentType::CreateMessage(hwnd, wParam, lParam);
}

System::WindowsLResult Framework::WindowMessageUnitTestSuite::KeyDownMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto windowsKeyCodes = boost::numeric_cast<int>(wParam);

    impl->KeyDownMessage(System::UnderlyingCastEnum<System::WindowsKeyCodes>(windowsKeyCodes));

    return ParentType::KeyDownMessage(hwnd, wParam, lParam);
}

void Framework::WindowMessageUnitTestSuite::Display(HWnd hwnd, int64_t timeDelta)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return ParentType::Display(hwnd, timeDelta);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowMessageUnitTestSuite, IsPrintRun, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Framework, WindowMessageUnitTestSuite, GetPassedNumber, int)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Framework, WindowMessageUnitTestSuite, AddSuite, Suite, void)

// protected
CoreTools::OStreamShared Framework::WindowMessageUnitTestSuite::GetStreamShared() noexcept
{
    FRAMEWORK_CLASS_IS_VALID_1;

    return stream->GetStreamShared();
}

// protected
void Framework::WindowMessageUnitTestSuite::AddTest(const string& suiteName, Suite& suite, const string& testName, const UnitTestSharedPtr& unitTest)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    impl->AddTest(suiteName, suite, testName, unitTest);
}

// private
System::WindowsLResult Framework::WindowMessageUnitTestSuite::AddSuiteOnCreateMessage(HWnd hwnd, WParam wParam, LParam lParam)
{
    const auto result = ParentType::CreateMessage(hwnd, wParam, lParam);

    InitSuite();

    impl->RunUnitTestOnMessage();

    return result;
}

// protected
CoreTools::Suite Framework::WindowMessageUnitTestSuite::GenerateSuite(const string& name)
{
    return Suite{ name, GetStreamShared(), IsPrintRun() };
}
