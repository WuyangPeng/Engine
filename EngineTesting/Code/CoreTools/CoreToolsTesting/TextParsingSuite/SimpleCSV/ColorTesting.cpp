///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/04 21:03)

#include "ColorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Color.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;
using std::make_shared;

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
    ASSERT_NOT_THROW_EXCEPTION_0(RGBColorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RGBAColorTest);
}

void CoreTools::ColorTesting::DefaultColorTest()
{
    const SimpleCSV::Color color0{};

    ASSERT_EQUAL(color0.GetAlpha(), 255);
    ASSERT_EQUAL(color0.GetRed(), 0);
    ASSERT_EQUAL(color0.GetGreen(), 0);
    ASSERT_EQUAL(color0.GetBlue(), 0);

    auto hex = color0.GetHex();

    const SimpleCSV::Color color1{ hex };

    ASSERT_EQUAL(color0.GetAlpha(), color1.GetAlpha());
    ASSERT_EQUAL(color0.GetRed(), color1.GetRed());
    ASSERT_EQUAL(color0.GetGreen(), color1.GetGreen());
    ASSERT_EQUAL(color0.GetBlue(), color1.GetBlue());
}

void CoreTools::ColorTesting::RGBColorTest()
{
    const SimpleCSV::Color color0{ 20, 30, 40 };

    ASSERT_EQUAL(color0.GetAlpha(), 255);
    ASSERT_EQUAL(color0.GetRed(), 20);
    ASSERT_EQUAL(color0.GetGreen(), 30);
    ASSERT_EQUAL(color0.GetBlue(), 40);

    auto hex = color0.GetHex();

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

void CoreTools::ColorTesting::RGBAColorTest()
{
    const SimpleCSV::Color color0{ 10, 20, 30, 40 };

    ASSERT_EQUAL(color0.GetAlpha(), 10);
    ASSERT_EQUAL(color0.GetRed(), 20);
    ASSERT_EQUAL(color0.GetGreen(), 30);
    ASSERT_EQUAL(color0.GetBlue(), 40);

    auto hex = color0.GetHex();

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
