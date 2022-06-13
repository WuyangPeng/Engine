///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 16:45)

#ifndef SYSTEM_TIME_SUITE_DELTA_TIME_TESTING_H
#define SYSTEM_TIME_SUITE_DELTA_TIME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class DeltaTimeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = DeltaTimeTesting;
        using ParentType = UnitTest;

    public:
        explicit DeltaTimeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MicrosecondsTest();
        void SecondsTest();
    };
}

#endif  // SYSTEM_TIME_SUITE_DELTA_TIME_TESTING_H