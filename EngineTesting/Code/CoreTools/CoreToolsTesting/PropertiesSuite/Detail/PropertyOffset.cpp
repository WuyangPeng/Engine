///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 13:44)

#include "PropertyOffset.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::PropertyOffset::PropertyOffset(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : offset{}, value{ "Value" }, internalOffset{ "Offset" }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, PropertyOffset)

ptrdiff_t CoreTools::PropertyOffset::GetOffset() noexcept
{
    enum
    {
        offset = offsetof(ClassType, offset)
    };

    return offset;
}

const string& CoreTools::PropertyOffset::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

const std::string& CoreTools::PropertyOffset::GetInternalValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return internalOffset.value;
}
