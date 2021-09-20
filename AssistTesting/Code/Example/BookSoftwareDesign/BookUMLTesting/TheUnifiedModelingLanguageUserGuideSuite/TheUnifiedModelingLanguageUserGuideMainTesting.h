// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.1.0.1 (2020/04/05 18:09)

#ifndef BOOK_UML_THE_UNIFIED_MODELING_LANGUAGE_USER_GUIDE_MAIN_TESTING_H
#define BOOK_UML_THE_UNIFIED_MODELING_LANGUAGE_USER_GUIDE_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookUML
{
	class TheUnifiedModelingLanguageUserGuideMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = TheUnifiedModelingLanguageUserGuideMainTesting;
		using ParentType = UnitTest;

	public:
		explicit TheUnifiedModelingLanguageUserGuideMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_UML_THE_UNIFIED_MODELING_LANGUAGE_USER_GUIDE_MAIN_TESTING_H
