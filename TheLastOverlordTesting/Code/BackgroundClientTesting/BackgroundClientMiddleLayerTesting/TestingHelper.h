// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ������԰汾��0.0.0.0 (2019/10/10 17:54)

#ifndef BACKGROUND_CLIENT_MIDDLE_LAYER_TESTING_TESTING_HELPER_H
#define BACKGROUND_CLIENT_MIDDLE_LAYER_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BackgroundClientTesting
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif //  BACKGROUND_CLIENT_MIDDLE_LAYER_TESTING_TESTING_HELPER_H
