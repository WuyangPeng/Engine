///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	��ʷ��������԰汾��0.8.1.0 (2022/08/03 13:41)

#ifndef THE_LAST_OVERLORD_TESTING_TESTING_HELPER_H
#define THE_LAST_OVERLORD_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace RiseOfHistory
{
    class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = CMainFunctionTestingHelper;

    public:
        TestingHelper(int argc, char** argv);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite();

        void AddVersionSuite();
        void AddEngineSuite();
    };
}

#endif  // THE_LAST_OVERLORD_TESTING_TESTING_HELPER_H