///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:28)

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