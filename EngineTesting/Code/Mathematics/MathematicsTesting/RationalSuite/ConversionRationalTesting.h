///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/26 11:09)

#ifndef MATHEMATICS_RATIONAL_SUITE_CONVERSION_RATIONAL_TESTING_H
#define MATHEMATICS_RATIONAL_SUITE_CONVERSION_RATIONAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class ConversionRationalTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ConversionRationalTesting;
        using ParentType = UnitTest;

    public:
        explicit ConversionRationalTesting(const OStreamShared& streamShared);

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

#endif  // MATHEMATICS_RATIONAL_SUITE_CONVERSION_RATIONAL_TESTING_H