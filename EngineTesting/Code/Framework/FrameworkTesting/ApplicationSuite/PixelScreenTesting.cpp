// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.3.0.2 (2020/06/24 21:04)

#include "PixelScreenTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Rendering/Renderers/Renderer.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Framework/WindowCreate/WindowSize.h"
#include "Mathematics/Algebra/Vector2DTools.h"

using std::swap;
using std::make_shared;
using std::uniform_int;
using std::default_random_engine;

Framework::PixelScreenTesting
	::PixelScreenTesting(const OStreamShared& stream)
	:ParentType{ stream }, m_Random{ sm_MinColour ,sm_MaxColour }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, PixelScreenTesting)

void Framework::PixelScreenTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::PixelScreenTesting
	::MainTest()
{
	Rendering::RendererManager::Create();

	ASSERT_NOT_THROW_EXCEPTION_0(DefaultColourTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ClearScreenTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ResizeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DoFlipTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetPixelTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetThickPixelTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DrawLineTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DrawRectangleSolidTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DrawRectangleHollowTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DrawCircleSolidTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DrawCircleHollowTest); 
	ASSERT_NOT_THROW_EXCEPTION_0(FillThickPixelTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FillRectangleSolidTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FillRectangleHollowTest);
	ASSERT_NOT_THROW_EXCEPTION_0(FillCircleSolidTest);
	ASSERT_NOT_THROW_EXCEPTION_0(DrawTest);

	Rendering::RendererManager::Destroy();
}

void Framework::PixelScreenTesting
	::DefaultColourTest()
{
	auto pixelScreen = CreateTestPixelScreen();

	AssertColour(pixelScreen, sm_Black);
}

void Framework::PixelScreenTesting
	::ClearScreenTest()
{
	default_random_engine generator{ GetEngineRandomSeed() };

	auto pixelScreen = CreateTestPixelScreen();
	
	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{		 
		const auto clearColour = GetRandomColour(generator);

		pixelScreen.ClearScreen(clearColour);

		AssertColour(pixelScreen, clearColour);
	}
}

Framework::PixelScreenTesting::Colour Framework::PixelScreenTesting
	::GetRandomColour(default_random_engine& generator)
{
	const auto red = m_Random(generator);
	const auto green = m_Random(generator);
	const auto blue = m_Random(generator);

	return Colour{ red, green, blue };
}

void Framework::PixelScreenTesting
	::ResizeTest()
{	 
	constexpr auto minSize = 1;
	constexpr auto maxSize = 256;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };
	const uniform_int<> sizeRandom{ minSize, maxSize };

	auto pixelScreen = CreateTestPixelScreen();

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		const auto newWidth = sizeRandom(generator);
		const auto newHeight = sizeRandom(generator);

		const WindowSize newWindowSize{ newWidth, newHeight };

		pixelScreen.Resize(newWindowSize,clearColour);
		ASSERT_EQUAL(pixelScreen.GetScreenWidth(), newWidth);
		ASSERT_EQUAL(pixelScreen.GetScreenHeight(), newHeight);

		AssertColour(pixelScreen, clearColour);
	}
}

void Framework::PixelScreenTesting
	::DoFlipTest()
{
	auto pixelScreen = CreateTestPixelScreen();

	ASSERT_FALSE(pixelScreen.IsDoFlip());

	pixelScreen.DoFlip(true);

	ASSERT_TRUE(pixelScreen.IsDoFlip());

	pixelScreen.DoFlip(false);

	ASSERT_FALSE(pixelScreen.IsDoFlip());
}

void Framework::PixelScreenTesting
	::SetPixelTest()
{ 
	constexpr auto minSize = 0;
	constexpr auto maxSize = 256;	 

	default_random_engine generator{ GetEngineRandomSeed() }; 
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1;

	auto pixelScreen = CreateTestPixelScreen(width, height);

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		const auto x = sizeRandom(generator);
		const auto y = sizeRandom(generator);	 

		pixelScreen.SetPixel(x,y, clearColour);
 
		const auto colour = pixelScreen.GetPixel(x, y);

		ASSERT_EQUAL(colour, clearColour); 
	}
}

void Framework::PixelScreenTesting
	::SetThickPixelTest()
{
	constexpr auto minSize = 0;
	constexpr auto maxSize = 128;	 
	constexpr auto minThick = 2;
	constexpr auto maxThick = 10;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<> thickRandom{ minThick, maxThick };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1; 

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		const auto thick = thickRandom(generator); 

		const auto x = sizeRandom(generator);
		const auto y = sizeRandom(generator);

		auto pixelScreen = CreateTestPixelScreen(width, height);

		pixelScreen.SetThickPixel(x, y, thick, clearColour);

		for (auto widthIndex = 0; widthIndex < width; ++widthIndex)
		{
			for (auto heightIndex = 0; heightIndex < height; ++heightIndex)
			{
				const auto colour = pixelScreen.GetPixel(widthIndex, heightIndex);

				if (x - thick <= widthIndex && widthIndex <= x + thick &&
					y - thick <= heightIndex && heightIndex <= y + thick)
				{
					ASSERT_EQUAL(colour, clearColour);
				}
				else
				{
					ASSERT_EQUAL(colour, sm_Black);
				}
			}
		}		 
	}	 
}

void Framework::PixelScreenTesting
	::DrawLineTest()
{
	constexpr auto minSize = 0;
	constexpr auto maxSize = 128;
	
	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1; 		

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		const auto xMin = sizeRandom(generator);
		const auto yMin = sizeRandom(generator);
		const auto xMax = sizeRandom(generator);
		const auto yMax = sizeRandom(generator);

		auto pixelScreen = CreateTestPixelScreen(width, height); 
	
		pixelScreen.DrawLine(xMin, yMin, xMax, yMax, clearColour);

		const auto xDifference = boost::numeric_cast<double>(xMin - xMax);
		const auto yDifference = boost::numeric_cast<double>(yMin - yMax);

		auto distanceX = Mathematics::DoubleMath::FAbs(xDifference);
                auto distanceY = Mathematics::DoubleMath::FAbs(yDifference);

		if (distanceY < distanceX)
		{
			auto slope = distanceY / distanceX;

			auto min = xMin < xMax ? xMin : xMax;
			auto max = xMin < xMax ? xMax : xMin;

			AssertColourOnX(pixelScreen, sm_Black, 0, min); 
			AssertColourOnX(pixelScreen, sm_Black, max + 1, pixelScreen.GetScreenWidth());
			
			for (int widthIndex = min; widthIndex <= max && widthIndex < pixelScreen.GetScreenWidth(); ++widthIndex)
			{
				constexpr auto deviation = 0.5;
				const auto difference = widthIndex - xMin;	
				auto step = Mathematics::DoubleMath::Floor(Mathematics::DoubleMath::FAbs(difference * slope) + deviation);
				if (yMax < yMin)
				{
					step = -step;
				}
				 
				const auto y = yMin + boost::numeric_cast<int>(step);

				for (int heightIndex = 0; heightIndex < pixelScreen.GetScreenHeight(); ++heightIndex)
				{
					const auto colour = pixelScreen.GetPixel(widthIndex, heightIndex);					

					if (heightIndex == y)
					{
						ASSERT_EQUAL(colour, clearColour);
					}
					else
					{	
						ASSERT_EQUAL(colour, sm_Black);
					}
				}
			} 
		}
		else
		{
			auto slope = distanceX / distanceY;

			auto min = yMin < yMax ? yMin : yMax;
			auto max = yMin < yMax ? yMax : yMin;

			AssertColourOnY(pixelScreen, sm_Black, 0, min);
			AssertColourOnY(pixelScreen, sm_Black, max + 1, pixelScreen.GetScreenHeight());			 

			for (int heightIndex = min; heightIndex <= max && heightIndex < pixelScreen.GetScreenHeight(); ++heightIndex)
			{
				constexpr auto deviation = 0.5;
				const auto difference = heightIndex - yMin;
				auto step = Mathematics::DoubleMath::Floor(Mathematics::DoubleMath::FAbs(difference * slope) + deviation);
				if (xMax < xMin)
				{
					step = -step;
				}

				const auto x = xMin + boost::numeric_cast<int>(step);
				
				for (int widthIndex = 0; widthIndex < pixelScreen.GetScreenWidth(); ++widthIndex)
				{
					const auto colour = pixelScreen.GetPixel(widthIndex, heightIndex);					

					if (widthIndex == x)
					{
						
						ASSERT_EQUAL(colour, clearColour);
					}
					else
					{
						ASSERT_EQUAL(colour, sm_Black);
					}
				}
			}
		}
	}	
}

void Framework::PixelScreenTesting
	::DrawRectangleSolidTest()
{
	constexpr auto minSize = 0;
	constexpr auto maxSize = 128;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1;

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		auto xMin = sizeRandom(generator);
		auto yMin = sizeRandom(generator);
		auto xMax = sizeRandom(generator);
		auto yMax = sizeRandom(generator);

		auto pixelScreen = CreateTestPixelScreen(width, height); 

		if (xMax < xMin)
		{
			swap(xMin, xMax);
		}

		if (yMax < yMin)
		{
			swap(yMin, yMax);
		}

		pixelScreen.DrawRectangle(xMin, yMin, xMax, yMax, clearColour, true);		

		for (auto widthIndex = 0; widthIndex < width; ++widthIndex)
		{
			for (auto heightIndex = 0; heightIndex < height; ++heightIndex)
			{
				const auto colour = pixelScreen.GetPixel(widthIndex, heightIndex);

				if (xMin <= widthIndex && widthIndex <= xMax &&
					yMin <= heightIndex && heightIndex <= yMax)
				{
					ASSERT_EQUAL(colour, clearColour);
				}
				else
				{
					ASSERT_EQUAL(colour, sm_Black);
				}
			}
		}
	}
}

void Framework::PixelScreenTesting
	::DrawRectangleHollowTest()
{
	constexpr auto minSize = 0;
	constexpr auto maxSize = 128;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1;

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		auto xMin = sizeRandom(generator);
		auto yMin = sizeRandom(generator);
		auto xMax = sizeRandom(generator);
		auto yMax = sizeRandom(generator);

		auto pixelScreen = CreateTestPixelScreen(width, height);
		const auto clearColour = GetRandomColour(generator);

		if (xMax < xMin)
		{
			swap(xMin, xMax);
		}

		if (yMax < yMin)
		{
			swap(yMin, yMax);
		}

		pixelScreen.DrawRectangle(xMin, yMin, xMax, yMax, clearColour, false);

		for (auto widthIndex = 0; widthIndex < width; ++widthIndex)
		{
			for (auto heightIndex = 0; heightIndex < height; ++heightIndex)
			{
				const auto colour = pixelScreen.GetPixel(widthIndex, heightIndex);

				if (((xMin <= widthIndex && widthIndex <= xMax) &&
					 (yMin == heightIndex || heightIndex == yMax)) ||
					((yMin <= heightIndex && heightIndex <= yMax) &&
					 (xMin == widthIndex || widthIndex == xMax)))
				{
					ASSERT_EQUAL(colour, clearColour);
				}
				else
				{
					ASSERT_EQUAL(colour, sm_Black);
				}
			}
		}
	}
}

void Framework::PixelScreenTesting
	::DrawCircleSolidTest()
{
	constexpr auto minSize = 0;
	constexpr auto maxSize = 128;
	constexpr auto minRadius = 2;
	constexpr auto maxRadius = 50;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<> radiusRandom{ minRadius, maxRadius };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1;

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		const auto radius = radiusRandom(generator); 

		const auto x = sizeRandom(generator);
		const auto y = sizeRandom(generator);

		const Mathematics::DoubleVector2D center{ boost::numeric_cast<double>(x),boost::numeric_cast<double>(y) };

		auto pixelScreen = CreateTestPixelScreen(width, height);

		pixelScreen.DrawCircle(x, y, radius, clearColour,true);

		for (auto widthIndex = 0; widthIndex < width; ++widthIndex)
		{
			for (auto heightIndex = 0; heightIndex < height; ++heightIndex)
			{
				const auto colour = pixelScreen.GetPixel(widthIndex, heightIndex);				

				const Mathematics::DoubleVector2D vector2D{ boost::numeric_cast<double>(widthIndex),boost::numeric_cast<double>(heightIndex) };
				auto distance = Mathematics::DoubleVector2DTools::Distance(center, vector2D);

				if (radius + 0.5 < distance)
				{
					ASSERT_EQUAL(colour, sm_Black);
				} 
				else if (distance < radius)
				{
					ASSERT_EQUAL(colour, clearColour);
				}
				else
				{
					// 检测边界值			 
			 
					auto difference = widthIndex - x;
					auto didifferenceAbsolute = Mathematics::DoubleMath::FAbs(difference);

					const auto separateRadius = GetSeparateRadius(radius);

					auto dec = 3 - 2 * radius;
					auto yStep = radius;

					if (heightIndex == y && didifferenceAbsolute <= radius)
					{
						ASSERT_EQUAL(colour, clearColour);
					}
					else if (didifferenceAbsolute < separateRadius)
					{ 
						for (auto xStep = 0; xStep <= yStep && xStep < didifferenceAbsolute; ++xStep)
						{
							if (0 <= dec)
							{
								dec += -4 * yStep + 4;
								--yStep;
							}
							dec += 4 * xStep + 6;
						}

						if ((heightIndex <= y + yStep && y < heightIndex) || (y - yStep <= heightIndex && heightIndex < y))
						{
							ASSERT_EQUAL(colour, clearColour);
						}
						else
						{
							ASSERT_EQUAL(colour, sm_Black);
						}
					}			 
					else
					{							
						auto xStep = 0;
						for (;xStep <= yStep && didifferenceAbsolute <= yStep; ++xStep)
						{
							if (0 <= dec)
							{
								dec += -4 * yStep + 4;
								--yStep;
							}
							dec += 4 * xStep + 6;
						} 

						if (0 < xStep)
						{
							--xStep;
						}

						if ((heightIndex <= y + xStep && y < heightIndex) || (y - xStep <= heightIndex && heightIndex < y))
						{
							ASSERT_EQUAL(colour, clearColour);
						}
						else
						{
							ASSERT_EQUAL(colour, sm_Black);
						}
					}					
				}
			}
		}
	}
}

void Framework::PixelScreenTesting
	::DrawCircleHollowTest()
{
	constexpr auto minSize = 0;
	constexpr auto maxSize = 128;
	constexpr auto minRadius = 2;
	constexpr auto maxRadius = 50;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<> radiusRandom{ minRadius, maxRadius };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1;

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		const auto radius = radiusRandom(generator);

		const auto x = sizeRandom(generator);
		const auto y = sizeRandom(generator);

		const Mathematics::DoubleVector2D center{ boost::numeric_cast<double>(x),boost::numeric_cast<double>(y) };

		auto pixelScreen = CreateTestPixelScreen(width, height);

		pixelScreen.DrawCircle(x, y, radius, clearColour, false);

		for (auto widthIndex = 0; widthIndex < width; ++widthIndex)
		{
			for (auto heightIndex = 0; heightIndex < height; ++heightIndex)
			{
				const auto colour = pixelScreen.GetPixel(widthIndex, heightIndex);

				const Mathematics::DoubleVector2D vector2D{ boost::numeric_cast<double>(widthIndex),boost::numeric_cast<double>(heightIndex) };
				auto distance = Mathematics::DoubleVector2DTools::Distance(center, vector2D);

				if (Mathematics::DoubleMath::FAbs(radius - distance) <= 0.5)
				{
					bool isClearColour = false;
					auto dec = 3 - 2 * radius;
					for (auto xStep = 0, yStep = radius; xStep <= yStep; ++xStep)
					{
						const auto xCenterMinusX = x - xStep;
						const auto xCenterPlusX = x + xStep;
						const auto yCenterMinusY = y - yStep;
						const auto yCenterPlusY = y + yStep;	

						if ((xCenterPlusX == widthIndex || xCenterMinusX == widthIndex) && 
							(yCenterPlusY == heightIndex || yCenterMinusY == heightIndex))
						{
							isClearColour = true;
							break;
						}	

						const auto xCenterMinusY = x - yStep;
						const auto xCenterPlusY = x + yStep;
						const auto yCenterMinusX = y - xStep;
						const auto yCenterPlusX = y + xStep;

						if ((xCenterPlusY == widthIndex || xCenterMinusY == widthIndex) &&
							(yCenterPlusX == heightIndex || yCenterMinusX == heightIndex))
						{
							isClearColour = true;
							break;
						}						

						if (0 <= dec)
						{
							dec += -4 * yStep + 4;
							--yStep;
						}
						dec += 4 * xStep + 6;
					}

					if (!isClearColour)
					{
						ASSERT_EQUAL(colour, sm_Black);
					}						
				}				
				else
				{
					ASSERT_EQUAL(colour, sm_Black);
				}
			}				
		}
	}
}

void Framework::PixelScreenTesting
	::FillThickPixelTest()
{
	constexpr auto minSize = 0;
	constexpr auto maxSize = 128;
	constexpr auto minThick = 2;
	constexpr auto maxThick = 10;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<> thickRandom{ minThick, maxThick };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1;

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		const auto thick = thickRandom(generator);

		const auto x = sizeRandom(generator);
		const auto y = sizeRandom(generator);

		auto pixelScreen = CreateTestPixelScreen(width, height);

		pixelScreen.SetThickPixel(x, y, thick, clearColour);

		auto originalPixelScreen = pixelScreen;

		const auto fillColour = GetRandomColour(generator);

		pixelScreen.Fill(x, y, fillColour, clearColour);
		originalPixelScreen.SetThickPixel(x, y, thick, fillColour);

		AssertColour(originalPixelScreen, pixelScreen);
	}
}

void Framework::PixelScreenTesting
	::FillRectangleSolidTest()
{
	constexpr auto minSize = 0;
	constexpr auto maxSize = 128;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1;

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		auto xMin = sizeRandom(generator);
		auto yMin = sizeRandom(generator);
		auto xMax = sizeRandom(generator);
		auto yMax = sizeRandom(generator);

		auto pixelScreen = CreateTestPixelScreen(width, height);

		if (xMax < xMin)
		{
			swap(xMin, xMax);
		}

		if (yMax < yMin)
		{
			swap(yMin, yMax);
		}

		pixelScreen.DrawRectangle(xMin, yMin, xMax, yMax, clearColour, true);

		auto originalPixelScreen = pixelScreen;

		const auto fillColour = GetRandomColour(generator);

		pixelScreen.Fill(xMin, yMin, fillColour, clearColour);
		originalPixelScreen.DrawRectangle(xMin, yMin, xMax, yMax, fillColour, true);

		AssertColour(originalPixelScreen, pixelScreen);
	}
}

void Framework::PixelScreenTesting
	::FillRectangleHollowTest()
{
	constexpr auto minSize = 0;
	constexpr auto maxSize = 128;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1;

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		auto xMin = sizeRandom(generator);
		auto yMin = sizeRandom(generator);
		auto xMax = sizeRandom(generator);
		auto yMax = sizeRandom(generator);

		auto pixelScreen = CreateTestPixelScreen(width, height);

		if (xMax < xMin)
		{
			swap(xMin, xMax);
		}

		if (yMax < yMin)
		{
			swap(yMin, yMax);
		}

		pixelScreen.DrawRectangle(xMin, yMin, xMax, yMax, clearColour, false);

		auto originalPixelScreen = pixelScreen;

		const auto fillColour = GetRandomColour(generator);

		pixelScreen.Fill(xMin, yMin, fillColour, clearColour);
		originalPixelScreen.DrawRectangle(xMin, yMin, xMax, yMax, fillColour, false);

		AssertColour(originalPixelScreen, pixelScreen);
	}
}

void Framework::PixelScreenTesting
	::FillCircleSolidTest()
{
	constexpr auto minSize = 0;
	constexpr auto maxSize = 128;
	constexpr auto minRadius = 2;
	constexpr auto maxRadius = 50;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> sizeRandom{ minSize, maxSize };
	const uniform_int<> radiusRandom{ minRadius, maxRadius };
	const uniform_int<uint8_t> colourRandom{ sm_MinColour, sm_MaxColour };

	constexpr auto width = maxSize + 1;
	constexpr auto height = maxSize + 1;

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto clearColour = GetRandomColour(generator);

		const auto radius = radiusRandom(generator);

		const auto x = sizeRandom(generator);
		const auto y = sizeRandom(generator);

		const Mathematics::DoubleVector2D center{ boost::numeric_cast<double>(x),boost::numeric_cast<double>(y) };

		auto pixelScreen = CreateTestPixelScreen(width, height);

		pixelScreen.DrawCircle(x, y, radius, clearColour, true);

		auto originalPixelScreen = pixelScreen;

		const auto fillColour = GetRandomColour(generator);

		pixelScreen.Fill(x, y, fillColour, clearColour);
		originalPixelScreen.DrawCircle(x, y, radius, fillColour, true);

		AssertColour(originalPixelScreen, pixelScreen);
	}
}

void Framework::PixelScreenTesting
	::AssertColour(const TestingType& pixelScreen, const Colour& colour)
{
	for (auto widthIndex = 0; widthIndex < pixelScreen.GetScreenWidth(); ++widthIndex)
	{
		for (auto heightIndex = 0; heightIndex < pixelScreen.GetScreenHeight(); ++heightIndex)
		{
			ASSERT_EQUAL(colour, pixelScreen.GetPixel(widthIndex, heightIndex));
		}
	}
}

void Framework::PixelScreenTesting
	::AssertColour(const TestingType& lhs, const TestingType& rhs)
{
	ASSERT_EQUAL_FAILURE_THROW(lhs.GetScreenWidth(), rhs.GetScreenWidth(), "测试对象的宽度不一致。");
	ASSERT_EQUAL_FAILURE_THROW(lhs.GetScreenHeight(), rhs.GetScreenHeight(), "测试对象的高度不一致。");

	for (auto widthIndex = 0; widthIndex < lhs.GetScreenWidth(); ++widthIndex)
	{
		for (auto heightIndex = 0; heightIndex < lhs.GetScreenHeight(); ++heightIndex)
		{
			ASSERT_EQUAL(lhs.GetPixel(widthIndex, heightIndex), rhs.GetPixel(widthIndex, heightIndex));
		}
	}
}

Framework::PixelScreen Framework::PixelScreenTesting
	::CreateTestPixelScreen()
{
	constexpr auto width = 20;
	constexpr auto height = 30;
	
	return CreateTestPixelScreen(width, height);
}

Framework::PixelScreen Framework::PixelScreenTesting
	::CreateTestPixelScreen(int width, int height)
{
	const WindowSize windowSize{ width, height };

	TestingType pixelScreen{ windowSize };
	ASSERT_EQUAL(pixelScreen.GetScreenWidth(), width);
	ASSERT_EQUAL(pixelScreen.GetScreenHeight(), height);

	return pixelScreen;
}

void Framework::PixelScreenTesting
	::AssertColourOnX(const TestingType& pixelScreen, const Colour& colour, int xBegin, int xEnd)
{
	for (int widthIndex = xBegin; widthIndex < xEnd && widthIndex < pixelScreen.GetScreenWidth(); ++widthIndex)
	{
		for (int heightIndex = 0; heightIndex < pixelScreen.GetScreenHeight(); ++heightIndex)
		{
			ASSERT_EQUAL(colour, pixelScreen.GetPixel(widthIndex, heightIndex));
		}
	}
}

void Framework::PixelScreenTesting
	::AssertColourOnY(const TestingType& pixelScreen, const Colour& colour, int yBegin, int yEnd)
{
	for (int heightIndex = yBegin; heightIndex < yEnd && heightIndex < pixelScreen.GetScreenHeight(); ++heightIndex)
	{
		for (int widthIndex = 0; widthIndex < pixelScreen.GetScreenWidth(); ++widthIndex)
		{
			ASSERT_EQUAL(colour, pixelScreen.GetPixel(widthIndex, heightIndex));
		}
	}
}

int Framework::PixelScreenTesting
	::GetSeparateRadius(int radius) const noexcept
{
	auto dec = 3 - 2 * radius;
	auto separateRadius = 0;
	auto yStep = radius;
	for (; separateRadius <= yStep; ++separateRadius)
	{
		if (0 <= dec)
		{
			dec += -4 * yStep + 4;
			--yStep;
		}
		dec += 4 * separateRadius + 6;
	}

	return separateRadius;
}

void Framework::PixelScreenTesting
	::DrawTest()
{
	auto renderer = make_shared<Rendering::Renderer>("Configuration/Renderer.json");
	renderer->Init();

	auto pixelScreen = CreateTestPixelScreen();

	pixelScreen.Draw(renderer);
}

