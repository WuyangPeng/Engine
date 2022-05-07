///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 14:00)

#include "Physics/PhysicsExport.h"

#include "CollisionGroupDetail.h"
#include "Rendering/DataTypes/Bound.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

#ifdef PHYSICS_TEMPLATE_TEST

namespace Physics
{
    template class CollisionGroup<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
    template class CollisionGroup<Rendering::TrianglesMeshSharedPtr, Rendering::BoundF>;
}

#endif  // PHYSICS_TEMPLATE_TEST
