///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 16:37)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_IMPL_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_IMPL_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"

#include <vector>

namespace Physics
{
    class PHYSICS_HIDDEN_DECLARE BoundTreeSplitTrianglesImpl
    {
    public:
        using ClassType = BoundTreeSplitTrianglesImpl;
        using AVector = Mathematics::AVectorF;
        using APoint = Mathematics::APointF;
        using Centroids = std::vector<APoint>;
        using Split = std::vector<int>;

    public:
        BoundTreeSplitTrianglesImpl(const Centroids& centroids, int beginIndex, int endIndex, const Split& inSplit, const APoint& origin, const AVector& direction);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetFirstOutSplitIndex() const noexcept;
        NODISCARD int GetSecondOutSplitIndex() const noexcept;
        NODISCARD Split GetOutSplit() const;

    private:
        void SplitTriangles(const Centroids& centroids, int beginIndex, int endIndex, const Split& inSplit, const APoint& origin, const AVector& direction);

    private:
        int outSplitIndex0;
        int outSplitIndex1;
        Split outSplit;
    };
}

#endif  // PHYSICS_COLLISION_DETECTION_BOUND_TREE_SPLIT_TRIANGLES_IMPL_H
