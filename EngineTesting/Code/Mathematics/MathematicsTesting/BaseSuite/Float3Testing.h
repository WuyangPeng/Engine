///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 10:44)

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