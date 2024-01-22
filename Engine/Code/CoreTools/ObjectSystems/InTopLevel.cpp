/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 09:59)

#include "CoreTools/CoreToolsExport.h"

#include "InTopLevel.h"
#include "Detail/InTopLevelImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, InTopLevel)

CoreTools::InTopLevel::InTopLevel(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, InTopLevel)

bool CoreTools::InTopLevel::IsTopLevel(const ObjectInterfaceSharedPtr& object) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsTopLevel(object);
}

int CoreTools::InTopLevel::GetTopLevelSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetTopLevelSize();
}

CoreTools::ObjectContainerConstIter CoreTools::InTopLevel::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->begin();
}

CoreTools::ObjectContainerConstIter CoreTools::InTopLevel::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->end();
}

CoreTools::ObjectContainerIter CoreTools::InTopLevel::begin()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->begin();
}

CoreTools::ObjectContainerIter CoreTools::InTopLevel::end()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->end();
}

void CoreTools::InTopLevel::Insert(const ObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Insert(object);
}

CoreTools::InTopLevel CoreTools::InTopLevel::Create()
{
    return InTopLevel{ DisableNotThrow::Disable };
}
