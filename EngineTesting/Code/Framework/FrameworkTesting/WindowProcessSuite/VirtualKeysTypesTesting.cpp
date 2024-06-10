///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 20:23)

#include "VirtualKeysTypesTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/WindowProcess/VirtualKeysTypes.h"

#include <random>

Framework::VirtualKeysTypesTesting::VirtualKeysTypesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, VirtualKeysTypesTesting)

void Framework::VirtualKeysTypesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::VirtualKeysTypesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WindowKeysTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GlutKeysTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetModifiersTest);
}

void Framework::VirtualKeysTypesTesting::WindowKeysTest()
{
    constexpr auto minValue = 0;
    constexpr auto maxValue = 1;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        VirtualKeysTypes::WParam wParam{};

        const auto isCtrlKeyDown = (random(generator) == 1 ? true : false);
        const auto isLeftMouseDown = (random(generator) == 1 ? true : false);
        const auto isMiddleMouseDown = (random(generator) == 1 ? true : false);
        const auto isRightMouseDown = (random(generator) == 1 ? true : false);
        const auto isShiftKeyDown = (random(generator) == 1 ? true : false);

        wParam = RandomParam(wParam, WindowApplicationTrait::MouseModifiers::modifierControl, isCtrlKeyDown);
        wParam = RandomParam(wParam, WindowApplicationTrait::MouseModifiers::modifierLeftButton, isLeftMouseDown);
        wParam = RandomParam(wParam, WindowApplicationTrait::MouseModifiers::modifierMiddleButton, isMiddleMouseDown);
        wParam = RandomParam(wParam, WindowApplicationTrait::MouseModifiers::modifierRightButton, isRightMouseDown);
        wParam = RandomParam(wParam, WindowApplicationTrait::MouseModifiers::modifierShift, isShiftKeyDown);

        const VirtualKeysTypes virtualKeys{ wParam };

        ASSERT_EQUAL(virtualKeys.IsCtrlKeyDown(), isCtrlKeyDown);
        ASSERT_EQUAL(virtualKeys.IsLeftMouseDown(), isLeftMouseDown);
        ASSERT_EQUAL(virtualKeys.IsMiddleMouseDown(), isMiddleMouseDown);
        ASSERT_EQUAL(virtualKeys.IsRightMouseDown(), isRightMouseDown);
        ASSERT_EQUAL(virtualKeys.IsShiftKeyDown(), isShiftKeyDown);
    }
}

System::WindowsWParam Framework::VirtualKeysTypesTesting::RandomParam(System::WindowsWParam wParam, int mouseModifiers, bool isDown) noexcept
{
    if (isDown)
    {
        return wParam | mouseModifiers;
    }
    else
    {
        return wParam;
    }
}

void Framework::VirtualKeysTypesTesting::GlutKeysTest()
{
    constexpr VirtualKeysTypes virtualKeys{};

    ASSERT_FALSE(virtualKeys.IsCtrlKeyDown());
    ASSERT_FALSE(virtualKeys.IsLeftMouseDown());
    ASSERT_FALSE(virtualKeys.IsMiddleMouseDown());
    ASSERT_FALSE(virtualKeys.IsRightMouseDown());
    ASSERT_FALSE(virtualKeys.IsShiftKeyDown());
}

void Framework::VirtualKeysTypesTesting::SetModifiersTest()
{
    constexpr auto minValue = 0;
    constexpr auto maxValue = 5;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        VirtualKeysTypes virtualKeys{};

        const auto modifiers = GetModifiers(random(generator));
        const auto button = GetButton(random(generator));

        virtualKeys.SetModifiers(modifiers);

        ASSERT_EQUAL(virtualKeys.IsCtrlKeyDown(), IsKeyDown(GlutApplicationTrait::MouseModifiers::modifierControl, modifiers));
        ASSERT_FALSE(virtualKeys.IsLeftMouseDown());
        ASSERT_FALSE(virtualKeys.IsMiddleMouseDown());
        ASSERT_FALSE(virtualKeys.IsRightMouseDown());
        ASSERT_EQUAL(virtualKeys.IsShiftKeyDown(), IsKeyDown(GlutApplicationTrait::MouseModifiers::modifierShift, modifiers));

        virtualKeys.SetMouseButtonsTypes(button);

        ASSERT_EQUAL(virtualKeys.IsCtrlKeyDown(), IsKeyDown(GlutApplicationTrait::MouseModifiers::modifierControl, modifiers));
        ASSERT_EQUAL(virtualKeys.IsLeftMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierLeftButton));
        ASSERT_EQUAL(virtualKeys.IsMiddleMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierMiddleButton));
        ASSERT_EQUAL(virtualKeys.IsRightMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierRightButton));
        ASSERT_EQUAL(virtualKeys.IsShiftKeyDown(), IsKeyDown(GlutApplicationTrait::MouseModifiers::modifierShift, modifiers));

        virtualKeys.ClearMouseButtonsTypes();

        ASSERT_EQUAL(virtualKeys.IsCtrlKeyDown(), IsKeyDown(GlutApplicationTrait::MouseModifiers::modifierControl, modifiers));
        ASSERT_FALSE(virtualKeys.IsLeftMouseDown());
        ASSERT_FALSE(virtualKeys.IsMiddleMouseDown());
        ASSERT_FALSE(virtualKeys.IsRightMouseDown());
        ASSERT_EQUAL(virtualKeys.IsShiftKeyDown(), IsKeyDown(GlutApplicationTrait::MouseModifiers::modifierShift, modifiers));

        virtualKeys.ClearKeyDownTypes();

        ASSERT_FALSE(virtualKeys.IsCtrlKeyDown());
        ASSERT_FALSE(virtualKeys.IsLeftMouseDown());
        ASSERT_FALSE(virtualKeys.IsMiddleMouseDown());
        ASSERT_FALSE(virtualKeys.IsRightMouseDown());
        ASSERT_FALSE(virtualKeys.IsShiftKeyDown());

        virtualKeys.SetMouseButtonsTypes(button);

        ASSERT_FALSE(virtualKeys.IsCtrlKeyDown());
        ASSERT_EQUAL(virtualKeys.IsLeftMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierLeftButton));
        ASSERT_EQUAL(virtualKeys.IsMiddleMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierMiddleButton));
        ASSERT_EQUAL(virtualKeys.IsRightMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierRightButton));
        ASSERT_FALSE(virtualKeys.IsShiftKeyDown());

        virtualKeys.SetModifiers(modifiers);

        ASSERT_EQUAL(virtualKeys.IsCtrlKeyDown(), IsKeyDown(GlutApplicationTrait::MouseModifiers::modifierControl, modifiers));
        ASSERT_EQUAL(virtualKeys.IsLeftMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierLeftButton));
        ASSERT_EQUAL(virtualKeys.IsMiddleMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierMiddleButton));
        ASSERT_EQUAL(virtualKeys.IsRightMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierRightButton));
        ASSERT_EQUAL(virtualKeys.IsShiftKeyDown(), IsKeyDown(GlutApplicationTrait::MouseModifiers::modifierShift, modifiers));
    }
}

int Framework::VirtualKeysTypesTesting::GetModifiers(int keyDown) noexcept
{
    if (keyDown % 2 == 0)
    {
        return GlutApplicationTrait::MouseModifiers::modifierControl;
    }
    else
    {
        return GlutApplicationTrait::MouseModifiers::modifierShift;
    }
}

int Framework::VirtualKeysTypesTesting::GetButton(int mouseDown) noexcept
{
    switch (mouseDown % 3)
    {
        case 0:
            return GlutApplicationTrait::MouseModifiers::modifierLeftButton;
        case 1:
            return GlutApplicationTrait::MouseModifiers::modifierMiddleButton;
        default:
            return GlutApplicationTrait::MouseModifiers::modifierRightButton;
    }
}
