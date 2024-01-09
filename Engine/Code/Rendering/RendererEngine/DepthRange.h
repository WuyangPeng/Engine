/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 15:16)

#ifndef RENDERING_RENDERER_ENGINE_DEPTH_RANGE_H
#define RENDERING_RENDERER_ENGINE_DEPTH_RANGE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

/// 视窗管理，视图体积的深度范围为[zMin，zMax]。
/// DirectX深度范围为[0, 1] 的子集。
/// OpenGL深度范围是[-1, 1] 的子集。
namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DepthRange final
    {
    public:
        using ClassType = DepthRange;

    public:
        DepthRange() noexcept;
        DepthRange(float zMin, float zMax);

        NODISCARD bool IsValid() const noexcept;

        NODISCARD float GetZMin() const noexcept;
        NODISCARD float GetZMax() const noexcept;

    private:
        float zMin;
        float zMax;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_DEPTH_RANGE_H
