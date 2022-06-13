///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/01 14:59)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MATRIX3_TOOLS_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MATRIX3_TOOLS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Matrix3ToolsTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Matrix3ToolsTesting);

    private:
        void MainTest();
        void SingularValueTest();
        void PolarDecompositionValueTest();
        void QDUDecompositionValueTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_MATRIX3_TOOLS_TESTING_H