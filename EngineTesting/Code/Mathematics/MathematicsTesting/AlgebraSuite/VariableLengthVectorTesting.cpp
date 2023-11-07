///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:39)

#include "VariableLengthVectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"

#include <boost/numeric/conversion/cast.hpp>
#include <random>

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class VariableLengthVector<float>;
    template class VariableLengthVector<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::VariableLengthVectorTesting::VariableLengthVectorTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, VariableLengthVectorTesting)

void Mathematics::VariableLengthVectorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::VariableLengthVectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VectorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
}

void Mathematics::VariableLengthVectorTesting::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<float> randomDistribution{ -100.0f, 100.0f };

    VariableLengthVectorF vector0(5);

    ASSERT_EQUAL(vector0.GetSize(), 5);

    std::vector<double> doubleVector;
    for (int i = 0; i < 15; ++i)
    {
        doubleVector.push_back(randomDistribution(generator));
    }

    VariableLengthVectorD vector1(doubleVector);
    ASSERT_EQUAL(vector1.GetSize(), boost::numeric_cast<int>(doubleVector.size()));

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector1[i], doubleVector.at(i), 1e-10);
    }

    VariableLengthVectorD vector2(vector1);
    ASSERT_EQUAL(vector1.GetSize(), vector2.GetSize());

    ASSERT_TRUE(Approximate(vector1, vector2, 1e-10));

    ASSERT_EQUAL(vector1.GetSize(), boost::numeric_cast<int>(doubleVector.size()));

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector1[i], doubleVector.at(i), 1e-10);
    }

    VariableLengthVectorD vector3;
    vector2 = vector3;

    ASSERT_EQUAL(vector2.GetSize(), 0);

    vector3.ResetSize(10);

    ASSERT_EQUAL(vector3.GetSize(), 10);
    ASSERT_EQUAL(vector2.GetSize(), 0);
}

void Mathematics::VariableLengthVectorTesting::AccessTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    std::vector<double> doubleVector;
    for (int i = 0; i < 15; ++i)
    {
        doubleVector.push_back(randomDistribution(generator));
    }

    const VariableLengthVectorD vector0(doubleVector);
    VariableLengthVectorD vector1(doubleVector);

    ASSERT_EQUAL(vector0.GetSize(), 15);
    ASSERT_EQUAL(vector1.GetSize(), 15);
}

void Mathematics::VariableLengthVectorTesting::ArithmeticCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    std::vector<double> firstDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        firstDoubleVector.push_back(randomDistribution(generator));
    }

    std::vector<double> secondDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        secondDoubleVector.push_back(randomDistribution(generator));
    }

    VariableLengthVectorD vector0(firstDoubleVector);
    VariableLengthVectorD vector1(secondDoubleVector);

    VariableLengthVectorD vector2 = -vector0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector2[i], -firstDoubleVector.at(i), 1e-10);
    }

    vector0 += vector1;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector0[i], firstDoubleVector.at(i) + secondDoubleVector.at(i), 1e-10);
    }

    vector1 -= vector0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector1[i], -firstDoubleVector.at(i), 1e-10);
    }

    vector2 *= 2.0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector2[i], -firstDoubleVector.at(i) * 2.0, 1e-10);
    }

    vector1 /= 2.0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector1[i], -firstDoubleVector.at(i) / 2.0, 1e-10);
    }

    vector2 = vector0 + vector1;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector2[i], firstDoubleVector.at(i) / 2.0 + secondDoubleVector.at(i), 1e-10);
    }

    vector2 = vector0 - vector1;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector2[i], firstDoubleVector.at(i) * 1.5 + secondDoubleVector.at(i), 1e-10);
    }

    vector2 = vector0 * 2.0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector2[i], firstDoubleVector.at(i) * 2.0 + secondDoubleVector.at(i) * 2.0, 1e-10);
    }

    vector2 = 2.0 * vector0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector2[i], firstDoubleVector.at(i) * 2.0 + secondDoubleVector.at(i) * 2.0, 1e-10);
    }

    vector2 = vector0 / 2.0;

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector2[i], firstDoubleVector.at(i) / 2.0 + secondDoubleVector.at(i) / 2.0, 1e-10);
    }
}

void Mathematics::VariableLengthVectorTesting::VectorCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    std::vector<double> firstDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        firstDoubleVector.push_back(randomDistribution(generator));
    }

    VariableLengthVectorD vector0(firstDoubleVector);

    double squaredLength = 0.0f;
    for (int i = 0; i < 15; ++i)
    {
        squaredLength += vector0[i] * vector0[i];
    }

    ASSERT_APPROXIMATE(squaredLength, vector0.SquaredLength(), 1e-10);
    ASSERT_APPROXIMATE(MathD::Sqrt(squaredLength), vector0.Length(), 1e-10);
    vector0.Normalize();

    for (int i = 0; i < 15; ++i)
    {
        ASSERT_APPROXIMATE(vector0[i], firstDoubleVector.at(i) / MathD::Sqrt(squaredLength), 1e-10);
    }

    std::vector<double> secondDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        secondDoubleVector.push_back(randomDistribution(generator));
    }

    VariableLengthVectorD vector1(secondDoubleVector);

    double dotProduct = 0.0;
    for (int i = 0; i < 15; ++i)
    {
        dotProduct += vector0[i] * vector1[i];
    }

    ASSERT_APPROXIMATE(dotProduct, Dot(vector0, vector1), 1e-10);
}

void Mathematics::VariableLengthVectorTesting::CompareTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution{ -100.0, 100.0 };

    std::vector<double> firstDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        firstDoubleVector.push_back(randomDistribution(generator));
    }

    std::vector<double> secondDoubleVector;
    for (int i = 0; i < 15; ++i)
    {
        secondDoubleVector.push_back(randomDistribution(generator));
    }

    VariableLengthVectorD vector0(firstDoubleVector);
    VariableLengthVectorD vector1(secondDoubleVector);

    vector0[0] = 0.0;
    vector1[0] = 1.0;

    ASSERT_TRUE(vector0 == vector0);
    ASSERT_FALSE(vector0 == vector1);
    ASSERT_TRUE(vector0 != vector1);
    ASSERT_TRUE(vector0 < vector1);
    ASSERT_TRUE(vector0 <= vector1);
    ASSERT_FALSE(vector0 > vector1);
    ASSERT_FALSE(vector0 >= vector1);

    ASSERT_TRUE(Approximate(vector0, vector0, 1e-10));
    ASSERT_TRUE(Approximate(vector1, vector1, 1e-10));
    ASSERT_FALSE(Approximate(vector0, vector1, 1e-10));
}
