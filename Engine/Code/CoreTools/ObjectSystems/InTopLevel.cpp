///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 23:09)

#include "CoreTools/CoreToolsExport.h"

#include "InTopLevel.h"
#include "Detail/InTopLevelImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::InTopLevel::InTopLevel(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : impl{ ImplCreateUseDefaultConstruction::Default }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, InTopLevel)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, InTopLevel, IsTopLevel, ObjectInterfaceSharedPtr, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, InTopLevel, GetTopLevelSize, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, InTopLevel, begin, CoreTools::ObjectContainerConstIter)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(CoreTools, InTopLevel, end, CoreTools::ObjectContainerConstIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, InTopLevel, begin, CoreTools::ObjectContainerIter)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, InTopLevel, end, CoreTools::ObjectContainerIter)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, InTopLevel, Insert, ObjectInterfaceSharedPtr, void)

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, InTopLevel)

CoreTools::InTopLevel CoreTools::InTopLevel::Create()
{
    return InTopLevel{ DisableNotThrow::Disable };
}
