/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:26)

#include "Physics/PhysicsExport.h"

#include "PhysicsMacroShared.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Shared/PhysicsMacroSharedImpl.h"

Physics::PhysicsMacroShared::PhysicsMacroShared(int count)
    : impl{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsMacroShared)

int Physics::PhysicsMacroShared::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Physics::PhysicsMacroShared::SetCount(int count) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}

const void* Physics::PhysicsMacroShared::GetAddress() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}