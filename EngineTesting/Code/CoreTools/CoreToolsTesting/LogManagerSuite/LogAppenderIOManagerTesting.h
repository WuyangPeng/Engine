// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:13)

#ifndef LOG_MANAGER_LOG_APPENDER_IO_MANAGER_TESTING_H
#define LOG_MANAGER_LOG_APPENDER_IO_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class LogAppenderIOManagerTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(LogAppenderIOManagerTesting);

	private:
		void MainTest();
		void IntegerTest();
		void StringTest();
		void Error1Test();
		void FormatTest();
		void LogAppenderIOManageSignTest();
		void FileContentTest();
		void DeleteFileTest();

		void DoRunUnitTest() override;

	private:
		using AppenderManagerPtr = std::shared_ptr<AppenderManager>;

	private:
		AppenderManagerPtr GetAppenderManager();

	private:
		System::String m_LogAppenderIOManagerTestingName;
		System::String m_LogAppenderIOManagerTestingFullName;
	};
}

#endif // LOG_MANAGER_LOG_APPENDER_IO_MANAGER_TESTING_H
