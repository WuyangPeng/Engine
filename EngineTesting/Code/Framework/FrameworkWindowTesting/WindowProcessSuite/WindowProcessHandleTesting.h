// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/05 21:10)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowProcessHandleTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowProcessHandleTesting;
		using ParentType = UnitTest;
		using HWnd = System::WindowHWnd;

	public:
		explicit WindowProcessHandleTesting(const OStreamShared& stream, HWnd hwnd);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void BaseTest();
		void ClassNameTest();
		void HWndTest();		

	private:
		HWnd m_Hwnd;
	};
}

#endif //FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_HANDLE_TESTING_H
