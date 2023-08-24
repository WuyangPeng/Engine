///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/04 14:00)

#ifndef FRAMEWORK_WINDOW_PROCESS_MOUSE_TYPES_H
#define FRAMEWORK_WINDOW_PROCESS_MOUSE_TYPES_H

namespace Framework
{
    enum class MouseButtonsTypes
    {
        NullButton,
        LeftButton,
        MiddleButton,
        RightButton
    };

    enum class MouseStateTypes
    {
        MouseNull,
        MouseUp,
        MouseDown
    };
}

#endif  // FRAMEWORK_WINDOW_PROCESS_MOUSE_TYPES_H
