///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 18:37)

#ifndef MATHEMATICS_QUERY_SUITE_QUERY3_RATIONAL_TESTING_H
#define MATHEMATICS_QUERY_SUITE_QUERY3_RATIONAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Query3RationalTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = Query3RationalTesting;
        using ParentType = UnitTest;

    public:
        explicit Query3RationalTesting(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void VerticesTest();
        void PlaneTest();
        void TetrahedronTest();
        void CircumspherTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_QUERY_SUITE_QUERY3_RATIONAL_TESTING_H