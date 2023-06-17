///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:57)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZEN_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZEN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace Mathematics
{
    class MinimizeNTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = MinimizeNTesting;
        using ParentType = UnitTest;

    public:
        explicit MinimizeNTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void GetMinimumTest();

        NODISCARD static double Function(const std::vector<double>& value, const MinimizeNTesting* minimize1Testing) noexcept;
        NODISCARD double GetValue() const noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZEN_TESTING_H