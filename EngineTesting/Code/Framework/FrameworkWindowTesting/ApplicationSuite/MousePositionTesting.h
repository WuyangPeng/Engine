// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/13 0:40)

#ifndef FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_MOUSE_POSITION_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_MOUSE_POSITION_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class MousePositionTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = MousePositionTesting;
		using ParentType = UnitTest;
		using HWnd = System::WindowsHWnd;

	public:
		explicit MousePositionTesting(const OStreamShared& stream, HWnd hwnd);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void WindowMousePositionTest();

	private:
		HWnd m_Hwnd;
	};
}

#endif // FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_MOUSE_POSITION_TESTING_H
