/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:54)

#include "DirectPropertyInternal.h"
#include "System/Helper/Tools.h"
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
