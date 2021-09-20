///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/08 15:51)

#include "WindowsFontInformationTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/WindowsFontInformation.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::WindowsFontInformationTesting::WindowsFontInformationTesting(const OStreamShared& stream, WindowsHWnd hwnd)
    : ParentType{ stream }, hwnd{ hwnd }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WindowsFontInformationTesting)

void System::WindowsFontInformationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WindowsFontInformationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FontInformationTest);
}

void System::WindowsFontInformationTesting::FontInformationTest()
{
    ASSERT_LESS(0, GetStringWidth(hwnd, SYSTEM_TEXT("GetStringWidth"s)));
    ASSERT_LESS(0, GetCharacterWidth(hwnd, 'G'));
    ASSERT_LESS(0, GetFontHeight(hwnd));

    const auto text = SYSTEM_TEXT("GetStringWidth"s);

    auto context = GetSystemDC(hwnd);

    WindowsPointSize size{ 0, 0 };
    ASSERT_TRUE(GetSystemTextExtentPoint32(context, text.c_str(), boost::numeric_cast<int>(text.size()), &size));
    WindowsTextMetric metric{};
    ASSERT_TRUE(GetSystemTextMetrics(context, &metric));

    ASSERT_TRUE(ReleaseSystemDC(hwnd, context));
}
