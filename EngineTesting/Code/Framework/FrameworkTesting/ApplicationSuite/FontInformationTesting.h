// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.2 (2020/06/12 21:19)

#ifndef FRAMEWORK_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Framework
{
	class FontInformationTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = FontInformationTesting;
		using ParentType = UnitTest;

	public:
		explicit FontInformationTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // FRAMEWORK_APPLICATION_SUITE_FONT_INFORMATION_TESTING_H
