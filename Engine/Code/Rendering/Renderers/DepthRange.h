///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:49)

#ifndef RENDERING_RENDERERS_DEPTH_RANGE_H
#define RENDERING_RENDERERS_DEPTH_RANGE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DepthRange
    {
    public:
        constexpr DepthRange(float zMin, float zMax) noexcept
            : zMin{ zMin }, zMax{ zMax }
        {
        }

        constexpr float GetZMin() const noexcept
        {
            return zMin;
        }

        constexpr float GetMax() const noexcept
        {
            return zMax;
        }

    private:
        float zMin;
        float zMax;
    };
}

#endif  // RENDERING_RENDERERS_GLOBAL_STATE_H
