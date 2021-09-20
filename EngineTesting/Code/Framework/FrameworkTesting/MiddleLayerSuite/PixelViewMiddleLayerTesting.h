// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.1.0 (2020/06/27 10:00)

#ifndef FRAMEWORK_MIDDLE_LAYER_SUITE_PIXEL_VIEW_MIDDLE_LAYER_TESTING_H
#define FRAMEWORK_MIDDLE_LAYER_SUITE_PIXEL_VIEW_MIDDLE_LAYER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h" 
#include "Framework/MiddleLayer/PixelViewMiddleLayer.h"

#include <gsl/gsl_util>
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
		void DoRunUnitTest() final;

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
		TestingType CreateTestPixelViewMiddleLayer();
		TestingType CreateTestPixelViewMiddleLayer(int width, int height);
		void AssertColourOnX(const TestingType& pixelScreen, const Colour& colour, int xBegin, int xEnd);
		void AssertColourOnY(const TestingType& pixelScreen, const Colour& colour, int yBegin, int yEnd);
		Colour GetRandomColour(std::default_random_engine& generator);

		int GetSeparateRadius(int radius) const noexcept;

	private:
		static constexpr auto sm_MinColour = gsl::narrow_cast<uint8_t>(Rendering::ColourDefaultTraits<uint8_t>::sm_MinValue);
		static constexpr auto sm_MaxColour = gsl::narrow_cast<uint8_t>(Rendering::ColourDefaultTraits<uint8_t>::sm_MaxValue);
		static constexpr Colour sm_Black{ };

		std::uniform_int<uint8_t> m_Random;
	};
}

#endif // FRAMEWORK_MIDDLE_LAYER_SUITE_PIXEL_VIEW_MIDDLE_LAYER_TESTING_H