///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:29)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_DIVISION_MODULO_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_DIVISION_MODULO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class IntegerDivisionModuloTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = IntegerDivisionModuloTesting;
        using ParentType = UnitTest;

    public:
        explicit IntegerDivisionModuloTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

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