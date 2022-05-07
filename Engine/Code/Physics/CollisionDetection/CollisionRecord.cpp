///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/25 14:00)

#include "Physics/PhysicsExport.h"

#include "CollisionRecordDetail.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

#ifdef PHYSICS_TEMPLATE_TEST

namespace Physics
{
    template class CollisionRecord<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
    template class CollisionRecord<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
}

#endif  // PHYSICS_TEMPLATE_TEST
