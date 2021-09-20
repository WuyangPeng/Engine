// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 16:19)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H

#include "System/Window/Flags/WindowFlags.h"
#include "System/Window/Using/WindowUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowCreateHandleTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowCreateHandleTesting;
		using ParentType = UnitTest;
		using HWnd = System::WindowHWnd;
		using HInstance = System::WindowHInstance;

	public:
		WindowCreateHandleTesting(const OStreamShared& stream, HInstance instance, HWnd hwnd);
		
		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		void MainTest();
		void CreateTest();

		void DoRunUnitTest() final;

	private:
		HInstance m_Instance;
		HWnd m_Hwnd;
	};
}

#endif // FRAMEWORK_WINDOW_TESTING_WINDOW_CREATE_SUITE_WINDOW_CREATE_HANDLE_TESTING_H
