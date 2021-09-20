///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/06 23:48)

#ifndef BOOK_TEMPLATE_TESTING_HELPER_H
#define BOOK_TEMPLATE_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace BookTemplate
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
	{
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;
        using Suite = CoreTools::Suite;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();
		 
		void AddCppTemplatesSuite();

		void AddCppTemplateMetaprogrammingSuite(); 
	};
}

#endif // BOOK_TEMPLATE_TESTING_HELPER_H