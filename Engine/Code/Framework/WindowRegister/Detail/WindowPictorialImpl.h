/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 14:11)

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
        using BrushTypes = System::WindowsBrushTypes;

    public:
        explicit WindowPictorialImpl(BrushTypes background);
        WindowPictorialImpl(const TChar* icon, const TChar* cursor, BrushTypes background);
        WindowPictorialImpl(HInstance instance, int icon, int cursor, BrushTypes background);
        WindowPictorialImpl(HInstance instance, int icon, const TChar* cursor, BrushTypes background);
        WindowPictorialImpl(HInstance instance, const TChar* icon, int cursor, BrushTypes background);
        WindowPictorialImpl(HInstance instance, bool isDefaultIcon, int icon, bool isDefaultCursor, int cursor, BrushTypes background);

        CLASS_INVARIANT_DECLARE;

        NODISCARD HIcon GetHIcon() const noexcept;
        NODISCARD HCursor GetHCursor() const noexcept;
        NODISCARD HBrush GetHBrush() const noexcept;

    private:
        using WindowHBrushUniquePtr = std::unique_ptr<WindowHBrush>;

    private:
        NODISCARD static WindowHBrushUniquePtr CreateWindowsHBrush(BrushTypes background);

    private:
        WindowHIcon windowsHIcon;
        WindowHCursor windowsHCursor;
        WindowHBrushUniquePtr windowsHBrush;
    };
}

#endif  // FRAMEWORK_WINDOW_REGISTER_WINDOW_PICTORIAL_IMPL_H
