// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/29 15:33)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_H

#include "Physics/PhysicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

PHYSICS_EXPORT_SHARED_PTR(BoundTreeSplitTrianglesImpl);

namespace Physics
{
    class PHYSICS_DEFAULT_DECLARE BoundTreeSplitTriangles
    {
    public:
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(BoundTreeSplitTriangles);
        using AVector = Mathematics::FloatAVector;
        using APoint = Mathematics::FloatAPoint;
        using Centroids = std::vector<APoint>;
        using Split = std::vector<int>;

    public:
        BoundTreeSplitTriangles(const Centroids& centroids, int beginIndex, int endIndex,
                                const Split& inSplit, const APoint& origin, const AVector& direction);

        CLASS_INVARIANT_DECLARE;

        int GetFirstOutSplitIndex() const noexcept;
        int GetSecondOutSplitIndex() const noexcept;
        const Split GetOutSplit() const;

    private:
        IMPL_TYPE_DECLARE(BoundTreeSplitTriangles);
    };
}

#endif  // PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_H
