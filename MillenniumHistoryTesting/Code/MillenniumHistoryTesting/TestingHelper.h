///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	千年史策测试版本：0.9.0.5 (2023/04/03 11:44)

#ifndef THE_LAST_OVERLORD_TESTING_TESTING_HELPER_H
#define THE_LAST_OVERLORD_TESTING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace MillenniumHistory
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