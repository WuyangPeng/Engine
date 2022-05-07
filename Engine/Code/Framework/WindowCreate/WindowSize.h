///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 15:21)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <iosfwd>

namespace Framework
{
    // 窗口大小类的声明，没有使用Impl模式。只定义了==、!=、<<操作运算符。
    class FRAMEWORK_DEFAULT_DECLARE WindowSize : private boost::equality_comparable<WindowSize>
    {
    public:
        using ClassType = WindowSize;
        using LParam = System::WindowsLParam;

    public:
        WindowSize() noexcept;
        WindowSize(int width, int height);
        explicit WindowSize(LParam lParam);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetWindowWidth() const noexcept;
        NODISCARD int GetWindowHeight() const noexcept;

        void SetWindowSize(int width, int height);

    private:
        int windowWidth;
        int windowHeight;
    };

    NODISCARD bool FRAMEWORK_DEFAULT_DECLARE operator==(const WindowSize& lhs, const WindowSize& rhs) noexcept;
    FRAMEWORK_DEFAULT_DECLARE std::ostream& operator<<(std::ostream& os, const WindowSize& size);
}

#endif  // FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H
