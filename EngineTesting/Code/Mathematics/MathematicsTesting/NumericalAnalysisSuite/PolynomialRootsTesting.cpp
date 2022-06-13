///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 15:57)

#include "PolynomialRootsTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/PolynomialDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/NumericalAnalysis/PolynomialRootsDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, PolynomialRootsTesting)

void Mathematics::PolynomialRootsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OnceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SecondaryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ThriceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SpecialCubicTest);
    ASSERT_NOT_THROW_EXCEPTION_0(QuarticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(PolynomialTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AllRealPartsNegativeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AllRealPartsPositiveTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetRootCountTest);
}

void Mathematics::PolynomialRootsTesting::BaseTest()
{
    PolynomialRootsD firstPolynomialRoots(1e-10);

    ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);
}

void Mathematics::PolynomialRootsTesting::OnceTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e10, 1.0e10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        PolynomialRootsD firstPolynomialRoots(1e-10);

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);

        auto constant = firstRandomDistribution(generator);
        auto once = firstRandomDistribution(generator);

        if (MathD::FAbs(once) < 1e-10)
        {
            once = 1.0;
        }

        ASSERT_TRUE(firstPolynomialRoots.FindAlgebraic(constant, once));

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 1);

        for (auto m = 0; m < firstPolynomialRoots.GetCount(); ++m)
        {
            auto root = firstPolynomialRoots.GetRoot(m);

            ASSERT_APPROXIMATE(root * once + constant, 0.0, 1e-6);
        }

        for (auto iter = firstPolynomialRoots.GetBegin(); iter != firstPolynomialRoots.GetEnd(); ++iter)
        {
            auto root = *iter;

            ASSERT_APPROXIMATE(root * once + constant, 0.0, 1e-6);
        }

        auto bound = firstPolynomialRoots.GetBound(constant, once);

        ASSERT_APPROXIMATE(MathD::FAbs(constant) / once + 1, bound, 1e-10);

        once = 1e-12;
        ASSERT_FALSE(firstPolynomialRoots.FindAlgebraic(constant, once));
        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);
    }
}

void Mathematics::PolynomialRootsTesting::SecondaryTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e8, 1.0e8);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        PolynomialRootsD firstPolynomialRoots(1e-10);

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);

        auto constant = firstRandomDistribution(generator);
        auto once = firstRandomDistribution(generator);
        auto secondary = firstRandomDistribution(generator);

        const auto result = firstPolynomialRoots.FindAlgebraic(constant, once, secondary);

        if (result)
        {
            ASSERT_TRUE(firstPolynomialRoots.GetCount() == 1 || firstPolynomialRoots.GetCount() == 2);

            for (auto m = 0; m < firstPolynomialRoots.GetCount(); ++m)
            {
                auto root = firstPolynomialRoots.GetRoot(m);

                ASSERT_APPROXIMATE(root * root * secondary + root * once + constant, 0.0, 1e-6);
            }

            for (auto iter = firstPolynomialRoots.GetBegin(); iter != firstPolynomialRoots.GetEnd(); ++iter)
            {
                auto root = *iter;

                ASSERT_APPROXIMATE(root * root * secondary + root * once + constant, 0.0, 1e-6);
            }
        }
        else
        {
            ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);
        }

        auto bound = firstPolynomialRoots.GetBound(constant, once, secondary);

        auto constantValue = MathD::FAbs(constant) / secondary + 1;
        auto onceValue = MathD::FAbs(once) / secondary + 1;

        auto maxValue = constantValue < onceValue ? onceValue : constantValue;

        ASSERT_APPROXIMATE(maxValue, bound, 1e-10);
    }
}

void Mathematics::PolynomialRootsTesting::ThriceTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e5, 1.0e5);
    const uniform_real<double> secondRandomDistribution(-1.0e1, 1.0e1);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        PolynomialRootsD firstPolynomialRoots(1e-6);

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);

        auto constant = firstRandomDistribution(generator);
        auto once = firstRandomDistribution(generator);
        auto secondary = firstRandomDistribution(generator);
        auto thrice = firstRandomDistribution(generator);

        ASSERT_TRUE(firstPolynomialRoots.FindAlgebraic(constant, once, secondary, thrice));

        ASSERT_TRUE(firstPolynomialRoots.GetCount() == 1 || firstPolynomialRoots.GetCount() == 2 || firstPolynomialRoots.GetCount() == 3);

        for (auto m = 0; m < firstPolynomialRoots.GetCount(); ++m)
        {
            auto root = firstPolynomialRoots.GetRoot(m);

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
        }

        for (auto iter = firstPolynomialRoots.GetBegin(); iter != firstPolynomialRoots.GetEnd(); ++iter)
        {
            auto root = *iter;

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
        }

        auto bound = firstPolynomialRoots.GetBound(constant, once, secondary, thrice);

        auto constantValue = MathD::FAbs(constant) / thrice + 1;
        auto onceValue = MathD::FAbs(once) / thrice + 1;
        auto secondaryValue = MathD::FAbs(secondary) / thrice + 1;

        auto maxValue = constantValue < onceValue ? onceValue : constantValue;
        maxValue = maxValue < secondaryValue ? secondaryValue : maxValue;

        ASSERT_APPROXIMATE(maxValue, bound, 1e-10);

        constant = secondRandomDistribution(generator);
        once = secondRandomDistribution(generator);
        secondary = secondRandomDistribution(generator);
        thrice = 1.0;

        PolynomialRootsD secondPolynomialRoots(1e-6);
        secondPolynomialRoots.SetMaxIterations(1024);

        ASSERT_TRUE(secondPolynomialRoots.FindEigenvalues(constant, once, secondary, thrice, false));

        ASSERT_TRUE(secondPolynomialRoots.GetCount() == 1 || secondPolynomialRoots.GetCount() == 2 || secondPolynomialRoots.GetCount() == 3);

        for (auto m = 0; m < secondPolynomialRoots.GetCount(); ++m)
        {
            auto root = secondPolynomialRoots.GetRoot(m);

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
        }

        for (auto iter = secondPolynomialRoots.GetBegin(); iter != secondPolynomialRoots.GetEnd(); ++iter)
        {
            auto root = *iter;

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
        }

        ASSERT_TRUE(secondPolynomialRoots.FindEigenvalues(constant, once, secondary, thrice, true));

        ASSERT_TRUE(secondPolynomialRoots.GetCount() == 1 || secondPolynomialRoots.GetCount() == 2 || secondPolynomialRoots.GetCount() == 3);

        for (auto m = 0; m < secondPolynomialRoots.GetCount(); ++m)
        {
            auto root = secondPolynomialRoots.GetRoot(m);

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
        }

        for (auto iter = secondPolynomialRoots.GetBegin(); iter != secondPolynomialRoots.GetEnd(); ++iter)
        {
            auto root = *iter;

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
        }

        ASSERT_TRUE(secondPolynomialRoots.FindEigenvalues(constant, once, secondary, thrice, true, 0.001, false));

        ASSERT_TRUE(secondPolynomialRoots.GetCount() == 1 ||
                    secondPolynomialRoots.GetCount() == 2 ||
                    secondPolynomialRoots.GetCount() == 3);

        for (auto m = 0; m < secondPolynomialRoots.GetCount(); ++m)
        {
            auto root = secondPolynomialRoots.GetRoot(m);

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
        }

        for (auto iter = secondPolynomialRoots.GetBegin(); iter != secondPolynomialRoots.GetEnd(); ++iter)
        {
            auto root = *iter;

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
        }
    }

    // 构造判别式为零
    constexpr auto constant = 1.0;
    constexpr auto once = 3.0;
    constexpr auto secondary = 3.0001;
    constexpr auto thrice = 1.0;

    PolynomialRootsD firstPolynomialRoots(1e-6);

    ASSERT_TRUE(firstPolynomialRoots.FindAlgebraic(constant, once, secondary, thrice));

    ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 2);

    for (auto i = 0; i < firstPolynomialRoots.GetCount(); ++i)
    {
        auto root = firstPolynomialRoots.GetRoot(i);

        ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
    }

    for (auto iter = firstPolynomialRoots.GetBegin(); iter != firstPolynomialRoots.GetEnd(); ++iter)
    {
        auto root = *iter;

        ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice, 0.0, 1e-3);
    }
}

void Mathematics::PolynomialRootsTesting::SpecialCubicTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e7, 1.0e7);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        PolynomialRootsD firstPolynomialRoots(1e-6);

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);

        auto constant = firstRandomDistribution(generator);
        auto once = MathD::FAbs(firstRandomDistribution(generator));
        auto thrice = MathD::FAbs(firstRandomDistribution(generator));

        auto root = firstPolynomialRoots.SpecialCubic(thrice, once, constant);

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);

        ASSERT_APPROXIMATE(-constant + root * once + root * root * root * thrice, 0.0, 1e-3);
    }
}

void Mathematics::PolynomialRootsTesting::QuarticTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e3, 1.0e3);
    const uniform_real<double> secondRandomDistribution(-2.0, 2.0);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        PolynomialRootsD firstPolynomialRoots(1e-6);

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);

        auto constant = firstRandomDistribution(generator);
        auto once = firstRandomDistribution(generator);
        auto secondary = firstRandomDistribution(generator);
        auto thrice = firstRandomDistribution(generator);
        auto quartic = firstRandomDistribution(generator);

        if (firstPolynomialRoots.FindAlgebraic(constant, once, secondary, thrice, quartic))
        {
            ASSERT_TRUE(firstPolynomialRoots.GetCount() == 2 || firstPolynomialRoots.GetCount() == 4);
        }

        for (auto m = 0; m < firstPolynomialRoots.GetCount(); ++m)
        {
            auto root = firstPolynomialRoots.GetRoot(m);

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice + root * root * root * root * quartic, 0.0, 1e-1);
        }

        for (auto iter = firstPolynomialRoots.GetBegin(); iter != firstPolynomialRoots.GetEnd(); ++iter)
        {
            auto root = *iter;

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice + root * root * root * root * quartic, 0.0, 1e-1);
        }

        auto bound = firstPolynomialRoots.GetBound(constant, once, secondary, thrice, quartic);

        auto constantValue = MathD::FAbs(constant) / quartic + 1;
        auto onceValue = MathD::FAbs(once) / quartic + 1;
        auto secondaryValue = MathD::FAbs(secondary) / quartic + 1;
        auto thriceValue = MathD::FAbs(thrice) / quartic + 1;

        auto maxValue = constantValue < onceValue ? onceValue : constantValue;
        maxValue = maxValue < secondaryValue ? secondaryValue : maxValue;
        maxValue = maxValue < thriceValue ? thriceValue : maxValue;

        ASSERT_APPROXIMATE(maxValue, bound, 1e-10);

        constant = secondRandomDistribution(generator);
        once = secondRandomDistribution(generator);
        secondary = secondRandomDistribution(generator);
        thrice = secondRandomDistribution(generator);
        quartic = 1.0;

        PolynomialRootsD secondPolynomialRoots(1e-5);
        secondPolynomialRoots.SetMaxIterations(4096);

        if (secondPolynomialRoots.FindEigenvalues(constant, once, secondary, thrice, quartic, false))
        {
            ASSERT_TRUE(secondPolynomialRoots.GetCount() == 2 || secondPolynomialRoots.GetCount() == 4);
        }

        for (auto m = 0; m < secondPolynomialRoots.GetCount(); ++m)
        {
            auto root = secondPolynomialRoots.GetRoot(m);

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice + root * root * root * root * quartic, 0.0, 1e-1);
        }

        for (auto iter = secondPolynomialRoots.GetBegin(); iter != secondPolynomialRoots.GetEnd(); ++iter)
        {
            auto root = *iter;

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice + root * root * root * root * quartic, 0.0, 1e-1);
        }

        if (secondPolynomialRoots.FindEigenvalues(constant, once, secondary, thrice, quartic, true))
        {
            ASSERT_TRUE(secondPolynomialRoots.GetCount() == 2 || secondPolynomialRoots.GetCount() == 4);
        }

        for (auto m = 0; m < secondPolynomialRoots.GetCount(); ++m)
        {
            auto root = secondPolynomialRoots.GetRoot(m);

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice + root * root * root * root * quartic, 0.0, 1e-1);
        }

        for (auto iter = secondPolynomialRoots.GetBegin(); iter != secondPolynomialRoots.GetEnd(); ++iter)
        {
            auto root = *iter;

            ASSERT_APPROXIMATE(constant + root * once + root * root * secondary + root * root * root * thrice + root * root * root * root * quartic, 0.0, 1e-1);
        }
    }
}

void Mathematics::PolynomialRootsTesting::PolynomialTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e6, 1.0e6);
    const uniform_int<> secondRandomDistribution(2, 8);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        PolynomialRootsD firstPolynomialRoots(1e-6);

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);

        vector<double> tuple;
        auto size = secondRandomDistribution(generator);

        for (auto m = 0; m < size; ++m)
        {
            tuple.push_back(firstRandomDistribution(generator));
        }

        PolynomialD firstPolynomial(tuple);

        MAYBE_UNUSED const auto result = firstPolynomialRoots.FindBisection(firstPolynomial, 20);

        for (auto m = 0; m < firstPolynomialRoots.GetCount(); ++m)
        {
            auto root = firstPolynomialRoots.GetRoot(m);

            ASSERT_APPROXIMATE(firstPolynomial(root), 0.0, 1e-1);
        }

        for (auto iter = firstPolynomialRoots.GetBegin(); iter != firstPolynomialRoots.GetEnd(); ++iter)
        {
            auto root = *iter;

            ASSERT_APPROXIMATE(firstPolynomial(root), 0.0, 1e-1);
        }

        auto bound = firstPolynomialRoots.GetBound(firstPolynomial);

        firstPolynomial.Compress(1e-6);
        auto maxValue = 0.0;
        for (auto m = 0; m < firstPolynomial.GetDegree(); ++m)
        {
            auto value = MathD::FAbs(firstPolynomial[m]) / firstPolynomial.GetEnd();
            if (maxValue < value)
            {
                maxValue = value;
            }
        }

        ASSERT_APPROXIMATE(maxValue + 1.0, bound, 1e-10);
    }
}

void Mathematics::PolynomialRootsTesting::AllRealPartsNegativeTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e6, 1.0e6);
    const uniform_int<> secondRandomDistribution(2, 8);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        PolynomialRootsD firstPolynomialRoots(1e-6);

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);

        vector<double> tuple;
        auto size = secondRandomDistribution(generator);

        for (auto i = 0; i < size; ++i)
        {
            tuple.push_back(firstRandomDistribution(generator));
        }

        PolynomialD firstPolynomial(tuple);

        const auto result = firstPolynomialRoots.AllRealPartsNegative(firstPolynomial);

        // 使多项式首一。
        auto degree = firstPolynomial.GetDegree();
        if (1e-6 < MathD::FAbs(firstPolynomial.GetEnd() - 1.0))
        {
            for (auto i = 0; i < degree; ++i)
            {
                firstPolynomial[i] /= firstPolynomial.GetEnd();
            }

            firstPolynomial[degree] = 1.0;
        }

        auto testResult = true;
        while (1 <= degree)
        {
            if (firstPolynomial[degree - 1] <= 0.0)
            {
                testResult = false;
                break;
            }

            if (degree == 1)
            {
                testResult = true;
                break;
            }

            vector<double> tmpCoeff(degree);
            tmpCoeff.at(0) = 2.0 * firstPolynomial[0] * firstPolynomial[degree - 1];

            for (auto i = 1; i <= degree - 2; ++i)
            {
                tmpCoeff.at(i) = firstPolynomial[degree - 1] * firstPolynomial[i];
                if (((degree - i) % 2) == 0)
                {
                    tmpCoeff.at(i) -= firstPolynomial[i - 1];
                }
                tmpCoeff.at(i) *= 2.0;
            }
            const auto temp = degree - 1;
            tmpCoeff.at(temp) = 2.0 * firstPolynomial[temp] * firstPolynomial[temp];

            auto nextDegree = 0;
            for (nextDegree = degree - 1; 0 <= nextDegree; --nextDegree)
            {
                if (1e-6 < MathD::FAbs(tmpCoeff.at(nextDegree)))
                {
                    break;
                }
            }
            for (auto i = 0; i <= nextDegree - 1; ++i)
            {
                firstPolynomial[i] = tmpCoeff.at(i) / tmpCoeff.at(nextDegree);
            }

            if (0 <= nextDegree)
            {
                firstPolynomial[nextDegree] = 1.0;
                degree = nextDegree;
            }
            else
            {
                testResult = false;
                break;
            }
        }

        ASSERT_EQUAL(result, testResult);
    }
}

void Mathematics::PolynomialRootsTesting::AllRealPartsPositiveTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e6, 1.0e6);
    const uniform_int<> secondRandomDistribution(2, 8);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        PolynomialRootsD firstPolynomialRoots(1e-6);

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);

        vector<double> tuple;
        auto size = secondRandomDistribution(generator);

        for (auto i = 0; i < size; ++i)
        {
            tuple.push_back(firstRandomDistribution(generator));
        }

        PolynomialD firstPolynomial(tuple);

        const auto result = firstPolynomialRoots.AllRealPartsPositive(firstPolynomial);

        // 使多项式首一。
        auto degree = firstPolynomial.GetDegree();
        if (1e-6 < MathD::FAbs(firstPolynomial.GetEnd() - 1.0))
        {
            for (auto i = 0; i < degree; ++i)
            {
                firstPolynomial[i] /= firstPolynomial.GetEnd();
            }

            firstPolynomial[degree] = 1.0;
        }

        auto sign = -1;
        for (auto i = degree - 1; 0 <= i; --i)
        {
            firstPolynomial[i] *= sign;
            sign = -sign;
        }

        auto testResult = true;
        while (1 <= degree)
        {
            if (firstPolynomial[degree - 1] <= 0.0)
            {
                testResult = false;
                break;
            }

            if (degree == 1)
            {
                testResult = true;
                break;
            }

            vector<double> tmpCoeff(degree);
            tmpCoeff.at(0) = 2.0 * firstPolynomial[0] * firstPolynomial[degree - 1];

            for (auto i = 1; i <= degree - 2; ++i)
            {
                tmpCoeff.at(i) = firstPolynomial[degree - 1] * firstPolynomial[i];
                if (((degree - i) % 2) == 0)
                {
                    tmpCoeff.at(i) -= firstPolynomial[i - 1];
                }
                tmpCoeff.at(i) *= 2.0;
            }
            const auto temp = degree - 1;
            tmpCoeff.at(temp) = 2.0 * firstPolynomial[temp] * firstPolynomial[temp];

            auto nextDegree = 0;
            for (nextDegree = degree - 1; 0 <= nextDegree; --nextDegree)
            {
                if (1e-6 < MathD::FAbs(tmpCoeff.at(nextDegree)))
                {
                    break;
                }
            }
            for (auto i = 0; i <= nextDegree - 1; ++i)
            {
                firstPolynomial[i] = tmpCoeff.at(i) / tmpCoeff.at(nextDegree);
            }

            if (0 <= nextDegree)
            {
                firstPolynomial[nextDegree] = 1.0;
                degree = nextDegree;
            }
            else
            {
                testResult = false;
                break;
            }
        }

        ASSERT_EQUAL(result, testResult);
    }
}

void Mathematics::PolynomialRootsTesting::GetRootCountTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e6, 1.0e6);
    const uniform_int<> secondRandomDistribution(2, 8);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        PolynomialRootsD firstPolynomialRoots(1e-6);

        ASSERT_EQUAL(firstPolynomialRoots.GetCount(), 0);

        vector<double> tuple;
        auto size = secondRandomDistribution(generator);

        for (auto m = 0; m < size; ++m)
        {
            tuple.push_back(firstRandomDistribution(generator));
        }

        PolynomialD firstPolynomial(tuple);

        MAYBE_UNUSED const auto value = firstPolynomialRoots.FindBisection(firstPolynomial, 20);
        MAYBE_UNUSED auto bound = firstPolynomialRoots.GetBound(firstPolynomial);
    }
}
