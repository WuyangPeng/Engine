// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 11:52)

#ifndef CORE_TOOLS_THREADING_SUITE_SEMAPHORE_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_SEMAPHORE_TESTING_H

#include "CoreTools/Threading/Semaphore.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class SemaphoreTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SemaphoreTesting);

	private:
		void MainTest();

		void CreateFourThread();
		void ReadThread();
		void WirteThread();

		void DoRunUnitTest() override;

	private:
		Semaphore m_Semaphore1;
		Semaphore m_Semaphore2;
	};
}

#endif // CORE_TOOLS_THREADING_SUITE_SEMAPHORE_TESTING_H