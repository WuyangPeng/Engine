///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/26 11:28)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_OPERATOR_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_OPERATOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class IntegerDataOperatorTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IntegerDataOperatorTesting);

    private:
        void MainTest();
        void AdditionTest();
        void SubtractionTest();
        void MultiplicationTest();
        void LeftShiftTest();
        void RightShiftTest();
        void DivisionModuloTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_RATIONAL_SUITE_INTEGER_DATA_OPERATOR_TESTING_H