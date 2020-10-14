// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/25 15:57)

#ifndef RENDERING_CURVES_SURFACES_SURFACE_PATCH_H
#define RENDERING_CURVES_SURFACES_SURFACE_PATCH_H

#include "Rendering/RenderingDll.h"

#include "PrincipalCurvatureInfo.h"
#include "SurfacePatchFrame.h"
#include "CoreTools/Helper/ExportMacro.h"

#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

RENDERING_EXPORT_SHARED_PTR(SurfacePatchImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SurfacePatch : public CoreTools::Object
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(SurfacePatch, = default);
        using ParentType = Object;
        using AVector = Mathematics::FloatAVector;
        using APoint = Mathematics::FloatAPoint;

    public:
        SurfacePatch(float uMin, float uMax, float vMin, float vMax, bool rectangular);
         

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_OVERRIDE_DECLARE;
        bool IsParameterValid(float u, float v) const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SurfacePatch);

        // ����������Ǿ��λ������Ρ�
        // ���ھ�������Ч��(u,v)ֵ����umin <= u <= umax,  vmin <= v <= vmax
        // ��������Ч��(u,v)ֵ������ umin <= u <= umax,  vmin <= v <= vmax��
        //  (vmax - vmin) * (u - umin) + (umax - umin) * (v - vmax) <= 0
        float GetUMin() const noexcept;
        float GetUMax() const noexcept;
        float GetVMin() const noexcept;
        float GetVMax() const noexcept;
        bool IsRectangular() const noexcept;

        // λ�ü����׵���
        virtual const APoint GetPosition(float u, float v) const = 0;
        virtual const AVector GetDerivativesU(float u, float v) const = 0;
        virtual const AVector GetDerivativesV(float u, float v) const = 0;
        virtual const AVector GetDerivativesUU(float u, float v) const = 0;
        virtual const AVector GetDerivativesUV(float u, float v) const = 0;
        virtual const AVector GetDerivativesVV(float u, float v) const = 0;

        // ����һ������ϵ������{T0,T1,N}��һ��������������ϵ��
        const AVector GetTangent0(float u, float v) const;
        const AVector GetTangent1(float u, float v) const;
        const AVector GetNormal(float u, float v) const;
        const SurfacePatchFrame GetFrame(float u, float v) const;

        // ΢�ּ����������صı����������ʣ�������ʸ���Ķ�Ӧ������
        const PrincipalCurvatureInfo ComputePrincipalCurvatureInfo(float u, float v) const;

    private:
        IMPL_TYPE_DECLARE(SurfacePatch);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(SurfacePatch);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( SurfacePatch);
}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_PATCH_H
