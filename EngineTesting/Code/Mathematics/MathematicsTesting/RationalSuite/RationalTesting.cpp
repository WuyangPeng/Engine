// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/26 16:53)

#include "RationalTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#include <limits>
#include <random>

using std::default_random_engine;
using std::uniform_int;
using std::uniform_real;
using std::vector;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
namespace Mathematics
{
    template class SignRational<5>;
    template class SignRational<7>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, RationalTesting)

void Mathematics::RationalTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EliminatePowersOfTwoTest);
}

void Mathematics::RationalTesting ::ConstructionTest()
{
    default_random_engine generator{};
    uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);
    uniform_real<float> secondRandomDistribution(-1.0e38f, 1.0e38f);
    uniform_real<double> thirdRandomDistribution(-1.0e300, 1.0e300);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(26);
        vector<uint16_t> secondShortVector(26);

        for (int i = 0; i < 26; ++i)
        {
            firstShortVector[i] = firstRandomDistribution(generator);
            secondShortVector[i] = firstRandomDistribution(generator);
        }

        Integer<13> firstInteger(firstShortVector);

        SignRational<17> firstRational;

        ASSERT_EQUAL(firstRational.GetNumerator(), Integer<17>(0));
        ASSERT_EQUAL(firstRational.GetDenominator(), Integer<17>(1));

        SignRational<13> secondRational(firstInteger);

        ASSERT_EQUAL(secondRational.GetNumerator(), firstInteger);
        ASSERT_EQUAL(secondRational.GetDenominator(), Integer<13>(1));

        Integer<13> secondInteger(secondShortVector);

        secondInteger[0] |= static_cast<uint16_t>(1);

        SignRational<13> thirdRational(firstInteger, secondInteger);

        ASSERT_EQUAL(thirdRational.GetNumerator(), firstInteger);
        ASSERT_EQUAL(thirdRational.GetDenominator(), secondInteger);

        SignRational<13> fourthRational(firstShortVector[0]);

        ASSERT_EQUAL(fourthRational.GetNumerator(), Integer<13>(firstShortVector[0]));
        ASSERT_EQUAL(fourthRational.GetDenominator(), Integer<13>(1));

        firstShortVector[1] |= static_cast<uint16_t>(1);

        SignRational<13> fifthRational(firstShortVector[0], firstShortVector[1]);

        ASSERT_EQUAL(fifthRational.GetNumerator(), Integer<13>(firstShortVector[0]));
        ASSERT_EQUAL(fifthRational.GetDenominator(), Integer<13>(firstShortVector[1]));

        float firstValue = secondRandomDistribution(generator);

        SignRational<13> sixthRational(firstValue);

        ASSERT_APPROXIMATE(firstValue, sixthRational.ConvertTo<float>(), 1e-8f);

        float secondValue = sixthRational.ConvertTo<float>();

        SignRational<13> seventhRational(secondValue);

        ASSERT_APPROXIMATE(secondValue, seventhRational.ConvertTo<float>(), 1e-8f);

        double thirdValue = thirdRandomDistribution(generator);

        SignRational<53> eighthRational(thirdValue);

        ASSERT_APPROXIMATE(thirdValue, eighthRational.ConvertTo<double>(), 1e-10);

        double fourthValue = eighthRational.ConvertTo<double>();

        SignRational<53> ninthRational(fourthValue);

        ASSERT_APPROXIMATE(fourthValue, ninthRational.ConvertTo<double>(), 1e-10);
    }
}

void Mathematics::RationalTesting ::AccessTest()
{
    default_random_engine generator{};
    uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(30);
        vector<uint16_t> secondShortVector(30);
        vector<uint16_t> thirdShortVector(30);

        for (int i = 0; i < 7; ++i)
        {
            firstShortVector[i] = firstRandomDistribution(generator);
            secondShortVector[i] = firstRandomDistribution(generator);
            thirdShortVector[i] = firstRandomDistribution(generator);
        }

        secondShortVector[0] |= static_cast<uint16_t>(1);
        thirdShortVector[0] |= static_cast<uint16_t>(1);
        firstShortVector[0] |= static_cast<uint16_t>(1);

        Integer<15> firstInteger(firstShortVector);
        Integer<15> secondInteger(secondShortVector);
        Integer<15> thirdInteger(thirdShortVector);

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

void Mathematics::RationalTesting ::OperatorTest()
{
    default_random_engine generator{};
    uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(30);
        vector<uint16_t> secondShortVector(30);
        vector<uint16_t> thirdShortVector(30);
        vector<uint16_t> fourthShortVector(30);

        for (int i = 0; i < 7; ++i)
        {
            firstShortVector[i] = firstRandomDistribution(generator);
            secondShortVector[i] = firstRandomDistribution(generator);
            thirdShortVector[i] = firstRandomDistribution(generator);
            fourthShortVector[i] = firstRandomDistribution(generator);
        }

        Integer<15> firstInteger(firstShortVector);
        Integer<15> secondInteger(secondShortVector);
        Integer<15> thirdInteger(thirdShortVector);
        Integer<15> fourthInteger(fourthShortVector);

        SignRational<15> firstRational(firstInteger, secondInteger);
        SignRational<15> secondRational(thirdInteger, fourthInteger);

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

void Mathematics::RationalTesting ::CompareTest()
{
    default_random_engine generator{};
    uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(30);
        vector<uint16_t> secondShortVector(30);
        vector<uint16_t> thirdShortVector(30);
        vector<uint16_t> fourthShortVector(30);

        for (int i = 0; i < 7; ++i)
        {
            firstShortVector[i] = firstRandomDistribution(generator);
            secondShortVector[i] = firstRandomDistribution(generator);
            thirdShortVector[i] = firstRandomDistribution(generator);
            fourthShortVector[i] = firstRandomDistribution(generator);
        }

        Integer<15> firstInteger(firstShortVector);
        Integer<15> secondInteger(secondShortVector);
        Integer<15> thirdInteger(thirdShortVector);
        Integer<15> fourthInteger(fourthShortVector);

        SignRational<15> firstRational(firstInteger, secondInteger);
        SignRational<15> secondRational(thirdInteger, fourthInteger);

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

void Mathematics::RationalTesting ::EliminatePowersOfTwoTest()
{
    default_random_engine generator{};
    uniform_int<uint16_t> firstRandomDistribution(0, UINT16_MAX);
    uniform_real<float> secondRandomDistribution(-1.0e38f, 1.0e38f);
    uniform_real<double> thirdRandomDistribution(-1.0e300, 1.0e300);

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        vector<uint16_t> firstShortVector(26);
        vector<uint16_t> secondShortVector(26);

        for (int i = 0; i < 26; ++i)
        {
            firstShortVector[i] = firstRandomDistribution(generator);
            secondShortVector[i] = firstRandomDistribution(generator);
        }

        Integer<13> firstInteger(firstShortVector);
        Integer<13> secondInteger(secondShortVector);

        SignRational<13> firstRational(firstInteger, secondInteger);

        SignRational<13> secondRational(firstRational.GetNumerator(), firstRational.GetDenominator());

        ASSERT_EQUAL(firstRational.GetDenominator(), secondRational.GetDenominator());
        ASSERT_EQUAL(firstRational.GetNumerator(), secondRational.GetNumerator());

        firstRational.Set(firstRational.GetDenominator(), firstRational.GetNumerator());

        SignRational<13> thirdRational(firstRational.GetNumerator(), firstRational.GetDenominator());

        ASSERT_EQUAL(firstRational.GetDenominator(), thirdRational.GetDenominator());
        ASSERT_EQUAL(firstRational.GetNumerator(), thirdRational.GetNumerator());
    }
}
