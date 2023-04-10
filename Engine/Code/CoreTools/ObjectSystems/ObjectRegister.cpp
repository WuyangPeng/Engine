///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/30 17:19)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectRegister.h"
#include "Detail/ObjectRegisterImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::ObjectRegister::ObjectRegister(ObjectRegisterCreate objectRegisterCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(objectRegisterCreate);

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectRegister)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, ObjectRegister, GetUniqueId, ConstObjectInterfaceSharedPtr, int64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectRegister, GetOrderedSize, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectRegister, RegisterRoot, const ConstObjectInterfaceSharedPtr&, int64_t)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectRegister, begin, CoreTools::ConstRegisterContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectRegister, end, CoreTools::ConstRegisterContainerConstIter)
COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, ObjectRegister)

CoreTools::ObjectRegister::ObjectRegisterSharedPtr CoreTools::ObjectRegister::Create()
{
    return std::make_shared<ClassType>(ObjectRegisterCreate::Init);
}
