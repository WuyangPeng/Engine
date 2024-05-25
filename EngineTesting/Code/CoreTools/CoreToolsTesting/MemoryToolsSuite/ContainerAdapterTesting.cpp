/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/15 20:23)

#include "ContainerAdapterTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/ContainerAdapterDetail.h"
#include "CoreTools/MemoryTools/RawIteratorsDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

#include <numeric>

CoreTools::ContainerAdapterTesting::ContainerAdapterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ContainerAdapterTesting)

void CoreTools::ContainerAdapterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ContainerAdapterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerAdapterArrayTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerAdapterVectorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ComputedAverage0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ComputedAverage1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ComputedAverage2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(ComputedAverage3Test);
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerAdapterArraySizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerAdapterArrayResetTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerAdapterArrayAccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerAdapterArrayFillTest);
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerAdapterVectorSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerAdapterVectorResetTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ContainerAdapterVectorAccessTest);
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArraySizeTest()
{
    std::vector<int> array(containerAdapterSize);
    std::iota(array.begin(), array.end(), beginNumber);

    const IntContainerAdapter8 container{ array.data() };

    ASSERT_EQUAL(container.size(), containerAdapterSize);

    ASSERT_UNEQUAL_NULL_PTR(container.GetData());
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayResetTest()
{
    std::vector<int> array(containerAdapterSize);
    std::iota(array.begin(), array.end(), beginNumber);

    IntContainerAdapter8 container{ array.data() };

    ASSERT_EQUAL(container.size(), containerAdapterSize);

    const auto data = container.GetData();

    ASSERT_UNEQUAL_NULL_PTR(data);
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayAccessTest()
{
    std::vector<int> array(containerAdapterSize);
    std::iota(array.begin(), array.end(), beginNumber);

    IntContainerAdapter8 container{ array.data() };

    for (auto i = 0; i < IntContainerAdapter8::size(); ++i)
    {
        ASSERT_EQUAL(container[i], i + beginNumber);
    }

    ASSERT_NOT_THROW_EXCEPTION_1(ContainerAdapterArrayAccessBeginTest, container);
    ASSERT_NOT_THROW_EXCEPTION_1(ContainerAdapterArrayAccessConstBeginTest, container);
    ASSERT_NOT_THROW_EXCEPTION_1(ContainerAdapterArrayAccessReverseBeginTest, container);
    ASSERT_NOT_THROW_EXCEPTION_1(ContainerAdapterArrayAccessReverseConstBeginTest, container);
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayAccessBeginTest(IntContainerAdapter8& container)
{
    auto index = beginNumber;
    for (auto iter = container.begin(); iter != container.end(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        ++index;
    }
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayAccessConstBeginTest(const IntContainerAdapter8& container)
{
    auto index = beginNumber;
    for (auto iter = container.cbegin(); iter != container.cend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        ++index;
    }
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayAccessReverseBeginTest(IntContainerAdapter8& container)
{
    auto index = containerAdapterSize;
    for (auto iter = container.rbegin(); iter != container.rend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        --index;
    }
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayAccessReverseConstBeginTest(const IntContainerAdapter8& container)
{
    auto index = containerAdapterSize;
    for (auto iter = container.crbegin(); iter != container.crend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        --index;
    }
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayFillTest()
{
    std::vector<int> array(containerAdapterSize);
    std::iota(array.begin(), array.end(), beginNumber);

    IntContainerAdapter8 container{ array.data() };

    container.Fill(containerAdapterSize / 2);

    for (auto i = 0; i < IntContainerAdapter8::size(); ++i)
    {
        ASSERT_EQUAL(container[i], containerAdapterSize / 2);
    }
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorSizeTest()
{
    std::vector<int> array(containerAdapterSize);
    std::iota(array.begin(), array.end(), beginNumber);

    IntContainerAdapter container{ array.data(), boost::numeric_cast<int>(array.size()) };

    ASSERT_EQUAL(container.size(), containerAdapterSize);

    ASSERT_UNEQUAL_NULL_PTR(container.GetData());
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorResetTest()
{
    std::vector<int> array(containerAdapterSize);
    std::iota(array.begin(), array.end(), beginNumber);

    IntContainerAdapter container{ array.data(), boost::numeric_cast<int>(array.size()) };

    ASSERT_EQUAL(container.size(), containerAdapterSize);

    const auto oldData = container.GetData();

    ASSERT_UNEQUAL_NULL_PTR(oldData);
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorAccessTest()
{
    std::vector<int> array(containerAdapterSize);
    std::iota(array.begin(), array.end(), beginNumber);

    IntContainerAdapter container{ array.data(), boost::numeric_cast<int>(array.size()) };

    for (auto i = 0; i < container.size(); ++i)
    {
        ASSERT_EQUAL(container[i], i + beginNumber);
    }

    ASSERT_NOT_THROW_EXCEPTION_1(ContainerAdapterVectorAccessBeginTest, container);
    ASSERT_NOT_THROW_EXCEPTION_1(ContainerAdapterVectorAccessConstBeginTest, container);
    ASSERT_NOT_THROW_EXCEPTION_1(ContainerAdapterVectorAccessReverseBeginTest, container);
    ASSERT_NOT_THROW_EXCEPTION_1(ContainerAdapterVectorAccessReverseConstBeginTest, container);
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorAccessBeginTest(IntContainerAdapter& container)
{
    auto index = beginNumber;
    for (auto iter = container.begin(); iter != container.end(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        ++index;
    }
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorAccessConstBeginTest(const IntContainerAdapter& container)
{
    auto index = beginNumber;
    for (auto iter = container.cbegin(); iter != container.cend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        ++index;
    }
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorAccessReverseBeginTest(IntContainerAdapter& container)
{
    auto index = containerAdapterSize;
    for (auto iter = container.rbegin(); iter != container.rend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        --index;
    }
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorAccessReverseConstBeginTest(const IntContainerAdapter& container)
{
    auto index = containerAdapterSize;
    for (auto iter = container.crbegin(); iter != container.crend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        --index;
    }
}

void CoreTools::ContainerAdapterTesting::ComputedAverage0Test()
{
    ArrayAverageContainer container0{ { 1.0, 2.0 }, { 3.0, 4.0 }, { 5.0, 6.0 }, { 7.0, 8.0 } };

    const auto average0 = ComputeAverage(container0);
    ASSERT_APPROXIMATE(average0.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average0.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());

    const Array2ContainerAdapter4 container1{ container0.data() };
    const auto average1 = ComputeAverage(container1);
    ASSERT_APPROXIMATE(average1.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average1.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::ContainerAdapterTesting::ComputedAverage1Test()
{
    ArrayAverageContainer container0{ { 1.0, 2.0 }, { 3.0, 4.0 }, { 5.0, 6.0 }, { 7.0, 8.0 } };

    const auto average0 = ComputeAverage(container0);
    ASSERT_APPROXIMATE(average0.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average0.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());

    const Array2ContainerAdapter container1{ container0.data(), 4 };
    const auto average1 = ComputeAverage(container1);
    ASSERT_APPROXIMATE(average1.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average1.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::ContainerAdapterTesting::ComputedAverage2Test()
{
    VectorAverageContainer container0{ { 1.0, 2.0 }, { 3.0, 4.0 }, { 5.0, 6.0 }, { 7.0, 8.0 } };

    const auto average0 = ComputeAverage(container0);
    ASSERT_APPROXIMATE(average0.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average0.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());

    const VectorContainerAdapter4 container1{ container0.data() };
    const auto average1 = ComputeAverage(container1);
    ASSERT_APPROXIMATE(average1.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average1.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::ContainerAdapterTesting::ComputedAverage3Test()
{
    VectorAverageContainer container0{ { 1.0, 2.0 }, { 3.0, 4.0 }, { 5.0, 6.0 }, { 7.0, 8.0 } };

    const auto average0 = ComputeAverage(container0);
    ASSERT_APPROXIMATE(average0.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average0.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());

    const VectorContainerAdapter container1{ container0.data(), 4 };
    const auto average1 = ComputeAverage(container1);
    ASSERT_APPROXIMATE(average1.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average1.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());
}
