//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.2 (2020/09/11 13:01)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectName.h"
#include "Detail/ObjectNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;
using std::string;

CoreTools::ObjectName::ObjectName(const string& name)
    : m_Impl{ make_shared<ImplType>(name) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

COPY_CONSTRUCTION_DEFINE(CoreTools, ObjectName)

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(CoreTools, ObjectName)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(CoreTools, ObjectName, GetName, string)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, ObjectName, SetName, string, void)

bool CoreTools::ObjectName::IsExactly(const ObjectName& name) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsExactly(*name.m_Impl);
}