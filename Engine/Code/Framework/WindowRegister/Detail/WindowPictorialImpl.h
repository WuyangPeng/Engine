///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:00)

#ifndef FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_IMPL_H
#define FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_IMPL_H

#include "Framework/FrameworkDll.h"

#include "System/Windows/Fwd/WindowsFlagsFwd.h"
#include "Framework/WindowRegister/WindowHCursor.h"
#include "Framework/WindowRegister/WindowHIcon.h"
#include "Framework/WindowRegister/WindowRegisterFwd.h"

#include <memory>

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE WindowPictorialImpl
    {
    public:
        using ClassType = WindowPictorialImpl;
        using TChar = System::TChar;
        using HIcon = System::WindowsHIcon;
        using HBrush = System::WindowsHBrush;
        using HCursor = System::WindowsHCursor;
        using HInstance = System::WindowsHInstance;
        using WindowsBrushTypes = System::WindowsBrushTypes;

    public:
        explicit WindowPictorialImpl(WindowsBrushTypes background);
        WindowPictorialImpl(const TChar* icon, const TChar* cursor, WindowsBrushTypes background);
        WindowPictorialImpl(HInstance instance, int icon, int cursor, WindowsBrushTypes background);
        WindowPictorialImpl(HInstance instance, int icon, const TChar* cursor, WindowsBrushTypes background);
        WindowPictorialImpl(HInstance instance, const TChar* icon, int cursor, WindowsBrushTypes background);
        WindowPictorialImpl(HInstance instance, bool isDefaultIcon, int icon, bool isDefaultCursor, int cursor, WindowsBrushTypes background);

        CLASS_INVARIANT_DECLARE;

        NODISCARD HIcon GetHIcon() const noexcept;
        NODISCARD HCursor GetHCursor() const noexcept;
        NODISCARD HBrush GetHBrush() const noexcept;

    private:
        using WindowHBrushUniquePtr = std::unique_ptr<WindowHBrush>;

    private:
        NODISCARD static WindowHBrushUniquePtr CreateWindowsHBrush(WindowsBrushTypes background);

    private:
        WindowHIcon windowsHIcon;
        WindowHCursor windowsHCursor;
        WindowHBrushUniquePtr windowsHBrush;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_IMPL_H
