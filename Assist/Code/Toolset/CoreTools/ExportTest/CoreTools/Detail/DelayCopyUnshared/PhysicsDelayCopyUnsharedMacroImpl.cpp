///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:04)

#include "Physics/PhysicsExport.h"

#include "PhysicsDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::PhysicsDelayCopyUnsharedMacroImpl::PhysicsDelayCopyUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsDelayCopyUnsharedMacroImpl)

int Physics::PhysicsDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return count;
}

void Physics::PhysicsDelayCopyUnsharedMacroImpl::SetCount(int aCount) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    count = aCount;
}