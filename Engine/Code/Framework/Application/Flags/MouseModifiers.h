/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:23)

#ifndef FRAMEWORK_APPLICATION_MOUSE_MODIFIERS_H
#define FRAMEWORK_APPLICATION_MOUSE_MODIFIERS_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Windows/Flags/WindowsKeyCodesFlags.h"

namespace Framework
{
    struct WindowMouseModifiers
    {
        static constexpr auto modifierControl = EnumCastUnderlying(System::WindowsModifiersCodes::Control);
        static constexpr auto modifierLeftButton = EnumCastUnderlying(System::WindowsModifiersCodes::LeftButton);
        static constexpr auto modifierMiddleButton = EnumCastUnderlying(System::WindowsModifiersCodes::MiddleButton);
        static constexpr auto modifierRightButton = EnumCastUnderlying(System::WindowsModifiersCodes::RightButton);
        static constexpr auto modifierShift = EnumCastUnderlying(System::WindowsModifiersCodes::Shift);
    };

    struct GlutMouseModifiers
    {
        static constexpr auto modifierControl = EnumCastUnderlying(System::GlutModifiersCodes::Control);
        static constexpr auto modifierLeftButton = EnumCastUnderlying(System::GlutModifiersCodes::LeftButton);
        static constexpr auto modifierMiddleButton = EnumCastUnderlying(System::GlutModifiersCodes::MiddleButton);
        static constexpr auto modifierRightButton = EnumCastUnderlying(System::GlutModifiersCodes::RightButton);
        static constexpr auto modifierShift = EnumCastUnderlying(System::GlutModifiersCodes::Shift);
    };

    struct AndroidMouseModifiers
    {
        static constexpr auto modifierControl = 0x0008;
        static constexpr auto modifierLeftButton = 0x0001;
        static constexpr auto modifierMiddleButton = 0x0010;
        static constexpr auto modifierRightButton = 0x0002;
        static constexpr auto modifierShift = 0x0004;
    };

    struct LinuxMouseModifiers
    {
        static constexpr auto modifierControl = 0;
        static constexpr auto modifierLeftButton = 0;
        static constexpr auto modifierMiddleButton = 0;
        static constexpr auto modifierRightButton = 0;
        static constexpr auto modifierShift = 0;
    };

    struct MacintoshMouseModifiers
    {
        static constexpr auto modifierControl = 0;
        static constexpr auto modifierLeftButton = 0;
        static constexpr auto modifierMiddleButton = 0;
        static constexpr auto modifierRightButton = 0;
        static constexpr auto modifierShift = 0;
    };
}

#endif  // FRAMEWORK_APPLICATION_MOUSE_MODIFIERS_H
