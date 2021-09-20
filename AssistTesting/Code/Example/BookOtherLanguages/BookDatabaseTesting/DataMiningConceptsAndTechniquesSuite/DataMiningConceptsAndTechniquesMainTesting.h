// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.1.0.0 (2020/04/05 12:03)

#ifndef BOOK_DATABASE_DATA_MINING_CONCEPTS_AND_TECHNIQUES_MAIN_TESTING_H
#define BOOK_DATABASE_DATA_MINING_CONCEPTS_AND_TECHNIQUES_MAIN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookDatabase
{
	class DataMiningConceptsAndTechniquesMainTesting final : public CoreTools::UnitTest
	{
	public:
		using ClassType = DataMiningConceptsAndTechniquesMainTesting;
		using ParentType = UnitTest;

	public:
		explicit DataMiningConceptsAndTechniquesMainTesting(const OStreamShared& stream);

		CLASS_INVARIANT_FINAL_DECLARE;

	private:
		void DoRunUnitTest() final;

		void MainTest();
	};
}

#endif // BOOK_DATABASE_DATA_MINING_CONCEPTS_AND_TECHNIQUES_MAIN_TESTING_H