// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 10:04)

#ifndef ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_COPYRIGHT_DATA_TESTING_H
#define ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_COPYRIGHT_DATA_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace AssistTools
{
	class CopyrightDataTesting : public CoreTools::UnitTest
	{
        public:
            using ClassType = CopyrightDataTesting;
            using ParentType = UnitTest;

        public:
            explicit CopyrightDataTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
	private:
		void MainTest();

		void AccessTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // ASSIST_TOOLS_GENERATE_PROJECTS_SUITE_COPYRIGHT_DATA_TESTING_H