/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/20 16:23)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_FLAGS_H
#define RENDERING_CONTROLLERS_CONTROLLER_FLAGS_H

namespace Rendering
{
    // ʱ�����һ������������ʹ���Լ���ʱ���������ָ��ʱ������α�ӳ�䵽Ӧ�ó���ʱ�䡣
    enum class ControllerRepeatType
    {
        Clamp,
        Wrap,
        ClampCycle
    };
}

#endif  // RENDERING_CONTROLLERS_CONTROLLER_FLAGS_H
