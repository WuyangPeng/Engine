// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/05 15:28)

#ifndef CORE_TOOLS_TESTING_C_FILE_MANAGER_TESTING_H
#define CORE_TOOLS_TESTING_C_FILE_MANAGER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class CFileManagerTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CFileManagerTesting);

	private:
		void MainTest();
		void CFileManagerHelpTest();
		void CReadFileManagerTest();
		void CWriteFileManagerTest();

		// CFileManagerHelp����
		void LoadFromFileTest(bool binaryFile);
		void LoadFromFileUseEnvironmentTest(bool binaryFile);
		void AppendToFileTest(bool binaryFile);
		void SaveIntoFileTest(bool binaryFile);

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_TESTING_C_FILE_MANAGER_TESTING_H