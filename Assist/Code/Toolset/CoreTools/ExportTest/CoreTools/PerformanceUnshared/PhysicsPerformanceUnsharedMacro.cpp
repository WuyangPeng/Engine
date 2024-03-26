/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 10:25)

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