///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 11:40)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_HEIGHT_LINE_FIT2_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_HEIGHT_LINE_FIT2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class HeightLineFit2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = HeightLineFit2Testing;
        using ParentType = UnitTest;

    public:
        explicit HeightLineFit2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void FitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_SUITE_HEIGHT_LINE_FIT2_TESTING_H