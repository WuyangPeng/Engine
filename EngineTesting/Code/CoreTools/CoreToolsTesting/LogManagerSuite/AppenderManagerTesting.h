// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:12)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class AppenderManagerTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AppenderManagerTesting);

	private:
		void MainTest();
		void LoggerTest();
		void AppenderTest();
		void WriteMessageTest();

		// Logger≤‚ ‘
		void LoggerSucceedTest();
		void InsertLoggerFailTest();
		void RemoveLoggerFailTest();

		// Appender≤‚ ‘
		void AppenderSucceedTest();
		void InsertAppenderFailTest();
		void RemoveAppenderFailTest();

		// WriteMessage≤‚ ‘
		void WriteMessageToFileTest();
		void FileContentTest();
		void DeleteFileTest();

		void DoRunUnitTest() override;

	private:
		System::String m_AppenderManagerTestingName;
		System::String m_AppenderManagerTestingFullName;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_SUITE_LOGGER_MANAGER_TESTING_H
