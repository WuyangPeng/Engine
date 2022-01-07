///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/24 23:11)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectName.h"
#include "Detail/ObjectNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, ObjectName)

CoreTools::ObjectName::ObjectName(const string& name)
    : impl{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectName)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectName, GetName, string)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, ObjectName, SetName, string, void)

bool CoreTools::ObjectName::IsExactly(const ObjectName& name) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsExactly(*name.impl);
}
