// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 13:24)

#include "AVectorOrthonormalBasisTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorOrthonormalBasisDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class AVectorOrthonormalBasis<float>;
    template class AVectorOrthonormalBasis<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, AVectorOrthonormalBasisTesting)

void Mathematics::AVectorOrthonormalBasisTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalBasisTest);
}

void Mathematics::AVectorOrthonormalBasisTesting ::OrthonormalBasisTest()
{
    default_random_engine randomEngine{};
    const uniform_real<double> firstRandomDistribution{ -10.0, 10.0 };
    const uniform_real<float> secondRandomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        AVectorD firstVector{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        AVectorF secondVector{ secondRandomDistribution(randomEngine), secondRandomDistribution(randomEngine), secondRandomDistribution(randomEngine) };

        const AVectorOrthonormalBasisD firstOrthonormalBasis{ firstVector, false };

        firstVector.Normalize();

        ASSERT_TRUE(Approximate(firstVector, firstOrthonormalBasis.GetWVector(), 1e-10));

        const AVectorOrthonormalBasisF secondOrthonormalBasis{ secondVector, false };

        secondVector.Normalize();

        ASSERT_TRUE(Approximate(secondVector, secondOrthonormalBasis.GetWVector(), 1e-8f));
    }
}
