/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 14:16)

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
