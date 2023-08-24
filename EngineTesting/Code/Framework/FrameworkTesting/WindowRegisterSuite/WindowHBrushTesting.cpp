///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 20:31)

#include "WindowHBrushTesting.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowRegister/WindowHBrush.h"

#include <algorithm>

Framework::WindowHBrushTesting::WindowHBrushTesting(const OStreamShared& stream)
    : ParentType{ stream },
      container{ System::WindowsBrushTypes::WhiteBrush,
                 System::WindowsBrushTypes::LightGrayBrush,
                 System::WindowsBrushTypes::GrayBrush,
                 System::WindowsBrushTypes::DarkGrayBrush,
                 System::WindowsBrushTypes::BlackBrush,
                 System::WindowsBrushTypes::NullBrush }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowHBrushTesting)

void Framework::WindowHBrushTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowHBrushTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BrushTest);
}

void Framework::WindowHBrushTesting::BrushTest()
{
    std::ranges::for_each(container, [this](const auto& value) {

        const WindowHBrush windowHBrush{ value };
        ASSERT_EQUAL(windowHBrush.GetHBrush(), System::GetSystemStockObject(value));

    });
}
