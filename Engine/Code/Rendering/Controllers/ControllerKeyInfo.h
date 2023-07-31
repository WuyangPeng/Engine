///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/24 19:28)

#ifndef RENDERING_CONTROLLERS_CONTROLLER_KEY_INFO_H
#define RENDERING_CONTROLLERS_CONTROLLER_KEY_INFO_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ControllerKeyInfo
    {
    public:
        using ClassType = ControllerKeyInfo;

    public:
        ControllerKeyInfo() noexcept;
        ControllerKeyInfo(float normTime, int firstIndex, int secondIndex) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD float GetNormTime() const noexcept;
        NODISCARD int GetFirstIndex() const noexcept;
        NODISCARD int GetSecondIndex() const noexcept;

    private:
        float normTime;
        int firstIndex;
        int secondIndex;
    };
}

#endif  // RENDERING_CONTROLLERS_CONTROLLER_KEY_INFO_H
