///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:12)

#include "PropertyExternal.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::PropertyExternal::PropertyExternal() noexcept
    : value{}, getType{ *this }, setType{ *this }, getSetType{ *this }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, PropertyExternal)

const std::string& CoreTools::PropertyExternal::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

void CoreTools::PropertyExternal::SetValue(const std::string& aValue)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    value = aValue;
}
