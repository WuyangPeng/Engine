///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/30 17:13)

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
