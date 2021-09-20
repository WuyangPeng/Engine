// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/05 15:30)

#ifndef CORE_TOOLS_TESTING_FILE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_FILE_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class FileManagerTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FileManagerTesting);

	private:
		void MainTest();
		void FileManagerHelpTest();
		void ReadFileManagerTest();
		void WriteFileManagerTest();

		// FileManagerHelp����
		void LoadFromFileTest(bool binaryFile);
		void AppendToFileTest(bool binaryFile);
		void SaveIntoFileTest(bool binaryFile);

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_TESTING_FILE_MANAGER_TESTING_H