///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 14:33)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BANDED_MATRIX_INVERT_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BANDED_MATRIX_INVERT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class BandedMatrixInvertTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BandedMatrixInvertTesting);

    private:
        void MainTest();
        void BandedTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_BANDED_MATRIX_INVERT_TESTING_H