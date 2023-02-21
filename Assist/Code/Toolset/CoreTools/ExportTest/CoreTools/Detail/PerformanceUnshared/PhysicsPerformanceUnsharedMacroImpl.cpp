///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.2 (2023/02/07 19:23)

#include "Physics/PhysicsExport.h"

#include "PhysicsPerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::PhysicsPerformanceUnsharedMacroImpl::PhysicsPerformanceUnsharedMacroImpl(int count) noexcept
    : count{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsPerformanceUnsharedMacroImpl)

int Physics::PhysicsPerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return count;
}

 