///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/24 17:02)

#include "Physics/PhysicsExport.h"

#include "BoundTreeProjectionInfo.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::BoundTreeProjectionInfo::BoundTreeProjectionInfo(int triangle, float projection) noexcept
    : triangle{ triangle }, projection{ projection }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, BoundTreeProjectionInfo)

int Physics::BoundTreeProjectionInfo::GetTriangle() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return triangle;
}

float Physics::BoundTreeProjectionInfo::GetProjection() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return projection;
}

bool Physics::operator<(const BoundTreeProjectionInfo& lhs, const BoundTreeProjectionInfo& rhs) noexcept
{
    return lhs.GetProjection() < rhs.GetProjection();
}
