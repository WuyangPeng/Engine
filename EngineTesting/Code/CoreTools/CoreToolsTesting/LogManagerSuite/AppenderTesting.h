// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:12)

#ifndef CORE_TOOLS_LOG_MANAGER_SUITE_APPENDER_TESTING_H
#define CORE_TOOLS_LOG_MANAGER_SUITE_APPENDER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class AppenderTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(AppenderTesting);

	private:
		void MainTest();

		void ConsoleTest();
		void FileTest();
		void FileConfigurationTest();
		void SetLogLevelTest();

		// File≤‚ ‘
		void FileLogTest();
		void FileContentTest();
		void BackupFileTest();
		void BackupFileContentTest();
		void DeleteFileTest();
		System::String GetBackupFileName();

		void DoRunUnitTest() override;

	private:
		System::String m_AppenderTestingName;
		System::String m_AppenderTestingFullName;
		System::String m_BackupFileName;
	};
}

#endif // CORE_TOOLS_LOG_MANAGER_SUITE_APPENDER_TESTING_H
