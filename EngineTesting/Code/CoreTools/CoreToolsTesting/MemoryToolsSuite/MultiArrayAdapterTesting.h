/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 16:25)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_MULTI_ARRAY_ADAPTER_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_MULTI_ARRAY_ADAPTER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class MultiArrayAdapterTesting final : public UnitTest
    {
    public:
        using ClassType = MultiArrayAdapterTesting;
        using ParentType = UnitTest;

    public:
        explicit MultiArrayAdapterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void SizeTest();
        void GetIndexTest();
        void GetIndexArrayTest();
        void CoordinateTest();

        void OrderLToRTest();
        void OrderLRoTTest();
        void OrderLToRConstantTest();
        void OrderLRoTConstantTest();

        void MultiArrayAdapterTest();
        void CompareTest();
        void ResetTest();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_MULTI_ARRAY_ADAPTER_TESTING_H