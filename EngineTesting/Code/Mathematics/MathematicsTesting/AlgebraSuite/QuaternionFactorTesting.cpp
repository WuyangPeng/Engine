// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 09:43)

#include "QuaternionFactorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/QuaternionFactorDetail.h"

#include "Mathematics/Algebra/Polynomial.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class QuaternionFactor<float>;
    template class QuaternionFactor<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QuaternionFactorTesting)

void Mathematics::QuaternionFactorTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FactorXYZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorXZYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorYZXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorYXZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorZXYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorZYXTest);
}

void Mathematics::QuaternionFactorTesting ::FactorXYZTest()
{
    default_random_engine generator{};
    uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        QuaternionF firstQuaternion(firstRandomDistribution(generator),
                                        firstRandomDistribution(generator),
                                        firstRandomDistribution(generator),
                                        firstRandomDistribution(generator));

        QuaternionFactorF firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::XYZ);

        QuaternionF secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        QuaternionF thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        QuaternionF fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionF fifthQuaternion = secondQuaternion * thirdQuaternion * fourthQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        //ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) );
    }
}

void Mathematics::QuaternionFactorTesting ::FactorXZYTest()
{
    default_random_engine generator{};
    uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        QuaternionF firstQuaternion(firstRandomDistribution(generator),
                                        firstRandomDistribution(generator),
                                        firstRandomDistribution(generator),
                                        firstRandomDistribution(generator));

        QuaternionFactorF firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::XZY);

        QuaternionF secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        QuaternionF thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        QuaternionF fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionF fifthQuaternion = secondQuaternion * fourthQuaternion * thirdQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        //ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) );
    }
}

void Mathematics::QuaternionFactorTesting ::FactorYZXTest()
{
    default_random_engine generator{};
    uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        QuaternionD firstQuaternion(firstRandomDistribution(generator),
                                         firstRandomDistribution(generator),
                                         firstRandomDistribution(generator),
                                         firstRandomDistribution(generator));

        QuaternionFactorD firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::YZX);

        QuaternionD secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        QuaternionD thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        QuaternionD fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionD fifthQuaternion = thirdQuaternion * fourthQuaternion * secondQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        //ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-10) || Approximate(firstQuaternion, -fifthQuaternion,1e-10) );
    }
}

void Mathematics::QuaternionFactorTesting ::FactorYXZTest()
{
    default_random_engine generator{};
    uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        QuaternionD firstQuaternion(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

        QuaternionFactorD firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::YXZ);

        QuaternionD secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        QuaternionD thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        QuaternionD fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionD fifthQuaternion = thirdQuaternion * secondQuaternion * fourthQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        //	ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-10) || Approximate(firstQuaternion, -fifthQuaternion,1e-10) );
    }
}

void Mathematics::QuaternionFactorTesting ::FactorZXYTest()
{
    default_random_engine generator{};
    uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        QuaternionF firstQuaternion(firstRandomDistribution(generator),
                                        firstRandomDistribution(generator),
                                        firstRandomDistribution(generator),
                                        firstRandomDistribution(generator));

        QuaternionFactorF firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::ZXY);

        QuaternionF secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        QuaternionF thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        QuaternionF fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionF fifthQuaternion = fourthQuaternion * secondQuaternion * thirdQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        //ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-6f) || Approximate(firstQuaternion, -fifthQuaternion,1e-6f) );
    }
}

void Mathematics::QuaternionFactorTesting ::FactorZYXTest()
{
    default_random_engine generator{};
    uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        QuaternionD firstQuaternion(firstRandomDistribution(generator),
                                         firstRandomDistribution(generator),
                                         firstRandomDistribution(generator),
                                         firstRandomDistribution(generator));

        QuaternionFactorD firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::ZYX);

        QuaternionD secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        QuaternionD thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        QuaternionD fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionD fifthQuaternion = fourthQuaternion * thirdQuaternion * secondQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();

        //ASSERT_TRUE(Approximate(firstQuaternion, fifthQuaternion,1e-10) || Approximate(firstQuaternion, -fifthQuaternion,1e-10) );
    }
}
