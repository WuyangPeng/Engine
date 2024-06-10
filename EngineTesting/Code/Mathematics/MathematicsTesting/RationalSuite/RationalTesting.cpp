///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:43)

#include "RationalTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#include <limits>
#include <random>

namespace Mathematics
{
    template class SignRational<5>;
    template class SignRational<7>;
}

Mathematics::RationalTesting::RationalTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, RationalTesting)

void Mathematics::RationalTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::RationalTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EliminatePowersOfTwoTest);
}

void Mathematics::RationalTesting::ConstructionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<uint16_t> randomDistribution0(0, UINT16_MAX);
    std::uniform_real_distribution<float> randomDistribution1(-1.0e38f, 1.0e38f);
    std::uniform_real_distribution<double> thirdRandomDistribution(-1.0e300, 1.0e300);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<uint16_t> firstShortVector(26);
        std::vector<uint16_t> secondShortVector(26);

        for (auto i = 0; i < 26; ++i)
        {
            firstShortVector.at(i) = randomDistribution0(generator);
            secondShortVector.at(i) = randomDistribution0(generator);
        }

        const Integer<13> firstInteger(firstShortVector);

        const SignRational<17> firstRational;

        ASSERT_EQUAL(firstRational.GetNumerator(), Integer<17>(0));
        ASSERT_EQUAL(firstRational.GetDenominator(), Integer<17>(1));

        const SignRational<13> secondRational(firstInteger);

        ASSERT_EQUAL(secondRational.GetNumerator(), firstInteger);
        ASSERT_EQUAL(secondRational.GetDenominator(), Integer<13>(1));

        Integer<13> secondInteger(secondShortVector);

        secondInteger[0] |= gsl::narrow_cast<uint16_t>(1);

        const SignRational<13> thirdRational(firstInteger, secondInteger);

        ASSERT_EQUAL(thirdRational.GetNumerator(), firstInteger);
        ASSERT_EQUAL(thirdRational.GetDenominator(), secondInteger);

        const SignRational<13> fourthRational(firstShortVector.at(0));

        ASSERT_EQUAL(fourthRational.GetNumerator(), Integer<13>(firstShortVector.at(0)));
        ASSERT_EQUAL(fourthRational.GetDenominator(), Integer<13>(1));

        firstShortVector.at(1) |= gsl::narrow_cast<uint16_t>(1);

        const SignRational<13> fifthRational(firstShortVector.at(0), firstShortVector.at(1));

        ASSERT_EQUAL(fifthRational.GetNumerator(), Integer<13>(firstShortVector.at(0)));
        ASSERT_EQUAL(fifthRational.GetDenominator(), Integer<13>(firstShortVector.at(1)));

        const float firstValue = randomDistribution1(generator);

        const SignRational<13> sixthRational(firstValue);

        ASSERT_APPROXIMATE(firstValue, sixthRational.ConvertTo<float>(), 1e-8f);

        auto secondValue = sixthRational.ConvertTo<float>();

        const SignRational<13> seventhRational(secondValue);

        ASSERT_APPROXIMATE(secondValue, seventhRational.ConvertTo<float>(), 1e-8f);

        auto thirdValue = thirdRandomDistribution(generator);

        const SignRational<53> eighthRational(thirdValue);

        ASSERT_APPROXIMATE(thirdValue, eighthRational.ConvertTo<double>(), 1e-10);

        auto fourthValue = eighthRational.ConvertTo<double>();

        const SignRational<53> ninthRational(fourthValue);

        ASSERT_APPROXIMATE(fourthValue, ninthRational.ConvertTo<double>(), 1e-10);
    }
}

void Mathematics::RationalTesting::AccessTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<uint16_t> randomDistribution0(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<uint16_t> firstShortVector(30);
        std::vector<uint16_t> secondShortVector(30);
        std::vector<uint16_t> thirdShortVector(30);

        for (auto i = 0; i < 7; ++i)
        {
            firstShortVector.at(i) = randomDistribution0(generator);
            secondShortVector.at(i) = randomDistribution0(generator);
            thirdShortVector.at(i) = randomDistribution0(generator);
        }

        secondShortVector.at(0) |= gsl::narrow_cast<uint16_t>(1);
        thirdShortVector.at(0) |= gsl::narrow_cast<uint16_t>(1);
        firstShortVector.at(0) |= gsl::narrow_cast<uint16_t>(1);

        const Integer<15> firstInteger(firstShortVector);
        const Integer<15> secondInteger(secondShortVector);
        const Integer<15> thirdInteger(thirdShortVector);

        SignRational<15> firstRational(firstInteger, secondInteger);

        ASSERT_EQUAL(firstInteger, firstRational.GetNumerator());
        ASSERT_EQUAL(secondInteger, firstRational.GetDenominator());

        firstRational.Set(thirdInteger, firstInteger);

        ASSERT_EQUAL(thirdInteger, firstRational.GetNumerator());
        ASSERT_EQUAL(firstInteger, firstRational.GetDenominator());

        if (firstRational < SignRational<15>(0))
        {
            ASSERT_EQUAL(firstRational.Abs(), -firstRational);
        }
        else
        {
            ASSERT_EQUAL(firstRational.Abs(), firstRational);
        }
    }
}

void Mathematics::RationalTesting::OperatorTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<uint16_t> randomDistribution0(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<uint16_t> firstShortVector(30);
        std::vector<uint16_t> secondShortVector(30);
        std::vector<uint16_t> thirdShortVector(30);
        std::vector<uint16_t> fourthShortVector(30);

        for (int i = 0; i < 7; ++i)
        {
            firstShortVector.at(i) = randomDistribution0(generator);
            secondShortVector.at(i) = randomDistribution0(generator);
            thirdShortVector.at(i) = randomDistribution0(generator);
            fourthShortVector.at(i) = randomDistribution0(generator);
        }

        const Integer<15> firstInteger(firstShortVector);
        const Integer<15> secondInteger(secondShortVector);
        const Integer<15> thirdInteger(thirdShortVector);
        const Integer<15> fourthInteger(fourthShortVector);

        const SignRational<15> firstRational(firstInteger, secondInteger);
        const SignRational<15> secondRational(thirdInteger, fourthInteger);

        SignRational<15> thirdRational = firstRational + secondRational;

        SignRational<15> fourthRational(firstInteger * fourthInteger + secondInteger * thirdInteger, secondInteger * fourthInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = -thirdRational;

        fourthRational.Set(-fourthRational.GetNumerator(), fourthRational.GetDenominator());

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = firstRational - secondRational;

        fourthRational.Set(firstInteger * fourthInteger - secondInteger * thirdInteger, secondInteger * fourthInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = firstRational * secondRational;

        fourthRational.Set(firstInteger * thirdInteger, secondInteger * fourthInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = firstRational / secondRational;

        fourthRational.Set(firstInteger * fourthInteger, secondInteger * thirdInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = firstRational + thirdInteger;

        fourthRational.Set(firstInteger + secondInteger * thirdInteger, secondInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = thirdInteger + firstRational;

        fourthRational.Set(firstInteger + secondInteger * thirdInteger, secondInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = firstRational - thirdInteger;

        fourthRational.Set(firstInteger - secondInteger * thirdInteger, secondInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = thirdInteger - firstRational;

        fourthRational.Set(secondInteger * thirdInteger - firstInteger, secondInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = firstRational * thirdInteger;

        fourthRational.Set(firstInteger * thirdInteger, secondInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = thirdInteger * firstRational;

        fourthRational.Set(firstInteger * thirdInteger, secondInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = firstRational / thirdInteger;

        fourthRational.Set(firstInteger, secondInteger * thirdInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);

        thirdRational = thirdInteger / firstRational;

        fourthRational.Set(secondInteger * thirdInteger, firstInteger);

        ASSERT_EQUAL(thirdRational, fourthRational);
    }
}

void Mathematics::RationalTesting::CompareTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<uint16_t> randomDistribution0(0, UINT16_MAX);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<uint16_t> firstShortVector(30);
        std::vector<uint16_t> secondShortVector(30);
        std::vector<uint16_t> thirdShortVector(30);
        std::vector<uint16_t> fourthShortVector(30);

        for (auto i = 0; i < 7; ++i)
        {
            firstShortVector.at(i) = randomDistribution0(generator);
            secondShortVector.at(i) = randomDistribution0(generator);
            thirdShortVector.at(i) = randomDistribution0(generator);
            fourthShortVector.at(i) = randomDistribution0(generator);
        }

        const Integer<15> firstInteger(firstShortVector);
        const Integer<15> secondInteger(secondShortVector);
        const Integer<15> thirdInteger(thirdShortVector);
        const Integer<15> fourthInteger(fourthShortVector);

        const SignRational<15> firstRational(firstInteger, secondInteger);
        const SignRational<15> secondRational(thirdInteger, fourthInteger);

        ASSERT_TRUE(firstRational == firstRational);
        ASSERT_FALSE(firstRational == secondRational);
        ASSERT_FALSE(secondRational != secondRational);
        ASSERT_TRUE(firstRational != secondRational);

        if (firstRational.ConvertTo<double>() < secondRational.ConvertTo<double>())
        {
            ASSERT_TRUE(firstRational < secondRational);
            ASSERT_TRUE(firstRational <= secondRational);
            ASSERT_FALSE(firstRational > secondRational);
            ASSERT_FALSE(firstRational >= secondRational);
        }
        else
        {
            ASSERT_FALSE(firstRational < secondRational);
            ASSERT_FALSE(firstRational <= secondRational);
            ASSERT_TRUE(firstRational > secondRational);
            ASSERT_TRUE(firstRational >= secondRational);
        }
    }
}

void Mathematics::RationalTesting::EliminatePowersOfTwoTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int_distribution<uint16_t> randomDistribution0(0, UINT16_MAX);
    const std::uniform_real_distribution<float> randomDistribution1(-1.0e38f, 1.0e38f);
    const std::uniform_real_distribution<double> thirdRandomDistribution(-1.0e300, 1.0e300);

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        std::vector<uint16_t> firstShortVector(26);
        std::vector<uint16_t> secondShortVector(26);

        for (auto i = 0; i < 26; ++i)
        {
            firstShortVector.at(i) = randomDistribution0(generator);
            secondShortVector.at(i) = randomDistribution0(generator);
        }

        const Integer<13> firstInteger(firstShortVector);
        const Integer<13> secondInteger(secondShortVector);

        SignRational<13> firstRational(firstInteger, secondInteger);

        const SignRational<13> secondRational(firstRational.GetNumerator(), firstRational.GetDenominator());

        ASSERT_EQUAL(firstRational.GetDenominator(), secondRational.GetDenominator());
        ASSERT_EQUAL(firstRational.GetNumerator(), secondRational.GetNumerator());

        firstRational.Set(firstRational.GetDenominator(), firstRational.GetNumerator());

        const SignRational<13> thirdRational(firstRational.GetNumerator(), firstRational.GetDenominator());

        ASSERT_EQUAL(firstRational.GetDenominator(), thirdRational.GetDenominator());
        ASSERT_EQUAL(firstRational.GetNumerator(), thirdRational.GetNumerator());
    }
}
