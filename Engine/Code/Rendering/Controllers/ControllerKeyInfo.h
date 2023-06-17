///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:01)

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
