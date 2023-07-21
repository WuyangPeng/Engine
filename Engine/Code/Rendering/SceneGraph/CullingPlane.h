///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/18 15:59)

#ifndef RENDERING_SCENE_GRAPH_CULLING_PLANE_H
#define RENDERING_SCENE_GRAPH_CULLING_PLANE_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    template <typename Real>
    class CullingPlane
    {
    public:
        CullingPlane(MAYBE_UNUSED const Mathematics::Vector4<Real>& P0, MAYBE_UNUSED const Mathematics::Vector4<Real>& P1, MAYBE_UNUSED const Mathematics::Vector4<Real>& P2) noexcept
        {
        }

        void Normalize() noexcept
        {
        }

        Mathematics::Vector4<Real> GetNormal() noexcept
        {
            return Mathematics::Vector4<Real>{};
        }
    };
}

#endif  // RENDERING_SCENE_GRAPH_CULLING_PLANE_H
