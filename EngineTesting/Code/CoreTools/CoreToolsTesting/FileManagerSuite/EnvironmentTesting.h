// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:29)

#ifndef CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H
#define CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class EnvironmentTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(EnvironmentTesting);

	private:
		void MainTest();
		void InsertDirectoryTest();
		void EraseDirectoryTest();
		void GetPathReadingSucceedTest();
		void GetPathWritingSucceedTest();
		void GetPathReadingAndWritingSucceedTest();
		void GetPathReadingFailureTest();
		void GetPathWritingFailureTest();
		void GetPathReadingAndWritingFailureTest();
		void ConfigurationPathTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_TESTING_ENVIRONMENT_TESTING_H