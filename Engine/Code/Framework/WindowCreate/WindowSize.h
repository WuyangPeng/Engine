/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:45)

#ifndef FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H
#define FRAMEWORK_WINDOW_CREATE_WINDOW_SIZE_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <iosfwd>

// 窗口大小类的声明，没有使用Impl模式。只定义了==、!=、<<操作运算符。
namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowSize : private boost::equality_comparable<WindowSize>
    {
    public:
        using ClassType = WindowSize;

        using WindowsLParam = System::WindowsLParam;

    public:
        WindowSize() noexcept;
        WindowSize(int width, int height);
        explicit WindowSize(WindowsLParam lParam);

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
