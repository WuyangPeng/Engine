///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/18 15:28)

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

        // ����������Ǿ��λ������Ρ�
        // ���ھ�������Ч��(u,v)ֵ����umin <= u <= umax,  vmin <= v <= vmax
        // ��������Ч��(u,v)ֵ������ umin <= u <= umax,  vmin <= v <= vmax��
        //  (vmax - vmin) * (u - umin) + (umax - umin) * (v - vmax) <= 0
        NODISCARD float GetUMin() const noexcept;
        NODISCARD float GetUMax() const noexcept;
        NODISCARD float GetVMin() const noexcept;
        NODISCARD float GetVMax() const noexcept;
        NODISCARD bool IsRectangular() const noexcept;

        // λ�ü����׵���
        NODISCARD virtual APoint GetPosition(float u, float v) const = 0;
        NODISCARD virtual AVector GetDerivativesU(float u, float v) const = 0;
        NODISCARD virtual AVector GetDerivativesV(float u, float v) const = 0;
        NODISCARD virtual AVector GetDerivativesUU(float u, float v) const = 0;
        NODISCARD virtual AVector GetDerivativesUV(float u, float v) const = 0;
        NODISCARD virtual AVector GetDerivativesVV(float u, float v) const = 0;

        // ����һ������ϵ������{T0,T1,N}��һ��������������ϵ��
        NODISCARD AVector GetTangent0(float u, float v) const;
        NODISCARD AVector GetTangent1(float u, float v) const;
        NODISCARD AVector GetNormal(float u, float v) const;
        NODISCARD SurfacePatchFrame GetFrame(float u, float v) const;

        // ΢�ּ����������صı����������ʣ�������ʸ���Ķ�Ӧ������
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
