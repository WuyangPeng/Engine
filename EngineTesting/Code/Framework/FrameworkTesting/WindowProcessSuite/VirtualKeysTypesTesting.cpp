// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/04 10:29)

#include "VirtualKeysTypesTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Framework/WindowProcess/VirtualKeysTypes.h"
#include "Framework/Application/Flags/ApplicationTrait.h" 

#include <random> 

using std::uniform_int;
using std::default_random_engine;

namespace Framework
{
	using TestingType = VirtualKeysTypes;
}

Framework::VirtualKeysTypesTesting
	::VirtualKeysTypesTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, VirtualKeysTypesTesting)

void Framework::VirtualKeysTypesTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::VirtualKeysTypesTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(WindowKeysTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GlutKeysTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetModifiersTest);
}

void Framework::VirtualKeysTypesTesting
	::WindowKeysTest()
{
	constexpr auto minValue = 0;
	constexpr auto maxValue = 1;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	for (auto i = 0; i < GetTestLoopCount(); ++i)
	{
		TestingType::WParam wParam{ };

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

		const TestingType virtualKeys{ wParam };

		ASSERT_EQUAL(virtualKeys.IsCtrlKeyDown(), isCtrlKeyDown);
		ASSERT_EQUAL(virtualKeys.IsLeftMouseDown(), isLeftMouseDown);
		ASSERT_EQUAL(virtualKeys.IsMiddleMouseDown(), isMiddleMouseDown);
		ASSERT_EQUAL(virtualKeys.IsRightMouseDown(), isRightMouseDown);
		ASSERT_EQUAL(virtualKeys.IsShiftKeyDown(), isShiftKeyDown);
	}
}

System::WindowsWParam Framework::VirtualKeysTypesTesting
	::RandomParam(System::WindowsWParam wParam, int mouseModifiers, bool isDown) noexcept
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

void Framework::VirtualKeysTypesTesting
	::GlutKeysTest()
{
	const TestingType virtualKeys{ };

	ASSERT_FALSE(virtualKeys.IsCtrlKeyDown());
	ASSERT_FALSE(virtualKeys.IsLeftMouseDown());
	ASSERT_FALSE(virtualKeys.IsMiddleMouseDown());
	ASSERT_FALSE(virtualKeys.IsRightMouseDown());
	ASSERT_FALSE(virtualKeys.IsShiftKeyDown());
}

void Framework::VirtualKeysTypesTesting
	::SetModifiersTest()
{
	constexpr auto minValue = 0;
	constexpr auto maxValue = 5;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	for (auto i = 0; i < GetTestLoopCount(); ++i)
	{
		TestingType virtualKeys{ };	 

		const auto modifiers = GetModifiers(random(generator)); 
		const auto button = GetButton(random(generator));

		virtualKeys.SetModifiers(modifiers);

		ASSERT_EQUAL(virtualKeys.IsCtrlKeyDown(), IsKeyDown(modifiers, GlutApplicationTrait::MouseModifiers::modifierControl));
		ASSERT_FALSE(virtualKeys.IsLeftMouseDown());
		ASSERT_FALSE(virtualKeys.IsMiddleMouseDown());
		ASSERT_FALSE(virtualKeys.IsRightMouseDown());
		ASSERT_EQUAL(virtualKeys.IsShiftKeyDown(), IsKeyDown(modifiers, GlutApplicationTrait::MouseModifiers::modifierShift));

		virtualKeys.SetMouseButtonsTypes(button);

		ASSERT_EQUAL(virtualKeys.IsCtrlKeyDown(), IsKeyDown(modifiers, GlutApplicationTrait::MouseModifiers::modifierControl));
		ASSERT_EQUAL(virtualKeys.IsLeftMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierLeftButton));
		ASSERT_EQUAL(virtualKeys.IsMiddleMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierMiddleButton));
		ASSERT_EQUAL(virtualKeys.IsRightMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierRightButton));
		ASSERT_EQUAL(virtualKeys.IsShiftKeyDown(), IsKeyDown(modifiers, GlutApplicationTrait::MouseModifiers::modifierShift));

		virtualKeys.ClearMouseButtonsTypes();

		ASSERT_EQUAL(virtualKeys.IsCtrlKeyDown(), IsKeyDown(modifiers, GlutApplicationTrait::MouseModifiers::modifierControl));
		ASSERT_FALSE(virtualKeys.IsLeftMouseDown());
		ASSERT_FALSE(virtualKeys.IsMiddleMouseDown());
		ASSERT_FALSE(virtualKeys.IsRightMouseDown());
		ASSERT_EQUAL(virtualKeys.IsShiftKeyDown(), IsKeyDown(modifiers, GlutApplicationTrait::MouseModifiers::modifierShift));

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

		ASSERT_EQUAL(virtualKeys.IsCtrlKeyDown(), IsKeyDown(modifiers, GlutApplicationTrait::MouseModifiers::modifierControl));
		ASSERT_EQUAL(virtualKeys.IsLeftMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierLeftButton));
		ASSERT_EQUAL(virtualKeys.IsMiddleMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierMiddleButton));
		ASSERT_EQUAL(virtualKeys.IsRightMouseDown(), IsButtonDown(button, GlutApplicationTrait::MouseModifiers::modifierRightButton));
		ASSERT_EQUAL(virtualKeys.IsShiftKeyDown(), IsKeyDown(modifiers, GlutApplicationTrait::MouseModifiers::modifierShift));
	}
}

int Framework::VirtualKeysTypesTesting
	::GetModifiers(int keyDown) noexcept
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

int Framework::VirtualKeysTypesTesting
	::GetButton(int mouseDown) noexcept
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

