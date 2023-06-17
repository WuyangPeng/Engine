///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:25)

#ifndef MATHEMATICS_BASE_SUITE_FLOAT_3_TESTING_H
#define MATHEMATICS_BASE_SUITE_FLOAT_3_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Float3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Float3Testing;
        using ParentType = UnitTest;

    public:
        explicit Float3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructorTest() noexcept;
        void DelayCopyTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_FLOAT_3_TESTING_H