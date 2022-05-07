///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 17:00)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_HBRUSH_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_HBRUSH_H

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

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_HBRUSH_H
