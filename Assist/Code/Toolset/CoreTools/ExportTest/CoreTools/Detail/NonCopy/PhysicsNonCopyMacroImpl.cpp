///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/01 14:08)

#include "Physics/PhysicsExport.h"

#include "PhysicsNonCopyMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::PhysicsNonCopyMacroImpl::PhysicsNonCopyMacroImpl(int count) noexcept
    : mCount{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsNonCopyMacroImpl)

int Physics::PhysicsNonCopyMacroImpl::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Physics::PhysicsNonCopyMacroImpl::SetCount(int count) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    mCount = count;
}