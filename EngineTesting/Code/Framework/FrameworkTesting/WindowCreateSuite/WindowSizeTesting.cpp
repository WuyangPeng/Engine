// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 11:36)

#include "WindowSizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/WindowCreate/WindowSize.h" 

#include <random> 
#include "System/Helper/WindowsMacro.h"

using std::uniform_int;
using std::default_random_engine;

namespace Framework
{
	using TestingType = WindowSize;
}

Framework::WindowSizeTesting
	::WindowSizeTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowSizeTesting)

void Framework::WindowSizeTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowSizeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
	ASSERT_NOT_THROW_EXCEPTION_0(RandomTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LParamTest);
	ASSERT_NOT_THROW_EXCEPTION_0(EqualTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SetWindowSizeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OstreamTest);
	ASSERT_NOT_THROW_EXCEPTION_0(NegativeTest);
}

void Framework::WindowSizeTesting
	::DefaultTest()
{
	const TestingType size{ };

	ASSERT_EQUAL(0, size.GetWindowWidth());
	ASSERT_EQUAL(0, size.GetWindowHeight());
}

void Framework::WindowSizeTesting
	::RandomTest()
{
	constexpr auto minValue = 0;
	constexpr auto maxValue = 2048;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto width = random(generator);
		const auto height = random(generator);

		const TestingType size{ width, height };

		ASSERT_EQUAL(width, size.GetWindowWidth());
		ASSERT_EQUAL(height, size.GetWindowHeight());
	}
}

void Framework::WindowSizeTesting
	::LParamTest()
{
	constexpr auto minValue = 0;
	constexpr auto maxValue = 2048;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto width = random(generator);
		const auto height = random(generator);
		const auto lParam = width + (height << System::g_WordShift); 

		const TestingType size{ lParam };

		ASSERT_EQUAL(width, size.GetWindowWidth());
		ASSERT_EQUAL(height, size.GetWindowHeight());
	}
}

void Framework::WindowSizeTesting
	::EqualTest()
{
	constexpr auto minValue = 0;
	constexpr auto maxValue = 2048;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto width = random(generator);
		const auto height = random(generator);
		const auto lParam = width + (height << System::g_WordShift);  

		const TestingType size1{ lParam };
		const TestingType size2{ width, height };

		ASSERT_EQUAL(size1, size2);

		const TestingType size3{ width, height + 1 };

		ASSERT_UNEQUAL(size1, size3);
	}
}

void Framework::WindowSizeTesting
	::SetWindowSizeTest()
{
	constexpr auto minValue = 1;
	constexpr auto maxValue = 2048;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		auto width = random(generator);
		auto height = random(generator);

		SetNegative(i, width, height);

		ASSERT_THROW_EXCEPTION_2(SetWindowSizeExceptionTest, width, height);
	}
}

void Framework::WindowSizeTesting
	::SetWindowSizeExceptionTest(int width, int height)
{
	TestingType size{ };

	size.SetWindowSize(width, height);
}

void Framework::WindowSizeTesting
	::OstreamTest()
{
	constexpr auto minValue = 0;
	constexpr auto maxValue = 2048;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto width = random(generator);
		const auto height = random(generator);

		const TestingType size{ width, height };

		GetStream() << size << '\n';
	}
}

void Framework::WindowSizeTesting
	::NegativeTest()
{
	constexpr auto minValue = 1;
	constexpr auto maxValue = 2048;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		auto width = random(generator);
		auto height = random(generator);

		SetNegative(i, width, height); 

		ASSERT_THROW_EXCEPTION_2(WindowSizeExceptionTest, width, height);		
	}
}

void Framework::WindowSizeTesting
	::WindowSizeExceptionTest(int width, int height)
{
	const TestingType size{ width, height };
}

void Framework::WindowSizeTesting
	::SetNegative(int index, int& width, int& height) noexcept
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
