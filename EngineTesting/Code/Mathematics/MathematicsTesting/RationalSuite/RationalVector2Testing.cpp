///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:44)

#include "RationalVector2Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/RationalVector2Detail.h"
#include "Mathematics/Rational/RationalVectorDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#include <random>

namespace Mathematics
{
    template class RationalVector2<5>;
    template class RationalVector2<8>;
}

Mathematics::RationalVector2Testing::RationalVector2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, RationalVector2Testing)

void Mathematics::RationalVector2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::RationalVector2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::RationalVector2Testing::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT32_MIN, INT32_MAX);

    RationalVector2<7> vector0;

    ASSERT_EQUAL(vector0.GetX(), SignRational<7>(0));
    ASSERT_EQUAL(vector0.GetY(), SignRational<7>(0));

    vector0.SetX(SignRational<7>(randomDistribution0(generator), randomDistribution0(generator)));

    vector0.SetY(SignRational<7>(randomDistribution0(generator), randomDistribution0(generator)));

    const RationalVector2<7> vector1(vector0);

    ASSERT_EQUAL(vector0.GetX(), vector1.GetX());
    ASSERT_EQUAL(vector0.GetY(), vector1.GetY());

    const SignRational<7> firstRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<7> secondRational(randomDistribution0(generator), randomDistribution0(generator));

    const RationalVector2<7> vector2(firstRational, secondRational);

    ASSERT_EQUAL(firstRational, vector2.GetX());
    ASSERT_EQUAL(secondRational, vector2.GetY());

    vector0 = vector2;

    ASSERT_EQUAL(vector0.GetX(), vector2.GetX());
    ASSERT_EQUAL(vector0.GetY(), vector2.GetY());

    RationalVector<2, 7> vector3;

    vector3[0] = SignRational<7>(randomDistribution0(generator), randomDistribution0(generator));

    vector3[1] = SignRational<7>(randomDistribution0(generator), randomDistribution0(generator));

    vector0 = vector3;

    ASSERT_EQUAL(vector0.GetX(), vector3[0]);
    ASSERT_EQUAL(vector0.GetY(), vector3[1]);

    const RationalVector2<7> vector4(vector3);

    ASSERT_EQUAL(vector4.GetX(), vector3[0]);
    ASSERT_EQUAL(vector4.GetY(), vector3[1]);
}

void Mathematics::RationalVector2Testing::CalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT16_MIN, INT16_MAX);

    const SignRational<15> firstRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<15> secondRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<15> thirdRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<15> fourthRational(randomDistribution0(generator), randomDistribution0(generator));

    const RationalVector2<15> vector0(firstRational, secondRational);
    const RationalVector2<15> vector1(thirdRational, fourthRational);

    const SignRational<15> squaredLength = firstRational * firstRational + secondRational * secondRational;

    ASSERT_EQUAL(squaredLength, vector0.SquaredLength());

    const SignRational<15> dot = firstRational * thirdRational + secondRational * fourthRational;

    ASSERT_EQUAL(dot, Dot(vector0, vector1));

    const RationalVector2<15> vector2(fourthRational, -thirdRational);

    ASSERT_EQUAL(vector2, vector1.Perp());

    const SignRational<15> fifthRational = firstRational * fourthRational - secondRational * thirdRational;

    ASSERT_EQUAL(fifthRational, DotPerp(vector0, vector1));
}

void Mathematics::RationalVector2Testing::OperatorTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT16_MIN, INT16_MAX);

    const SignRational<12> firstRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<12> secondRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<12> thirdRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<12> fourthRational(randomDistribution0(generator), randomDistribution0(generator));

    const RationalVector2<12> vector0(firstRational, secondRational);
    const RationalVector2<12> vector1(thirdRational, fourthRational);

    RationalVector2<12> vector2 = vector0 + vector1;
    RationalVector2<12> vector3(firstRational + thirdRational, secondRational + fourthRational);

    ASSERT_EQUAL(vector2, vector3);

    vector2 = vector0 - vector1;

    vector3.SetX(firstRational - thirdRational);
    vector3.SetY(secondRational - fourthRational);

    ASSERT_EQUAL(vector2, vector3);

    SignRational<12> firstValue(randomDistribution0(generator), randomDistribution0(generator));

    vector2 = vector0 * firstValue;

    vector3.SetX(firstRational * firstValue);
    vector3.SetY(secondRational * firstValue);

    ASSERT_EQUAL(vector2, vector3);

    firstValue = SignRational<12>(randomDistribution0(generator), randomDistribution0(generator));

    vector2 = firstValue * vector0;

    vector3.SetX(firstRational * firstValue);
    vector3.SetY(secondRational * firstValue);

    ASSERT_EQUAL(vector2, vector3);

    firstValue = SignRational<12>(randomDistribution0(generator), randomDistribution0(generator));

    vector2 = vector0 / firstValue;

    vector3.SetX(firstRational / firstValue);
    vector3.SetY(secondRational / firstValue);

    ASSERT_EQUAL(vector2, vector3);

    vector3 = -vector0;

    ASSERT_EQUAL(-vector3.GetX(), vector0.GetX());
    ASSERT_EQUAL(-vector3.GetY(), vector0.GetY());
}

void Mathematics::RationalVector2Testing::CompareTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT16_MIN, INT16_MAX);

    const SignRational<3> firstRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<3> secondRational(randomDistribution0(generator), randomDistribution0(generator));

    const RationalVector2<3> vector0(SignRational<3>(0), firstRational);
    const RationalVector2<3> vector1(SignRational<3>(1), secondRational);

    ASSERT_TRUE(vector0 == vector0);
    ASSERT_FALSE(vector0 == vector1);
    ASSERT_FALSE(vector1 != vector1);
    ASSERT_TRUE(vector0 != vector1);

    ASSERT_TRUE(vector0 < vector1);
    ASSERT_TRUE(vector0 <= vector1);
    ASSERT_FALSE(vector0 > vector1);
    ASSERT_FALSE(vector0 >= vector1);
}