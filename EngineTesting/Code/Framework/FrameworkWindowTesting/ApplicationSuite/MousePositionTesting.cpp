// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/13 0:41)

#include "MousePositionTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/WindowCreate/WindowPoint.h"
#include "Framework/Application/MousePosition.h"

namespace Framework
{
	using TestingType = MousePosition;
}

Framework::MousePositionTesting
	::MousePositionTesting(const OStreamShared& stream, HWnd hwnd)
	:ParentType{ stream }, m_Hwnd{ hwnd }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MousePositionTesting)

void Framework::MousePositionTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MousePositionTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(WindowMousePositionTest);
}

void Framework::MousePositionTesting
	::WindowMousePositionTest()
{
	TestingType windowMousePosition{ m_Hwnd };

	const auto point1 = windowMousePosition.GetMousePosition();
	windowMousePosition.SetMousePosition(point1);

	const auto point2 = windowMousePosition.GetMousePosition();

	ASSERT_EQUAL(point1, point2);
}

