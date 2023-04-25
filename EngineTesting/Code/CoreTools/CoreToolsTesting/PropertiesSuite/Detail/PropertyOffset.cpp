///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 10:12)

#include "PropertyOffset.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::PropertyOffset::PropertyOffset(DisableNotThrow disableNotThrow)
    : internalOffset{ "Offset" }, value{ "Value" }, offset{}
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, PropertyOffset)

ptrdiff_t CoreTools::PropertyOffset::GetOffset() noexcept
{
    enum
    {
        Offset = offsetof(ClassType, offset)
    };

    return Offset;
}

const std::string& CoreTools::PropertyOffset::GetValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return value;
}

const std::string& CoreTools::PropertyOffset::GetInternalValue() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return internalOffset.value;
}
