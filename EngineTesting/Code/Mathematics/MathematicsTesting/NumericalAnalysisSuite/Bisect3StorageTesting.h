///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/01 14:37)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_STORAGE_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_STORAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Bisect3StorageTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Bisect3StorageTesting;
        using ParentType = UnitTest;

    public:
        explicit Bisect3StorageTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void TestValuesTest() noexcept;
        void SetStorageValueTest() noexcept;

        void DoRunUnitTest() override;

        NODISCARD constexpr static double FirstEquation(double x, double y, double z)
        {
            return 1.0 * x + 1.0 * y - 2.0 * z + 1.0;
        }

        NODISCARD constexpr static double SecondEquation(double x, double y, double z)
        {
            return 2.0 * x + 3.0 * y - 1.0 * z - 1.0;
        }

        NODISCARD constexpr static double ThirdEquation(double x, double y, double z)
        {
            return 3.0 * x + 1.0 * y - 2.0 * z - 1.0;
        }
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BISECT3_STORAGE_TESTING_H