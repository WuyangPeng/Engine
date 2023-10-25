///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:51)

#include "CoreTools/CoreToolsExport.h"

#include "OutTopLevel.h"
#include "Detail/OutTopLevelImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, OutTopLevel)

CoreTools::OutTopLevel CoreTools::OutTopLevel::Create()
{
    return OutTopLevel{ DisableNotThrow::Disable };
}

CoreTools::OutTopLevel::OutTopLevel(DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, OutTopLevel)

bool CoreTools::OutTopLevel::IsTopLevel(const ConstObjectInterfaceSharedPtr& object) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsTopLevel(object);
}

int CoreTools::OutTopLevel::GetTopLevelSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetTopLevelSize();
}

CoreTools::ConstObjectContainerConstIter CoreTools::OutTopLevel::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->begin();
}

CoreTools::ConstObjectContainerConstIter CoreTools::OutTopLevel::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->end();
}

void CoreTools::OutTopLevel::Insert(const ObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->Insert(object);
}
