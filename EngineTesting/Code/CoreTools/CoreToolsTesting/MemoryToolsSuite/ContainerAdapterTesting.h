/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/15 20:15)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_CONTAINER_ADAPTER_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_CONTAINER_ADAPTER_TESTING_H

#include "CoreTools/MemoryTools/MemoryToolsFwd.h"
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
        static constexpr auto beginNumber = 1;
        static constexpr auto containerAdapterSize = 8;
        using IntContainerAdapter8 = ContainerAdapter<int, containerAdapterSize>;
        using IntContainerAdapter = ContainerAdapter<int>;
        using ArrayAverageContainer = std::vector<std::array<double, 2>>;
        using VectorAverageContainer = std::vector<std::vector<double>>;
        using Array2ContainerAdapter4 = ContainerAdapter<std::array<double, 2>, 4>;
        using Array2ContainerAdapter = ContainerAdapter<std::array<double, 2>>;
        using VectorContainerAdapter4 = ContainerAdapter<std::vector<double>, 4>;
        using VectorContainerAdapter = ContainerAdapter<std::vector<double>>;

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
        NODISCARD ElementType ComputeSum(const Container& container);

        template <typename Container, typename ElementType = typename Container::value_type>
        NODISCARD ElementType ComputeAverage(const Container& container);

        void ComputedAverage0Test();
        void ComputedAverage1Test();
        void ComputedAverage2Test();
        void ComputedAverage3Test();

        void ContainerAdapterArrayAccessBeginTest(IntContainerAdapter8& container);
        void ContainerAdapterArrayAccessConstBeginTest(const IntContainerAdapter8& container);
        void ContainerAdapterArrayAccessReverseBeginTest(IntContainerAdapter8& container);
        void ContainerAdapterArrayAccessReverseConstBeginTest(const IntContainerAdapter8& container);

        void ContainerAdapterVectorAccessBeginTest(IntContainerAdapter& container);
        void ContainerAdapterVectorAccessConstBeginTest(const IntContainerAdapter& container);
        void ContainerAdapterVectorAccessReverseBeginTest(IntContainerAdapter& container);
        void ContainerAdapterVectorAccessReverseConstBeginTest(const IntContainerAdapter& container);
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_CONTAINER_ADAPTER_TESTING_H