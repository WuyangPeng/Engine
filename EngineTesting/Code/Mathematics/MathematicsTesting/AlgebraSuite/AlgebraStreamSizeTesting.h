///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 11:10)

#ifndef MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_STREAM_SIZE_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_STREAM_SIZE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class AlgebraStreamSizeTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = AlgebraStreamSizeTesting;
        using ParentType = UnitTest;

    public:
        explicit AlgebraStreamSizeTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void StreamSizeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_ALGEBRA_STREAM_SIZE_TESTING_H