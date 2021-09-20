// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.1 (2020/05/22 23:48)

#ifndef FRAMEWORK_HELPER_SUITE_LINUX_PROCESS_TESTING_H
#define FRAMEWORK_HELPER_SUITE_LINUX_PROCESS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 

namespace Framework
{
	class LinuxProcessTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = LinuxProcessTesting;
		using ParentType = UnitTest;		

	public:
		explicit LinuxProcessTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;	 

	private:
		void DoRunUnitTest() final;

		void MainTest();		 
	};
}

#endif // FRAMEWORK_HELPER_SUITE_LINUX_PROCESS_TESTING_H