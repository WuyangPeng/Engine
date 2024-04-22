/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:20)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectName.h"
#include "Detail/ObjectNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools, ObjectName)

CoreTools::ObjectName::ObjectName(const std::string& name)
    : impl{ name }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectName)

std::string CoreTools::ObjectName::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->GetName();
}

void CoreTools::ObjectName::SetName(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->SetName(name);
}

bool CoreTools::ObjectName::IsExactly(const ObjectName& name) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return impl->IsExactly(*name.impl);
}
