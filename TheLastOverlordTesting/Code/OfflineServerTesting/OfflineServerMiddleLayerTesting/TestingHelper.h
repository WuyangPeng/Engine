// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���İ������԰汾��0.0.0.1 (2019/10/12 14:03)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_TESTING_TESTING_HELPER_H
#define OFFLINE_SERVER_MIDDLE_LAYER_TESTING_TESTING_HELPER_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

namespace OfflineServerTesting
{
    class TestingHelper : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite() noexcept;
    };
}

#endif  //  OFFLINE_SERVER_MIDDLE_LAYER_TESTING_TESTING_HELPER_H
