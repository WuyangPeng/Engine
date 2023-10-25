///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:08)

#include "ContainerAdapterTestingDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/MemoryTools/ContainerAdapterDetail.h"
#include "CoreTools/MemoryTools/RawIteratorsDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

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
    std::vector array{ 1, 2, 3, 4, 5, 6, 7, 8 };

    const ContainerAdapter<int, 8> container{ array.data() };

    ASSERT_EQUAL(container.size(), 8);

    ASSERT_UNEQUAL_NULL_PTR(container.GetData());
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayResetTest()
{
    std::vector array{ 1, 2, 3, 4, 5, 6, 7, 8 };

    ContainerAdapter<int, 8> container0{ array.data() };

    ASSERT_EQUAL(container0.size(), 8);

    const auto oldData = container0.GetData();

    ASSERT_UNEQUAL_NULL_PTR(oldData);
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayAccessTest()
{
    std::vector array{ 1, 2, 3, 4, 5, 6, 7, 8 };

    ContainerAdapter<int, 8> container{ array.data() };

    for (auto i = 0; i < container.size(); ++i)
    {
        ASSERT_EQUAL(container[i], i + 1);
    }

    auto index = 1;
    for (auto iter = container.begin(); iter != container.end(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        ++index;
    }

    index = 1;
    for (auto iter = container.cbegin(); iter != container.cend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        ++index;
    }

    index = 8;
    for (auto iter = container.crbegin(); iter != container.crend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        --index;
    }

    index = 8;
    for (auto iter = container.rbegin(); iter != container.rend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        --index;
    }
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterArrayFillTest()
{
    std::vector array{ 1, 2, 3, 4, 5, 6, 7, 8 };

    ContainerAdapter<int, 8> container{ array.data() };

    container.Fill(5);

    for (auto i = 0; i < container.size(); ++i)
    {
        ASSERT_EQUAL(container[i], 5);
    }
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorSizeTest()
{
    std::vector array{ 1, 2, 3, 4, 5, 6, 7, 8 };

    ContainerAdapter<int> container{ array.data(), boost::numeric_cast<int>(array.size()) };

    ASSERT_EQUAL(container.size(), 8);

    ASSERT_UNEQUAL_NULL_PTR(container.GetData());
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorResetTest()
{
    std::vector array{ 1, 2, 3, 4, 5, 6, 7, 8 };

    ContainerAdapter<int> container{ array.data(), boost::numeric_cast<int>(array.size()) };

    ASSERT_EQUAL(container.size(), 8);

    const auto oldData = container.GetData();

    ASSERT_UNEQUAL_NULL_PTR(oldData);
}

void CoreTools::ContainerAdapterTesting::ContainerAdapterVectorAccessTest()
{
    std::vector array{ 1, 2, 3, 4, 5, 6, 7, 8 };

    ContainerAdapter<int> container{ array.data(), boost::numeric_cast<int>(array.size()) };

    for (auto i = 0; i < container.size(); ++i)
    {
        ASSERT_EQUAL(container[i], i + 1);
    }

    auto index = 1;
    for (auto iter = container.cbegin(); iter != container.end(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        ++index;
    }

    index = 1;
    for (auto iter = container.cbegin(); iter != container.cend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        ++index;
    }

    index = 8;
    for (auto iter = container.crbegin(); iter != container.crend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        --index;
    }

    index = 8;
    for (auto iter = container.rbegin(); iter != container.rend(); ++iter)
    {
        ASSERT_EQUAL(*iter, index);

        --index;
    }
}

void CoreTools::ContainerAdapterTesting::ComputedAverage0Test()
{
    std::vector<std::array<double, 2>> container0{ { 1.0, 2.0 }, { 3.0, 4.0 }, { 5.0, 6.0 }, { 7.0, 8.0 } };

    const auto average0 = ComputeAverage0(container0);
    ASSERT_APPROXIMATE(average0.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average0.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());

    const ContainerAdapter<std::array<double, 2>, 4> container1{ container0.data() };
    const auto average1 = ComputeAverage0(container1);
    ASSERT_APPROXIMATE(average1.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average1.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());

    const ContainerAdapter<std::array<double, 2>> container2{ container0.data(), 4 };
    const auto average2 = ComputeAverage0(container2);
    ASSERT_APPROXIMATE(average2.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average2.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());
}

void CoreTools::ContainerAdapterTesting::ComputedAverage1Test()
{
    std::vector<std::vector<double>> container0{ { 1.0, 2.0 }, { 3.0, 4.0 }, { 5.0, 6.0 }, { 7.0, 8.0 } };

    const auto average0 = ComputeAverage0(container0);
    ASSERT_APPROXIMATE(average0.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average0.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());

    const ContainerAdapter<std::vector<double>, 4> container1{ container0.data() };
    const auto average1 = ComputeAverage0(container1);
    ASSERT_APPROXIMATE(average1.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average1.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());

    const ContainerAdapter<std::vector<double>> container2{ container0.data(), 4 };
    const auto average2 = ComputeAverage0(container2);
    ASSERT_APPROXIMATE(average2.at(0), 4.0, Mathematics::MathD::GetZeroTolerance());
    ASSERT_APPROXIMATE(average2.at(1), 5.0, Mathematics::MathD::GetZeroTolerance());
}
