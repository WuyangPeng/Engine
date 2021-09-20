///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/13 21:40)

#include "Physics/PhysicsExport.h"

#include "PhysicsPerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::PhysicsPerformanceUnsharedMacroImpl::PhysicsPerformanceUnsharedMacroImpl(int count) noexcept
    : m_Count{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsPerformanceUnsharedMacroImpl)

int Physics::PhysicsPerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return m_Count;
}

void Physics::PhysicsPerformanceUnsharedMacroImpl::SetCount(int count) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    m_Count = count;
}