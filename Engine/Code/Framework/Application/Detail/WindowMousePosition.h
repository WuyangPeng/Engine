/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:22)

#ifndef FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H
#define FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H

#include "Framework/FrameworkDll.h"

#include "MousePositionImpl.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowMousePosition final : public MousePositionImpl
    {
    public:
        using ClassType = WindowMousePosition;
        using ParentType = MousePositionImpl;

    public:
        explicit WindowMousePosition(WindowsHWnd hWnd) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 鼠标位置
        NODISCARD WindowPoint GetMousePosition() const noexcept override;
        void SetMousePosition(const WindowPoint& windowPoint) noexcept override;
        NODISCARD MousePositionImplSharedPtr Clone() const override;

    private:
        WindowsHWnd hWnd;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H
