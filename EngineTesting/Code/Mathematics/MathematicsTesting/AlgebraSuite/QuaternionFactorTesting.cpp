///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 22:30)

#include "QuaternionFactorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Polynomial.h"
#include "Mathematics/Algebra/QuaternionFactorDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;

namespace Mathematics
{
    template class QuaternionFactor<float>;
    template class QuaternionFactor<double>;
}

Mathematics::QuaternionFactorTesting::QuaternionFactorTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, QuaternionFactorTesting)

void Mathematics::QuaternionFactorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::QuaternionFactorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FactorXYZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorXZYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorYZXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorYXZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorZXYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FactorZYXTest);
}

void Mathematics::QuaternionFactorTesting::FactorXYZTest()
{
    default_random_engine generator{};
    const uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        QuaternionF firstQuaternion(firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator));

        const QuaternionFactorF firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::XYZ);

        const QuaternionF secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        const QuaternionF thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        const QuaternionF fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionF fifthQuaternion = secondQuaternion * thirdQuaternion * fourthQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();
    }
}

void Mathematics::QuaternionFactorTesting::FactorXZYTest()
{
    default_random_engine generator{};
    const uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        QuaternionF firstQuaternion(firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator));

        const QuaternionFactorF firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::XZY);

        const QuaternionF secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        const QuaternionF thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        const QuaternionF fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionF fifthQuaternion = secondQuaternion * fourthQuaternion * thirdQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();
    }
}

void Mathematics::QuaternionFactorTesting::FactorYZXTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        QuaternionD firstQuaternion(firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator));

        const QuaternionFactorD firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::YZX);

        const QuaternionD secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        const QuaternionD thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        const QuaternionD fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionD fifthQuaternion = thirdQuaternion * fourthQuaternion * secondQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();
    }
}

void Mathematics::QuaternionFactorTesting::FactorYXZTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        QuaternionD firstQuaternion(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

        const QuaternionFactorD firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::YXZ);

        const QuaternionD secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        const QuaternionD thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        const QuaternionD fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionD fifthQuaternion = thirdQuaternion * secondQuaternion * fourthQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();
    }
}

void Mathematics::QuaternionFactorTesting::FactorZXYTest()
{
    default_random_engine generator{};
    const uniform_real<float> firstRandomDistribution{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        QuaternionF firstQuaternion(firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator));

        const QuaternionFactorF firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::ZXY);

        const QuaternionF secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        const QuaternionF thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        const QuaternionF fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionF fifthQuaternion = fourthQuaternion * secondQuaternion * thirdQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();
    }
}

void Mathematics::QuaternionFactorTesting::FactorZYXTest()
{
    default_random_engine generator{};
    const uniform_real<double> firstRandomDistribution{ -100.0, 100.0 };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        QuaternionD firstQuaternion(firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator),
                                    firstRandomDistribution(generator));

        const QuaternionFactorD firstQuaternionFactor(firstQuaternion, QuaternionFactorFlags::ZYX);

        const QuaternionD secondQuaternion(firstQuaternionFactor.GetCosX(), firstQuaternionFactor.GetSinX(), 0.0f, 0.0f);

        const QuaternionD thirdQuaternion(firstQuaternionFactor.GetCosY(), 0.0f, firstQuaternionFactor.GetSinY(), 0.0f);

        const QuaternionD fourthQuaternion(firstQuaternionFactor.GetCosZ(), 0.0f, 0.0f, firstQuaternionFactor.GetSinZ());

        QuaternionD fifthQuaternion = fourthQuaternion * thirdQuaternion * secondQuaternion;

        fifthQuaternion.Normalize();
        firstQuaternion.Normalize();
    }
}
