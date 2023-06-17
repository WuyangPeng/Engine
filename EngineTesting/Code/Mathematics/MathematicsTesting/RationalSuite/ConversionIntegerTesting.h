///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:36)

#ifndef MATHEMATICS_RATIONAL_SUITE_INTEGER_CONVERSION_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_INTEGER_CONVERSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class ConversionIntegerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConversionIntegerTesting;
        using ParentType = UnitTest;

    public:
        explicit ConversionIntegerTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void NumericalValueSymbolTest();
        void ExponentTest();
        void MantissaTest();
        void IntegerTest();
        void UnsignedIntegerTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_RATIONAL_SUITE_INTEGER_CONVERSION_TESTING_H