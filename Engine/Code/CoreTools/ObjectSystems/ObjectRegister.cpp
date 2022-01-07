///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 23:11)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectRegister.h"
#include "Detail/ObjectRegisterImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::ObjectRegister::ObjectRegister(MAYBE_UNUSED ObjectRegisterCreate objectRegisterCreate)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectRegister)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, ObjectRegister, GetUniqueID, ConstObjectInterfaceSharedPtr, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectRegister, GetOrderedSize, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectRegister, RegisterRoot, const ConstObjectInterfaceSharedPtr&, uint64_t)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectRegister, begin, CoreTools::ConstRegisterContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectRegister, end, CoreTools::ConstRegisterContainerConstIter)
COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, ObjectRegister)

CoreTools::ObjectRegister::ObjectRegisterSharedPtr CoreTools::ObjectRegister::Create()
{
    return make_shared<ClassType>(ObjectRegisterCreate::Init);
}
