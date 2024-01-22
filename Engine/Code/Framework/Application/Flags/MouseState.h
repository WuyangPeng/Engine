/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:23)

#ifndef FRAMEWORK_APPLICATION_MOUSE_STATE_H
#define FRAMEWORK_APPLICATION_MOUSE_STATE_H

#include "Framework/FrameworkDll.h"

#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"

namespace Framework
{
    struct WindowMouseState
    {
        static constexpr auto mouseUp = 1;
        static constexpr auto mouseDown = 0;
    };

    struct GlutMouseState
    {
        static constexpr auto mouseUp = EnumCastUnderlying(System::GlutModifiersCodes::Up);
        static constexpr auto mouseDown = EnumCastUnderlying(System::GlutModifiersCodes::Down);
    };

    struct AndroidMouseState
    {
        static constexpr auto mouseUp = 1;
        static constexpr auto mouseDown = 0;
    };

    struct LinuxMouseState
    {
        static constexpr auto mouseUp = 1;
        static constexpr auto mouseDown = 0;
    };

    struct MacintoshMouseState
    {
        static constexpr auto mouseUp = 1;
        static constexpr auto mouseDown = 0;
    };
}

#endif  // FRAMEWORK_APPLICATION_MOUSE_STATE_H
