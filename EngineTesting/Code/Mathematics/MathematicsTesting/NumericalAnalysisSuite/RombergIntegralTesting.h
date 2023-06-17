///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:58)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ROMBERG_INTEGRAL_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ROMBERG_INTEGRAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class RombergIntegralTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = RombergIntegralTesting;
        using ParentType = UnitTest;

    public:
        explicit RombergIntegralTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ValueTest();

        void DoRunUnitTest() override;

        NODISCARD static double Solution(double input, const RombergIntegralTesting* userData) noexcept;
        NODISCARD double GetUserData() const noexcept;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_ROMBERG_INTEGRAL_TESTING_H