/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:55)

#include "PropertyOffset.h"
#include "System/Helper/Tools.h"
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
