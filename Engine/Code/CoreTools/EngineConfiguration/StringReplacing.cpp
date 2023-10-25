///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/23 09:24)

#include "CoreTools/CoreToolsExport.h"

#include "StringReplacing.h"
#include "Detail/StringReplacingImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::StringReplacing::StringReplacing(const std::string& configurationFileName)
    : impl{ configurationFileName }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StringReplacing)

CoreTools::StringReplacing::String CoreTools::StringReplacing::GetReplacing(const String& original) const
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetReplacing(original);
}
