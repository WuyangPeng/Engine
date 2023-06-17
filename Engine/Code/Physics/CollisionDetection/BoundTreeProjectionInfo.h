///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 16:38)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_PROJECTION_INFO_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_PROJECTION_INFO_H

#include "Physics/PhysicsDll.h"

namespace Physics
{
    // 在轴上进行重心预测的排序
    class PHYSICS_DEFAULT_DECLARE BoundTreeProjectionInfo
    {
    public:
        using ClassType = BoundTreeProjectionInfo;

    public:
        BoundTreeProjectionInfo(int triangle, float projection) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetTriangle() const noexcept;
        NODISCARD float GetProjection() const noexcept;

    private:
        int triangle;
        float projection;
    };

    NODISCARD bool PHYSICS_DEFAULT_DECLARE operator<(const BoundTreeProjectionInfo& lhs, const BoundTreeProjectionInfo& rhs) noexcept;
}

#endif  // PHYSICS_COLLISION_DETECTION_BOUND_TREE_PROJECTION_INFO_H
