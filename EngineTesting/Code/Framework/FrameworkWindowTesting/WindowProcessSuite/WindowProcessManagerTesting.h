// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.3.0.2 (2020/06/04 16:30)

#ifndef FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_MANAGE_TESTING_H
#define FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_MANAGE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class WindowProcessManagerTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowProcessManagerTesting;
		using ParentType = UnitTest;
		using HWnd = System::WindowsHWnd;

	public:
		explicit WindowProcessManagerTesting(const OStreamShared& stream, HWnd hwnd);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void ManagerTest();
		void ClassNameTest();
		void SetMainWindow();		

	private:
		HWnd m_Hwnd;
	};
}

#endif // FRAMEWORK_WINDOW_TESTING_WINDOW_PROCESS_SUITE_WINDOW_PROCESS_MANAGE_TESTING_H