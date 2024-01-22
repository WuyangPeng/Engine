/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 15:23)

#ifndef FRAMEWORK_APPLICATION_MOUSE_BUTTONS_H
#define FRAMEWORK_APPLICATION_MOUSE_BUTTONS_H

#include "Framework/FrameworkDll.h"

#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"

namespace Framework
{
    struct WindowMouseButtons
    {
        static constexpr auto mouseLeftButton = 0;
        static constexpr auto mouseMiddleButton = 1;
        static constexpr auto mouseRightButton = 2;
    };

    struct GlutMouseButtons
    {
        static constexpr auto mouseLeftButton = EnumCastUnderlying(System::GlutModifiersCodes::LeftButton);
        static constexpr auto mouseMiddleButton = EnumCastUnderlying(System::GlutModifiersCodes::MiddleButton);
        static constexpr auto mouseRightButton = EnumCastUnderlying(System::GlutModifiersCodes::RightButton);
    };

    struct AndroidMouseButtons
    {
        static constexpr auto mouseLeftButton = 0;
        static constexpr auto mouseMiddleButton = 1;
        static constexpr auto mouseRightButton = 2;
    };

    struct LinuxMouseButtons
    {
        static constexpr auto mouseLeftButton = 0;
        static constexpr auto mouseMiddleButton = 1;
        static constexpr auto mouseRightButton = 2;
    };

    struct MacintoshMouseButtons
    {
        static constexpr auto mouseLeftButton = 0;
        static constexpr auto mouseMiddleButton = 1;
        static constexpr auto mouseRightButton = 2;
    };
}

#endif  // FRAMEWORK_APPLICATION_MOUSE_BUTTONS_H
