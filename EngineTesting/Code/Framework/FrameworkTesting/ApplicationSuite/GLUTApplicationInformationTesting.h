// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/14 21:25)

#ifndef FRAMEWORK_APPLICATION_SUITE_GLUT_APPLICATION_INFORMATION_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_GLUT_APPLICATION_INFORMATION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class GLUTApplicationInformationTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = GLUTApplicationInformationTesting;
		using ParentType = UnitTest;

	public:
		explicit GLUTApplicationInformationTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();

		void InformationTest();
	};
}

#endif // FRAMEWORK_APPLICATION_SUITE_GLUT_APPLICATION_INFORMATION_TESTING_H