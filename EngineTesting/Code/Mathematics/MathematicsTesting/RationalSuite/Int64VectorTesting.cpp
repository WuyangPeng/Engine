///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:31)

#include "Int64VectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Rational/Int64VectorDetail.h"

#include <random>

Mathematics::Int64VectorTesting::Int64VectorTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Int64VectorTesting)

void Mathematics::Int64VectorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Int64VectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::Int64VectorTesting::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_int<int64_t> randomDistribution0{ INT64_MIN, INT64_MAX };

    Int64Vector<4> vector0;

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(vector0[i], 0);
    }

    for (int i = 0; i < 4; ++i)
    {
        vector0[i] = randomDistribution0(generator);
    }

    Int64Vector<4> vector1(vector0);

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(vector0[i], vector1[i]);
    }

    Int64Vector<4> vector2;

    for (int i = 0; i < 4; ++i)
    {
        vector2[i] = randomDistribution0(generator);
    }

    vector0 = vector2;

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(vector0[i], vector2[i]);
    }
}

void Mathematics::Int64VectorTesting::CalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_int<int64_t> randomDistribution0{ INT64_MIN, INT64_MAX };

    Int64Vector<4> vector0;
    Int64Vector<4> vector1;

    for (int i = 0; i < 4; ++i)
    {
        vector0[i] = randomDistribution0(generator);
        vector1[i] = randomDistribution0(generator);
    }

    int64_t squaredLength = 0;
    for (int i = 0; i < 4; ++i)
    {
        squaredLength += vector0[i] * vector0[i];
    }

    ASSERT_EQUAL(squaredLength, vector0.SquaredLength());

    int64_t dot = 0;
    for (int i = 0; i < 4; ++i)
    {
        dot += vector0[i] * vector1[i];
    }

    ASSERT_EQUAL(dot, Dot(vector0, vector1));
}

void Mathematics::Int64VectorTesting::OperatorTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_int<int64_t> randomDistribution0{ INT64_MIN, INT64_MAX };

    Int64Vector<4> vector0;
    Int64Vector<4> vector1;

    for (int i = 0; i < 4; ++i)
    {
        vector0[i] = randomDistribution0(generator);
        vector1[i] = randomDistribution0(generator);
    }

    Int64Vector<4> vector2 = vector0 + vector1;
    Int64Vector<4> vector3;

    for (int i = 0; i < 4; ++i)
    {
        vector3[i] = vector0[i] + vector1[i];
    }

    ASSERT_EQUAL(vector2, vector3);

    vector2 = vector0 - vector1;

    for (int i = 0; i < 4; ++i)
    {
        vector3[i] = vector0[i] - vector1[i];
    }

    ASSERT_EQUAL(vector2, vector3);

    int64_t firstValue = randomDistribution0(generator);

    vector2 = vector0 * firstValue;

    for (int i = 0; i < 4; ++i)
    {
        vector3[i] = vector0[i] * firstValue;
    }

    ASSERT_EQUAL(vector2, vector3);

    firstValue = randomDistribution0(generator);

    vector2 = firstValue * vector0;

    for (int i = 0; i < 4; ++i)
    {
        vector3[i] = vector0[i] * firstValue;
    }

    ASSERT_EQUAL(vector2, vector3);

    firstValue = randomDistribution0(generator);

    vector2 = vector0 / firstValue;

    for (int i = 0; i < 4; ++i)
    {
        vector3[i] = vector0[i] / firstValue;
    }

    ASSERT_EQUAL(vector2, vector3);

    vector3 = -vector0;

    for (int i = 0; i < 4; ++i)
    {
        ASSERT_EQUAL(-vector3[i], vector0[i]);
    }
}

void Mathematics::Int64VectorTesting::CompareTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_int<int64_t> randomDistribution0{ INT64_MIN, INT64_MAX };

    Int64Vector<4> vector0;
    Int64Vector<4> vector1;

    for (int i = 0; i < 4; ++i)
    {
        vector0[i] = randomDistribution0(generator);
        vector1[i] = randomDistribution0(generator);
    }

    vector0[0] = 0;
    vector1[0] = 1;

    ASSERT_TRUE(vector0 == vector0);
    ASSERT_FALSE(vector0 == vector1);
    ASSERT_FALSE(vector1 != vector1);
    ASSERT_TRUE(vector0 != vector1);

    ASSERT_TRUE(vector0 < vector1);
    ASSERT_TRUE(vector0 <= vector1);
    ASSERT_FALSE(vector0 > vector1);
    ASSERT_FALSE(vector0 >= vector1);
}