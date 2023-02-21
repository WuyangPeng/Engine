///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/18 15:28)

#ifndef RENDERING_CURVES_SURFACES_SURFACE_PATCH_H
#define RENDERING_CURVES_SURFACES_SURFACE_PATCH_H

#include "Rendering/RenderingDll.h"

#include "PrincipalCurvatureInfo.h"
#include "SurfacePatchFrame.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(SurfacePatch, SurfacePatchImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SurfacePatch : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(SurfacePatch);
        using ParentType = Object;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;

    public:
        SurfacePatch(float uMin, float uMax, float vMin, float vMax, bool rectangular);

#ifdef OPEN_CLASS_INVARIANT

        CLASS_INVARIANT_OVERRIDE_DECLARE;

#endif  // OPEN_CLASS_INVARIANT

        NODISCARD bool IsParameterValid(float u, float v) const noexcept;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SurfacePatch);

        // 参数域可以是矩形或三角形。
        // 对于矩形域有效的(u,v)值满足umin <= u <= umax,  vmin <= v <= vmax
        // 三角域有效的(u,v)值的满足 umin <= u <= umax,  vmin <= v <= vmax，
        //  (vmax - vmin) * (u - umin) + (umax - umin) * (v - vmax) <= 0
        NODISCARD float GetUMin() const noexcept;
        NODISCARD float GetUMax() const noexcept;
        NODISCARD float GetVMin() const noexcept;
        NODISCARD float GetVMax() const noexcept;
        NODISCARD bool IsRectangular() const noexcept;

        // 位置及二阶导数
        NODISCARD virtual APoint GetPosition(float u, float v) const = 0;
        NODISCARD virtual AVector GetDerivativesU(float u, float v) const = 0;
        NODISCARD virtual AVector GetDerivativesV(float u, float v) const = 0;
        NODISCARD virtual AVector GetDerivativesUU(float u, float v) const = 0;
        NODISCARD virtual AVector GetDerivativesUV(float u, float v) const = 0;
        NODISCARD virtual AVector GetDerivativesVV(float u, float v) const = 0;

        // 计算一个坐标系。集合{T0,T1,N}是一个右手正交坐标系。
        NODISCARD AVector GetTangent0(float u, float v) const;
        NODISCARD AVector GetTangent1(float u, float v) const;
        NODISCARD AVector GetNormal(float u, float v) const;
        NODISCARD SurfacePatchFrame GetFrame(float u, float v) const;

        // 微分几何量。返回的标量是主曲率，并返回矢量的对应主方向。
        NODISCARD PrincipalCurvatureInfo ComputePrincipalCurvatureInfo(float u, float v) const;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(SurfacePatch);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(SurfacePatch);
}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_PATCH_H
