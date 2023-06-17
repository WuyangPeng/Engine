///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:11)

#ifndef RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_H
#define RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/APoint.h"

RENDERING_PERFORMANCE_UNSHARED_EXPORT_IMPL(TrianglePositionImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TrianglePosition
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(TrianglePosition);
        using APoint = Mathematics::APointF;

    public:
        TrianglePosition(const APoint& firstPosition, const APoint& secondPosition, const APoint& thirdPosition);

        CLASS_INVARIANT_DECLARE;

        NODISCARD APoint GetFirstPosition() const noexcept;
        NODISCARD APoint GetSecondPosition() const noexcept;
        NODISCARD APoint GetThirdPosition() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_SCENE_GRAPH_TRIANGLES_POSITION_H
