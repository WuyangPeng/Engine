// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.3.0.2 (2020/06/04 15:55)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class WindowMessageTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowMessageTesting;
		using ParentType = UnitTest;
		using HWnd = System::WindowsHWnd;

	public:
		WindowMessageTesting(const OStreamShared& stream, HWnd hwnd);

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

#endif // FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_MESSAGE_TESTING_H