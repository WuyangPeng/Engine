// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.1 (2020/05/22 23:48)

#ifndef FRAMEWORK_HELPER_SUITE_MACINTOSH_FRAME_BUILD_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MACINTOSH_FRAME_BUILD_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class MacintoshFrameBuildTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = MacintoshFrameBuildTesting;
		using ParentType = UnitTest;		

	public:
		explicit MacintoshFrameBuildTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;	 

	private:
		void DoRunUnitTest() final;

		void MainTest();		 
	};
}

#endif // FRAMEWORK_HELPER_SUITE_MACINTOSH_FRAME_BUILD_TESTING_H