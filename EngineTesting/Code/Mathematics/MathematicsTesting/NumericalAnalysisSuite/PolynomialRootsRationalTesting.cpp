///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:06)

#include "PolynomialRootsRationalTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRootsRationalDetail.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#include <random>

namespace Mathematics
{
    template class PolynomialRootsRational<float>;
    template class PolynomialRootsRational<double>;
}

Mathematics::PolynomialRootsRationalTesting::PolynomialRootsRationalTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, PolynomialRootsRationalTesting)

void Mathematics::PolynomialRootsRationalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::PolynomialRootsRationalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OnceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SecondaryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ThriceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(QuarticTest);
}

void Mathematics::PolynomialRootsRationalTesting::BaseTest()
{
    const PolynomialRootsRationalD firstPolynomialRootsRational(1e-10);

    ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
}

void Mathematics::PolynomialRootsRationalTesting::OnceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-1.0e10, 1.0e10);
    std::uniform_int<> randomDistribution1(0, 100000000);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        PolynomialRootsRationalD firstPolynomialRootsRational(1e-10);

        ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);

        const double constant = randomDistribution0(generator);
        double once = randomDistribution0(generator);

        if (MathD::FAbs(once) < 1e-10)
        {
            once = 1.0;
        }

        ASSERT_TRUE(firstPolynomialRootsRational.Linear(constant, once));

        ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 1);

        for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
        {
            const double root = firstPolynomialRootsRational.GetRoot(k);

            ASSERT_APPROXIMATE(root * once + constant, 0.0, 1e-5);
            ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
        }

        const PolynomialRootsRationalD::PolynomialRational constantPolynomialRational(constant);
        const PolynomialRootsRationalD::PolynomialRational oncePolynomialRational(once);

        ASSERT_TRUE(firstPolynomialRootsRational.Linear(constantPolynomialRational, oncePolynomialRational));

        ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 1);

        for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
        {
            const double root = firstPolynomialRootsRational.GetRoot(k);

            ASSERT_APPROXIMATE(root * oncePolynomialRational.ConvertTo<double>() + constantPolynomialRational.ConvertTo<double>(), 0.0, 1e-5);

            ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
        }

        const int constantDenominator = randomDistribution1(generator);
        const int onceDenominator = randomDistribution1(generator);

        const PolynomialRootsRationalD::PolynomialRational constantPolynomialRationalDenominator(static_cast<int>(constant), constantDenominator);
        const PolynomialRootsRationalD::PolynomialRational oncePolynomialRationalDenominator(static_cast<int>(once), onceDenominator);

        ASSERT_TRUE(firstPolynomialRootsRational.Linear(constantPolynomialRationalDenominator, oncePolynomialRationalDenominator));

        ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 1);

        for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
        {
            const double root = firstPolynomialRootsRational.GetRoot(k);

            ASSERT_APPROXIMATE(root * oncePolynomialRationalDenominator.ConvertTo<double>() + constantPolynomialRationalDenominator.ConvertTo<double>(), 0.0, 1e-2);

            ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
        }

        once = 0.0;
        ASSERT_FALSE(firstPolynomialRootsRational.Linear(constant, once));
        ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);

        ASSERT_FALSE(firstPolynomialRootsRational.Linear(constantPolynomialRational, PolynomialRootsRationalD::PolynomialRational()));
        ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
    }
}

void Mathematics::PolynomialRootsRationalTesting::SecondaryTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-1.0e8, 1.0e8);
    std::uniform_int<> randomDistribution1(0, 1000000);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        PolynomialRootsRationalD firstPolynomialRootsRational(1e-10);

        ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);

        const double constant = randomDistribution0(generator);
        const double once = randomDistribution0(generator);
        const double secondary = randomDistribution0(generator);

        bool result = firstPolynomialRootsRational.Quadratic(constant, once, secondary);

        if (result)
        {
            ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 || firstPolynomialRootsRational.GetQuantity() == 2);

            for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
            {
                const double root = firstPolynomialRootsRational.GetRoot(k);

                ASSERT_APPROXIMATE(root * root * secondary + root * once + constant, 0.0, 1e-6);

                if (firstPolynomialRootsRational.GetQuantity() == 2)
                    ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
                else
                    ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 2);
            }
        }
        else
        {
            ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
        }

        const PolynomialRootsRationalD::PolynomialRational constantPolynomialRational(constant);
        const PolynomialRootsRationalD::PolynomialRational oncePolynomialRational(once);
        const PolynomialRootsRationalD::PolynomialRational secondaryPolynomialRational(secondary);

        result = firstPolynomialRootsRational.Quadratic(constantPolynomialRational, oncePolynomialRational, secondaryPolynomialRational);

        if (result)
        {
            ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 || firstPolynomialRootsRational.GetQuantity() == 2);

            for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
            {
                const double root = firstPolynomialRootsRational.GetRoot(k);

                ASSERT_APPROXIMATE(root * root * secondaryPolynomialRational.ConvertTo<double>() + root * oncePolynomialRational.ConvertTo<double>() + constantPolynomialRational.ConvertTo<double>(), 0.0, 1e-6);

                if (firstPolynomialRootsRational.GetQuantity() == 2)
                    ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
                else
                    ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 2);
            }
        }
        else
        {
            ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
        }

        const int constantDenominator = randomDistribution1(generator);
        const int onceDenominator = randomDistribution1(generator);
        const int secondaryDenominator = randomDistribution1(generator);

        const PolynomialRootsRationalD::PolynomialRational constantPolynomialRationalDenominator(static_cast<int>(constant), constantDenominator);
        const PolynomialRootsRationalD::PolynomialRational oncePolynomialRationalDenominator(static_cast<int>(once), onceDenominator);
        const PolynomialRootsRationalD::PolynomialRational secondaryPolynomialRationalDenominator(static_cast<int>(secondary), secondaryDenominator);

        result = firstPolynomialRootsRational.Quadratic(constantPolynomialRationalDenominator, oncePolynomialRationalDenominator, secondaryPolynomialRationalDenominator);

        if (result)
        {
            ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 || firstPolynomialRootsRational.GetQuantity() == 2);

            for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
            {
                const double root = firstPolynomialRootsRational.GetRoot(k);

                ASSERT_APPROXIMATE(root * root * secondaryPolynomialRationalDenominator.ConvertTo<double>() + root * oncePolynomialRationalDenominator.ConvertTo<double>() + constantPolynomialRationalDenominator.ConvertTo<double>(), 0.0, 1e-6);

                if (firstPolynomialRootsRational.GetQuantity() == 2)
                    ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 1);
                else
                    ASSERT_EQUAL(firstPolynomialRootsRational.GetMultiplicity(k), 2);
            }
        }
        else
        {
            ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);
        }
    }
}

void Mathematics::PolynomialRootsRationalTesting::ThriceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-1.0e7, 1.0e7);
    std::uniform_int<> randomDistribution1(0, 1000000);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        PolynomialRootsRationalD firstPolynomialRootsRational(1e-10);

        ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);

        const double constant = randomDistribution0(generator);
        const double once = randomDistribution0(generator);
        const double secondary = randomDistribution0(generator);
        const double thrice = randomDistribution0(generator);

        ASSERT_TRUE(firstPolynomialRootsRational.Cubic(constant, once, secondary, thrice));

        ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 || firstPolynomialRootsRational.GetQuantity() == 2 || firstPolynomialRootsRational.GetQuantity() == 3);

        for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
        {
            const double root = firstPolynomialRootsRational.GetRoot(k);

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
        }

        const PolynomialRootsRationalD::PolynomialRational constantPolynomialRational(constant);
        const PolynomialRootsRationalD::PolynomialRational oncePolynomialRational(once);
        const PolynomialRootsRationalD::PolynomialRational secondaryPolynomialRational(secondary);
        const PolynomialRootsRationalD::PolynomialRational thricePolynomialRational(thrice);

        ASSERT_TRUE(firstPolynomialRootsRational.Cubic(constantPolynomialRational, oncePolynomialRational, secondaryPolynomialRational, thricePolynomialRational));

        ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 || firstPolynomialRootsRational.GetQuantity() == 2 || firstPolynomialRootsRational.GetQuantity() == 3);

        for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
        {
            const double root = firstPolynomialRootsRational.GetRoot(k);

            ASSERT_APPROXIMATE(constantPolynomialRational.ConvertTo<double>() +
                                   root * oncePolynomialRational.ConvertTo<double>() +
                                   root * root * secondaryPolynomialRational.ConvertTo<double>() +
                                   root * root * root * thricePolynomialRational.ConvertTo<double>(),
                               0.0, 1e-3);
        }

        const int constantDenominator = randomDistribution1(generator);
        const int onceDenominator = randomDistribution1(generator);
        const int secondaryDenominator = randomDistribution1(generator);
        const int thriceDenominator = randomDistribution1(generator);

        const PolynomialRootsRationalD::PolynomialRational constantPolynomialRationalDenominator(static_cast<int>(constant), constantDenominator);
        const PolynomialRootsRationalD::PolynomialRational oncePolynomialRationalDenominator(static_cast<int>(once), onceDenominator);
        const PolynomialRootsRationalD::PolynomialRational secondaryPolynomialRationalDenominator(static_cast<int>(secondary), secondaryDenominator);
        const PolynomialRootsRationalD::PolynomialRational thricePolynomialRationalDenominator(static_cast<int>(thrice), thriceDenominator);

        ASSERT_TRUE(firstPolynomialRootsRational.Cubic(constantPolynomialRationalDenominator, oncePolynomialRationalDenominator, secondaryPolynomialRationalDenominator, thricePolynomialRationalDenominator));

        ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 1 ||
                    firstPolynomialRootsRational.GetQuantity() == 2 ||
                    firstPolynomialRootsRational.GetQuantity() == 3);

        for (int k = 0; k < firstPolynomialRootsRational.GetQuantity(); ++k)
        {
            const double root = firstPolynomialRootsRational.GetRoot(k);

            ASSERT_APPROXIMATE(constantPolynomialRationalDenominator.ConvertTo<double>() +
                                   root * oncePolynomialRationalDenominator.ConvertTo<double>() +
                                   root * root * secondaryPolynomialRationalDenominator.ConvertTo<double>() +
                                   root * root * root * thricePolynomialRationalDenominator.ConvertTo<double>(),
                               0.0, 1e-3);
        }
    }

    // 构造判别式为零
    constexpr double constant = 1.0;
    constexpr double once = 3.0;
    constexpr double secondary = 3.0001;
    constexpr double thrice = 1.0;

    PolynomialRootsRationalD firstPolynomialRootsRational(1e-10);

    ASSERT_TRUE(firstPolynomialRootsRational.Cubic(constant, once, secondary, thrice));

    for (int i = 0; i < firstPolynomialRootsRational.GetQuantity(); ++i)
    {
        const double root = firstPolynomialRootsRational.GetRoot(i);

        ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
    }
}

void Mathematics::PolynomialRootsRationalTesting::QuarticTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real<double> randomDistribution0(-1.0e6, 1.0e6);
    std::uniform_int<> randomDistribution1(0, 1000000);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        PolynomialRootsRationalD firstPolynomialRootsRational(1e-10);

        ASSERT_EQUAL(firstPolynomialRootsRational.GetQuantity(), 0);

        const double constant = randomDistribution0(generator);
        const double once = randomDistribution0(generator);
        const double secondary = randomDistribution0(generator);
        const double thrice = randomDistribution0(generator);
        const double quartic = randomDistribution0(generator);

        if (firstPolynomialRootsRational.Quartic(constant, once, secondary, thrice, quartic))
        {
            ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 2 ||
                        firstPolynomialRootsRational.GetQuantity() == 4);
        }

        for (int m = 0; m < firstPolynomialRootsRational.GetQuantity(); ++m)
        {
            const double root = firstPolynomialRootsRational.GetRoot(m);

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice + root * root * root * root * quartic, 0.0, 1e-2);
        }

        const PolynomialRootsRationalD::PolynomialRational constantPolynomialRational(constant);
        const PolynomialRootsRationalD::PolynomialRational oncePolynomialRational(once);
        const PolynomialRootsRationalD::PolynomialRational secondaryPolynomialRational(secondary);
        const PolynomialRootsRationalD::PolynomialRational thricePolynomialRational(thrice);
        const PolynomialRootsRationalD::PolynomialRational quarticPolynomialRational(quartic);

        if (firstPolynomialRootsRational.Quartic(constantPolynomialRational, oncePolynomialRational, secondaryPolynomialRational, thricePolynomialRational, quarticPolynomialRational))
        {
            ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 2 ||
                        firstPolynomialRootsRational.GetQuantity() == 4);
        }

        for (int m = 0; m < firstPolynomialRootsRational.GetQuantity(); ++m)
        {
            const double root = firstPolynomialRootsRational.GetRoot(m);

            ASSERT_APPROXIMATE(constantPolynomialRational.ConvertTo<double>() +
                                   root * oncePolynomialRational.ConvertTo<double>() +
                                   root * root * secondaryPolynomialRational.ConvertTo<double>() +
                                   root * root * root * thricePolynomialRational.ConvertTo<double>() +
                                   root * root * root * root * quarticPolynomialRational.ConvertTo<double>(),
                               0.0, 1e-3);
        }

        const int constantDenominator = randomDistribution1(generator);
        const int onceDenominator = randomDistribution1(generator);
        const int secondaryDenominator = randomDistribution1(generator);
        const int thriceDenominator = randomDistribution1(generator);
        const int quarticDenominator = randomDistribution1(generator);

        const PolynomialRootsRationalD::PolynomialRational constantPolynomialRationalDenominator(static_cast<int>(constant), constantDenominator);
        const PolynomialRootsRationalD::PolynomialRational oncePolynomialRationalDenominator(static_cast<int>(once), onceDenominator);
        const PolynomialRootsRationalD::PolynomialRational secondaryPolynomialRationalDenominator(static_cast<int>(secondary), secondaryDenominator);
        const PolynomialRootsRationalD::PolynomialRational thricePolynomialRationalDenominator(static_cast<int>(thrice), thriceDenominator);
        const PolynomialRootsRationalD::PolynomialRational quarticPolynomialRationalDenominator(static_cast<int>(thrice), quarticDenominator);

        if (firstPolynomialRootsRational.Quartic(constantPolynomialRationalDenominator, oncePolynomialRationalDenominator, secondaryPolynomialRationalDenominator, thricePolynomialRationalDenominator, quarticPolynomialRationalDenominator))
        {
            ASSERT_TRUE(firstPolynomialRootsRational.GetQuantity() == 2 ||
                        firstPolynomialRootsRational.GetQuantity() == 4);
        }

        for (int m = 0; m < firstPolynomialRootsRational.GetQuantity(); ++m)
        {
            const double root = firstPolynomialRootsRational.GetRoot(m);

            ASSERT_APPROXIMATE(constantPolynomialRationalDenominator.ConvertTo<double>() +
                                   root * oncePolynomialRationalDenominator.ConvertTo<double>() +
                                   root * root * secondaryPolynomialRationalDenominator.ConvertTo<double>() +
                                   root * root * root * thricePolynomialRationalDenominator.ConvertTo<double>() +
                                   root * root * root * root * quarticPolynomialRationalDenominator.ConvertTo<double>(),
                               0.0, 1e-3);
            ;
        }
    }
}
