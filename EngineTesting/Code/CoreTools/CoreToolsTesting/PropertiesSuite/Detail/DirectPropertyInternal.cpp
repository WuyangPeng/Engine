///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:42)

#include "DirectPropertyInternal.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::DirectPropertyInternal::DirectPropertyInternal(DisableNotThrow disableNotThrow)
    : getType{ "Init" }, setType{ "SetType" }
{
    System::UnusedFunction(disableNotThrow);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, DirectPropertyInternal)

void CoreTools::DirectPropertyInternal::SetValue(const std::string& value)
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;

    getType.value = value;
}

std::string CoreTools::DirectPropertyInternal::GetValue() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return setType.value;
}
