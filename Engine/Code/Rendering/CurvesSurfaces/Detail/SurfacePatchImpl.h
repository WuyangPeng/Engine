///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:58)

#ifndef RENDERING_CURVES_SURFACES_SURFACE_PATCH_IMPL_H
#define RENDERING_CURVES_SURFACES_SURFACE_PATCH_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SurfacePatchImpl
    {
    public:
        using ClassType = SurfacePatchImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        SurfacePatchImpl() noexcept;
        SurfacePatchImpl(float uMin, float uMax, float vMin, float vMax, bool rectangular) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        // 参数域可以是矩形或三角形。
        // 对于矩形域有效的(u,v)值满足umin <= u <= umax,  vmin <= v <= vmax
        // 三角域有效的(u,v)值的满足 umin <= u <= umax,  vmin <= v <= vmax，
        //  (vmax - vmin) * (u - umin) + (umax - umin) * (v - vmax) <= 0
        NODISCARD float GetUMin() const noexcept;
        NODISCARD float GetUMax() const noexcept;
        NODISCARD float GetVMin() const noexcept;
        NODISCARD float GetVMax() const noexcept;
        NODISCARD bool IsRectangular() const noexcept;

    private:
        float uMin;
        float uMax;
        float vMin;
        float vMax;
        bool rectangular;
    };
}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_PATCH_IMPL_H
