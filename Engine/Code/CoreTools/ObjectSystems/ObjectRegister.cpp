//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/22 16:40)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectRegister.h"
#include "Detail/ObjectRegisterImpl.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "../Contract/Flags/ImplFlags.h"

CoreTools::ObjectRegister::ObjectRegister([[maybe_unused]] DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectRegister)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectRegister, GetUniqueID, const ConstObjectInterfaceSharedPtr&, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectRegister, GetOrderedSize, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectRegister, RegisterRoot, const ConstObjectInterfaceSharedPtr&, uint64_t)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectRegister, begin, CoreTools::ConstRegisterContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectRegister, end, CoreTools::ConstRegisterContainerConstIter)
COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, ObjectRegister)