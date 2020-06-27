// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:37)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_STREAM_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_STREAM_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Command/CommandFwd.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowMessageUnitTestSuiteStream
	{
	public:
		using ClassType = WindowMessageUnitTestSuiteStream;
		using OStreamShared = CoreTools::OStreamShared;

	public:
		explicit WindowMessageUnitTestSuiteStream(bool usecommand);

		CLASS_INVARIANT_DECLARE;

		OStreamShared GetStreamShared() noexcept;

	private:
		using Command = CoreTools::CommandHandle;
		using CommandSharedPtr = std::shared_ptr<Command>;

	private:
		static CommandSharedPtr GenerateCommandSharedPtr(bool usecommand);
		static OStreamShared GenerateStreamShared(bool usecommand);
		static std::string GetMultiByteCommandLine();

	private:
		OStreamShared m_OStreamShared;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_STREAM_H
