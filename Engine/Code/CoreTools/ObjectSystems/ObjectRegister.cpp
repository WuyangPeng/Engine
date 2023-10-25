///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 15:50)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectRegister.h"
#include "Detail/ObjectRegisterImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, ObjectRegister)

CoreTools::ObjectRegister::ObjectRegister(ObjectRegisterCreate objectRegisterCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(objectRegisterCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectRegister)

int64_t CoreTools::ObjectRegister::GetUniqueId(const ConstObjectInterfaceSharedPtr& pointer) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetUniqueId(pointer);
}

int CoreTools::ObjectRegister::GetOrderedSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetOrderedSize();
}

int64_t CoreTools::ObjectRegister::RegisterRoot(const ConstObjectInterfaceSharedPtr& pointer)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->RegisterRoot(pointer);
}

CoreTools::ConstRegisterContainerConstIter CoreTools::ObjectRegister::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->begin();
}

CoreTools::ConstRegisterContainerConstIter CoreTools::ObjectRegister::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->end();
}

CoreTools::ObjectRegister::ObjectRegisterSharedPtr CoreTools::ObjectRegister::Create()
{
    return std::make_shared<ClassType>(ObjectRegisterCreate::Init);
}
