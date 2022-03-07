// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 13:26)

#include "AVectorOrthonormalizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/AVectorOrthonormalizeDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class AVectorOrthonormalize<float>;
    template class AVectorOrthonormalize<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, AVectorOrthonormalizeTesting)

void Mathematics::AVectorOrthonormalizeTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalizeTest);
}

void Mathematics::AVectorOrthonormalizeTesting ::OrthonormalizeTest()
{
    default_random_engine randomEngine{};
    const uniform_real<double> firstRandomDistribution{ -10.0, 10.0 };
    const uniform_real<float> secondRandomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        AVectorD firstVector{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };
        AVectorD secondVector{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };
        AVectorD thirdVector{ firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine), firstRandomDistribution(randomEngine) };

        AVectorF fourthVector{ secondRandomDistribution(randomEngine), secondRandomDistribution(randomEngine), secondRandomDistribution(randomEngine) };
        AVectorF fifthVector{ secondRandomDistribution(randomEngine), secondRandomDistribution(randomEngine), secondRandomDistribution(randomEngine) };
        AVectorF sixthVector{ secondRandomDistribution(randomEngine), secondRandomDistribution(randomEngine), secondRandomDistribution(randomEngine) };

        const AVectorOrthonormalizeD firstOrthonormalize{ firstVector, secondVector, thirdVector, 1e-10 };

        firstVector.Normalize();
        auto dot0 = Dot(firstVector, secondVector);
        secondVector -= firstVector * dot0;
        secondVector.Normalize();
        dot0 = Dot(firstVector, thirdVector);
        thirdVector -= firstVector * dot0;
        dot0 = Dot(secondVector, thirdVector);
        thirdVector -= secondVector * dot0;
        thirdVector.Normalize();

        ASSERT_TRUE(Approximate(firstVector, firstOrthonormalize.GetUVector(), 1e-10));

        ASSERT_TRUE(Approximate(secondVector, firstOrthonormalize.GetVVector(), 1e-10));

        ASSERT_TRUE(Approximate(thirdVector, firstOrthonormalize.GetWVector(), 1e-10));

        const AVectorOrthonormalizeF secondOrthonormalize{ fourthVector, fifthVector, sixthVector, 1e-3f };

        fourthVector.Normalize();
        auto dot1 = Dot(fourthVector, fifthVector);
        fifthVector -= fourthVector * dot1;
        fifthVector.Normalize();

        dot1 = Dot(fourthVector, sixthVector);
        sixthVector -= fourthVector * dot1;
        dot1 = Dot(fifthVector, sixthVector);
        sixthVector -= fifthVector * dot1;
        sixthVector.Normalize();

        ASSERT_TRUE(Approximate(fourthVector, secondOrthonormalize.GetUVector(), 1e-8f));

        ASSERT_TRUE(Approximate(fifthVector, secondOrthonormalize.GetVVector(), 1e-8f));

        ASSERT_TRUE(Approximate(sixthVector, secondOrthonormalize.GetWVector(), 1e-4f));
    }
}
