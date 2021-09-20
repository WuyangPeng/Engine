// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.0.1 (2019/09/28 20:02)

#ifndef BOOK_GAME_ENGINE_TESTING_HELPER_H
#define BOOK_GAME_ENGINE_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookGameEngine
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 	 

		void Add3DGameEngineDesignSuite();

		void AddMasteringUnrealTechnologySuite();

		void AddMasteringUnrealTechnologyIntroductionToLevelDesignWithUnrealEngine3Suite(Suite& masteringUnrealTechnologySuite);

		void AddMasteringUnrealTechnologyAdvancedLevelDesignConceptsWithUnrealEngine3Suite(Suite& masteringUnrealTechnologySuite);

		void AddGameEngineArchitectureSuite();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_GAME_ENGINE_TESTING_HELPER_H