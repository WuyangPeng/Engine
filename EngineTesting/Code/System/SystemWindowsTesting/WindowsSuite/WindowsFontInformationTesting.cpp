/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:16)

#include "WindowsFontInformationTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Windows/WindowsFontInformation.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::WindowsFontInformationTesting::WindowsFontInformationTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
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
    ASSERT_NOT_THROW_EXCEPTION_0(GetFontInformationTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FontInformationTest);
}

void System::WindowsFontInformationTesting::GetFontInformationTest()
{
    ASSERT_LESS(0, GetStringWidth(hWnd, SYSTEM_TEXT("GetStringWidth"s)));
    ASSERT_LESS(0, GetCharacterWidth(hWnd, 'G'));
    ASSERT_LESS(0, GetFontHeight(hWnd));
}

void System::WindowsFontInformationTesting::FontInformationTest()
{
    const auto context = GetSystemDC(hWnd);

    ASSERT_NOT_THROW_EXCEPTION_1(DoFontInformationTest, context);

    ASSERT_TRUE(ReleaseSystemDC(hWnd, context));
}

void System::WindowsFontInformationTesting::DoFontInformationTest(WindowsHdc context)
{
    const auto text = SYSTEM_TEXT("GetStringWidth"s);

    WindowsPointSize size{ 0, 0 };
    ASSERT_TRUE(GetSystemTextExtentPoint32(context, text.c_str(), boost::numeric_cast<int>(text.size()), &size));
    WindowsTextMetric metric{};
    ASSERT_TRUE(GetSystemTextMetrics(context, &metric));
}
