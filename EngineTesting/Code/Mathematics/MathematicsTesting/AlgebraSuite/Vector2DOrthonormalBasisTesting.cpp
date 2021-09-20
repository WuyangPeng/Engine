// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 11:04)

#include "Vector2DOrthonormalBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DOrthonormalBasisDetail.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Vector2DOrthonormalBasisTesting)

void Mathematics::Vector2DOrthonormalBasisTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalBasisTest);
}

void Mathematics::Vector2DOrthonormalBasisTesting::OrthonormalBasisTest()
{
    default_random_engine generator{};

    uniform_real<double> firstRandomDistribution{ -10.0, 10.0 };
    uniform_real<float> secondRandomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        DoubleVector2D firstVector(firstRandomDistribution(generator), firstRandomDistribution(generator));

        FloatVector2D secondVector(secondRandomDistribution(generator), secondRandomDistribution(generator));

        DoubleVector2DOrthonormalBasis firstOrthonormalBasis(firstVector);

        firstVector.Normalize();

        ASSERT_TRUE(DoubleVector2DTools::Approximate(firstVector, firstOrthonormalBasis.GetUVector(), 1e-10));

        ASSERT_TRUE(DoubleVector2DTools::Approximate(DoubleVector2D(firstVector[1], -firstVector[0]), firstOrthonormalBasis.GetVVector(), 1e-10));

        FloatVector2DOrthonormalBasis secondOrthonormalBasis(secondVector);

        secondVector.Normalize();

        ASSERT_TRUE(FloatVector2DTools::Approximate(secondVector, secondOrthonormalBasis.GetUVector(), 1e-8f));

        ASSERT_TRUE(FloatVector2DTools::Approximate(DoubleVector2D(secondVector[1], -secondVector[0]), secondOrthonormalBasis.GetVVector(), 1e-8f));
    }
}
