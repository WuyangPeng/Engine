/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:11)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_H_BRUSH_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_H_BRUSH_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Flags/WindowsPictorialFlags.h"
#include "System/Windows/Using/WindowsPictorialUsing.h"

namespace Framework
{
    class FRAMEWORK_DEFAULT_DECLARE WindowHBrush
    {
    public:
        using ClassType = WindowHBrush;

        using HBrush = System::WindowsHBrush;
        using HGdiObj = System::WindowsHGdiObj;
        using WindowsBrushTypes = System::WindowsBrushTypes;

    public:
        explicit WindowHBrush(WindowsBrushTypes background = WindowsBrushTypes::WhiteBrush) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD HBrush GetHBrush() const noexcept;

    private:
        void CheckUpHBrush() noexcept;

    private:
        HGdiObj hBrush;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_H_BRUSH_H
