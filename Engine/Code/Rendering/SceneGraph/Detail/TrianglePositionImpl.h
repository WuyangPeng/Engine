///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:07)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_IMPL_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE TrianglePositionImpl
    {
    public:
        using ClassType = TrianglePositionImpl;
        using APoint = Mathematics::APointF;

    public:
        TrianglePositionImpl(const APoint& firstPosition, const APoint& secondPosition, const APoint& thirdPosition) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD APoint GetFirstPosition() const noexcept;
        NODISCARD APoint GetSecondPosition() const noexcept;
        NODISCARD APoint GetThirdPosition() const noexcept;

    private:
        APoint firstPosition;
        APoint secondPosition;
        APoint thirdPosition;
    };
}

#endif  // RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_IMPL_H
