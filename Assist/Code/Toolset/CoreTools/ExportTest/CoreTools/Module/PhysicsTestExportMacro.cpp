///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 18:40)

#include "Physics/PhysicsExport.h"

#include "PhysicsTestExportMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/Module/PhysicsTestExportMacroImpl.h"

Physics::PhysicsTestExportMacro::PhysicsTestExportMacro(int count)
    : impl{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsTestExportMacro)

int Physics::PhysicsTestExportMacro::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Physics::PhysicsTestExportMacro::SetCount(int count) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}