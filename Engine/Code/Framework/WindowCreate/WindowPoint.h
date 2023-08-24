///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 15:15)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_POINT_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_POINT_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/Operators.h"
#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "System/Windows/WindowsCreate.h"

#include <gsl/util>
#include <iosfwd>

// 窗口点类的声明，没有使用Impl模式。只定义了==、!=、<<操作运算符。
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowPoint : private boost::equality_comparable<WindowPoint>
    {
    public:
        using ClassType = WindowPoint;

        using WindowsPoint = System::WindowsPoint;
        using WindowsLParam = System::WindowsLParam;
        using WindowPointUse = System::WindowsPointUse;

    public:
        constexpr WindowPoint() noexcept
            : WindowPoint{ 0, 0 }
        {
        }

        explicit constexpr WindowPoint(WindowPointUse windowPointUse) noexcept
            : WindowPoint{ System::EnumCastUnderlying(windowPointUse), System::EnumCastUnderlying(windowPointUse) }
        {
        }

        explicit constexpr WindowPoint(WindowsLParam lParam) noexcept
            : WindowPoint{ System::GetLowWord(lParam), System::GetHighWord(lParam) }
        {
        }

        explicit constexpr WindowPoint(const WindowsPoint& point)
            : WindowPoint{ gsl::narrow_cast<int>(point.x), gsl::narrow_cast<int>(point.y) }
        {
        }

        constexpr WindowPoint(int x, int y) noexcept
            : xPoint{ x }, yPoint{ y }
        {
        }

        CLASS_INVARIANT_DECLARE;

        NODISCARD constexpr int GetWindowX() const noexcept
        {
            return xPoint;
        }

        NODISCARD constexpr int GetWindowY() const noexcept
        {
            return yPoint;
        }

        constexpr void SetWindowPoint(int x, int y) noexcept
        {
            xPoint = x;
            yPoint = y;
        }

    private:
        int xPoint;
        int yPoint;
    };

    NODISCARD constexpr bool operator==(const WindowPoint& lhs, const WindowPoint& rhs) noexcept
    {
        return lhs.GetWindowX() == rhs.GetWindowX() && lhs.GetWindowY() == rhs.GetWindowY();
    }

    FRAMEWORK_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const WindowPoint& windowPoint);
}

#endif  // FRAMEWORK_WINDOW_CREATE_WINDOW_POINT_H
