///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 19:47)

#include "WindowHBrushTesting.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowRegister/WindowHBrush.h"

#include <algorithm>

namespace Framework
{
    using TestingType = WindowHBrush;
}

Framework::WindowHBrushTesting::WindowHBrushTesting(const OStreamShared& stream)
    : ParentType{ stream },
      container{ System::WindowsBrushTypes::WhiteBrush,
                 System::WindowsBrushTypes::LtgrayBrush,
                 System::WindowsBrushTypes::GrayBrush,
                 System::WindowsBrushTypes::DkgrayBrush,
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
    for_each(container.begin(), container.end(), [this](const auto& value) {
        const TestingType windowHBrush{ value };
        ASSERT_EQUAL(windowHBrush.GetHBrush(), System::GetSystemStockObject(value));
    });
}
