///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/06 10:18)

#ifndef FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H
#define FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H

#include "MousePositionImpl.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowMousePosition final : public MousePositionImpl
    {
    public:
        using ClassType = WindowMousePosition;
        using ParentType = MousePositionImpl;

    public:
        explicit WindowMousePosition(WindowsHWnd hwnd) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 鼠标位置
        NODISCARD WindowPoint GetMousePosition() const noexcept final;
        void SetMousePosition(const WindowPoint& windowPoint) noexcept final;
        NODISCARD MousePositionImplSharedPtr Clone() const final;

    private:
        WindowsHWnd hwnd;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H
