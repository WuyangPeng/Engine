// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.2 (2020/06/08 21:50)

#include "WindowHBrushTesting.h"
#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "System/Windows/WindowsRegister.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowRegister/WindowHBrush.h"

#include <algorithm>

namespace Framework
{
    using TestingType = WindowHBrush;
}

Framework::WindowHBrushTesting::WindowHBrushTesting(const OStreamShared& stream)
    : ParentType{ stream },
      m_Container{ System::WindowsBrushTypes::WhiteBrush,
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
    for_each(m_Container.begin(), m_Container.end(), [this](const auto& value) {
        const TestingType windowHBrush{ value };
        ASSERT_EQUAL(windowHBrush.GetHBrush(), System::GetSystemStockObject(value));
    });
}