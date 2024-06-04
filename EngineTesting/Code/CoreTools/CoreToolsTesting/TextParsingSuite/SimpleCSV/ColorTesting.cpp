/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 17:49)

#include "ColorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Color.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ColorTesting::ColorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ColorTesting)

void CoreTools::ColorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ColorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultColorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RgbColorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RgbaColorTest);
}

void CoreTools::ColorTesting::DefaultColorTest()
{
    constexpr SimpleCSV::Color color{};

    ASSERT_EQUAL(color.GetAlpha(), 255);
    ASSERT_EQUAL(color.GetRed(), 0);
    ASSERT_EQUAL(color.GetGreen(), 0);
    ASSERT_EQUAL(color.GetBlue(), 0);

    ASSERT_NOT_THROW_EXCEPTION_1(DefaultColorGetHexTest, color);
}

void CoreTools::ColorTesting::DefaultColorGetHexTest(const Color& color0)
{
    const auto hex = color0.GetHex();

    const SimpleCSV::Color color1{ hex };

    ASSERT_EQUAL(color0.GetAlpha(), color1.GetAlpha());
    ASSERT_EQUAL(color0.GetRed(), color1.GetRed());
    ASSERT_EQUAL(color0.GetGreen(), color1.GetGreen());
    ASSERT_EQUAL(color0.GetBlue(), color1.GetBlue());
}

void CoreTools::ColorTesting::RgbColorTest()
{
    const SimpleCSV::Color color{ 20, 30, 40 };

    ASSERT_EQUAL(color.GetAlpha(), 255);
    ASSERT_EQUAL(color.GetRed(), 20);
    ASSERT_EQUAL(color.GetGreen(), 30);
    ASSERT_EQUAL(color.GetBlue(), 40);

    ASSERT_NOT_THROW_EXCEPTION_1(RgbColorGetHexTest, color);
}

void CoreTools::ColorTesting::RgbColorGetHexTest(const Color& color0)
{
    const auto hex = color0.GetHex();

    SimpleCSV::Color color1{ hex };

    ASSERT_EQUAL(color0.GetAlpha(), color1.GetAlpha());
    ASSERT_EQUAL(color0.GetRed(), color1.GetRed());
    ASSERT_EQUAL(color0.GetGreen(), color1.GetGreen());
    ASSERT_EQUAL(color0.GetBlue(), color1.GetBlue());

    color1.Set(30, 40, 50);

    ASSERT_EQUAL(color1.GetAlpha(), 255);
    ASSERT_EQUAL(color1.GetRed(), 30);
    ASSERT_EQUAL(color1.GetGreen(), 40);
    ASSERT_EQUAL(color1.GetBlue(), 50);
}

void CoreTools::ColorTesting::RgbaColorTest()
{
    const SimpleCSV::Color color{ 10, 20, 30, 40 };

    ASSERT_EQUAL(color.GetAlpha(), 10);
    ASSERT_EQUAL(color.GetRed(), 20);
    ASSERT_EQUAL(color.GetGreen(), 30);
    ASSERT_EQUAL(color.GetBlue(), 40);

    ASSERT_NOT_THROW_EXCEPTION_1(RgbaColorGetHexTest, color);
}

void CoreTools::ColorTesting::RgbaColorGetHexTest(const Color& color0)
{
    const auto hex = color0.GetHex();

    SimpleCSV::Color color1{ hex };

    ASSERT_EQUAL(color0.GetAlpha(), color1.GetAlpha());
    ASSERT_EQUAL(color0.GetRed(), color1.GetRed());
    ASSERT_EQUAL(color0.GetGreen(), color1.GetGreen());
    ASSERT_EQUAL(color0.GetBlue(), color1.GetBlue());

    color1.Set(50, 30, 40, 50);

    ASSERT_EQUAL(color1.GetAlpha(), 50);
    ASSERT_EQUAL(color1.GetRed(), 30);
    ASSERT_EQUAL(color1.GetGreen(), 40);
    ASSERT_EQUAL(color1.GetBlue(), 50);

    color1.Set(hex);

    ASSERT_EQUAL(color0.GetAlpha(), color1.GetAlpha());
    ASSERT_EQUAL(color0.GetRed(), color1.GetRed());
    ASSERT_EQUAL(color0.GetGreen(), color1.GetGreen());
    ASSERT_EQUAL(color0.GetBlue(), color1.GetBlue());
}