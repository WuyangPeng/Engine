///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 10:44)

#ifndef MATHEMATICS_BASE_SUITE_FLOAT_4_TESTING_H
#define MATHEMATICS_BASE_SUITE_FLOAT_4_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Float4Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Float4Testing;
        using ParentType = UnitTest;

    public:
        explicit Float4Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructorTest() noexcept;
        void DelayCopyTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_BASE_SUITE_FLOAT_4_TESTING_H