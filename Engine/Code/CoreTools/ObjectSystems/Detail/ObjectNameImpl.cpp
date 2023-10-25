///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:34)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectNameImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::ObjectNameImpl::ObjectNameImpl(std::string name) noexcept
    : name{ std::move(name) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectNameImpl)

std::string CoreTools::ObjectNameImpl::GetName() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return name;
}

bool CoreTools::ObjectNameImpl::IsExactly(const ObjectNameImpl& aName) const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return name == aName.name;
}

void CoreTools::ObjectNameImpl::SetName(const std::string& aName)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    name = aName;
}
