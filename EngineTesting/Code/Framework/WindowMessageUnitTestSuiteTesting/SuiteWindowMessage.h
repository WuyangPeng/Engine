// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/06 22:04)

#ifndef WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_SUITE_WINDOW_MESSAGE_H
#define WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_SUITE_WINDOW_MESSAGE_H

#include "Framework/WindowProcess/WindowMessageUnitTestSuiteDetail.h"

#include <memory>

namespace Framework
{
	class SuiteWindowMessage final : public Framework::WindowMessageUnitTestSuite, public std::enable_shared_from_this<SuiteWindowMessage>
	{
	public:
		using ClassType = SuiteWindowMessage;
		using ParentType = WindowMessageUnitTestSuite;

	public:
		explicit SuiteWindowMessage(int64_t delta);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void InitSuite() final;
	};

	using WindowProcessTesting = Framework::WindowProcessHandle<SuiteWindowMessage>;
}

#endif // WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_SUITE_WINDOW_MESSAGE_H
