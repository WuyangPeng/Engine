///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 19:34)

#include "WindowPointTesting.h"
#include "System/Windows/Flags/WindowsFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowCreate/WindowPoint.h"

#include <random>

Framework::WindowPointTesting::WindowPointTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowPointTesting)

void Framework::WindowPointTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowPointTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RandomTest);
    ASSERT_NOT_THROW_EXCEPTION_0(WindowPointUseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EqualTest);
}

void Framework::WindowPointTesting::DefaultTest() noexcept
{
    constexpr WindowPoint windowPoint{};

    static_assert(0 == windowPoint.GetWindowX());
    static_assert(0 == windowPoint.GetWindowY());
}

void Framework::WindowPointTesting::RandomTest()
{
    constexpr auto minValue = 0;
    constexpr auto maxValue = 2048;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        const auto x = random(generator);
        const auto y = random(generator);

        const WindowPoint point0{ x, y };

        ASSERT_EQUAL(x, point0.GetWindowX());
        ASSERT_EQUAL(y, point0.GetWindowY());

        const WindowPoint::WindowsPoint point1{ x, y };

        const WindowPoint point2{ point1 };

        ASSERT_EQUAL(x, point2.GetWindowX());
        ASSERT_EQUAL(y, point2.GetWindowY());
    }
}

void Framework::WindowPointTesting::WindowPointUseTest() noexcept
{
    constexpr WindowPoint windowPoint{ System::WindowsPointUse::Default };

    static_assert(System::EnumCastUnderlying(System::WindowsPointUse::Default) == windowPoint.GetWindowX());
    static_assert(System::EnumCastUnderlying(System::WindowsPointUse::Default) == windowPoint.GetWindowY());
}

void Framework::WindowPointTesting::LParamTest()
{
    constexpr auto minValue = 0;
    constexpr auto maxValue = 2048;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        const auto x = random(generator);
        const auto y = random(generator);

        const auto lParam = x + (y << gWordShift);

        const WindowPoint windowPoint{ lParam };

        ASSERT_EQUAL(x, windowPoint.GetWindowX());
        ASSERT_EQUAL(y, windowPoint.GetWindowY());
    }
}

void Framework::WindowPointTesting::EqualTest()
{
    constexpr auto minValue = 0;
    constexpr auto maxValue = 2048;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random(minValue, maxValue);

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        const int x = random(generator);
        const int y = random(generator);

        const WindowPoint lhsPoint{ x, y };
        WindowPoint rhsPoint{};

        ASSERT_UNEQUAL(lhsPoint, rhsPoint);
        ASSERT_EQUAL(lhsPoint, lhsPoint);
        ASSERT_EQUAL(rhsPoint, rhsPoint);

        rhsPoint.SetWindowPoint(x, y);

        ASSERT_EQUAL(lhsPoint, rhsPoint);
    }
}

void Framework::WindowPointTesting::OStreamTest()
{
    constexpr auto minValue = 0;
    constexpr auto maxValue = 2048;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        const int x = random(generator);
        const int y = random(generator);

        const WindowPoint point{ x, y };

        GetStream() << point << '\n';
    }
}

namespace Framework
{
    constexpr WindowPoint GetWindowPointSum(const WindowPoint& lhs, const WindowPoint& rhs)
    {
        WindowPoint sum{};

        sum.SetWindowPoint(lhs.GetWindowX() + rhs.GetWindowX(), lhs.GetWindowY() + rhs.GetWindowY());

        return sum;
    }
}

void Framework::WindowPointTesting::ConstexprTest() noexcept
{
    constexpr auto x = 1;
    constexpr auto y = 2;
    constexpr auto lParam = x + (y << gWordShift);

    constexpr WindowPoint windowPoint0{ x, y };

    static_assert(x == windowPoint0.GetWindowX());
    static_assert(y == windowPoint0.GetWindowY());

    constexpr WindowPoint windowPoint1{ lParam };

    static_assert(x == windowPoint1.GetWindowX());
    static_assert(y == windowPoint1.GetWindowY());

    constexpr WindowPoint::WindowsPoint point{ x, y };

    constexpr WindowPoint windowPoint2{ point };

    static_assert(x == windowPoint2.GetWindowX());
    static_assert(y == windowPoint2.GetWindowY());

    constexpr auto windowPoint3 = GetWindowPointSum(windowPoint0, windowPoint1);

    static_assert(x + x == windowPoint3.GetWindowX());
    static_assert(y + y == windowPoint3.GetWindowY());
}
