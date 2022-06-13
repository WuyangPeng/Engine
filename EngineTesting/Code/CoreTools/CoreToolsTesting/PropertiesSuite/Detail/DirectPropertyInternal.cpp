///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 11:40)

#include "DirectPropertyInternal.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::DirectPropertyInternal::DirectPropertyInternal(MAYBE_UNUSED DisableNotThrow disableNotThrow)
    : getType{ "Init" }, setType{ "SetType" }
{
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

    return setType.m_Value;
}
