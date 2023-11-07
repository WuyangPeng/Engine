///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 19:34)

#include "WindowSizeTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Framework/WindowCreate/WindowSize.h"

#include <random>

Framework::WindowSizeTesting::WindowSizeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowSizeTesting)

void Framework::WindowSizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(RandomTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LParamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EqualTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetWindowSizeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OStreamTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NegativeTest);
}

void Framework::WindowSizeTesting::DefaultTest()
{
    const WindowSize size{};

    ASSERT_EQUAL(0, size.GetWindowWidth());
    ASSERT_EQUAL(0, size.GetWindowHeight());
}

void Framework::WindowSizeTesting::RandomTest()
{
    constexpr auto minValue = 0;
    constexpr auto maxValue = 2048;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        const auto width = random(generator);
        const auto height = random(generator);

        const WindowSize size{ width, height };

        ASSERT_EQUAL(width, size.GetWindowWidth());
        ASSERT_EQUAL(height, size.GetWindowHeight());
    }
}

void Framework::WindowSizeTesting::LParamTest()
{
    constexpr auto minValue = 0;
    constexpr auto maxValue = 2048;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        const auto width = random(generator);
        const auto height = random(generator);
        const auto lParam = width + (height << gWordShift);

        const WindowSize size{ lParam };

        ASSERT_EQUAL(width, size.GetWindowWidth());
        ASSERT_EQUAL(height, size.GetWindowHeight());
    }
}

void Framework::WindowSizeTesting::EqualTest()
{
    constexpr auto minValue = 0;
    constexpr auto maxValue = 2048;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        const auto width = random(generator);
        const auto height = random(generator);
        const auto lParam = width + (height << gWordShift);

        const WindowSize size0{ lParam };
        const WindowSize size1{ width, height };

        ASSERT_EQUAL(size0, size1);

        const WindowSize size2{ width, height + 1 };

        ASSERT_UNEQUAL(size0, size2);
    }
}

void Framework::WindowSizeTesting::SetWindowSizeTest()
{
    constexpr auto minValue = 1;
    constexpr auto maxValue = 2048;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        auto width = random(generator);
        auto height = random(generator);

        SetNegative(i, width, height);

        ASSERT_THROW_EXCEPTION_2(SetWindowSizeExceptionTest, width, height);
    }
}

void Framework::WindowSizeTesting::SetWindowSizeExceptionTest(int width, int height)
{
    WindowSize size{};

    size.SetWindowSize(width, height);
}

void Framework::WindowSizeTesting::OStreamTest()
{
    constexpr auto minValue = 0;
    constexpr auto maxValue = 2048;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        const auto width = random(generator);
        const auto height = random(generator);

        const WindowSize size{ width, height };

        GetStream() << size << '\n';
    }
}

void Framework::WindowSizeTesting::NegativeTest()
{
    constexpr auto minValue = 1;
    constexpr auto maxValue = 2048;

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_int<> random{ minValue, maxValue };

    for (auto i = 0; i < GetTestLoopCount(); ++i)
    {
        auto width = random(generator);
        auto height = random(generator);

        SetNegative(i, width, height);

        ASSERT_THROW_EXCEPTION_2(WindowSizeExceptionTest, width, height);
    }
}

void Framework::WindowSizeTesting::WindowSizeExceptionTest(int width, int height)
{
    const WindowSize size{ width, height };
}

void Framework::WindowSizeTesting::SetNegative(int index, int& width, int& height) noexcept
{
    switch (index % 3)
    {
        case 0:
        {
            width = -width;
        }
        break;
        case 1:
        {
            height = -height;
        }
        break;
        case 2:
        {
            width = -width;
            height = -height;
        }
        break;
        default:
            break;
    }
}
