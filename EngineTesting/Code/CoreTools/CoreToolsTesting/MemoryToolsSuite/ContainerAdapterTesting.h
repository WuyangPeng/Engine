/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/22 15:59)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_CONTAINER_ADAPTER_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_CONTAINER_ADAPTER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ContainerAdapterTesting final : public UnitTest
    {
    public:
        using ClassType = ContainerAdapterTesting;
        using ParentType = UnitTest;

    public:
        explicit ContainerAdapterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ContainerAdapterArrayTest();
        void ContainerAdapterVectorTest();

        void ContainerAdapterArraySizeTest();
        void ContainerAdapterArrayResetTest();
        void ContainerAdapterArrayAccessTest();
        void ContainerAdapterArrayFillTest();

        void ContainerAdapterVectorSizeTest();
        void ContainerAdapterVectorResetTest();
        void ContainerAdapterVectorAccessTest();

        template <typename Container, typename ElementType = typename Container::value_type>
        NODISCARD ElementType ComputeAverage(const Container& container);

        void ComputedAverage0Test();
        void ComputedAverage1Test();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_CONTAINER_ADAPTER_TESTING_H