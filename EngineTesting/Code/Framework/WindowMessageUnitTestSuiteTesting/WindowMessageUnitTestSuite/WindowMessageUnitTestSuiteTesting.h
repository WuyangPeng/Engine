// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.2 (2020/06/06 22:27)

#ifndef WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H
#define WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class SuiteWindowMessage;

	class WindowMessageUnitTestSuiteTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = WindowMessageUnitTestSuiteTesting;
		using ParentType = UnitTest;
		using WindowMessageSharedPtr = std::shared_ptr<SuiteWindowMessage>;

	public:
		explicit WindowMessageUnitTestSuiteTesting(const OStreamShared& stream, const WindowMessageSharedPtr& message);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void KeyDownMessageTest();
		void CreateMessageTest();
		void DisplayTest();

	private:
		std::weak_ptr<SuiteWindowMessage> m_Message;
	};
}

#endif // WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_H
