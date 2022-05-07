///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:25)

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
