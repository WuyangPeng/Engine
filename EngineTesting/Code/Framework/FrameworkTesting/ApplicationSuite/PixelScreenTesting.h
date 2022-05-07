// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/19 22:00)

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
        TestingType CreateTestPixelScreen();
        TestingType CreateTestPixelScreen(int width, int height);
        void AssertColourOnX(const TestingType& pixelScreen, const Colour& colour, int xBegin, int xEnd);
        void AssertColourOnY(const TestingType& pixelScreen, const Colour& colour, int yBegin, int yEnd);
        Colour GetRandomColour(std::default_random_engine& generator);

        int GetSeparateRadius(int radius) const noexcept;

    private:
        static constexpr auto minColour = gsl::narrow_cast<uint8_t>(Rendering::ColourDefaultTraits<uint8_t>::minValue);
        static constexpr auto maxColour = gsl::narrow_cast<uint8_t>(Rendering::ColourDefaultTraits<uint8_t>::maxValue);
        static constexpr Colour sm_Black{};

        std::uniform_int<uint8_t> m_Random;
    };
}

#endif  // FRAMEWORK_APPLICATION_SUITE_PIXEL_SCREEN_TESTING_H