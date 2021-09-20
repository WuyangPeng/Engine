// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.3.0.2 (2020/06/03 13:58)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_POINT_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_POINT_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/WindowsCreate.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Operators.h"

#include <gsl/util>
#include <iosfwd>

namespace Framework
{
	// 窗口点类的声明，没有使用Impl模式。只定义了==、!=、<<操作运算符。
	class FRAMEWORK_DEFAULT_DECLARE WindowPoint : private boost::equality_comparable<WindowPoint>
	{
	public:
		using ClassType = WindowPoint;
		using Point = System::WindowsPoint;
		using LParam = System::WindowsLParam;
		using WindowPointUse = System::WindowsPointUse;

	public:
		constexpr WindowPoint() noexcept
			:WindowPoint{ 0 , 0 }
		{
		}

		explicit constexpr WindowPoint(WindowPointUse windowPointUse) noexcept
			:WindowPoint{ System::EnumCastUnderlying(windowPointUse), System::EnumCastUnderlying(windowPointUse) }
		{
		}

		explicit constexpr WindowPoint(LParam lParam) noexcept
			:WindowPoint{ System::GetLowWord(lParam) , System::GetHighWord(lParam) }
		{
		}

		explicit constexpr WindowPoint(const Point& point)
			: WindowPoint{ gsl::narrow_cast<int>(point.x), gsl::narrow_cast<int>(point.y) }
		{
		}
		 
		constexpr WindowPoint(int x, int y) noexcept
			:m_X{ x }, m_Y{ y }
		{
		}

		CLASS_INVARIANT_DECLARE;

		constexpr int GetWindowX() const noexcept
		{
			return m_X;
		}

		constexpr int GetWindowY() const noexcept
		{
			return m_Y;
		}

		constexpr void SetWindowPoint(int x, int y) noexcept
		{
			m_X = x;
			m_Y = y;
		}

	private:
		int m_X;
		int m_Y;
	};

	constexpr bool operator == (const WindowPoint& lhs, const WindowPoint& rhs) noexcept
	{
		return lhs.GetWindowX() == rhs.GetWindowX() && lhs.GetWindowY() == rhs.GetWindowY();
	}

	FRAMEWORK_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const WindowPoint& windowPoint);
}

#endif // FRAMEWORK_WINDOW_CREATE_WINDOW_POINT_H
