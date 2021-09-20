///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.1 (2021/08/13 17:14)

#include "Physics/PhysicsExport.h"

#include "PhysicsDelayCopyUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::PhysicsDelayCopyUnsharedMacroImpl::PhysicsDelayCopyUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsDelayCopyUnsharedMacroImpl)

int Physics::PhysicsDelayCopyUnsharedMacroImpl::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Physics::PhysicsDelayCopyUnsharedMacroImpl::SetCount(int count) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    m_Count = count;
}