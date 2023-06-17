///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:43)

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
        static const auto modifierControl = System::EnumCastUnderlying(System::WindowsModifiersCodes::Control);
        static const auto modifierLeftButton = System::EnumCastUnderlying(System::WindowsModifiersCodes::LeftButton);
        static const auto modifierMiddleButton = System::EnumCastUnderlying(System::WindowsModifiersCodes::MiddleButton);
        static const auto modifierRightButton = System::EnumCastUnderlying(System::WindowsModifiersCodes::RightButton);
        static const auto modifierShift = System::EnumCastUnderlying(System::WindowsModifiersCodes::Shift);
    };

    struct GlutMouseModifiers
    {
        static const auto modifierControl = System::EnumCastUnderlying(System::GlutModifiersCodes::Control);
        static const auto modifierLeftButton = System::EnumCastUnderlying(System::GlutModifiersCodes::LeftButton);
        static const auto modifierMiddleButton = System::EnumCastUnderlying(System::GlutModifiersCodes::MiddleButton);
        static const auto modifierRightButton = System::EnumCastUnderlying(System::GlutModifiersCodes::RightButton);
        static const auto modifierShift = System::EnumCastUnderlying(System::GlutModifiersCodes::Shift);
    };

    struct AndroidMouseModifiers
    {
        static const auto modifierControl = 0x0008;
        static const auto modifierLeftButton = 0x0001;
        static const auto modifierMiddleButton = 0x0010;
        static const auto modifierRightButton = 0x0002;
        static const auto modifierShift = 0x0004;
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
