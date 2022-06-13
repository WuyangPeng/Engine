///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/01 14:58)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_EQUATION_RESULT_CONST_ITERATOR_TESTING_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_EQUATION_RESULT_CONST_ITERATOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class EquationResultConstIteratorTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(EquationResultConstIteratorTesting);

    private:
        void MainTest();
        void DereferenceTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SUITE_EQUATION_RESULT_CONST_ITERATOR_TESTING_H