///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/16 17:45)

#ifndef RENDERING_CURVES_SURFACES_CURVE_SEGMENT_H
#define RENDERING_CURVES_SURFACES_CURVE_SEGMENT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE CurveSegment : public CoreTools::Object
    {
    private:
        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(CurveSegment);

    public:
        using ClassType = CurveSegment;
        using ParentType = Object;
        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;

    protected:
        CurveSegment(float umin, float umax);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD float GetUMin() const noexcept;
        NODISCARD float GetUMax() const noexcept;

        NODISCARD virtual APoint P(float u) const = 0;
        NODISCARD virtual AVector PU(float u) const = 0;
        NODISCARD virtual AVector PUU(float u) const = 0;
        NODISCARD virtual AVector PUUU(float u) const = 0;

        NODISCARD AVector Tangent(float u) const;
        NODISCARD AVector Normal(float u) const;
        NODISCARD AVector Binormal(float u) const;
        void GetFrame(float u, APoint& position, AVector& tangent, AVector& normal, AVector& binormal) const;
        NODISCARD float Curvature(float u) const;
        NODISCARD float Torsion(float u) const;

    private:
        float uMin;
        float uMax;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(CurveSegment);
}

#endif  // RENDERING_CURVES_SURFACES_CURVE_SEGMENT_H
