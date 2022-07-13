///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 19:05)

#include "Physics/PhysicsExport.h"

#include "PhysicsPerformanceUnsharedMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::PhysicsPerformanceUnsharedMacroImpl::PhysicsPerformanceUnsharedMacroImpl(int count) noexcept
    : mCount{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsPerformanceUnsharedMacroImpl)

int Physics::PhysicsPerformanceUnsharedMacroImpl::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return mCount;
}

void Physics::PhysicsPerformanceUnsharedMacroImpl::SetCount(int count) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    mCount = count;
}