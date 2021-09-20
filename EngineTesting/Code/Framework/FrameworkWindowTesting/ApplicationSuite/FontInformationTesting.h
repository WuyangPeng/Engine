// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/12 21:20)

#ifndef FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H

#include "System/Window/Using/WindowUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class FontInformationTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = FontInformationTesting;
		using ParentType = UnitTest;
		using HWnd = System::WindowHWnd;

	public:
		explicit FontInformationTesting(const OStreamShared& stream, HWnd hwnd);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void WindowFontInformationTest();
		void GlutFontInformationTest();

	private:
		HWnd m_Hwnd;
	};
}

#endif // FRAMEWORK_WINDOW_TESTING_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H
