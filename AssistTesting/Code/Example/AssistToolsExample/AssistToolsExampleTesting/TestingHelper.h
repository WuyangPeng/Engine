// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.0.2.2 (2020/01/27 15:01)

#ifndef ASSIST_TOOLS_EXAMPLE_TESTING_HELPER_H
#define ASSIST_TOOLS_EXAMPLE_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace AssistToolsExample
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 
	
		virtual int DoRun() override;			

	private:
		void AddSuites();	 

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // ASSIST_TOOLS_EXAMPLE_TESTING_HELPER_H
