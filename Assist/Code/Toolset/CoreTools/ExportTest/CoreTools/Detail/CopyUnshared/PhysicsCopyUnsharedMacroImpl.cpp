///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/12 22:37)

#include "Physics/PhysicsExport.h"

#include "PhysicsCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::PhysicsCopyUnsharedMacroImpl::PhysicsCopyUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsCopyUnsharedMacroImpl)

int Physics::PhysicsCopyUnsharedMacroImpl::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Physics::PhysicsCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    m_Count = count;
}