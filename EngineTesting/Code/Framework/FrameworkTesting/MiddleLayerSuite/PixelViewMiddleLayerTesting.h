///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/12 15:26)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_PIXEL_VIEW_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_PIXEL_VIEW_MIDDLE_LAYER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Framework/MiddleLayer/PixelViewMiddleLayer.h"

#include <gsl/util>
#include <random>

namespace Framework
{
    class PixelViewMiddleLayerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PixelViewMiddleLayerTesting;
        using ParentType = UnitTest;

    public:
        explicit PixelViewMiddleLayerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using TestingType = PixelViewMiddleLayer;
        using Colour = PixelViewMiddleLayer::Colour;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void MiddleLayerTest();

        void DefaultColourTest();
        void ClearScreenTest();
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

        void AssertColour(const TestingType& pixelScreen, const Colour& colour);
        void AssertColour(const TestingType& lhs, const TestingType& rhs);
        NODISCARD TestingType CreateTestPixelViewMiddleLayer();
        NODISCARD TestingType CreateTestPixelViewMiddleLayer(int width, int height);
        void AssertColourOnX(const TestingType& pixelScreen, const Colour& colour, int xBegin, int xEnd);
        void AssertColourOnY(const TestingType& pixelScreen, const Colour& colour, int yBegin, int yEnd);
        NODISCARD Colour GetRandomColour(std::default_random_engine& generator);

        NODISCARD int GetSeparateRadius(int radius) const noexcept;

    private:
        static constexpr auto minColour = gsl::narrow_cast<uint8_t>(Rendering::ColourDefaultTraits<uint8_t>::minValue);
        static constexpr auto maxColour = gsl::narrow_cast<uint8_t>(Rendering::ColourDefaultTraits<uint8_t>::maxValue);
        static constexpr Colour black{};

        std::uniform_int_distribution<uint16_t> random;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_SUITE_PIXEL_VIEW_MIDDLE_LAYER_TESTING_H