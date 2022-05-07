///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 13:57)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_H

#include "Physics/PhysicsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

PHYSICS_PERFORMANCE_UNSHARED_EXPORT_IMPL(BoundTreeSplitTrianglesImpl);

namespace Physics
{
    class PHYSICS_DEFAULT_DECLARE BoundTreeSplitTriangles
    {
    public:
        PERFORMANCE_UNSHARED_TYPE_DECLARE(BoundTreeSplitTriangles);
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;
        using Centroids = std::vector<APoint>;
        using Split = std::vector<int>;

    public:
        BoundTreeSplitTriangles(const Centroids& centroids, int beginIndex, int endIndex, const Split& inSplit, const APoint& origin, const AVector& direction);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetFirstOutSplitIndex() const noexcept;
        NODISCARD int GetSecondOutSplitIndex() const noexcept;
        NODISCARD Split GetOutSplit() const;

    private:
        PackageType impl;
    };
}

#endif  // PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_H
