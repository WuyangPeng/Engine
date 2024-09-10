///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:44)

#include "RationalVector3Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/RationalVector3Detail.h"
#include "Mathematics/Rational/RationalVectorDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#include <random>

namespace Mathematics
{
    template class RationalVector3<6>;
    template class RationalVector3<7>;
}

Mathematics::RationalVector3Testing::RationalVector3Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, RationalVector3Testing)

void Mathematics::RationalVector3Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::RationalVector3Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::RationalVector3Testing::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT32_MIN, INT32_MAX);

    RationalVector3<7> vector0;

    ASSERT_EQUAL(vector0.GetX(), SignRational<7>(0));
    ASSERT_EQUAL(vector0.GetY(), SignRational<7>(0));
    ASSERT_EQUAL(vector0.GetZ(), SignRational<7>(0));

    vector0.SetX(SignRational<7>(randomDistribution0(generator), randomDistribution0(generator)));

    vector0.SetY(SignRational<7>(randomDistribution0(generator), randomDistribution0(generator)));

    vector0.SetZ(SignRational<7>(randomDistribution0(generator), randomDistribution0(generator)));

    const RationalVector3<7> vector1(vector0);

    ASSERT_EQUAL(vector0.GetX(), vector1.GetX());
    ASSERT_EQUAL(vector0.GetY(), vector1.GetY());
    ASSERT_EQUAL(vector0.GetZ(), vector1.GetZ());

    const SignRational<7> firstRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<7> secondRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<7> thirdRational(randomDistribution0(generator), randomDistribution0(generator));

    const RationalVector3<7> vector2(firstRational, secondRational, thirdRational);

    ASSERT_EQUAL(firstRational, vector2.GetX());
    ASSERT_EQUAL(secondRational, vector2.GetY());
    ASSERT_EQUAL(thirdRational, vector2.GetZ());

    vector0 = vector2;

    ASSERT_EQUAL(vector0.GetX(), vector2.GetX());
    ASSERT_EQUAL(vector0.GetY(), vector2.GetY());
    ASSERT_EQUAL(vector0.GetZ(), vector2.GetZ());

    RationalVector<3, 7> vector3;

    vector3[0] = SignRational<7>(randomDistribution0(generator), randomDistribution0(generator));

    vector3[1] = SignRational<7>(randomDistribution0(generator), randomDistribution0(generator));

    vector3[2] = SignRational<7>(randomDistribution0(generator), randomDistribution0(generator));

    vector0 = vector3;

    ASSERT_EQUAL(vector0.GetX(), vector3[0]);
    ASSERT_EQUAL(vector0.GetY(), vector3[1]);
    ASSERT_EQUAL(vector0.GetZ(), vector3[2]);

    const RationalVector3<7> vector4(vector3);

    ASSERT_EQUAL(vector4.GetX(), vector3[0]);
    ASSERT_EQUAL(vector4.GetY(), vector3[1]);
    ASSERT_EQUAL(vector4.GetZ(), vector3[2]);
}

void Mathematics::RationalVector3Testing::CalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };

    std::uniform_int_distribution<int> randomDistribution0(INT16_MIN, INT16_MAX);

    const SignRational<15> firstRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<15> secondRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<15> thirdRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<15> fourthRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<15> fifthRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<15> sixthRational(randomDistribution0(generator), randomDistribution0(generator));

    const RationalVector3<15> vector0(firstRational, secondRational, thirdRational);
    const RationalVector3<15> vector1(fourthRational, fifthRational, sixthRational);

    const SignRational<15> squaredLength = firstRational * firstRational + secondRational * secondRational + thirdRational * thirdRational;

    ASSERT_EQUAL(squaredLength, vector0.SquaredLength());

    const SignRational<15> dot = firstRational * fourthRational + secondRational * fifthRational + thirdRational * sixthRational;

    ASSERT_EQUAL(dot, Dot(vector0, vector1));

    const RationalVector3<15> vector2(secondRational * sixthRational - thirdRational * fifthRational,
                                      thirdRational * fourthRational - firstRational * sixthRational,
                                      firstRational * fifthRational - secondRational * fourthRational);

    ASSERT_EQUAL(vector2, Cross(vector0, vector1));

    const SignRational<15> seventhRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<15> eighthRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<15> ninthRational(randomDistribution0(generator), randomDistribution0(generator));

    const RationalVector3<15> vector3(seventhRational, eighthRational, ninthRational);

    ASSERT_EQUAL(Dot(vector0, Cross(vector1, vector3)), TripleScalar(vector0, vector1, vector3));
}

void Mathematics::RationalVector3Testing::OperatorTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT16_MIN, INT16_MAX);

    const SignRational<12> firstRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<12> secondRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<12> thirdRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<12> fourthRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<12> fifthRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<12> sixthRational(randomDistribution0(generator), randomDistribution0(generator));

    const RationalVector3<12> vector0(firstRational, secondRational, thirdRational);
    const RationalVector3<12> vector1(fourthRational, fifthRational, sixthRational);

    RationalVector3<12> vector2 = vector0 + vector1;
    RationalVector3<12> vector3(firstRational + fourthRational, secondRational + fifthRational, thirdRational + sixthRational);

    ASSERT_EQUAL(vector2, vector3);

    vector2 = vector0 - vector1;

    vector3.SetX(firstRational - fourthRational);
    vector3.SetY(secondRational - fifthRational);
    vector3.SetZ(thirdRational - sixthRational);

    ASSERT_EQUAL(vector2, vector3);

    SignRational<12> firstValue(randomDistribution0(generator), randomDistribution0(generator));

    vector2 = vector0 * firstValue;

    vector3.SetX(firstRational * firstValue);
    vector3.SetY(secondRational * firstValue);
    vector3.SetZ(thirdRational * firstValue);

    ASSERT_EQUAL(vector2, vector3);

    firstValue = SignRational<12>(randomDistribution0(generator), randomDistribution0(generator));

    vector2 = firstValue * vector0;

    vector3.SetX(firstRational * firstValue);
    vector3.SetY(secondRational * firstValue);
    vector3.SetZ(thirdRational * firstValue);

    ASSERT_EQUAL(vector2, vector3);

    firstValue = SignRational<12>(randomDistribution0(generator), randomDistribution0(generator));

    vector2 = vector0 / firstValue;

    vector3.SetX(firstRational / firstValue);
    vector3.SetY(secondRational / firstValue);
    vector3.SetZ(thirdRational / firstValue);

    ASSERT_EQUAL(vector2, vector3);

    vector3 = -vector0;

    ASSERT_EQUAL(-vector3.GetX(), vector0.GetX());
    ASSERT_EQUAL(-vector3.GetY(), vector0.GetY());
    ASSERT_EQUAL(-vector3.GetZ(), vector0.GetZ());
}

void Mathematics::RationalVector3Testing::CompareTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<int> randomDistribution0(INT16_MIN, INT16_MAX);

    const SignRational<3> firstRational(randomDistribution0(generator), randomDistribution0(generator));

    const SignRational<3> secondRational(randomDistribution0(generator), randomDistribution0(generator));

    const RationalVector3<3> vector0(SignRational<3>(0), firstRational, secondRational);
    const RationalVector3<3> vector1(SignRational<3>(1), secondRational, firstRational);

    ASSERT_TRUE(vector0 == vector0);
    ASSERT_FALSE(vector0 == vector1);
    ASSERT_FALSE(vector1 != vector1);
    ASSERT_TRUE(vector0 != vector1);

    ASSERT_TRUE(vector0 < vector1);
    ASSERT_TRUE(vector0 <= vector1);
    ASSERT_FALSE(vector0 > vector1);
    ASSERT_FALSE(vector0 >= vector1);
}