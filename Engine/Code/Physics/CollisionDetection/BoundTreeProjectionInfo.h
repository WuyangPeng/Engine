// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 15:32)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_PROJECTION_INFO_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_PROJECTION_INFO_H

#include "Physics/PhysicsDll.h"
  
namespace Physics
{
	// 在轴上进行重心预测的排序
	class PHYSICS_DEFAULT_DECLARE BoundTreeProjectionInfo
    {
	public:
		using  ClassType = BoundTreeProjectionInfo;

    public:
                BoundTreeProjectionInfo(int triangle, float projection) noexcept;

		CLASS_INVARIANT_DECLARE;

		int GetTriangle() const noexcept;
                float GetProjection() const noexcept;

	private:
        int m_Triangle;
		float m_Projection;
    };

	bool PHYSICS_DEFAULT_DECLARE operator<(const BoundTreeProjectionInfo& lhs, const BoundTreeProjectionInfo& rhs) noexcept;
}


#endif // PHYSICS_COLLISION_DETECTION_BOUND_TREE_PROJECTION_INFO_H
