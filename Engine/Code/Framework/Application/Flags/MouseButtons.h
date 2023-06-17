///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/13 14:43)

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
        static constexpr auto mouseLeftButton = System::EnumCastUnderlying(System::GlutModifiersCodes::LeftButton);
        static constexpr auto mouseMiddleButton = System::EnumCastUnderlying(System::GlutModifiersCodes::MiddleButton);
        static constexpr auto mouseRightButton = System::EnumCastUnderlying(System::GlutModifiersCodes::RightButton);
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
