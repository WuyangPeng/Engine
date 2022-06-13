///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 17:14)

#include "EquationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Equation.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"

#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, EquationTesting)

void Mathematics::EquationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OnceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SecondaryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ThriceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(QuarticTest);
}

void Mathematics::EquationTesting::OnceTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e10, 1.0e10);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Equation firstEquation(firstRandomDistribution(generator), firstRandomDistribution(generator));

        ASSERT_TRUE(firstEquation.IsRealResult());
        ASSERT_EQUAL(firstEquation.GetRealResultCount(), 1);
        ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 0);

        ASSERT_EQUAL(firstEquation.GetImaginaryBegin(), firstEquation.GetImaginaryEnd());

        auto iter = firstEquation.GetRealBegin();

        auto result = *iter;

        ASSERT_EQUAL(++iter, firstEquation.GetRealEnd());

        ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-6);
    }
}

void Mathematics::EquationTesting::SecondaryTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e8, 1.0e8);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Equation firstEquation(firstRandomDistribution(generator),
                               firstRandomDistribution(generator),
                               firstRandomDistribution(generator));

        if (firstEquation.IsRealResult())
        {
            ASSERT_TRUE(firstEquation.GetRealResultCount() == 1 || firstEquation.GetRealResultCount() == 2);

            ASSERT_EQUAL(firstEquation.GetImaginaryBegin(), firstEquation.GetImaginaryEnd());

            for (auto iter = firstEquation.GetRealBegin(); iter != firstEquation.GetRealEnd(); ++iter)
            {
                auto result = *iter;

                ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-5);
            }
        }
        else
        {
            ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 2);
            ASSERT_EQUAL(firstEquation.GetRealBegin(), firstEquation.GetRealEnd());

            for (auto iter = firstEquation.GetImaginaryBegin();
                 iter != firstEquation.GetImaginaryEnd();
                 ++iter)
            {
                auto result = *iter;
                const auto substitution = firstEquation.Substitution(result);

                ASSERT_APPROXIMATE(substitution.real(), 0.0, 1e-6);
                ASSERT_APPROXIMATE(substitution.imag(), 0.0, 1e-6);
            }
        }
    }
}

void Mathematics::EquationTesting::ThriceTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e7, 1.0e7);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Equation firstEquation(firstRandomDistribution(generator),
                               firstRandomDistribution(generator),
                               firstRandomDistribution(generator),
                               firstRandomDistribution(generator));

        ASSERT_TRUE(firstEquation.IsRealResult());

        ASSERT_TRUE(firstEquation.GetRealResultCount() == 1 ||
                    firstEquation.GetRealResultCount() == 2 ||
                    firstEquation.GetRealResultCount() == 3);

        if (firstEquation.GetRealResultCount() == 3)
        {
            ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 0);
            ASSERT_EQUAL(firstEquation.GetImaginaryBegin(),
                         firstEquation.GetImaginaryEnd());

            for (auto iter = firstEquation.GetRealBegin();
                 iter != firstEquation.GetRealEnd();
                 ++iter)
            {
                auto result = *iter;

                ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-5);
            }
        }
        else if (firstEquation.GetRealResultCount() == 2)
        {
            ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 0);
            ASSERT_EQUAL(firstEquation.GetImaginaryBegin(), firstEquation.GetImaginaryEnd());

            for (auto iter = firstEquation.GetRealBegin();
                 iter != firstEquation.GetRealEnd();
                 ++iter)
            {
                auto result = *iter;

                ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-6);
            }
        }
        else
        {
            for (auto iter = firstEquation.GetRealBegin();
                 iter != firstEquation.GetRealEnd();
                 ++iter)
            {
                auto result = *iter;

                ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-5);
            }

            ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 2);

            for (auto iter = firstEquation.GetImaginaryBegin();
                 iter != firstEquation.GetImaginaryEnd();
                 ++iter)
            {
                auto result = *iter;
                const auto substitution = firstEquation.Substitution(result);

                ASSERT_APPROXIMATE(substitution.real(), 0.0, 1e-6);
                ASSERT_APPROXIMATE(substitution.imag(), 0.0, 1e-6);
            }
        }
    }

    // 构造判别式为零
    constexpr auto constant = 1.0;
    constexpr auto once = 3.0;
    constexpr auto secondary = 3.0001;
    constexpr auto thrice = 1.0;

    Equation firstEquation(constant, once, secondary, thrice);

    ASSERT_TRUE(firstEquation.IsRealResult());

    ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 0);
    ASSERT_EQUAL(firstEquation.GetImaginaryBegin(), firstEquation.GetImaginaryEnd());

    for (auto iter = firstEquation.GetRealBegin();
         iter != firstEquation.GetRealEnd();
         ++iter)
    {
        auto result = *iter;

        ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-5);
    }
}

void Mathematics::EquationTesting::QuarticTest()
{
    default_random_engine generator;
    const uniform_real<double> firstRandomDistribution(-1.0e6, 1.0e6);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Equation firstEquation(firstRandomDistribution(generator),
                               firstRandomDistribution(generator),
                               firstRandomDistribution(generator),
                               firstRandomDistribution(generator),
                               firstRandomDistribution(generator));

        for (auto iter = firstEquation.GetRealBegin();
             iter != firstEquation.GetRealEnd();
             ++iter)
        {
            auto result = *iter;

            ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-2);
        }

        for (auto iter = firstEquation.GetImaginaryBegin();
             iter != firstEquation.GetImaginaryEnd();
             ++iter)
        {
            auto result = *iter;
            const auto substitution = firstEquation.Substitution(result);

            ASSERT_APPROXIMATE(substitution.real(), 0.0, 1e-6);
            ASSERT_APPROXIMATE(substitution.imag(), 0.0, 1e-6);
        }
    }
}
