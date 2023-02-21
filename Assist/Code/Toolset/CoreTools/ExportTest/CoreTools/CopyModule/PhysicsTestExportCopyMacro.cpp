///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.2 (2023/02/07 18:52)

#include "Physics/PhysicsExport.h"

#include "PhysicsTestExportCopyMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Toolset/CoreTools/ExportTest/CoreTools/Detail/CopyModule/PhysicsTestExportCopyMacroImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Physics, PhysicsTestExportCopyMacro)

Physics::PhysicsTestExportCopyMacro::PhysicsTestExportCopyMacro(int count)
    : impl{ count }
{
    PHYSICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Physics, PhysicsTestExportCopyMacro)

int Physics::PhysicsTestExportCopyMacro::GetCount() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return impl->GetCount();
}

void Physics::PhysicsTestExportCopyMacro::SetCount(int count) noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    impl->SetCount(count);
}
