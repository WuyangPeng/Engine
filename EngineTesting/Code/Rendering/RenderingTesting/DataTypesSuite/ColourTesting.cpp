///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:57)

#include "ColourTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/DataTypes/ColourDetail.h"

Rendering::ColourTesting::ColourTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ColourTesting)

void Rendering::ColourTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ColourTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UInt32Test);
    ASSERT_NOT_THROW_EXCEPTION_0(FloatTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ConvertingTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorTest);
}

void Rendering::ColourTesting::UInt32Test()
{
    Colour<unsigned> firstColour;

    ASSERT_EQUAL(firstColour.GetRed(), 0u);
    ASSERT_EQUAL(firstColour.GetGreen(), 0u);
    ASSERT_EQUAL(firstColour.GetBlue(), 0u);
    ASSERT_EQUAL(firstColour.GetAlpha(), 255u);

    Colour<unsigned> secondColour(30, 257, 51, 55);

    ASSERT_EQUAL(secondColour.GetRed(), 30u);
    ASSERT_EQUAL(secondColour.GetGreen(), 255u);
    ASSERT_EQUAL(secondColour.GetBlue(), 51u);
    ASSERT_EQUAL(secondColour.GetAlpha(), 55u);

    const auto ptr = secondColour.GetPoint();

    secondColour.SetRed(66);
    secondColour.SetGreen(166);
    secondColour.SetBlue(22);
    secondColour.SetAlpha(266);

    ASSERT_EQUAL(secondColour.GetRed(), 66u);
    ASSERT_EQUAL(secondColour.GetGreen(), 166u);
    ASSERT_EQUAL(secondColour.GetBlue(), 22u);
    ASSERT_EQUAL(secondColour.GetAlpha(), 255u);

    ASSERT_EQUAL(ptr.at(0), 30u);
    ASSERT_EQUAL(ptr.at(1), 255u);
    ASSERT_EQUAL(ptr.at(2), 51u);
    ASSERT_EQUAL(ptr.at(3), 55u);

    firstColour.SetColour(6, 99, 66, 333);

    ASSERT_EQUAL(firstColour.GetRed(), 6u);
    ASSERT_EQUAL(firstColour.GetGreen(), 99u);
    ASSERT_EQUAL(firstColour.GetBlue(), 66u);
    ASSERT_EQUAL(firstColour.GetAlpha(), 255u);

    secondColour = firstColour;

    ASSERT_EQUAL(secondColour.GetRed(), 6u);
    ASSERT_EQUAL(secondColour.GetGreen(), 99u);
    ASSERT_EQUAL(secondColour.GetBlue(), 66u);
    ASSERT_EQUAL(secondColour.GetAlpha(), 255u);

    secondColour.SetRed(66u);

    ASSERT_EQUAL(secondColour.GetRed(), 66u);
    ASSERT_EQUAL(firstColour.GetRed(), 6u);

    const Colour<unsigned> thirdColour(firstColour);

    ASSERT_EQUAL(thirdColour.GetRed(), 6u);
    ASSERT_EQUAL(thirdColour.GetGreen(), 99u);
    ASSERT_EQUAL(thirdColour.GetBlue(), 66u);
    ASSERT_EQUAL(thirdColour.GetAlpha(), 255u);

    firstColour.SetGreen(68);

    ASSERT_EQUAL(thirdColour.GetGreen(), 99u);
    ASSERT_EQUAL(firstColour.GetGreen(), 68u);
}

void Rendering::ColourTesting::FloatTest()
{
    Colour<float> firstColour;

    ASSERT_APPROXIMATE(firstColour.GetRed(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstColour.GetGreen(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstColour.GetBlue(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstColour.GetAlpha(), 1.0f, 1e-8f);

    Colour<float> secondColour(0.2f, 0.5f, 1.1f, -0.1f);

    ASSERT_APPROXIMATE(secondColour.GetRed(), 0.2f, 1e-8f);
    ASSERT_APPROXIMATE(secondColour.GetGreen(), 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(secondColour.GetBlue(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondColour.GetAlpha(), 0.0f, 1e-8f);

    const auto ptr = secondColour.GetPoint();

    secondColour.SetRed(0.02f);
    secondColour.SetGreen(0.12f);
    secondColour.SetBlue(0.58f);
    secondColour.SetAlpha(1.01f);

    ASSERT_APPROXIMATE(secondColour.GetRed(), 0.02f, 1e-8f);
    ASSERT_APPROXIMATE(secondColour.GetGreen(), 0.12f, 1e-8f);
    ASSERT_APPROXIMATE(secondColour.GetBlue(), 0.58f, 1e-8f);
    ASSERT_APPROXIMATE(secondColour.GetAlpha(), 1.0f, 1e-8f);

    ASSERT_APPROXIMATE(ptr.at(0), 0.2f, 1e-8f);
    ASSERT_APPROXIMATE(ptr.at(1), 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(ptr.at(2), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(ptr.at(3), 0.0f, 1e-8f);

    firstColour.SetColour(0.12f, 0.25f, 0.1f, -0.12f);

    ASSERT_APPROXIMATE(firstColour.GetRed(), 0.12f, 1e-8f);
    ASSERT_APPROXIMATE(firstColour.GetGreen(), 0.25f, 1e-8f);
    ASSERT_APPROXIMATE(firstColour.GetBlue(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(firstColour.GetAlpha(), 0.0f, 1e-8f);

    secondColour = firstColour;

    ASSERT_APPROXIMATE(secondColour.GetRed(), 0.12f, 1e-8f);
    ASSERT_APPROXIMATE(secondColour.GetGreen(), 0.25f, 1e-8f);
    ASSERT_APPROXIMATE(secondColour.GetBlue(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondColour.GetAlpha(), 0.0f, 1e-8f);

    secondColour.SetBlue(0.2f);

    ASSERT_APPROXIMATE(secondColour.GetBlue(), 0.2f, 1e-8f);
    ASSERT_APPROXIMATE(firstColour.GetBlue(), 0.1f, 1e-8f);

    const Colour<float> thirdColour(firstColour);

    ASSERT_APPROXIMATE(thirdColour.GetRed(), 0.12f, 1e-8f);
    ASSERT_APPROXIMATE(thirdColour.GetGreen(), 0.25f, 1e-8f);
    ASSERT_APPROXIMATE(thirdColour.GetBlue(), 0.1f, 1e-8f);
    ASSERT_APPROXIMATE(thirdColour.GetAlpha(), 0.0f, 1e-8f);

    firstColour.SetAlpha(1.0f);

    ASSERT_APPROXIMATE(thirdColour.GetAlpha(), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstColour.GetAlpha(), 1.0f, 1e-8f);
}

void Rendering::ColourTesting::ConvertingTest() noexcept
{
}

void Rendering::ColourTesting::OperatorTest()
{
    const Colour<unsigned> firstColour(30, 57, 51, 55);
    const Colour<unsigned> secondColour(32, 151, 61, 85);

    Colour<unsigned> thirdColour = firstColour + secondColour;

    ASSERT_EQUAL(thirdColour.GetRed(), 62u);
    ASSERT_EQUAL(thirdColour.GetGreen(), 208u);
    ASSERT_EQUAL(thirdColour.GetBlue(), 112u);
    ASSERT_EQUAL(thirdColour.GetAlpha(), 140u);

    thirdColour = secondColour - firstColour;

    ASSERT_EQUAL(thirdColour.GetRed(), 2u);
    ASSERT_EQUAL(thirdColour.GetGreen(), 94u);
    ASSERT_EQUAL(thirdColour.GetBlue(), 10u);
    ASSERT_EQUAL(thirdColour.GetAlpha(), 30u);

    thirdColour = thirdColour * 2;

    ASSERT_EQUAL(thirdColour.GetRed(), 4u);
    ASSERT_EQUAL(thirdColour.GetGreen(), 188u);
    ASSERT_EQUAL(thirdColour.GetBlue(), 20u);
    ASSERT_EQUAL(thirdColour.GetAlpha(), 60u);

    thirdColour = 2 * thirdColour;

    ASSERT_EQUAL(thirdColour.GetRed(), 8u);
    ASSERT_EQUAL(thirdColour.GetGreen(), 255u);
    ASSERT_EQUAL(thirdColour.GetBlue(), 40u);
    ASSERT_EQUAL(thirdColour.GetAlpha(), 120u);

    thirdColour = thirdColour / 8;

    ASSERT_EQUAL(thirdColour.GetRed(), 1u);
    ASSERT_EQUAL(thirdColour.GetGreen(), 31u);
    ASSERT_EQUAL(thirdColour.GetBlue(), 5u);
    ASSERT_EQUAL(thirdColour.GetAlpha(), 15u);

    thirdColour = firstColour * secondColour;

    ASSERT_EQUAL(thirdColour.GetRed(), 30u * 32u / 255u);
    ASSERT_EQUAL(thirdColour.GetGreen(), 57u * 151u / 255u);
    ASSERT_EQUAL(thirdColour.GetBlue(), 51u * 61u / 255u);
    ASSERT_EQUAL(thirdColour.GetAlpha(), 55u * 85u / 255u);

    Colour<float> fourthColour(0.2f, 0.15f, 1.0f, 0.1f);
    const Colour<float> fifthColour(0.12f, 0.25f, 0.01f, 0.2f);

    fourthColour += fifthColour;

    ASSERT_APPROXIMATE(fourthColour.GetRed(), 0.32f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetGreen(), 0.4f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetBlue(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetAlpha(), 0.3f, 1e-8f);

    fourthColour -= fifthColour;

    ASSERT_APPROXIMATE(fourthColour.GetRed(), 0.2f, 1e-7f);
    ASSERT_APPROXIMATE(fourthColour.GetGreen(), 0.15f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetBlue(), 0.99f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetAlpha(), 0.1f, 1e-8f);

    fourthColour *= 2.0f;

    ASSERT_APPROXIMATE(fourthColour.GetRed(), 0.4f, 1e-7f);
    ASSERT_APPROXIMATE(fourthColour.GetGreen(), 0.3f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetBlue(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetAlpha(), 0.2f, 1e-7f);

    fourthColour /= 2.0f;

    ASSERT_APPROXIMATE(fourthColour.GetRed(), 0.2f, 1e-7f);
    ASSERT_APPROXIMATE(fourthColour.GetGreen(), 0.15f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetBlue(), 0.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetAlpha(), 0.1f, 1e-8f);

    fourthColour *= fifthColour;

    ASSERT_APPROXIMATE(fourthColour.GetRed(), 0.2f * 0.12f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetGreen(), 0.15f * 0.25f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetBlue(), 0.5f * 0.01f, 1e-8f);
    ASSERT_APPROXIMATE(fourthColour.GetAlpha(), 0.1f * 0.2f, 1e-8f);
}
