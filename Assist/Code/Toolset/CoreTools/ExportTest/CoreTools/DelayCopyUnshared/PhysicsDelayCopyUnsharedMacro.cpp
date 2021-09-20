///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.1 (2021/08/12 16:12)

#include "Physics/PhysicsExport.h"

#include "PhysicsDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/PhysicsDelayCopyUnsharedMacroImpl.h"

Physics::PhysicsDelayCopyUnsharedMacro::PhysicsDelayCopyUnsharedMacro(int count)
    : impl{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsDelayCopyUnsharedMacro)

int Physics::PhysicsDelayCopyUnsharedMacro::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Physics::PhysicsDelayCopyUnsharedMacro::SetCount(int count)
{
    PHYSICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

COPY_UNSHARED_CLONE_SELF_DEFINE(Physics, PhysicsDelayCopyUnsharedMacro)