// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/25 15:51)

#ifndef RENDERING_CURVES_SURFACES_SURFACE_PATCH_IMPL_H
#define RENDERING_CURVES_SURFACES_SURFACE_PATCH_IMPL_H

#include "Rendering/RenderingDll.h"

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
}

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

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        int GetStreamingSize() const;

        // ����������Ǿ��λ������Ρ�
        // ���ھ�������Ч��(u,v)ֵ����umin <= u <= umax,  vmin <= v <= vmax
        // ��������Ч��(u,v)ֵ������ umin <= u <= umax,  vmin <= v <= vmax��
        //  (vmax - vmin) * (u - umin) + (umax - umin) * (v - vmax) <= 0
        float GetUMin() const noexcept;
        float GetUMax() const noexcept;
        float GetVMin() const noexcept;
        float GetVMax() const noexcept;
        bool IsRectangular() const noexcept;

    private:
        float m_UMin;
        float m_UMax;
        float m_VMin;
        float m_VMax;
        bool m_Rectangular;
    };
}

#endif  // RENDERING_CURVES_SURFACES_SURFACE_PATCH_IMPL_H
