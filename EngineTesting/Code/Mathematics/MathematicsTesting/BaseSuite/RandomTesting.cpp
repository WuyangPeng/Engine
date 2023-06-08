///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 11:33)

#include "MathTesting.h"
#include "RandomTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Base/RandomDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Random<float>;
    template class Random<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::RandomTesting::RandomTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, RandomTesting)

void Mathematics::RandomTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::RandomTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FloatRandomTest);
    ASSERT_NOT_THROW_EXCEPTION_0(DoubleRandomTest);
}

void Mathematics::RandomTesting::FloatRandomTest()
{
    // 固定值测试

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstRandom = RandomF::UnitRandom(2);
        ASSERT_TRUE(MathF::GetValue(0) <= firstRandom);
        ASSERT_TRUE(firstRandom <= MathF::GetValue(1));

        auto secondRandom = RandomF::SymmetricRandom(3);
        ASSERT_TRUE(MathF::GetValue(-1) <= secondRandom);
        ASSERT_TRUE(secondRandom <= MathF::GetValue(1));

        auto thirdRandom = RandomF::IntervalRandom(11.0f, 21.0f, 4);
        ASSERT_TRUE(11.0f <= thirdRandom && thirdRandom <= 21.0f);
    }
}

void Mathematics::RandomTesting::DoubleRandomTest()
{
    // 固定值测试

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        auto firstRandom = RandomD::UnitRandom(5);
        ASSERT_TRUE(MathD::GetValue(0) <= firstRandom);
        ASSERT_TRUE(firstRandom <= MathD::GetValue(1));

        auto secondRandom = RandomD::SymmetricRandom(6);
        ASSERT_TRUE(MathD::GetValue(-1) <= secondRandom);
        ASSERT_TRUE(secondRandom <= MathD::GetValue(1));

        auto thirdRandom = RandomD::IntervalRandom(21.0, 31.0, 7);
        ASSERT_TRUE(21.0 <= thirdRandom && thirdRandom <= 31.0);
    }
}
