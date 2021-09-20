// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:29)

#ifndef CORE_TOOLS_TESTING_FILE_HANDLE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_HANDLE_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/FileManager/FileManagerFwd.h"

namespace CoreTools
{ 
	class FileHandleTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FileHandleTesting); 

	private:
		void MainTest();
		void FileHandleHelpTest();
		void ReadFileHandleTest();
		void WriteFileHandleTest();
		void ReadAndWriteFileHandleTest();
		void InexistenceFileTest();
		void CannotOpenWriteFileHandleTest();
		void CannotOpenReadAndWriteFileHandleTest();

		// FileHandleHelp≤‚ ‘
		void LoadFromFileTest();
		void AppendToFileTest();
		void SaveIntoFileTest();

		// ReadAndWriteFileHandle≤‚ ‘
		void ReadAndWriteFileHandleWriteFileTest();
		void ReadAndWriteFileHandleReadFileTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_TESTING_FILE_HANDLE_MANAGER_TESTING_H
