///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:51)

#ifndef C_MAIN_FUNCTION_HELPER_TESTING_HELPER_H
#define C_MAIN_FUNCTION_HELPER_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace CMainFunctionHelper
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        NODISCARD int DoRun() override;
    };
}

#endif  // C_MAIN_FUNCTION_HELPER_TESTING_HELPER_H