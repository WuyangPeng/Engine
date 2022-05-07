///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/05 19:00)

#ifndef FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H
#define FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H

#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"
#include "Framework/FrameworkDll.h"

namespace Framework
{
    struct WindowKeyboardModifiers
    {
        static constexpr auto keyShift = System::EnumCastUnderlying(System::WindowsKeyCodes::Shift);
        static constexpr auto keyControl = System::EnumCastUnderlying(System::WindowsKeyCodes::Control);
        static constexpr auto keyAlt = System::EnumCastUnderlying(System::WindowsKeyCodes::Menu);
    };

    struct GlutKeyboardModifiers
    {
        static constexpr auto keyShift = System::EnumCastUnderlying(System::GlutModifiersCodes::Shift);
        static constexpr auto keyControl = System::EnumCastUnderlying(System::GlutModifiersCodes::Control);
        static constexpr auto keyAlt = System::EnumCastUnderlying(System::GlutModifiersCodes::Alt);
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
