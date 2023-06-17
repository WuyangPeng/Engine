///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:02)

#include "EquationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/NumericalAnalysis/Equation.h"
#include "Mathematics/NumericalAnalysis/EquationResultConstIteratorDetail.h"

#include <random>

Mathematics::EquationTesting::EquationTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EquationTesting)

void Mathematics::EquationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::EquationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OnceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SecondaryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ThriceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(QuarticTest);
}

void Mathematics::EquationTesting::OnceTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-1.0e10, 1.0e10);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Equation firstEquation(randomDistribution0(generator), randomDistribution0(generator));

        ASSERT_TRUE(firstEquation.IsRealResult());
        ASSERT_EQUAL(firstEquation.GetRealResultCount(), 1);
        ASSERT_EQUAL(firstEquation.GetImaginaryResultCount(), 0);

        ASSERT_EQUAL(firstEquation.GetImaginaryBegin(), firstEquation.GetImaginaryEnd());

        auto iter = firstEquation.GetRealBegin();

        auto result = *iter;

        ASSERT_EQUAL(++iter, firstEquation.GetRealEnd());

        ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-5);
    }
}

void Mathematics::EquationTesting::SecondaryTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-1.0e8, 1.0e8);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Equation firstEquation(randomDistribution0(generator),
                               randomDistribution0(generator),
                               randomDistribution0(generator));

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
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-1.0e7, 1.0e7);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Equation firstEquation(randomDistribution0(generator),
                               randomDistribution0(generator),
                               randomDistribution0(generator),
                               randomDistribution0(generator));

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

                ASSERT_APPROXIMATE(firstEquation.Substitution(result), 0.0, 1e-3);
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
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> randomDistribution0(-1.0e4, 1.0e4);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        Equation firstEquation(randomDistribution0(generator),
                               randomDistribution0(generator),
                               randomDistribution0(generator),
                               randomDistribution0(generator),
                               randomDistribution0(generator));

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
