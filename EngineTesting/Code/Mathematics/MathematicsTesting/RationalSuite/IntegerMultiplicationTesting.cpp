///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:37)

#include "IntegerMultiplicationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"
#include "Mathematics/Rational/IntegerMultiplicationDetail.h"

#include <boost/utility/binary.hpp>
#include <random>

namespace Mathematics
{
    template class IntegerData<21>;
    template class IntegerData<22>;
    template class IntegerData<29>;
    template class IntegerData<32>;

    template class IntegerMultiplication<21>;
    template class IntegerMultiplication<22>;
    template class IntegerMultiplication<29>;
    template class IntegerMultiplication<32>;
}

Mathematics::IntegerMultiplicationTesting::IntegerMultiplicationTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, IntegerMultiplicationTesting)

void Mathematics::IntegerMultiplicationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::IntegerMultiplicationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MultiplicationTest);
}

void Mathematics::IntegerMultiplicationTesting::MultiplicationTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<> randomDistribution0(0, UINT16_MAX);
    std::uniform_int_distribution<uint16_t> randomDistribution1(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<uint16_t> firstShortVector(40);
        std::vector<uint16_t> secondShortVector(40);

        // 避免计算溢出
        for (auto i = 0; i < 19; ++i)
        {
            firstShortVector.at(i) = randomDistribution1(generator);
            secondShortVector.at(i) = randomDistribution1(generator);
        }

        const IntegerData<20> firstInteger(firstShortVector);
        const IntegerData<20> secondInteger(secondShortVector);

        IntegerMultiplication<20> thirdIntegerDataOperator(firstInteger, secondInteger);
        const IntegerData<20> thirdInteger = thirdIntegerDataOperator.GetMultiplication();

        IntegerMultiplication<20> fourthIntegerDataOperator(secondInteger, firstInteger);
        const IntegerData<20> fourthInteger = fourthIntegerDataOperator.GetMultiplication();

        ASSERT_EQUAL(thirdInteger, fourthInteger);

        const uint64_t firstValue = randomDistribution0(generator);
        const uint64_t secondValue = randomDistribution0(generator);

        const IntegerData<4> fifthInteger(firstValue);
        const IntegerData<4> sixthInteger(secondValue);

        IntegerMultiplication<4> fifthIntegerDataOperator(fifthInteger, sixthInteger);

        ASSERT_EQUAL(fifthIntegerDataOperator.GetMultiplication(), IntegerData<4>(firstValue * secondValue));
    }
}
