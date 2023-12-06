///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.0 (2023/11/16 09:51)

#include "AssistTools/AssistToolsExport.h"

#include "Replace.h"
#include "Detail/ReplaceImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"

AssistTools::Replace::Replace(const StringView& keyCode, const String& parameter)
    : impl{ keyCode, parameter }
{
    ASSIST_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, Replace)

System::StringView AssistTools::Replace::GetKeyCode() const noexcept
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetKeyCode();
}

System::String AssistTools::Replace::GetParameter() const
{
    ASSIST_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetParameter();
}