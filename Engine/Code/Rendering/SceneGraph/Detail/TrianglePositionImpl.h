///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:07)

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
