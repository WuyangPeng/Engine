/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:23)

#ifndef FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H
#define FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H

#include "Framework/FrameworkDll.h"

#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"

namespace Framework
{
    struct WindowKeyboardModifiers
    {
        static constexpr auto keyShift = EnumCastUnderlying(System::WindowsKeyCodes::Shift);
        static constexpr auto keyControl = EnumCastUnderlying(System::WindowsKeyCodes::Control);
        static constexpr auto keyAlt = EnumCastUnderlying(System::WindowsKeyCodes::Menu);
    };

    struct GlutKeyboardModifiers
    {
        static constexpr auto keyShift = EnumCastUnderlying(System::GlutModifiersCodes::Shift);
        static constexpr auto keyControl = EnumCastUnderlying(System::GlutModifiersCodes::Control);
        static constexpr auto keyAlt = EnumCastUnderlying(System::GlutModifiersCodes::Alt);
    };

    struct AndroidKeyboardModifiers
    {
        static constexpr auto keyShift = 0;
        static constexpr auto keyControl = 0;
        static constexpr auto keyAlt = 0;
    };

    struct LinuxKeyboardModifiers
    {
        static constexpr auto keyShift = 0;
        static constexpr auto keyControl = 0;
        static constexpr auto keyAlt = 0;
    };

    struct MacintoshKeyboardModifiers
    {
        static constexpr auto keyShift = 0;
        static constexpr auto keyControl = 0;
        static constexpr auto keyAlt = 0;
    };
}

#endif  // FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H
