///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 11:11)

#ifndef MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EXTRACT_TESTING_H
#define MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EXTRACT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Matrix3ExtractTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Matrix3ExtractTesting;
        using ParentType = UnitTest;

    public:
        explicit Matrix3ExtractTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ExtractTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_ALGEBRA_SUITE_MATRIX3_EXTRACT_TESTING_H