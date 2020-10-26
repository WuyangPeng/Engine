//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/22 16:40)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectRegister.h"
#include "Detail/ObjectRegisterImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

CoreTools::ObjectRegister::ObjectRegister([[maybe_unused]] DisableNotThrow disableNotThrow)
    : m_Impl{ make_shared<ImplType>() }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, ObjectRegister)

DELAY_COPY_CONSTRUCTION_DEFINE(CoreTools, ObjectRegister);

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectRegister, GetUniqueID, const ConstObjectInterfaceSharedPtr&, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectRegister, GetOrderedSize, int)

IMPL_NON_CONST_COPY_MEMBER_FUNCTION_DEFINE_1_V(CoreTools, ObjectRegister, RegisterRoot, const ConstObjectInterfaceSharedPtr&, uint64_t)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectRegister, begin, CoreTools::ConstRegisterContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, ObjectRegister, end, CoreTools::ConstRegisterContainerConstIter)
