///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:28)

#include "QuerySortToolsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Query/QuerySortTools.h"

#include <random>

Mathematics::QuerySortToolsTesting::QuerySortToolsTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, QuerySortToolsTesting)

void Mathematics::QuerySortToolsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::QuerySortToolsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SortTwoValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SortThreeValueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SortFourValueTest);
}

void Mathematics::QuerySortToolsTesting::SortTwoValueTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> randomDistribution0(0, 2000);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);
        auto secondValue = randomDistribution0(generator);

        QuerySortTools querySortTools(firstValue, secondValue);

        ASSERT_TRUE(querySortTools.GetValue(0) <= querySortTools.GetValue(1));

        if (firstValue <= secondValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
    }
}

void Mathematics::QuerySortToolsTesting::SortThreeValueTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> randomDistribution0(0, 2000);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);
        auto secondValue = randomDistribution0(generator);
        auto thirdValue = randomDistribution0(generator);

        QuerySortTools querySortTools(firstValue, secondValue, thirdValue);

        ASSERT_TRUE(querySortTools.GetValue(0) <= querySortTools.GetValue(1));
        ASSERT_TRUE(querySortTools.GetValue(1) <= querySortTools.GetValue(2));

        if (firstValue <= secondValue && secondValue <= thirdValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (firstValue <= thirdValue && thirdValue <= secondValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (secondValue <= firstValue && firstValue <= thirdValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (secondValue <= thirdValue && thirdValue <= firstValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (thirdValue <= firstValue && firstValue <= secondValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (thirdValue <= secondValue && secondValue <= firstValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
    }
}

void Mathematics::QuerySortToolsTesting::SortFourValueTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> randomDistribution0(0, 2000);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstValue = randomDistribution0(generator);
        auto secondValue = randomDistribution0(generator);
        auto thirdValue = randomDistribution0(generator);
        auto fourthValue = randomDistribution0(generator);

        QuerySortTools querySortTools(firstValue, secondValue, thirdValue, fourthValue);

        ASSERT_TRUE(querySortTools.GetValue(0) <= querySortTools.GetValue(1));
        ASSERT_TRUE(querySortTools.GetValue(1) <= querySortTools.GetValue(2));
        ASSERT_TRUE(querySortTools.GetValue(2) <= querySortTools.GetValue(3));

        if (firstValue <= secondValue && secondValue <= thirdValue && thirdValue <= fourthValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (firstValue <= secondValue && secondValue <= fourthValue && fourthValue <= thirdValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (firstValue <= thirdValue && thirdValue <= secondValue && secondValue <= fourthValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (firstValue <= thirdValue && thirdValue <= fourthValue && fourthValue <= secondValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (secondValue <= firstValue && firstValue <= thirdValue && thirdValue <= fourthValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (secondValue <= firstValue && firstValue <= fourthValue && fourthValue <= thirdValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (secondValue <= thirdValue && thirdValue <= firstValue && firstValue <= fourthValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (secondValue <= thirdValue && thirdValue <= fourthValue && fourthValue <= firstValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (thirdValue <= firstValue && firstValue <= secondValue && secondValue <= fourthValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (thirdValue <= firstValue && firstValue <= fourthValue && fourthValue <= secondValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (thirdValue <= secondValue && secondValue <= firstValue && firstValue <= fourthValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (thirdValue <= secondValue && secondValue <= fourthValue && fourthValue <= firstValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (thirdValue <= fourthValue && fourthValue <= firstValue && firstValue <= secondValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (thirdValue <= fourthValue && fourthValue <= secondValue && secondValue <= firstValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (fourthValue <= firstValue && firstValue <= secondValue && secondValue <= thirdValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (fourthValue <= firstValue && firstValue <= thirdValue && thirdValue <= secondValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (fourthValue < secondValue && secondValue <= firstValue && firstValue <= thirdValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
        else if (fourthValue <= secondValue && secondValue <= thirdValue && thirdValue <= firstValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (fourthValue <= thirdValue && thirdValue <= firstValue && firstValue <= secondValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Negative);
        }
        else if (fourthValue <= thirdValue && thirdValue <= secondValue && secondValue <= firstValue)
        {
            ASSERT_EQUAL(querySortTools.GetSymbol(), NumericalValueSymbol::Positive);
        }
    }
}
