///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/27 11:15)

#ifndef FRAMEWORK_APPLICATION_SUITE_PIXEL_SCREEN_TESTING_H
#define FRAMEWORK_APPLICATION_SUITE_PIXEL_SCREEN_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Framework/Application/PixelScreen.h"

#include <gsl/util>
#include <random>

namespace Framework
{
    class PixelScreenTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PixelScreenTesting;
        using ParentType = UnitTest;

    public:
        explicit PixelScreenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using TestingType = PixelScreen;
        using Colour = PixelScreen::Colour;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void DefaultColourTest();
        void ClearScreenTest();
        void ResizeTest();
        void DoFlipTest();
        void SetPixelTest();
        void SetThickPixelTest();
        void DrawLineTest();
        void DrawRectangleSolidTest();
        void DrawRectangleHollowTest();
        void DrawCircleSolidTest();
        void DrawCircleHollowTest();
        void FillThickPixelTest();
        void FillRectangleSolidTest();
        void FillRectangleHollowTest();
        void FillCircleSolidTest();
        void DrawTest();

        void AssertColour(const TestingType& pixelScreen, const Colour& colour);
        void AssertColour(const TestingType& lhs, const TestingType& rhs);
        NODISCARD TestingType CreateTestPixelScreen();
        NODISCARD TestingType CreateTestPixelScreen(int width, int height);
        void AssertColourOnX(const TestingType& pixelScreen, const Colour& colour, int xBegin, int xEnd);
        void AssertColourOnY(const TestingType& pixelScreen, const Colour& colour, int yBegin, int yEnd);
        NODISCARD Colour GetRandomColour(std::default_random_engine& generator);

        NODISCARD int GetSeparateRadius(int radius) const noexcept;

    private:
        static constexpr auto minColour = gsl::narrow_cast<uint8_t>(Rendering::ColourDefaultTraits<uint8_t>::minValue);
        static constexpr auto maxColour = gsl::narrow_cast<uint8_t>(Rendering::ColourDefaultTraits<uint8_t>::maxValue);
        static constexpr Colour black{};

        std::uniform_int<uint8_t> random;
    };
}

#endif  // FRAMEWORK_APPLICATION_SUITE_PIXEL_SCREEN_TESTING_H