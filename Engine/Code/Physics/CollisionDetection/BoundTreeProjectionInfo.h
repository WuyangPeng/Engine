// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 15:32)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_PROJECTION_INFO_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_PROJECTION_INFO_H

#include "Physics/PhysicsDll.h"
  
namespace Physics
{
	// �����Ͻ�������Ԥ�������
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
