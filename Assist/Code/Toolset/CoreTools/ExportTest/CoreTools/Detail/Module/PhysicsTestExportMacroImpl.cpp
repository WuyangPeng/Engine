///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/18 22:29)

#include "Physics/PhysicsExport.h"

#include "PhysicsTestExportMacroImpl.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

Physics::PhysicsTestExportMacroImpl::PhysicsTestExportMacroImpl(int count) noexcept
    : count{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsTestExportMacroImpl)

int Physics::PhysicsTestExportMacroImpl::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return count;
}

void Physics::PhysicsTestExportMacroImpl::SetCount(int aCount) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    count = aCount;
}