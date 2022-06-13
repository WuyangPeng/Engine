///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 15:00)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZEN_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZEN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <vector>

namespace Mathematics
{
    class MinimizeNTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MinimizeNTesting);

    private:
        void MainTest();
        void GetMinimumTest();

        NODISCARD static double Function(const std::vector<double>& value, const MinimizeNTesting* minimize1Testing) noexcept;
        NODISCARD double GetValue() const noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MINIMIZEN_TESTING_H