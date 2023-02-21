///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 19:37)

#include "Physics/PhysicsExport.h"

#include "PhysicsPerformanceUnsharedMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/PerformanceUnshared/PhysicsPerformanceUnsharedMacroImpl.h"

Physics::PhysicsPerformanceUnsharedMacro::PhysicsPerformanceUnsharedMacro(int count)
    : impl{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsPerformanceUnsharedMacro)

int Physics::PhysicsPerformanceUnsharedMacro::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

const void* Physics::PhysicsPerformanceUnsharedMacro::GetAddress() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return &(*impl);
}