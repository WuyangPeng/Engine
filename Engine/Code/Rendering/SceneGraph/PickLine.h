/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/04 10:26)

#ifndef RENDERING_SCENE_GRAPH_PICK_LINE_H
#define RENDERING_SCENE_GRAPH_PICK_LINE_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PickLine
    {
    public:
        using ClassType = PickLine;

        using Math = Mathematics::Math<float>;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;

    public:
        PickLine() noexcept;
        PickLine(const APoint& origin, const AVector& direction, bool isContain) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD APoint GetOrigin() const noexcept;
        NODISCARD AVector GetDirection() const noexcept;
        NODISCARD bool IsContain() const noexcept;

    private:
        APoint origin;
        AVector direction;
        bool isContain;
    };
}

#endif  // RENDERING_SCENE_GRAPH_PICK_LINE_H
