///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:31)

#include "Int64Vector3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Rational/Int64Vector3.h"
#include "Mathematics/Rational/Int64VectorDetail.h"

#include <random>

Mathematics::Int64Vector3Testing::Int64Vector3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Int64Vector3Testing)

void Mathematics::Int64Vector3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Int64Vector3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::Int64Vector3Testing::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<int64_t> randomDistribution0{ INT64_MIN, INT64_MAX };

    auto vector0 = Int64Vector3::CreateDefault();

    ASSERT_EQUAL(vector0.GetX(), 0);
    ASSERT_EQUAL(vector0.GetY(), 0);
    ASSERT_EQUAL(vector0.GetZ(), 0);

    vector0.SetX(randomDistribution0(generator));
    vector0.SetY(randomDistribution0(generator));
    vector0.SetZ(randomDistribution0(generator));

    Int64Vector3 vector1(vector0);

    ASSERT_EQUAL(vector0.GetX(), vector1.GetX());
    ASSERT_EQUAL(vector0.GetY(), vector1.GetY());
    ASSERT_EQUAL(vector0.GetZ(), vector1.GetZ());

    Int64Vector3 vector2 = Int64Vector3::CreateDefault();

    vector2.SetX(randomDistribution0(generator));
    vector2.SetY(randomDistribution0(generator));
    vector2.SetZ(randomDistribution0(generator));

    vector0 = vector2;

    ASSERT_EQUAL(vector0.GetX(), vector2.GetX());
    ASSERT_EQUAL(vector0.GetY(), vector2.GetY());
    ASSERT_EQUAL(vector0.GetZ(), vector2.GetZ());

    Int64Vector<3> vector3;

    vector3[0] = randomDistribution0(generator);
    vector3[1] = randomDistribution0(generator);
    vector3[2] = randomDistribution0(generator);

    Int64Vector3 vector4(vector3);

    ASSERT_EQUAL(vector4.GetX(), vector3[0]);
    ASSERT_EQUAL(vector4.GetY(), vector3[1]);
    ASSERT_EQUAL(vector4.GetZ(), vector3[2]);

    vector2 = vector3;

    ASSERT_EQUAL(vector2.GetX(), vector3[0]);
    ASSERT_EQUAL(vector2.GetY(), vector3[1]);
    ASSERT_EQUAL(vector2.GetZ(), vector3[2]);

    Int64Vector3 vector5(vector3[0], vector3[1], vector3[2]);

    ASSERT_EQUAL(vector5.GetX(), vector3[0]);
    ASSERT_EQUAL(vector5.GetY(), vector3[1]);
    ASSERT_EQUAL(vector5.GetZ(), vector3[2]);

    vector5.SetX(vector3[1]);
    vector5.SetY(vector3[2]);
    vector5.SetZ(vector3[0]);

    ASSERT_EQUAL(vector5.GetX(), vector3[1]);
    ASSERT_EQUAL(vector5.GetY(), vector3[2]);
    ASSERT_EQUAL(vector5.GetZ(), vector3[0]);
}

void Mathematics::Int64Vector3Testing::CalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<int64_t> randomDistribution0{ INT64_MIN, INT64_MAX };

    Int64Vector3 vector0(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));
    Int64Vector3 vector1(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

    const auto squaredLength = vector0.GetX() * vector0.GetX() +
                               vector0.GetY() * vector0.GetY() +
                               vector0.GetZ() * vector0.GetZ();

    ASSERT_EQUAL(squaredLength, vector0.SquaredLength());

    const auto dot = vector0.GetX() * vector1.GetX() +
                     vector0.GetY() * vector1.GetY() +
                     vector0.GetZ() * vector1.GetZ();

    ASSERT_EQUAL(dot, vector0.Dot(vector1));

    auto vector2 = vector0.Cross(vector1);

    Int64Vector3 vector3(vector0.GetY() * vector1.GetZ() - vector0.GetZ() * vector1.GetY(),
                         vector0.GetZ() * vector1.GetX() - vector0.GetX() * vector1.GetZ(),
                         vector0.GetX() * vector1.GetY() - vector0.GetY() * vector1.GetX());

    ASSERT_EQUAL(vector2, vector3);

    const auto tripleScalar = vector0.Dot(vector1.Cross(vector2));

    ASSERT_EQUAL(tripleScalar, vector0.TripleScalar(vector1, vector2));
}

void Mathematics::Int64Vector3Testing::OperatorTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<int64_t> randomDistribution0{ INT64_MIN, INT64_MAX };

    Int64Vector3 vector0(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));
    Int64Vector3 vector1(randomDistribution0(generator),
                         randomDistribution0(generator),
                         randomDistribution0(generator));

    auto vector2 = vector0 + vector1;
    Int64Vector3 vector3(vector0.GetX() + vector1.GetX(),
                         vector0.GetY() + vector1.GetY(),
                         vector0.GetZ() + vector1.GetZ());

    ASSERT_EQUAL(vector2, vector3);

    vector2 = vector0 - vector1;

    vector3.SetX(vector0.GetX() - vector1.GetX());
    vector3.SetY(vector0.GetY() - vector1.GetY());
    vector3.SetZ(vector0.GetZ() - vector1.GetZ());

    ASSERT_EQUAL(vector2, vector3);

    int64_t firstValue = randomDistribution0(generator);

    vector2 = vector0 * firstValue;

    vector3.SetX(vector0.GetX() * firstValue);
    vector3.SetY(vector0.GetY() * firstValue);
    vector3.SetZ(vector0.GetZ() * firstValue);

    ASSERT_EQUAL(vector2, vector3);

    firstValue = randomDistribution0(generator);

    vector2 = firstValue * vector0;

    vector3.SetX(vector0.GetX() * firstValue);
    vector3.SetY(vector0.GetY() * firstValue);
    vector3.SetZ(vector0.GetZ() * firstValue);

    ASSERT_EQUAL(vector2, vector3);

    firstValue = randomDistribution0(generator);

    vector2 = vector0 / firstValue;

    vector3.SetX(vector0.GetX() / firstValue);
    vector3.SetY(vector0.GetY() / firstValue);
    vector3.SetZ(vector0.GetZ() / firstValue);

    ASSERT_EQUAL(vector2, vector3);

    vector3 = -vector0;

    ASSERT_EQUAL(-vector3.GetX(), vector0.GetX());
    ASSERT_EQUAL(-vector3.GetY(), vector0.GetY());
    ASSERT_EQUAL(-vector3.GetZ(), vector0.GetZ());
}

void Mathematics::Int64Vector3Testing::CompareTest()
{
    const std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_int<int64_t> randomDistribution0{ INT64_MIN, INT64_MAX };

    Int64Vector3 vector0(0, 2, 5);
    Int64Vector3 vector1(0, 3, 1);

    ASSERT_TRUE(vector0 == vector0);
    ASSERT_FALSE(vector0 == vector1);
    ASSERT_FALSE(vector1 != vector1);
    ASSERT_TRUE(vector0 != vector1);

    ASSERT_TRUE(vector0 < vector1);
    ASSERT_TRUE(vector0 <= vector1);
    ASSERT_FALSE(vector0 > vector1);
    ASSERT_FALSE(vector0 >= vector1);
}