// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.2 (2020/06/03 14:19)

#include "WindowPointTesting.h"
#include "System/Window/Flags/WindowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "Framework/WindowCreate/WindowPoint.h"

#include <random> 

using std::uniform_int;
using std::default_random_engine;

namespace Framework
{
	using TestingType = WindowPoint;
}

Framework::WindowPointTesting
	::WindowPointTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowPointTesting)

void Framework::WindowPointTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowPointTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
	ASSERT_NOT_THROW_EXCEPTION_0(RandomTest);
	ASSERT_NOT_THROW_EXCEPTION_0(WindowPointUseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(EqualTest);
}

void Framework::WindowPointTesting
	::DefaultTest() noexcept
{
	constexpr TestingType windowPoint{ };

	static_assert(0 == windowPoint.GetWindowX());
	static_assert(0 == windowPoint.GetWindowY());
}

void Framework::WindowPointTesting
	::RandomTest()
{
	constexpr auto minValue = 0;
	constexpr auto maxValue = 2048;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto x = random(generator);
		const auto y = random(generator);

		const TestingType point1(x, y);

		ASSERT_EQUAL(x, point1.GetWindowX());
		ASSERT_EQUAL(y, point1.GetWindowY());

		const TestingType::Point point2{ x, y };

		const TestingType point3(point2);

		ASSERT_EQUAL(x, point3.GetWindowX());
		ASSERT_EQUAL(y, point3.GetWindowY());
	}
}

void Framework::WindowPointTesting
	::WindowPointUseTest() noexcept
{
	constexpr TestingType windowPoint{ System::WindowPointUse::Default };

	static_assert(System::EnumCastUnderlying(System::WindowPointUse::Default) == windowPoint.GetWindowX());
	static_assert(System::EnumCastUnderlying(System::WindowPointUse::Default) == windowPoint.GetWindowY());
}

void Framework::WindowPointTesting
	::LParamTest()
{
	constexpr auto minValue = 0;
	constexpr auto maxValue = 2048;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const auto x = random(generator);
		const auto y = random(generator);

		const auto lParam = x + (y << System::g_WordShift);

		const TestingType windowPoint{ lParam };

		ASSERT_EQUAL(x, windowPoint.GetWindowX());
		ASSERT_EQUAL(y, windowPoint.GetWindowY());
	}
}

void Framework::WindowPointTesting
	::EqualTest()
{
	constexpr auto minValue = 0;
	constexpr auto maxValue = 2048;

	std::default_random_engine generator{ GetEngineRandomSeed() };
	const std::uniform_int<> random(minValue, maxValue);

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const int x = random(generator);
		const int y = random(generator);

		const TestingType lhsPoint(x, y);
		TestingType rhsPoint;

		ASSERT_UNEQUAL(lhsPoint, rhsPoint);
		ASSERT_EQUAL(lhsPoint, lhsPoint);
		ASSERT_EQUAL(rhsPoint, rhsPoint);

		rhsPoint.SetWindowPoint(x, y);

		ASSERT_EQUAL(lhsPoint, rhsPoint); 
	}
}

void Framework::WindowPointTesting
	::OstreamTest()
{
	constexpr auto minValue = 0;
	constexpr auto maxValue = 2048;

	default_random_engine generator{ GetEngineRandomSeed() };
	const uniform_int<> random{ minValue, maxValue };

	const auto testLoopCount = GetTestLoopCount();
	for (auto i = 0; i < testLoopCount; ++i)
	{
		const int x = random(generator);
		const int y = random(generator);

		const TestingType point(x, y);

		GetStream() << point << '\n';
	}
}

namespace Framework
{
	constexpr TestingType GetWindowPointSum(const TestingType& lhs, const TestingType& rhs)
	{
		TestingType sum{ };

		sum.SetWindowPoint(lhs.GetWindowX() + rhs.GetWindowX(), lhs.GetWindowY() + rhs.GetWindowY());

		return sum;
	}
}

void Framework::WindowPointTesting
	::ConstexprTest() noexcept
{
	constexpr auto x = 1;
	constexpr auto y = 2;
	constexpr auto lParam = x + (y << System::g_WordShift);

	constexpr TestingType windowPoint1{ x, y };

	static_assert(x == windowPoint1.GetWindowX());
	static_assert(y == windowPoint1.GetWindowY());

	constexpr TestingType windowPoint2{ lParam };

	static_assert(x == windowPoint2.GetWindowX());
	static_assert(y == windowPoint2.GetWindowY());

	constexpr TestingType::Point point{ x,y };

	constexpr TestingType windowPoint3{ point };

	static_assert(x == windowPoint3.GetWindowX());
	static_assert(y == windowPoint3.GetWindowY());

	constexpr auto windowPoint4 = GetWindowPointSum(windowPoint1, windowPoint2);

	static_assert(x + x == windowPoint4.GetWindowX());
	static_assert(y + y == windowPoint4.GetWindowY());
}

