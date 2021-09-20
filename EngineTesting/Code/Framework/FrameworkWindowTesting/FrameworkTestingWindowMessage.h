// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.3.0.2 (2020/06/03 09:30)

#ifndef FRAMEWORK_WINDOW_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
#define FRAMEWORK_WINDOW_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H

#include "Framework/WindowProcess/WindowMessageUnitTestSuiteDetail.h"

namespace Framework
{
	class FrameworkTestingWindowMessage final : public WindowMessageUnitTestSuite
	{
	public:
		using ClassType = FrameworkTestingWindowMessage;
		using ParentType = WindowMessageUnitTestSuite;

	public:
		explicit FrameworkTestingWindowMessage(int64_t delta);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void InitSuite() final;

		void AddWindowCreateSuite();
		void AddWindowProcessSuite();
		void AddWindowRegisterSuite();
		void AddApplicationSuite();
	};

	using FrameworkHandle = WindowProcessHandle<FrameworkTestingWindowMessage>;
}

#endif // FRAMEWORK_WINDOW_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
