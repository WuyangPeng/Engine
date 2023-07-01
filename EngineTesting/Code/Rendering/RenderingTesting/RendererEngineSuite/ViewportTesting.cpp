///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/21 10:20)

#include "ViewportTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Rendering/RendererEngine/Viewport.h"

Rendering::ViewportTesting::ViewportTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, ViewportTesting)

void Rendering::ViewportTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Rendering::ViewportTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(IsInViewportStaticTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IsInViewportTrueTest);
    ASSERT_NOT_THROW_EXCEPTION_0(IsInViewportFalseTest);
}

void Rendering::ViewportTesting::IsInViewportStaticTest() noexcept
{
    constexpr Viewport viewport{ 100, 100, 1024, 768 };

    static_assert(!viewport.IsInViewport(50, 40));
    static_assert(viewport.IsInViewport(510, 140));

    static_assert(viewport.IsInViewport(100, 100));
    static_assert(viewport.IsInViewport(1124, 100));
    static_assert(viewport.IsInViewport(100, 868));
    static_assert(viewport.IsInViewport(1124, 868));

    static_assert(!viewport.IsInViewport(99, 100));
    static_assert(!viewport.IsInViewport(1124, 99));
    static_assert(!viewport.IsInViewport(100, 869));
    static_assert(!viewport.IsInViewport(1125, 868));
}

void Rendering::ViewportTesting::IsInViewportTrueTest()
{
    constexpr auto xPosition = 100;
    constexpr auto yPosition = 100;
    constexpr auto width = 924;
    constexpr auto height = 668;

    constexpr Viewport viewport{ xPosition, yPosition, width, height };

    for (auto x = 0; x < width; ++x)
    {
        for (auto y = 0; y < height; ++y)
        {
            ASSERT_TRUE(viewport.IsInViewport(x + xPosition, y + yPosition));
        }
    }
}

void Rendering::ViewportTesting::IsInViewportFalseTest()
{
    constexpr auto xPosition = 100;
    constexpr auto yPosition = 100;
    constexpr auto width = 924;
    constexpr auto height = 668;

    constexpr auto step = 20;

    constexpr Viewport viewport{ xPosition, yPosition, width, height };

    for (auto x = 0; x < xPosition; x += step)
    {
        for (auto y = 0; y < yPosition + height; y += step)
        {
            ASSERT_FALSE(viewport.IsInViewport(x, y));
        }
    }

    constexpr auto xEnd = 2000;

    for (auto x = xPosition + width + 1; x < xEnd; x += step)
    {
        for (auto y = 0; y < yPosition + height; y += step)
        {
            ASSERT_FALSE(viewport.IsInViewport(x, y));
        }
    }

    for (auto x = 0; x < xPosition + width; x += step)
    {
        for (auto y = 0; y < yPosition; y += step)
        {
            ASSERT_FALSE(viewport.IsInViewport(x, y));
        }

        constexpr auto yEnd = 2000;
        for (auto y = yPosition + height + 1; y < yEnd; y += step)
        {
            ASSERT_FALSE(viewport.IsInViewport(x, y));
        }
    }
}
