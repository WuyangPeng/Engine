// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/04 13:55)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_INTERFACE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_INTERFACE_TESTING_H

#include "System/Window/Using/WindowUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class WindowMessageInterfaceTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowMessageInterfaceTesting;
		using ParentType = UnitTest;
		using HWnd = System::WindowHWnd;

	public:
		WindowMessageInterfaceTesting(const OStreamShared& stream, HWnd hwnd);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void MessageTest();
		void CloseMessageTest();
		void DestroyMessageTest();
		void SetMainWindowTest();		

	private:
		HWnd m_Hwnd;
	};
}

#endif // FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_INTERFACE_TESTING_H
