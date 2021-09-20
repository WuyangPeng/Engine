// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 15:28)

#ifndef CORE_TOOLS_TESTING_COPY_FILE_TOOLS_TESTING_H
#define CORE_TOOLS_TESTING_COPY_FILE_TOOLS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class CopyFileToolsTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CopyFileToolsTesting);

	private:
		void MainTest();
		void CopyFileTest();
		void VerificationTest();
		void DeleteFileTest();

		void DoRunUnitTest() override;
	};
}

#endif // CORE_TOOLS_TESTING_COPY_FILE_TOOLS_TESTING_H