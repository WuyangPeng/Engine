///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:45)

#include "RationalVectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/RationalVectorDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#include <random>

Mathematics::RationalVectorTesting::RationalVectorTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, RationalVectorTesting)

void Mathematics::RationalVectorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::RationalVectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::RationalVectorTesting::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT32_MIN, INT32_MAX);

    RationalVector<3, 7> vector0;

    for (auto i = 0; i < 3; ++i)
    {
        ASSERT_EQUAL(vector0[i], SignRational<7>(0));
    }

    for (auto i = 0; i < 3; ++i)
    {
        vector0[i] = SignRational<7>(randomDistribution0(generator), randomDistribution0(generator));
    }

    RationalVector<3, 7> vector1(vector0);

    for (auto i = 0; i < 3; ++i)
    {
        ASSERT_EQUAL(vector0[i], vector1[i]);
    }

    RationalVector<3, 7> vector2;

    for (auto i = 0; i < 3; ++i)
    {
        vector2[i] = SignRational<7>(randomDistribution0(generator), randomDistribution0(generator));
    }

    vector0 = vector2;

    for (auto i = 0; i < 3; ++i)
    {
        ASSERT_EQUAL(vector0[i], vector2[i]);
    }
}

void Mathematics::RationalVectorTesting::CalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT16_MIN, INT16_MAX);

    RationalVector<4, 15> vector0;
    RationalVector<4, 15> vector1;

    for (auto i = 0; i < 4; ++i)
    {
        vector0[i] = SignRational<15>(randomDistribution0(generator), randomDistribution0(generator));
        vector1[i] = SignRational<15>(randomDistribution0(generator), randomDistribution0(generator));
    }

    SignRational<15> squaredLength(0);
    for (auto i = 0; i < 4; ++i)
    {
        squaredLength += vector0[i] * vector0[i];
    }

    ASSERT_EQUAL(squaredLength, vector0.SquaredLength());

    SignRational<15> dot(0);
    for (auto i = 0; i < 4; ++i)
    {
        dot += vector0[i] * vector1[i];
    }

    ASSERT_EQUAL(dot, Dot(vector0, vector1));
}

void Mathematics::RationalVectorTesting::OperatorTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT16_MIN, INT16_MAX);

    RationalVector<4, 12> vector0;
    RationalVector<4, 12> vector1;

    for (auto i = 0; i < 4; ++i)
    {
        vector0[i] = SignRational<12>(randomDistribution0(generator), randomDistribution0(generator));
        vector1[i] = SignRational<12>(randomDistribution0(generator), randomDistribution0(generator));
    }

    RationalVector<4, 12> vector2 = vector0 + vector1;
    RationalVector<4, 12> vector3;

    for (auto i = 0; i < 4; ++i)
    {
        vector3[i] = vector0[i] + vector1[i];
    }

    ASSERT_EQUAL(vector2, vector3);

    vector2 = vector0 - vector1;

    for (auto i = 0; i < 4; ++i)
    {
        vector3[i] = vector0[i] - vector1[i];
    }

    ASSERT_EQUAL(vector2, vector3);

    SignRational<12> firstValue(randomDistribution0(generator), randomDistribution0(generator));

    vector2 = vector0 * firstValue;

    for (auto i = 0; i < 4; ++i)
    {
        vector3[i] = vector0[i] * firstValue;
    }

    ASSERT_EQUAL(vector2, vector3);

    firstValue = SignRational<12>(randomDistribution0(generator), randomDistribution0(generator));

    vector2 = firstValue * vector0;

    for (auto i = 0; i < 4; ++i)
    {
        vector3[i] = vector0[i] * firstValue;
    }

    ASSERT_EQUAL(vector2, vector3);

    firstValue = SignRational<12>(randomDistribution0(generator), randomDistribution0(generator));

    vector2 = vector0 / firstValue;

    for (auto i = 0; i < 4; ++i)
    {
        vector3[i] = vector0[i] / firstValue;
    }

    ASSERT_EQUAL(vector2, vector3);

    vector3 = -vector0;

    for (auto i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(-vector3[i], vector0[i]);
    }
}

void Mathematics::RationalVectorTesting::CompareTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT16_MIN, INT16_MAX);

    RationalVector<2, 3> vector0;
    RationalVector<2, 3> vector1;

    for (auto i = 0; i < 2; ++i)
    {
        vector0[i] = SignRational<3>(randomDistribution0(generator), randomDistribution0(generator));
        vector1[i] = SignRational<3>(randomDistribution0(generator), randomDistribution0(generator));
    }

    vector0[0] = SignRational<3>(0);
    vector1[0] = SignRational<3>(1);

    ASSERT_TRUE(vector0 == vector0);
    ASSERT_FALSE(vector0 == vector1);
    ASSERT_FALSE(vector1 != vector1);
    ASSERT_TRUE(vector0 != vector1);

    ASSERT_TRUE(vector0 < vector1);
    ASSERT_TRUE(vector0 <= vector1);
    ASSERT_FALSE(vector0 > vector1);
    ASSERT_FALSE(vector0 >= vector1);
}