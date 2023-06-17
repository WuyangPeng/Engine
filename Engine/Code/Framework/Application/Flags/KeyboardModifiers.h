///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:43)

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
