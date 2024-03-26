/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:16)

#include "Physics/PhysicsExport.h"

#include "PhysicsMacroSharedImpl.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::PhysicsMacroSharedImpl::PhysicsMacroSharedImpl(int count) noexcept
    : count{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsMacroSharedImpl)

int Physics::PhysicsMacroSharedImpl::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return count;
}

void Physics::PhysicsMacroSharedImpl::SetCount(int aCount) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    count = aCount;
}