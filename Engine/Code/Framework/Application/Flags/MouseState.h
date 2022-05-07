///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/05/05 19:03)

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
        static constexpr auto mouseUp = System::EnumCastUnderlying(System::GlutModifiersCodes::Up);
        static constexpr auto mouseDown = System::EnumCastUnderlying(System::GlutModifiersCodes::Down);
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
