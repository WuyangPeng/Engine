///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/26 11:29)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_DIVISION_MODULO_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_DIVISION_MODULO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class IntegerDivisionModuloTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IntegerDivisionModuloTesting);

    private:
        void MainTest();
        void DenominatorIsLargeTest();
        void SingleTest();
        void MultipleTest();
        void Int32Test();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_RATIONAL_SUITE_INTEGER_DIVISION_MODULO_TESTING_H