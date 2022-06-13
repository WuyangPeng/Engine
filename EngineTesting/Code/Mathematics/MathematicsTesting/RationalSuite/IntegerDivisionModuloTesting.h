///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 11:29)

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