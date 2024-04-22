///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 15:52)

#include "WindowCreateParameterTesting.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowCreate/WindowCreateParameter.h"
#include "Framework/WindowCreate/WindowPoint.h"

using namespace std::literals;

Framework::WindowCreateParameterTesting::WindowCreateParameterTesting(const OStreamShared& stream, WindowsHWnd hWnd)
    : ParentType{ stream }, hWnd{ hWnd }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowCreateParameterTesting)

void Framework::WindowCreateParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowCreateParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
}

void Framework::WindowCreateParameterTesting::ValueTest()
{
    const auto windowsName = SYSTEM_TEXT("WindowsName"s);
    constexpr auto style = System::WindowsStyles::OverlappedWindow | System::WindowsStyles::Visible;
    constexpr WindowPoint leftTopCorner{};
    constexpr auto menu = nullptr;

    const WindowCreateParameter parameter{ windowsName, style, hWnd, menu, leftTopCorner };

    ASSERT_EQUAL(parameter.GetWindowsName(), windowsName);
    ASSERT_EQUAL(parameter.GetStyle(), style);
    ASSERT_EQUAL(parameter.GetParent(), hWnd);
    ASSERT_EQUAL(parameter.GetMenu(), menu);
    ASSERT_EQUAL(parameter.GetLeftTopCorner(), leftTopCorner);
}