///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/26 16:22)

#include "IntegerMultiplicationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Rational/IntegerDataDetail.h"
#include "Mathematics/Rational/IntegerMultiplicationDetail.h"

#include <boost/utility/binary.hpp>
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::vector;

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

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, IntegerMultiplicationTesting)

void Mathematics::IntegerMultiplicationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MultiplicationTest);
}

void Mathematics::IntegerMultiplicationTesting::MultiplicationTest()
{
    default_random_engine generator{};
    const uniform_int<> firstRandomDistribution(0, UINT16_MAX);
    const uniform_int<uint16_t> secondRandomDistribution(0, UINT16_MAX);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(40);
        vector<uint16_t> secondShortVector(40);

        // 避免计算溢出
        for (auto i = 0; i < 19; ++i)
        {
            firstShortVector.at(i) = secondRandomDistribution(generator);
            secondShortVector.at(i) = secondRandomDistribution(generator);
        }

        const IntegerData<20> firstInteger(firstShortVector);
        const IntegerData<20> secondInteger(secondShortVector);

        IntegerMultiplication<20> thirdIntegerDataOperator(firstInteger, secondInteger);
        const IntegerData<20> thirdInteger = thirdIntegerDataOperator.GetMultiplication();

        IntegerMultiplication<20> fourthIntegerDataOperator(secondInteger, firstInteger);
        const IntegerData<20> fourthInteger = fourthIntegerDataOperator.GetMultiplication();

        ASSERT_EQUAL(thirdInteger, fourthInteger);

        const uint64_t firstValue = firstRandomDistribution(generator);
        const uint64_t secondValue = firstRandomDistribution(generator);

        const IntegerData<4> fifthInteger(firstValue);
        const IntegerData<4> sixthInteger(secondValue);

        IntegerMultiplication<4> fifthIntegerDataOperator(fifthInteger, sixthInteger);

        ASSERT_EQUAL(fifthIntegerDataOperator.GetMultiplication(), IntegerData<4>(firstValue * secondValue));
    }
}
