// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.1.0.1 (2020/04/05 18:09)

#ifndef BOOK_UML_OBJECT_ORIENTED_MODELING_AND_DESIGN_WITH_UML_MAIN_TESTING_H
#define BOOK_UML_OBJECT_ORIENTED_MODELING_AND_DESIGN_WITH_UML_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookUML
{
	class ObjectOrientedModelingAndDesignWithUMLMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = ObjectOrientedModelingAndDesignWithUMLMainTesting;
		using ParentType = UnitTest;

	public:
		explicit ObjectOrientedModelingAndDesignWithUMLMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_UML_OBJECT_ORIENTED_MODELING_AND_DESIGN_WITH_UML_MAIN_TESTING_H