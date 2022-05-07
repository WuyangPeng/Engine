// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 16:09)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_PARAMETER_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_PARAMETER_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowCreateParameterTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowCreateParameterTesting;
		using ParentType = UnitTest;
		using HWnd = System::WindowsHWnd; 

	public:
		WindowCreateParameterTesting(const OStreamShared& stream, HWnd hwnd);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void MainTest();

		void DoRunUnitTest() final;

		void ValueTest();

	private:
		HWnd m_Hwnd;
	};
}

#endif // FRAMEWORK_WINDOW_CREATE_SUITE_WINDOW_CREATE_PARAMETER_TESTING_H
