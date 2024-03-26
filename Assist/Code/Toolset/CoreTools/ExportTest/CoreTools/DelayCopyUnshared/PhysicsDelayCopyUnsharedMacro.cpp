/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/06 10:01)

#include "Physics/PhysicsExport.h"

#include "PhysicsDelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/DelayCopyUnshared/PhysicsDelayCopyUnsharedMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Physics, PhysicsDelayCopyUnsharedMacro)

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

const void* Physics::PhysicsDelayCopyUnsharedMacro::GetAddress() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}