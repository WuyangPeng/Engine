// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:42)

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
        explicit WindowMousePosition(HWnd hwnd) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        //  Û±ÍŒª÷√
        const WindowPoint GetMousePosition() const noexcept final;
        void SetMousePosition(const WindowPoint& windowPoint) noexcept final;
        MousePositionImplSharedPtr Clone() const final;

    private:
        HWnd m_Hwnd;
    };
}

#endif  // FRAMEWORK_APPLICATION_WINDOW_MOUSE_POSITION_H
